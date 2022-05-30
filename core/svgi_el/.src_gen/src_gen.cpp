#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <iostream>
#include <fstream>
#include <regex>
#include <iomanip>
#include <filesystem>
#include "../../json.hpp"

std::string out_dir = "..";
std::string base_dir = "../..";
std::string json_dir = "../../.svg_def";

using json = nlohmann::json;
namespace fs = std::filesystem;

#define is_uppercase(c) (c <= 'Z' && c >= 'A')
#define is_lowercase(c) (c <= 'z' && c >= 'a')
#define to_uppercase(c) ((char)(is_uppercase(c) ? c : ('A' + c - 'a')))
#define to_lowercase(c) ((char)(is_lowercase(c) ? c : ('a' + c - 'A')))
#define to_bcase(c, b) ((char)(b ? to_uppercase(c) : to_lowercase(c)))
// DOM style to snake style
const std::string dom_to_snake(const std::string &dom, bool uppercase = false) {
    std::string snake;
    for (int i = 0; i < dom.size(); i++) {
        if (dom[i] == '-') {
            snake.push_back('_');
        } else if (is_uppercase(dom[i])) {
            if (i == 0 || (dom[i-1] != '-' && !is_uppercase(dom[i-1]))) snake.push_back('_');
            snake.push_back(to_bcase(dom[i], uppercase));
        } else snake.push_back(to_bcase(dom[i], uppercase));
    }
    return snake;
}
// DOM style to pascal style
const std::string dom_to_pascal(const std::string &dom) {
    std::string pascal;
    bool uppercase = true;
    for (int i = 0; i < dom.size(); i++) {
        if (dom[i] == '-') {
            uppercase = true;
        } else if (is_uppercase(dom[i])) {
            uppercase = true;
            pascal.push_back(to_bcase(dom[i], uppercase));
            uppercase = false;
        } else if (is_lowercase(dom[i])) {
            pascal.push_back(to_bcase(dom[i], uppercase));
            uppercase = false;
        } else {
            pascal.push_back(dom[i]);
            uppercase = true;
        }
    }
    return pascal;
}

const std::string type_to_ctype(const std::string &typ) {
    auto g = std::regex_replace(typ, std::regex("\\s"), "");
    if (g == "") g = "<anything>";
    
    int i = 0;
    std::function<std::string()> _func;
    std::function<std::string(const std::string &, const std::string &, const std::vector<std::string> &)> list_string;
    list_string = [](const std::string &head, const std::string &tail, const std::vector<std::string> &attrs) {
        std::stringstream ss;
        if (attrs.size() == 1) ss << attrs[0];
        else {
            ss << head;
            for (int i = 0; i < attrs.size(); i++) {
                if (i > 0) ss << ", ";
                ss << attrs[i];
            }
            ss << tail;
        }
        return ss.str();
    };
    _func = [&](){
        std::vector<std::string> attrs_tuple;
        std::vector<std::string> attrs_enumerate;
        bool in_tuple = 0;
        while (i < g.size()) { // next attr
            std::string attr;
            if (g[i] == '(') {
                i++, attrs_tuple.push_back(_func());
                in_tuple = 1;
                continue;
            }
            if (g[i] == ')') {
                i++; break;
            }
            if (g[i] == '|') {
                i++;
                if (in_tuple) {
                    in_tuple = 0;
                    attrs_enumerate.push_back(list_string("AttrTuple<", ">", attrs_tuple));
                    attrs_tuple.clear();
                }
                continue;
            }
            while (i < g.size() && g[i] != '|' && g[i] != '(' && g[i] != ')') {
                attr.push_back(g[i]);
                i++;
                if (g[i] == ':') {
                    while (i < g.size() && g[i] != '|' && g[i] != '(' && g[i] != ')') i++;
                }
                if (g[i] == '(') in_tuple = 1;
            }
            if (attr == "") break;
            bool prime = (attr.find('<') != std::string::npos);
            attr = std::regex_replace(attr, std::regex("<"), "");
            attr = std::regex_replace(attr, std::regex(">"), "");
            if (prime) attr = dom_to_pascal(attr);
            else attr = "Const" + dom_to_pascal(attr);
            if (in_tuple) attrs_tuple.push_back("Attr" + attr);
            else attrs_enumerate.push_back("Attr" + attr);
        }
        if (in_tuple) attrs_enumerate.push_back(list_string("AttrTuple<", ">", attrs_tuple));
        return list_string("AttrEnumerate<", ">", attrs_enumerate);
    };

    return _func();
}

