#ifndef __LZ_ATTR_TYPE__
#define __LZ_ATTR_TYPE__
#include <string>
#include <memory>
#include <iostream>
#include "../../utils.h"

namespace Lewzen {
    /**
    * An attribute for SVG. (Unimplemented)
    */
    class Number {
    private:
        const std::string (*_commit)();
        const std::string (*_getter)();
        void (*_setter)(const std::string &);
    public:
        /**
        * Empty constructor of Number.
        */
        Number();
        /**
        * Constructor of Number, with binding with getter and setter.
        *
        * @param getter getter function
        * @param setter setter function
        */
        Number(const std::string (*getter)(), void (*setter)(const std::string &));

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
        const std::string get_commit() const;
        /**
        * Commit binding or value by setter.
        */
        void commit();

    public:
        /**
        * Set attribute from value, conver to string and call setter. This will break value binding with bind_func and bind_ptr. (This function will reset commit)
        *
        * @param attr attribute.
        */
        template <typename T>
        void set(const T &attr);
        /**
        * Set attribute from value, conver to string and call setter.  This will break value binding with bind_func and bind_ptr. (This function will reset commit)
        *
        * @param attr attribute.
        */
        template <typename T>
        Number &operator=(const T &attr);

        /**
        * Bind attribute to a function. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_func binding function.
        */
        template <typename T>
        void bind(const T (*bind_func)());
        /**
        * Bind attribute to a function. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_func binding function.
        */
        template <typename T>
        Number &operator[](const T (*bind_func));
        /**
        * Bind attribute to a function. This will break value binding with bind_func. (This function will reset commit)
        *
        * @param bind_ptr binding pointer.
        */
        template <typename T>
        void bind(const std::weak_ptr<T> &bind_ptr);
        /**
        * Bind attribute to a function. This will break value binding with bind_func. (This function will reset commit)
        *
        * @param bind_ptr binding pointer.
        */
        template <typename T>
        Number &operator[](const std::weak_ptr<T> &bind_ptr);

    private:
        int _con_val_int;
        const std::string _from_con_val_int();
        const int (*_bind_func_int)();
        const std::string _from_bind_func_int();
        std::weak_ptr<int> _bind_ptr_int;
        const std::string _from_bind_ptr_int();
        /**
        * Convert integer to string of Number.
        */
        static std::string integer_to_string(const int &attr);
    public:
        /**
        * Set attribute from integer, conver to string and call setter. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr integer attribute.
        */
        void set(const int &attr);
        /**
        * Set attribute from integer, conver to string and call setter.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr integer attribute.
        */
        Number &operator=(const int &attr);
        /**
        * Bind attribute to a integer function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(const int (*bind_func)());
        /**
        * Bind attribute to a integer function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        Number &operator[](const int (*bind_func)());
        /**
        * Bind attribute to a integer function. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<int> &bind_ptr);
        /**
        * Bind attribute to a integer function. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        Number &operator[](const std::weak_ptr<int> &bind_ptr);
    };
}
#endif