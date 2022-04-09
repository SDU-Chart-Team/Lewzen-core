#include <string>
#include "point.h"
#ifndef __LZ_COORDINATE__
#define __LZ_COORDINATE__

namespace Lewzen {
    /**
    * Coordinate information.
    */
    class Coordinate {
    private:
        // coordinate type
        std::string _coordinate_type;
    public:
        /**
        * Empty constructor of coordinate.
        */
        Coordinate();
        /**
        * Constructor of coordinate.
        *
        * @param coordinate_type coordinate type.
        */
        Coordinate(const std::string &coordinate_type);
        /**
        * Get coordinate type.
        *
        * @return coordinate type.
        */
        const std::string &get_type() const;
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        virtual bool operator== (const Coordinate &coordianate) const;
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        virtual bool operator!= (const Coordinate &coordianate) const;
        /**
        * Convert a point in Canvas Coordinate to this coordinate.
        *
        * @param p a point in Canvas Coordinate.
        * @return a point in this coordinate.
        */
        virtual Point2D from_canvas(const Point2D &p) const;
        /**
        * Convert a point in this coordinate to Canvas Coordinate.
        *
        * @param p a point in this coordinate.
        * @return a point in Canvas Coordinate.
        */
        virtual Point2D to_canvas(const Point2D &p) const;
    };
}
#endif