#include "component_rotatable.h"

namespace Lewzen {
    const std::string ComponentRotatable::get_rotate() const {
        return _rotate_trans;
    }
    
    ComponentRotatable::ComponentRotatable() {}
    ComponentRotatable::ComponentRotatable(const std::weak_ptr<SVGIElement> &svg_element_interface): _svg_element_interface(svg_element_interface) {}

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
            if (sp->get_coordinate_system() != get_coordinate_system()) throw coordinate_system_mismatch("Rotate center must be in this ComponentCoordinateSystem");
            _rotate_center = rotate_center;
        } else {
            throw std::runtime_error("Null pointer when setting rotate center");
        }
    }
    const std::weak_ptr<Point2D> ComponentRotatable::get_area_vertex() const {
        return _area_vertex;
    }
    void ComponentRotatable::set_area_vertex(const std::weak_ptr<Point2D> &area_vertex) {
        if (auto sp = area_vertex.lock()) {
            if (sp->get_coordinate_system()  != get_coordinate_system()) throw coordinate_system_mismatch("Area vertex must be in this ComponentCoordinateSystem");
            _area_vertex = area_vertex;
        } else {
            throw std::runtime_error("Null pointer when setting area vertex");
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

    Point2D ComponentRotatable::from_canvas(const Point2D &p) const {
        if (p.get_coordinate_system().get_type() != "CAN") {
            throw coordinate_system_mismatch("Point is not in canvas coordinate system");
        }
        auto sp1 = _rotate_center.lock();
        auto sp2 = _area_vertex.lock();
        if (sp1 && sp2) {
            Point2D pf = p;
            if (auto pp = get_parent().lock()) pf = pp->from_canvas(p);
            pf = create_point(pf.get_x(), pf.get_y());
            return center_rotate(pf, *sp1, _theta);
        }
        throw std::runtime_error("Null pointer when converting CanvasCoordinateSystem to ComponentCoordinateSystem");
    }
    Point2D ComponentRotatable::to_canvas(const Point2D &p) const {
        if (p.get_coordinate_system() != get_coordinate_system()) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        auto sp1 = _rotate_center.lock();
        auto sp2 = _area_vertex.lock();
        if (sp1 && sp2) {
            Point2D pf = center_rotate(p, *sp1, -_theta);
            if (auto pp = get_parent().lock()) return pp->to_canvas(pp->create_point(pf.get_x(), pf.get_y()));
            return Point2D(pf.get_x(), pf.get_y(), CanvasCoordinateSystem());
        }
        throw std::runtime_error("Null pointer when converting CanvasCoordinateSystem to ComponentCoordinateSystem");
    }

    const CoordinateSystem ComponentRotatable::get_coordinate_system() const {
        return ComponentCoordinateSystem(shared_from_this());
    }
    Point2D ComponentRotatable::create_point() const {
        return create_point(0, 0);
    }
    Point2D ComponentRotatable::create_point(double x, double y) const {
        return Point2D(x, y, get_coordinate_system());
    }
}