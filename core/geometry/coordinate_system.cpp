#include "coordinate_system.h"

namespace Lewzen {
    CoordinateSystem::CoordinateSystem() {
        new (this)CoordinateSystem("NULL");
    }
    CoordinateSystem::CoordinateSystem(const std::string &coordinate_system_type): _coordinate_system_type(coordinate_system_type) {}
    CoordinateSystem::CoordinateSystem(const CoordinateSystem &coordinate_system) {
        new (this)CoordinateSystem(coordinate_system.get_type());
    }
    const std::string CoordinateSystem::get_type() const {
        return _coordinate_system_type;
    }
    std::shared_ptr<CoordinateSystem> CoordinateSystem::clone() const {
        return std::make_shared<CoordinateSystem>(*this);
    }
    bool CoordinateSystem::operator==(const CoordinateSystem &coordinate_system) const {
        return _coordinate_system_type == coordinate_system.get_type();
    }
    bool CoordinateSystem::operator!=(const CoordinateSystem &coordinate_system) const {
        return _coordinate_system_type != coordinate_system.get_type();
    }
    Point2D CoordinateSystem::from_canvas(const Point2D &p) const {
        if (p.get_coordinate_system().get_type() != "CAN") {
            throw coordinate_system_mismatch("Point is not in canvas coordinate system");
        }
        return Point2D(p.get_x(), p.get_y(), *this);
    }
    Point2D CoordinateSystem::to_canvas(const Point2D &p) const {
        if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        throw coordinate_system_mismatch("Cannot convert a point in null coordinate system to canvas coordinate system");
        return p;
    }

    coordinate_system_mismatch::coordinate_system_mismatch(): std::logic_error("Coordinate systems mismatch.") {}
    coordinate_system_mismatch::coordinate_system_mismatch(const std::string &str):  std::logic_error("Coordinate systems mismatch : " + str) {}
    char const* coordinate_system_mismatch::what() const noexcept {
        return std::logic_error::what();
    }
}