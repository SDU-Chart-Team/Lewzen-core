#include "component_relative_coordinate_system.h"

namespace Lewzen {
    ComponentRelativeCoordinateSystem::ComponentRelativeCoordinateSystem(const std::weak_ptr<ComponentRotatable> &component): _component(component) {
        new (this)CoordinateSystem("COMR");
    }
    ComponentRelativeCoordinateSystem::ComponentRelativeCoordinateSystem(const ComponentRelativeCoordinateSystem &coordinate_system): _component(coordinate_system.get_component()) {
        new (this)CoordinateSystem("COMR");
    }
    const std::weak_ptr<ComponentRotatable> ComponentRelativeCoordinateSystem::get_component() const {
        return _component;
    }
    std::shared_ptr<CoordinateSystem> ComponentRelativeCoordinateSystem::clone() const {
        return std::make_shared<ComponentRelativeCoordinateSystem>(*this);
    }
    bool ComponentRelativeCoordinateSystem::operator==(const CoordinateSystem &coordinate_system) const {
        if (!CoordinateSystem::operator==(coordinate_system)) return false;
        auto __component = static_cast<const ComponentRelativeCoordinateSystem &>(coordinate_system).get_component();
        return !(_component.owner_before(__component) || __component.owner_before(_component));
    }
    bool ComponentRelativeCoordinateSystem::operator!=(const CoordinateSystem &coordinate_system) const {
        if (CoordinateSystem::operator==(coordinate_system)) return false;
        auto __component = static_cast<const ComponentRelativeCoordinateSystem &>(coordinate_system).get_component();
        return _component.owner_before(__component) || __component.owner_before(_component);
    }
    Point2D ComponentRelativeCoordinateSystem::to_absolute(const Point2D &p) const { // TO BE CONTINUE
        return p;
    }
    Point2D ComponentRelativeCoordinateSystem::from_canvas(const Point2D &p) const {
        return p;
    }
    Point2D ComponentRelativeCoordinateSystem::to_canvas(const Point2D &p) const {
        return p;
    }
}