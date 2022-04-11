#ifndef __LZ_SVG_POLYGON__
#define __LZ_SVG_POLYGON__
#include <string>
#include <sstream>
#include "../svg_element.h"

namespace Lewzen {
    /**
    * The <polygon> element defines a closed shape consisting of a set of connected straight line segments. The last point is connected to the first point.
    */
    class SVGPolygon: public SVGElement {
    public:
        /**
        * Constructor of polygon.
        */
        SVGPolygon();
        /**
        * Deep copy of polygon.
        */
        SVGPolygon(const SVGPolygon &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// Polygon
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