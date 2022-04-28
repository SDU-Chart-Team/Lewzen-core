#ifndef __LZ_VECTOR_RELATIVE_COORDINATE__
#define __LZ_VECTOR_RELATIVE_COORDINATE__
#include <string>
#include <memory>
#include "../coordinate_system.h"

namespace Lewzen {
    /**
    * Vector relative coordinate system information.
    */
    class VectorRelativeCoordinateSystem: public CoordinateSystem {
    private:
        // origin
        std::weak_ptr<Point2D> _A;
        // vertex
        std::weak_ptr<Point2D> _B;
    public:
        /**
        * Constructor of VectorRelativeCoordinateSystem.
        *
        * @param A the origin of vector relative coordinate system.
        * @param B vector AB means x-axis of point relative coordinate system, and B means (1, 0) in this coordinate system.
        */
        VectorRelativeCoordinateSystem(const std::weak_ptr<Point2D> &A, const std::weak_ptr<Point2D> &B);
        /**
        * Deep copy of this coordinate system.
        */
        VectorRelativeCoordinateSystem(const VectorRelativeCoordinateSystem &coordinate_system);
        /**
        * Get origin of VectorRelativeCoordinateSystem.
        *
        * @return the origin of vector relative coordinate system.
        */
        const std::weak_ptr<Point2D> get_A() const;
        /**
        * Get unit (1, 0) of VectorRelativeCoordinateSystem.
        *
        * @return the unit (1, 0) of vector relative coordinate system.
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
        * Get point in corresponding absolute coordinate system.
        *
        * @return point in corresponding absolute coordinate system.
        */
        Point2D to_absolute(const Point2D &p) const;
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