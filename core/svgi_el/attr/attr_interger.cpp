#ifndef __LZ_ATTR_INTERGER_I__
#define __LZ_ATTR_INTERGER_I__
#include "attr_interger.h"

namespace Lewzen {
    AttrInterger::AttrInterger() {}
    AttrInterger::AttrInterger(std::function<const std::string()> getter, std::function<void(const std::string &)> setter): _getter(getter), _setter(setter) {}
    void AttrInterger::set_getter(std::function<const std::string()> getter) {
        _getter = getter;
    }
    void AttrInterger::set_setter(std::function<void(const std::string &)> setter) {
        _setter = setter;
    }
    const std::string AttrInterger::get() const {
        if (!_getter) return STR_NULL;
        return _getter();
    }
    const std::string AttrInterger::get_commit() const {
        if (!_commit) return STR_NULL;
        return _commit();   
    }
    void AttrInterger::commit() {
        if (!_setter || !_commit) return;
        _setter(_commit());
    }
    template <typename T>
    void AttrInterger::set(const T &attr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrInterger.set with no implementation. Reset value.")
    }
    template <typename T>
    AttrInterger &AttrInterger::operator=(const T &attr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrInterger.set with no implementation. Reset value.")
    }
    template <typename T>
    void AttrInterger::bind(std::function<const T()>bind_func) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrInterger.set with no implementation. Reset value.")
    }
    template <typename T>
    void AttrInterger::bind(const std::weak_ptr<T> &bind_ptr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrInterger.set with no implementation. Reset value.")
    }
    template <typename T>
    AttrInterger &AttrInterger::operator[](std::function<const T()>bind_func) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrInterger.set with no implementation. Reset value.")
    }
    template <typename T>
    AttrInterger &AttrInterger::operator[](const std::weak_ptr<T> &bind_ptr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrInterger.set with no implementation. Reset value.")
    }

    const std::string AttrInterger::_from_con_val_integer() {
        return integer_to_string(_con_val_integer);
    }
    const std::string AttrInterger::_from_bind_func_integer() {
        return integer_to_string(_bind_func_integer());
    }
    const std::string AttrInterger::_from_bind_ptr_integer() {
        if (auto sp = _bind_ptr_integer.lock()) return integer_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrInterger::integer_to_string(const int &attr) {
        return std::to_string(attr);
    }
    void AttrInterger::set(const int &attr) {
        _con_val_integer = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrInterger::_from_con_val_integer, this);
        _on_assign(_last);
    }
    AttrInterger &AttrInterger::operator=(const int &attr) {
        _con_val_integer = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrInterger::_from_con_val_integer, this);
        _on_assign(_last);
    }
    void AttrInterger::bind(std::function<const int()> bind_func) {
        _bind_func_integer = bind_func;
        _commit = std::bind(&AttrInterger::_from_bind_func_integer, this);
        _on_bind_func();
    }
    AttrInterger &AttrInterger::operator[](std::function<const int()> bind_func) {
        _bind_func_integer = bind_func;
        _commit = std::bind(&AttrInterger::_from_bind_func_integer, this);
        _on_bind_func();
        return *this;
    }
    void AttrInterger::bind(const std::weak_ptr<int> &bind_ptr) {
        _bind_ptr_integer = bind_ptr;
        _commit = std::bind(&AttrInterger::_from_bind_ptr_integer, this);
        _on_bind_ptr();
    }
    AttrInterger &AttrInterger::operator[](const std::weak_ptr<int> &bind_ptr) {
        _bind_ptr_integer = bind_ptr;
        _commit = std::bind(&AttrInterger::_from_bind_ptr_integer, this);
        _on_bind_ptr();
        return *this;
    }

    const std::string AttrInterger::_from_con_val_long() {
        return long_to_string(_con_val_long);
    }
    const std::string AttrInterger::_from_bind_func_long() {
        return long_to_string(_bind_func_long());
    }
    const std::string AttrInterger::_from_bind_ptr_long() {
        if (auto sp = _bind_ptr_long.lock()) return long_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrInterger::long_to_string(const long &attr) {
        return std::to_string(attr);
    }
    void AttrInterger::set(const long &attr) {
        _con_val_long = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrInterger::_from_con_val_long, this);
        _on_assign(_last);
    }
    AttrInterger &AttrInterger::operator=(const long &attr) {
        _con_val_long = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrInterger::_from_con_val_long, this);
        _on_assign(_last);
    }
    void AttrInterger::bind(std::function<const long()> bind_func) {
        _bind_func_long = bind_func;
        _commit = std::bind(&AttrInterger::_from_bind_func_long, this);
        _on_bind_func();
    }
    AttrInterger &AttrInterger::operator[](std::function<const long()> bind_func) {
        _bind_func_long = bind_func;
        _commit = std::bind(&AttrInterger::_from_bind_func_long, this);
        _on_bind_func();
        return *this;
    }
    void AttrInterger::bind(const std::weak_ptr<long> &bind_ptr) {
        _bind_ptr_long = bind_ptr;
        _commit = std::bind(&AttrInterger::_from_bind_ptr_long, this);
        _on_bind_ptr();
    }
    AttrInterger &AttrInterger::operator[](const std::weak_ptr<long> &bind_ptr) {
        _bind_ptr_long = bind_ptr;
        _commit = std::bind(&AttrInterger::_from_bind_ptr_long, this);
        _on_bind_ptr();
        return *this;
    }

    const std::string AttrInterger::_from_con_val_long_integer() {
        return long_integer_to_string(_con_val_long_integer);
    }
    const std::string AttrInterger::_from_bind_func_long_integer() {
        return long_integer_to_string(_bind_func_long_integer());
    }
    const std::string AttrInterger::_from_bind_ptr_long_integer() {
        if (auto sp = _bind_ptr_long_integer.lock()) return long_integer_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrInterger::long_integer_to_string(const long long int &attr) {
        return std::to_string(attr);
    }
    void AttrInterger::set(const long long int &attr) {
        _con_val_long_integer = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrInterger::_from_con_val_long_integer, this);
        _on_assign(_last);
    }
    AttrInterger &AttrInterger::operator=(const long long int &attr) {
        _con_val_long_integer = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrInterger::_from_con_val_long_integer, this);
        _on_assign(_last);
    }
    void AttrInterger::bind(std::function<const long long int()> bind_func) {
        _bind_func_long_integer = bind_func;
        _commit = std::bind(&AttrInterger::_from_bind_func_long_integer, this);
        _on_bind_func();
    }
    AttrInterger &AttrInterger::operator[](std::function<const long long int()> bind_func) {
        _bind_func_long_integer = bind_func;
        _commit = std::bind(&AttrInterger::_from_bind_func_long_integer, this);
        _on_bind_func();
        return *this;
    }
    void AttrInterger::bind(const std::weak_ptr<long long int> &bind_ptr) {
        _bind_ptr_long_integer = bind_ptr;
        _commit = std::bind(&AttrInterger::_from_bind_ptr_long_integer, this);
        _on_bind_ptr();
    }
    AttrInterger &AttrInterger::operator[](const std::weak_ptr<long long int> &bind_ptr) {
        _bind_ptr_long_integer = bind_ptr;
        _commit = std::bind(&AttrInterger::_from_bind_ptr_long_integer, this);
        _on_bind_ptr();
        return *this;
    }

    const std::string AttrInterger::_from_con_val_legal_string() {
        return legal_string_to_string(_con_val_legal_string);
    }
    const std::string AttrInterger::_from_bind_func_legal_string() {
        return legal_string_to_string(_bind_func_legal_string());
    }
    const std::string AttrInterger::_from_bind_ptr_legal_string() {
        if (auto sp = _bind_ptr_legal_string.lock()) return legal_string_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrInterger::legal_string_to_string(const std::string &attr) {
        if (!is_legal_string(attr)) {
            _LZ_WARNING("Illegal string when converting \"" << attr << "\" to Integer.")
            return STR_NULL;
        } else {
            return attr;
        }
    }
    void AttrInterger::set(const std::string &attr) {
        _con_val_legal_string = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrInterger::_from_con_val_legal_string, this);
        _on_assign(_last);
    }
    AttrInterger &AttrInterger::operator=(const std::string &attr) {
        _con_val_legal_string = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrInterger::_from_con_val_legal_string, this);
        _on_assign(_last);
    }
    void AttrInterger::set(const char *attr) {
        set(std::string(attr));
    }
    AttrInterger &AttrInterger::operator=(const char *attr) {
        operator=(std::string(attr));
    }
    void AttrInterger::bind(std::function<const std::string()> bind_func) {
        _bind_func_legal_string = bind_func;
        _commit = std::bind(&AttrInterger::_from_bind_func_legal_string, this);
        _on_bind_func();
    }
    AttrInterger &AttrInterger::operator[](std::function<const std::string()> bind_func) {
        _bind_func_legal_string = bind_func;
        _commit = std::bind(&AttrInterger::_from_bind_func_legal_string, this);
        _on_bind_func();
        return *this;
    }
    void AttrInterger::bind(const std::weak_ptr<std::string> &bind_ptr) {
        _bind_ptr_legal_string = bind_ptr;
        _commit = std::bind(&AttrInterger::_from_bind_ptr_legal_string, this);
        _on_bind_ptr();
    }
    AttrInterger &AttrInterger::operator[](const std::weak_ptr<std::string> &bind_ptr) {
        _bind_ptr_legal_string = bind_ptr;
        _commit = std::bind(&AttrInterger::_from_bind_ptr_legal_string, this);
        _on_bind_ptr();
        return *this;
    }
    bool AttrInterger::is_legal_string(const std::string &attr) {
        std::regex re(R"(^[+-]?[0-9]+$)");
        return std::regex_match(attr, re);
    }
    void AttrInterger::callback_assign(std::function<void(const std::string &)> on_assign) { _on_assign = on_assign; }
    void AttrInterger::callback_assign() { _on_assign = [](const std::string &last){}; }
    void AttrInterger::callback_bind_func(std::function<void()> on_bind_func) { _on_bind_func = on_bind_func; }
    void AttrInterger::callback_bind_func() { _on_bind_func = [](){}; }
    void AttrInterger::callback_bind_ptr(std::function<void()> on_bind_ptr) { _on_bind_ptr = on_bind_ptr; }
    void AttrInterger::callback_bind_ptr() { _on_bind_ptr = [](){}; }
}
#endif
