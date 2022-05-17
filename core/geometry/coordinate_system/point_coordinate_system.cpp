#include "point_coordinate_system.h"
#include "point_relative_coordinate_system.h"

namespace Lewzen {
    PointCoordinateSystem::PointCoordinateSystem(const std::weak_ptr<Point2D> &origin): CoordinateSystem("POI"), _origin(origin) {
        if (auto sp = origin.lock()) {
            _vertex_default = std::make_shared<Point2D>(sp->get_x() + 1, sp->get_y() + 1, sp->get_coordinate_system());
            _vertex = _vertex_default;
        } else {
            throw std::runtime_error("Null pointer when initialization PointCoordinateSystem");
        }
    }
    PointCoordinateSystem::PointCoordinateSystem(const std::weak_ptr<Point2D> &origin, const std::weak_ptr<Point2D> &vertex): CoordinateSystem("POI"), _origin(origin), _vertex(vertex) {
        auto sp1 = origin.lock(); auto sp2 = vertex.lock();
        if (sp1 && sp2) {
            if (sp1->get_coordinate_system() != sp2->get_coordinate_system()) {
                throw coordinate_system_mismatch("Two points are not in the same coordinate system");
            }
        } else {
            throw std::runtime_error("Null pointer when initialization PointCoordinateSystem");
        }
    }
    PointCoordinateSystem::PointCoordinateSystem(const PointCoordinateSystem &coordinate_system): CoordinateSystem("POI"), _origin(coordinate_system.get_origin()), _vertex(coordinate_system.get_vertex()) {}
    const std::weak_ptr<Point2D> PointCoordinateSystem::get_origin() const {
        return _origin;
    }
    const std::weak_ptr<Point2D> PointCoordinateSystem::get_vertex() const {
        return _vertex;
    }
    std::shared_ptr<CoordinateSystem> PointCoordinateSystem::clone() const {
        return std::make_shared<PointCoordinateSystem>(*this);
    }
    bool PointCoordinateSystem::operator==(const CoordinateSystem &coordinate_system) const {
        if (!CoordinateSystem::operator==(coordinate_system)) return false;
        auto __origin = static_cast<const PointCoordinateSystem &>(coordinate_system).get_origin();
        auto __vertex = static_cast<const PointCoordinateSystem &>(coordinate_system).get_vertex();
        auto sp1 = __origin.lock(); auto sp2 = __vertex.lock(); auto sp3 = _origin.lock(); auto sp4 = _vertex.lock();
        if (sp1 && sp2 && sp3 && sp4) {
            return *sp1 == *sp3 && *sp2 == *sp4;
        } else {
            throw std::runtime_error("Null pointer when comparing PointCoordinateSystem");
        }
    }
    bool PointCoordinateSystem::operator!=(const CoordinateSystem &coordinate_system) const {
        if (CoordinateSystem::operator==(coordinate_system)) return false;
        auto __origin = static_cast<const PointCoordinateSystem &>(coordinate_system).get_origin();
        auto __vertex = static_cast<const PointCoordinateSystem &>(coordinate_system).get_vertex();
        auto sp1 = __origin.lock(); auto sp2 = __vertex.lock(); auto sp3 = _origin.lock(); auto sp4 = _vertex.lock();
        if (sp1 && sp2 && sp3 && sp4) {
            return !(*sp1 == *sp3 && *sp2 == *sp4);
        } else {
            throw std::runtime_error("Null pointer when comparing PointCoordinateSystem");
        }
    }
    Point2D PointCoordinateSystem::to_relative(const Point2D &p) const {
       if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        auto sp1 = _origin.lock(); auto sp2 = _vertex.lock();
        if (sp1 && sp2) {
            double dx = sp2->get_x() - sp1->get_x(), dy = sp2->get_y() - sp1->get_y();
            return Point2D((dx == 0) ? 0 : p.get_x() / dx, (dy == 0) ? 0 : p.get_y() / dy, std::make_shared<PointRelativeCoordinateSystem>(sp1, sp2));
        } else {
            throw std::runtime_error("Null pointer when converting PointCoordinateSystem to PointRelativeCoordinateSystem");
        }
    }
    Point2D PointCoordinateSystem::from_canvas(const Point2D &p) const {
       if (p.get_coordinate_system()->get_type() != "CAN") {
            throw coordinate_system_mismatch("Point is not in canvas coordinate system");
        }
        auto sp1 = _origin.lock(); auto sp2 = _vertex.lock();
        if (sp1 && sp2) {
            const Point2D &pf = sp1->get_coordinate_system()->from_canvas(p);
            return Point2D(pf.get_x() - sp1->get_x(), pf.get_y() - sp2->get_y(), std::make_shared<PointRelativeCoordinateSystem>(sp1, sp2));
        } else {
            throw std::runtime_error("Null pointer when converting CanvasCoordinateSystem to PointCoordinateSystem");
        }
    }
    Point2D PointCoordinateSystem::to_canvas(const Point2D &p) const {
        if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        auto sp1 = _origin.lock(); auto sp2 = _vertex.lock();
        if (sp1 && sp2) {
            const Point2D &pf = Point2D(p.get_x() + sp1->get_x(), p.get_y() + sp1->get_y(), sp1->get_coordinate_system());
            return sp1->get_coordinate_system()->to_canvas(pf);
        } else {
            throw std::runtime_error("Null pointer when converting PointCoordinateSystem to CanvasCoordinateSystem");
        }
    }
}