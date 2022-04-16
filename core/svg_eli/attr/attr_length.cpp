#ifndef __LZ_ATTR_LENGTH_I__
#define __LZ_ATTR_LENGTH_I__
#include "attr_length.h"

namespace Lewzen {
    Length::Length() {}
    Length::Length(std::function<const std::string()> getter, std::function<void(const std::string &)> setter): _getter(getter), _setter(setter) {}
    const std::string Length::get() const {
        if (!_getter) return STR_NULL;
        return _getter();
    }
    const std::string Length::get_commit() const {
        if (!_commit) return STR_NULL;
        return _commit();   
    }
    void Length::commit() {
        if (!_setter || !_commit) return;
        _setter(_commit());
    }
    template <typename T>
    void Length::set(const T &attr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling Attribute.set with no implementation. Reset value.")
    }
    template <typename T>
    Length &Length::operator=(const T &attr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling Attribute.set with no implementation. Reset value.")
    }
    template <typename T>
    void Length::bind(const T (*bind_func)()) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling Attribute.set with no implementation. Reset value.")
    }
    template <typename T>
    void Length::bind(const std::weak_ptr<T> &bind_ptr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling Attribute.set with no implementation. Reset value.")
    }
    template <typename T>
    Length &Length::operator[](const T (*bind_func)) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling Attribute.set with no implementation. Reset value.")
    }
    template <typename T>
    Length &Length::operator[](const std::weak_ptr<T> &bind_ptr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling Attribute.set with no implementation. Reset value.")
    }

    const std::string Length::_from_con_val_integer() {
        return integer_to_string(_con_val_integer);
    }
    const std::string Length::_from_bind_func_integer() {
    return integer_to_string((*_bind_func_integer)());
    }
    const std::string Length::_from_bind_ptr_integer() {
        if (auto sp = _bind_ptr_integer.lock()) return integer_to_string(*sp);
        else return STR_NULL;
    }
    std::string Length::integer_to_string(const int &attr) {
        return std::to_string(attr);
    }
    void Length::set(const int &attr) {
        _con_val_integer = attr;
        _commit = std::bind(&Length::_from_con_val_integer, this);
    }
    Length &Length::operator=(const int &attr) {
        _con_val_integer = attr;
        _commit = std::bind(&Length::_from_con_val_integer, this);
    }
    void Length::bind(const int (*bind_func)()) {
        _bind_func_integer = bind_func;
        _commit = std::bind(&Length::_from_bind_func_integer, this);
    }
    Length &Length::operator[](const int (*bind_func)()) {
        _bind_func_integer = bind_func;
        _commit = std::bind(&Length::_from_bind_func_integer, this);
    }
    void Length::bind(const std::weak_ptr<int> &bind_ptr) {
        _bind_ptr_integer = bind_ptr;
        _commit = std::bind(&Length::_from_bind_ptr_integer, this);
    }
    Length &Length::operator[](const std::weak_ptr<int> &bind_ptr) {
        _bind_ptr_integer = bind_ptr;
        _commit = std::bind(&Length::_from_bind_ptr_integer, this);
    }

    const std::string Length::_from_con_val_float() {
        return float_to_string(_con_val_float);
    }
    const std::string Length::_from_bind_func_float() {
    return float_to_string((*_bind_func_float)());
    }
    const std::string Length::_from_bind_ptr_float() {
        if (auto sp = _bind_ptr_float.lock()) return float_to_string(*sp);
        else return STR_NULL;
    }
    std::string Length::float_to_string(const float &attr) {
        return std::to_string(attr);
    }
    void Length::set(const float &attr) {
        _con_val_float = attr;
        _commit = std::bind(&Length::_from_con_val_float, this);
    }
    Length &Length::operator=(const float &attr) {
        _con_val_float = attr;
        _commit = std::bind(&Length::_from_con_val_float, this);
    }
    void Length::bind(const float (*bind_func)()) {
        _bind_func_float = bind_func;
        _commit = std::bind(&Length::_from_bind_func_float, this);
    }
    Length &Length::operator[](const float (*bind_func)()) {
        _bind_func_float = bind_func;
        _commit = std::bind(&Length::_from_bind_func_float, this);
    }
    void Length::bind(const std::weak_ptr<float> &bind_ptr) {
        _bind_ptr_float = bind_ptr;
        _commit = std::bind(&Length::_from_bind_ptr_float, this);
    }
    Length &Length::operator[](const std::weak_ptr<float> &bind_ptr) {
        _bind_ptr_float = bind_ptr;
        _commit = std::bind(&Length::_from_bind_ptr_float, this);
    }

    const std::string Length::_from_con_val_double() {
        return double_to_string(_con_val_double);
    }
    const std::string Length::_from_bind_func_double() {
    return double_to_string((*_bind_func_double)());
    }
    const std::string Length::_from_bind_ptr_double() {
        if (auto sp = _bind_ptr_double.lock()) return double_to_string(*sp);
        else return STR_NULL;
    }
    std::string Length::double_to_string(const double &attr) {
        return std::to_string(attr);
    }
    void Length::set(const double &attr) {
        _con_val_double = attr;
        _commit = std::bind(&Length::_from_con_val_double, this);
    }
    Length &Length::operator=(const double &attr) {
        _con_val_double = attr;
        _commit = std::bind(&Length::_from_con_val_double, this);
    }
    void Length::bind(const double (*bind_func)()) {
        _bind_func_double = bind_func;
        _commit = std::bind(&Length::_from_bind_func_double, this);
    }
    Length &Length::operator[](const double (*bind_func)()) {
        _bind_func_double = bind_func;
        _commit = std::bind(&Length::_from_bind_func_double, this);
    }
    void Length::bind(const std::weak_ptr<double> &bind_ptr) {
        _bind_ptr_double = bind_ptr;
        _commit = std::bind(&Length::_from_bind_ptr_double, this);
    }
    Length &Length::operator[](const std::weak_ptr<double> &bind_ptr) {
        _bind_ptr_double = bind_ptr;
        _commit = std::bind(&Length::_from_bind_ptr_double, this);
    }

    const std::string Length::_from_con_val_long() {
        return long_to_string(_con_val_long);
    }
    const std::string Length::_from_bind_func_long() {
    return long_to_string((*_bind_func_long)());
    }
    const std::string Length::_from_bind_ptr_long() {
        if (auto sp = _bind_ptr_long.lock()) return long_to_string(*sp);
        else return STR_NULL;
    }
    std::string Length::long_to_string(const long &attr) {
        return std::to_string(attr);
    }
    void Length::set(const long &attr) {
        _con_val_long = attr;
        _commit = std::bind(&Length::_from_con_val_long, this);
    }
    Length &Length::operator=(const long &attr) {
        _con_val_long = attr;
        _commit = std::bind(&Length::_from_con_val_long, this);
    }
    void Length::bind(const long (*bind_func)()) {
        _bind_func_long = bind_func;
        _commit = std::bind(&Length::_from_bind_func_long, this);
    }
    Length &Length::operator[](const long (*bind_func)()) {
        _bind_func_long = bind_func;
        _commit = std::bind(&Length::_from_bind_func_long, this);
    }
    void Length::bind(const std::weak_ptr<long> &bind_ptr) {
        _bind_ptr_long = bind_ptr;
        _commit = std::bind(&Length::_from_bind_ptr_long, this);
    }
    Length &Length::operator[](const std::weak_ptr<long> &bind_ptr) {
        _bind_ptr_long = bind_ptr;
        _commit = std::bind(&Length::_from_bind_ptr_long, this);
    }

    const std::string Length::_from_con_val_long_integer() {
        return long_integer_to_string(_con_val_long_integer);
    }
    const std::string Length::_from_bind_func_long_integer() {
    return long_integer_to_string((*_bind_func_long_integer)());
    }
    const std::string Length::_from_bind_ptr_long_integer() {
        if (auto sp = _bind_ptr_long_integer.lock()) return long_integer_to_string(*sp);
        else return STR_NULL;
    }
    std::string Length::long_integer_to_string(const long long int &attr) {
        return std::to_string(attr);
    }
    void Length::set(const long long int &attr) {
        _con_val_long_integer = attr;
        _commit = std::bind(&Length::_from_con_val_long_integer, this);
    }
    Length &Length::operator=(const long long int &attr) {
        _con_val_long_integer = attr;
        _commit = std::bind(&Length::_from_con_val_long_integer, this);
    }
    void Length::bind(const long long int (*bind_func)()) {
        _bind_func_long_integer = bind_func;
        _commit = std::bind(&Length::_from_bind_func_long_integer, this);
    }
    Length &Length::operator[](const long long int (*bind_func)()) {
        _bind_func_long_integer = bind_func;
        _commit = std::bind(&Length::_from_bind_func_long_integer, this);
    }
    void Length::bind(const std::weak_ptr<long long int> &bind_ptr) {
        _bind_ptr_long_integer = bind_ptr;
        _commit = std::bind(&Length::_from_bind_ptr_long_integer, this);
    }
    Length &Length::operator[](const std::weak_ptr<long long int> &bind_ptr) {
        _bind_ptr_long_integer = bind_ptr;
        _commit = std::bind(&Length::_from_bind_ptr_long_integer, this);
    }

    const std::string Length::_from_con_val_long_double() {
        return long_double_to_string(_con_val_long_double);
    }
    const std::string Length::_from_bind_func_long_double() {
    return long_double_to_string((*_bind_func_long_double)());
    }
    const std::string Length::_from_bind_ptr_long_double() {
        if (auto sp = _bind_ptr_long_double.lock()) return long_double_to_string(*sp);
        else return STR_NULL;
    }
    std::string Length::long_double_to_string(const long double &attr) {
        return std::to_string(attr);
    }
    void Length::set(const long double &attr) {
        _con_val_long_double = attr;
        _commit = std::bind(&Length::_from_con_val_long_double, this);
    }
    Length &Length::operator=(const long double &attr) {
        _con_val_long_double = attr;
        _commit = std::bind(&Length::_from_con_val_long_double, this);
    }
    void Length::bind(const long double (*bind_func)()) {
        _bind_func_long_double = bind_func;
        _commit = std::bind(&Length::_from_bind_func_long_double, this);
    }
    Length &Length::operator[](const long double (*bind_func)()) {
        _bind_func_long_double = bind_func;
        _commit = std::bind(&Length::_from_bind_func_long_double, this);
    }
    void Length::bind(const std::weak_ptr<long double> &bind_ptr) {
        _bind_ptr_long_double = bind_ptr;
        _commit = std::bind(&Length::_from_bind_ptr_long_double, this);
    }
    Length &Length::operator[](const std::weak_ptr<long double> &bind_ptr) {
        _bind_ptr_long_double = bind_ptr;
        _commit = std::bind(&Length::_from_bind_ptr_long_double, this);
    }

    const std::string Length::_from_con_val_legal_string() {
        return legal_string_to_string(_con_val_legal_string);
    }
    const std::string Length::_from_bind_func_legal_string() {
    return legal_string_to_string((*_bind_func_legal_string)());
    }
    const std::string Length::_from_bind_ptr_legal_string() {
        if (auto sp = _bind_ptr_legal_string.lock()) return legal_string_to_string(*sp);
        else return STR_NULL;
    }
    std::string Length::legal_string_to_string(const std::string &attr) {
        if (!is_legal_string(attr)) {
            _LZ_WARNING("Illegal string when converting \"" << attr << "\" to Length.")
            return STR_NULL;
        } else {
            return attr;
        }
    }
    void Length::set(const std::string &attr) {
        _con_val_legal_string = attr;
        _commit = std::bind(&Length::_from_con_val_legal_string, this);
    }
    Length &Length::operator=(const std::string &attr) {
        _con_val_legal_string = attr;
        _commit = std::bind(&Length::_from_con_val_legal_string, this);
    }
    void Length::set(const char *attr) {
        set(std::string(attr));
    }
    Length &Length::operator=(const char *attr) {
        operator=(std::string(attr));
    }
    void Length::bind(const std::string (*bind_func)()) {
        _bind_func_legal_string = bind_func;
        _commit = std::bind(&Length::_from_bind_func_legal_string, this);
    }
    Length &Length::operator[](const std::string (*bind_func)()) {
        _bind_func_legal_string = bind_func;
        _commit = std::bind(&Length::_from_bind_func_legal_string, this);
    }
    void Length::bind(const std::weak_ptr<std::string> &bind_ptr) {
        _bind_ptr_legal_string = bind_ptr;
        _commit = std::bind(&Length::_from_bind_ptr_legal_string, this);
    }
    Length &Length::operator[](const std::weak_ptr<std::string> &bind_ptr) {
        _bind_ptr_legal_string = bind_ptr;
        _commit = std::bind(&Length::_from_bind_ptr_legal_string, this);
    }
    bool Length::is_legal_string(const std::string &attr) {
        std::regex re(R"(^(([+-]?[0-9]+)([Ee]([+-]?[0-9]+))?|[+-]?[0-9]*\.[0-9]+([Ee]([+-]?[0-9]+))?)(em|ex|px|in|cm|mm|pt|pc|%)?$)");
        return std::regex_match(attr, re);
    }
}
#endif
