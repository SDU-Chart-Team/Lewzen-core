#include "vector_relative_coordinate_system.h"
#include "vector_coordinate_system.h"
#include "../point_func.h"
#include <cmath>

namespace Lewzen {
    VectorRelativeCoordinateSystem::VectorRelativeCoordinateSystem(const std::shared_ptr<Point2D> &A, const std::shared_ptr<Point2D> &B): _A(A), _B(B) {
        if (A->get_coordinate_system() != B->get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        new (this)CoordinateSystem("VECR");
    }
    VectorRelativeCoordinateSystem::VectorRelativeCoordinateSystem(const VectorRelativeCoordinateSystem &coordinate_system): _A(coordinate_system.get_A()), _B(coordinate_system.get_B()) {
        new (this)CoordinateSystem("VECR");
    }
    const std::shared_ptr<Point2D> VectorRelativeCoordinateSystem::get_A() const {
        return _A;
    }
    const std::shared_ptr<Point2D> VectorRelativeCoordinateSystem::get_B() const {
        return _B;
    }
    std::shared_ptr<CoordinateSystem> VectorRelativeCoordinateSystem::clone() const {
        return std::make_shared<VectorRelativeCoordinateSystem>(*this);
    }
    bool VectorRelativeCoordinateSystem::operator==(const CoordinateSystem &coordinate_system) const {
        if (!CoordinateSystem::operator==(coordinate_system)) return false;
        return *_A == *(static_cast<const VectorRelativeCoordinateSystem &>(coordinate_system).get_A())
               && *_B == *(static_cast<const VectorRelativeCoordinateSystem &>(coordinate_system).get_B());
    }
    bool VectorRelativeCoordinateSystem::operator!=(const CoordinateSystem &coordinate_system) const {
        if (CoordinateSystem::operator==(coordinate_system)) return false;
        return !(*_A == *(static_cast<const VectorRelativeCoordinateSystem &>(coordinate_system).get_B()))
                   || !(*_B == *(static_cast<const VectorRelativeCoordinateSystem &>(coordinate_system).get_B()));
    }
    Point2D VectorRelativeCoordinateSystem::to_absolute(const Point2D &p) const {
       if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        double dx = _B->get_x() - _A->get_x(), dy = _B->get_y() - _A->get_y(), l = std::sqrt(dx * dx + dy * dy);
        return Point2D(p.get_x() * l, p.get_y() * l, VectorCoordinateSystem(_A, _B));
    }
    Point2D VectorRelativeCoordinateSystem::from_canvas(const Point2D &p) const {
       if (p.get_coordinate_system().get_type() != "CAN") {
            throw coordinate_system_mismatch("Point is not in canvas coordinate system");
        }
        const Point2D &pf = _A->get_coordinate_system().from_canvas(p);
        double dx = _B->get_x() - _A->get_x(), dy = _B->get_y() - _A->get_y(), l = std::sqrt(dx * dx + dy * dy);
        double cos = dx / l, sin = dy / l;
        Point2D d = linear_transform(cos, sin, -sin, cos, pf - *_A);
        return Point2D((l == 0) ? 0 : d.get_x() / l, (l == 0) ? 0 : d.get_y() / l, *this);
    }
    Point2D VectorRelativeCoordinateSystem::to_canvas(const Point2D &p) const {
        if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        double dx = _B->get_x() - _A->get_x(), dy = _B->get_y() - _A->get_y(), l = std::sqrt(dx * dx + dy * dy);
        double cos = dx / l, sin = dy / l;
        Point2D d = linear_transform(cos, -sin, sin, cos, p);
        const Point2D &pf = Point2D(d.get_x() * l + _A->get_x(), d.get_y() * l + _A->get_y(), _A->get_coordinate_system());
        return _A->get_coordinate_system().to_canvas(pf);
    }
}