#ifndef __LZ_ATTR__
#define __LZ_ATTR__
#include <string>
#include <memory>
#include <iostream>
#include "../utils.h"

namespace Lewzen {
    /**
    * An attribute for SVG. (Unimplemented)
    */
    class Attribute {
    private:
        std::function<const std::string()> _commit;
        std::function<const std::string()> _getter;
        std::function<void(const std::string &)> _setter;
        std::function<void(const std::string &)> _on_assign = [](const std::string &last){};
        std::function<void()> _on_bind_func = [](){};
        std::function<void()> _on_bind_ptr = [](){};
    public:
        /**
        * Empty constructor of Attribute.
        */
        Attribute()  {}
        /**
        * Constructor of Attribute, with binding with getter and setter.
        *
        * @param getter getter function
        * @param setter setter function
        */
        Attribute(std::function<const std::string()> getter, std::function<void(const std::string &)> setter): _getter(getter), _setter(setter) {}

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
        const std::string get_commit()  const {
            if (!_commit) return STR_NULL;
            return _commit();
        }

        /**
        * Set attribute from value, conver to string and call setter. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr attribute.
        */
        template <typename T>
        void set(const T &attr) { _LZ_WARNING("Calling Attribute.set, but no implementation.") }
        /**
        * Set attribute from value, conver to string and call setter.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr attribute.
        */
        template <typename T>
        Attribute &operator=(const T &attr) { _LZ_WARNING("Calling Attribute.operator=, but no implementation.") return *this; }

        /**
        * Bind attribute to a function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        template <typename T>
        void bind(std::function<const T> bind_func) { _LZ_WARNING("Calling Attribute.bind, but no implementation.") }
        /**
        * Bind attribute to a function. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        template <typename T>
        void bind(const std::weak_ptr<T> &bind_ptr) { _LZ_WARNING("Calling Attribute.bind, but no implementation.") }
        /**
        * Bind attribute to a function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        template <typename T>
        Attribute &operator[](std::function<const T> bind_func) {
            bind(bind_func);
            return *this;
        }
        /**
        * Bind attribute to a function. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        template <typename T>
        Attribute &operator[](const std::weak_ptr<T> &bind_ptr){
            bind(bind_ptr);
            return *this;
    }

        /**
        * Commit binding or value by setter.
        */
        void commit() {
            if (!_setter || !_commit) return;
            _setter(_commit());
        }

    /// Callback
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

#include "attr/attr_color.hpp"
#include "attr/attr_coordinate.hpp"
#include "attr/attr_anything.hpp"
#include "attr/attr_integer.hpp"
#include "attr/attr_list-of-numbers.hpp"
#include "attr/attr_URL.hpp"
#include "attr/attr_transform-list.hpp"
#include "attr/attr_percentage.hpp"
#include "attr/attr_length.hpp"
#include "attr/attr_IRI.hpp"
#include "attr/attr_paint.hpp"
#include "attr/attr_name.hpp"
#include "attr/attr_angle.hpp"
#include "attr/attr_opacity-value.hpp"
#include "attr/attr_number.hpp"
#include "attr/attr_FuncIRI.hpp"
#include "attr/attr_constant.hpp"
#include "attr/attr_tuple.hpp"
#include "attr/attr_enumerate.hpp"
#endif
