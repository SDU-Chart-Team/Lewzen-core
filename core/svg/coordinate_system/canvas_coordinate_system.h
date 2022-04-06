#include <string>
#include "../coordinate_system.h"
#include "../point.h"
#ifndef __LZ_CANVAS_COORDINATE__
#define __LZ_CANVAS_COORDINATE__

namespace Lewzen {
    /**
    * Canvas coordinate system information.
    */
    class CanvasCoordinateSystem: public CoordinateSystem {
    public:
        /**
        * Constructor of CanvasCoordinateSystem.
        */
        CanvasCoordinateSystem();
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