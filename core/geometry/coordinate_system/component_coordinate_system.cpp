#include "component_coordinate_system.h"

namespace Lewzen {
    ComponentCoordinateSystem::ComponentCoordinateSystem(const std::weak_ptr<ComponentRotatable> &component): _component(component) {
        new (this)CoordinateSystem("COM");
    }
    ComponentCoordinateSystem::ComponentCoordinateSystem(const ComponentCoordinateSystem &coordinate_system): _component(coordinate_system.get_component()) {
        new (this)CoordinateSystem("COM");
    }
    const std::weak_ptr<ComponentRotatable> ComponentCoordinateSystem::get_component() const {
        return _component;
    }
    std::shared_ptr<CoordinateSystem> ComponentCoordinateSystem::clone() const {
        return std::make_shared<ComponentCoordinateSystem>(*this);
    }
    bool ComponentCoordinateSystem::operator==(const CoordinateSystem &coordinate_system) const {
        if (!CoordinateSystem::operator==(coordinate_system)) return false;
        auto __component = static_cast<const ComponentCoordinateSystem &>(coordinate_system).get_component();
        return !(_component.owner_before(__component) || __component.owner_before(_component));
    }
    bool ComponentCoordinateSystem::operator!=(const CoordinateSystem &coordinate_system) const {
        if (CoordinateSystem::operator==(coordinate_system)) return false;
        auto __component = static_cast<const ComponentCoordinateSystem &>(coordinate_system).get_component();
        return _component.owner_before(__component) || __component.owner_before(_component);
    }
    Point2D ComponentCoordinateSystem::to_relative(const Point2D &p) const { // TO BE CONTINUE
        return p;
    }
    Point2D ComponentCoordinateSystem::from_canvas(const Point2D &p) const {
        return p;
    }
    Point2D ComponentCoordinateSystem::to_canvas(const Point2D &p) const {
        return p;
    }
}