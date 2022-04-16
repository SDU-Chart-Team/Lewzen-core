#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <iostream>
#include <fstream>
#include <regex>
#include <set>
#include <iomanip>
#include <filesystem>
#include "../../../json.hpp"

std::string out_dir = "..";
std::string json_dir = "../../../.attr_def";

using json = nlohmann::json;
namespace fs = std::filesystem;

#define is_uppercase(c) (c <= 'Z' && c >= 'A')
#define is_lowercase(c) (c <= 'z' && c >= 'a')
#define is_legal(c) (is_uppercase(c) || is_lowercase(c) || c == '_')
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

class Func {
private:
    std::string _cls, _declaration, _comment, _implementation;
    std::string _indentation, _indentation2;
public:
    Func(std::string cls, std::string declaration, std::string comment, std::string implementation, int indentation) {
        _cls = cls, _declaration = declaration, _comment = comment, _implementation = implementation;
        for (int i = 0; i < indentation; i++) _indentation.push_back(' ');
        for (int i = 0; i < indentation - 4; i++) _indentation2.push_back(' ');
        _comment = std::regex_replace(_comment, std::regex("\n"), "\n" + _indentation + "* ");
        _implementation = _indentation + std::regex_replace(_implementation, std::regex("\n"), "\n" + _indentation);
    }
    const std::string in_header_file() {
        std::stringstream ss;
        ss << _indentation << "/**" << std::endl;
        ss << _indentation << "* " << _comment << std::endl;
        ss << _indentation << "*/" << std::endl;
        ss << _indentation << _declaration << std::endl;
        return ss.str();
    }
    const std::string in_cpp_file() {
        auto _dd = std::regex_replace(_declaration, std::regex(";"), "");
        _dd = std::regex_replace(_dd, std::regex("^static "), "");
        _dd = std::regex_replace(_dd, std::regex("^virtual "), "");
        int i = _dd.find_first_of("("); i--;
        while (i > 0 && is_legal(_dd[i])) i--; i++;
        _dd.insert(i, _cls + "::");
        std::stringstream ss;
        ss << _indentation2 << _dd << " {" << std::endl;
        ss << _implementation << std::endl;
        ss << _indentation2 << "}" << std::endl;
        return ss.str();
    }
};

