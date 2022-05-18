#include <string>
#include <vector>
#include <set>
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
        } else {
            pascal.push_back(to_bcase(dom[i], uppercase));
            uppercase = false;
        }
    }
    return pascal;
}

class Attribute {
protected:
    std::string _tag;
    std::string _name;
    std::string _comment;
public:
    Attribute(const std::string &tag, const std::string &name, const std::string &comment): _tag(tag), _name(name), _comment(comment) {}
    // ttt _xxx
    virtual const std::string private_domain() const = 0;
    // _xxx = ...
    virtual const std::string init_default() const = 0;
    // _xxx = ...
    const std::string init_clone() const {
        std::stringstream ss;
        ss << "        _" << dom_to_snake(_name) <<" = element.get_" << dom_to_snake(_name) <<"();" << std::endl;
        return ss.str();
    }
    // ttt get_xxx() const;
    virtual const std::string getter_defination() const = 0;
    // void set_xxx(const ttt &xxx);
    virtual const std::string setter_defination() const = 0;
    // ttt get_xxx() const;
    virtual const std::string getter_implemetation() const = 0;
    // void set_xxx(const ttt &xxx);
    virtual const std::string setter_implemetation() const = 0;
    // if (_xxx != ...) ss << "...=" << ...
    virtual const std::string str_get_attributes() const = 0;
    // if (_xxx != _element.get_xxx()) ...
    virtual const std::string str_operator_minus() const = 0;
};

std::vector<std::shared_ptr<Attribute>> _attributes;
std::set<std::string> _attribute_names;

class StringAttribute: public Attribute {
public:
    StringAttribute(const std::string &tag, const std::string &name, const std::string &comment): Attribute(tag, name, comment) {
        _comment = std::regex_replace(_comment, std::regex("\n"), "\n        * ");
    }
    const std::string private_domain() const {
        std::stringstream ss;
        ss << "    private:" << std::endl;
        ss << "        std::string _" << dom_to_snake(_name) <<";" << std::endl;
        return ss.str();
    }
    const std::string init_default() const {
        std::stringstream ss;
        ss << "        _" << dom_to_snake(_name) <<" = STR_NULL;" << std::endl;
        return ss.str();
    }
    const std::string getter_defination() const {
        std::string override = (_attribute_names.count(_name) && _tag != "element") ? " override" : "";
        std::stringstream ss;
        ss << "        /**" << std::endl;
        ss << "        * " << _comment << std::endl;
        ss << "        *" << std::endl;
        ss << "        * @return the " << _name << std::endl;
        ss << "        */" << std::endl;
        ss << "        virtual const std::string get_" << dom_to_snake(_name) << "() const" << override << ";" << std::endl;
        return ss.str();
    }
    const std::string setter_defination() const {
        std::string override = (_attribute_names.count(_name) && _tag != "element") ? " override" : "";
        std::stringstream ss;
        ss << "        /**" << std::endl;
        ss << "        * " << _comment << std::endl;
        ss << "        *" << std::endl;
        ss << "        * @param  the " << _name << std::endl;
        ss << "        */" << std::endl;
        ss << "        virtual void set_" << dom_to_snake(_name) << "(const std::string &" << ((dom_to_snake(_name) == "class") ? "cls" : dom_to_snake(_name)) << ")" << override << ";" << std::endl;
        return ss.str();
    }
    const std::string getter_implemetation() const {
        std::stringstream ss;
        ss << "    const std::string SVG" << dom_to_pascal(_tag) << "::get_" << dom_to_snake(_name) << "() const {" << std::endl;
        ss << "        return _" << dom_to_snake(_name) << ";" << std::endl;
        ss << "    }" << std::endl;
        return ss.str();
    }
    const std::string setter_implemetation() const {
        std::stringstream ss;
        ss << "    void SVG" << dom_to_pascal(_tag) << "::set_" << dom_to_snake(_name) << "(const std::string &" << ((dom_to_snake(_name) == "class") ? "cls" : dom_to_snake(_name)) << ") {" << std::endl;
        ss << "        _" << dom_to_snake(_name) << " = " << ((dom_to_snake(_name) == "class") ? "cls" : dom_to_snake(_name)) << ";" << std::endl;
        ss << "        update_attribute_hash();" << std::endl;
        ss << "    }" << std::endl;
        return ss.str();
    }
    const std::string str_get_attributes() const {
        std::stringstream ss;
        ss << "        if (_" << dom_to_snake(_name) << " != STR_NULL) ss << \" " << _name << "=\\\"\" << _" << dom_to_snake(_name) << " << \"\\\"\";" << std::endl;;
        return ss.str();
    }
    const std::string str_operator_minus() const {
        std::stringstream ss;
        ss << "        if (_" << dom_to_snake(_name) << " != element.get_" << dom_to_snake(_name) << "()) {" << std::endl;;
        ss << "            if (_" << dom_to_snake(_name) << " == STR_NULL) ss << \"reset " << _name << "\" << std::endl;" << std::endl;;
        ss << "            else ss << \"modify " << _name << " \\\"\" << _" << dom_to_snake(_name) << " << \"\\\"\" << std::endl;" << std::endl;;
        ss << "        }" << std::endl;
        return ss.str();
    }
};

