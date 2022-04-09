#include "point_relative_coordinate.h"
#include "point_coordinate.h"

namespace Lewzen {
    PointRelativeCoordinate::PointRelativeCoordinate(const std::shared_ptr<Point2D> &origin, const std::shared_ptr<Point2D> &vertex): _origin(origin), _vertex(vertex) {
        if (origin.get_coordinate() != vertex.get_coordinate()) {
            throw "Two points are not in the same coordinate";
        }
        new (this)Coordinate("POIR");
    }
    const std::shared_ptr<Point2D> &PointRelativeCoordinate::get_origin() const {
        return _origin;
    }
    const std::shared_ptr<Point2D> &PointRelativeCoordinate::get_vertex() const {
        return _vertex;
    }
    bool PointRelativeCoordinate::operator== (const Coordinate &coordianate) const {
        if (!A::operator==(coordianate)) return false;
        return _component == static_cast<const PointRelativeCoordinate &>(coordianate).get_origin()
               && _component == static_cast<const PointRelativeCoordinate &>(coordianate).get_vertex();
    }
    bool PointRelativeCoordinate::operator!= (const Coordinate &coordianate) const {
        if (A::operator==(coordianate)) return false;
        return !_component == static_cast<const PointRelativeCoordinate &>(coordianate).get_origin()
                   || !_component == static_cast<const PointRelativeCoordinate &>(coordianate).get_vertex();
    }
    Point2D to_absolute(const Point2D &p) const {
       if (p.get_coordinate() != *this) {
            throw "Point is not in this coordinate";
        }
        double dx = _vertex.get_x() - _origin.get_x(), dy = _vertex.get_y() - _origin.get_y();
        return Point2D(p.get_x() * dx, p.get_y() * dy, PointCoordinate(_origin, _vertex));
    }
    Point2D from_canvas(const Point2D &p) const {
       if (p.get_coordinate().get_type() != "CAN") {
            throw "Point is not in canvas coordinate";
        }
        const Point2D &pf = _origin.get_coordinate().from_canvas(p);
        double dx = _vertex.get_x() - _origin.get_x(), dy = _vertex.get_y() - _origin.get_y();
        return Point2D((dx == 0) ? 0 : (pf.get_x() - _origin.get_x()) / dx, (dy == 0) ? 0 : (pf.get_y() - _origin.get_y()) / dy, *this);
    }
    Point2D to_canvas(const Point2D &p) const {
        if (p.get_coordinate() != *this) {
            throw "Point is not in this coordinate";
        }
        double dx = _vertex.get_x() - _origin.get_x(), dy = _vertex.get_y() - _origin.get_y();
        const Point2D &pf = Point2D(p.get_x() * dx + _origin.get_x(), p.get_x() * dx + _origin.get_y(), _origin.get_coordinate());
        return _origin.get_coordinate().to_canvas(pf);
    }
}