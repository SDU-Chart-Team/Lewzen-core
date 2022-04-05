#include <string>
#include <memory>
#include "../coordinate.h"
#include "../point.h"
#ifndef __LZ_POINT_RELATIVE_COORDINATE__
#define __LZ_POINT_RELATIVE_COORDINATE__

namespace Lewzen {
    /**
    * Point relative coordinate information.
    */
    class PointRelativeCoordinate: public Coordinate {
    private:
        // origin
        std::shared_ptr<Point2D> _origin;
        // vertex
        std::shared_ptr<Point2D> _vertex;
    public:
        /**
        * Constructor of Point Relative Coordinate.
        *
        * @param origin the origin of point relative coordinate.
        * @param vertex the (1, 1) of point relative coordinate.
        */
        PointRelativeCoordinate(const std::shared_ptr<Point2D> &origin, const std::shared_ptr<Point2D> &vertex);
        /**
        * Get origin of Point Relative Coordinate.
        *
        * @return the origin of point relative coordinate.
        */
        const std::shared_ptr<Point2D> &get_origin() const;
        /**
        * Get vertex of Point Relative Coordinate.
        *
        * @return the vertex of point relative coordinate.
        */
        const std::shared_ptr<Point2D> &get_vertex() const;
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