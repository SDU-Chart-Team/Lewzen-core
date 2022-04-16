#ifndef __LZ_ATTR__
#define __LZ_ATTR__
#include <string>
#include <memory>
#include <iostream>
#include "../../utils.h"

namespace Lewzen {
    /**
    * An attribute for SVG. (Unimplemented)
    */
    class Attribute {
    private:
        const std::string (*_commit)();
        const std::string (*_getter)();
        void (*_setter)(const std::string &);
    public:
        /**
        * Empty constructor of Attribute.
        */
        Attribute();
        /**
        * Constructor of Attribute, with binding with getter and setter.
        *
        * @param getter getter function
        * @param setter setter function
        */
        Attribute(const std::string (*getter)(), void (*setter)(const std::string &));

        /**
        * Return attribute string, from getter.
        *
        * @return attribute string.
        */
        const std::string get() const;
        /**
        * Return attribute string to be committed.
        *
        * @return attribute string.
        */
        const std::string get_commit()  const;

        /**
        * Set attribute from value, conver to string and call setter. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr attribute.
        */
        template <typename T>
        void set(const T &attr);
        /**
        * Set attribute from value, conver to string and call setter.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr attribute.
        */
        template <typename T>
        Attribute &operator=(const T &attr);

        /**
        * Bind attribute to a function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        template <typename T>
        void bind(const T (*bind_func)());
        /**
        * Bind attribute to a function. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        template <typename T>
        void bind(const std::weak_ptr<T> &bind_ptr);
        /**
        * Bind attribute to a function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        template <typename T>
        Attribute &operator[](const T (*bind_func));
        /**
        * Bind attribute to a function. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        template <typename T>
        Attribute &operator[](const std::weak_ptr<T> &bind_ptr);

        /**
        * Commit binding or value by setter.
        */
        void commit();
    };
}
#include "attr.tpp"
#endif