class Accept {
private:
    std::string _type, _comment;
    std::string _ctype, _cname, _to_string;
    std::vector<Func> _funcs;
public:
    Accept(std::string typ, std::string comment,
               std::string ctype, std::string cname, std::string to_string,
               std::vector<Func> funcs): _type(typ), _comment(comment), _ctype(ctype), _cname(cname), _to_string(to_string), _funcs(funcs) {
        _comment = std::regex_replace(_comment, std::regex("\n"), "\n        * ");
        _to_string = "        " + std::regex_replace(_to_string, std::regex("\n"), "\n        ");
    }
    const std::string in_header_file() {
        std::stringstream ss;
        ss << "    private:" << std::endl;
        ss << "        " << _ctype << " _con_val_" << std::regex_replace(_cname, std::regex("\\s"), "_") << ";" << std::endl;
        ss << "        const std::string _from_con_val_" << std::regex_replace(_cname, std::regex("\\s"), "_") << "();" << std::endl;
        ss << "        const " << _ctype << " (*_bind_func_" << std::regex_replace(_cname, std::regex("\\s"), "_") << ")();" << std::endl;
        ss << "        const std::string _from_bind_func_" << std::regex_replace(_cname, std::regex("\\s"), "_") << "();" << std::endl;
        ss << "        std::weak_ptr<" << _ctype << "> _bind_ptr_" << std::regex_replace(_cname, std::regex("\\s"), "_") << ";" << std::endl;
        ss << "        const std::string _from_bind_ptr_" << std::regex_replace(_cname, std::regex("\\s"), "_") << "();" << std::endl;
        ss << "        /**" << std::endl;
        ss << "        * Convert " << _cname << " to string of " << dom_to_pascal(_type) << "." << std::endl;
        ss << "        */" << std::endl;
        ss << "        static std::string " << std::regex_replace(_cname, std::regex("\\s"), "_") << "_to_string(const " << _ctype << " &attr);" << std::endl;
        ss << "    public:" << std::endl;
        ss << "        /**" << std::endl;
        ss << "        * Set attribute from " << _cname << ", conver to string and call setter. This will break value binding with bind_func and bind_ptr." << std::endl;
        ss << "        *" << std::endl;
        ss << "        * @param attr " << _cname << " attribute." << std::endl;
        ss << "        */" << std::endl;
        ss << "        void set(const " << _ctype << " &attr);" << std::endl;
        ss << "        /**" << std::endl;
        ss << "        * Set attribute from " << _cname << ", conver to string and call setter.  This will break value binding with bind_func and bind_ptr." << std::endl;
        ss << "        *" << std::endl;
        ss << "        * @param attr " << _cname << " attribute." << std::endl;
        ss << "        */" << std::endl;
        ss << "        " << dom_to_pascal(_type) << " &operator=(const " << _ctype << " &attr);" << std::endl;
        if (_ctype == "std::string") { // consider char *
            ss << "        /**" << std::endl;
            ss << "        * Set attribute from " << _cname << ", conver to string and call setter. This will break value binding with bind_func and bind_ptr." << std::endl;
            ss << "        *" << std::endl;
            ss << "        * @param attr " << _cname << " attribute." << std::endl;
            ss << "        */" << std::endl;
            ss << "        void set(const char * attr);" << std::endl;
            ss << "        /**" << std::endl;
            ss << "        * Set attribute from " << _cname << ", conver to string and call setter.  This will break value binding with bind_func and bind_ptr." << std::endl;
            ss << "        *" << std::endl;
            ss << "        * @param attr " << _cname << " attribute." << std::endl;
            ss << "        */" << std::endl;
            ss << "        " << dom_to_pascal(_type) << " &operator=(const char * attr);" << std::endl;
        }
        ss << "        /**" << std::endl;
        ss << "        * Bind attribute to a " << _cname << " function. This will break value binding with bind_ptr." << std::endl;
        ss << "        *" << std::endl;
        ss << "        * @param bind_func binding function." << std::endl;
        ss << "        */" << std::endl;
        ss << "        void bind(const " << _ctype << " (*bind_func)());" << std::endl;
        ss << "        /**" << std::endl;
        ss << "        * Bind attribute to a " << _cname << " function. This will break value binding with bind_ptr." << std::endl;
        ss << "        *" << std::endl;
        ss << "        * @param bind_func binding function." << std::endl;
        ss << "        */" << std::endl;
        ss << "        " << dom_to_pascal(_type) << " &operator[](const " << _ctype << " (*bind_func)());" << std::endl;
        ss << "        /**" << std::endl;
        ss << "        * Bind attribute to a " << _cname << " pointer. This will break value binding with bind_func." << std::endl;
        ss << "        *" << std::endl;
        ss << "        * @param bind_ptr binding pointer." << std::endl;
        ss << "        */" << std::endl;
        ss << "        void bind(const std::weak_ptr<" << _ctype << "> &bind_ptr);" << std::endl;
        ss << "        /**" << std::endl;
        ss << "        * Bind attribute to a " << _cname << " pointer. This will break value binding with bind_func." << std::endl;
        ss << "        *" << std::endl;
        ss << "        * @param bind_ptr binding pointer." << std::endl;
        ss << "        */" << std::endl;
        ss << "        " << dom_to_pascal(_type) << " &operator[](const std::weak_ptr<" << _ctype << "> &bind_ptr);" << std::endl;
        for (auto &f : _funcs) ss << f.in_header_file();
        return ss.str();
    }
    const std::string in_cpp_file() {
        std::stringstream ss;
        ss << "    const std::string " << dom_to_pascal(_type) << "::_from_con_val_" << std::regex_replace(_cname, std::regex("\\s"), "_") << "() {" << std::endl;
        ss << "        return " << std::regex_replace(_cname, std::regex("\\s"), "_") << "_to_string(_con_val_" << std::regex_replace(_cname, std::regex("\\s"), "_") << ");" << std::endl;
        ss << "    }" << std::endl;
        ss << "    const std::string " << dom_to_pascal(_type) << "::_from_bind_func_" << std::regex_replace(_cname, std::regex("\\s"), "_") << "() {" << std::endl;
        ss << "    return " << std::regex_replace(_cname, std::regex("\\s"), "_") << "_to_string((*_bind_func_" << std::regex_replace(_cname, std::regex("\\s"), "_") << ")());" << std::endl;
        ss << "    }" << std::endl;
        ss << "    const std::string " << dom_to_pascal(_type) << "::_from_bind_ptr_" << std::regex_replace(_cname, std::regex("\\s"), "_") << "() {" << std::endl;
        ss << "        if (auto sp = _bind_ptr_" << std::regex_replace(_cname, std::regex("\\s"), "_") << ".lock()) return " << std::regex_replace(_cname, std::regex("\\s"), "_") << "_to_string(*sp);" << std::endl;
        ss << "        else return STR_NULL;" << std::endl;
        ss << "    }" << std::endl;
        ss << "    std::string " << dom_to_pascal(_type) << "::" << std::regex_replace(_cname, std::regex("\\s"), "_") << "_to_string(const " << _ctype << " &attr) {" << std::endl;
        ss << _to_string << std::endl;
        ss << "    }" << std::endl;
        ss << "    void " << dom_to_pascal(_type) << "::set(const " << _ctype << " &attr) {" << std::endl;
        ss << "        _con_val_" << std::regex_replace(_cname, std::regex("\\s"), "_") << " = attr;" << std::endl;
        ss << "        _commit = std::bind(&" << dom_to_pascal(_type) << "::_from_con_val_" << std::regex_replace(_cname, std::regex("\\s"), "_") << ", this);" << std::endl;
        ss << "    }" << std::endl;
        ss << "    " << dom_to_pascal(_type) << " &" << dom_to_pascal(_type) << "::operator=(const " << _ctype << " &attr) {" << std::endl;
        ss << "        _con_val_" << std::regex_replace(_cname, std::regex("\\s"), "_") << " = attr;" << std::endl;
        ss << "        _commit = std::bind(&" << dom_to_pascal(_type) << "::_from_con_val_" << std::regex_replace(_cname, std::regex("\\s"), "_") << ", this);" << std::endl;
        ss << "    }" << std::endl;
        if (_ctype == "std::string") { // consider char *
            ss << "    void " << dom_to_pascal(_type) << "::set(const char *attr) {" << std::endl;
            ss << "        set(std::string(attr));" << std::endl;
            ss << "    }" << std::endl;
            ss << "    " << dom_to_pascal(_type) << " &" << dom_to_pascal(_type) << "::operator=(const char *attr) {" << std::endl;
            ss << "        operator=(std::string(attr));" << std::endl;
            ss << "    }" << std::endl;
        }
        ss << "    void " << dom_to_pascal(_type) << "::bind(const " << _ctype << " (*bind_func)()) {" << std::endl;
        ss << "        _bind_func_" << std::regex_replace(_cname, std::regex("\\s"), "_") << " = bind_func;" << std::endl;
        ss << "        _commit = std::bind(&" << dom_to_pascal(_type) << "::_from_bind_func_" << std::regex_replace(_cname, std::regex("\\s"), "_") << ", this);" << std::endl;
        ss << "    }" << std::endl;
        ss << "    " << dom_to_pascal(_type) << " &" << dom_to_pascal(_type) << "::operator[](const " << _ctype << " (*bind_func)()) {" << std::endl;
        ss << "        _bind_func_" << std::regex_replace(_cname, std::regex("\\s"), "_") << " = bind_func;" << std::endl;
        ss << "        _commit = std::bind(&" << dom_to_pascal(_type) << "::_from_bind_func_" << std::regex_replace(_cname, std::regex("\\s"), "_") << ", this);" << std::endl;
        ss << "    }" << std::endl;
        ss << "    void " << dom_to_pascal(_type) << "::bind(const std::weak_ptr<" << _ctype << "> &bind_ptr) {" << std::endl;
        ss << "        _bind_ptr_" << std::regex_replace(_cname, std::regex("\\s"), "_") << " = bind_ptr;" << std::endl;
        ss << "        _commit = std::bind(&" << dom_to_pascal(_type) << "::_from_bind_ptr_" << std::regex_replace(_cname, std::regex("\\s"), "_") << ", this);" << std::endl;
        ss << "    }" << std::endl;
        ss << "    " << dom_to_pascal(_type) << " &" << dom_to_pascal(_type) << "::operator[](const std::weak_ptr<" << _ctype << "> &bind_ptr) {" << std::endl;
        ss << "        _bind_ptr_" << std::regex_replace(_cname, std::regex("\\s"), "_") << " = bind_ptr;" << std::endl;
        ss << "        _commit = std::bind(&" << dom_to_pascal(_type) << "::_from_bind_ptr_" << std::regex_replace(_cname, std::regex("\\s"), "_") << ", this);" << std::endl;
        ss << "    }" << std::endl;
        for (auto &f : _funcs) ss << f.in_cpp_file();
        return ss.str();
    }
};

