#ifndef __LZ_ATTR__FUNC_IRI__
#define __LZ_ATTR__FUNC_IRI__
#include <functional>
#include <string>
#include <memory>
#include <iostream>
#include "../../utils.h"

namespace Lewzen {
    /**
    * Functional notation for a reference. The syntax for this reference is the same as the css uri.
    */
    class AttrFuncIRI {
    private:
        std::function<const std::string()> _commit;
        std::function<const std::string()> _getter;
        std::function<void(const std::string &)> _setter;
    public:
        /**
        * Empty constructor of FuncIRI.
        */
        AttrFuncIRI() {}
        /**
        * Constructor of FuncIRI, with binding with getter and setter.
        *
        * @param getter getter function
        * @param setter setter function
        */
        AttrFuncIRI(std::function<const std::string()> getter, std::function<void(const std::string &)> setter): _getter(getter), _setter(setter) {}

        /**
        * Set getter of FuncIRI this attribute.
        * @param getter getter function
        */
        void set_getter(std::function<const std::string()> getter) {
            _getter = getter;
        }
        /**
        * Set setter of FuncIRI this attribute.
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
            _LZ_WARNING("Calling AttrFuncIRI.set with no implementation. Reset value.")
        }
        /**
        * Set attribute from value, conver to string.  This will break value binding with bind_func and bind_ptr. (This function will reset commit)
        *
        * @param attr attribute.
        */
        template <typename T>
        AttrFuncIRI &operator=(const T &attr) {
            _setter(STR_NULL);
            _LZ_WARNING("Calling AttrFuncIRI.set with no implementation. Reset value.")
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
            _LZ_WARNING("Calling AttrFuncIRI.bind with no implementation. Reset value.")
        }
        /**
        * Bind attribute to a function. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_func binding function.
        */
        template <typename T>
        AttrFuncIRI &operator[](std::function<const T()>bind_func) {
            _setter(STR_NULL);
            _LZ_WARNING("Calling AttrFuncIRI.bind with no implementation. Reset value.")
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
            _LZ_WARNING("Calling AttrFuncIRI.bind with no implementation. Reset value.")
        }
        /**
        * Bind attribute to a pointer. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_ptr binding pointer.
        */
        template <typename T>
        AttrFuncIRI &operator[](const std::weak_ptr<T> &bind_ptr) {
            _setter(STR_NULL);
            _LZ_WARNING("Calling AttrFuncIRI.bind with no implementation. Reset value.")
            return *this;
        }

    private:
        std::string _con_val_string;
        const std::string _from_con_val_string() {
            return string_to_string(_con_val_string);
        }
        std::function<const std::string()> _bind_func_string;
        const std::string _from_bind_func_string() {
            return string_to_string(_bind_func_string());
        }
        std::weak_ptr<std::string> _bind_ptr_string;
        const std::string _from_bind_ptr_string() {
            if (auto sp = _bind_ptr_string.lock()) return string_to_string(*sp);
            else return STR_NULL;
        }
        /**
        * Convert string to string of AttrFuncIRI.
        */
        static std::string string_to_string(const std::string &attr) {
            return attr;
        }
    public:
        /**
        * Set attribute from string, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr string attribute.
        */
        void set(const std::string &attr) {
            _con_val_string = attr;
            auto _last = get_commit();
            _commit = std::bind(&AttrFuncIRI::_from_con_val_string, this);
            _on_assign(_last);
        }
        /**
        * Set attribute from string, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr string attribute.
        */
        AttrFuncIRI &operator=(const std::string &attr) {
            _con_val_string = attr;
            auto _last = get_commit();
            _commit = std::bind(&AttrFuncIRI::_from_con_val_string, this);
            _on_assign(_last);
            return *this;
        }
        /**
        * Set attribute from string, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr string attribute.
        */
        void set(const char * attr) {
            set(std::string(attr));
        }
        /**
        * Set attribute from string, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr string attribute.
        */
        AttrFuncIRI &operator=(const char * attr) {
            operator=(std::string(attr));
            return *this;
        }
        /**
        * Bind attribute to a string function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(std::function<const std::string()> bind_func) {
            _bind_func_string = bind_func;
            _commit = std::bind(&AttrFuncIRI::_from_bind_func_string, this);
            _on_bind_func();
        }
        /**
        * Bind attribute to a string function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        AttrFuncIRI &operator[](std::function<const std::string()> bind_func) {
            _bind_func_string = bind_func;
            _commit = std::bind(&AttrFuncIRI::_from_bind_func_string, this);
            _on_bind_func();
            return *this;
        }
        /**
        * Bind attribute to a string pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<std::string> &bind_ptr) {
            _bind_ptr_string = bind_ptr;
            _commit = std::bind(&AttrFuncIRI::_from_bind_ptr_string, this);
            _on_bind_ptr();
        }
        /**
        * Bind attribute to a string pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        AttrFuncIRI &operator[](const std::weak_ptr<std::string> &bind_ptr) {
            _bind_ptr_string = bind_ptr;
            _commit = std::bind(&AttrFuncIRI::_from_bind_ptr_string, this);
            _on_bind_ptr();
            return *this;
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
