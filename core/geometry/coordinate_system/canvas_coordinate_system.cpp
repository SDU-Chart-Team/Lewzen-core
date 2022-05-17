#include "canvas_coordinate_system.h"

namespace Lewzen {
    std::shared_ptr<CanvasCoordinateSystem> CanvasCoordinateSystem::canvas_coordinate_system = std::make_shared<CanvasCoordinateSystem>();
    CanvasCoordinateSystem::CanvasCoordinateSystem(): CoordinateSystem("CAN") {}
    CanvasCoordinateSystem::CanvasCoordinateSystem(const CanvasCoordinateSystem &coordinate_system): CoordinateSystem(coordinate_system.get_type()) {}
    std::shared_ptr<CoordinateSystem> CanvasCoordinateSystem::clone() const {
        return std::make_shared<CanvasCoordinateSystem>(*this);
    }
    bool CanvasCoordinateSystem::operator==(const CoordinateSystem &coordinate_system) const {
        return CoordinateSystem::operator==(coordinate_system);
    }
    bool CanvasCoordinateSystem::operator!=(const CoordinateSystem &coordinate_system) const {
        return !CoordinateSystem::operator==(coordinate_system);
    }
    Point2D CanvasCoordinateSystem::from_canvas(const Point2D &p) const {
       if (p.get_coordinate_system()->get_type() != "CAN") {
            throw coordinate_system_mismatch("Point is not in canvas coordinate system");
        }
        return p;
    }
    Point2D CanvasCoordinateSystem::to_canvas(const Point2D &p) const {
        if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        return p;
    }
}