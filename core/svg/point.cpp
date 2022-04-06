#include "point.h"
#include "point_func.h"
#include <iostream>

namespace Lewzen {
    Point2D::Point2D(const double &x, const double &y) {
        new (this)Point2D(x, y, CoordinateSystem());
    }
    Point2D::Point2D(const double &x, const double &y, const CoordinateSystem &coordinate_system): _x(x), _y(y), _coordinate system(coordinate system) {}
    const CoordinateSystem &Point2D::get_coordinate_system() {
        return _coordinate system;
    }
    double Point2D::get_x() {
        return _x;
    }
    void Point2D::set_x(const double &x) {
        _x = x;
    }
    double Point2D::get_y() {
        return _y;
    }
    void Point2D::set_y(const double &y) {
        _y = y;
    }
    void Point2D::move(const double &dx, const double &dy) {
        _x += dx;
        _y += dy;
    }
    bool operator== (const Point2D &point) {
        return _x == point.get_x() && _y == point.get_y() && _coordinate system == point.get_coordinate_system();
    }
    Point2D& operator=(const Point2D& point) {
        if (p.get_coordinate_system() != c.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        _x = point.get_x();
        _y = point.get_y();
    }
    Point2D& operator+= (const Point2D &point) {
        if (p.get_coordinate_system() != c.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        _x += point.get_x();
        _y += point.get_y();
        return *this;
    }
    Point2D& operator-= (const Point2D &point) {
        if (p.get_coordinate_system() != c.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        _x -= point.get_x();
        _y -= point.get_y();
        return *this;
    }
    Point2D operator+ (const Point2D &point) {
        if (p.get_coordinate_system() != c.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        return Point2D(_x + point.get_x(), _y + point.get_y(), p.get_coordinate_system());
    }
    Point2D operator- (const Point2D &point) {
        if (p.get_coordinate_system() != c.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        return Point2D(_x - point.get_x(), _y - point.get_y(), p.get_coordinate_system());
    }
    Point2D operator() (const CoordinateSystem &coordinate_system) {
        return coordinate system_convert(*this, coordinate system);
    }
}