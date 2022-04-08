#include "point.h"
#include "point_func.h"
#include <iostream>

namespace Lewzen {
    Point2D::Point2D(const double &x, const double &y) {
        new (this)Point2D(x, y, CoordinateSystem());
    }
    Point2D::Point2D(const double &x, const double &y, const CoordinateSystem &coordinate_system): _x(x), _y(y), _coordinate_system(coordinate_system.clone()) {}
    const CoordinateSystem &Point2D::get_coordinate_system() const {
        return *_coordinate_system;
    }
    double Point2D::get_x() const {
        return _x;
    }
    void Point2D::set_x(const double &x) {
        _x = x;
    }
    double Point2D::get_y() const {
        return _y;
    }
    void Point2D::set_y(const double &y) {
        _y = y;
    }
    void Point2D::move(const double &dx, const double &dy) {
        _x += dx;
        _y += dy;
    }
    bool Point2D::operator==(const Point2D &point) const {
        return _x == point.get_x() && _y == point.get_y() && get_coordinate_system() == point.get_coordinate_system();
    }
    Point2D& Point2D::operator=(const Point2D& point) {
        if (get_coordinate_system() != point.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        _x = point.get_x();
        _y = point.get_y();
    }
    Point2D& Point2D::operator+= (const Point2D &point) {
        if (get_coordinate_system() != point.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        _x += point.get_x();
        _y += point.get_y();
        return *this;
    }
    Point2D& Point2D::operator-= (const Point2D &point) {
        if (get_coordinate_system() != point.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        _x -= point.get_x();
        _y -= point.get_y();
        return *this;
    }
    Point2D Point2D::operator+ (const Point2D &point) const {
        if (get_coordinate_system() != point.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        return Point2D(_x + point.get_x(), _y + point.get_y(), point.get_coordinate_system());
    }
    Point2D Point2D::operator- (const Point2D &point) const {
        if (get_coordinate_system() != point.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        return Point2D(_x - point.get_x(), _y - point.get_y(), point.get_coordinate_system());
    }
    Point2D Point2D::operator() (const CoordinateSystem &coordinate_system) const {
        return coordinate_system_convert(*this, coordinate_system);
    }
}