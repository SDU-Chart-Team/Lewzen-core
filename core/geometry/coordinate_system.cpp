#include "coordinate_system.h"

namespace Lewzen {
    CoordinateSystem::CoordinateSystem() { _coordinate_system_type = "NULL"; }
    CoordinateSystem::CoordinateSystem(const std::string &coordinate_system_type): _coordinate_system_type(coordinate_system_type) {}
    CoordinateSystem::CoordinateSystem(const CoordinateSystem &coordinate_system): _coordinate_system_type(coordinate_system.get_type()) {}
    const std::string CoordinateSystem::get_type() const {
        return _coordinate_system_type;
    }
    std::shared_ptr<CoordinateSystem> CoordinateSystem::clone() const {
        return std::make_shared<CoordinateSystem>(*this);
    }
    bool CoordinateSystem::operator==(const CoordinateSystem &coordinate_system) const {
        return _coordinate_system_type == coordinate_system.get_type();
    }
    bool operator==(const std::shared_ptr<CoordinateSystem> &c1, const CoordinateSystem &c2) {
        return *c1 == c2;
    }
    bool operator==(const CoordinateSystem &c1, const std::shared_ptr<CoordinateSystem> &c2) {
        return c1 == *c2;
    }
    bool operator==(const std::shared_ptr<CoordinateSystem> &c1, const std::shared_ptr<CoordinateSystem> &c2) {
        return *c1 == *c2;
    }
    bool CoordinateSystem::operator!=(const CoordinateSystem &coordinate_system) const {
        return _coordinate_system_type != coordinate_system.get_type();
    }
    bool operator!=(const std::shared_ptr<CoordinateSystem> &c1, const CoordinateSystem &c2) {
        return *c1 != c2;
    }
    bool operator!=(const CoordinateSystem &c1, const std::shared_ptr<CoordinateSystem> &c2) {
        return c1 != *c2;
    }
    bool operator!=(const std::shared_ptr<CoordinateSystem> &c1, const std::shared_ptr<CoordinateSystem> &c2) {
        return *c1 != *c2;
    }
    Point2D CoordinateSystem::from_canvas(const Point2D &p) const {
        if (p.get_coordinate_system()->get_type() != "CAN") {
            throw coordinate_system_mismatch("Point is not in canvas coordinate system");
        }
        throw coordinate_system_mismatch("Cannot convert a point to null coordinate system from canvas coordinate system");
    }
    Point2D CoordinateSystem::to_canvas(const Point2D &p) const {
        if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        throw coordinate_system_mismatch("Cannot convert a point in null coordinate system to canvas coordinate system");
    }

    coordinate_system_mismatch::coordinate_system_mismatch(): std::logic_error("Coordinate systems mismatch.") {}
    coordinate_system_mismatch::coordinate_system_mismatch(const std::string &str):  std::logic_error("Coordinate systems mismatch : " + str) {}
    char const* coordinate_system_mismatch::what() const noexcept {
        return std::logic_error::what();
    }
}