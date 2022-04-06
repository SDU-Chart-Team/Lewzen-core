#include "coordinate_system.h"

namespace Lewzen {
    CoordinateSystem::CoordinateSystem() {
        new (this)CoordinateSystem("NULL");
    }
    CoordinateSystem::CoordinateSystem(const std::string &coordinate system_type): _coordinate_system_type(coordinate system_type) {}
    const std::string &CoordinateSystem::get_type() const {
        return _coordinate_system_type;
    }
    bool CoordinateSystem::operator== (const CoordinateSystem &coordianate_system) const {
        return _coordinate_system_type == coordianate.get_type();
    }
    bool CoordinateSystem::operator!= (const CoordinateSystem &coordianate_system) const {
        return _coordinate_system_type != coordianate.get_type();
    }
    Point2D from_canvas(const Point2D &p) const override {
        if (p.get_coordinate_system().get_type() != "CAN") {
            throw coordinate_system_mismatch("Point is not in canvas coordinate system");
        }
        return Point2D(p.get_x(), p.get_y(), *this);
    }
    Point2D to_canvas(const Point2D &p) const override {
        if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        throw coordinate_system_mismatch("Cannot convert a point in null coordinate system to canvas coordinate system");
        return p;
    }

    coordinate_system_mismatch::coordinate_system_mismatch(): _message("Coordinate systems mismatch.") {}
    coordinate_system_mismatch::coordinate_system_mismatch(const std::string &str): _message("Coordinate systems mismatch : " + str) {}
    virtual char const* coordinate_system_mismatch::what() const noexcept override {
        return _message.c_str();
    }
}