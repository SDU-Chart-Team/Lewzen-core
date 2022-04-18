#include "attr.h"

namespace Lewzen {
    Attribute::Attribute() {}
    Attribute::Attribute(const std::string (*getter)(), void (*setter)(const std::string &)): _getter(getter), _setter(setter) {}
    const std::string Attribute::get() const {
        if (_getter == nullptr) return STR_NULL;
        return (*_getter)();
    }
    const std::string Attribute::get_commit() const {
        return (*_commit)();
    }
    template <typename T>
    void Attribute::set(const T &attr) { _LZ_WARNING("Calling Attribute.set, but no implementation.") }
    template <typename T>
    Attribute &Attribute::operator=(const T &attr) { _LZ_WARNING("Calling Attribute.operator=, but no implementation.") }
    template <typename T>
    void Attribute::bind(const T (*bind_func)()) { _LZ_WARNING("Calling Attribute.bind, but no implementation.") }
    template <typename T>
    void Attribute::bind(const std::weak_ptr<T> &bind_ptr) { _LZ_WARNING("Calling Attribute.bind, but no implementation.") }
    template <typename T>
    Attribute &Attribute::operator[](const T (*bind_func)) {
        bind(bind_func);
        return *this;
    }
    template <typename T>
    Attribute &Attribute::operator[](const std::weak_ptr<T> &bind_ptr) {
        bind(bind_ptr);
        return *this;
    }
    void Attribute::commit() {
        if (_setter == nullptr || _commit == nullptr) return;
        (*_setter)((* _commit)());
    }
}   