#include "vector_relative_coordinate_system.h"
#include "vector_coordinate_system.h"
#include "../point_func.h"
#include <cmath>

namespace Lewzen {
    VectorRelativeCoordinateSystem::VectorRelativeCoordinateSystem(const std::shared_ptr<Point2D> &A, const std::shared_ptr<Point2D> &B): _A(A), _B(B) {
        if (A.get_coordinate_system() != B.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        new (this)CoordinateSystem("VECR");
    }
    const std::shared_ptr<Point2D> &VectorRelativeCoordinateSystem::get_A() const {
        return _A;
    }
    const std::shared_ptr<Point2D> &VectorRelativeCoordinateSystem::get_B() const {
        return _B;
    }
    bool VectorRelativeCoordinateSystem::operator== (const CoordinateSystem &coordinate_system) const {
        if (!A::operator==(coordinate)) return false;
        return _component == static_cast<const VectorRelativeCoordinateSystem &>(coordinate).get_A()
               && _component == static_cast<const VectorRelativeCoordinateSystem &>(coordinate).get_B();
    }
    bool VectorRelativeCoordinateSystem::operator!= (const CoordinateSystem &coordinate_system) const {
        if (A::operator==(coordinate)) return false;
        return !_component == static_cast<const VectorRelativeCoordinateSystem &>(coordinate).get_A()
                   || !_component == static_cast<const VectorRelativeCoordinateSystem &>(coordinate).get_B();
    }
    Point2D to_absolute(const Point2D &p) const {
       if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        double dx = _B.get_x() - _A.get_x(), dy = _B.get_y() - _A.get_y(), l = std::sqrt(dx * dx + dy * dy);
        return Point2D(p.get_x() * l, p.get_y() * l, VectorCoordinateSystem(_A, _B));
    }
    Point2D from_canvas(const Point2D &p) const override {
       if (p.get_coordinate_system().get_type() != "CAN") {
            throw coordinate_system_mismatch("Point is not in canvas coordinate system");
        }
        const Point2D &pf = _origin.get_coordinate_system().from_canvas(p);
        double dx = _B.get_x() - _A.get_x(), dy = _B.get_y() - _A.get_y(), l = std::sqrt(dx * dx + dy * dy);
        double cos = dx / l, sin = dy / l;
        Point2D d = linear_transform(cos, sin, -sin, cos, pf - _A);
        return Point2D((l == 0) ? 0 : d.get_x() / l, (l == 0) ? 0 : d.get_y() / l, *this);
    }
    Point2D to_canvas(const Point2D &p) const override {
        if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        double dx = _B.get_x() - _A.get_x(), dy = _B.get_y() - _A.get_y(), l = std::sqrt(dx * dx + dy * dy);
        double cos = dx / l, sin = dy / l;
        Point2D d = linear_transform(cos, -sin, sin, cos, p);
        const Point2D &pf = Point2D(d.get_x() * l + _A.get_x(), d.get_y() * l + _A.get_y(), _origin.get_coordinate_system());
        return _origin.get_coordinate_system().to_canvas(pf);
    }
}