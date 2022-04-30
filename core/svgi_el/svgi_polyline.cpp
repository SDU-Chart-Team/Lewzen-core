#include "svgi_polyline.h"

namespace Lewzen {
    SVGIPolyline::SVGIPolyline(): SVGIElement() {}
    void SVGIPolyline::_bind_getter_setter() {
        std::function<const std::string()> _getter_points = std::bind(&SVGPolyline::get_points, (SVGPolyline *)this);
        std::function<void(const std::string &)> _setter_points = std::bind(&SVGPolyline::set_points, (SVGPolyline *)this, std::placeholders::_1);
        Points.set_getter(_getter_points), Points.set_setter(_setter_points);
        Points.callback_assign(_attr_on_assign[0]), Points.callback_bind_func(_attr_on_bind[0]), Points.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_path_length = std::bind(&SVGPolyline::get_path_length, (SVGPolyline *)this);
        std::function<void(const std::string &)> _setter_path_length = std::bind(&SVGPolyline::set_path_length, (SVGPolyline *)this, std::placeholders::_1);
        PathLength.set_getter(_getter_path_length), PathLength.set_setter(_setter_path_length);
        PathLength.callback_assign(_attr_on_assign[1]), PathLength.callback_bind_func(_attr_on_bind[1]), PathLength.callback_bind_ptr(_attr_on_bind[1]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIPolyline::get_tag() const {
        return "polyline";
    }
    const std::string SVGIPolyline::inner_SVG() const {
        return SVGIElement::inner_SVG();
    }
    void SVGIPolyline::set_inner_text(const std::string &text) {
        SVGIElement::set_inner_text(text);
    }
    const std::string SVGIPolyline::get_inner_text() const {
        return SVGIElement::get_inner_text();
    }
    void SVGIPolyline::append(const std::shared_ptr<SVGIElement> &inner_element) {
        SVGIElement::add_inner_element(inner_element);
    }
    void SVGIPolyline::remove(const std::shared_ptr<SVGIElement> &inner_element, bool remove_all) {
        SVGIElement::remove_inner_element(inner_element, remove_all);
    }
    const std::vector<std::shared_ptr<SVGIElement>> SVGIPolyline::get_inner_elements() const {
        return SVGIElement::get_inner_elements();
    }
    void SVGIPolyline::set_inner_elements(const std::vector<std::shared_ptr<SVGIElement>> &inner_elements) {
        SVGIElement::set_inner_elements(inner_elements);
    }
    const std::string SVGIPolyline::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGIPolyline::commit() {
        std::stringstream ss;

        // attribute differ
        for (auto &i : bound) ss << _attr_commit[i]() << std::endl;
        for (auto &i : modified) ss << _attr_commit[i]() << std::endl;
        modified.clear();

        // base class
        ss << SVGIElement::commit();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGIPolyline::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGIPolyline> SVGIPolyline::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIPolyline>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGIPolyline::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGIPolyline &SVGIPolyline::operator=(const SVGIPolyline &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));
        Points = element.Points;
        PathLength = element.PathLength;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIPolyline::operator-(const SVGElement &element) const {
        return SVGPolyline::operator-(element);
    }
}
