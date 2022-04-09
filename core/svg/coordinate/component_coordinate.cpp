#include "component_coordinate.h"

namespace Lewzen {
    ComponentCoordinate::ComponentCoordinate(const std::shared_ptr<Component> &component): _component(component) {
        new (this)Coordinate("COM");
    }
    const std::shared_ptr<Component> &ComponentCoordinate::get_component() const {
        return _component;
    }
    bool ComponentCoordinate::operator== (const Coordinate &coordianate) const {
        if (!A::operator==(coordianate)) return false;
        return _component == static_cast<const ComponentCoordinate &>(coordianate).get_component();
    }
    bool ComponentCoordinate::operator!= (const Coordinate &coordianate) const {
        if (A::operator==(coordianate)) return false;
        return !_component == static_cast<const ComponentCoordinate &>(coordianate).get_component();
    }
    Point2D to_relative(const Point2D &p) const {

    }
    Point2D from_canvas(const Point2D &p) const {

    }
    Point2D to_canvas(const Point2D &p) const {
        
    }
}