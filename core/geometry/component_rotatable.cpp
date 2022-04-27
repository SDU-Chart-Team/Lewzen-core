#include "component_rotatable.h"

namespace Lewzen {
    const std::string ComponentRotatable::get_rotate() {
        return _rotate_trans;
    }
    
    ComponentRotatable::ComponentRotatable() {}
    ComponentRotatable::ComponentRotatable(const std::weak_ptr<SVGIElement> &svg_element_interface, const std::weak_ptr<Point2D> &rotate_center):
        _svg_element_interface(svg_element_interface), _rotate_center(rotate_center) {}

    double ComponentRotatable::get_theta() const {
        return _theta;
    }
    void ComponentRotatable::set_theta(double theta) {
        _theta = theta;
    }
    const std::weak_ptr<Point2D> ComponentRotatable::get_rotate_center() const {
        return _rotate_center;
    }
    void ComponentRotatable::set_rotate_center(const std::weak_ptr<Point2D> &rotate_center) {
        if (auto sp = rotate_center.lock()) {
            if (sp->get_coordinate_system().get_type() != "CAN") throw coordinate_system_mismatch("Rotate center must be in ComponentCoordinateSystem");
            _rotate_center = rotate_center;
        } else {
            throw std::runtime_error("Null pointer when setting rotate center");
        }
    }
    const std::weak_ptr<SVGIElement> ComponentRotatable::get_svg_element_interface() const {
        return _svg_element_interface;
    }
    void ComponentRotatable::set_svg_element_interface(const std::weak_ptr<SVGIElement> &svg_element_interface) {
        _svg_element_interface = svg_element_interface;
    }

    void ComponentRotatable::update_transform() {
        auto sp1 = _svg_element_interface.lock();
        auto sp2 = get_parent().lock();
        auto sp3 = _rotate_center.lock();
        if (sp1 && sp2 && sp3) {
            auto _parent_trans = sp2->get_rotate();
            if (_parent_trans != STR_NULL) _parent_trans.push_back(' ');
            _rotate_trans = _parent_trans + "rotate(" + std::to_string(_theta) + "rad, " + std::to_string(sp3->get_x()) + ", " + std::to_string(sp3->get_y()) + ")";
            sp1->Transform = _rotate_trans;
        }
    }
}