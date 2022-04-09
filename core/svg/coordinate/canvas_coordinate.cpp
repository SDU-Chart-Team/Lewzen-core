#include "canvas_coordinate.h"

namespace Lewzen {
    CanvasCoordinate::CanvasCoordinate(): {
        new (this)Coordinate("CAN");
    }
    bool CanvasCoordinate::operator== (const Coordinate &coordianate) const {
        return A::operator==(coordianate)
    }
    bool CanvasCoordinate::operator!= (const Coordinate &coordianate) const {
        return !A::operator==(coordianate)
    }
    Point2D from_canvas(const Point2D &p) const {
       if (p.get_coordinate().get_type() != "CAN") {
            throw "Point is not in canvas coordinate";
        }
        return p;
    }
    Point2D to_canvas(const Point2D &p) const {
        if (p.get_coordinate() != *this) {
            throw "Point is not in this coordinate";
        }
        return p;
    }
}