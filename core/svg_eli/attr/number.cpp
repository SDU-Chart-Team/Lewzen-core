#include "number.h"

namespace Lewzen {
    Number::Number() {}
    Number::Number(const std::string (*getter)(), void (*setter)(const std::string &)): _getter(getter), _setter(setter) {}
    const std::string Number::get() const {
        if (_getter == nullptr) return STR_NULL;
        return (*_getter)();
    }
    const std::string Number::get_commit() const {
        return (* _commit)();   
    }
    void Number::commit() {
        if (_setter == nullptr || _commit == nullptr) return;
        (*_setter)((* _commit)());
    }
    template <typename T>
    void Number::set(const T &attr) {
        (*_setter)(STR_NULL);
    }
    template <typename T>
    Number &Number::operator=(const T &attr) {
        (*_setter)(STR_NULL);
    }
    template <typename T>
    void Number::bind(const T (*bind_func)()) {
        (*_setter)(STR_NULL);
    }
    template <typename T>
    void Number::bind(const std::weak_ptr<T> &bind_ptr) {
        (*_setter)(STR_NULL);
    }
    template <typename T>
    Number &Number::operator[](const T (*bind_func)) {
        (*_setter)(STR_NULL);
    }
    template <typename T>
    Number &Number::operator[](const std::weak_ptr<T> &bind_ptr) {
        (*_setter)(STR_NULL);
    }

    const std::string Number::_from_con_val_int() {
        return integer_to_string(_con_val_int);
    }
        const std::string Number::_from_bind_func_int() {
        return integer_to_string((*_bind_func_int)());
        }
    const std::string Number::_from_bind_ptr_int() {
        if (auto sp = _bind_ptr_int.lock()) return integer_to_string(*sp);
        else return STR_NULL;
    }
    std::string Number::integer_to_string(const int &attr) {
        return std::to_string(attr);
    }
    void Number::set(const int &attr) {
        _con_val_int = attr;
    }
    Number &Number::operator=(const int &attr) {
        _con_val_int = attr;
    }
    void Number::bind(const int (*bind_func)()) {
        _bind_func_int = bind_func;
    }
    Number &Number::operator[](const int (*bind_func)()) {
        _bind_func_int = bind_func;
    }
    void Number::bind(const std::weak_ptr<int> &bind_ptr) {
        _bind_ptr_int = bind_ptr;
    }
    Number &Number::operator[](const std::weak_ptr<int> &bind_ptr) {
        _bind_ptr_int = bind_ptr;
    }
}