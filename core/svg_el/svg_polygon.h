#ifndef __LZ_SVG_POLYGON__
#define __LZ_SVG_POLYGON__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The <polygon> element defines a closed shape consisting of a set of connected straight line segments. The last point is connected to the first point.
    */
    class SVGPolygon: public virtual SVGElement {
    public:
        /**
        * Constructor of polygon.
        */
        SVGPolygon();

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

        /// Polygon
    private:
        std::string _points;
    private:
        std::string _path_length;
    public:
        /**
        * This attribute defines the list of points (pairs of x,y absolute coordinates) required to draw the polygon. 
        * Value type: <list-of-numbers> ; Default value: ""; Animatable: yes
        *
        * @return the points
        */
        virtual const std::string get_points() const;
        /**
        * This attribute defines the list of points (pairs of x,y absolute coordinates) required to draw the polygon. 
        * Value type: <list-of-numbers> ; Default value: ""; Animatable: yes
        *
        * @param  the points
        */
        virtual void set_points(const std::string &points);
        /**
        * This attribute lets specify the total length for the path, in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        *
        * @return the pathLength
        */
        virtual const std::string get_path_length() const;
        /**
        * This attribute lets specify the total length for the path, in user units. 
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
        const std::string attribute_differ(const SVGPolygon &element) const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGPolygon
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGPolygon
        */
        std::shared_ptr<SVGPolygon> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGPolygon
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGPolygon
        */
        virtual SVGPolygon &operator=(const SVGPolygon &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif