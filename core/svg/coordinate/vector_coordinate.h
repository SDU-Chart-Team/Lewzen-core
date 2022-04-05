#include <string>
#include <memory>
#include "../coordinate.h"
#include "../point.h"
#ifndef __LZ_VECTOR_COORDINATE__
#define __LZ_VECTOR_COORDINATE__

namespace Lewzen {
    /**
    * Vector coordinate information.
    */
    class VectorCoordinate: public Coordinate {
    private:
        // origin
        std::shared_ptr<Point2D> _A;
        // vertex
        std::shared_ptr<Point2D> _B;
    public:
        /**
        * Constructor of Vector Coordinate. Unit is equal to Canvas Coordinate.
        *
        * @param A the origin of vector coordinate.
        * @param B vector AB means x-axis of point coordinate, .
        */
        VectorCoordinate(const std::shared_ptr<Point2D> &A, const std::shared_ptr<Point2D> &B);
        /**
        * Get Aof Vector Coordinate.
        *
        * @return A point of vector coordinate.
        */
        const std::shared_ptr<Point2D> &get_A() const;
        /**
        * Get B of Vector Coordinate.
        *
        * @return B point of vector coordinate.
        */
        const std::shared_ptr<Point2D> &get_B() const;
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