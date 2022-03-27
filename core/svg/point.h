#include <string>
#include "coordinate.h"
#ifndef __LZ_POINT__
#define __LZ_POINT__

namespace Lewzen {
    class Point2D {
    private:
        double _x, _y;
        Coordinate _coordinate;
    public:
        Point2D(const double &x, const double &y);
        Point2D(const double &x, const double &y, const Coordinate &coordinate);
        const Coordinate &get_coordinate();
        double get_x();
        void set_x(const double &x);
        double get_y();
        void set_y(const double &y);
    };

    class Point2DFunction {
    public:
        Point2D operator() (const Point2D &point);
    };

    class Point2DTransform: public Point2DFunction {
        Point2D operator() (const Point2D &point, const bool &reversed);
    };
}
#endif