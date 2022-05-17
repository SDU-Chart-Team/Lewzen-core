#include "component_coordinate_system.h"
#include "../point_func.h"

namespace Lewzen {
    ComponentCoordinateSystem::ComponentCoordinateSystem(const std::weak_ptr<const ComponentRotatable> &component): CoordinateSystem("COM"), _component(component) {}
    ComponentCoordinateSystem::ComponentCoordinateSystem(const ComponentCoordinateSystem &coordinate_system): CoordinateSystem("COM"), _component(coordinate_system.get_component()) {}
    const std::weak_ptr<const ComponentRotatable> ComponentCoordinateSystem::get_component() const {
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
    Point2D ComponentCoordinateSystem::to_relative(const Point2D &p) const {
        if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        if (auto sp = _component.lock()) {
            auto &p1 = sp->get_rotate_center();
            auto &p2 = sp->get_area_vertex();
            double dx = p2.get_x() - p1.get_x(), dy = p2.get_y() - p1.get_y();
            return Point2D((dx == 0) ? 0 : p.get_x() / dx, (dy == 0) ? 0 : p.get_y() / dy, std::make_shared<ComponentRelativeCoordinateSystem>(sp));
        }
        throw std::runtime_error("Null pointer when converting ComponentCoordinateSystem to ComponentRelativeCoordinateSystem");
    }
    Point2D ComponentCoordinateSystem::from_canvas(const Point2D &p) const {
        if (p.get_coordinate_system()->get_type() != "CAN") {
            throw coordinate_system_mismatch("Point is not in canvas coordinate system");
        }
        if (auto sp = _component.lock()) {
            return sp->from_canvas(p);
        }
        throw std::runtime_error("Null pointer when converting CanvasCoordinateSystem to ComponentCoordinateSystem");
    }
    Point2D ComponentCoordinateSystem::to_canvas(const Point2D &p) const {
        if (p.get_coordinate_system() != *this) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        if (auto sp = _component.lock()) {
            return sp->to_canvas(p);
        }
        throw std::runtime_error("Null pointer when converting ComponentCoordinateSystem to CanvasCoordinateSystem");
    }
}