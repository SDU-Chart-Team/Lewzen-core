#ifndef __LZ_ATTR__IRI_I__
#define __LZ_ATTR__IRI_I__
#include "attr_IRI.h"

namespace Lewzen {
    AttrIRI::AttrIRI() {}
    AttrIRI::AttrIRI(std::function<const std::string()> getter, std::function<void(const std::string &)> setter): _getter(getter), _setter(setter) {}
    void AttrIRI::set_getter(std::function<const std::string()> getter) {
        _getter = getter;
    }
    void AttrIRI::set_setter(std::function<void(const std::string &)> setter) {
        _setter = setter;
    }
    const std::string AttrIRI::get() const {
        if (!_getter) return STR_NULL;
        return _getter();
    }
    const std::string AttrIRI::get_commit() const {
        if (!_commit) return STR_NULL;
        return _commit();   
    }
    void AttrIRI::commit() {
        if (!_setter || !_commit) return;
        _setter(_commit());
    }
    template <typename T>
    void AttrIRI::set(const T &attr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrIRI.set with no implementation. Reset value.")
    }
    template <typename T>
    AttrIRI &AttrIRI::operator=(const T &attr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrIRI.set with no implementation. Reset value.")
    }
    template <typename T>
    void AttrIRI::bind(std::function<const T()>bind_func) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrIRI.set with no implementation. Reset value.")
    }
    template <typename T>
    void AttrIRI::bind(const std::weak_ptr<T> &bind_ptr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrIRI.set with no implementation. Reset value.")
    }
    template <typename T>
    AttrIRI &AttrIRI::operator[](std::function<const T()>bind_func) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrIRI.set with no implementation. Reset value.")
    }
    template <typename T>
    AttrIRI &AttrIRI::operator[](const std::weak_ptr<T> &bind_ptr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrIRI.set with no implementation. Reset value.")
    }

    const std::string AttrIRI::_from_con_val_string() {
        return string_to_string(_con_val_string);
    }
    const std::string AttrIRI::_from_bind_func_string() {
        return string_to_string(_bind_func_string());
    }
    const std::string AttrIRI::_from_bind_ptr_string() {
        if (auto sp = _bind_ptr_string.lock()) return string_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrIRI::string_to_string(const std::string &attr) {
        return attr;
    }
    void AttrIRI::set(const std::string &attr) {
        _con_val_string = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrIRI::_from_con_val_string, this);
        _on_assign(_last);
    }
    AttrIRI &AttrIRI::operator=(const std::string &attr) {
        _con_val_string = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrIRI::_from_con_val_string, this);
        _on_assign(_last);
    }
    void AttrIRI::set(const char *attr) {
        set(std::string(attr));
    }
    AttrIRI &AttrIRI::operator=(const char *attr) {
        operator=(std::string(attr));
    }
    void AttrIRI::bind(std::function<const std::string()> bind_func) {
        _bind_func_string = bind_func;
        _commit = std::bind(&AttrIRI::_from_bind_func_string, this);
        _on_bind_func();
    }
    AttrIRI &AttrIRI::operator[](std::function<const std::string()> bind_func) {
        _bind_func_string = bind_func;
        _commit = std::bind(&AttrIRI::_from_bind_func_string, this);
        _on_bind_func();
        return *this;
    }
    void AttrIRI::bind(const std::weak_ptr<std::string> &bind_ptr) {
        _bind_ptr_string = bind_ptr;
        _commit = std::bind(&AttrIRI::_from_bind_ptr_string, this);
        _on_bind_ptr();
    }
    AttrIRI &AttrIRI::operator[](const std::weak_ptr<std::string> &bind_ptr) {
        _bind_ptr_string = bind_ptr;
        _commit = std::bind(&AttrIRI::_from_bind_ptr_string, this);
        _on_bind_ptr();
        return *this;
    }
    void AttrIRI::callback_assign(std::function<void(const std::string &)> on_assign) { _on_assign = on_assign; }
    void AttrIRI::callback_assign() { _on_assign = [](const std::string &last){}; }
    void AttrIRI::callback_bind_func(std::function<void()> on_bind_func) { _on_bind_func = on_bind_func; }
    void AttrIRI::callback_bind_func() { _on_bind_func = [](){}; }
    void AttrIRI::callback_bind_ptr(std::function<void()> on_bind_ptr) { _on_bind_ptr = on_bind_ptr; }
    void AttrIRI::callback_bind_ptr() { _on_bind_ptr = [](){}; }
}
#endif
