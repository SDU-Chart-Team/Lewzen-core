#include "point_coordinate.h"
#include "point_relative_coordinate.h"

namespace Lewzen {
    PointCoordinate::PointCoordinate(const std::shared_ptr<Point2D> &origin): _origin(origin) {
        _vertex = make_shared<Point2D>(origin->get_x() + 1, origin->get_y() + 1, origin->get_coordinate());
        new (this)Coordinate("POI");
    }
    PointCoordinate::PointCoordinate(const std::shared_ptr<Point2D> &origin, const std::shared_ptr<Point2D> &vertex): _origin(origin), _vertex(vertex) {
        new (this)Coordinate("POI");
    }
    const std::shared_ptr<Point2D> &PointCoordinate::get_origin() const {
        return _origin;
    }
    bool PointCoordinate::operator== (const Coordinate &coordianate) const {
        if (!A::operator==(coordianate)) return false;
        return _component == static_cast<const PointCoordinate &>(coordianate).get_origin();
    }
    bool PointCoordinate::operator!= (const Coordinate &coordianate) const {
        if (A::operator==(coordianate)) return false;
        return !_component == static_cast<const PointCoordinate &>(coordianate).get_origin();
    }
    Point2D to_relative(const Point2D &p) const {
       if (p.get_coordinate() != *this) {
            throw "Point is not in this coordinate";
        }
        double dx = _vertex.get_x() - _origin.get_x(), dy = _vertex.get_y() - _origin.get_y();
        return Point2D((dx == 0) ? 0 : p.get_x() / dx, (dy == 0) ? 0 : p.get_y() / dy, PointRelativeCoordinate(_origin, _vertex));
    }
    Point2D from_canvas(const Point2D &p) const {
       if (p.get_coordinate().get_type() != "CAN") {
            throw "Point is not in canvas coordinate";
        }
        const Point2D &pf = _origin.get_coordinate().from_canvas(p);
        return Point2D(pf.get_x() - _origin.get_x(), pf.get_y() - _origin.get_y(), *this);
    }
    Point2D to_canvas(const Point2D &p) const {
        if (p.get_coordinate() != *this) {
            throw "Point is not in this coordinate";
        }
        const Point2D &pf = Point2D(p.get_x() + _origin.get_x(), p.get_y() + _origin.get_y(), _origin.get_coordinate());
        return _origin.get_coordinate().to_canvas(pf);
    }
}