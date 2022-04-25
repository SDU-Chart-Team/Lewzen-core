#include "attr.h"

namespace Lewzen {
    Attribute::Attribute() {}
    Attribute::Attribute(std::function<const std::string()> getter, std::function<void(const std::string &)> setter): _getter(getter), _setter(setter) {}
    const std::string Attribute::get() const {
        if (!_getter) return STR_NULL;
        return _getter();
    }
    const std::string Attribute::get_commit() const {
        if (!_commit) return STR_NULL;
        return _commit();
    }
    template <typename T>
    void Attribute::set(const T &attr) { _LZ_WARNING("Calling Attribute.set, but no implementation.") }
    template <typename T>
    Attribute &Attribute::operator=(const T &attr) { _LZ_WARNING("Calling Attribute.operator=, but no implementation.") }
    template <typename T>
    void Attribute::bind(std::function<const T> bind_func) { _LZ_WARNING("Calling Attribute.bind, but no implementation.") }
    template <typename T>
    void Attribute::bind(const std::weak_ptr<T> &bind_ptr) { _LZ_WARNING("Calling Attribute.bind, but no implementation.") }
    template <typename T>
    Attribute &Attribute::operator[](std::function<const T> bind_func) {
        bind(bind_func);
        return *this;
    }
    template <typename T>
    Attribute &Attribute::operator[](const std::weak_ptr<T> &bind_ptr) {
        bind(bind_ptr);
        return *this;
    }
    void Attribute::commit() {
        if (!_setter || !_commit) return;
        _setter(_commit());
    }
    void Attribute::callback_assign(std::function<void(const std::string &)> on_assign) { _on_assign = on_assign; }
    void Attribute::callback_assign() { _on_assign = [](const std::string &last){}; }
    void Attribute::callback_bind_func(std::function<void()> on_bind_func) { _on_bind_func = on_bind_func; }
    void Attribute::callback_bind_func() { _on_bind_func = [](){}; }
    void Attribute::callback_bind_ptr(std::function<void()> on_bind_ptr) { _on_bind_ptr = on_bind_ptr; }
    void Attribute::callback_bind_ptr() { _on_bind_ptr = [](){}; }
}
