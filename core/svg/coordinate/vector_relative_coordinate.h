#include <string>
#include <memory>
#include "../coordinate.h"
#include "../point.h"
#ifndef __LZ_VECTOR_RELATIVE_COORDINATE__
#define __LZ_VECTOR_RELATIVE_COORDINATE__

namespace Lewzen {
    /**
    * Vector relative coordinate information.
    */
    class VectorRelativeCoordinate: public Coordinate {
    private:
        // origin
        std::shared_ptr<Point2D> _A;
        // vertex
        std::shared_ptr<Point2D> _B;
    public:
        /**
        * Constructor of Vector Relative Coordinate.
        *
        * @param A the origin of vector relative coordinate.
        * @param B vector AB means x-axis of point relative coordinate, and B means (1, 0) in this coordinate.
        */
        VectorRelativeCoordinate(const std::shared_ptr<Point2D> &A, const std::shared_ptr<Point2D> &B);
        /**
        * Get origin of Vector Relative Coordinate.
        *
        * @return the origin of vector relative coordinate.
        */
        const std::shared_ptr<Point2D> &get_A() const;
        /**
        * Get unit (1, 0) of Vector Relative Coordinate.
        *
        * @return the unit (1, 0) of vector relative coordinate.
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