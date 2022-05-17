#include "vector_coordinate_system.h"
#include "vector_relative_coordinate_system.h"
#include "../point_func.h"
#include <cmath>

namespace Lewzen {
    VectorCoordinateSystem::VectorCoordinateSystem(const std::weak_ptr<Point2D> &A, const std::weak_ptr<Point2D> &B): CoordinateSystem("VEC"), _A(A), _B(B) {
        auto sp1 = A.lock(); auto sp2 = B.lock();
        if (sp1 && sp2) {
            if (sp1->get_coordinate_system() != sp2->get_coordinate_system()) {
                throw coordinate_system_mismatch("Two points are not in the same coordinate system");
            }
        } else {
            throw std::runtime_error("Null pointer when initialization VectorCoordinateSystem");
        }
    }
    VectorCoordinateSystem::VectorCoordinateSystem(const VectorCoordinateSystem &coordinate_system): CoordinateSystem("VEC"), _A(coordinate_system.get_A()), _B(coordinate_system.get_B()) {}
    const std::weak_ptr<Point2D> VectorCoordinateSystem::get_A() const {
        return _A;
    }
    const std::weak_ptr<Point2D> VectorCoordinateSystem::get_B() const {
        return _B;
    }
    std::shared_ptr<CoordinateSystem> VectorCoordinateSystem::clone() const {
        return std::make_shared<VectorCoordinateSystem>(*this);
    }
    bool VectorCoordinateSystem::operator==(const CoordinateSystem &coordinate_system) const {
        if (!CoordinateSystem::operator==(coordinate_system)) return false;
        auto __A = static_cast<const VectorCoordinateSystem &>(coordinate_system).get_A();
        auto __B = static_cast<const VectorCoordinateSystem &>(coordinate_system).get_B();
        auto sp1 = __A.lock(); auto sp2 = __B.lock(); auto sp3 = _A.lock(); auto sp4 = _B.lock();
        if (sp1 && sp2 && sp3 && sp4) {
            return *sp1 == *sp3 && *sp2 == *sp4;
        } else {
            throw std::runtime_error("Null pointer when comparing VectorCoordinateSystem");
        }
    }
    bool VectorCoordinateSystem::operator!=(const CoordinateSystem &coordinate_system) const {
        if (CoordinateSystem::operator==(coordinate_system)) return false;
        auto __A = static_cast<const VectorCoordinateSystem &>(coordinate_system).get_A();
        auto __B = static_cast<const VectorCoordinateSystem &>(coordinate_system).get_B();
        auto sp1 = __A.lock(); auto sp2 = __B.lock(); auto sp3 = _A.lock(); auto sp4 = _B.lock();
        if (sp1 && sp2 && sp3 && sp4) {
            return !(*sp1 == *sp3 && *sp2 == *sp4);
        } else {
            throw std::runtime_error("Null pointer when comparing VectorCoordinateSystem");
        }
    }
    Point2D VectorCoordinateSystem::to_relative(const Point2D &p) const {
       if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        auto sp1 = _A.lock(); auto sp2 = _B.lock();
        if (sp1 && sp2) {
            double dx = sp2->get_x() - sp1->get_x(), dy = sp2->get_y() - sp1->get_y(), l = std::sqrt(dx * dx + dy * dy);
            return Point2D((l == 0) ? 0 : p.get_x() / l, (l == 0) ? 0 : p.get_y() / l, std::make_shared<VectorRelativeCoordinateSystem>(sp1, sp2));
        } else {
            throw std::runtime_error("Null pointer when converting VectorCoordinateSystem to VectorRelativeCoordinateSystem");
        }
    }
    Point2D VectorCoordinateSystem::from_canvas(const Point2D &p) const {
       if (p.get_coordinate_system()->get_type() != "CAN") {
            throw coordinate_system_mismatch("Point is not in canvas coordinate system");
        }
        auto sp1 = _A.lock(); auto sp2 = _B.lock();
        if (sp1 && sp2) {
            const Point2D &pf = sp1->get_coordinate_system()->from_canvas(p);
            double dx = sp2->get_x() - sp1->get_x(), dy = sp2->get_y() - sp1->get_y(), l = std::sqrt(dx * dx + dy * dy);
            double cos = dx / l, sin = dy / l;
            Point2D d = linear_transform(cos, sin, -sin, cos, pf - *sp1);
            return Point2D(d.get_x(), d.get_y(), std::make_shared<VectorRelativeCoordinateSystem>(sp1, sp2));
        } else {
            throw std::runtime_error("Null pointer when converting CanvasCoordinateSystem to VectorCoordinateSystem");
        }
    }
    Point2D VectorCoordinateSystem::to_canvas(const Point2D &p) const {
        if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        auto sp1 = _A.lock(); auto sp2 = _B.lock();
        if (sp1 && sp2) {
            double dx = sp2->get_x() - sp1->get_x(), dy = sp2->get_y() - sp1->get_y(), l = std::sqrt(dx * dx + dy * dy);
            double cos = dx / l, sin = dy / l;
            Point2D d = linear_transform(cos, -sin, sin, cos, p);
            const Point2D &pf = Point2D(d.get_x() + sp1->get_x(), d.get_y() + sp1->get_y(), sp1->get_coordinate_system());
            return sp1->get_coordinate_system()->to_canvas(pf);
        } else {
            throw std::runtime_error("Null pointer when converting VectorCoordinateSystem to CanvasCoordinateSystem");
        }
    }
}