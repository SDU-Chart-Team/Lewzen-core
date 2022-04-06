#include <string>
#include <memory>
#include "../coordinate_system.h"
#include "../../component.h"
#ifndef __LZ_COMPONENT_COORDINATE__
#define __LZ_COMPONENT_COORDINATE__

namespace Lewzen {
    /**
    * Component coordinate system information.
    */
    class ComponentCoordinateSystem: public CoordinateSystem {
    private:
        // component
        std::shared_ptr<Component> _component;
    public:
        /**
        * Constructor of ComponentCoordinateSystem. Unit is equal to CanvasCoordinateSystem.
        *
        * @param component the component of component coordinate system.
        */
        ComponentCoordinateSystem(const std::shared_ptr<Component> &component);
        /**
        * Get component of ComponentCoordinateSystem.
        *
        * @return the component of component coordinate system.
        */
        const std::shared_ptr<Component> &get_component() const;
        /**
        * Compare two coordinate systems.
        *
        * @relatesalso CoordinateSystem
        */
        bool operator== (const CoordinateSystem &coordianate_system) const override;
        /**
        * Compare two coordinate systems.
        *
        * @relatesalso CoordinateSystem
        */
        bool operator!= (const CoordinateSystem &coordianate_system) const override;
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
        */
        Point2D from_canvas(const Point2D &p) const override;
        /**
        * Convert a point in this coordinate system to CanvasCoordinateSystem.
        *
        * @param p a point in this coordinate system.
        * @return a point in CanvasCoordinateSystem.
        */
        Point2D to_canvas(const Point2D &p) const override;
    };
}