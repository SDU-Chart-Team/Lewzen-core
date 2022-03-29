#include <string>
#include "coordinate.h"
#ifndef __LZ_POINT__
#define __LZ_POINT__

namespace Lewzen {
    /**
    * A 2D point.
    */
    class Point2D {
    private:
        // position (x, y)
        double _x, _y;
        // corrdiante information
        Coordinate _coordinate;
    public:
        /**
        * Constructor of SVG Element. The coordinate is 'NULL'.
        *
        * @param x x position.
        * @param y y position.
        */
        Point2D(const double &x, const double &y);
        /**
        * Constructor of SVG Element.
        *
        * @param x x position.
        * @param y y position.
        * @param coordinate coordinate information.
        */
        Point2D(const double &x, const double &y, const Coordinate &coordinate);

        /// Property
        /**
        * Get coordinate information.
        *
        * @return coordinate information.
        */
        const Coordinate &get_coordinate();
        /**
        * Get x position.
        *
        * @return x position.
        */
        double get_x();
        /**
        * Set x position.
        *
        * @param x x position.
        */
        void set_x(const double &x);
        /**
        * Get y position.
        *
        * @return y position.
        */
        double get_y();
        /**
        * Set y position.
        *
        * @param x y position.
        */
        void set_y(const double &y);
        /**
        * Move (x, y) to (x + dx, y + dy).
        *
        * @param dx delta x.
        * @param dy delta y.
        */
        void move(const double &dx, const double &dy);

        /**
        * Convert this point to another coordianate.
        *
        * @relatesalso Coordinate
        */
        Point2D operator() (const Coordinate &coordinate);
        /**
        * Assign another point to this point and do coordinate conversion automatically .
        *
        * @relatesalso Coordinate
        */
        Point2D& operator=(const Point2D& point);
    };
}
#endif