std::string SVGCPP() {
    std::stringstream ss;
    ss << "#include <sstream>" << std::endl;
    ss << "#include <algorithm>" << std::endl;
    ss << "#include <map>" << std::endl;
    ss << "#include <unordered_map>" << std::endl;
    ss << "#include \"svg_el.h\"" << std::endl;
    ss << "" << std::endl;
    ss << "namespace Lewzen {" << std::endl;
    ss << "    SVGElement::SVGElement() {" << std::endl;
    for (auto &p : _attributes) ss << p->init_default();
    ss << "        _raw_HTML = STR_NULL;" << std::endl;
    ss << "" << std::endl;
    ss << "        _attribute_hash = 0;" << std::endl;
    ss << "        _inner_hash = 0;" << std::endl;
    ss << "        _outer_hash = 0;" << std::endl;
    ss << "    }" << std::endl;
    ss << "" << std::endl;
    ss << "    const std::string SVGElement::get_tag() const {" << std::endl;
    ss << "        return \"?\";" << std::endl;
    ss << "    }" << std::endl;
    for (auto &p : _attributes) ss << p->getter_implemetation() << p->setter_implemetation();
    ss << "" << std::endl;
    ss << "        const std::string SVGElement::inner_SVG() const {" << std::endl;
    ss << "        std::stringstream ss;" << std::endl;
    ss << "        if (_raw_HTML != STR_NULL) ss << _raw_HTML;" << std::endl;
    ss << "        for (auto &p : _inner_elements) ss << p->outer_SVG();" << std::endl;
    ss << "        return ss.str();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    void SVGElement::set_raw_HTML(const std::string &text) {" << std::endl;
    ss << "        _raw_HTML = text;" << std::endl;
    ss << "        update_inner_hash();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const std::string SVGElement::get_raw_HTML() const {" << std::endl;
    ss << "        return _raw_HTML;" << std::endl;
    ss << "    }" << std::endl;
    ss << "    void SVGElement::add_inner_element(const std::shared_ptr<SVGElement> &inner_element, int index) {" << std::endl;
    ss << "        if (auto sp = inner_element->_parent_element.lock()) {" << std::endl;
    ss << "            auto &els = sp->_inner_elements;" << std::endl;
    ss << "            els.erase(std::remove(els.begin(), els.end(), inner_element), els.end());" << std::endl;
    ss << "        }" << std::endl;
    ss << "        inner_element->_parent_element = shared_from_this();" << std::endl;
    ss << "        if (index == -1) _inner_elements.push_back(inner_element);" << std::endl;
    ss << "        else _inner_elements.insert(_inner_elements.begin() + index, inner_element);" << std::endl;
    ss << "        update_inner_hash();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    void SVGElement::remove_inner_element(const std::shared_ptr<SVGElement> &inner_element, bool remove_all) {" << std::endl;
    ss << "        bool success;" << std::endl;
    ss << "        std::vector<std::shared_ptr<SVGElement>> removed;" << std::endl;
    ss << "        _inner_elements.erase(std::remove_if(_inner_elements.begin(), _inner_elements.end()," << std::endl;
    ss << "                                [&](const std::shared_ptr<SVGElement>& _inner_element) { " << std::endl;
    ss << "                                    if (success && !remove_all) return false;" << std::endl;
    ss << "                                    if (_inner_element->get_outer_hash() == inner_element->get_outer_hash()) {" << std::endl;
    ss << "                                        success = true;" << std::endl;
    ss << "                                        removed.push_back(_inner_element);" << std::endl;
    ss << "                                        return true;" << std::endl;
    ss << "                                    }" << std::endl;
    ss << "                                    return false;" << std::endl;
    ss << "                                }), _inner_elements.end());" << std::endl;
    ss << "        success = false;" << std::endl;
    ss << "        for (auto &p : removed) p->_parent_element = std::weak_ptr<SVGElement>();" << std::endl;
    ss << "        update_inner_hash();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    void SVGElement::remove_inner_element(int index) {" << std::endl;
    ss << "        _inner_elements[index]->_parent_element = std::weak_ptr<SVGElement>();" << std::endl;
    ss << "        _inner_elements.erase(_inner_elements.begin() + index);" << std::endl;
    ss << "        update_inner_hash();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    std::shared_ptr<SVGElement> SVGElement::get_inner_element(int index) const {" << std::endl;
    ss << "        return _inner_elements[index];" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const std::vector<std::shared_ptr<SVGElement>> SVGElement::get_inner_elements() const {" << std::endl;
    ss << "        return _inner_elements;" << std::endl;
    ss << "    }" << std::endl;
    ss << "    void SVGElement::set_inner_elements(const std::vector<std::shared_ptr<SVGElement>> &inner_elements) {" << std::endl;
    ss << "        while (_inner_elements.size() > 0) remove_inner_element(0);" << std::endl;
    ss << "        for (auto p : inner_elements) add_inner_element(p);" << std::endl;
    ss << "        update_inner_hash();" << std::endl;
    ss << "    }" << std::endl;
    ss << "" << std::endl;
    ss << "    const std::string SVGElement::get_attributes() const {" << std::endl;
    ss << "        std::stringstream ss;" << std::endl;
    ss << "" << std::endl;
    for (auto &p : _attributes) ss << p->str_get_attributes();
    ss << "        " << std::endl;
    ss << "        return ss.str();" << std::endl;
    ss << "    }" << std::endl;
    ss << "" << std::endl;
    ss << "    const std::string SVGElement::outer_SVG() const {" << std::endl;
    ss << "        if (_raw_HTML != STR_NULL) return _raw_HTML;" << std::endl;
    ss << "" << std::endl;
    ss << "        std::stringstream ss;" << std::endl;
    ss << "" << std::endl;
    ss << "        ss << \"<\" << get_tag();" << std::endl;
    ss << "" << std::endl;
    ss << "        const std::string _attributes = get_attributes();" << std::endl;
    ss << "        if (_attributes != \"\") ss << _attributes;" << std::endl;
    ss << "" << std::endl;
    ss << "        auto _inner_svg = inner_SVG();" << std::endl;
    ss << "        if (_inner_svg == \"\") {" << std::endl;
    ss << "            ss << \"/>\";" << std::endl;
    ss << "        } else {" << std::endl;
    ss << "            ss << \">\" << _inner_svg << \"</\" << get_tag() << \">\";" << std::endl;
    ss << "        }" << std::endl;
    ss << "" << std::endl;
    ss << "        return ss.str();" << std::endl;
    ss << "    }" << std::endl;
    ss << "" << std::endl;
    ss << "    void SVGElement::update_outer_hash() {" << std::endl;
    ss << "        // has raw html" << std::endl;
    ss << "        if (_raw_HTML != STR_NULL) {" << std::endl;
    ss << "            _attribute_hash = _inner_hash = 0;" << std::endl;
    ss << "            _outer_hash = str_hash(_raw_HTML);" << std::endl;
    ss << "        }" << std::endl;
    ss << "        // update outer hash by attribute hash and inner hash" << std::endl;
    ss << "        else {" << std::endl;
    ss << "            std::stringstream ss;" << std::endl;
    ss << "            ss << get_tag() << \",\";" << std::endl;
    ss << "            ss << _attribute_hash << \",\";" << std::endl;
    ss << "            ss << _inner_hash;" << std::endl;
    ss << "            _outer_hash = str_hash(ss.str());" << std::endl;
    ss << "        }" << std::endl;
    ss << "" << std::endl;
    ss << "        // update parent element" << std::endl;
    ss << "        if (auto sp = _parent_element.lock()) {" << std::endl;
    ss << "            sp->update_inner_hash();" << std::endl;
    ss << "        }" << std::endl;
    ss << "    }" << std::endl;
    ss << "    void SVGElement::update_attribute_hash() {" << std::endl;
    ss << "        // update attribute hash" << std::endl;
    ss << "        if (_raw_HTML == STR_NULL) {" << std::endl;
    ss << "            _attribute_hash = str_hash(get_attributes());" << std::endl;
    ss << "        }" << std::endl;
    ss << "" << std::endl;
    ss << "        // update outer hash" << std::endl;
    ss << "        update_outer_hash();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    void SVGElement::update_inner_hash() {" << std::endl;
    ss << "        // inner string + (inner elements)" << std::endl;
    ss << "        if (_raw_HTML == STR_NULL) {" << std::endl;
    ss << "            std::stringstream ss;" << std::endl;
    ss << "            ss << get_raw_HTML() << \",\";" << std::endl;
    ss << "            for (auto p : _inner_elements) ss << p->get_outer_hash() << \",\";" << std::endl;
    ss << "            _inner_hash = str_hash(ss.str());" << std::endl;
    ss << "        }" << std::endl;
    ss << "" << std::endl;
    ss << "        // update outer hash" << std::endl;
    ss << "        update_outer_hash();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const HASH_CODE SVGElement::get_attribute_hash() const {" << std::endl;
    ss << "        return _attribute_hash;" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const HASH_CODE SVGElement::get_inner_hash() const {" << std::endl;
    ss << "        return _inner_hash;" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const HASH_CODE SVGElement::get_outer_hash() const {" << std::endl;
    ss << "        return _outer_hash;" << std::endl;
    ss << "    }" << std::endl;
    ss << "" << std::endl;
    ss << "    std::shared_ptr<SVGElement> SVGElement::clone() const {" << std::endl;
    ss << "        auto cloned =  std::make_shared<SVGElement>();" << std::endl;
    ss << "        *cloned = *this;" << std::endl;
    ss << "        return cloned;" << std::endl;
    ss << "    }" << std::endl;
    ss << "    SVGElement &SVGElement::operator=(const SVGElement &element) {" << std::endl;
    for (auto &p : _attributes) ss << p->init_clone();
    ss << "" << std::endl;
    ss << "        _raw_HTML = element.get_raw_HTML();" << std::endl;
    ss << "        for (auto p : element.get_inner_elements()) {" << std::endl;
    ss << "            auto cloned = p->clone();" << std::endl;
    ss << "            _inner_elements.push_back(cloned);" << std::endl;
    ss << "            p->_parent_element = cloned;" << std::endl;
    ss << "        }" << std::endl;
    ss << "" << std::endl;
    ss << "        _attribute_hash = element.get_attribute_hash();" << std::endl;
    ss << "        _inner_hash = element.get_inner_hash();" << std::endl;
    ss << "        _outer_hash = element.get_outer_hash();" << std::endl;
    ss << "        return *this;" << std::endl;
    ss << "    }" << std::endl;
    ss << "    bool SVGElement::operator==(const SVGElement &element) const {" << std::endl;
    ss << "        return element.get_outer_hash() == get_outer_hash();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    bool SVGElement::operator!=(const SVGElement &element) const {" << std::endl;
    ss << "        return !operator==(element);" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const std::string SVGElement::operator-(const SVGElement &element) const {" << std::endl;
    ss << "        std::stringstream ss;" << std::endl;
    ss << "" << std::endl;
    ss << "        // tag differ" << std::endl;
    ss << "        if (get_tag() != element.get_tag()) {" << std::endl;
    ss << "            auto svg = outer_SVG();" << std::endl;
    ss << "            ss << \"replace \" << svg.size() << std::endl << svg << std::endl;" << std::endl;
    ss << "            return ss.str();" << std::endl;
    ss << "        }" << std::endl;
    ss << "" << std::endl;
    ss << "        // cast" << std::endl;
    ss << "        auto _element = static_cast<const SVGElement &>(element);" << std::endl;
    ss << "" << std::endl;
    ss << "        // attribute differ" << std::endl;
    ss << "        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);" << std::endl;
    ss << "" << std::endl;
    ss << "        // inner differ" << std::endl;
    ss << "        if (element.get_inner_hash() == get_inner_hash()) return ss.str();" << std::endl;
    ss << "" << std::endl;
    ss << "        // extract change relation" << std::endl;
    ss << "        std::vector<_el_idx> removal;" << std::endl;
    ss << "        std::vector<_el_idx> addition;" << std::endl;
    ss << "        std::vector<std::pair<_el_idx, _el_idx>> unchanged;" << std::endl;
    ss << "        std::vector<std::pair<_el_idx, _el_idx>> changed;" << std::endl;
    ss << "        inner_differ(element, removal, addition, unchanged, changed);" << std::endl;
    ss << "        // remove" << std::endl;
    ss << "        int m = _inner_elements.size(), n = element.get_inner_elements().size();" << std::endl;
    ss << "        int *indices = new int[m], *removed = new int[n];" << std::endl;
    ss << "        std::fill(indices, indices + m, 0); std::fill(removed, removed + n, 0);" << std::endl;
    ss << "        for (auto &r : removal) removed[r.idx] = 1;" << std::endl;
    ss << "        for (int i = 1; i < n; i++) removed[i] += removed[i - 1];" << std::endl;
    ss << "        for (auto &r : removal) ss << \"remove \" << r.idx - (r.idx > 0 ? removed[r.idx - 1] : 0) << std::endl;" << std::endl;
    ss << "        // append" << std::endl;
    ss << "        for (auto &a : addition) {" << std::endl;
    ss << "            auto svg = a.ptr->outer_SVG();" << std::endl;
    ss << "            ss << \"append \" << svg.size() << std::endl << svg << std::endl;" << std::endl;
    ss << "        }" << std::endl;
    ss << "        // change recursively" << std::endl;
    ss << "        for (auto &c : changed) {" << std::endl;
    ss << "            auto &a = c.first; auto &b = c.second;" << std::endl;
    ss << "            ss << \"child \" << b.idx - removed[b.idx] << std::endl;" << std::endl;
    ss << "            ss << (*a.ptr - *b.ptr);" << std::endl;
    ss << "            ss << \"parent\" << std::endl;" << std::endl;
    ss << "        }" << std::endl;
    ss << "        // sort" << std::endl;
    ss << "        for (auto &c : unchanged) {" << std::endl;
    ss << "            auto &a = c.first; auto &b = c.second;" << std::endl;
    ss << "            indices[b.idx - removed[b.idx]] = a.idx;" << std::endl;
    ss << "        }" << std::endl;
    ss << "        for (auto &c : changed) {" << std::endl;
    ss << "            auto &a = c.first; auto &b = c.second;" << std::endl;
    ss << "            indices[b.idx - removed[b.idx]] =  a.idx;" << std::endl;
    ss << "        }" << std::endl;
    ss << "        for (int i = 0; i < addition.size(); i++) {" << std::endl;
    ss << "            auto &a = addition[i];" << std::endl;
    ss << "            indices[unchanged.size() + changed.size() + i] = a.idx;" << std::endl;
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
    ss << "        return ss.str();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const std::string SVGElement::attribute_differ(const SVGElement &element) const {" << std::endl;
    ss << "        std::stringstream ss;" << std::endl;
    ss << "" << std::endl;
    for (auto &p : _attributes) ss << p->str_operator_minus();
    ss << std::endl;
    ss << "        return ss.str();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    void SVGElement::inner_differ(const SVGElement &element," << std::endl;
    ss << "            std::vector<_el_idx> &removal," << std::endl;
    ss << "            std::vector<_el_idx> &addition," << std::endl;
    ss << "            std::vector<std::pair<_el_idx, _el_idx>> &unchanged," << std::endl;
    ss << "            std::vector<std::pair<_el_idx, _el_idx>> &changed) const {" << std::endl;
    ss << "        std::function<const std::string(const std::shared_ptr<SVGElement> &)> get_tag;" << std::endl;
    ss << "        get_tag = [](const std::shared_ptr<SVGElement> &x){" << std::endl;
    ss << "            if (x->get_raw_HTML() != STR_NULL) return std::string(\"#\") + std::to_string(x->get_outer_hash());" << std::endl;
    ss << "            return std::string(x->get_tag());" << std::endl;
    ss << "        };" << std::endl;
    ss << "        std::unordered_map<std::string, std::set<_el_idx>> tags_map;" << std::endl;
    ss << "        std::set<_el_idx> A, B;" << std::endl;
    ss << "        int c = 0;" << std::endl;
    ss << "        for (auto &a : _inner_elements) A.insert({a, c++}); c = 0;" << std::endl;
    ss << "        for (auto &b : element.get_inner_elements()) tags_map[get_tag(b)].insert({b, c}), B.insert({b, c++});" << std::endl;
    ss << "" << std::endl;
    ss << "        c = 0;" << std::endl;
    ss << "        for (auto &_a : _inner_elements) { // with outer hash equal" << std::endl;
    ss << "            auto &tag  = get_tag(_a);" << std::endl;
    ss << "            _el_idx a = { _a, c++ };" << std::endl;
    ss << "            if (!A.count(a) || !tags_map.count(tag)) continue;" << std::endl;
    ss << "            _el_idx match = { nullptr, -1 };" << std::endl;
    ss << "            for (auto &b : tags_map[tag]) {" << std::endl;
    ss << "                if (b.ptr->get_outer_hash() == a.ptr->get_outer_hash()) {" << std::endl;
    ss << "                    match = b;" << std::endl;
    ss << "                    break;" << std::endl;
    ss << "                }" << std::endl;
    ss << "            }" << std::endl;
    ss << "            if (match.idx >= 0) {" << std::endl;
    ss << "                tags_map[tag].erase(match);" << std::endl;
    ss << "                A.erase(a), B.erase(match);" << std::endl;
    ss << "                unchanged.push_back({a, match});" << std::endl;
    ss << "            }" << std::endl;
    ss << "        }" << std::endl;
    ss << "        c = 0;" << std::endl;
    ss << "        for (auto &_a : _inner_elements) { // with inner hash equal" << std::endl;
    ss << "            auto &tag  = get_tag(_a);" << std::endl;
    ss << "            _el_idx a = { _a, c++ };" << std::endl;
    ss << "            if (!A.count(a) || !tags_map.count(tag)) continue;" << std::endl;
    ss << "            _el_idx match = { nullptr, -1 };" << std::endl;
    ss << "            for (auto &b : tags_map[tag]) {" << std::endl;
    ss << "                if (b.ptr->get_inner_hash() == a.ptr->get_inner_hash()) {" << std::endl;
    ss << "                    match = b;" << std::endl;
    ss << "                    break;" << std::endl;
    ss << "                }" << std::endl;
    ss << "            }" << std::endl;
    ss << "            if (match.idx >= 0) {" << std::endl;
    ss << "                tags_map[tag].erase(match);" << std::endl;
    ss << "                A.erase(a), B.erase(match);" << std::endl;
    ss << "                changed.push_back({a, match});" << std::endl;
    ss << "            }" << std::endl;
    ss << "        }" << std::endl;
    ss << "        c = 0;" << std::endl;
    ss << "        for (auto &_a : _inner_elements) { // with attribute hash equal" << std::endl;
    ss << "            auto &tag  = get_tag(_a);" << std::endl;
    ss << "            _el_idx a = { _a, c++ };" << std::endl;
    ss << "            if (!A.count(a) || !tags_map.count(tag)) continue;" << std::endl;
    ss << "            _el_idx match = { nullptr, -1 };" << std::endl;
    ss << "            for (auto &b : tags_map[tag]) {" << std::endl;
    ss << "                if (b.ptr->get_attribute_hash() == a.ptr->get_attribute_hash()) {" << std::endl;
    ss << "                    match = b;" << std::endl;
    ss << "                    break;" << std::endl;
    ss << "                }" << std::endl;
    ss << "            }" << std::endl;
    ss << "            if (match.idx >= 0) {" << std::endl;
    ss << "                tags_map[tag].erase(match);" << std::endl;
    ss << "                A.erase(a), B.erase(match);" << std::endl;
    ss << "                changed.push_back({a, match});" << std::endl;
    ss << "            }" << std::endl;
    ss << "        }" << std::endl;
    ss << "        c = 0;" << std::endl;
    ss << "        for (auto &_a : _inner_elements) { // with tag equal" << std::endl;
    ss << "            auto &tag  = get_tag(_a);" << std::endl;
    ss << "            _el_idx a = { _a, c++ };" << std::endl;
    ss << "            if (!A.count(a) || !tags_map.count(tag) || tags_map[tag].size() == 0) continue;" << std::endl;
    ss << "            _el_idx match = *tags_map[tag].begin();" << std::endl;
    ss << "            tags_map[tag].erase(match);" << std::endl;
    ss << "            A.erase(a), B.erase(match);" << std::endl;
    ss << "            changed.push_back({a, match});" << std::endl;
    ss << "        }" << std::endl;
    ss << "        for (auto &a : A) addition.push_back(a);" << std::endl;
    ss << "        for (auto &b : B) removal.push_back(b);" << std::endl;
    ss << "    }" << std::endl;
    ss << "}" << std::endl;
    return ss.str();
}

std::string SVGH(const std::vector<std::string> &tags) {
    std::stringstream ss;
    ss << "#ifndef __LZ_SVG_ELEMENT__" << std::endl;
    ss << "#define __LZ_SVG_ELEMENT__" << std::endl;
    ss << "#include <string>" << std::endl;
    ss << "#include <vector>" << std::endl;
    ss << "#include <set>" << std::endl;
    ss << "#include <memory>" << std::endl;
    ss << "#include <utility>" << std::endl;
    ss << "#include \"utils.h\"" << std::endl;
    ss << "" << std::endl;
    ss << "namespace Lewzen {" << std::endl;
    ss << "    /**" << std::endl;
    ss << "    * An SVG element." << std::endl;
    ss << "    */" << std::endl;
    ss << "    class SVGElement: public std::enable_shared_from_this<SVGElement> {" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Constructor of SVG element." << std::endl;
    ss << "        */" << std::endl;
    ss << "        SVGElement();" << std::endl;
    ss << "" << std::endl;
    ss << "        /// Tag" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get tag name of this element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return tag name." << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual const std::string get_tag() const;" << std::endl;
    ss << "" << std::endl;
    ss << "        /// Element" << std::endl;
    for (auto &p : _attributes) ss << p->private_domain();
    ss << "    public:" << std::endl;
    for (auto &p : _attributes) ss << p->getter_defination() << p->setter_defination();
    ss << "        /// Attributes" << std::endl;
    ss << "    protected:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get attribute string of this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return outer SVG." << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual const std::string get_attributes() const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Returning differences on attributes." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return DOM Commands." << std::endl;
    ss << "        */" << std::endl;
    ss << "        const std::string attribute_differ(const SVGElement &element) const;" << std::endl;
    ss << "        " << std::endl;
    ss << "        /// Inner SVG" << std::endl;
    ss << "    protected:" << std::endl;
    ss << "        std::string _raw_HTML;" << std::endl;
    ss << "        std::vector<std::shared_ptr<SVGElement>> _inner_elements;" << std::endl;
    ss << "        std::weak_ptr<SVGElement> _parent_element;" << std::endl;
    ss << "    protected:" << std::endl;
    ss << "        struct _el_idx {" << std::endl;
    ss << "            std::shared_ptr<SVGElement> ptr;" << std::endl;
    ss << "            int idx;" << std::endl;
    ss << "            bool operator<(const _el_idx &b) const {" << std::endl;
    ss << "                if (ptr == b.ptr) return idx < b.idx;" << std::endl;
    ss << "                return ptr < b.ptr;" << std::endl;
    ss << "            }" << std::endl;
    ss << "        };" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Returning differences on inner elements." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return DOM Commands." << std::endl;
    ss << "        */" << std::endl;
    ss << "        void inner_differ(const SVGElement &element," << std::endl;
    ss << "            std::vector<_el_idx> &removal," << std::endl;
    ss << "            std::vector<_el_idx> &addition," << std::endl;
    ss << "            std::vector<std::pair<_el_idx, _el_idx>> &unchanged," << std::endl;
    ss << "            std::vector<std::pair<_el_idx, _el_idx>> &changed) const;" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get inner SVG of this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return inner SVG." << std::endl;
    ss << "        */" << std::endl;
    ss << "        const std::string inner_SVG() const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Set raw HTML of this SVG element. SVG string or text." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @param element an raw HTML." << std::endl;
    ss << "        */" << std::endl;
    ss << "        void set_raw_HTML(const std::string &text);" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Set raw HTML of this SVG element. SVG string or text." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @param element an raw HTML." << std::endl;
    ss << "        */" << std::endl;
    ss << "        const std::string get_raw_HTML() const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Add a sub element to this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @param element an inner element." << std::endl;
    ss << "        * @param index the index to be insert. default -1 means tail." << std::endl;
    ss << "        */" << std::endl;
    ss << "        void add_inner_element(const std::shared_ptr<SVGElement> &element, int index = -1);" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Remove a child element or child elements from this SVG element, based on content." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @param element an inner element." << std::endl;
    ss << "        * @param remove_all if to remove all occurances." << std::endl;
    ss << "        */" << std::endl;
    ss << "        void remove_inner_element(const std::shared_ptr<SVGElement> &element, bool remove_all = false);" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Remove a child element or child elements from this SVG element, by index." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @param index the index of inner element." << std::endl;
    ss << "        */" << std::endl;
    ss << "        void remove_inner_element(int index);" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get inner SVG element in this SVG element, by index." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return inner element." << std::endl;
    ss << "        */" << std::endl;
    ss << "        std::shared_ptr<SVGElement> get_inner_element(int index) const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get inner SVG elements list in this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return inner element list, readonly." << std::endl;
    ss << "        */" << std::endl;
    ss << "        const std::vector<std::shared_ptr<SVGElement>> get_inner_elements() const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Set inner SVG elements list in this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @param inner_elements inner elements list." << std::endl;
    ss << "        */" << std::endl;
    ss << "        void set_inner_elements(const std::vector<std::shared_ptr<SVGElement>> &inner_elements);" << std::endl;
    ss << "" << std::endl;
    ss << "        /// Outer SVG" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get SVG of this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return outer SVG." << std::endl;
    ss << "        */" << std::endl;
    ss << "        const std::string outer_SVG() const;" << std::endl;
    ss << "" << std::endl;
    ss << "        /// Hash" << std::endl;
    ss << "    private:" << std::endl;
    ss << "        HASH_CODE _attribute_hash;" << std::endl;
    ss << "        HASH_CODE _inner_hash;" << std::endl;
    ss << "        HASH_CODE _outer_hash;" << std::endl;
    ss << "    protected:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Update outer hash by inner hash and attribtue hash." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return hash code." << std::endl;
    ss << "        */" << std::endl;
    ss << "        void update_outer_hash();" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Update attribute hash and outer hash of this element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return hash code." << std::endl;
    ss << "        */" << std::endl;
    ss << "        void update_attribute_hash();" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Update inner hash and outer hash of this element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return hash code." << std::endl;
    ss << "        */" << std::endl;
    ss << "        void update_inner_hash();" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get hash of attributes of this element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return hash code." << std::endl;
    ss << "        */" << std::endl;
    ss << "        const HASH_CODE get_attribute_hash() const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get hash of inner content of this element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return inner hash code." << std::endl;
    ss << "        */" << std::endl;
    ss << "        const HASH_CODE get_inner_hash() const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get hash of this element, including tag, attributes and inner content." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return outer hash code." << std::endl;
    ss << "        */" << std::endl;
    ss << "        const HASH_CODE get_outer_hash() const;" << std::endl;
    ss << "" << std::endl;
    ss << "        /// Operators" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Deep copy this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual std::shared_ptr<SVGElement> clone() const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Assigning SVG element by deep copy." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual SVGElement &operator=(const SVGElement &element);" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Compare two SVG elements." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        bool operator==(const SVGElement &element) const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Compare two SVG elements." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        bool operator!=(const SVGElement &element) const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * SVG substraction, returning differences." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual const std::string operator-(const SVGElement &element) const;" << std::endl;
    ss << "    };" << std::endl;
    ss << "}" << std::endl;

    fs::path p(out_dir);
    fs::path base(base_dir);
    auto ip = fs::relative(p, base).generic_string();
    ss << std::endl;
    for (auto &tag : tags) {
        ss << "#include \"" << ip << "/svg_" << tag <<".h\"" << std::endl;
    }
    ss << "#endif" << std::endl;
    return ss.str();
}

const std::string HeaderFile(const std::string &tag, const std::string &comment, const std::vector<std::shared_ptr<Attribute>> attributes) {
    fs::path p(out_dir);
    fs::path base(base_dir);
    auto ip = fs::relative(base, p).generic_string();

    std::stringstream ss;
    ss << "#ifndef __LZ_SVG_" << dom_to_snake(tag, true) << "__" << std::endl;
    ss << "#define __LZ_SVG_" << dom_to_snake(tag, true) << "__" << std::endl;
    ss << "#include <string>" << std::endl;
    ss << "#include <sstream>" << std::endl;
    ss << "#include \"" << ip << "/svg_el.h\"" << std::endl;
    ss << std::endl;
    ss << "namespace Lewzen {" << std::endl;
    ss << "    /**" << std::endl;
    ss << "    * " << comment << std::endl;
    ss << "    */" << std::endl;
    ss << "    class SVG" << dom_to_pascal(tag) << ": public virtual SVGElement {" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Constructor of " << tag << "." << std::endl;
    ss << "        */" << std::endl;
    ss << "        SVG" << dom_to_pascal(tag) << "();" << std::endl;
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
    ss << "        /// " << dom_to_pascal(tag) << std::endl;
    for (auto &p : attributes) ss << p->private_domain();
    ss << "    public:" << std::endl;
    for (auto &p : attributes) ss << p->getter_defination() << p->setter_defination();
    ss << std::endl;
    ss << "        /// Attributes" << std::endl;
    ss << "    protected:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get attribute string of this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return outer SVG." << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual const std::string get_attributes() const override;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Returning differences on attributes." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return DOM Commands." << std::endl;
    ss << "        */" << std::endl;
    ss << "        const std::string attribute_differ(const SVG" << dom_to_pascal(tag) << " &element) const;" << std::endl;
    ss << std::endl;
    ss << "        /// Operators" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Deep copy this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVG" << dom_to_pascal(tag) << "" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual std::shared_ptr<SVGElement> clone() const override;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Deep copy this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVG" << dom_to_pascal(tag) << "" << std::endl;
    ss << "        */" << std::endl;
    ss << "        std::shared_ptr<SVG" << dom_to_pascal(tag) << "> clone(bool identity) const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Assigning SVG element by deep copy." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVG" << dom_to_pascal(tag) << "" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual SVGElement &operator=(const SVGElement &element) override;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Assigning SVG element by deep copy." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVG" << dom_to_pascal(tag) << "" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual SVG" << dom_to_pascal(tag) << " &operator=(const SVG" << dom_to_pascal(tag) << " &element);" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * SVG substraction, returning differences." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        virtual const std::string operator-(const SVGElement &element) const override;" << std::endl;
    ss << "    };" << std::endl;
    ss << "}" << std::endl;
    ss << "#endif";
    return ss.str();
}

const std::string CPPFile(const std::string &tag, const std::string &comment, const std::vector<std::shared_ptr<Attribute>> attributes) {
    std::stringstream ss;
    ss << "#include \"svg_" << dom_to_snake(tag) << ".h\"" << std::endl;
    ss << std::endl;
    ss << "namespace Lewzen {" << std::endl;
    ss << "    SVG" << dom_to_pascal(tag) << "::SVG" << dom_to_pascal(tag) << "() {" << std::endl;
    for (auto &p : attributes) ss << p->init_default();
    ss << "    }" << std::endl;
    ss << "    const std::string SVG" << dom_to_pascal(tag) << "::get_tag() const {" << std::endl;
    ss << "        return \"" << tag << "\";" << std::endl;
    ss << "    }" << std::endl;
    for (auto &p : attributes) ss << p->getter_implemetation() << p->setter_implemetation();
    ss << "    const std::string SVG" << dom_to_pascal(tag) << "::get_attributes() const {" << std::endl;
    ss << "        std::stringstream ss;" << std::endl;
    ss << std::endl;
    for (auto &p : attributes) ss << p->str_get_attributes();
    ss << "        ss << SVGElement::get_attributes();" << std::endl;
    ss << std::endl;
    ss << "        return ss.str();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    std::shared_ptr<SVGElement> SVG" << dom_to_pascal(tag) << "::clone() const {" << std::endl;
    ss << "        return clone(true);" << std::endl;
    ss << "    }" << std::endl;
    ss << "    std::shared_ptr<SVG" << dom_to_pascal(tag) << "> SVG" << dom_to_pascal(tag) << "::clone(bool identity) const {" << std::endl;
    ss << "        auto cloned =  std::make_shared<SVG" << dom_to_pascal(tag) << ">();" << std::endl;
    ss << "        *cloned = *this;" << std::endl;
    ss << "        return cloned;" << std::endl;
    ss << "    }" << std::endl;
    ss << "    SVGElement &SVG" << dom_to_pascal(tag) << "::operator=(const SVGElement &element) {" << std::endl;
    ss << "        return SVGElement::operator=(element);" << std::endl;
    ss << "    }" << std::endl;
    ss << "    SVG" << dom_to_pascal(tag) << " &SVG" << dom_to_pascal(tag) << "::operator=(const SVG" << dom_to_pascal(tag) << " &element) {" << std::endl;
    ss << "        SVGElement::operator=(element);" << std::endl;
    ss << "        return *this;" << std::endl;
    ss << std::endl;
    for (auto &p : attributes) ss << p->init_clone();
    ss << "        return *this;" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const std::string SVG" << dom_to_pascal(tag) << "::operator-(const SVGElement &element) const {" << std::endl;
    ss << "        std::stringstream ss;" << std::endl;
    ss << std::endl;
    ss << "        ss << SVGElement::operator-(element);" << std::endl;
    ss << "        if (get_tag() != element.get_tag()) return ss.str();" << std::endl;
    ss << "        auto _element = dynamic_cast<const SVG" << dom_to_pascal(tag) << " &>(element);" << std::endl;
    ss << std::endl;
    ss << "        // attribute differ" << std::endl;
    ss << "        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);" << std::endl;
    ss << "" << std::endl;
    ss << "        return ss.str();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const std::string SVG" << dom_to_pascal(tag) << "::attribute_differ(const SVG" << dom_to_pascal(tag) << " &element) const {" << std::endl;
    ss << "        std::stringstream ss;" << std::endl;
    ss << "" << std::endl;
    for (auto &p : attributes) ss << p->str_operator_minus();
    ss << std::endl;
    ss << "        return ss.str();" << std::endl;
    ss << "    }" << std::endl;
    ss << "}" << std::endl;
    return ss.str();
}

const std::string Makefile(const std::vector<std::string> &tags) {
    std::stringstream ss;
    ss << "objects = \\" << std::endl;
    for (int i = 0; i < tags.size(); i++) {
        ss << "\tsvg_" << tags[i] << ".o";
        if (i < tags.size() - 1) ss << "\\";
        ss << std::endl;
    }
    ss << "cc = g++" << std::endl;
    ss << std::endl;
    ss << ".PHONY: all" << std::endl;
    ss << "all: $(objects)" << std::endl;
    ss << std::endl;
    for (auto &tag : tags) ss << "svg_" << tag << ".o: svg_" << tag << ".cpp svg_" << tag << ".h" << std::endl << "\t$(cc) -c svg_" << tag << ".cpp" << std::endl;
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
    for (auto &atr : j["attributes"]) {
        std::string name = atr["name"];
        std::string type = atr["type"];
        std::string acom = atr["comment"];
        attributes.push_back(std::make_shared<StringAttribute>(tag, name, acom));
    }

    std::ofstream o1(out_dir + "/svg_" + dom_to_snake(tag) + ".h");
    o1 << HeaderFile(tag, comment, attributes);

    std::ofstream o2(out_dir + "/svg_" + dom_to_snake(tag) + ".cpp");
    o2 << CPPFile(tag, comment, attributes);

    std::cout << "done : " << tag << std::endl;
    return tag;
}

int main(int argc, char **argv) {
    std::ifstream i(json_dir + "/_svg._json");
    json j; i >> j;
    for (auto &atr : j["attributes"]) {
        std::string name = atr["name"];
        std::string type = atr["type"];
        std::string acom = atr["comment"];
        _attributes.push_back(std::make_shared<StringAttribute>("element", name, acom));
        _attribute_names.insert(name);
    }

    std::vector<std::string> tags;
    for (const auto &file : fs::directory_iterator(json_dir)) {
        auto tag = json_to_source(file.path());
        if (tag != "") tags.push_back(dom_to_snake(tag));
    }
    
    std::ofstream o1(out_dir + "/Makefile");
    o1 << Makefile(tags);
    std::cout << "Makefile done." << std::endl;

    o1 = std::ofstream(base_dir + "/svg_el.cpp");
    o1 << SVGCPP();

    o1 = std::ofstream(base_dir + "/svg_el.h");
    o1 << SVGH(tags);
    
    std::cout << "svg_el done." << std::endl;
}