#ifndef __LZ_ATTR_COLOR__
#define __LZ_ATTR_COLOR__
#include <functional>
#include <string>
#include <memory>
#include <iostream>
#include "../../utils.h"

namespace Lewzen {
    /**
    * A <transform-list> is used to specify a list of coordinate system transformations. A detailed description of the possible values for a <transform-list> is given in the transform attribute definition.
    * Within the SVG DOM, a <transform-list> value is represented using an SVGTransformList or SVGAnimatedTransformList object.The basic type <color> is a CSS2 compatible specification for a color in the sRGB color space. <color> applies to SVG\'s use of the color attribute and is a component of the definitions of attributes fill, stroke, stop-color, flood-color, and lighting-color, which also offer optional ICC-based color specifications.
    * SVG supports all of the syntax alternatives for <color> defined in CSS2 syntax and basic data types, and (depend on the implementation) in the future CSS Color Module Level 3.
    * A <color> is either a keyword or a numerical RGB specification.
    * In addition to these color keywords, users may specify keywords that correspond to the colors used by objects in the user\'s environment. The normative definition of these keywords is found in User preferences for colors (CSS2, section 18.2).
    * The format of an RGB value in hexadecimal notation is a "#" immediately followed by either three or six hexadecimal characters. The three-digit RGB notation (#rgb) is converted into six-digit form (#rrggbb) by replicating digits, not by adding zeros. For example, #fb0 expands to #ffbb00. This ensures that white (#ffffff) can be specified with the short notation (#fff) and removes any dependencies on the color depth of the display. The format of an RGB value in the functional notation is an RGB start-function, followed by a comma-separated list of three numerical values (either three integer values or three percentage values) followed by ")". An RGB start-function is the case-insensitive string "rgb(", for example "RGB(" or "rGb(". For compatibility, the all-lowercase form "rgb(" is preferred. The integer value 255 corresponds to 100%, and to F or FF in the hexadecimal notation: rgb(255,255,255) = rgb(100%,100%,100%) = #FFF. White space characters are allowed around the numerical values. All RGB colors are specified in the sRGB color space. Using sRGB provides an unambiguous and objectively measurable definition of the color, which can be related to international standards.
    * ```
    * color    ::= "#" hexdigit hexdigit hexdigit (hexdigit hexdigit hexdigit)?
    *               | "rgb("integer, integer, integer")"
    *               | "rgb("integer "%", integer "%", integer "%)"
    *               | color-keyword
    * hexdigit ::= [0-9A-Fa-f]
    * ```
    * where color-keyword matches (case insensitively) one of the color keywords listed in CSS Color Module Level 3, or one of the system color keywords listed in User preferences for colors (CSS2, section 18.2).
    * The corresponding SVG DOM interface definitions for <color> are defined the one defined by CSS. SVG\'s extension to color, including the ability to specify ICC-based colors, are represented using DOM interface SVGColor.
    */
    class AttrColor {
    private:
        std::function<const std::string()> _commit;
        std::function<const std::string()> _getter;
        std::function<void(const std::string &)> _setter;
    public:
        /**
        * Empty constructor of Color.
        */
        AttrColor() {}
        /**
        * Constructor of Color, with binding with getter and setter.
        *
        * @param getter getter function
        * @param setter setter function
        */
        AttrColor(std::function<const std::string()> getter, std::function<void(const std::string &)> setter): _getter(getter), _setter(setter) {}

        /**
        * Set getter of Color this attribute.
        * @param getter getter function
        */
        void set_getter(std::function<const std::string()> getter) {
            _getter = getter;
        }
        /**
        * Set setter of Color this attribute.
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
            _LZ_WARNING("Calling AttrColor.set with no implementation. Reset value.")
        }
        /**
        * Set attribute from value, conver to string.  This will break value binding with bind_func and bind_ptr. (This function will reset commit)
        *
        * @param attr attribute.
        */
        template <typename T>
        AttrColor &operator=(const T &attr) {
            _setter(STR_NULL);
            _LZ_WARNING("Calling AttrColor.set with no implementation. Reset value.")
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
            _LZ_WARNING("Calling AttrColor.bind with no implementation. Reset value.")
        }
        /**
        * Bind attribute to a function. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_func binding function.
        */
        template <typename T>
        AttrColor &operator[](std::function<const T()>bind_func) {
            _setter(STR_NULL);
            _LZ_WARNING("Calling AttrColor.bind with no implementation. Reset value.")
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
            _LZ_WARNING("Calling AttrColor.bind with no implementation. Reset value.")
        }
        /**
        * Bind attribute to a pointer. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_ptr binding pointer.
        */
        template <typename T>
        AttrColor &operator[](const std::weak_ptr<T> &bind_ptr) {
            _setter(STR_NULL);
            _LZ_WARNING("Calling AttrColor.bind with no implementation. Reset value.")
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
        * Convert string to string of AttrColor.
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
            _commit = std::bind(&AttrColor::_from_con_val_string, this);
            _on_assign(_last);
        }
        /**
        * Set attribute from string, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr string attribute.
        */
        AttrColor &operator=(const std::string &attr) {
            _con_val_string = attr;
            auto _last = get_commit();
            _commit = std::bind(&AttrColor::_from_con_val_string, this);
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
        AttrColor &operator=(const char * attr) {
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
            _commit = std::bind(&AttrColor::_from_bind_func_string, this);
            _on_bind_func();
        }
        /**
        * Bind attribute to a string function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        AttrColor &operator[](std::function<const std::string()> bind_func) {
            _bind_func_string = bind_func;
            _commit = std::bind(&AttrColor::_from_bind_func_string, this);
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
            _commit = std::bind(&AttrColor::_from_bind_ptr_string, this);
            _on_bind_ptr();
        }
        /**
        * Bind attribute to a string pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        AttrColor &operator[](const std::weak_ptr<std::string> &bind_ptr) {
            _bind_ptr_string = bind_ptr;
            _commit = std::bind(&AttrColor::_from_bind_ptr_string, this);
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
