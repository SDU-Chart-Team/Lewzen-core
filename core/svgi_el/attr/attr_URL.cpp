#ifndef __LZ_ATTR__URL_I__
#define __LZ_ATTR__URL_I__
#include "attr_URL.h"

namespace Lewzen {
    AttrURL::AttrURL() {}
    AttrURL::AttrURL(std::function<const std::string()> getter, std::function<void(const std::string &)> setter): _getter(getter), _setter(setter) {}
    void AttrURL::set_getter(std::function<const std::string()> getter) {
        _getter = getter;
    }
    void AttrURL::set_setter(std::function<void(const std::string &)> setter) {
        _setter = setter;
    }
    const std::string AttrURL::get() const {
        if (!_getter) return STR_NULL;
        return _getter();
    }
    const std::string AttrURL::get_commit() const {
        if (!_commit) return STR_NULL;
        return _commit();   
    }
    void AttrURL::commit() {
        if (!_setter || !_commit) return;
        _setter(_commit());
    }
    template <typename T>
    void AttrURL::set(const T &attr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrURL.set with no implementation. Reset value.")
    }
    template <typename T>
    AttrURL &AttrURL::operator=(const T &attr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrURL.set with no implementation. Reset value.")
    }
    template <typename T>
    void AttrURL::bind(std::function<const T()>bind_func) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrURL.set with no implementation. Reset value.")
    }
    template <typename T>
    void AttrURL::bind(const std::weak_ptr<T> &bind_ptr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrURL.set with no implementation. Reset value.")
    }
    template <typename T>
    AttrURL &AttrURL::operator[](std::function<const T()>bind_func) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrURL.set with no implementation. Reset value.")
    }
    template <typename T>
    AttrURL &AttrURL::operator[](const std::weak_ptr<T> &bind_ptr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrURL.set with no implementation. Reset value.")
    }

    const std::string AttrURL::_from_con_val_string() {
        return string_to_string(_con_val_string);
    }
    const std::string AttrURL::_from_bind_func_string() {
        return string_to_string(_bind_func_string());
    }
    const std::string AttrURL::_from_bind_ptr_string() {
        if (auto sp = _bind_ptr_string.lock()) return string_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrURL::string_to_string(const std::string &attr) {
        return attr;
    }
    void AttrURL::set(const std::string &attr) {
        _con_val_string = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrURL::_from_con_val_string, this);
        _on_assign(_last);
    }
    AttrURL &AttrURL::operator=(const std::string &attr) {
        _con_val_string = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrURL::_from_con_val_string, this);
        _on_assign(_last);
    }
    void AttrURL::set(const char *attr) {
        set(std::string(attr));
    }
    AttrURL &AttrURL::operator=(const char *attr) {
        operator=(std::string(attr));
    }
    void AttrURL::bind(std::function<const std::string()> bind_func) {
        _bind_func_string = bind_func;
        _commit = std::bind(&AttrURL::_from_bind_func_string, this);
        _on_bind_func();
    }
    AttrURL &AttrURL::operator[](std::function<const std::string()> bind_func) {
        _bind_func_string = bind_func;
        _commit = std::bind(&AttrURL::_from_bind_func_string, this);
        _on_bind_func();
        return *this;
    }
    void AttrURL::bind(const std::weak_ptr<std::string> &bind_ptr) {
        _bind_ptr_string = bind_ptr;
        _commit = std::bind(&AttrURL::_from_bind_ptr_string, this);
        _on_bind_ptr();
    }
    AttrURL &AttrURL::operator[](const std::weak_ptr<std::string> &bind_ptr) {
        _bind_ptr_string = bind_ptr;
        _commit = std::bind(&AttrURL::_from_bind_ptr_string, this);
        _on_bind_ptr();
        return *this;
    }
    void AttrURL::callback_assign(std::function<void(const std::string &)> on_assign) { _on_assign = on_assign; }
    void AttrURL::callback_assign() { _on_assign = [](const std::string &last){}; }
    void AttrURL::callback_bind_func(std::function<void()> on_bind_func) { _on_bind_func = on_bind_func; }
    void AttrURL::callback_bind_func() { _on_bind_func = [](){}; }
    void AttrURL::callback_bind_ptr(std::function<void()> on_bind_ptr) { _on_bind_ptr = on_bind_ptr; }
    void AttrURL::callback_bind_ptr() { _on_bind_ptr = [](){}; }
}
#endif
