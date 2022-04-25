#ifndef __LZ_ATTR_LIST_OF_NUMBERS_I__
#define __LZ_ATTR_LIST_OF_NUMBERS_I__
#include "attr_list-of-numbers.h"

namespace Lewzen {
    AttrListOfNumbers::AttrListOfNumbers() {}
    AttrListOfNumbers::AttrListOfNumbers(std::function<const std::string()> getter, std::function<void(const std::string &)> setter): _getter(getter), _setter(setter) {}
    void AttrListOfNumbers::set_getter(std::function<const std::string()> getter) {
        _getter = getter;
    }
    void AttrListOfNumbers::set_setter(std::function<void(const std::string &)> setter) {
        _setter = setter;
    }
    const std::string AttrListOfNumbers::get() const {
        if (!_getter) return STR_NULL;
        return _getter();
    }
    const std::string AttrListOfNumbers::get_commit() const {
        if (!_commit) return STR_NULL;
        return _commit();   
    }
    void AttrListOfNumbers::commit() {
        if (!_setter || !_commit) return;
        _setter(_commit());
    }
    template <typename T>
    void AttrListOfNumbers::set(const T &attr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrListOfNumbers.set with no implementation. Reset value.")
    }
    template <typename T>
    AttrListOfNumbers &AttrListOfNumbers::operator=(const T &attr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrListOfNumbers.set with no implementation. Reset value.")
    }
    template <typename T>
    void AttrListOfNumbers::bind(std::function<const T()>bind_func) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrListOfNumbers.set with no implementation. Reset value.")
    }
    template <typename T>
    void AttrListOfNumbers::bind(const std::weak_ptr<T> &bind_ptr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrListOfNumbers.set with no implementation. Reset value.")
    }
    template <typename T>
    AttrListOfNumbers &AttrListOfNumbers::operator[](std::function<const T()>bind_func) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrListOfNumbers.set with no implementation. Reset value.")
    }
    template <typename T>
    AttrListOfNumbers &AttrListOfNumbers::operator[](const std::weak_ptr<T> &bind_ptr) {
        _setter(STR_NULL);
        _LZ_WARNING("Calling AttrListOfNumbers.set with no implementation. Reset value.")
    }

    const std::string AttrListOfNumbers::_from_con_val_vec_int() {
        return vec_int_to_string(_con_val_vec_int);
    }
    const std::string AttrListOfNumbers::_from_bind_func_vec_int() {
        return vec_int_to_string(_bind_func_vec_int());
    }
    const std::string AttrListOfNumbers::_from_bind_ptr_vec_int() {
        if (auto sp = _bind_ptr_vec_int.lock()) return vec_int_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrListOfNumbers::vec_int_to_string(const std::vector<int> &attr) {
        return _vec_int_to_str(attr);
    }
    void AttrListOfNumbers::set(const std::vector<int> &attr) {
        _con_val_vec_int = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_int, this);
        _on_assign(_last);
    }
    AttrListOfNumbers &AttrListOfNumbers::operator=(const std::vector<int> &attr) {
        _con_val_vec_int = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_int, this);
        _on_assign(_last);
    }
    void AttrListOfNumbers::bind(std::function<const std::vector<int>()> bind_func) {
        _bind_func_vec_int = bind_func;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_int, this);
        _on_bind_func();
    }
    AttrListOfNumbers &AttrListOfNumbers::operator[](std::function<const std::vector<int>()> bind_func) {
        _bind_func_vec_int = bind_func;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_int, this);
        _on_bind_func();
        return *this;
    }
    void AttrListOfNumbers::bind(const std::weak_ptr<std::vector<int>> &bind_ptr) {
        _bind_ptr_vec_int = bind_ptr;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_int, this);
        _on_bind_ptr();
    }
    AttrListOfNumbers &AttrListOfNumbers::operator[](const std::weak_ptr<std::vector<int>> &bind_ptr) {
        _bind_ptr_vec_int = bind_ptr;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_int, this);
        _on_bind_ptr();
        return *this;
    }
    const std::string AttrListOfNumbers::_vec_int_to_str(const std::vector<int> &attr) {
        std::stringstream ss;
        for(int i = 0; i < attr.size(); ++i) {
            if(i > 0) ss << " ";
            ss << attr[i];
        }
        return ss.str();
    }

    const std::string AttrListOfNumbers::_from_con_val_vec_long() {
        return vec_long_to_string(_con_val_vec_long);
    }
    const std::string AttrListOfNumbers::_from_bind_func_vec_long() {
        return vec_long_to_string(_bind_func_vec_long());
    }
    const std::string AttrListOfNumbers::_from_bind_ptr_vec_long() {
        if (auto sp = _bind_ptr_vec_long.lock()) return vec_long_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrListOfNumbers::vec_long_to_string(const std::vector<long> &attr) {
        return _vec_long_to_str(attr);
    }
    void AttrListOfNumbers::set(const std::vector<long> &attr) {
        _con_val_vec_long = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_long, this);
        _on_assign(_last);
    }
    AttrListOfNumbers &AttrListOfNumbers::operator=(const std::vector<long> &attr) {
        _con_val_vec_long = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_long, this);
        _on_assign(_last);
    }
    void AttrListOfNumbers::bind(std::function<const std::vector<long>()> bind_func) {
        _bind_func_vec_long = bind_func;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_long, this);
        _on_bind_func();
    }
    AttrListOfNumbers &AttrListOfNumbers::operator[](std::function<const std::vector<long>()> bind_func) {
        _bind_func_vec_long = bind_func;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_long, this);
        _on_bind_func();
        return *this;
    }
    void AttrListOfNumbers::bind(const std::weak_ptr<std::vector<long>> &bind_ptr) {
        _bind_ptr_vec_long = bind_ptr;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_long, this);
        _on_bind_ptr();
    }
    AttrListOfNumbers &AttrListOfNumbers::operator[](const std::weak_ptr<std::vector<long>> &bind_ptr) {
        _bind_ptr_vec_long = bind_ptr;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_long, this);
        _on_bind_ptr();
        return *this;
    }
    const std::string AttrListOfNumbers::_vec_long_to_str(const std::vector<long> &attr) {
        std::stringstream ss;
        for(long i = 0; i < attr.size(); ++i) {
            if(i > 0) ss << " ";
            ss << attr[i];
        }
        return ss.str();
    }

    const std::string AttrListOfNumbers::_from_con_val_vec_ll() {
        return vec_ll_to_string(_con_val_vec_ll);
    }
    const std::string AttrListOfNumbers::_from_bind_func_vec_ll() {
        return vec_ll_to_string(_bind_func_vec_ll());
    }
    const std::string AttrListOfNumbers::_from_bind_ptr_vec_ll() {
        if (auto sp = _bind_ptr_vec_ll.lock()) return vec_ll_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrListOfNumbers::vec_ll_to_string(const std::vector<long long int> &attr) {
        return _vec_ll_to_str(attr);
    }
    void AttrListOfNumbers::set(const std::vector<long long int> &attr) {
        _con_val_vec_ll = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_ll, this);
        _on_assign(_last);
    }
    AttrListOfNumbers &AttrListOfNumbers::operator=(const std::vector<long long int> &attr) {
        _con_val_vec_ll = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_ll, this);
        _on_assign(_last);
    }
    void AttrListOfNumbers::bind(std::function<const std::vector<long long int>()> bind_func) {
        _bind_func_vec_ll = bind_func;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_ll, this);
        _on_bind_func();
    }
    AttrListOfNumbers &AttrListOfNumbers::operator[](std::function<const std::vector<long long int>()> bind_func) {
        _bind_func_vec_ll = bind_func;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_ll, this);
        _on_bind_func();
        return *this;
    }
    void AttrListOfNumbers::bind(const std::weak_ptr<std::vector<long long int>> &bind_ptr) {
        _bind_ptr_vec_ll = bind_ptr;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_ll, this);
        _on_bind_ptr();
    }
    AttrListOfNumbers &AttrListOfNumbers::operator[](const std::weak_ptr<std::vector<long long int>> &bind_ptr) {
        _bind_ptr_vec_ll = bind_ptr;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_ll, this);
        _on_bind_ptr();
        return *this;
    }
    const std::string AttrListOfNumbers::_vec_ll_to_str(const std::vector<long long int> &attr) {
        std::stringstream ss;
        for(long long int i = 0; i < attr.size(); ++i) {
            if(i > 0) ss << " ";
            ss << attr[i];
        }
        return ss.str();
    }

    const std::string AttrListOfNumbers::_from_con_val_vec_double() {
        return vec_double_to_string(_con_val_vec_double);
    }
    const std::string AttrListOfNumbers::_from_bind_func_vec_double() {
        return vec_double_to_string(_bind_func_vec_double());
    }
    const std::string AttrListOfNumbers::_from_bind_ptr_vec_double() {
        if (auto sp = _bind_ptr_vec_double.lock()) return vec_double_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrListOfNumbers::vec_double_to_string(const std::vector<double> &attr) {
        return _vec_double_to_str(attr);
    }
    void AttrListOfNumbers::set(const std::vector<double> &attr) {
        _con_val_vec_double = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_double, this);
        _on_assign(_last);
    }
    AttrListOfNumbers &AttrListOfNumbers::operator=(const std::vector<double> &attr) {
        _con_val_vec_double = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_double, this);
        _on_assign(_last);
    }
    void AttrListOfNumbers::bind(std::function<const std::vector<double>()> bind_func) {
        _bind_func_vec_double = bind_func;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_double, this);
        _on_bind_func();
    }
    AttrListOfNumbers &AttrListOfNumbers::operator[](std::function<const std::vector<double>()> bind_func) {
        _bind_func_vec_double = bind_func;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_double, this);
        _on_bind_func();
        return *this;
    }
    void AttrListOfNumbers::bind(const std::weak_ptr<std::vector<double>> &bind_ptr) {
        _bind_ptr_vec_double = bind_ptr;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_double, this);
        _on_bind_ptr();
    }
    AttrListOfNumbers &AttrListOfNumbers::operator[](const std::weak_ptr<std::vector<double>> &bind_ptr) {
        _bind_ptr_vec_double = bind_ptr;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_double, this);
        _on_bind_ptr();
        return *this;
    }
    const std::string AttrListOfNumbers::_vec_double_to_str(const std::vector<double> &attr) {
        std::stringstream ss;
        for(double i = 0; i < attr.size(); ++i) {
            if(i > 0) ss << " ";
            ss << attr[i];
        }
        return ss.str();
    }

    const std::string AttrListOfNumbers::_from_con_val_vec_float() {
        return vec_float_to_string(_con_val_vec_float);
    }
    const std::string AttrListOfNumbers::_from_bind_func_vec_float() {
        return vec_float_to_string(_bind_func_vec_float());
    }
    const std::string AttrListOfNumbers::_from_bind_ptr_vec_float() {
        if (auto sp = _bind_ptr_vec_float.lock()) return vec_float_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrListOfNumbers::vec_float_to_string(const std::vector<float> &attr) {
        return _vec_float_to_str(attr);
    }
    void AttrListOfNumbers::set(const std::vector<float> &attr) {
        _con_val_vec_float = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_float, this);
        _on_assign(_last);
    }
    AttrListOfNumbers &AttrListOfNumbers::operator=(const std::vector<float> &attr) {
        _con_val_vec_float = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_float, this);
        _on_assign(_last);
    }
    void AttrListOfNumbers::bind(std::function<const std::vector<float>()> bind_func) {
        _bind_func_vec_float = bind_func;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_float, this);
        _on_bind_func();
    }
    AttrListOfNumbers &AttrListOfNumbers::operator[](std::function<const std::vector<float>()> bind_func) {
        _bind_func_vec_float = bind_func;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_float, this);
        _on_bind_func();
        return *this;
    }
    void AttrListOfNumbers::bind(const std::weak_ptr<std::vector<float>> &bind_ptr) {
        _bind_ptr_vec_float = bind_ptr;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_float, this);
        _on_bind_ptr();
    }
    AttrListOfNumbers &AttrListOfNumbers::operator[](const std::weak_ptr<std::vector<float>> &bind_ptr) {
        _bind_ptr_vec_float = bind_ptr;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_float, this);
        _on_bind_ptr();
        return *this;
    }
    const std::string AttrListOfNumbers::_vec_float_to_str(const std::vector<float> &attr) {
        std::stringstream ss;
        for(float i = 0; i < attr.size(); ++i) {
            if(i > 0) ss << " ";
            ss << attr[i];
        }
        return ss.str();
    }

    const std::string AttrListOfNumbers::_from_con_val_vec_ld() {
        return vec_ld_to_string(_con_val_vec_ld);
    }
    const std::string AttrListOfNumbers::_from_bind_func_vec_ld() {
        return vec_ld_to_string(_bind_func_vec_ld());
    }
    const std::string AttrListOfNumbers::_from_bind_ptr_vec_ld() {
        if (auto sp = _bind_ptr_vec_ld.lock()) return vec_ld_to_string(*sp);
        else return STR_NULL;
    }
    std::string AttrListOfNumbers::vec_ld_to_string(const std::vector<long double> &attr) {
        return _vec_ld_to_str(attr);
    }
    void AttrListOfNumbers::set(const std::vector<long double> &attr) {
        _con_val_vec_ld = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_ld, this);
        _on_assign(_last);
    }
    AttrListOfNumbers &AttrListOfNumbers::operator=(const std::vector<long double> &attr) {
        _con_val_vec_ld = attr;
        auto _last = get_commit();
        _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_ld, this);
        _on_assign(_last);
    }
    void AttrListOfNumbers::bind(std::function<const std::vector<long double>()> bind_func) {
        _bind_func_vec_ld = bind_func;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_ld, this);
        _on_bind_func();
    }
    AttrListOfNumbers &AttrListOfNumbers::operator[](std::function<const std::vector<long double>()> bind_func) {
        _bind_func_vec_ld = bind_func;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_ld, this);
        _on_bind_func();
        return *this;
    }
    void AttrListOfNumbers::bind(const std::weak_ptr<std::vector<long double>> &bind_ptr) {
        _bind_ptr_vec_ld = bind_ptr;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_ld, this);
        _on_bind_ptr();
    }
    AttrListOfNumbers &AttrListOfNumbers::operator[](const std::weak_ptr<std::vector<long double>> &bind_ptr) {
        _bind_ptr_vec_ld = bind_ptr;
        _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_ld, this);
        _on_bind_ptr();
        return *this;
    }
    const std::string AttrListOfNumbers::_vec_ld_to_str(const std::vector<long double> &attr) {
        std::stringstream ss;
        for(long double i = 0; i < attr.size(); ++i) {
            if(i > 0) ss << " ";
            ss << attr[i];
        }
        return ss.str();
    }
    void AttrListOfNumbers::callback_assign(std::function<void(const std::string &)> on_assign) { _on_assign = on_assign; }
    void AttrListOfNumbers::callback_assign() { _on_assign = [](const std::string &last){}; }
    void AttrListOfNumbers::callback_bind_func(std::function<void()> on_bind_func) { _on_bind_func = on_bind_func; }
    void AttrListOfNumbers::callback_bind_func() { _on_bind_func = [](){}; }
    void AttrListOfNumbers::callback_bind_ptr(std::function<void()> on_bind_ptr) { _on_bind_ptr = on_bind_ptr; }
    void AttrListOfNumbers::callback_bind_ptr() { _on_bind_ptr = [](){}; }
}
#endif
