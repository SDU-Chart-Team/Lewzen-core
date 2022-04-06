#include "component_relative_coordinate_system.h"

namespace Lewzen {
    ComponentRelativeCoordinateSystem::ComponentRelativeCoordinateSystem(const std::shared_ptr<Component> &component): _component(component) {
        new (this)CoordinateSystem("COMR");
    }
    const std::shared_ptr<Component> &ComponentRelativeCoordinateSystem::get_component() const {
        return _component;
    }
    bool ComponentRelativeCoordinateSystem::operator== (const CoordinateSystem &coordinate_system) const {
        if (!A::operator==(coordinate)) return false;
        return _component == static_cast<const ComponentRelativeCoordinateSystem &>(coordinate).get_component();
    }
    bool ComponentRelativeCoordinateSystem::operator!= (const CoordinateSystem &coordinate_system) const {
        if (A::operator==(coordinate)) return false;
        return !_component == static_cast<const ComponentRelativeCoordinateSystem &>(coordinate).get_component();
    }
    Point2D to_absolute(const Point2D &p) const {
        
    }
    Point2D from_canvas(const Point2D &p) const override {

    }
    Point2D to_canvas(const Point2D &p) const override {

    }
}