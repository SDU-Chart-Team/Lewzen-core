#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <iostream>
#include <fstream>
#include <regex>
#include <iomanip>
#include <filesystem>
#include "../../.svg_def/json.hpp"

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
        std::stringstream ss;
        ss << "        /**" << std::endl;
        ss << "        * " << _comment << std::endl;
        ss << "        *" << std::endl;
        ss << "        * @return the " << _name << std::endl;
        ss << "        */" << std::endl;
        ss << "        const std::string get_" << dom_to_snake(_name) << "() const;" << std::endl;
        return ss.str();
    }
    const std::string setter_defination() const {
        std::stringstream ss;
        ss << "        /**" << std::endl;
        ss << "        * " << _comment << std::endl;
        ss << "        *" << std::endl;
        ss << "        * @param  the " << _name << std::endl;
        ss << "        */" << std::endl;
        ss << "        void set_" << dom_to_snake(_name) << "(const std::string &" << dom_to_snake(_name) << ");" << std::endl;
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
        ss << "    void SVG" << dom_to_pascal(_tag) << "::set_" << dom_to_snake(_name) << "(const std::string &" << dom_to_snake(_name) << ") {" << std::endl;
        ss << "        _" << dom_to_snake(_name) << " = " << dom_to_snake(_name) << ";" << std::endl;
        ss << "        update_hash();" << std::endl;
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
        ss << "        if (_" << dom_to_snake(_name) << " != _element.get_" << dom_to_snake(_name) << "()) {" << std::endl;;
        ss << "            if (_" << dom_to_snake(_name) << " == STR_NULL) ss << \"reset " << _name << "\" << std::endl;" << std::endl;;
        ss << "            else ss << \"modify " << _name << " \\\"\" << _" << dom_to_snake(_name) << " << \"\\\"\" << std::endl;" << std::endl;;
        ss << "        }" << std::endl;
        return ss.str();
    }
};

const std::string HeaderFile(const std::string &tag, const std::string &comment, const std::vector<std::shared_ptr<Attribute>> attributes) {
    fs::path p(out_dir);
    fs::path base(base_dir);
    auto ip = fs::relative(base, p).generic_string();

    std::stringstream ss;
    ss << "#ifndef __LZ_SVG_" << dom_to_snake(tag, true) << "__" << std::endl;
    ss << "#define __LZ_SVG_" << dom_to_snake(tag, true) << "__" << std::endl;
    ss << "#include <string>" << std::endl;
    ss << "#include <sstream>" << std::endl;
    ss << "#include \"" << ip << "/svg_element.h\"" << std::endl;
    ss << std::endl;
    ss << "namespace Lewzen {" << std::endl;
    ss << "    /**" << std::endl;
    ss << "    * " << comment << std::endl;
    ss << "    */" << std::endl;
    ss << "    class SVG" << dom_to_pascal(tag) << ": public SVGElement {" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Constructor of " << tag << "." << std::endl;
    ss << "        */" << std::endl;
    ss << "        SVG" << dom_to_pascal(tag) << "();" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Deep copy of " << tag << "." << std::endl;
    ss << "        */" << std::endl;
    ss << "        SVG" << dom_to_pascal(tag) << "(const SVG" << dom_to_pascal(tag) << " &element);" << std::endl;
    ss << std::endl;
    ss << "        /// Tag" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Get tag name of this element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return tag name." << std::endl;
    ss << "        */" << std::endl;
    ss << "        const std::string get_tag() const;" << std::endl;
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
    ss << "        const std::string get_attributes() const;" << std::endl;
    ss << std::endl;
    ss << "        /// Operators" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Deep copy this SVG element." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        std::shared_ptr<SVGElement> clone() const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * SVG substraction, returning differences." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @relatesalso SVGElement" << std::endl;
    ss << "        */" << std::endl;
    ss << "        const std::string operator-(const SVGElement &element) const;" << std::endl;
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
    ss << "    SVG" << dom_to_pascal(tag) << "::SVG" << dom_to_pascal(tag) << "(const SVG" << dom_to_pascal(tag) << " &element) {" << std::endl;
    for (auto &p : attributes) ss << p->init_clone();
    ss << "        new (this)SVGElement(element);" << std::endl;
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
    ss << "        return std::make_shared<SVG" << dom_to_pascal(tag) << ">(*this);" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const std::string SVG" << dom_to_pascal(tag) << "::operator-(const SVGElement &element) const {" << std::endl;
    ss << "        std::stringstream ss;" << std::endl;
    ss << std::endl;
    ss << "        ss << SVGElement::operator-(element);" << std::endl;
    ss << "        if (get_tag() != element.get_tag()) return ss.str();" << std::endl;
    ss << "        auto _element = static_cast<const SVG" << dom_to_pascal(tag) << " &>(element);" << std::endl;
    ss << std::endl;
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

const std::string Includes(const std::vector<std::string> &tags) {
    fs::path p(out_dir);
    fs::path base(base_dir);
    auto ip = fs::relative(p, base).generic_string();

    std::stringstream ss;
    for (auto &tag : tags) {
        ss << "#include \"" << ip << "/svg_" << tag <<".h\"" << std::endl;
    }
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
    std::vector<std::string> tags;
    for (const auto &file : fs::directory_iterator(json_dir)) {
        auto tag = json_to_source(file.path());
        if (tag != "") tags.push_back(dom_to_snake(tag));
    }
    
    std::ofstream o1(out_dir + "/Makefile");
    o1 << Makefile(tags);
    std::cout << "Makefile done." << std::endl;

    std::ofstream o2("includes.out");
    o2 << "// copy following code to \"svg_element.h\":" << std::endl << Includes(tags);

    std::cout << "includes.out done." << std::endl;
}