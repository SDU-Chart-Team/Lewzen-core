#include "svgi_polygon.h"

namespace Lewzen {
    SVGIPolygon::SVGIPolygon(): SVGIElement() { SVGIPolygon::_bind_getter_setter(); }
    void SVGIPolygon::_bind_getter_setter() {
        std::function<const std::string()> _getter_points = std::bind(&SVGPolygon::get_points, (SVGPolygon *)this);
        std::function<void(const std::string &)> _setter_points = std::bind(&SVGPolygon::set_points, (SVGPolygon *)this, std::placeholders::_1);
        Points.set_getter(_getter_points), Points.set_setter(_setter_points);
        Points.callback_assign(_attr_on_assign[0]), Points.callback_bind_func(_attr_on_bind[0]), Points.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_path_length = std::bind(&SVGPolygon::get_path_length, (SVGPolygon *)this);
        std::function<void(const std::string &)> _setter_path_length = std::bind(&SVGPolygon::set_path_length, (SVGPolygon *)this, std::placeholders::_1);
        PathLength.set_getter(_getter_path_length), PathLength.set_setter(_setter_path_length);
        PathLength.callback_assign(_attr_on_assign[1]), PathLength.callback_bind_func(_attr_on_bind[1]), PathLength.callback_bind_ptr(_attr_on_bind[1]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIPolygon::get_tag() const {
        return "polygon";
    }
    const std::string SVGIPolygon::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGIPolygon::commit() {
        std::stringstream ss;

        // attribute differ
        for (auto &i : bound) {
            auto &cmd = _attr_commit[i]();
            if (cmd != STR_NULL) ss << cmd  << std::endl;
        }
        for (auto &i : modified) {
            auto &cmd = _attr_commit[i]();
            if (cmd != STR_NULL) ss << cmd  << std::endl;
        }
        modified.clear();

        // base class
        ss << SVGIElement::commit();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGIPolygon::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGIPolygon> SVGIPolygon::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIPolygon>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGIPolygon::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGIPolygon &SVGIPolygon::operator=(const SVGIPolygon &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));
        Points = element.Points;
        PathLength = element.PathLength;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIPolygon::operator-(const SVGElement &element) const {
        return SVGPolygon::operator-(element);
    }
}
