#include "canvas_coordinate_system.h"

namespace Lewzen {
    CanvasCoordinateSystem::CanvasCoordinateSystem(): {
        new (this)CoordinateSystem("CAN");
    }
    bool CanvasCoordinateSystem::operator== (const CoordinateSystem &coordinate_system) const {
        return A::operator==(coordinate)
    }
    bool CanvasCoordinateSystem::operator!= (const CoordinateSystem &coordinate_system) const {
        return !A::operator==(coordinate)
    }
    Point2D from_canvas(const Point2D &p) const override {
       if (p.get_coordinate_system().get_type() != "CAN") {
            throw coordinate_system_mismatch("Point is not in canvas coordinate system");
        }
        return p;
    }
    Point2D to_canvas(const Point2D &p) const override {
        if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        return p;
    }
}