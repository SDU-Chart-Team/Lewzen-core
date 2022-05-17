#include "component_relative_coordinate_system.h"

namespace Lewzen {
    ComponentRelativeCoordinateSystem::ComponentRelativeCoordinateSystem(const std::weak_ptr<const ComponentRotatable> &component): CoordinateSystem("COMR"), _component(component) {}
    ComponentRelativeCoordinateSystem::ComponentRelativeCoordinateSystem(const ComponentRelativeCoordinateSystem &coordinate_system): CoordinateSystem("COMR"), _component(coordinate_system.get_component()) {}
    const std::weak_ptr<const ComponentRotatable> ComponentRelativeCoordinateSystem::get_component() const {
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
    Point2D ComponentRelativeCoordinateSystem::to_absolute(const Point2D &p) const {
        if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        if (auto sp = _component.lock()) {
            auto &p1 = sp->get_rotate_center();
            auto &p2 = sp->get_area_vertex();
            double dx = p2.get_x() - p1.get_x(), dy = p2.get_y() - p1.get_y();
            return Point2D(p.get_x() * dx, p.get_y() * dy, std::make_shared<ComponentRelativeCoordinateSystem>(sp));
        }
        throw std::runtime_error("Null pointer when converting ComponentRelativeCoordinateSystem to ComponentCoordinateSystem");
    }
    Point2D ComponentRelativeCoordinateSystem::from_canvas(const Point2D &p) const {
        if (p.get_coordinate_system()->get_type() != "CAN") {
            throw coordinate_system_mismatch("Point is not in canvas coordinate system");
        }
        if (auto sp = _component.lock()) {
            Point2D pf = sp->from_canvas(p);
            auto ccs = std::static_pointer_cast<ComponentCoordinateSystem>(pf.get_coordinate_system());
            return ccs->to_relative(pf);
        }
        throw std::runtime_error("Null pointer when converting CanvasCoordinateSystem to ComponentRelativeCoordinateSystem");
    }
    Point2D ComponentRelativeCoordinateSystem::to_canvas(const Point2D &p) const {
        if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        if (auto sp = _component.lock()) {
            auto crcs = std::static_pointer_cast<ComponentRelativeCoordinateSystem>(p.get_coordinate_system());
            return sp->to_canvas(crcs->to_absolute(p));
        }
        throw std::runtime_error("Null pointer when converting ComponentRelativeCoordinateSystem to CanvasCoordinateSystem");
    }
}