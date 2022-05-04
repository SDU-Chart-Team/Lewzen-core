#ifndef __LZ_SVG_RECT__
#define __LZ_SVG_RECT__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The <rect> element is a basic SVG shape that draws rectangles, defined by their position, width, and height. The rectangles may have their corners rounded.
    */
    class SVGRect: public virtual SVGElement {
    public:
        /**
        * Constructor of rect.
        */
        SVGRect();

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

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
        virtual const std::string get_x() const;
        /**
        * The x coordinate of the rect. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the x
        */
        virtual void set_x(const std::string &x);
        /**
        * The y coordinate of the rect. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the y
        */
        virtual const std::string get_y() const;
        /**
        * The y coordinate of the rect. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the y
        */
        virtual void set_y(const std::string &y);
        /**
        * The width of the rect. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @return the width
        */
        virtual const std::string get_width() const;
        /**
        * The width of the rect. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @param  the width
        */
        virtual void set_width(const std::string &width);
        /**
        * The height of the rect. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @return the height
        */
        virtual const std::string get_height() const;
        /**
        * The height of the rect. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @param  the height
        */
        virtual void set_height(const std::string &height);
        /**
        * The horizontal corner radius of the rect. Defaults to ry if it is specified. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @return the rx
        */
        virtual const std::string get_rx() const;
        /**
        * The horizontal corner radius of the rect. Defaults to ry if it is specified. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @param  the rx
        */
        virtual void set_rx(const std::string &rx);
        /**
        * The vertical corner radius of the rect. Defaults to rx if it is specified. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @return the ry
        */
        virtual const std::string get_ry() const;
        /**
        * The vertical corner radius of the rect. Defaults to rx if it is specified. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @param  the ry
        */
        virtual void set_ry(const std::string &ry);
        /**
        * The total length of the rectangle's perimeter, in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        *
        * @return the pathLength
        */
        virtual const std::string get_path_length() const;
        /**
        * The total length of the rectangle's perimeter, in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        *
        * @param  the pathLength
        */
        virtual void set_path_length(const std::string &path_length);

        /// Attributes
    protected:
        /**
        * Get attribute string of this SVG element.
        *
        * @return outer SVG.
        */
        virtual const std::string get_attributes() const override;
        /**
        * Returning differences on attributes.
        *
        * @return DOM Commands.
        */
        const std::string attribute_differ(const SVGRect &element) const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGRect
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGRect
        */
        std::shared_ptr<SVGRect> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGRect
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGRect
        */
        virtual SVGRect &operator=(const SVGRect &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif