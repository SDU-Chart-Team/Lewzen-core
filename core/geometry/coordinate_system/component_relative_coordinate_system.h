#ifndef __LZ_COMPONENT_RELATIVE_COORDINATE__
#define __LZ_COMPONENT_RELATIVE_COORDINATE__
#include <string>
#include <memory>
#include "../coordinate_system.h"
#include "../component_rotatable.h"

namespace Lewzen {
    class ComponentRotatable;
    /**
    * Component relative coordinate system information.
    */
    class ComponentRelativeCoordinateSystem: public CoordinateSystem {
    private:
        // component
        std::weak_ptr<const ComponentRotatable> _component;
    public:
        /**
        * Constructor of ComponentRelativeCoordinateSystem. Top-left and bottom-right of component's box is (-1, -1) to (1, 1).
        *
        * @param component the component of component relative coordinate system.
        */
        ComponentRelativeCoordinateSystem(const std::weak_ptr<const ComponentRotatable> &component);
        /**
        * Deep copy of this coordinate system.
        */
        ComponentRelativeCoordinateSystem(const ComponentRelativeCoordinateSystem &coordinate_system);
        /**
        * Get component of ComponentRelativeCoordinateSystem.
        *
        * @return the component of component relative coordinate system.
        */
        const std::weak_ptr<const ComponentRotatable> get_component() const;
        /**
        * Deep copy of this coordinate system.
        *
        * @relatesalso CoordinateSystem
        */
        std::shared_ptr<CoordinateSystem> clone() const;
        /**
        * Compare two coordinate systems.
        *
        * @relatesalso CoordinateSystem
        */
        bool operator==(const CoordinateSystem &coordinate_system) const override;
        /**
        * Compare two coordinate systems.
        *
        * @relatesalso CoordinateSystem
        */
        bool operator!=(const CoordinateSystem &coordinate_system) const override;
        /**
        * Get point in corresponding absolute coordinate system.
        *
        * @return point in corresponding absolute coordinate system.
        */
        Point2D to_absolute(const Point2D &p) const;
        /**
        * Convert a point in CanvasCoordinateSystem to this coordinate system.
        *
        * @param p a point in CanvasCoordinateSystem.
        * @return a point in this coordinate system.
        * @throws Lewzen::coordinate_system_mismatch: thrown if point p is not in CanvasCoordinateSystem.
        */
        Point2D from_canvas(const Point2D &p) const override;
        /**
        * Convert a point in this coordinate system to CanvasCoordinateSystem.
        *
        * @param p a point in this coordinate system.
        * @return a point in CanvasCoordinateSystem.
        * @throws Lewzen::coordinate_system_mismatch: thrown if point p is not in this coordinate system.
        */
        Point2D to_canvas(const Point2D &p) const override;
    };
}
#endif