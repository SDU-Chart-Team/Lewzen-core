#ifndef __LZ_ATTR_LIST_OF_NUMBERS__
#define __LZ_ATTR_LIST_OF_NUMBERS__
#include <functional>
#include <string>
#include <memory>
#include <iostream>
#include <sstream>
#include <vector>
#include "../../utils.h"

namespace Lewzen {
    /**
    * A list consists of a separated sequence of values. Unless explicitly described differently, lists within SVG's XML attributes can be either comma-separated (with optional white space before or after the comma), or white space-separated.
    */
    class AttrListOfNumbers {
    private:
        std::function<const std::string()> _commit;
        std::function<const std::string()> _getter;
        std::function<void(const std::string &)> _setter;
    public:
        /**
        * Empty constructor of ListOfNumbers.
        */
        AttrListOfNumbers() {}
        /**
        * Constructor of ListOfNumbers, with binding with getter and setter.
        *
        * @param getter getter function
        * @param setter setter function
        */
        AttrListOfNumbers(std::function<const std::string()> getter, std::function<void(const std::string &)> setter): _getter(getter), _setter(setter) {}

        /**
        * Set getter of ListOfNumbers this attribute.
        * @param getter getter function
        */
        void set_getter(std::function<const std::string()> getter) {
            _getter = getter;
        }
        /**
        * Set setter of ListOfNumbers this attribute.
        *
        * @param setter setter function
        */
        void set_setter(std::function<void(const std::string &)> setter) {
            _setter = setter;
        }

        /**
        * Return attribute string, from getter.
        *
        * @return attribute string.
        */
        const std::string get() const {
            if (!_getter) return STR_NULL;
            return _getter();
        }
        /**
        * Return attribute string to be committed.
        *
        * @return attribute string.
        */
        const std::string get_commit() const {
            if (!_commit) return STR_NULL;
            return _commit();   
        }
        /**
        * Commit binding or value by setter.
        */
        void commit() {
            if (!_setter || !_commit) return;
            _setter(_commit());
        }

    public:
        /**
        * Set attribute from value, conver to string. This will break value binding with bind_func and bind_ptr. (This function will reset commit)
        *
        * @param attr attribute.
        */
        template <typename T>
        void set(const T &attr) {
            _setter(STR_NULL);
            _LZ_WARNING("Calling AttrListOfNumbers.set with no implementation. Reset value.")
        }
        /**
        * Set attribute from value, conver to string.  This will break value binding with bind_func and bind_ptr. (This function will reset commit)
        *
        * @param attr attribute.
        */
        template <typename T>
        AttrListOfNumbers &operator=(const T &attr) {
            _setter(STR_NULL);
            _LZ_WARNING("Calling AttrListOfNumbers.set with no implementation. Reset value.")
            return *this;
        }

        /**
        * Bind attribute to a function. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_func binding function.
        */
        template <typename T>
        void bind(std::function<const T()>bind_func) {
            _setter(STR_NULL);
            _LZ_WARNING("Calling AttrListOfNumbers.bind with no implementation. Reset value.")
        }
        /**
        * Bind attribute to a function. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_func binding function.
        */
        template <typename T>
        AttrListOfNumbers &operator[](std::function<const T()>bind_func) {
            _setter(STR_NULL);
            _LZ_WARNING("Calling AttrListOfNumbers.bind with no implementation. Reset value.")
            return *this;
        }
        /**
        * Bind attribute to a pointer. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_ptr binding pointer.
        */
        template <typename T>
        void bind(const std::weak_ptr<T> &bind_ptr) {
            _setter(STR_NULL);
            _LZ_WARNING("Calling AttrListOfNumbers.bind with no implementation. Reset value.")
        }
        /**
        * Bind attribute to a pointer. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_ptr binding pointer.
        */
        template <typename T>
        AttrListOfNumbers &operator[](const std::weak_ptr<T> &bind_ptr) {
            _setter(STR_NULL);
            _LZ_WARNING("Calling AttrListOfNumbers.bind with no implementation. Reset value.")
            return *this;
        }

