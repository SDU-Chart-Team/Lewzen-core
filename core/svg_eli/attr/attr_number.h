#ifndef __LZ_ATTR_NUMBER__
#define __LZ_ATTR_NUMBER__
#include <string>
#include <memory>
#include <iostream>
#include <regex>
#include "../../utils.h"

namespace Lewzen {
    /**
    * Real numbers are specified in one of two ways. When used in a stylesheet, a <number> is defined as follows: 
    * ```number ::= integer
    *     | [+-]? [0-9]* "." [0-9]+```
    * When used in an SVG attribute, a <number> is defined differently, to allow numbers with large magnitudes to be specified more concisely:
    * ```number ::= integer ([Ee] integer)?
    *     | [+-]? [0-9]* "." [0-9]+ ([Ee] integer)?```
    * Within the SVG DOM, a <number> is represented as a float, SVGNumber or a SVGAnimatedNumber.
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
        int _con_val_integer;
        const std::string _from_con_val_integer();
        const int (*_bind_func_integer)();
        const std::string _from_bind_func_integer();
        std::weak_ptr<int> _bind_ptr_integer;
        const std::string _from_bind_ptr_integer();
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
        * Bind attribute to a integer pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<int> &bind_ptr);
        /**
        * Bind attribute to a integer pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        Number &operator[](const std::weak_ptr<int> &bind_ptr);

    private:
        float _con_val_float;
        const std::string _from_con_val_float();
        const float (*_bind_func_float)();
        const std::string _from_bind_func_float();
        std::weak_ptr<float> _bind_ptr_float;
        const std::string _from_bind_ptr_float();
        /**
        * Convert float to string of Number.
        */
        static std::string float_to_string(const float &attr);
    public:
        /**
        * Set attribute from float, conver to string and call setter. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr float attribute.
        */
        void set(const float &attr);
        /**
        * Set attribute from float, conver to string and call setter.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr float attribute.
        */
        Number &operator=(const float &attr);
        /**
        * Bind attribute to a float function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(const float (*bind_func)());
        /**
        * Bind attribute to a float function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        Number &operator[](const float (*bind_func)());
        /**
        * Bind attribute to a float pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<float> &bind_ptr);
        /**
        * Bind attribute to a float pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        Number &operator[](const std::weak_ptr<float> &bind_ptr);

    private:
        double _con_val_double;
        const std::string _from_con_val_double();
        const double (*_bind_func_double)();
        const std::string _from_bind_func_double();
        std::weak_ptr<double> _bind_ptr_double;
        const std::string _from_bind_ptr_double();
        /**
        * Convert double to string of Number.
        */
        static std::string double_to_string(const double &attr);
    public:
        /**
        * Set attribute from double, conver to string and call setter. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr double attribute.
        */
        void set(const double &attr);
        /**
        * Set attribute from double, conver to string and call setter.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr double attribute.
        */
        Number &operator=(const double &attr);
        /**
        * Bind attribute to a double function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(const double (*bind_func)());
        /**
        * Bind attribute to a double function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        Number &operator[](const double (*bind_func)());
        /**
        * Bind attribute to a double pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<double> &bind_ptr);
        /**
        * Bind attribute to a double pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        Number &operator[](const std::weak_ptr<double> &bind_ptr);

    private:
        long long int _con_val_long_integer;
        const std::string _from_con_val_long_integer();
        const long long int (*_bind_func_long_integer)();
        const std::string _from_bind_func_long_integer();
        std::weak_ptr<long long int> _bind_ptr_long_integer;
        const std::string _from_bind_ptr_long_integer();
        /**
        * Convert long integer to string of Number.
        */
        static std::string long_integer_to_string(const long long int &attr);
    public:
        /**
        * Set attribute from long integer, conver to string and call setter. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr long integer attribute.
        */
        void set(const long long int &attr);
        /**
        * Set attribute from long integer, conver to string and call setter.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr long integer attribute.
        */
        Number &operator=(const long long int &attr);
        /**
        * Bind attribute to a long integer function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(const long long int (*bind_func)());
        /**
        * Bind attribute to a long integer function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        Number &operator[](const long long int (*bind_func)());
        /**
        * Bind attribute to a long integer pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<long long int> &bind_ptr);
        /**
        * Bind attribute to a long integer pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        Number &operator[](const std::weak_ptr<long long int> &bind_ptr);

    private:
        long double _con_val_long_double;
        const std::string _from_con_val_long_double();
        const long double (*_bind_func_long_double)();
        const std::string _from_bind_func_long_double();
        std::weak_ptr<long double> _bind_ptr_long_double;
        const std::string _from_bind_ptr_long_double();
        /**
        * Convert long double to string of Number.
        */
        static std::string long_double_to_string(const long double &attr);
    public:
        /**
        * Set attribute from long double, conver to string and call setter. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr long double attribute.
        */
        void set(const long double &attr);
        /**
        * Set attribute from long double, conver to string and call setter.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr long double attribute.
        */
        Number &operator=(const long double &attr);
        /**
        * Bind attribute to a long double function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(const long double (*bind_func)());
        /**
        * Bind attribute to a long double function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        Number &operator[](const long double (*bind_func)());
        /**
        * Bind attribute to a long double pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<long double> &bind_ptr);
        /**
        * Bind attribute to a long double pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        Number &operator[](const std::weak_ptr<long double> &bind_ptr);

    private:
        std::string _con_val_legal_string;
        const std::string _from_con_val_legal_string();
        const std::string (*_bind_func_legal_string)();
        const std::string _from_bind_func_legal_string();
        std::weak_ptr<std::string> _bind_ptr_legal_string;
        const std::string _from_bind_ptr_legal_string();
        /**
        * Convert legal string to string of Number.
        */
        static std::string legal_string_to_string(const std::string &attr);
    public:
        /**
        * Set attribute from legal string, conver to string and call setter. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr legal string attribute.
        */
        void set(const std::string &attr);
        /**
        * Set attribute from legal string, conver to string and call setter.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr legal string attribute.
        */
        Number &operator=(const std::string &attr);
        /**
        * Bind attribute to a legal string function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(const std::string (*bind_func)());
        /**
        * Bind attribute to a legal string function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        Number &operator[](const std::string (*bind_func)());
        /**
        * Bind attribute to a legal string pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<std::string> &bind_ptr);
        /**
        * Bind attribute to a legal string pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        Number &operator[](const std::weak_ptr<std::string> &bind_ptr);
        /**
        * Check if a string is legal as a Number attribute.
        */
        static bool is_legal_string(const std::string &attr);
    };
}
#endif
