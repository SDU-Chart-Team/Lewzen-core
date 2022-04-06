#include <string>
#include "point.h"
#ifndef __LZ_COORDINATE__
#define __LZ_COORDINATE__

namespace Lewzen {
    /**
    * Coordinate system information.
    */
    class CoordinateSystem {
    private:
        // coordinate system type
        std::string _coordinate_system_type;
    public:
        /**
        * Empty constructor of coordinate system.
        */
        CoordinateSystem();
        /**
        * Constructor of coordinate system.
        *
        * @param coordinate system_type coordinate system type.
        */
        CoordinateSystem(const std::string &coordinate system_type);
        /**
        * Get coordinate system type.
        *
        * @return coordinate system type.
        */
        const std::string &get_type() const;
        /**
        * Compare two coordinate systems.
        *
        * @relatesalso CoordinateSystem
        */
        virtual bool operator== (const CoordinateSystem &coordinate_system) const;
        /**
        * Compare two coordinate systems.
        *
        * @relatesalso CoordinateSystem
        */
        virtual bool operator!= (const CoordinateSystem &coordinate_system) const;
        /**
        * Convert a point in CanvasCoordinateSystem to this coordinate system.
        *
        * @param p a point in CanvasCoordinateSystem.
        * @return a point in this coordinate system.
        * @throws Lewzen::coordinate_system_mismatch: thrown if point p is not in CanvasCoordinateSystem.
        */
        virtual Point2D from_canvas(const Point2D &p) const;
        /**
        * Convert a point in this coordinate system to CanvasCoordinateSystem.
        *
        * @param p a point in this coordinate system.
        * @return a point in CanvasCoordinateSystem.
        * @throws Lewzen::coordinate_system_mismatch: thrown if point p is not in this coordinate system.
        */
        virtual Point2D to_canvas(const Point2D &p) const;
    };

    /**
    * Coordinate system mismatch exception.
    */
    class coordinate_system_mismatch: public std::logic_error
    {
    private:
        std::string _message;
    public:
        coordinate_system_mismatch();
        coordinate_system_mismatch(const std::string &str);
        virtual char const* what() const noexcept override;
    };
}
#endif