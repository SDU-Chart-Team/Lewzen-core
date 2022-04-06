#include "component_coordinate_system.h"

namespace Lewzen {
    ComponentCoordinateSystem::ComponentCoordinateSystem(const std::shared_ptr<Component> &component): _component(component) {
        new (this)CoordinateSystem("COM");
    }
    const std::shared_ptr<Component> &ComponentCoordinateSystem::get_component() const {
        return _component;
    }
    bool ComponentCoordinateSystem::operator== (const CoordinateSystem &coordinate_system) const {
        if (!A::operator==(coordinate)) return false;
        return _component == static_cast<const ComponentCoordinateSystem &>(coordinate).get_component();
    }
    bool ComponentCoordinateSystem::operator!= (const CoordinateSystem &coordinate_system) const {
        if (A::operator==(coordinate)) return false;
        return !_component == static_cast<const ComponentCoordinateSystem &>(coordinate).get_component();
    }
    Point2D to_relative(const Point2D &p) const {

    }
    Point2D from_canvas(const Point2D &p) const override {

    }
    Point2D to_canvas(const Point2D &p) const override {
        
    }
}