const std::string HeaderFile(std::string typ, std::string comment, std::vector<std::string> includes, std::vector<Accept> accepts) {
    std::stringstream ss;
    comment = std::regex_replace(comment, std::regex("\n"), "\n    * ");
    ss << "#ifndef __LZ_ATTR_" << dom_to_snake(typ, true) << "__" << std::endl;
    ss << "#define __LZ_ATTR_" << dom_to_snake(typ, true) << "__" << std::endl;
    ss << "#include <functional>" << std::endl;
    ss << "#include <string>" << std::endl;
    ss << "#include <memory>" << std::endl;
    ss << "#include <iostream>" << std::endl;
    for (auto &inc : includes) ss << "#include <" << inc << ">" << std::endl;
    ss << "#include \"../../utils.h\"" << std::endl;
    ss << "" << std::endl;
    ss << "namespace Lewzen {" << std::endl;
    ss << "    /**" << std::endl;
    ss << "    * " << comment << std::endl;
    ss << "    */" << std::endl;
    ss << "    class " << dom_to_pascal(typ) << " {" << std::endl;
    ss << "    private:" << std::endl;
    ss << "        std::function<const std::string()> _commit;" << std::endl;
    ss << "        std::function<const std::string()> _getter;" << std::endl;
    ss << "        std::function<void(const std::string &)> _setter;" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Empty constructor of " << dom_to_pascal(typ) << "." << std::endl;
    ss << "        */" << std::endl;
    ss << "        " << dom_to_pascal(typ) << "();" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Constructor of " << dom_to_pascal(typ) << ", with binding with getter and setter." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @param getter getter function" << std::endl;
    ss << "        * @param setter setter function" << std::endl;
    ss << "        */" << std::endl;
    ss << "        " << dom_to_pascal(typ) << "(std::function<const std::string()> getter, std::function<void(const std::string &)> setter);" << std::endl;
    ss << "" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Return attribute string, from getter." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return attribute string." << std::endl;
    ss << "        */" << std::endl;
    ss << "        const std::string get() const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Return attribute string to be committed." << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @return attribute string." << std::endl;
    ss << "        */" << std::endl;
    ss << "        const std::string get_commit() const;" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Commit binding or value by setter." << std::endl;
    ss << "        */" << std::endl;
    ss << "        void commit();" << std::endl;
    ss << "" << std::endl;
    ss << "    public:" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Set attribute from value, conver to string and call setter. This will break value binding with bind_func and bind_ptr. (This function will reset commit)" << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @param attr attribute." << std::endl;
    ss << "        */" << std::endl;
    ss << "        template <typename T>" << std::endl;
    ss << "        void set(const T &attr);" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Set attribute from value, conver to string and call setter.  This will break value binding with bind_func and bind_ptr. (This function will reset commit)" << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @param attr attribute." << std::endl;
    ss << "        */" << std::endl;
    ss << "        template <typename T>" << std::endl;
    ss << "        " << dom_to_pascal(typ) << " &operator=(const T &attr);" << std::endl;
    ss << "" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Bind attribute to a function. This will break value binding with bind_ptr. (This function will reset commit)" << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @param bind_func binding function." << std::endl;
    ss << "        */" << std::endl;
    ss << "        template <typename T>" << std::endl;
    ss << "        void bind(const T (*bind_func)());" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Bind attribute to a function. This will break value binding with bind_ptr. (This function will reset commit)" << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @param bind_func binding function." << std::endl;
    ss << "        */" << std::endl;
    ss << "        template <typename T>" << std::endl;
    ss << "        " << dom_to_pascal(typ) << " &operator[](const T (*bind_func));" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Bind attribute to a function. This will break value binding with bind_func. (This function will reset commit)" << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @param bind_ptr binding pointer." << std::endl;
    ss << "        */" << std::endl;
    ss << "        template <typename T>" << std::endl;
    ss << "        void bind(const std::weak_ptr<T> &bind_ptr);" << std::endl;
    ss << "        /**" << std::endl;
    ss << "        * Bind attribute to a function. This will break value binding with bind_func. (This function will reset commit)" << std::endl;
    ss << "        *" << std::endl;
    ss << "        * @param bind_ptr binding pointer." << std::endl;
    ss << "        */" << std::endl;
    ss << "        template <typename T>" << std::endl;
    ss << "        " << dom_to_pascal(typ) << " &operator[](const std::weak_ptr<T> &bind_ptr);" << std::endl;
    for (auto &a : accepts) ss << std::endl << a.in_header_file();
    ss << "    };" << std::endl;
    ss << "}" << std::endl;
    ss << "#include \"attr_" << typ << ".cpp\"" << std::endl;
    ss << "#endif" << std::endl;
    return ss.str();
}

