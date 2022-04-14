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
        std::string _path_length;
    public:
        /**
        * This attribute defines the list of points (pairs of x,y absolute coordinates) required to draw the polygon. 
        * Value type: <number>+ ; Default value: ""; Animatable: yes
        *
        * @return the points
        */
        const std::string get_points() const;
        /**
        * This attribute defines the list of points (pairs of x,y absolute coordinates) required to draw the polygon. 
        * Value type: <number>+ ; Default value: ""; Animatable: yes
        *
        * @param  the points
        */
        void set_points(const std::string &points);
        /**
        * This attribute lets specify the total length for the path, in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        *
        * @return the pathLength
        */
        const std::string get_path_length() const;
        /**
        * This attribute lets specify the total length for the path, in user units. 
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