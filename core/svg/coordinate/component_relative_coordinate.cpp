#include "component_relative_coordinate.h"

namespace Lewzen {
    ComponentRelativeCoordinate::ComponentRelativeCoordinate(const std::shared_ptr<Component> &component): _component(component) {
        new (this)Coordinate("COMR");
    }
    const std::shared_ptr<Component> &ComponentRelativeCoordinate::get_component() const {
        return _component;
    }
    bool ComponentRelativeCoordinate::operator== (const Coordinate &coordianate) const {
        if (!A::operator==(coordianate)) return false;
        return _component == static_cast<const ComponentRelativeCoordinate &>(coordianate).get_component();
    }
    bool ComponentRelativeCoordinate::operator!= (const Coordinate &coordianate) const {
        if (A::operator==(coordianate)) return false;
        return !_component == static_cast<const ComponentRelativeCoordinate &>(coordianate).get_component();
    }
    Point2D to_absolute(const Point2D &p) const {
        
    }
    Point2D from_canvas(const Point2D &p) const {

    }
    Point2D to_canvas(const Point2D &p) const {

    }
}