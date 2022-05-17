#include "point_relative_coordinate_system.h"
#include "point_coordinate_system.h"

namespace Lewzen {
    PointRelativeCoordinateSystem::PointRelativeCoordinateSystem(const std::weak_ptr<Point2D> &origin, const std::weak_ptr<Point2D> &vertex): CoordinateSystem("POIR"), _origin(origin), _vertex(vertex) {
        auto sp1 = origin.lock(); auto sp2 = vertex.lock();
        if (sp1 && sp2) {
            if (sp1->get_coordinate_system() != sp2->get_coordinate_system()) {
                throw coordinate_system_mismatch("Two points are not in the same coordinate system");
            }
        } else {
            throw std::runtime_error("Null pointer when initialization PointRelativeCoordinateSystem");
        }
    }
    PointRelativeCoordinateSystem::PointRelativeCoordinateSystem(const PointRelativeCoordinateSystem &coordinate_system): CoordinateSystem("POIR"), _origin(coordinate_system.get_origin()), _vertex(coordinate_system.get_vertex()) {}
    const std::weak_ptr<Point2D> PointRelativeCoordinateSystem::get_origin() const {
        return _origin;
    }
    const std::weak_ptr<Point2D> PointRelativeCoordinateSystem::get_vertex() const {
        return _vertex;
    }
    std::shared_ptr<CoordinateSystem> PointRelativeCoordinateSystem::clone() const {
        return std::make_shared<PointRelativeCoordinateSystem>(*this);
    }
    bool PointRelativeCoordinateSystem::operator==(const CoordinateSystem &coordinate_system) const {
        if (!CoordinateSystem::operator==(coordinate_system)) return false;
        auto __origin = static_cast<const PointRelativeCoordinateSystem &>(coordinate_system).get_origin();
        auto __vertex = static_cast<const PointRelativeCoordinateSystem &>(coordinate_system).get_vertex();
        auto sp1 = __origin.lock(); auto sp2 = __vertex.lock(); auto sp3 = _origin.lock(); auto sp4 = _vertex.lock();
        if (sp1 && sp2 && sp3 && sp4) {
            return *sp1 == *sp3 && *sp2 == *sp4;
        } else {
            throw std::runtime_error("Null pointer when comparing PointRelativeCoordinateSystem");
        }
    }
    bool PointRelativeCoordinateSystem::operator!=(const CoordinateSystem &coordinate_system) const {
        if (CoordinateSystem::operator==(coordinate_system)) return false;
        auto __origin = static_cast<const PointRelativeCoordinateSystem &>(coordinate_system).get_origin();
        auto __vertex = static_cast<const PointRelativeCoordinateSystem &>(coordinate_system).get_vertex();
        auto sp1 = __origin.lock(); auto sp2 = __vertex.lock(); auto sp3 = _origin.lock(); auto sp4 = _vertex.lock();
        if (sp1 && sp2 && sp3 && sp4) {
            return !(*sp1 == *sp3 && *sp2 == *sp4);
        } else {
            throw std::runtime_error("Null pointer when comparing PointRelativeCoordinateSystem");
        }
    }
    Point2D PointRelativeCoordinateSystem::to_absolute(const Point2D &p) const {
       if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        auto sp1 = _origin.lock(); auto sp2 = _vertex.lock();
        if (sp1 && sp2) {
            double dx = sp2->get_x() - sp1->get_x(), dy = sp2->get_y() - sp1->get_y();
            return Point2D(p.get_x() * dx, p.get_y() * dy, std::make_shared<PointCoordinateSystem>(sp1, sp2));
        } else {
            throw std::runtime_error("Null pointer when converting PointRelativeCoordinateSystem to PointCoordinateSystem");
        }
    }
    Point2D PointRelativeCoordinateSystem::from_canvas(const Point2D &p) const {
       if (p.get_coordinate_system()->get_type() != "CAN") {
            throw coordinate_system_mismatch("Point is not in canvas coordinate system");
        }
        auto sp1 = _origin.lock(); auto sp2 = _vertex.lock();
        if (sp1 && sp2) {
            const Point2D &pf = sp1->get_coordinate_system()->from_canvas(p);
            double dx = sp2->get_x() - sp1->get_x(), dy = sp2->get_y() - sp1->get_y();
            return Point2D((dx == 0) ? 0 : (pf.get_x() - sp1->get_x()) / dx, (dy == 0) ? 0 : (pf.get_y() - sp1->get_y()) / dy, std::make_shared<PointCoordinateSystem>(sp1, sp2));
        } else {
            throw std::runtime_error("Null pointer when converting CanvasCoordinateSystem to PointRelativeCoordinateSystem");
        }
    }
    Point2D PointRelativeCoordinateSystem::to_canvas(const Point2D &p) const {
        if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        auto sp1 = _origin.lock(); auto sp2 = _vertex.lock();
        if (sp1 && sp2) {
            double dx = sp2->get_x() - sp1->get_x(), dy = sp2->get_y() - sp1->get_y();
            const Point2D &pf = Point2D(p.get_x() * dx + sp1->get_x(), p.get_x() * dx + sp1->get_y(), sp1->get_coordinate_system());
            return sp1->get_coordinate_system()->to_canvas(pf);
        } else {
            throw std::runtime_error("Null pointer when converting PointRelativeCoordinateSystem to CanvasCoordinateSystem");
        }
    }
}