#ifndef __LZ_SVG_CIRCLE__
#define __LZ_SVG_CIRCLE__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The <circle> SVG element is an SVG basic shape, used to draw circles based on a center point and a radius.
    */
    class SVGCircle: public virtual SVGElement {
    public:
        /**
        * Constructor of circle.
        */
        SVGCircle();

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

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
        virtual const std::string get_cx() const;
        /**
        * The x-axis coordinate of the center of the circle. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the cx
        */
        virtual void set_cx(const std::string &cx);
        /**
        * The y-axis coordinate of the center of the circle. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the cy
        */
        virtual const std::string get_cy() const;
        /**
        * The y-axis coordinate of the center of the circle. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the cy
        */
        virtual void set_cy(const std::string &cy);
        /**
        * The radius of the circle. A value lower or equal to zero disables rendering of the circle. 
        * Value type: <length> ; Default value: 0; Animatable: yes
        *
        * @return the r
        */
        virtual const std::string get_r() const;
        /**
        * The radius of the circle. A value lower or equal to zero disables rendering of the circle. 
        * Value type: <length> ; Default value: 0; Animatable: yes
        *
        * @param  the r
        */
        virtual void set_r(const std::string &r);
        /**
        * The total length for the circle's circumference, in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        *
        * @return the pathLength
        */
        virtual const std::string get_path_length() const;
        /**
        * The total length for the circle's circumference, in user units. 
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
        const std::string attribute_differ(const SVGCircle &element) const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGCircle
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGCircle
        */
        std::shared_ptr<SVGCircle> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGCircle
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGCircle
        */
        virtual SVGCircle &operator=(const SVGCircle &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif