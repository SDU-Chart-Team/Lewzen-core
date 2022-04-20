#ifndef __LZ_ATTR_NUMBER_I__
#define __LZ_ATTR_NUMBER_I__
#include "attr_number.h"

namespace Lewzen {
    Number::Number() {}
    Number::Number(std::function<const std::string()> getter, std::function<void(const std::string &)> setter): _getter(getter), _setter(setter) {}
    void Number::set_getter(std::function<const std::string()> getter) {
        _getter = getter;
    }
    void Number::set_setter(std::function<void(const std::string &)> setter) {
        _setter = setter;
    }
    const std::string Number::get() const {
        if (!_getter) return STR_NULL;
        return _getter();
    }
    const std::string Number::get_commit() const {
        if (!_commit) return STR_NULL;
        return _commit();   
    }
    void Number::commit() {
        if (!_setter || !_commit) return;
        _setter(_commit());
    }
    template <typename T>
    void Number::set(const T &attr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling Attribute.set with no implementation. Reset value.")
    }
    template <typename T>
    Number &Number::operator=(const T &attr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling Attribute.set with no implementation. Reset value.")
    }
    template <typename T>
    void Number::bind(std::function<const T()>bind_func) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling Attribute.set with no implementation. Reset value.")
    }
    template <typename T>
    void Number::bind(const std::weak_ptr<T> &bind_ptr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling Attribute.set with no implementation. Reset value.")
    }
    template <typename T>
    Number &Number::operator[](std::function<const T()>bind_func) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling Attribute.set with no implementation. Reset value.")
    }
    template <typename T>
    Number &Number::operator[](const std::weak_ptr<T> &bind_ptr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling Attribute.set with no implementation. Reset value.")
    }

    const std::string Number::_from_con_val_integer() {
        return integer_to_string(_con_val_integer);
    }
    const std::string Number::_from_bind_func_integer() {
        return integer_to_string(_bind_func_integer());
    }
    const std::string Number::_from_bind_ptr_integer() {
        if (auto sp = _bind_ptr_integer.lock()) return integer_to_string(*sp);
        else return STR_NULL;
    }
    std::string Number::integer_to_string(const int &attr) {
        return std::to_string(attr);
    }
    void Number::set(const int &attr) {
        _con_val_integer = attr;
        _commit = std::bind(&Number::_from_con_val_integer, this);
    }
    Number &Number::operator=(const int &attr) {
        _con_val_integer = attr;
        _commit = std::bind(&Number::_from_con_val_integer, this);
    }
    void Number::bind(std::function<const int()> bind_func) {
        _bind_func_integer = bind_func;
        _commit = std::bind(&Number::_from_bind_func_integer, this);
    }
    Number &Number::operator[](std::function<const int()> bind_func) {
        _bind_func_integer = bind_func;
        _commit = std::bind(&Number::_from_bind_func_integer, this);
    }
    void Number::bind(const std::weak_ptr<int> &bind_ptr) {
        _bind_ptr_integer = bind_ptr;
        _commit = std::bind(&Number::_from_bind_ptr_integer, this);
    }
    Number &Number::operator[](const std::weak_ptr<int> &bind_ptr) {
        _bind_ptr_integer = bind_ptr;
        _commit = std::bind(&Number::_from_bind_ptr_integer, this);
    }

    const std::string Number::_from_con_val_float() {
        return float_to_string(_con_val_float);
    }
    const std::string Number::_from_bind_func_float() {
        return float_to_string(_bind_func_float());
    }
    const std::string Number::_from_bind_ptr_float() {
        if (auto sp = _bind_ptr_float.lock()) return float_to_string(*sp);
        else return STR_NULL;
    }
    std::string Number::float_to_string(const float &attr) {
        return std::to_string(attr);
    }
    void Number::set(const float &attr) {
        _con_val_float = attr;
        _commit = std::bind(&Number::_from_con_val_float, this);
    }
    Number &Number::operator=(const float &attr) {
        _con_val_float = attr;
        _commit = std::bind(&Number::_from_con_val_float, this);
    }
    void Number::bind(std::function<const float()> bind_func) {
        _bind_func_float = bind_func;
        _commit = std::bind(&Number::_from_bind_func_float, this);
    }
    Number &Number::operator[](std::function<const float()> bind_func) {
        _bind_func_float = bind_func;
        _commit = std::bind(&Number::_from_bind_func_float, this);
    }
    void Number::bind(const std::weak_ptr<float> &bind_ptr) {
        _bind_ptr_float = bind_ptr;
        _commit = std::bind(&Number::_from_bind_ptr_float, this);
    }
    Number &Number::operator[](const std::weak_ptr<float> &bind_ptr) {
        _bind_ptr_float = bind_ptr;
        _commit = std::bind(&Number::_from_bind_ptr_float, this);
    }

    const std::string Number::_from_con_val_double() {
        return double_to_string(_con_val_double);
    }
    const std::string Number::_from_bind_func_double() {
        return double_to_string(_bind_func_double());
    }
    const std::string Number::_from_bind_ptr_double() {
        if (auto sp = _bind_ptr_double.lock()) return double_to_string(*sp);
        else return STR_NULL;
    }
    std::string Number::double_to_string(const double &attr) {
        return std::to_string(attr);
    }
    void Number::set(const double &attr) {
        _con_val_double = attr;
        _commit = std::bind(&Number::_from_con_val_double, this);
    }
    Number &Number::operator=(const double &attr) {
        _con_val_double = attr;
        _commit = std::bind(&Number::_from_con_val_double, this);
    }
    void Number::bind(std::function<const double()> bind_func) {
        _bind_func_double = bind_func;
        _commit = std::bind(&Number::_from_bind_func_double, this);
    }
    Number &Number::operator[](std::function<const double()> bind_func) {
        _bind_func_double = bind_func;
        _commit = std::bind(&Number::_from_bind_func_double, this);
    }
    void Number::bind(const std::weak_ptr<double> &bind_ptr) {
        _bind_ptr_double = bind_ptr;
        _commit = std::bind(&Number::_from_bind_ptr_double, this);
    }
    Number &Number::operator[](const std::weak_ptr<double> &bind_ptr) {
        _bind_ptr_double = bind_ptr;
        _commit = std::bind(&Number::_from_bind_ptr_double, this);
    }

    const std::string Number::_from_con_val_long() {
        return long_to_string(_con_val_long);
    }
    const std::string Number::_from_bind_func_long() {
        return long_to_string(_bind_func_long());
    }
    const std::string Number::_from_bind_ptr_long() {
        if (auto sp = _bind_ptr_long.lock()) return long_to_string(*sp);
        else return STR_NULL;
    }
    std::string Number::long_to_string(const long &attr) {
        return std::to_string(attr);
    }
    void Number::set(const long &attr) {
        _con_val_long = attr;
        _commit = std::bind(&Number::_from_con_val_long, this);
    }
    Number &Number::operator=(const long &attr) {
        _con_val_long = attr;
        _commit = std::bind(&Number::_from_con_val_long, this);
    }
    void Number::bind(std::function<const long()> bind_func) {
        _bind_func_long = bind_func;
        _commit = std::bind(&Number::_from_bind_func_long, this);
    }
    Number &Number::operator[](std::function<const long()> bind_func) {
        _bind_func_long = bind_func;
        _commit = std::bind(&Number::_from_bind_func_long, this);
    }
    void Number::bind(const std::weak_ptr<long> &bind_ptr) {
        _bind_ptr_long = bind_ptr;
        _commit = std::bind(&Number::_from_bind_ptr_long, this);
    }
    Number &Number::operator[](const std::weak_ptr<long> &bind_ptr) {
        _bind_ptr_long = bind_ptr;
        _commit = std::bind(&Number::_from_bind_ptr_long, this);
    }

    const std::string Number::_from_con_val_long_integer() {
        return long_integer_to_string(_con_val_long_integer);
    }
    const std::string Number::_from_bind_func_long_integer() {
        return long_integer_to_string(_bind_func_long_integer());
    }
    const std::string Number::_from_bind_ptr_long_integer() {
        if (auto sp = _bind_ptr_long_integer.lock()) return long_integer_to_string(*sp);
        else return STR_NULL;
    }
    std::string Number::long_integer_to_string(const long long int &attr) {
        return std::to_string(attr);
    }
    void Number::set(const long long int &attr) {
        _con_val_long_integer = attr;
        _commit = std::bind(&Number::_from_con_val_long_integer, this);
    }
    Number &Number::operator=(const long long int &attr) {
        _con_val_long_integer = attr;
        _commit = std::bind(&Number::_from_con_val_long_integer, this);
    }
    void Number::bind(std::function<const long long int()> bind_func) {
        _bind_func_long_integer = bind_func;
        _commit = std::bind(&Number::_from_bind_func_long_integer, this);
    }
    Number &Number::operator[](std::function<const long long int()> bind_func) {
        _bind_func_long_integer = bind_func;
        _commit = std::bind(&Number::_from_bind_func_long_integer, this);
    }
    void Number::bind(const std::weak_ptr<long long int> &bind_ptr) {
        _bind_ptr_long_integer = bind_ptr;
        _commit = std::bind(&Number::_from_bind_ptr_long_integer, this);
    }
    Number &Number::operator[](const std::weak_ptr<long long int> &bind_ptr) {
        _bind_ptr_long_integer = bind_ptr;
        _commit = std::bind(&Number::_from_bind_ptr_long_integer, this);
    }

    const std::string Number::_from_con_val_long_double() {
        return long_double_to_string(_con_val_long_double);
    }
    const std::string Number::_from_bind_func_long_double() {
        return long_double_to_string(_bind_func_long_double());
    }
    const std::string Number::_from_bind_ptr_long_double() {
        if (auto sp = _bind_ptr_long_double.lock()) return long_double_to_string(*sp);
        else return STR_NULL;
    }
    std::string Number::long_double_to_string(const long double &attr) {
        return std::to_string(attr);
    }
    void Number::set(const long double &attr) {
        _con_val_long_double = attr;
        _commit = std::bind(&Number::_from_con_val_long_double, this);
    }
    Number &Number::operator=(const long double &attr) {
        _con_val_long_double = attr;
        _commit = std::bind(&Number::_from_con_val_long_double, this);
    }
    void Number::bind(std::function<const long double()> bind_func) {
        _bind_func_long_double = bind_func;
        _commit = std::bind(&Number::_from_bind_func_long_double, this);
    }
    Number &Number::operator[](std::function<const long double()> bind_func) {
        _bind_func_long_double = bind_func;
        _commit = std::bind(&Number::_from_bind_func_long_double, this);
    }
    void Number::bind(const std::weak_ptr<long double> &bind_ptr) {
        _bind_ptr_long_double = bind_ptr;
        _commit = std::bind(&Number::_from_bind_ptr_long_double, this);
    }
    Number &Number::operator[](const std::weak_ptr<long double> &bind_ptr) {
        _bind_ptr_long_double = bind_ptr;
        _commit = std::bind(&Number::_from_bind_ptr_long_double, this);
    }

    const std::string Number::_from_con_val_legal_string() {
        return legal_string_to_string(_con_val_legal_string);
    }
    const std::string Number::_from_bind_func_legal_string() {
        return legal_string_to_string(_bind_func_legal_string());
    }
    const std::string Number::_from_bind_ptr_legal_string() {
        if (auto sp = _bind_ptr_legal_string.lock()) return legal_string_to_string(*sp);
        else return STR_NULL;
    }
    std::string Number::legal_string_to_string(const std::string &attr) {
        if (!is_legal_string(attr)) {
            _LZ_WARNING("Illegal string when converting \"" << attr << "\" to Number.")
            return STR_NULL;
        } else {
            return attr;
        }
    }
    void Number::set(const std::string &attr) {
        _con_val_legal_string = attr;
        _commit = std::bind(&Number::_from_con_val_legal_string, this);
    }
    Number &Number::operator=(const std::string &attr) {
        _con_val_legal_string = attr;
        _commit = std::bind(&Number::_from_con_val_legal_string, this);
    }
    void Number::set(const char *attr) {
        set(std::string(attr));
    }
    Number &Number::operator=(const char *attr) {
        operator=(std::string(attr));
    }
    void Number::bind(std::function<const std::string()> bind_func) {
        _bind_func_legal_string = bind_func;
        _commit = std::bind(&Number::_from_bind_func_legal_string, this);
    }
    Number &Number::operator[](std::function<const std::string()> bind_func) {
        _bind_func_legal_string = bind_func;
        _commit = std::bind(&Number::_from_bind_func_legal_string, this);
    }
    void Number::bind(const std::weak_ptr<std::string> &bind_ptr) {
        _bind_ptr_legal_string = bind_ptr;
        _commit = std::bind(&Number::_from_bind_ptr_legal_string, this);
    }
    Number &Number::operator[](const std::weak_ptr<std::string> &bind_ptr) {
        _bind_ptr_legal_string = bind_ptr;
        _commit = std::bind(&Number::_from_bind_ptr_legal_string, this);
    }
    bool Number::is_legal_string(const std::string &attr) {
        std::regex re(R"(^([+-]?[0-9]+)([Ee]([+-]?[0-9]+))?|[+-]?[0-9]*\.[0-9]+([Ee]([+-]?[0-9]+))?$)");
        return std::regex_match(attr, re);
    }
}
#endif
