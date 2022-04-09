#include <string>
#include <memory>
#include "../coordinate.h"
#include "../../component.h"
#ifndef __LZ_COMPONENT_RELATIVE_COORDINATE__
#define __LZ_COMPONENT_RELATIVE_COORDINATE__

namespace Lewzen {
    /**
    * Component relative coordinate information.
    */
    class ComponentRelativeCoordinate: public Coordinate {
    private:
        // component
        std::shared_ptr<Component> _component;
    public:
        /**
        * Constructor of Component Relative Coordinate. Top-left and bottom-right of component's box is (-1, -1) to (1, 1).
        *
        * @param component the component of component relative coordinate.
        */
        ComponentRelativeCoordinate(const std::shared_ptr<Component> &component);
        /**
        * Get component of Component Relative Coordinate.
        *
        * @return the component of component relative coordinate.
        */
        const std::shared_ptr<Component> &get_component() const;
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        bool operator== (const Coordinate &coordianate) const;
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        bool operator!= (const Coordinate &coordianate) const;
        /**
        * Get point in corresponding absolute coordinate.
        *
        * @return point in corresponding absolute coordinate.
        */
        Point2D to_absolute(const Point2D &p) const;
        /**
        * Convert a point in Canvas Coordinate to this coordinate.
        *
        * @param p a point in Canvas Coordinate.
        * @return a point in this coordinate.
        */
        Point2D from_canvas(const Point2D &p) const;
        /**
        * Convert a point in this coordinate to Canvas Coordinate.
        *
        * @param p a point in this coordinate.
        * @return a point in Canvas Coordinate.
        */
        Point2D to_canvas(const Point2D &p) const;
    };
}