class Attribute {
protected:
    std::string _tag;
    std::string _name;
    std::string _rname;
    std::string _type;
    std::string _comment;
    int _i;
public:
    Attribute(const std::string &tag, const std::string &name, const std::string &typ, const std::string &comment, int i): _tag(tag), _name(name), _type(type_to_ctype(typ)), _comment(comment), _i(i) {
        _comment = std::regex_replace(_comment, std::regex("\n"), "\n        * ");
        _rname = name;
        _name = dom_to_pascal(std::regex_replace(_name, std::regex(":"), "-"));
    }
    const std::string domain() const {
        std::stringstream ss;
        ss << "    public:" << std::endl;
         ss << "        /**" << std::endl;
        ss << "        * " << _comment << std::endl;
        ss << "        */" << std::endl;
        ss << "        " + _type + " " + _name + ";" << std::endl;
        return ss.str();
    }
    const std::string on_assign() const {
        std::stringstream ss;
        ss << "            [this](const std::string &last){" << std::endl;
        ss << "                if (" + _name + ".get() == " + _name + ".get_commit()) modified.erase(" << _i << ");" << std::endl;
        ss << "                else modified.insert(" << _i << ");" << std::endl;
        ss << "                bound.erase(" << _i << ");" << std::endl;
        ss << "            }," << std::endl;
        return ss.str();
    }
    const std::string on_bind() const {
        std::stringstream ss;
        ss << "            std::bind([this](){" << std::endl;
        ss << "                modified.erase(" << _i << ");" << std::endl;
        ss << "                bound.insert(" << _i << ");" << std::endl;
        ss << "            })," << std::endl;
        return ss.str();
    }
    const std::string on_commit() const {
        std::stringstream ss;
        ss << "            [this](){" << std::endl;
        ss << "                if (SVG" + dom_to_pascal(_tag) + "::get_" + dom_to_snake(_rname) + "() == " + _name + ".get_commit()) return std::string(\"\");" << std::endl;
        ss << "                " + _name + ".commit();" << std::endl;
        ss << "                if (" + _name + ".get() == STR_NULL) return std::string(\"reset " + _rname + "\");" << std::endl;
        ss << "                else return std::string(\"modify " + _rname + " \\\"\" + " + _name + ".get() + \"\\\"\");" << std::endl;
        ss << "            }," << std::endl;
        return ss.str();
    }
    const std::string get_set() const {
        std::stringstream ss;
        ss << "        std::function<const std::string()> _getter_" + dom_to_snake(_rname) + " = std::bind(&SVG" + dom_to_pascal(_tag) + "::get_" + dom_to_snake(_rname) + ", (SVG" + dom_to_pascal(_tag) + " *)this);" << std::endl;
        ss << "        std::function<void(const std::string &)> _setter_" + dom_to_snake(_rname) + " = std::bind(&SVG" + dom_to_pascal(_tag) + "::set_" + dom_to_snake(_rname) + ", (SVG" + dom_to_pascal(_tag) + " *)this, std::placeholders::_1);" << std::endl;
        ss << "        " + _name + ".set_getter(_getter_" + dom_to_snake(_rname) + "), " + _name + ".set_setter(_setter_" + dom_to_snake(_rname) + ");" << std::endl;
        ss << "        " + _name + ".callback_assign(_attr_on_assign[" << _i << "]), " + _name + ".callback_bind_func(_attr_on_bind[" << _i << "]), " + _name + ".callback_bind_ptr(_attr_on_bind[" << _i << "]);" << std::endl;
        return ss.str();
    }
    const std::string hide() const {
        std::stringstream ss;
        ss << "        using SVG" + dom_to_pascal(_tag) + "::get_" + dom_to_snake(_rname) + ";" << std::endl;
        ss << "        using SVG" + dom_to_pascal(_tag) + "::set_" + dom_to_snake(_rname) + ";" << std::endl;
        return ss.str();
    }
    const std::string copy() const {
        std::stringstream ss;
        ss << "        " + _name + " = element." + _name + ";" << std::endl;
        return ss.str();
    }
};

std::vector<std::shared_ptr<Attribute>> attributes_i;

std::string SVGICPP() {
    std::stringstream ss;
    ss << "#include <sstream>" << std::endl;
    ss << "#include <algorithm>" << std::endl;
    ss << "#include <map>" << std::endl;
    ss << "#include <unordered_map>" << std::endl;
    ss << "#include \"svgi_el.h\"" << std::endl;
    ss << "" << std::endl;
    ss << "namespace Lewzen {" << std::endl;
    ss << "    SVGIElement::SVGIElement(): SVGElement() {" << std::endl;
    ss << "        _bind_getter_setter();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    void SVGIElement::_bind_getter_setter() {" << std::endl;
    for (auto &p : attributes_i) ss << p->get_set();
    ss << "" << std::endl;
    ss << "        std::function<const std::string()> _getter_raw_html = std::bind(&SVGElement::get_raw_HTML, (SVGElement *)this);" << std::endl;
    ss << "        std::function<void(const std::string &)> _setter_raw_html = std::bind(&SVGElement::set_raw_HTML, (SVGElement *)this, std::placeholders::_1);" << std::endl;
    ss << "        RawHTML.set_getter(_getter_raw_html), RawHTML.set_setter(_setter_raw_html);" << std::endl;
    ss << "    }" << std::endl;
    ss << "" << std::endl;
    ss << "    const std::string SVGIElement::get_tag() const {" << std::endl;
    ss << "        return SVGElement::get_tag();" << std::endl;
    ss << "    }" << std::endl;
    ss << "" << std::endl;
    ss << "    const std::string SVGIElement::inner_SVG() const {" << std::endl;
    ss << "        return SVGElement::inner_SVG();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    void SVGIElement::add(const std::shared_ptr<SVGIElement> &element, int index) {" << std::endl;
    ss << "        if (index == -1) _inner_elements_commit.push_back(element);" << std::endl;
    ss << "        else _inner_elements_commit.insert(_inner_elements_commit.begin() + index, element);" << std::endl;
    ss << "    }" << std::endl;
    ss << "    void SVGIElement::remove(const std::shared_ptr<SVGIElement> &element, bool remove_all) {" << std::endl;
    ss << "        bool success = false;" << std::endl;
    ss << "        std::vector<std::shared_ptr<SVGIElement>> removed;" << std::endl;
    ss << "        _inner_elements_commit.erase(std::remove_if(_inner_elements_commit.begin(), _inner_elements_commit.end()," << std::endl;
    ss << "                                [&](const std::shared_ptr<SVGIElement>& _inner_element) { " << std::endl;
    ss << "                                    if (success && !remove_all) return false;" << std::endl;
    ss << "                                    if (_inner_element->get_outer_hash() == element->get_outer_hash()) {" << std::endl;
    ss << "                                        success = true;" << std::endl;
    ss << "                                        removed.push_back(_inner_element);" << std::endl;
    ss << "                                        return true;" << std::endl;
    ss << "                                    }" << std::endl;
    ss << "                                    return false;" << std::endl;
    ss << "                                }), _inner_elements_commit.end());" << std::endl;
    ss << "        success = false;" << std::endl;
    ss << "        for (auto &p : removed) p->_parent_element_commit = std::weak_ptr<SVGIElement>();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    void SVGIElement::remove(int index) {" << std::endl;
    ss << "        _inner_elements_commit[index]->_parent_element = std::weak_ptr<SVGIElement>();" << std::endl;
    ss << "        _inner_elements_commit.erase(_inner_elements_commit.begin() + index);" << std::endl;
    ss << "    }" << std::endl;
    ss << "    std::shared_ptr<SVGIElement> SVGIElement::child(int index) const {" << std::endl;
    ss << "        return _inner_elements_commit[index];" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const std::vector<std::shared_ptr<SVGIElement>> SVGIElement::children() const {" << std::endl;
    ss << "        return _inner_elements_commit;" << std::endl;
    ss << "    }" << std::endl;
    ss << "    void SVGIElement::children(const std::vector<std::shared_ptr<SVGIElement>> &elements) {" << std::endl;
    ss << "        while (_inner_elements_commit.size() > 0) remove(0);" << std::endl;
    ss << "        for (auto p : elements) add(p);" << std::endl;
    ss << "    }" << std::endl;
    ss << "" << std::endl;
    ss << "    const std::string SVGIElement::outer_SVG() const {" << std::endl;
    ss << "        return SVGElement::outer_SVG();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const HASH_CODE SVGIElement::hash() const {" << std::endl;
    ss << "        return SVGElement::get_outer_hash();" << std::endl;
    ss << "    }" << std::endl;
    ss << "" << std::endl;
    ss << "    const std::string SVGIElement::commit() {" << std::endl;
    ss << "        std::stringstream ss;" << std::endl;
    ss << "" << std::endl;
    ss << "        _updated_raw_html = get_raw_HTML() != RawHTML.get_commit();" << std::endl;
    ss << "        RawHTML.commit();" << std::endl;
    ss << "        if (get_raw_HTML() != STR_NULL) return \"\";" << std::endl;
    ss << "" << std::endl;
    ss << "        // attribute differ" << std::endl;
    ss << "        for (auto &i : bound) {" << std::endl;
    ss << "            auto &cmd = _attr_commit[i]();" << std::endl;
    ss << "            if (cmd != STR_NULL) ss << cmd  << std::endl;" << std::endl;
    ss << "        }" << std::endl;
    ss << "        for (auto &i : modified) {" << std::endl;
    ss << "            auto &cmd = _attr_commit[i]();" << std::endl;
    ss << "            if (cmd != STR_NULL) ss << cmd  << std::endl;" << std::endl;
    ss << "        }" << std::endl;
    ss << "        modified.clear();" << std::endl;
    ss << "        " << std::endl;
    ss << "        // recursion" << std::endl;
    ss << "        std::vector<std::string> changed;" << std::endl;
    ss << "        for (auto &p : _inner_elements_commit) changed.push_back(p->commit());" << std::endl;
    ss << "        // extract change relation" << std::endl;
    ss << "        std::vector<int> removal;" << std::endl;
    ss << "        std::vector<int> addition;" << std::endl;
    ss << "        std::vector<std::pair<int, int>> unchanged;" << std::endl;
    ss << "        inner_differ_commit(removal, addition, unchanged);" << std::endl;
    ss << "        // remove" << std::endl;
    ss << "        int m = _inner_elements_commit.size(), n = _inner_elements_last.size();" << std::endl;
    ss << "        int *indices = new int[m], *removed = new int[n];" << std::endl;
    ss << "        std::fill(indices, indices + m, 0); std::fill(removed, removed + n, 0);" << std::endl;
    ss << "        for (auto &r : removal) removed[r] = 1;" << std::endl;
    ss << "        for (int i = 1; i < n; i++) removed[i] += removed[i - 1];" << std::endl;
    ss << "        for (auto &r : removal) ss << \"remove \" << r - (r > 0 ? removed[r - 1] : 0) << std::endl;" << std::endl;
    ss << "        // append" << std::endl;
    ss << "        for (auto &a : addition) {" << std::endl;
    ss << "            auto svg = _inner_elements_commit[a]->outer_SVG();" << std::endl;
    ss << "            ss << \"append \" << svg.size() << std::endl << svg << std::endl;" << std::endl;
    ss << "        }" << std::endl;
    ss << "        // changed" << std::endl;
    ss << "        for (auto &c : unchanged) {" << std::endl;
    ss << "            auto &a = c.first; auto &b = c.second;" << std::endl;
    ss << "            auto s = changed[a];" << std::endl;
    ss << "            if (s == STR_NULL) s = *_inner_elements_commit[b] - *_inner_elements_last[a]; // try differ" << std::endl;
    ss << "            if (s == STR_NULL) continue;" << std::endl;
    ss << "            ss << \"child \" << b - removed[b] << std::endl;" << std::endl;
    ss << "            ss << s;" << std::endl;
    ss << "            ss << \"parent\" << std::endl;" << std::endl;
    ss << "        }" << std::endl;
    ss << "        // sort" << std::endl;
    ss << "        for (auto &c : unchanged) {" << std::endl;
    ss << "            auto &a = c.first; auto &b = c.second;" << std::endl;
    ss << "            indices[b - removed[b]] = a;" << std::endl;
    ss << "        }" << std::endl;
    ss << "        for (int i = 0; i < addition.size(); i++) {" << std::endl;
    ss << "            auto &a = addition[i];" << std::endl;
    ss << "            indices[unchanged.size() + i] = a;" << std::endl;
    ss << "        }" << std::endl;
    ss << "        bool ordered = true;" << std::endl;
    ss << "        for (int i = 0; i < m && ordered; i++) if (indices[i] != i) ordered = false;" << std::endl;
    ss << "        if (!ordered) {" << std::endl;
    ss << "            ss << \"sort \\\"\";" << std::endl;
    ss << "            for (int i = 0; i < m; i++) {" << std::endl;
    ss << "                ss << indices[i];" << std::endl;
    ss << "                if (i < m - 1) ss << \",\";" << std::endl;
    ss << "            }" << std::endl;
    ss << "            ss << \"\\\"\" << std::endl;" << std::endl;
    ss << "        }" << std::endl;
    ss << "        delete[] removed; delete[] indices;" << std::endl;
    ss << "" << std::endl;
    ss << "        // commit inner changes" << std::endl;
    ss << "        _inner_elements_last.clear();" << std::endl;
    ss << "        SVGElement::set_inner_elements({});" << std::endl;
    ss << "        for (auto &p : _inner_elements_commit) {" << std::endl;
    ss << "            if (p->_updated_raw_html) p->_updated_raw_html = false;" << std::endl;
    ss << "            _inner_elements_last.push_back(p);" << std::endl;
    ss << "            SVGElement::add_inner_element(p);" << std::endl;
    ss << "        }" << std::endl;
    ss << "" << std::endl;
    ss << "        return ss.str();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const std::string SVGIElement::commit_this() {" << std::endl;
    ss << "        std::stringstream ss;" << std::endl;
    ss << "" << std::endl;
    ss << "        _updated_raw_html = get_raw_HTML() != RawHTML.get_commit();" << std::endl;
    ss << "        RawHTML.commit();" << std::endl;
    ss << "        if (get_raw_HTML() != STR_NULL) return \"\";" << std::endl;
    ss << "" << std::endl;
    ss << "        // attribute differ" << std::endl;
    ss << "        for (auto &i : bound) {" << std::endl;
    ss << "            auto &cmd = _attr_commit[i]();" << std::endl;
    ss << "            if (cmd != STR_NULL) ss << cmd  << std::endl;" << std::endl;
    ss << "        }" << std::endl;
    ss << "        for (auto &i : modified) {" << std::endl;
    ss << "            auto &cmd = _attr_commit[i]();" << std::endl;
    ss << "            if (cmd != STR_NULL) ss << cmd  << std::endl;" << std::endl;
    ss << "        }" << std::endl;
    ss << "        modified.clear();" << std::endl;
    ss << "" << std::endl;
    ss << "        // commit inner changes" << std::endl;
    ss << "        _inner_elements_last.clear();" << std::endl;
    ss << "        SVGElement::set_inner_elements({});" << std::endl;
    ss << "        for (auto &p : _inner_elements_commit) {" << std::endl;
    ss << "            if (p->_updated_raw_html) p->_updated_raw_html = false;" << std::endl;
    ss << "            _inner_elements_last.push_back(p);" << std::endl;
    ss << "            SVGElement::add_inner_element(p);" << std::endl;
    ss << "        }" << std::endl;
    ss << "" << std::endl;
    ss << "        return ss.str();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    void SVGIElement::inner_differ_commit(std::vector<int> &removal," << std::endl;
    ss << "            std::vector<int> &addition," << std::endl;
    ss << "            std::vector<std::pair<int, int>> &unchanged) const {" << std::endl;
    ss << "        std::function<const std::string(const std::shared_ptr<SVGIElement> &)> get_tag;" << std::endl;
    ss << "        int _uc;" << std::endl;
    ss << "        get_tag = [&](const std::shared_ptr<SVGIElement> &x){" << std::endl;
    ss << "            if (x->_updated_raw_html) return std::string(\"#\") + std::to_string(_uc++);" << std::endl;
    ss << "            return std::string(x->get_tag());" << std::endl;
    ss << "        };" << std::endl;
    ss << "        std::unordered_map<std::string, std::set<_i_el_idx>> tags_map;" << std::endl;
    ss << "        std::set<_i_el_idx> A, B;" << std::endl;
    ss << "        int c = 0;" << std::endl;
    ss << "        for (auto &a : _inner_elements_commit) A.insert({a, c++}); c = 0;" << std::endl;
    ss << "        for (auto &b : _inner_elements_last) tags_map[get_tag(b)].insert({b, c}), B.insert({b, c++});" << std::endl;
    ss << "" << std::endl;
    ss << "        c = 0;" << std::endl;
    ss << "        for (auto &_a : _inner_elements_commit) { // with outer hash equal" << std::endl;
    ss << "            auto &tag  = get_tag(_a);" << std::endl;
    ss << "            _i_el_idx a = { _a, c++ };" << std::endl;
    ss << "            if (!A.count(a) || !tags_map.count(tag)) continue;" << std::endl;
    ss << "            _i_el_idx match = { nullptr, -1 };" << std::endl;
    ss << "            for (auto &b : tags_map[tag]) {" << std::endl;
    ss << "                if (b.ptr->get_outer_hash() == a.ptr->get_outer_hash()) {" << std::endl;
    ss << "                    match = b;" << std::endl;
    ss << "                    break;" << std::endl;
    ss << "                }" << std::endl;
    ss << "            }" << std::endl;
    ss << "            if (match.idx >= 0) {" << std::endl;
    ss << "                tags_map[tag].erase(match);" << std::endl;
    ss << "                A.erase(a), B.erase(match);" << std::endl;
    ss << "                unchanged.push_back({a.idx, match.idx});" << std::endl;
    ss << "            }" << std::endl;
    ss << "        }" << std::endl;
    ss << "        c = 0;" << std::endl;
    ss << "        for (auto &_a : _inner_elements_commit) { // with inner hash equal" << std::endl;
    ss << "            auto &tag  = get_tag(_a);" << std::endl;
    ss << "            _i_el_idx a = { _a, c++ };" << std::endl;
    ss << "            if (!A.count(a) || !tags_map.count(tag)) continue;" << std::endl;
    ss << "            _i_el_idx match = { nullptr, -1 };" << std::endl;
    ss << "            for (auto &b : tags_map[tag]) {" << std::endl;
    ss << "                if (b.ptr->get_inner_hash() == a.ptr->get_inner_hash()) {" << std::endl;
    ss << "                    match = b;" << std::endl;
    ss << "                    break;" << std::endl;
    ss << "                }" << std::endl;
    ss << "            }" << std::endl;
    ss << "            if (match.idx >= 0) {" << std::endl;
    ss << "                tags_map[tag].erase(match);" << std::endl;
    ss << "                A.erase(a), B.erase(match);" << std::endl;
    ss << "                unchanged.push_back({a.idx, match.idx});" << std::endl;
    ss << "            }" << std::endl;
    ss << "        }" << std::endl;
    ss << "        c = 0;" << std::endl;
    ss << "        for (auto &_a : _inner_elements_commit) { // with attribute hash equal" << std::endl;
    ss << "            auto &tag  = get_tag(_a);" << std::endl;
    ss << "            _i_el_idx a = { _a, c++ };" << std::endl;
    ss << "            if (!A.count(a) || !tags_map.count(tag)) continue;" << std::endl;
    ss << "            _i_el_idx match = { nullptr, -1 };" << std::endl;
    ss << "            for (auto &b : tags_map[tag]) {" << std::endl;
    ss << "                if (b.ptr->get_attribute_hash() == a.ptr->get_attribute_hash()) {" << std::endl;
    ss << "                    match = b;" << std::endl;
    ss << "                    break;" << std::endl;
    ss << "                }" << std::endl;
    ss << "            }" << std::endl;
    ss << "            if (match.idx >= 0) {" << std::endl;
    ss << "                tags_map[tag].erase(match);" << std::endl;
    ss << "                A.erase(a), B.erase(match);" << std::endl;
    ss << "                unchanged.push_back({a.idx, match.idx});" << std::endl;
    ss << "            }" << std::endl;
    ss << "        }" << std::endl;
    ss << "        c = 0;" << std::endl;
    ss << "        for (auto &_a : _inner_elements_commit) { // with tag equal" << std::endl;
    ss << "            auto &tag  = get_tag(_a);" << std::endl;
    ss << "            _i_el_idx a = { _a, c++ };" << std::endl;
    ss << "            if (!A.count(a) || !tags_map.count(tag) || tags_map[tag].size() == 0) continue;" << std::endl;
    ss << "            _i_el_idx match = *tags_map[tag].begin();" << std::endl;
    ss << "            tags_map[tag].erase(match);" << std::endl;
    ss << "            A.erase(a), B.erase(match);" << std::endl;
    ss << "            unchanged.push_back({a.idx, match.idx});" << std::endl;
    ss << "        }" << std::endl;
    ss << "        for (auto &a : A) addition.push_back(a.idx);" << std::endl;
    ss << "        for (auto &b : B) removal.push_back(b.idx);" << std::endl;
    ss << "    }" << std::endl;
    ss << "    std::shared_ptr<SVGElement> SVGIElement::clone() const {" << std::endl;
    ss << "        auto cloned = std::make_shared<SVGElement>();" << std::endl;
    ss << "        *cloned = *this;" << std::endl;
    ss << "        return cloned;" << std::endl;
    ss << "    }" << std::endl;
    ss << "    std::shared_ptr<SVGIElement> SVGIElement::clone(bool identity) const {" << std::endl;
    ss << "        auto cloned = std::make_shared<SVGIElement>();" << std::endl;
    ss << "        *cloned = *this;" << std::endl;
    ss << "        return cloned;" << std::endl;
    ss << "    }" << std::endl;
    ss << "    SVGElement &SVGIElement::operator=(const SVGElement &element) {" << std::endl;
    ss << "        SVGElement::operator=(element);" << std::endl;
    ss << "        return *this;" << std::endl;
    ss << "    }" << std::endl;
    ss << "    SVGIElement &SVGIElement::operator=(const SVGIElement &element) {" << std::endl;
    ss << "        SVGElement::operator=(element);" << std::endl;
    for (auto &p : attributes_i) ss << p->copy();
    ss << std::endl;
    ss << "        _bind_getter_setter();" << std::endl;
    ss << "        return *this;" << std::endl;
    ss << "    }" << std::endl;
    ss << "    bool SVGIElement::operator==(const SVGElement &element) const {" << std::endl;
    ss << "        return SVGElement::operator==(element);" << std::endl;
    ss << "    }" << std::endl;
    ss << "    bool SVGIElement::operator!=(const SVGElement &element) const {" << std::endl;
    ss << "        return SVGElement::operator!=(element);" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const std::string SVGIElement::operator-(const SVGElement &element) const {" << std::endl;
    ss << "        return SVGElement::operator-(element);" << std::endl;
    ss << "    }" << std::endl;
    ss << "}" << std::endl;
    return ss.str();
}

std::string SVGIH(const std::vector<std::string> &tags) {
    std::stringstream ss;
    ss << "#ifndef __LZ_SVGI_ELEMENT__" << std::endl;
    ss << "#define __LZ_SVGI_ELEMENT__" << std::endl;
    ss << "#include <set>" << std::endl;
    ss << "#include \"svgi_el/attr.hpp\"" << std::endl;
    ss << "#include \"svg_el.h\"" << std::endl;
    ss << "" << std::endl;
    ss << "namespace Lewzen {" << std::endl;
    ss << "    /**" << std::endl;
    ss << "    * An SVG element interface." << std::endl;
    ss << "    */" << std::endl;
    ss << "    class SVGIElement : public virtual SVGElement {" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Constructor of SVG element interface." << std::endl;
    ss << "        */" << std::endl;
    ss << "        SVGIElement();" << std::endl;
    ss << "    protected:" << std::endl;
    ss << "        virtual void _bind_getter_setter();" << std::endl;
    ss << "" << std::endl;
    ss << "        /// Tag" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get tag name of this element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return tag name." << std::endl;
    ss << "        */" << std::endl;
    ss << "        const std::string get_tag() const;" << std::endl;
    ss << "" << std::endl;
    ss << "        /// Attributes" << std::endl;
    for (auto &p : attributes_i) ss << p->domain();
    ss << std::endl;
    ss << "    private:" << std::endl;
    ss << "        std::set<int> bound;" << std::endl;
    ss << "        std::set<int> modified;" << std::endl;
    ss << "        const std::array<std::function<void(const std::string &)>, " << attributes_i.size() << "> _attr_on_assign = {" << std::endl;
    for (auto &p : attributes_i) ss << p->on_assign();
    ss << "        };" << std::endl;
    ss << "        const std::array<std::function<void()>, " << attributes_i.size() << "> _attr_on_bind = {" << std::endl;
    for (auto &p : attributes_i) ss << p->on_bind();
    ss << "        };" << std::endl;
    ss << "        const std::array<std::function<const std::string()>, " << attributes_i.size() << "> _attr_commit = {" << std::endl;
    for (auto &p : attributes_i) ss << p->on_commit();
    ss << "        };" << std::endl;
    ss << std::endl;
    ss << "    private:" << std::endl;
    ss << "        using SVGElement::inner_SVG;" << std::endl;
    ss << "        using SVGElement::set_raw_HTML;" << std::endl;
    ss << "        using SVGElement::get_raw_HTML;" << std::endl;
    ss << "        using SVGElement::add_inner_element;" << std::endl;
    ss << "        using SVGElement::remove_inner_element;" << std::endl;
    ss << "        using SVGElement::get_inner_element;" << std::endl;
    ss << "        using SVGElement::get_inner_elements;" << std::endl;
    ss << "        using SVGElement::set_inner_elements;" << std::endl;
    ss << "        using SVGElement::get_attribute_hash;" << std::endl;
    ss << "        using SVGElement::get_inner_hash;" << std::endl;
    ss << "        using SVGElement::get_outer_hash;" << std::endl;
    ss << "    private:" << std::endl;
    for (auto &p : attributes_i) ss << p->hide();
    ss << "    " << std::endl;
    ss << "        /// Inner SVG" << std::endl;
    ss << "    protected:" << std::endl;
    ss << "        std::string _inner_text_commit;" << std::endl;
    ss << "        std::vector<std::shared_ptr<SVGIElement>> _inner_elements_commit;" << std::endl;
    ss << "        std::vector<std::shared_ptr<SVGIElement>> _inner_elements_last;" << std::endl;
    ss << "        std::weak_ptr<SVGIElement> _parent_element_commit;" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        AttrAnything RawHTML;" << std::endl;
    ss << "    private:" << std::endl;
    ss << "        bool _updated_raw_html = false;" << std::endl;
    ss << "    protected:" << std::endl;
    ss << "        struct _i_el_idx {" << std::endl;
    ss << "            std::shared_ptr<SVGIElement> ptr;" << std::endl;
    ss << "            int idx;" << std::endl;
    ss << "            bool operator<(const _i_el_idx &b) const {" << std::endl;
    ss << "                if (ptr == b.ptr) return idx < b.idx;" << std::endl;
    ss << "                return ptr < b.ptr;" << std::endl;
    ss << "            }" << std::endl;
    ss << "        };" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Compare inner elements before and after commitment." << std::endl;
    ss << "        */" << std::endl;
    ss << "        void inner_differ_commit(std::vector<int> &removal," << std::endl;
    ss << "            std::vector<int> &addition," << std::endl;
    ss << "            std::vector<std::pair<int, int>> &unchanged) const;" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get inner SVG of this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return inner SVG." << std::endl;
    ss << "        */" << std::endl;
    ss << "        const std::string inner_SVG() const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Add a sub element to this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @param element an inner element." << std::endl;
    ss << "        * @param index the index to be insert. default -1 means tail." << std::endl;
    ss << "        */" << std::endl;
    ss << "        void add(const std::shared_ptr<SVGIElement> &element, int index = -1);" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Remove a child element or child elements from this SVG element, based on content." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @param element an inner element." << std::endl;
    ss << "        * @param remove_all if to remove all occurances." << std::endl;
    ss << "        */" << std::endl;
    ss << "        void remove(const std::shared_ptr<SVGIElement> &element, bool remove_all = false);" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Remove a child element or child elements from this SVG element, by index." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @param index the index of inner element." << std::endl;
    ss << "        */" << std::endl;
    ss << "        void remove(int index);" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get inner SVG element in this SVG element, by index." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return inner element." << std::endl;
    ss << "        */" << std::endl;
    ss << "        std::shared_ptr<SVGIElement> child(int index) const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get inner SVG elements list in this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return inner element list, readonly." << std::endl;
    ss << "        */" << std::endl;
    ss << "        const std::vector<std::shared_ptr<SVGIElement>> children() const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Set inner SVG elements list in this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @param inner_elements inner elements list." << std::endl;
    ss << "        */" << std::endl;
    ss << "        void children(const std::vector<std::shared_ptr<SVGIElement>> &inner_elements);" << std::endl;
    ss << "    " << std::endl;
    ss << "        /// Outer SVG" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get SVG of this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return outer SVG." << std::endl;
    ss << "        */" << std::endl;
    ss << "        const std::string outer_SVG() const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get hash of outer SVG." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return hash of outer SVG." << std::endl;
    ss << "        */" << std::endl;
    ss << "        const HASH_CODE hash() const;" << std::endl;
    ss << "" << std::endl;
    ss << "        /// Operators" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Commit all changes and get DOM commands." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGIElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual const std::string commit();" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Commit all changes in this element and get DOM commands. (ignoring children)" << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGIElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual const std::string commit_this();" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Deep copy this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGIElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual std::shared_ptr<SVGElement> clone() const override;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Deep copy this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGIElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        std::shared_ptr<SVGIElement> clone(bool identity) const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Assigning SVG element by deep copy." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGIElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual SVGElement &operator=(const SVGElement &element) override;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Assigning SVG element by deep copy." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGIElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual SVGIElement &operator=(const SVGIElement &element);" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Compare two SVG elements." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGIElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        bool operator==(const SVGElement &element) const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Compare two SVG elements." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGIElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        bool operator!=(const SVGElement &element) const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * SVG substraction, returning differences." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGIElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual const std::string operator-(const SVGElement &element) const;" << std::endl;
    ss << "    };" << std::endl;
    ss << "}" << std::endl;
    
    fs::path p(out_dir);
    fs::path base(base_dir);
    auto ip = fs::relative(p, base).generic_string();
    ss << std::endl;
    for (auto &tag : tags) {
        ss << "#include \"" << ip << "/svgi_" << tag <<".h\"" << std::endl;
    }
    ss << "#endif" << std::endl;
    return ss.str();
}

const std::string CPPFile(const std::string &tag, const std::string &comment, const std::vector<std::shared_ptr<Attribute>> attributes) {
    fs::path p(out_dir);
    fs::path base(base_dir);
    auto ip = fs::relative(base, p).generic_string();
    std::stringstream ss;
    
    ss << "#include \"svgi_" + dom_to_snake(tag) + ".h\"" << std::endl;
    ss << "" << std::endl;
    ss << "namespace Lewzen {" << std::endl;
    ss << "    SVGI" << dom_to_pascal(tag) << "::SVGI" << dom_to_pascal(tag) << "(): SVGIElement() { SVGI" << dom_to_pascal(tag) << "::_bind_getter_setter(); }" << std::endl;
    ss << "    void SVGI" << dom_to_pascal(tag) << "::_bind_getter_setter() {" << std::endl;
    for (auto &p : attributes) ss << p->get_set();
    ss << "        SVGIElement::_bind_getter_setter();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const std::string SVGI" << dom_to_pascal(tag) << "::get_tag() const {" << std::endl;
    ss << "        return \"" << tag << "\";" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const std::string SVGI" << dom_to_pascal(tag) << "::outer_SVG() const {" << std::endl;
    ss << "        return SVGIElement::outer_SVG();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const std::string SVGI" << dom_to_pascal(tag) << "::commit() {" << std::endl;
    ss << "        std::stringstream ss;" << std::endl;
    ss << "" << std::endl;
    ss << "        // attribute differ" << std::endl;
    ss << "        for (auto &i : bound) {" << std::endl;
    ss << "            auto &cmd = _attr_commit[i]();" << std::endl;
    ss << "            if (cmd != STR_NULL) ss << cmd  << std::endl;" << std::endl;
    ss << "        }" << std::endl;
    ss << "        for (auto &i : modified) {" << std::endl;
    ss << "            auto &cmd = _attr_commit[i]();" << std::endl;
    ss << "            if (cmd != STR_NULL) ss << cmd  << std::endl;" << std::endl;
    ss << "        }" << std::endl;
    ss << "        modified.clear();" << std::endl;
    ss << "" << std::endl;
    ss << "        // base class" << std::endl;
    ss << "        ss << SVGIElement::commit();" << std::endl;
    ss << "" << std::endl;
    ss << "        return ss.str();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const std::string SVGI" << dom_to_pascal(tag) << "::commit_this() {" << std::endl;
    ss << "        std::stringstream ss;" << std::endl;
    ss << "" << std::endl;
    ss << "        // attribute differ" << std::endl;
    ss << "        for (auto &i : bound) {" << std::endl;
    ss << "            auto &cmd = _attr_commit[i]();" << std::endl;
    ss << "            if (cmd != STR_NULL) ss << cmd  << std::endl;" << std::endl;
    ss << "        }" << std::endl;
    ss << "        for (auto &i : modified) {" << std::endl;
    ss << "            auto &cmd = _attr_commit[i]();" << std::endl;
    ss << "            if (cmd != STR_NULL) ss << cmd  << std::endl;" << std::endl;
    ss << "        }" << std::endl;
    ss << "        modified.clear();" << std::endl;
    ss << "" << std::endl;
    ss << "        // base class" << std::endl;
    ss << "        ss << SVGIElement::commit_this();" << std::endl;
    ss << "" << std::endl;
    ss << "        return ss.str();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    std::shared_ptr<SVGElement> SVGI" << dom_to_pascal(tag) << "::clone() const {" << std::endl;
    ss << "        auto cloned = std::make_shared<SVGElement>();" << std::endl;
    ss << "        cloned->SVGElement::operator=(*this);" << std::endl;
    ss << "        return cloned;" << std::endl;
    ss << "    }" << std::endl;
    ss << "    std::shared_ptr<SVGI" << dom_to_pascal(tag) << "> SVGI" << dom_to_pascal(tag) << "::clone(bool identity) const {" << std::endl;
    ss << "        auto cloned = std::make_shared<SVGI" << dom_to_pascal(tag) << ">();" << std::endl;
    ss << "        *cloned = *this;" << std::endl;
    ss << "        return cloned;" << std::endl;
    ss << "    }" << std::endl;
    ss << "    SVGElement &SVGI" << dom_to_pascal(tag) << "::operator=(const SVGElement &element) {" << std::endl;
    ss << "        SVGElement::operator=(element);" << std::endl;
    ss << "        return *this;" << std::endl;
    ss << "    }" << std::endl;
    ss << "    SVGI" << dom_to_pascal(tag) << " &SVGI" << dom_to_pascal(tag) << "::operator=(const SVGI" << dom_to_pascal(tag) << " &element) {" << std::endl;
    ss << "        SVGIElement::operator=(static_cast<SVGIElement>(element));" << std::endl;
    for (auto &p : attributes) ss << p->copy();
    ss << std::endl;
    ss << "        _bind_getter_setter();" << std::endl;
    ss << "        return *this;" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const std::string SVGI" << dom_to_pascal(tag) << "::operator-(const SVGElement &element) const {" << std::endl;
    ss << "        return SVG" << dom_to_pascal(tag) << "::operator-(element);" << std::endl;
    ss << "    }" << std::endl;
    ss << "}" << std::endl;
    return ss.str();
}

const std::string HeaderFile(const std::string &tag, const std::string &comment, const std::vector<std::shared_ptr<Attribute>> attributes) {
    fs::path p(out_dir);
    fs::path base(base_dir);
    auto ip = fs::relative(base, p).generic_string();
    std::stringstream ss;

    ss << "#ifndef __LZ_SVGI_" << dom_to_snake(tag, true) << "__" << std::endl;
    ss << "#define __LZ_SVGI_" << dom_to_snake(tag, true) << "__" << std::endl;
    ss << "#include \"../svgi_el.h\"" << std::endl;
    ss << "" << std::endl;
    ss << "namespace Lewzen {" << std::endl;
    ss << "    /**" << std::endl;
    ss << "    * " << comment << std::endl;
    ss << "    */" << std::endl;
    ss << "    class SVGI" << dom_to_pascal(tag) << " : public virtual SVGIElement, public virtual SVG" << dom_to_pascal(tag) << " {" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Constructor of circle." << std::endl;
    ss << "        */" << std::endl;
    ss << "        SVGI" << dom_to_pascal(tag) << "();" << std::endl;
    ss << "    protected:" << std::endl;
    ss << "        virtual void _bind_getter_setter() override;" << std::endl;
    ss << std::endl;
    ss << "        /// Tag" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get tag name of this element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return tag name." << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual const std::string get_tag() const override;" << std::endl;
    ss << std::endl;
    ss << "    private:" << std::endl;
    ss << "        void add_inner_element(const std::shared_ptr<SVGElement> &element) = delete;" << std::endl;
    ss << "        void remove_inner_element(const std::shared_ptr<SVGElement> &element, bool remove_all = false) = delete;" << std::endl;
    for (auto &p : attributes) ss << p->hide();
    for (auto &p : attributes_i) ss << p->hide();
    ss << std::endl;
    ss << "        /// Outer SVG" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get SVG of this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return outer SVG." << std::endl;
    ss << "        */" << std::endl;
    ss << "        const std::string outer_SVG() const;" << std::endl;
    ss << std::endl;
    ss << "        /// " << dom_to_pascal(tag) << "" << std::endl;
    for (auto &p : attributes) ss << p->domain();
    ss << "    private:" << std::endl;
    ss << "        std::set<int> bound;" << std::endl;
    ss << "        std::set<int> modified;" << std::endl;
    ss << "        const std::array<std::function<void(const std::string &)>, " << attributes.size() << "> _attr_on_assign = {" << std::endl;
    for (auto &p : attributes) ss << p->on_assign();
    ss << "        };" << std::endl;
    ss << "        const std::array<std::function<void()>, " << attributes.size() << "> _attr_on_bind = {" << std::endl;
    for (auto &p : attributes) ss << p->on_bind();
    ss << "        };" << std::endl;
    ss << "        const std::array<std::function<const std::string()>, " << attributes.size() << "> _attr_commit = {" << std::endl;
    for (auto &p : attributes) ss << p->on_commit();
    ss << "        };" << std::endl;
    ss << "" << std::endl;
    ss << "        /// Operators" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Commit all changes and get DOM commands." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGIElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual const std::string commit() override;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Commit all changes in this element and get DOM commands. (ignoring children)" << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGIElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual const std::string commit_this() override;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Deep copy this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGIElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual std::shared_ptr<SVGElement> clone() const override;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Deep copy this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGIElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        std::shared_ptr<SVGI" << dom_to_pascal(tag) << "> clone(bool identity) const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Assigning SVG element by deep copy." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGIElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual SVGElement &operator=(const SVGElement &element) override;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Assigning SVG element by deep copy." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGIElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual SVGI" << dom_to_pascal(tag) << " &operator=(const SVGI" << dom_to_pascal(tag) << " &element);" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * SVG substraction, returning differences." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGIElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual const std::string operator-(const SVGElement &element) const override;" << std::endl;
    ss << "    };" << std::endl;
    ss << "}" << std::endl;
    ss << "#endif" << std::endl;
    return ss.str();
}

const std::string Makefile(const std::vector<std::string> &tags) {
    std::stringstream ss;
    ss << "objects = \\" << std::endl;
    for (int i = 0; i < tags.size(); i++) {
        ss << "\tsvgi_" << tags[i] << ".o";
        if (i < tags.size() - 1) ss << "\\";
        ss << std::endl;
    }
    ss << "cc = g++" << std::endl;
    ss << std::endl;
    ss << ".PHONY: all" << std::endl;
    ss << "all: $(objects)" << std::endl;
    ss << std::endl;
    for (auto &tag : tags) ss << "svgi_" << tag << ".o: svgi_" << tag << ".cpp svgi_" << tag << ".h" << std::endl << "\t$(cc) -w -c svgi_" << tag << ".cpp" << std::endl;
    ss << std::endl;
    ss << ".PHONY: all" << std::endl;
    ss << "clean:" << std::endl;
	ss << "\t-rm $(objects)" << std::endl;
    return ss.str();
}

const std::string json_to_source(const std::string &path) {
    fs::path p(path);
    if (p.extension() != ".json") return "";
    std::ifstream i(path);
    json j; i >> j;
    
    std::string tag = j["tag"];
    std::string comment = j["comment"];
    comment = std::regex_replace(comment, std::regex("\n"), "\n        * ");
    std::vector<std::shared_ptr<Attribute>> attributes;
    int _i = 0;
    for (auto &atr : j["attributes"]) {
        std::string name = atr["name"];
        std::string type = atr["type"];
        std::string acom = atr["comment"];
        attributes.push_back(std::make_shared<Attribute>(tag, name, type, acom, _i++));
    }

    std::ofstream o1(out_dir + "/svgi_" + dom_to_snake(tag) + ".h");
    o1 << HeaderFile(tag, comment, attributes);

    std::ofstream o2(out_dir + "/svgi_" + dom_to_snake(tag) + ".cpp");
    o2 << CPPFile(tag, comment, attributes);

    std::cout << "done : " << tag << std::endl;
    return tag;
}

int main(int argc, char **argv) {
    std::ifstream i(json_dir + "/_svg._json");
    json j; i >> j;
    int _i = 0;
    for (auto &atr : j["attributes"]) {
        std::string name = atr["name"];
        std::string type = atr["type"];
        std::string acom = atr["comment"];
        attributes_i.push_back(std::make_shared<Attribute>("element", name, type, acom, _i++));
    }

    std::vector<std::string> tags;
    for (const auto &file : fs::directory_iterator(json_dir)) {
        auto tag = json_to_source(file.path());
        if (tag != "") tags.push_back(dom_to_snake(tag));
    }
    
    std::ofstream o1(out_dir + "/Makefile");
    o1 << Makefile(tags);
    std::cout << "Makefile done." << std::endl;

    o1 = std::ofstream(base_dir + "/svgi_el.cpp");
    o1 << SVGICPP();

    o1 = std::ofstream(base_dir + "/svgi_el.h");
    o1 << SVGIH(tags);
    
    std::cout << "svgi_el done." << std::endl;
}