#ifndef __LZ_VECTOR_COORDINATE__
#define __LZ_VECTOR_COORDINATE__
#include <string>
#include <memory>
#include "../coordinate_system.h"

namespace Lewzen {
    /**
    * Vector coordinate system information.
    */
    class VectorCoordinateSystem: public CoordinateSystem {
    private:
        // origin
        std::weak_ptr<Point2D> _A;
        // vertex
        std::weak_ptr<Point2D> _B;
    public:
        /**
        * Constructor of VectorCoordinateSystem. Unit is equal to CanvasCoordinateSystem.
        *
        * @param A the origin of vector coordinate system.
        * @param B vector AB means x-axis of point coordinate system, .
        */
        VectorCoordinateSystem(const std::weak_ptr<Point2D> &A, const std::weak_ptr<Point2D> &B);
        /**
        * Deep copy of this coordinate system.
        */
        VectorCoordinateSystem(const VectorCoordinateSystem &coordinate_system);
        /**
        * Get Aof VectorCoordinateSystem.
        *
        * @return A point of vector coordinate system.
        */
        const std::weak_ptr<Point2D> get_A() const;
        /**
        * Get B of VectorCoordinateSystem.
        *
        * @return B point of vector coordinate system.
        */
        const std::weak_ptr<Point2D> get_B() const;
        /**
        * Deep copy of this coordinate system.
        *
        * @relatesalso CoordinateSystem
        */
        std::shared_ptr<CoordinateSystem> clone() const;
        /**
        * Compare two coordinate systems.
        *
        * @relatesalso CoordinateSystem
        */
        bool operator==(const CoordinateSystem &coordinate_system) const override;
        /**
        * Compare two coordinate systems.
        *
        * @relatesalso CoordinateSystem
        */
        bool operator!=(const CoordinateSystem &coordinate_system) const override;
        /**
        * Get point in corresponding relative coordinate system.
        *
        * @return point in corresponding relative coordinate system.
        */
        Point2D to_relative(const Point2D &p) const;
        /**
        * Convert a point in CanvasCoordinateSystem to this coordinate system.
        *
        * @param p a point in CanvasCoordinateSystem.
        * @return a point in this coordinate system.
        * @throws Lewzen::coordinate_system_mismatch: thrown if point p is not in CanvasCoordinateSystem.
        */
        Point2D from_canvas(const Point2D &p) const override;
        /**
        * Convert a point in this coordinate system to CanvasCoordinateSystem.
        *
        * @param p a point in this coordinate system.
        * @return a point in CanvasCoordinateSystem.
        * @throws Lewzen::coordinate_system_mismatch: thrown if point p is not in this coordinate system.
        */
        Point2D to_canvas(const Point2D &p) const override;
    };
}
#endif