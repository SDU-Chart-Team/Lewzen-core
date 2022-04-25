#ifndef __LZ_ATTR_NAME_I__
#define __LZ_ATTR_NAME_I__
#include "attr_name.h"

namespace Lewzen {
    AttrName::AttrName() {}
    AttrName::AttrName(std::function<const std::string()> getter, std::function<void(const std::string &)> setter): _getter(getter), _setter(setter) {}
    void AttrName::set_getter(std::function<const std::string()> getter) {
        _getter = getter;
    }
    void AttrName::set_setter(std::function<void(const std::string &)> setter) {
        _setter = setter;
    }
    const std::string AttrName::get() const {
        if (!_getter) return STR_NULL;
        return _getter();
    }
    const std::string AttrName::get_commit() const {
        if (!_commit) return STR_NULL;
        return _commit();   
    }
    void AttrName::commit() {
        if (!_setter || !_commit) return;
        _setter(_commit());
    }
    template <typename T>
    void AttrName::set(const T &attr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrName.set with no implementation. Reset value.")
    }
    template <typename T>
    AttrName &AttrName::operator=(const T &attr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrName.set with no implementation. Reset value.")
    }
    template <typename T>
    void AttrName::bind(std::function<const T()>bind_func) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrName.set with no implementation. Reset value.")
    }
    template <typename T>
    void AttrName::bind(const std::weak_ptr<T> &bind_ptr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrName.set with no implementation. Reset value.")
    }
    template <typename T>
    AttrName &AttrName::operator[](std::function<const T()>bind_func) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrName.set with no implementation. Reset value.")
    }
    template <typename T>
    AttrName &AttrName::operator[](const std::weak_ptr<T> &bind_ptr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrName.set with no implementation. Reset value.")
    }

    const std::string AttrName::_from_con_val_legal_string() {
        return legal_string_to_string(_con_val_legal_string);
    }
    const std::string AttrName::_from_bind_func_legal_string() {
        return legal_string_to_string(_bind_func_legal_string());
    }
    const std::string AttrName::_from_bind_ptr_legal_string() {
        if (auto sp = _bind_ptr_legal_string.lock()) return legal_string_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrName::legal_string_to_string(const std::string &attr) {
        if (!is_legal_string(attr)) {
            _LZ_WARNING("Illegal string when converting \"" << attr << "\" to Name.")
            return STR_NULL;
        } else {
            return attr;
        }
    }
    void AttrName::set(const std::string &attr) {
        _con_val_legal_string = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrName::_from_con_val_legal_string, this);
        _on_assign(_last);
    }
    AttrName &AttrName::operator=(const std::string &attr) {
        _con_val_legal_string = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrName::_from_con_val_legal_string, this);
        _on_assign(_last);
    }
    void AttrName::set(const char *attr) {
        set(std::string(attr));
    }
    AttrName &AttrName::operator=(const char *attr) {
        operator=(std::string(attr));
    }
    void AttrName::bind(std::function<const std::string()> bind_func) {
        _bind_func_legal_string = bind_func;
        _commit = std::bind(&AttrName::_from_bind_func_legal_string, this);
        _on_bind_func();
    }
    AttrName &AttrName::operator[](std::function<const std::string()> bind_func) {
        _bind_func_legal_string = bind_func;
        _commit = std::bind(&AttrName::_from_bind_func_legal_string, this);
        _on_bind_func();
        return *this;
    }
    void AttrName::bind(const std::weak_ptr<std::string> &bind_ptr) {
        _bind_ptr_legal_string = bind_ptr;
        _commit = std::bind(&AttrName::_from_bind_ptr_legal_string, this);
        _on_bind_ptr();
    }
    AttrName &AttrName::operator[](const std::weak_ptr<std::string> &bind_ptr) {
        _bind_ptr_legal_string = bind_ptr;
        _commit = std::bind(&AttrName::_from_bind_ptr_legal_string, this);
        _on_bind_ptr();
        return *this;
    }
    bool AttrName::is_legal_string(const std::string &attr) {
        std::regex re(R"(^[^,()\x20\x9\xD\xA]+$)");
        return std::regex_match(attr, re);
    }
    void AttrName::callback_assign(std::function<void(const std::string &)> on_assign) { _on_assign = on_assign; }
    void AttrName::callback_assign() { _on_assign = [](const std::string &last){}; }
    void AttrName::callback_bind_func(std::function<void()> on_bind_func) { _on_bind_func = on_bind_func; }
    void AttrName::callback_bind_func() { _on_bind_func = [](){}; }
    void AttrName::callback_bind_ptr(std::function<void()> on_bind_ptr) { _on_bind_ptr = on_bind_ptr; }
    void AttrName::callback_bind_ptr() { _on_bind_ptr = [](){}; }
}
#endif
