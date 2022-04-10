#include "point_coordinate_system.h"
#include "point_relative_coordinate_system.h"

namespace Lewzen {
    PointCoordinateSystem::PointCoordinateSystem(const std::shared_ptr<Point2D> &origin): _origin(origin) {
        _vertex = std::make_shared<Point2D>(origin->get_x() + 1, origin->get_y() + 1, origin->get_coordinate_system());
        new (this)CoordinateSystem("POI");
    }
    PointCoordinateSystem::PointCoordinateSystem(const std::shared_ptr<Point2D> &origin, const std::shared_ptr<Point2D> &vertex): _origin(origin), _vertex(vertex) {
        if (origin->get_coordinate_system() != vertex->get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        new (this)CoordinateSystem("POI");
    }
    PointCoordinateSystem::PointCoordinateSystem(const PointCoordinateSystem &coordinate_system): _origin(coordinate_system.get_origin()), _vertex(coordinate_system.get_vertex()) {
        new (this)CoordinateSystem("POI");
    }
    const std::shared_ptr<Point2D> PointCoordinateSystem::get_origin() const {
        return _origin;
    }
    const std::shared_ptr<Point2D> PointCoordinateSystem::get_vertex() const {
        return _vertex;
    }
    std::shared_ptr<CoordinateSystem> PointCoordinateSystem::clone() const {
        return std::make_shared<PointCoordinateSystem>(*this);
    }
    bool PointCoordinateSystem::operator==(const CoordinateSystem &coordinate_system) const {
        if (!CoordinateSystem::operator==(coordinate_system)) return false;
        return *_origin == *(static_cast<const PointCoordinateSystem &>(coordinate_system).get_origin())
               && *_vertex == *(static_cast<const PointCoordinateSystem &>(coordinate_system).get_vertex());
    }
    bool PointCoordinateSystem::operator!=(const CoordinateSystem &coordinate_system) const {
        if (CoordinateSystem::operator==(coordinate_system)) return false;
        return !(*_origin == *(static_cast<const PointCoordinateSystem &>(coordinate_system).get_origin()))
                   || !(*_vertex == *(static_cast<const PointCoordinateSystem &>(coordinate_system).get_vertex()));
    }
    Point2D PointCoordinateSystem::to_relative(const Point2D &p) const {
       if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        double dx = _vertex->get_x() - _origin->get_x(), dy = _vertex->get_y() - _origin->get_y();
        return Point2D((dx == 0) ? 0 : p.get_x() / dx, (dy == 0) ? 0 : p.get_y() / dy, PointRelativeCoordinateSystem(_origin, _vertex));
    }
    Point2D PointCoordinateSystem::from_canvas(const Point2D &p) const {
       if (p.get_coordinate_system().get_type() != "CAN") {
            throw coordinate_system_mismatch("Point is not in canvas coordinate system");
        }
        const Point2D &pf = _origin->get_coordinate_system().from_canvas(p);
        return Point2D(pf.get_x() - _origin->get_x(), pf.get_y() - _origin->get_y(), *this);
    }
    Point2D PointCoordinateSystem::to_canvas(const Point2D &p) const {
        if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        const Point2D &pf = Point2D(p.get_x() + _origin->get_x(), p.get_y() + _origin->get_y(), _origin->get_coordinate_system());
        return _origin->get_coordinate_system().to_canvas(pf);
    }
}