#ifndef __LZ_SVG_RECT__
#define __LZ_SVG_RECT__
#include <string>
#include <sstream>
#include "../svg_element.h"

namespace Lewzen {
    /**
    * The <rect> element is a basic SVG shape that draws rectangles, defined by their position, width, and height. The rectangles may have their corners rounded.
    */
    class SVGRect: public SVGElement {
    public:
        /**
        * Constructor of rect.
        */
        SVGRect();
        /**
        * Deep copy of rect.
        */
        SVGRect(const SVGRect &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// Rect
    private:
        std::string _x;
    private:
        std::string _y;
    private:
        std::string _width;
    private:
        std::string _height;
    private:
        std::string _rx;
    private:
        std::string _ry;
    private:
        std::string _path_length;
    public:
        /**
        * The x coordinate of the rect. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the x
        */
        const std::string get_x() const;
        /**
        * The x coordinate of the rect. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the x
        */
        void set_x(const std::string &x);
        /**
        * The y coordinate of the rect. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the y
        */
        const std::string get_y() const;
        /**
        * The y coordinate of the rect. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the y
        */
        void set_y(const std::string &y);
        /**
        * The width of the rect. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @return the width
        */
        const std::string get_width() const;
        /**
        * The width of the rect. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @param  the width
        */
        void set_width(const std::string &width);
        /**
        * The height of the rect. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @return the height
        */
        const std::string get_height() const;
        /**
        * The height of the rect. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @param  the height
        */
        void set_height(const std::string &height);
        /**
        * The horizontal corner radius of the rect. Defaults to ry if it is specified. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @return the rx
        */
        const std::string get_rx() const;
        /**
        * The horizontal corner radius of the rect. Defaults to ry if it is specified. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @param  the rx
        */
        void set_rx(const std::string &rx);
        /**
        * The vertical corner radius of the rect. Defaults to rx if it is specified. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @return the ry
        */
        const std::string get_ry() const;
        /**
        * The vertical corner radius of the rect. Defaults to rx if it is specified. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @param  the ry
        */
        void set_ry(const std::string &ry);
        /**
        * The total length of the rectangle's perimeter, in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        *
        * @return the pathLength
        */
        const std::string get_path_length() const;
        /**
        * The total length of the rectangle's perimeter, in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        *
        * @param  the pathLength
        */
        void set_path_length(const std::string &path_length);

        /// Attributes
    protected:
        /**
        * Get attribute string of this SVG element.
        *
        * @return outer SVG.
        */
        const std::string get_attributes() const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGElement
        */
        std::shared_ptr<SVGElement> clone() const;
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        const std::string operator-(const SVGElement &element) const;
    };
}
#endif