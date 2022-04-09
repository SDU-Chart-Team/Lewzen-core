#include "vector_coordinate.h"
#include "vector_relative_coordinate.h"
#include "../point_func.h"
#include <cmath>

namespace Lewzen {
    VectorCoordinate::VectorCoordinate(const std::shared_ptr<Point2D> &A, const std::shared_ptr<Point2D> &B): _A(A), _B(B) {
        if (A.get_coordinate() != B.get_coordinate()) {
            throw "Two points are not in the same coordinate";
        }
        new (this)Coordinate("VEC");
    }
    const std::shared_ptr<Point2D> &VectorCoordinate::get_A() const {
        return _A;
    }
    const std::shared_ptr<Point2D> &VectorCoordinate::get_B() const {
        return _B;
    }
    bool VectorCoordinate::operator== (const Coordinate &coordianate) const {
        if (!A::operator==(coordianate)) return false;
        return _component == static_cast<const VectorCoordinate &>(coordianate).get_A()
               && _component == static_cast<const VectorCoordinate &>(coordianate).get_B();
    }
    bool VectorCoordinate::operator!= (const Coordinate &coordianate) const {
        if (A::operator==(coordianate)) return false;
        return !_component == static_cast<const VectorCoordinate &>(coordianate).get_A()
                   || !_component == static_cast<const VectorCoordinate &>(coordianate).get_B();
    }
    Point2D to_relative(const Point2D &p) const {
       if (p.get_coordinate() != *this) {
            throw "Point is not in this coordinate";
        }
        double dx = _B.get_x() - _A.get_x(), dy = _B.get_y() - _A.get_y(), l = std::sqrt(dx * dx + dy * dy);
        return Point2D((l == 0) ? 0 : p.get_x() / l, (l == 0) ? 0 : p.get_y() / l, VectorRelativeCoordinate(_A, _B));
    }
    Point2D from_canvas(const Point2D &p) const {
       if (p.get_coordinate().get_type() != "CAN") {
            throw "Point is not in canvas coordinate";
        }
        const Point2D &pf = _origin.get_coordinate().from_canvas(p);
        double dx = _B.get_x() - _A.get_x(), dy = _B.get_y() - _A.get_y(), l = std::sqrt(dx * dx + dy * dy);
        double cos = dx / l, sin = dy / l;
        Point2D d = linear_transform(cos, sin, -sin, cos, pf - _A);
        return Point2D(d.get_x(), d.get_y(), *this);
    }
    Point2D to_canvas(const Point2D &p) const {
        if (p.get_coordinate() != *this) {
            throw "Point is not in this coordinate";
        }
        double dx = _B.get_x() - _A.get_x(), dy = _B.get_y() - _A.get_y(), l = std::sqrt(dx * dx + dy * dy);
        double cos = dx / l, sin = dy / l;
        Point2D d = linear_transform(cos, -sin, sin, cos, p);
        const Point2D &pf = Point2D(d.get_x() + _A.get_x(), d.get_y() + _A.get_y(), _origin.get_coordinate());
        return _origin.get_coordinate().to_canvas(pf);
    }
}