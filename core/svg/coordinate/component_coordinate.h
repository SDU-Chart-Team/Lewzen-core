#include <string>
#include <memory>
#include "../coordinate.h"
#include "../../component.h"
#ifndef __LZ_COMPONENT_COORDINATE__
#define __LZ_COMPONENT_COORDINATE__

namespace Lewzen {
    /**
    * Component coordinate information.
    */
    class ComponentCoordinate: public Coordinate {
    private:
        // component
        std::shared_ptr<Component> _component;
    public:
        /**
        * Constructor of Component Coordinate. Unit is equal to Canvas Coordinate.
        *
        * @param component the component of component coordinate.
        */
        ComponentCoordinate(const std::shared_ptr<Component> &component);
        /**
        * Get component of Component Coordinate.
        *
        * @return the component of component coordinate.
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
        * Get point in corresponding relative coordinate.
        *
        * @return point in corresponding relative coordinate.
        */
        Point2D to_relative(const Point2D &p) const;
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