#ifndef __LZ_COORDINATE__
#define __LZ_COORDINATE__
#include <string>
#include <memory>
#include <stdexcept>
#include "point.h"

namespace Lewzen {
    class Point2D;
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
        CoordinateSystem(const std::string &coordinate_system_type);
        /**
        * Deep copy of coordinate system.
        */
        CoordinateSystem(const CoordinateSystem &coordinate_system);

        /**
        * Get coordinate system type.
        *
        * @return coordinate system type.
        */
        const std::string get_type() const;
        /**
        * Deep copy of coordinate system.
        *
        * @relatesalso CoordinateSystem
        */
        virtual std::shared_ptr<CoordinateSystem> clone() const;
        /**
        * Compare two coordinate systems.
        *
        * @relatesalso CoordinateSystem
        */
        virtual bool operator==(const CoordinateSystem &coordinate_system) const;
        friend bool operator==(const std::shared_ptr<CoordinateSystem> &c1, const CoordinateSystem &c2);
        friend bool operator==(const CoordinateSystem &c1, const std::shared_ptr<CoordinateSystem> &c2);
        friend bool operator==(const std::shared_ptr<CoordinateSystem> &c1, const std::shared_ptr<CoordinateSystem> &c2);
        /**
        * Compare two coordinate systems.
        *
        * @relatesalso CoordinateSystem
        */
        virtual bool operator!=(const CoordinateSystem &coordinate_system) const;
        friend bool operator!=(const std::shared_ptr<CoordinateSystem> &c1, const CoordinateSystem &c2);
        friend bool operator!=(const CoordinateSystem &c1, const std::shared_ptr<CoordinateSystem> &c2);
        friend bool operator!=(const std::shared_ptr<CoordinateSystem> &c1, const std::shared_ptr<CoordinateSystem> &c2);
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
    public:
        coordinate_system_mismatch();
        coordinate_system_mismatch(const std::string &str);
        virtual char const* what() const noexcept override;
    };
}

#include "coordinate_system/canvas_coordinate_system.h"
#include "coordinate_system/component_coordinate_system.h"
#include "coordinate_system/component_relative_coordinate_system.h"
#include "coordinate_system/point_coordinate_system.h"
#include "coordinate_system/point_relative_coordinate_system.h"
#include "coordinate_system/vector_coordinate_system.h"
#include "coordinate_system/vector_relative_coordinate_system.h"
#endif
