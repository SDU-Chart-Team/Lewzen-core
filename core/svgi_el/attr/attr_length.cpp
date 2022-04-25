#ifndef __LZ_ATTR_LENGTH_I__
#define __LZ_ATTR_LENGTH_I__
#include "attr_length.h"

namespace Lewzen {
    AttrLength::AttrLength() {}
    AttrLength::AttrLength(std::function<const std::string()> getter, std::function<void(const std::string &)> setter): _getter(getter), _setter(setter) {}
    void AttrLength::set_getter(std::function<const std::string()> getter) {
        _getter = getter;
    }
    void AttrLength::set_setter(std::function<void(const std::string &)> setter) {
        _setter = setter;
    }
    const std::string AttrLength::get() const {
        if (!_getter) return STR_NULL;
        return _getter();
    }
    const std::string AttrLength::get_commit() const {
        if (!_commit) return STR_NULL;
        return _commit();   
    }
    void AttrLength::commit() {
        if (!_setter || !_commit) return;
        _setter(_commit());
    }
    template <typename T>
    void AttrLength::set(const T &attr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrLength.set with no implementation. Reset value.")
    }
    template <typename T>
    AttrLength &AttrLength::operator=(const T &attr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrLength.set with no implementation. Reset value.")
    }
    template <typename T>
    void AttrLength::bind(std::function<const T()>bind_func) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrLength.set with no implementation. Reset value.")
    }
    template <typename T>
    void AttrLength::bind(const std::weak_ptr<T> &bind_ptr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrLength.set with no implementation. Reset value.")
    }
    template <typename T>
    AttrLength &AttrLength::operator[](std::function<const T()>bind_func) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrLength.set with no implementation. Reset value.")
    }
    template <typename T>
    AttrLength &AttrLength::operator[](const std::weak_ptr<T> &bind_ptr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrLength.set with no implementation. Reset value.")
    }

    const std::string AttrLength::_from_con_val_integer() {
        return integer_to_string(_con_val_integer);
    }
    const std::string AttrLength::_from_bind_func_integer() {
        return integer_to_string(_bind_func_integer());
    }
    const std::string AttrLength::_from_bind_ptr_integer() {
        if (auto sp = _bind_ptr_integer.lock()) return integer_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrLength::integer_to_string(const int &attr) {
        return std::to_string(attr);
    }
    void AttrLength::set(const int &attr) {
        _con_val_integer = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrLength::_from_con_val_integer, this);
        _on_assign(_last);
    }
    AttrLength &AttrLength::operator=(const int &attr) {
        _con_val_integer = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrLength::_from_con_val_integer, this);
        _on_assign(_last);
    }
    void AttrLength::bind(std::function<const int()> bind_func) {
        _bind_func_integer = bind_func;
        _commit = std::bind(&AttrLength::_from_bind_func_integer, this);
        _on_bind_func();
    }
    AttrLength &AttrLength::operator[](std::function<const int()> bind_func) {
        _bind_func_integer = bind_func;
        _commit = std::bind(&AttrLength::_from_bind_func_integer, this);
        _on_bind_func();
        return *this;
    }
    void AttrLength::bind(const std::weak_ptr<int> &bind_ptr) {
        _bind_ptr_integer = bind_ptr;
        _commit = std::bind(&AttrLength::_from_bind_ptr_integer, this);
        _on_bind_ptr();
    }
    AttrLength &AttrLength::operator[](const std::weak_ptr<int> &bind_ptr) {
        _bind_ptr_integer = bind_ptr;
        _commit = std::bind(&AttrLength::_from_bind_ptr_integer, this);
        _on_bind_ptr();
        return *this;
    }

    const std::string AttrLength::_from_con_val_float() {
        return float_to_string(_con_val_float);
    }
    const std::string AttrLength::_from_bind_func_float() {
        return float_to_string(_bind_func_float());
    }
    const std::string AttrLength::_from_bind_ptr_float() {
        if (auto sp = _bind_ptr_float.lock()) return float_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrLength::float_to_string(const float &attr) {
        return std::to_string(attr);
    }
    void AttrLength::set(const float &attr) {
        _con_val_float = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrLength::_from_con_val_float, this);
        _on_assign(_last);
    }
    AttrLength &AttrLength::operator=(const float &attr) {
        _con_val_float = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrLength::_from_con_val_float, this);
        _on_assign(_last);
    }
    void AttrLength::bind(std::function<const float()> bind_func) {
        _bind_func_float = bind_func;
        _commit = std::bind(&AttrLength::_from_bind_func_float, this);
        _on_bind_func();
    }
    AttrLength &AttrLength::operator[](std::function<const float()> bind_func) {
        _bind_func_float = bind_func;
        _commit = std::bind(&AttrLength::_from_bind_func_float, this);
        _on_bind_func();
        return *this;
    }
    void AttrLength::bind(const std::weak_ptr<float> &bind_ptr) {
        _bind_ptr_float = bind_ptr;
        _commit = std::bind(&AttrLength::_from_bind_ptr_float, this);
        _on_bind_ptr();
    }
    AttrLength &AttrLength::operator[](const std::weak_ptr<float> &bind_ptr) {
        _bind_ptr_float = bind_ptr;
        _commit = std::bind(&AttrLength::_from_bind_ptr_float, this);
        _on_bind_ptr();
        return *this;
    }

    const std::string AttrLength::_from_con_val_double() {
        return double_to_string(_con_val_double);
    }
    const std::string AttrLength::_from_bind_func_double() {
        return double_to_string(_bind_func_double());
    }
    const std::string AttrLength::_from_bind_ptr_double() {
        if (auto sp = _bind_ptr_double.lock()) return double_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrLength::double_to_string(const double &attr) {
        return std::to_string(attr);
    }
    void AttrLength::set(const double &attr) {
        _con_val_double = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrLength::_from_con_val_double, this);
        _on_assign(_last);
    }
    AttrLength &AttrLength::operator=(const double &attr) {
        _con_val_double = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrLength::_from_con_val_double, this);
        _on_assign(_last);
    }
    void AttrLength::bind(std::function<const double()> bind_func) {
        _bind_func_double = bind_func;
        _commit = std::bind(&AttrLength::_from_bind_func_double, this);
        _on_bind_func();
    }
    AttrLength &AttrLength::operator[](std::function<const double()> bind_func) {
        _bind_func_double = bind_func;
        _commit = std::bind(&AttrLength::_from_bind_func_double, this);
        _on_bind_func();
        return *this;
    }
    void AttrLength::bind(const std::weak_ptr<double> &bind_ptr) {
        _bind_ptr_double = bind_ptr;
        _commit = std::bind(&AttrLength::_from_bind_ptr_double, this);
        _on_bind_ptr();
    }
    AttrLength &AttrLength::operator[](const std::weak_ptr<double> &bind_ptr) {
        _bind_ptr_double = bind_ptr;
        _commit = std::bind(&AttrLength::_from_bind_ptr_double, this);
        _on_bind_ptr();
        return *this;
    }

    const std::string AttrLength::_from_con_val_long() {
        return long_to_string(_con_val_long);
    }
    const std::string AttrLength::_from_bind_func_long() {
        return long_to_string(_bind_func_long());
    }
    const std::string AttrLength::_from_bind_ptr_long() {
        if (auto sp = _bind_ptr_long.lock()) return long_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrLength::long_to_string(const long &attr) {
        return std::to_string(attr);
    }
    void AttrLength::set(const long &attr) {
        _con_val_long = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrLength::_from_con_val_long, this);
        _on_assign(_last);
    }
    AttrLength &AttrLength::operator=(const long &attr) {
        _con_val_long = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrLength::_from_con_val_long, this);
        _on_assign(_last);
    }
    void AttrLength::bind(std::function<const long()> bind_func) {
        _bind_func_long = bind_func;
        _commit = std::bind(&AttrLength::_from_bind_func_long, this);
        _on_bind_func();
    }
    AttrLength &AttrLength::operator[](std::function<const long()> bind_func) {
        _bind_func_long = bind_func;
        _commit = std::bind(&AttrLength::_from_bind_func_long, this);
        _on_bind_func();
        return *this;
    }
    void AttrLength::bind(const std::weak_ptr<long> &bind_ptr) {
        _bind_ptr_long = bind_ptr;
        _commit = std::bind(&AttrLength::_from_bind_ptr_long, this);
        _on_bind_ptr();
    }
    AttrLength &AttrLength::operator[](const std::weak_ptr<long> &bind_ptr) {
        _bind_ptr_long = bind_ptr;
        _commit = std::bind(&AttrLength::_from_bind_ptr_long, this);
        _on_bind_ptr();
        return *this;
    }

    const std::string AttrLength::_from_con_val_long_integer() {
        return long_integer_to_string(_con_val_long_integer);
    }
    const std::string AttrLength::_from_bind_func_long_integer() {
        return long_integer_to_string(_bind_func_long_integer());
    }
    const std::string AttrLength::_from_bind_ptr_long_integer() {
        if (auto sp = _bind_ptr_long_integer.lock()) return long_integer_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrLength::long_integer_to_string(const long long int &attr) {
        return std::to_string(attr);
    }
    void AttrLength::set(const long long int &attr) {
        _con_val_long_integer = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrLength::_from_con_val_long_integer, this);
        _on_assign(_last);
    }
    AttrLength &AttrLength::operator=(const long long int &attr) {
        _con_val_long_integer = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrLength::_from_con_val_long_integer, this);
        _on_assign(_last);
    }
    void AttrLength::bind(std::function<const long long int()> bind_func) {
        _bind_func_long_integer = bind_func;
        _commit = std::bind(&AttrLength::_from_bind_func_long_integer, this);
        _on_bind_func();
    }
    AttrLength &AttrLength::operator[](std::function<const long long int()> bind_func) {
        _bind_func_long_integer = bind_func;
        _commit = std::bind(&AttrLength::_from_bind_func_long_integer, this);
        _on_bind_func();
        return *this;
    }
    void AttrLength::bind(const std::weak_ptr<long long int> &bind_ptr) {
        _bind_ptr_long_integer = bind_ptr;
        _commit = std::bind(&AttrLength::_from_bind_ptr_long_integer, this);
        _on_bind_ptr();
    }
    AttrLength &AttrLength::operator[](const std::weak_ptr<long long int> &bind_ptr) {
        _bind_ptr_long_integer = bind_ptr;
        _commit = std::bind(&AttrLength::_from_bind_ptr_long_integer, this);
        _on_bind_ptr();
        return *this;
    }

    const std::string AttrLength::_from_con_val_long_double() {
        return long_double_to_string(_con_val_long_double);
    }
    const std::string AttrLength::_from_bind_func_long_double() {
        return long_double_to_string(_bind_func_long_double());
    }
    const std::string AttrLength::_from_bind_ptr_long_double() {
        if (auto sp = _bind_ptr_long_double.lock()) return long_double_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrLength::long_double_to_string(const long double &attr) {
        return std::to_string(attr);
    }
    void AttrLength::set(const long double &attr) {
        _con_val_long_double = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrLength::_from_con_val_long_double, this);
        _on_assign(_last);
    }
    AttrLength &AttrLength::operator=(const long double &attr) {
        _con_val_long_double = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrLength::_from_con_val_long_double, this);
        _on_assign(_last);
    }
    void AttrLength::bind(std::function<const long double()> bind_func) {
        _bind_func_long_double = bind_func;
        _commit = std::bind(&AttrLength::_from_bind_func_long_double, this);
        _on_bind_func();
    }
    AttrLength &AttrLength::operator[](std::function<const long double()> bind_func) {
        _bind_func_long_double = bind_func;
        _commit = std::bind(&AttrLength::_from_bind_func_long_double, this);
        _on_bind_func();
        return *this;
    }
    void AttrLength::bind(const std::weak_ptr<long double> &bind_ptr) {
        _bind_ptr_long_double = bind_ptr;
        _commit = std::bind(&AttrLength::_from_bind_ptr_long_double, this);
        _on_bind_ptr();
    }
    AttrLength &AttrLength::operator[](const std::weak_ptr<long double> &bind_ptr) {
        _bind_ptr_long_double = bind_ptr;
        _commit = std::bind(&AttrLength::_from_bind_ptr_long_double, this);
        _on_bind_ptr();
        return *this;
    }

    const std::string AttrLength::_from_con_val_legal_string() {
        return legal_string_to_string(_con_val_legal_string);
    }
    const std::string AttrLength::_from_bind_func_legal_string() {
        return legal_string_to_string(_bind_func_legal_string());
    }
    const std::string AttrLength::_from_bind_ptr_legal_string() {
        if (auto sp = _bind_ptr_legal_string.lock()) return legal_string_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrLength::legal_string_to_string(const std::string &attr) {
        if (!is_legal_string(attr)) {
            _LZ_WARNING("Illegal string when converting \"" << attr << "\" to Length.")
            return STR_NULL;
        } else {
            return attr;
        }
    }
    void AttrLength::set(const std::string &attr) {
        _con_val_legal_string = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrLength::_from_con_val_legal_string, this);
        _on_assign(_last);
    }
    AttrLength &AttrLength::operator=(const std::string &attr) {
        _con_val_legal_string = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrLength::_from_con_val_legal_string, this);
        _on_assign(_last);
    }
    void AttrLength::set(const char *attr) {
        set(std::string(attr));
    }
    AttrLength &AttrLength::operator=(const char *attr) {
        operator=(std::string(attr));
    }
    void AttrLength::bind(std::function<const std::string()> bind_func) {
        _bind_func_legal_string = bind_func;
        _commit = std::bind(&AttrLength::_from_bind_func_legal_string, this);
        _on_bind_func();
    }
    AttrLength &AttrLength::operator[](std::function<const std::string()> bind_func) {
        _bind_func_legal_string = bind_func;
        _commit = std::bind(&AttrLength::_from_bind_func_legal_string, this);
        _on_bind_func();
        return *this;
    }
    void AttrLength::bind(const std::weak_ptr<std::string> &bind_ptr) {
        _bind_ptr_legal_string = bind_ptr;
        _commit = std::bind(&AttrLength::_from_bind_ptr_legal_string, this);
        _on_bind_ptr();
    }
    AttrLength &AttrLength::operator[](const std::weak_ptr<std::string> &bind_ptr) {
        _bind_ptr_legal_string = bind_ptr;
        _commit = std::bind(&AttrLength::_from_bind_ptr_legal_string, this);
        _on_bind_ptr();
        return *this;
    }
    bool AttrLength::is_legal_string(const std::string &attr) {
        std::regex re(R"(^(([+-]?[0-9]+)([Ee]([+-]?[0-9]+))?|[+-]?[0-9]*\.[0-9]+([Ee]([+-]?[0-9]+))?)(em|ex|px|in|cm|mm|pt|pc|%)?$)");
        return std::regex_match(attr, re);
    }
    void AttrLength::callback_assign(std::function<void(const std::string &)> on_assign) { _on_assign = on_assign; }
    void AttrLength::callback_assign() { _on_assign = [](const std::string &last){}; }
    void AttrLength::callback_bind_func(std::function<void()> on_bind_func) { _on_bind_func = on_bind_func; }
    void AttrLength::callback_bind_func() { _on_bind_func = [](){}; }
    void AttrLength::callback_bind_ptr(std::function<void()> on_bind_ptr) { _on_bind_ptr = on_bind_ptr; }
    void AttrLength::callback_bind_ptr() { _on_bind_ptr = [](){}; }
}
#endif
