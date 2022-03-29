#include "point.h"
#include <iostream>

namespace Lewzen {
    Point2D::Point2D(const double &x, const double &y) {
        new (this)Point2D(x, y, Coordinate());
    }
    Point2D::Point2D(const double &x, const double &y, const Coordinate &coordinate): _x(x), _y(y), _coordinate(coordinate) {}
    const Coordinate &Point2D::get_coordinate() {
        return _coordinate;
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
    Point2D operator() (const Coordinate &coordinate) {
        
    }
    Point2D& operator=(const Point2D& point) {
        //_x = point.get_x();
        //_y = point.get_y();
    }
}