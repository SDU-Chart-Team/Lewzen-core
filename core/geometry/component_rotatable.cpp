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
    const Point2D ComponentRotatable::get_rotate_center() const {
        if (!_rotate_center) return Point2D(0, 0, get_coordinate_system());
        return *_rotate_center;
    }
    void ComponentRotatable::set_rotate_center(const Point2D &rotate_center) {
        if (!_rotate_center) _rotate_center = std::make_shared<Point2D>(0, 0, get_coordinate_system());
        if (rotate_center.get_coordinate_system() != get_coordinate_system()) throw coordinate_system_mismatch("Rotate center must be in this ComponentCoordinateSystem");
        *_rotate_center = rotate_center;
    }
    void ComponentRotatable::set_rotate_center(const double &x, const double &y) {
        if (!_rotate_center) _rotate_center = std::make_shared<Point2D>(0, 0, get_coordinate_system());
        _rotate_center->set_x(x);
        _rotate_center->set_y(y);
    }
    const Point2D ComponentRotatable::get_area_vertex() const {
        if (!_rotate_center) return Point2D(0, 0, get_coordinate_system());
        return *_area_vertex;
    }
    void ComponentRotatable::set_area_vertex(const Point2D &area_vertex) {
        if (!_area_vertex) _area_vertex = std::make_shared<Point2D>(0, 0, get_coordinate_system());
        if (area_vertex.get_coordinate_system()  != get_coordinate_system()) throw coordinate_system_mismatch("Area vertex must be in this ComponentCoordinateSystem");
        *_area_vertex = area_vertex;
    }
    void ComponentRotatable::set_area_vertex(const double &x, const double &y) {
        if (!_area_vertex) _area_vertex = std::make_shared<Point2D>(0, 0, get_coordinate_system());
        _area_vertex->set_x(x);
        _area_vertex->set_y(y);
    }
    const std::weak_ptr<SVGIElement> ComponentRotatable::get_svg_element_interface() const {
        return _svg_element_interface;
    }
    void ComponentRotatable::set_svg_element_interface(const std::weak_ptr<SVGIElement> &svg_element_interface) {
        _svg_element_interface = svg_element_interface;
    }

    void ComponentRotatable::update_transform() {
        if (!_rotate_center) _rotate_center = std::make_shared<Point2D>(0, 0, get_coordinate_system());
        auto sp1 = _svg_element_interface.lock();
        auto sp2 = get_parent().lock();
        std::string _parent_trans = (sp2) ? sp2->get_rotate() : STR_NULL;
        std::string _this_trans = (_theta != 0) ? ("rotate(" + std::to_string(_theta / 3.141592653589793238462643383279502884L * 180) + ", " + std::to_string(_rotate_center->get_x()) + ", " + std::to_string(_rotate_center->get_y()) + ")") : "";
        _rotate_trans = _parent_trans + (_parent_trans != STR_NULL ? " " : STR_NULL) +  _this_trans;
        if (sp1) sp1->Transform = _rotate_trans;
    }

    Point2D ComponentRotatable::from_canvas(const Point2D &p) const {
        if (p.get_coordinate_system()->get_type() != "CAN") {
            throw coordinate_system_mismatch("Point is not in canvas coordinate system");
        }
        auto pf = create_point(p.get_x(), p.get_y());
        if (auto pp = get_parent().lock()) {
            auto cp = pp->from_canvas(p);
            pf.set_x(cp.get_x()), pf.set_y(cp.get_y());
        }
        return center_rotate(pf, (!_rotate_center) ? Point2D(0, 0, get_coordinate_system()) : *_rotate_center, _theta);
    }
    Point2D ComponentRotatable::to_canvas(const Point2D &p) const {
        if (p.get_coordinate_system() != get_coordinate_system()) {
            throw coordinate_system_mismatch("Point is not in this coordinate system");
        }
        Point2D pf = center_rotate(p, (!_rotate_center) ? Point2D(0, 0, get_coordinate_system()) : *_rotate_center, -_theta);
        if (auto pp = get_parent().lock())return pp->to_canvas(pp->create_point(pf.get_x(), pf.get_y()));
        return canvas_point(pf.get_x(), pf.get_y());
    }

    Point2D ComponentRotatable::create_point() const {
        return create_point(0, 0);
    }
    Point2D ComponentRotatable::create_point(double x, double y) const {
        return Point2D(x, y, get_coordinate_system());
    }
}