const std::string CPPFile(std::string typ, std::string comment, std::vector<Accept> accepts) {
    std::stringstream ss;
    ss << "#ifndef __LZ_ATTR_" << dom_to_snake(typ, true) << "_I__" << std::endl;
    ss << "#define __LZ_ATTR_" << dom_to_snake(typ, true) << "_I__" << std::endl;
    ss << "#include \"attr_" << typ << ".h\"" << std::endl;
    ss << "" << std::endl;
    ss << "namespace Lewzen {" << std::endl;
    ss << "    " << dom_to_pascal(typ) << "::" << dom_to_pascal(typ) << "() {}" << std::endl;
    ss << "    " << dom_to_pascal(typ) << "::" << dom_to_pascal(typ) << "(std::function<const std::string()> getter, std::function<void(const std::string &)> setter): _getter(getter), _setter(setter) {}" << std::endl;
    ss << "    const std::string " << dom_to_pascal(typ) << "::get() const {" << std::endl;
    ss << "        if (!_getter) return STR_NULL;" << std::endl;
    ss << "        return _getter();" << std::endl;
    ss << "    }" << std::endl;
    ss << "    const std::string " << dom_to_pascal(typ) << "::get_commit() const {" << std::endl;
    ss << "        if (!_commit) return STR_NULL;" << std::endl;
    ss << "        return _commit();   " << std::endl;
    ss << "    }" << std::endl;
    ss << "    void " << dom_to_pascal(typ) << "::commit() {" << std::endl;
    ss << "        if (!_setter || !_commit) return;" << std::endl;
    ss << "        _setter(_commit());" << std::endl;
    ss << "    }" << std::endl;
    ss << "    template <typename T>" << std::endl;
    ss << "    void " << dom_to_pascal(typ) << "::set(const T &attr) {" << std::endl;
    ss << "        _setter(STR_NULL);" << std::endl;
    ss << "        _LZ_WARNING(\"Calling Attribute.set with no implementation. Reset value.\")" << std::endl;
    ss << "    }" << std::endl;
    ss << "    template <typename T>" << std::endl;
    ss << "    " << dom_to_pascal(typ) << " &" << dom_to_pascal(typ) << "::operator=(const T &attr) {" << std::endl;
    ss << "        _setter(STR_NULL);" << std::endl;
    ss << "        _LZ_WARNING(\"Calling Attribute.set with no implementation. Reset value.\")" << std::endl;
    ss << "    }" << std::endl;
    ss << "    template <typename T>" << std::endl;
    ss << "    void " << dom_to_pascal(typ) << "::bind(const T (*bind_func)()) {" << std::endl;
    ss << "        _setter(STR_NULL);" << std::endl;
    ss << "        _LZ_WARNING(\"Calling Attribute.set with no implementation. Reset value.\")" << std::endl;
    ss << "    }" << std::endl;
    ss << "    template <typename T>" << std::endl;
    ss << "    void " << dom_to_pascal(typ) << "::bind(const std::weak_ptr<T> &bind_ptr) {" << std::endl;
    ss << "        _setter(STR_NULL);" << std::endl;
    ss << "        _LZ_WARNING(\"Calling Attribute.set with no implementation. Reset value.\")" << std::endl;
    ss << "    }" << std::endl;
    ss << "    template <typename T>" << std::endl;
    ss << "    " << dom_to_pascal(typ) << " &" << dom_to_pascal(typ) << "::operator[](const T (*bind_func)) {" << std::endl;
    ss << "        _setter(STR_NULL);" << std::endl;
    ss << "        _LZ_WARNING(\"Calling Attribute.set with no implementation. Reset value.\")" << std::endl;
    ss << "    }" << std::endl;
    ss << "    template <typename T>" << std::endl;
    ss << "    " << dom_to_pascal(typ) << " &" << dom_to_pascal(typ) << "::operator[](const std::weak_ptr<T> &bind_ptr) {" << std::endl;
    ss << "        _setter(STR_NULL);" << std::endl;
    ss << "        _LZ_WARNING(\"Calling Attribute.set with no implementation. Reset value.\")" << std::endl;
    ss << "    }" << std::endl;
    for (auto &a : accepts) ss << std::endl << a.in_cpp_file();
    ss << "}" << std::endl;
    ss << "#endif" << std::endl;
    return ss.str();
}

const std::string json_to_source(const std::string &path) {
    fs::path p(path);
    if (p.extension() != ".json") return "";
    std::ifstream i(path);
    json j; i >> j;

    std::string typ = j["type"];
    std::string comment =  j["comment"];
    std::vector<std::string> includes;
    for (auto inc: j["includes"]) includes.push_back(inc);
    std::vector<Accept> accepts;

    for (auto a : j["accepts"]) {
        std::vector<Func> funcs;
        for (auto f : a["additional_funcs"]) {
            funcs.push_back(Func(dom_to_pascal(typ), f["declaration"], f["comment"], f["implementation"], 8));
        }
        accepts.push_back(Accept(typ, comment, a["ctype"], a["cname"], a["to_string"], funcs));
    }

    std::ofstream o1(out_dir + "/attr_" + typ + ".h");
    o1 << HeaderFile(typ, comment, includes, accepts);

    std::ofstream o2(out_dir + "/attr_" + typ + ".cpp");
    o2 << CPPFile(typ, comment, accepts);

    std::cout << "done : " << typ << std::endl;
    return typ;
}

int main(int argc, char **argv) {
    std::vector<std::string> tags;
    for (const auto &file : fs::directory_iterator(json_dir)) {
        auto src = json_to_source(file.path());
        if (src == "") continue;
    }
}

// Tuple
// Enumerate
// Basic Type
    // Plain Text
    // Content Type