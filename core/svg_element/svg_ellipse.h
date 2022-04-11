#ifndef __LZ_SVG_ELLIPSE__
#define __LZ_SVG_ELLIPSE__
#include <string>
#include <sstream>
#include "../svg_element.h"

namespace Lewzen {
    /**
    * The <ellipse> element is an SVG basic shape, used to create ellipses based on a center coordinate, and both their x and y radius.
    */
    class SVGEllipse: public SVGElement {
    public:
        /**
        * Constructor of ellipse.
        */
        SVGEllipse();
        /**
        * Deep copy of ellipse.
        */
        SVGEllipse(const SVGEllipse &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// Ellipse
    private:
        double _cx;
    private:
        double _cy;
    private:
        double _rx;
    private:
        double _ry;
    private:
        double _path_length;
    public:
        /**
        * Get x position of the ellipse.
        *
        * @return x position of the ellipse.
        */
        double get_cx() const;
        /**
        * Set x position of the ellipse.
        *
        * @param cx x position of the ellipse.
        */
        void set_cx(const double &cx);
        /**
        * Get y position of the ellipse.
        *
        * @return y position of the ellipse.
        */
        double get_cy() const;
        /**
        * Set y position of the ellipse.
        *
        * @param cy y position of the ellipse.
        */
        void set_cy(const double &cy);
        /**
        * Get the radius of the ellipse on the x axis.
        *
        * @return the radius of the ellipse on the x axis.
        */
        double get_rx() const;
        /**
        * Set the radius of the ellipse on the x axis.
        *
        * @param rx the radius of the ellipse on the x axis.
        */
        void set_rx(const double &rx);
        /**
        * Get the radius of the ellipse on the y axis.
        *
        * @return the radius of the ellipse on the y axis.
        */
        double get_ry() const;
        /**
        * Set the radius of the ellipse on the y axis.
        *
        * @param ry the radius of the ellipse on the y axis.
        */
        void set_ry(const double &ry);
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