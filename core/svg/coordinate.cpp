#include "coordinate.h"

namespace Lewzen {
    Coordinate::Coordinate() {
        new (this)Coordinate("NULL");
    }
    Coordinate::Coordinate(const std::string &coordinate_type): _coordinate_type(coordinate_type) {}
    const std::string &Coordinate::get_type() const {
        return _coordinate_type;
    }
    bool Coordinate::operator== (const Coordinate &coordianate) const {
        return _coordinate_type == coordianate.get_type();
    }
    bool Coordinate::operator!= (const Coordinate &coordianate) const {
        return _coordinate_type != coordianate.get_type();
    }
    Point2D from_canvas(const Point2D &p) const {
        if (p.get_coordinate().get_type() != "CAN") {
            throw "Point is not in canvas coordinate";
        }
        return Point2D(p.get_x(), p.get_y(), *this);
    }
    Point2D to_canvas(const Point2D &p) const {
        if (p.get_coordinate() != *this) {
            throw "Point is not in this coordinate";
        }
        throw "Cannot convert a point in null coordinate to canvas coordinate";
        return p;
    }
}