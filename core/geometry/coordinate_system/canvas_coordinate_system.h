#ifndef __LZ_CANVAS_COORDINATE__
#define __LZ_CANVAS_COORDINATE__
#include <string>
#include "../coordinate_system.h"

namespace Lewzen {
    /**
    * Canvas coordinate system information.
    */
    class CanvasCoordinateSystem: public CoordinateSystem {
    public:
        /**
        * Static pointer of CanvasCoordinateSystem.
        */
        static std::shared_ptr<CanvasCoordinateSystem> canvas_coordinate_system;
        /**
        * Constructor of CanvasCoordinateSystem.
        */
        CanvasCoordinateSystem();
        /**
        * Deep copy of this coordinate system.
        */
        CanvasCoordinateSystem(const CanvasCoordinateSystem &coordinate_system);
        /**
        * Deep copy of this coordinate system.
        *
        * @relatesalso CoordinateSystem
        */
        std::shared_ptr<CoordinateSystem> clone() const override;
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