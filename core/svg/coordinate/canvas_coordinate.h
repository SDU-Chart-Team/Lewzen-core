#include <string>
#include "../coordinate.h"
#include "../point.h"
#ifndef __LZ_CANVAS_COORDINATE__
#define __LZ_CANVAS_COORDINATE__

namespace Lewzen {
    /**
    * Canvas coordinate information.
    */
    class CanvasCoordinate: public Coordinate {
    public:
        /**
        * Constructor of Canvas Coordinate.
        */
        CanvasCoordinate();
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