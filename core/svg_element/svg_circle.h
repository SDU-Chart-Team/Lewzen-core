#ifndef __LZ_SVG_CIRCLE__
#define __LZ_SVG_CIRCLE__
#include <string>
#include <sstream>
#include "../svg_element.h"

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
        double _cx;
    private:
        double _cy;
    private:
        double _r;
    private:
        double _path_length;
    public:
        /**
        * Get x of the center of the circle.
        *
        * @return x of the center of the circle.
        */
        double get_cx() const;
        /**
        * Set x of the center of the circle.
        *
        * @param cx x of the center of the circle.
        */
        void set_cx(const double &cx);
        /**
        * Get y of the center of the circle.
        *
        * @return y of the center of the circle.
        */
        double get_cy() const;
        /**
        * Set y of the center of the circle.
        *
        * @param cy y of the center of the circle.
        */
        void set_cy(const double &cy);
        /**
        * Get the radius of the circle.
        *
        * @return the radius of the circle.
        */
        double get_r() const;
        /**
        * Set the radius of the circle.
        *
        * @param r the radius of the circle.
        */
        void set_r(const double &r);
        /**
        * Get the total length for the circle's circumference, in user units.
        *
        * @return the total length for the circle's circumference, in user units.
        */
        double get_path_length() const;
        /**
        * Set the total length for the circle's circumference, in user units.
        *
        * @param path_length the total length for the circle's circumference, in user units.
        */
        void set_path_length(const double &path_length);

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