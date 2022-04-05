#include <string>
#include <memory>
#include "../coordinate.h"
#include "../point.h"
#ifndef __LZ_POINT_COORDINATE__
#define __LZ_POINT_COORDINATE__

namespace Lewzen {
    /**
    * Point coordinate information.
    */
    class PointCoordinate: public Coordinate {
    private:
        // origin
        std::shared_ptr<Point2D> _origin;
    public:
        /**
        * Constructor of Point Coordinate. Unit is equal to Canvas Coordinate.
        *
        * @param origin the origin of point coordinate. 
        */
        PointCoordinate(const std::shared_ptr<Point2D> &origin);
        /**
        * Constructor of Point Coordinate. Unit is equal to Canvas Coordinate.
        *
        * @param origin the origin of point coordinate. 
        * @param vertex the (1, 1) of point relative coordinate. default: (origin.x + 1, origin.y + 1).
        */
        PointCoordinate(const std::shared_ptr<Point2D> &origin, const std::shared_ptr<Point2D> &vertex);
        /**
        * Get origin of Point Coordinate.
        *
        * @return the origin of point coordinate.
        */
        const std::shared_ptr<Point2D> &get_origin() const;
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