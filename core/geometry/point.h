#ifndef __LZ_POINT__
#define __LZ_POINT__
#include <string>
#include <memory>
#include <functional>
#include "coordinate_system.h"

namespace Lewzen {
    class CoordinateSystem;
    /**
    * A 2D point.
    */
    class Point2D {
    private:
        // position (x, y)
        double _x, _y;
        // corrdiante information
        std::shared_ptr<CoordinateSystem> _coordinate_system;
        // callback
        std::function<void(const double &, const double &, const double &, const double &)> _callback = [](const double &lx, const double &ly, const double &x, const double &y){};
        const double _epsilon = 1e-6;
        bool _eq(const double &_, const double &__) { double _d =  _ - __; return (_d < 0) ? _d > -_epsilon : _d < _epsilon; }
    public:
        /**
        * Constructor of SVG Element. The coordinate system is 'NULL'.
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
        * @param coordinate system coordinate system information.
        */
        Point2D(const double &x, const double &y, const std::shared_ptr<CoordinateSystem> &coordinate_system);
        /**
        * Deep copy of point.
        */
        Point2D(const Point2D &point);

        /// Property
        /**
        * Get coordinate system information.
        *
        * @return coordinate system information.
        */
        const std::shared_ptr<CoordinateSystem> get_coordinate_system() const;
        /**
        * Get x position.
        *
        * @return x position.
        */
        double get_x() const;
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
        double get_y() const;
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
        * Deep copy of point.
        *
        * @relatesalso Point2D
        */
        virtual std::shared_ptr<Point2D> clone() const;
        /**
        * Compare two points. Compare x, y and coordinate system.
        *
        * @relatesalso Point
        */
        bool operator==(const Point2D &point) const;
        /**
        * Let this point equals to another point. Two points should be in the same coordinate system.
        *
        * @relatesalso Point
        */
        Point2D &operator=(const Point2D &point);
        /**
        * Add another point to this point. Two points should be in the same coordinate system.
        *
        * @relatesalso Point
        */
        Point2D &operator+=(const Point2D &point);
        /**
        * Substract another point from this point. Two points should be in the same coordinate system.
        *
        * @relatesalso Point
        */
        Point2D &operator-=(const Point2D &point);
        /**
        * Point addition. Two points should be in the same coordinate system.
        *
        * @relatesalso Point
        */
        Point2D operator+(const Point2D &point) const;
        /**
        * Point substraction. Two points should be in the same coordinate system.
        *
        * @relatesalso Point
        */
        Point2D operator-(const Point2D &point) const;
        /**
        * Dot. Two points should be in the same coordinate system.
        *
        * @relatesalso Point
        */
        friend double operator*(const Point2D &p1, const Point2D &p2);
        /**
        * Multiplication.
        *
        * @relatesalso Point
        */
        friend Point2D operator*(const double &c, const Point2D &p);
        /**
        * Multiplication.
        *
        * @relatesalso Point
        */
        friend Point2D operator*(const Point2D &p, const double &c);
        /**
        * Convert this point to another coordinate.
        *
        * @relatesalso CoordinateSystem
        */
        Point2D operator() (const std::shared_ptr<CoordinateSystem> &coordinate_system) const;

        /**
        * Set update callback function.
        *
        * @param callback callback function
        */
        void on_update(const std::function<void(const double &, const double &, const double &, const double &)> callback);
        /**
        * Reset update callback function
        */
        void on_update();
    };
}
#endif