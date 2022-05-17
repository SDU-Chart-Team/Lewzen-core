#ifndef __LZ_COMPONENT_COORDINATE__
#define __LZ_COMPONENT_COORDINATE__
#include <string>
#include <memory>
#include "../coordinate_system.h"
#include "../component_rotatable.h"

namespace Lewzen {
    class ComponentRotatable;
    /**
    * Component coordinate system information.
    */
    class ComponentCoordinateSystem: public CoordinateSystem {
    private:
        // component
        std::weak_ptr<const ComponentRotatable> _component;
    public:
        /**
        * Constructor of ComponentCoordinateSystem. Unit is equal to CanvasCoordinateSystem.
        *
        * @param component the component of component coordinate system.
        */
        ComponentCoordinateSystem(const std::weak_ptr<const ComponentRotatable> &component);
        /**
        * Deep copy of this coordinate system.
        */
        ComponentCoordinateSystem(const ComponentCoordinateSystem &coordinate_system);
        /**
        * Get component of ComponentCoordinateSystem.
        *
        * @return the component of component coordinate system.
        */
        const std::weak_ptr<const ComponentRotatable> get_component() const;
        /**
        * Deep copy of this coordinate system.
        *
        * @relatesalso CoordinateSystem
        */
        std::shared_ptr<CoordinateSystem> clone() const override;
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
        * Get point in corresponding relative coordinate system.
        *
        * @return point in corresponding relative coordinate system.
        */
        Point2D to_relative(const Point2D &p) const;
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