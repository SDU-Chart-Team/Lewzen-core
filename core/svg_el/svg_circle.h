#ifndef __LZ_SVG_CIRCLE__
#define __LZ_SVG_CIRCLE__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The <circle> SVG element is an SVG basic shape, used to draw circles based on a center point and a radius.
    */
    class SVGCircle: public SVGElement {
    public:
        /**
        * Constructor of circle.
        */
        SVGCircle();
        /**
        * Deep copy of circle.
        */
        SVGCircle(const SVGCircle &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// Circle
    private:
        std::string _cx;
    private:
        std::string _cy;
    private:
        std::string _r;
    private:
        std::string _path_length;
    public:
        /**
        * The x-axis coordinate of the center of the circle. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the cx
        */
        const std::string get_cx() const;
        /**
        * The x-axis coordinate of the center of the circle. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the cx
        */
        void set_cx(const std::string &cx);
        /**
        * The y-axis coordinate of the center of the circle. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the cy
        */
        const std::string get_cy() const;
        /**
        * The y-axis coordinate of the center of the circle. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the cy
        */
        void set_cy(const std::string &cy);
        /**
        * The radius of the circle. A value lower or equal to zero disables rendering of the circle. 
        * Value type: <length> ; Default value: 0; Animatable: yes
        *
        * @return the r
        */
        const std::string get_r() const;
        /**
        * The radius of the circle. A value lower or equal to zero disables rendering of the circle. 
        * Value type: <length> ; Default value: 0; Animatable: yes
        *
        * @param  the r
        */
        void set_r(const std::string &r);
        /**
        * The total length for the circle's circumference, in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        *
        * @return the pathLength
        */
        const std::string get_path_length() const;
        /**
        * The total length for the circle's circumference, in user units. 
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