    private:
        std::vector<int> _con_val_vec_int;
        const std::string _from_con_val_vec_int() {
            return vec_int_to_string(_con_val_vec_int);
        }
        std::function<const std::vector<int>()> _bind_func_vec_int;
        const std::string _from_bind_func_vec_int() {
            return vec_int_to_string(_bind_func_vec_int());
        }
        std::weak_ptr<std::vector<int>> _bind_ptr_vec_int;
        const std::string _from_bind_ptr_vec_int() {
            if (auto sp = _bind_ptr_vec_int.lock()) return vec_int_to_string(*sp);
            else return STR_NULL;
        }
        /**
        * Convert vec_int to string of AttrListOfNumbers.
        */
        static std::string vec_int_to_string(const std::vector<int> &attr) {
            return _vec_int_to_str(attr);
        }
    public:
        /**
        * Set attribute from vec_int, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr vec_int attribute.
        */
        void set(const std::vector<int> &attr) {
            _con_val_vec_int = attr;
            auto _last = get_commit();
            _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_int, this);
            _on_assign(_last);
        }
        /**
        * Set attribute from vec_int, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr vec_int attribute.
        */
        AttrListOfNumbers &operator=(const std::vector<int> &attr) {
            _con_val_vec_int = attr;
            auto _last = get_commit();
            _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_int, this);
            _on_assign(_last);
            return *this;
        }
        /**
        * Bind attribute to a vec_int function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(std::function<const std::vector<int>()> bind_func) {
            _bind_func_vec_int = bind_func;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_int, this);
            _on_bind_func();
        }
        /**
        * Bind attribute to a vec_int function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        AttrListOfNumbers &operator[](std::function<const std::vector<int>()> bind_func) {
            _bind_func_vec_int = bind_func;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_int, this);
            _on_bind_func();
            return *this;
        }
        /**
        * Bind attribute to a vec_int pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<std::vector<int>> &bind_ptr) {
            _bind_ptr_vec_int = bind_ptr;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_int, this);
            _on_bind_ptr();
        }
        /**
        * Bind attribute to a vec_int pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        AttrListOfNumbers &operator[](const std::weak_ptr<std::vector<int>> &bind_ptr) {
            _bind_ptr_vec_int = bind_ptr;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_int, this);
            _on_bind_ptr();
            return *this;
        }
        /**
        * Convert vector of integer to string.
        */
        static const std::string _vec_int_to_str(const std::vector<int> &attr) {
        std::stringstream ss;
        for(int i = 0; i < attr.size(); ++i) {
            if(i > 0) ss << " ";
            ss << attr[i];
        }
        return ss.str();
        }

    private:
        std::vector<long> _con_val_vec_long;
        const std::string _from_con_val_vec_long() {
            return vec_long_to_string(_con_val_vec_long);
        }
        std::function<const std::vector<long>()> _bind_func_vec_long;
        const std::string _from_bind_func_vec_long() {
            return vec_long_to_string(_bind_func_vec_long());
        }
        std::weak_ptr<std::vector<long>> _bind_ptr_vec_long;
        const std::string _from_bind_ptr_vec_long() {
            if (auto sp = _bind_ptr_vec_long.lock()) return vec_long_to_string(*sp);
            else return STR_NULL;
        }
        /**
        * Convert vec_long to string of AttrListOfNumbers.
        */
        static std::string vec_long_to_string(const std::vector<long> &attr) {
            return _vec_long_to_str(attr);
        }
    public:
        /**
        * Set attribute from vec_long, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr vec_long attribute.
        */
        void set(const std::vector<long> &attr) {
            _con_val_vec_long = attr;
            auto _last = get_commit();
            _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_long, this);
            _on_assign(_last);
        }
        /**
        * Set attribute from vec_long, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr vec_long attribute.
        */
        AttrListOfNumbers &operator=(const std::vector<long> &attr) {
            _con_val_vec_long = attr;
            auto _last = get_commit();
            _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_long, this);
            _on_assign(_last);
            return *this;
        }
        /**
        * Bind attribute to a vec_long function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(std::function<const std::vector<long>()> bind_func) {
            _bind_func_vec_long = bind_func;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_long, this);
            _on_bind_func();
        }
        /**
        * Bind attribute to a vec_long function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        AttrListOfNumbers &operator[](std::function<const std::vector<long>()> bind_func) {
            _bind_func_vec_long = bind_func;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_long, this);
            _on_bind_func();
            return *this;
        }
        /**
        * Bind attribute to a vec_long pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<std::vector<long>> &bind_ptr) {
            _bind_ptr_vec_long = bind_ptr;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_long, this);
            _on_bind_ptr();
        }
        /**
        * Bind attribute to a vec_long pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        AttrListOfNumbers &operator[](const std::weak_ptr<std::vector<long>> &bind_ptr) {
            _bind_ptr_vec_long = bind_ptr;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_long, this);
            _on_bind_ptr();
            return *this;
        }
        /**
        * Convert vector of loong to string.
        */
        static const std::string _vec_long_to_str(const std::vector<long> &attr) {
        std::stringstream ss;
        for(long i = 0; i < attr.size(); ++i) {
            if(i > 0) ss << " ";
            ss << attr[i];
        }
        return ss.str();
        }

    private:
        std::vector<long long int> _con_val_vec_ll;
        const std::string _from_con_val_vec_ll() {
            return vec_ll_to_string(_con_val_vec_ll);
        }
        std::function<const std::vector<long long int>()> _bind_func_vec_ll;
        const std::string _from_bind_func_vec_ll() {
            return vec_ll_to_string(_bind_func_vec_ll());
        }
        std::weak_ptr<std::vector<long long int>> _bind_ptr_vec_ll;
        const std::string _from_bind_ptr_vec_ll() {
            if (auto sp = _bind_ptr_vec_ll.lock()) return vec_ll_to_string(*sp);
            else return STR_NULL;
        }
        /**
        * Convert vec_ll to string of AttrListOfNumbers.
        */
        static std::string vec_ll_to_string(const std::vector<long long int> &attr) {
            return _vec_ll_to_str(attr);
        }
    public:
        /**
        * Set attribute from vec_ll, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr vec_ll attribute.
        */
        void set(const std::vector<long long int> &attr) {
            _con_val_vec_ll = attr;
            auto _last = get_commit();
            _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_ll, this);
            _on_assign(_last);
        }
        /**
        * Set attribute from vec_ll, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr vec_ll attribute.
        */
        AttrListOfNumbers &operator=(const std::vector<long long int> &attr) {
            _con_val_vec_ll = attr;
            auto _last = get_commit();
            _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_ll, this);
            _on_assign(_last);
            return *this;
        }
        /**
        * Bind attribute to a vec_ll function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(std::function<const std::vector<long long int>()> bind_func) {
            _bind_func_vec_ll = bind_func;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_ll, this);
            _on_bind_func();
        }
        /**
        * Bind attribute to a vec_ll function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        AttrListOfNumbers &operator[](std::function<const std::vector<long long int>()> bind_func) {
            _bind_func_vec_ll = bind_func;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_ll, this);
            _on_bind_func();
            return *this;
        }
        /**
        * Bind attribute to a vec_ll pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<std::vector<long long int>> &bind_ptr) {
            _bind_ptr_vec_ll = bind_ptr;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_ll, this);
            _on_bind_ptr();
        }
        /**
        * Bind attribute to a vec_ll pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        AttrListOfNumbers &operator[](const std::weak_ptr<std::vector<long long int>> &bind_ptr) {
            _bind_ptr_vec_ll = bind_ptr;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_ll, this);
            _on_bind_ptr();
            return *this;
        }
        /**
        * Convert vector of long long integer to string.
        */
        static const std::string _vec_ll_to_str(const std::vector<long long int> &attr) {
        std::stringstream ss;
        for(long long int i = 0; i < attr.size(); ++i) {
            if(i > 0) ss << " ";
            ss << attr[i];
        }
        return ss.str();
        }

    private:
        std::vector<double> _con_val_vec_double;
        const std::string _from_con_val_vec_double() {
            return vec_double_to_string(_con_val_vec_double);
        }
        std::function<const std::vector<double>()> _bind_func_vec_double;
        const std::string _from_bind_func_vec_double() {
            return vec_double_to_string(_bind_func_vec_double());
        }
        std::weak_ptr<std::vector<double>> _bind_ptr_vec_double;
        const std::string _from_bind_ptr_vec_double() {
            if (auto sp = _bind_ptr_vec_double.lock()) return vec_double_to_string(*sp);
            else return STR_NULL;
        }
        /**
        * Convert vec_double to string of AttrListOfNumbers.
        */
        static std::string vec_double_to_string(const std::vector<double> &attr) {
            return _vec_double_to_str(attr);
        }
    public:
        /**
        * Set attribute from vec_double, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr vec_double attribute.
        */
        void set(const std::vector<double> &attr) {
            _con_val_vec_double = attr;
            auto _last = get_commit();
            _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_double, this);
            _on_assign(_last);
        }
        /**
        * Set attribute from vec_double, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr vec_double attribute.
        */
        AttrListOfNumbers &operator=(const std::vector<double> &attr) {
            _con_val_vec_double = attr;
            auto _last = get_commit();
            _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_double, this);
            _on_assign(_last);
            return *this;
        }
        /**
        * Bind attribute to a vec_double function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(std::function<const std::vector<double>()> bind_func) {
            _bind_func_vec_double = bind_func;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_double, this);
            _on_bind_func();
        }
        /**
        * Bind attribute to a vec_double function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        AttrListOfNumbers &operator[](std::function<const std::vector<double>()> bind_func) {
            _bind_func_vec_double = bind_func;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_double, this);
            _on_bind_func();
            return *this;
        }
        /**
        * Bind attribute to a vec_double pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<std::vector<double>> &bind_ptr) {
            _bind_ptr_vec_double = bind_ptr;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_double, this);
            _on_bind_ptr();
        }
        /**
        * Bind attribute to a vec_double pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        AttrListOfNumbers &operator[](const std::weak_ptr<std::vector<double>> &bind_ptr) {
            _bind_ptr_vec_double = bind_ptr;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_double, this);
            _on_bind_ptr();
            return *this;
        }
        /**
        * Convert vector of double to string.
        */
        static const std::string _vec_double_to_str(const std::vector<double> &attr) {
        std::stringstream ss;
        for(double i = 0; i < attr.size(); ++i) {
            if(i > 0) ss << " ";
            ss << attr[i];
        }
        return ss.str();
        }

    private:
        std::vector<float> _con_val_vec_float;
        const std::string _from_con_val_vec_float() {
            return vec_float_to_string(_con_val_vec_float);
        }
        std::function<const std::vector<float>()> _bind_func_vec_float;
        const std::string _from_bind_func_vec_float() {
            return vec_float_to_string(_bind_func_vec_float());
        }
        std::weak_ptr<std::vector<float>> _bind_ptr_vec_float;
        const std::string _from_bind_ptr_vec_float() {
            if (auto sp = _bind_ptr_vec_float.lock()) return vec_float_to_string(*sp);
            else return STR_NULL;
        }
        /**
        * Convert vec_float to string of AttrListOfNumbers.
        */
        static std::string vec_float_to_string(const std::vector<float> &attr) {
            return _vec_float_to_str(attr);
        }
    public:
        /**
        * Set attribute from vec_float, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr vec_float attribute.
        */
        void set(const std::vector<float> &attr) {
            _con_val_vec_float = attr;
            auto _last = get_commit();
            _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_float, this);
            _on_assign(_last);
        }
        /**
        * Set attribute from vec_float, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr vec_float attribute.
        */
        AttrListOfNumbers &operator=(const std::vector<float> &attr) {
            _con_val_vec_float = attr;
            auto _last = get_commit();
            _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_float, this);
            _on_assign(_last);
            return *this;
        }
        /**
        * Bind attribute to a vec_float function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(std::function<const std::vector<float>()> bind_func) {
            _bind_func_vec_float = bind_func;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_float, this);
            _on_bind_func();
        }
        /**
        * Bind attribute to a vec_float function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        AttrListOfNumbers &operator[](std::function<const std::vector<float>()> bind_func) {
            _bind_func_vec_float = bind_func;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_float, this);
            _on_bind_func();
            return *this;
        }
        /**
        * Bind attribute to a vec_float pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<std::vector<float>> &bind_ptr) {
            _bind_ptr_vec_float = bind_ptr;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_float, this);
            _on_bind_ptr();
        }
        /**
        * Bind attribute to a vec_float pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        AttrListOfNumbers &operator[](const std::weak_ptr<std::vector<float>> &bind_ptr) {
            _bind_ptr_vec_float = bind_ptr;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_float, this);
            _on_bind_ptr();
            return *this;
        }
        /**
        * Convert vector of float to string.
        */
        static const std::string _vec_float_to_str(const std::vector<float> &attr) {
        std::stringstream ss;
        for(float i = 0; i < attr.size(); ++i) {
            if(i > 0) ss << " ";
            ss << attr[i];
        }
        return ss.str();
        }

    private:
        std::vector<long double> _con_val_vec_ld;
        const std::string _from_con_val_vec_ld() {
            return vec_ld_to_string(_con_val_vec_ld);
        }
        std::function<const std::vector<long double>()> _bind_func_vec_ld;
        const std::string _from_bind_func_vec_ld() {
            return vec_ld_to_string(_bind_func_vec_ld());
        }
        std::weak_ptr<std::vector<long double>> _bind_ptr_vec_ld;
        const std::string _from_bind_ptr_vec_ld() {
            if (auto sp = _bind_ptr_vec_ld.lock()) return vec_ld_to_string(*sp);
            else return STR_NULL;
        }
        /**
        * Convert vec_ld to string of AttrListOfNumbers.
        */
        static std::string vec_ld_to_string(const std::vector<long double> &attr) {
            return _vec_ld_to_str(attr);
        }
    public:
        /**
        * Set attribute from vec_ld, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr vec_ld attribute.
        */
        void set(const std::vector<long double> &attr) {
            _con_val_vec_ld = attr;
            auto _last = get_commit();
            _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_ld, this);
            _on_assign(_last);
        }
        /**
        * Set attribute from vec_ld, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr vec_ld attribute.
        */
        AttrListOfNumbers &operator=(const std::vector<long double> &attr) {
            _con_val_vec_ld = attr;
            auto _last = get_commit();
            _commit = std::bind(&AttrListOfNumbers::_from_con_val_vec_ld, this);
            _on_assign(_last);
            return *this;
        }
        /**
        * Bind attribute to a vec_ld function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(std::function<const std::vector<long double>()> bind_func) {
            _bind_func_vec_ld = bind_func;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_ld, this);
            _on_bind_func();
        }
        /**
        * Bind attribute to a vec_ld function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        AttrListOfNumbers &operator[](std::function<const std::vector<long double>()> bind_func) {
            _bind_func_vec_ld = bind_func;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_func_vec_ld, this);
            _on_bind_func();
            return *this;
        }
        /**
        * Bind attribute to a vec_ld pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<std::vector<long double>> &bind_ptr) {
            _bind_ptr_vec_ld = bind_ptr;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_ld, this);
            _on_bind_ptr();
        }
        /**
        * Bind attribute to a vec_ld pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        AttrListOfNumbers &operator[](const std::weak_ptr<std::vector<long double>> &bind_ptr) {
            _bind_ptr_vec_ld = bind_ptr;
            _commit = std::bind(&AttrListOfNumbers::_from_bind_ptr_vec_ld, this);
            _on_bind_ptr();
            return *this;
        }
        /**
        * Convert vector of long double to string.
        */
        static const std::string _vec_ld_to_str(const std::vector<long double> &attr) {
        std::stringstream ss;
        for(long double i = 0; i < attr.size(); ++i) {
            if(i > 0) ss << " ";
            ss << attr[i];
        }
        return ss.str();
        }

    /// Callback
    private:
        std::function<void(const std::string &)> _on_assign = [](const std::string &last){};
        std::function<void()> _on_bind_func = [](){};
        std::function<void()> _on_bind_ptr = [](){};
    public:
        /**
        * Set callback for assignment operation.
        *
        * @param on_assign callback function.
        */
        void callback_assign(std::function<void(const std::string &)> on_assign) { _on_assign = on_assign; }
        /**
        * Remove callback for assignment operation.
        */
        void callback_assign() { _on_assign = [](const std::string &last){}; }
        /**
        * Set callback for binding function operation.
        *
        * @param on_bind_func callback function.
        */
        void callback_bind_func(std::function<void()> on_bind_func) { _on_bind_func = on_bind_func; }
        /**
        * Remove callback for binding function operation.
        */
        void callback_bind_func() { _on_bind_func = [](){}; }
        /**
        * Set callback for binding pointer operation.
        *
        * @param on_bind_ptr callback function.
        */
        void callback_bind_ptr(std::function<void()> on_bind_ptr) { _on_bind_ptr = on_bind_ptr; }
        /**
        * Remove callback for binding pointer operation.
        */
        void callback_bind_ptr() { _on_bind_ptr = [](){}; }
    };
}
#endif
