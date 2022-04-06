#include "point_relative_coordinate_system.h"
#include "point_coordinate_system.h"

namespace Lewzen {
    PointRelativeCoordinateSystem::PointRelativeCoordinateSystem(const std::shared_ptr<Point2D> &origin, const std::shared_ptr<Point2D> &vertex): _origin(origin), _vertex(vertex) {
        if (origin.get_coordinate_system() != vertex.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        new (this)CoordinateSystem("POIR");
    }
    const std::shared_ptr<Point2D> &PointRelativeCoordinateSystem::get_origin() const {
        return _origin;
    }
    const std::shared_ptr<Point2D> &PointRelativeCoordinateSystem::get_vertex() const {
        return _vertex;
    }
    bool PointRelativeCoordinateSystem::operator== (const CoordinateSystem &coordinate_system) const {
        if (!A::operator==(coordinate)) return false;
        return _component == static_cast<const PointRelativeCoordinateSystem &>(coordinate).get_origin()
               && _component == static_cast<const PointRelativeCoordinateSystem &>(coordinate).get_vertex();
    }
    bool PointRelativeCoordinateSystem::operator!= (const CoordinateSystem &coordinate_system) const {
        if (A::operator==(coordinate)) return false;
        return !_component == static_cast<const PointRelativeCoordinateSystem &>(coordinate).get_origin()
                   || !_component == static_cast<const PointRelativeCoordinateSystem &>(coordinate).get_vertex();
    }
    Point2D to_absolute(const Point2D &p) const {
       if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        double dx = _vertex.get_x() - _origin.get_x(), dy = _vertex.get_y() - _origin.get_y();
        return Point2D(p.get_x() * dx, p.get_y() * dy, PointCoordinateSystem(_origin, _vertex));
    }
    Point2D from_canvas(const Point2D &p) const override {
       if (p.get_coordinate_system().get_type() != "CAN") {
            throw coordinate_system_mismatch("Point is not in canvas coordinate system");
        }
        const Point2D &pf = _origin.get_coordinate_system().from_canvas(p);
        double dx = _vertex.get_x() - _origin.get_x(), dy = _vertex.get_y() - _origin.get_y();
        return Point2D((dx == 0) ? 0 : (pf.get_x() - _origin.get_x()) / dx, (dy == 0) ? 0 : (pf.get_y() - _origin.get_y()) / dy, *this);
    }
    Point2D to_canvas(const Point2D &p) const override {
        if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        double dx = _vertex.get_x() - _origin.get_x(), dy = _vertex.get_y() - _origin.get_y();
        const Point2D &pf = Point2D(p.get_x() * dx + _origin.get_x(), p.get_x() * dx + _origin.get_y(), _origin.get_coordinate_system());
        return _origin.get_coordinate_system().to_canvas(pf);
    }
}