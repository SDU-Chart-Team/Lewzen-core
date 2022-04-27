#ifndef __LZ_POINT_COORDINATE__
#define __LZ_POINT_COORDINATE__
#include <string>
#include <memory>
#include "../coordinate_system.h"

namespace Lewzen {
    /**
    * Point coordinate system information.
    */
    class PointCoordinateSystem: public CoordinateSystem {
    private:
        // origin
        std::weak_ptr<Point2D> _origin;
        // vertex
        std::weak_ptr<Point2D> _vertex;
        std::shared_ptr<Point2D> _vertex_default;
    public:
        /**
        * Constructor of PointCoordinateSystem. Unit is equal to CanvasCoordinateSystem.
        *
        * @param origin the origin of point coordinate system. 
        */
        PointCoordinateSystem(const std::weak_ptr<Point2D> &origin);
        /**
        * Constructor of PointCoordinateSystem. Unit is equal to CanvasCoordinateSystem.
        *
        * @param origin the origin of point coordinate system. 
        * @param vertex the (1, 1) of point relative coordinate system. default: (origin.x + 1, origin.y + 1).
        */
        PointCoordinateSystem(const std::weak_ptr<Point2D> &origin, const std::weak_ptr<Point2D> &vertex);
        /**
        * Deep copy of this coordinate system.
        */
        PointCoordinateSystem(const PointCoordinateSystem &coordinate_system);
        /**
        * Get origin of PointCoordinateSystem.
        *
        * @return the origin of point coordinate system.
        */
        const std::weak_ptr<Point2D> get_origin() const;
        /**
        * Get vertex of PointCoordinateSystem.
        *
        * @return the vertex of point coordinate system. for relative coordinate system.
        */
        const std::weak_ptr<Point2D> get_vertex() const;
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