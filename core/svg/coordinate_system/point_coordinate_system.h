#include <string>
#include <memory>
#include "../coordinate_system.h"
#include "../point.h"
#ifndef __LZ_POINT_COORDINATE__
#define __LZ_POINT_COORDINATE__

namespace Lewzen {
    /**
    * Point coordinate system information.
    */
    class PointCoordinateSystem: public CoordinateSystem {
    private:
        // origin
        std::shared_ptr<Point2D> _origin;
    public:
        /**
        * Constructor of PointCoordinateSystem. Unit is equal to CanvasCoordinateSystem.
        *
        * @param origin the origin of point coordinate system. 
        */
        PointCoordinateSystem(const std::shared_ptr<Point2D> &origin);
        /**
        * Constructor of PointCoordinateSystem. Unit is equal to CanvasCoordinateSystem.
        *
        * @param origin the origin of point coordinate system. 
        * @param vertex the (1, 1) of point relative coordinate system. default: (origin.x + 1, origin.y + 1).
        */
        PointCoordinateSystem(const std::shared_ptr<Point2D> &origin, const std::shared_ptr<Point2D> &vertex);
        /**
        * Get origin of PointCoordinateSystem.
        *
        * @return the origin of point coordinate system.
        */
        const std::shared_ptr<Point2D> &get_origin() const;
        /**
        * Compare two coordinate systems.
        *
        * @relatesalso CoordinateSystem
        */
        bool operator== (const CoordinateSystem &coordianate_system) const override;
        /**
        * Compare two coordinate systems.
        *
        * @relatesalso CoordinateSystem
        */
        bool operator!= (const CoordinateSystem &coordianate_system) const override;
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
        */
        Point2D from_canvas(const Point2D &p) const override;
        /**
        * Convert a point in this coordinate system to CanvasCoordinateSystem.
        *
        * @param p a point in this coordinate system.
        * @return a point in CanvasCoordinateSystem.
        */
        Point2D to_canvas(const Point2D &p) const override;
    };
}