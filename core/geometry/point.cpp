#include "point.h"
#include "point_func.h"
#include <iostream>

namespace Lewzen {
    Point2D::Point2D(const double &x, const double &y) {
        new (this)Point2D(x, y, CoordinateSystem());
    }
    Point2D::Point2D(const double &x, const double &y, const CoordinateSystem &coordinate_system): _x(x), _y(y), _coordinate_system(coordinate_system.clone()) {}
    Point2D::Point2D(const Point2D &point): _x(point.get_x()), _y(point.get_y()), _coordinate_system(point.get_coordinate_system().clone()) {}
    const CoordinateSystem &Point2D::get_coordinate_system() const {
        return *_coordinate_system;
    }
    double Point2D::get_x() const {
        return _x;
    }
    void Point2D::set_x(const double &x) {
        double last_x;
        _x = x;
        if (!(x == last_x)) _callback();
    }
    double Point2D::get_y() const {
        return _y;
    }
    void Point2D::set_y(const double &y) {
        double last_y;
        _y = y;
        if (!(y == last_y)) _callback();
    }
    void Point2D::move(const double &dx, const double &dy) {
        double last_x = _x, last_y = _y;
        _x += dx;
        _y += dy;
        if (!(_x == last_x && _y == last_y)) _callback();
    }
    std::shared_ptr<Point2D> Point2D::clone() const {
        return std::make_shared<Point2D>(*this);
    }
    bool Point2D::operator==(const Point2D &point) const {
        return _x == point.get_x() && _y == point.get_y() && get_coordinate_system() == point.get_coordinate_system();
    }
    Point2D& Point2D::operator=(const Point2D &point) {
        if (get_coordinate_system() != point.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        double last_x = _x, last_y = _y;
        _x = point.get_x();
        _y = point.get_y();
        if (!(_x == last_x && _y == last_y)) _callback();
    }
    Point2D& Point2D::operator+= (const Point2D &point) {
        if (get_coordinate_system() != point.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        double last_x = _x, last_y = _y;
        _x += point.get_x();
        _y += point.get_y();
        if (!(_x == last_x && _y == last_y)) _callback();
        return *this;
    }
    Point2D& Point2D::operator-= (const Point2D &point) {
        if (get_coordinate_system() != point.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        double last_x = _x, last_y = _y;
        _x -= point.get_x();
        _y -= point.get_y();
        if (!(_x == last_x && _y == last_y)) _callback();
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
    void Point2D::on_update(const std::function<void()> callback) {
         _callback = callback;
    }
    void Point2D::on_update() {
         _callback = [](){};
    }
}