#ifndef __LZ_SVG_POLYLINE__
#define __LZ_SVG_POLYLINE__
#include <string>
#include <sstream>
#include "../svg_element.h"

namespace Lewzen {
    /**
    * The <polyline> SVG element is an SVG basic shape that creates straight lines connecting several points. Typically a polyline is used to create open shapes as the last point doesn't have to be connected to the first point. For closed shapes see the <polygon> element.
    */
    class SVGPolyline: public SVGElement {
    public:
        /**
        * Constructor of polyline.
        */
        SVGPolyline();
        /**
        * Deep copy of polyline.
        */
        SVGPolyline(const SVGPolyline &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// Polyline
    private:
        std::string _points;
    private:
        double _path_length;
    public:
        /**
        * Get defines the list of points (pairs of x,y absolute coordinates) required to draw the polygon.
        *
        * @return defines the list of points (pairs of x,y absolute coordinates) required to draw the polygon.
        */
        const std::string get_points() const;
        /**
        * Set defines the list of points (pairs of x,y absolute coordinates) required to draw the polygon.
        *
        * @param points defines the list of points (pairs of x,y absolute coordinates) required to draw the polygon.
        */
        void set_points(const std::string &points);
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