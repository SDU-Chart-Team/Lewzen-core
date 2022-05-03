#include "svgi_stop.h"

namespace Lewzen {
    SVGIStop::SVGIStop(): SVGIElement() { SVGIStop::_bind_getter_setter(); }
    void SVGIStop::_bind_getter_setter() {
        std::function<const std::string()> _getter_offset = std::bind(&SVGStop::get_offset, (SVGStop *)this);
        std::function<void(const std::string &)> _setter_offset = std::bind(&SVGStop::set_offset, (SVGStop *)this, std::placeholders::_1);
        Offset.set_getter(_getter_offset), Offset.set_setter(_setter_offset);
        Offset.callback_assign(_attr_on_assign[0]), Offset.callback_bind_func(_attr_on_bind[0]), Offset.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_stop_color = std::bind(&SVGStop::get_stop_color, (SVGStop *)this);
        std::function<void(const std::string &)> _setter_stop_color = std::bind(&SVGStop::set_stop_color, (SVGStop *)this, std::placeholders::_1);
        StopColor.set_getter(_getter_stop_color), StopColor.set_setter(_setter_stop_color);
        StopColor.callback_assign(_attr_on_assign[1]), StopColor.callback_bind_func(_attr_on_bind[1]), StopColor.callback_bind_ptr(_attr_on_bind[1]);
        std::function<const std::string()> _getter_stop_opacity = std::bind(&SVGStop::get_stop_opacity, (SVGStop *)this);
        std::function<void(const std::string &)> _setter_stop_opacity = std::bind(&SVGStop::set_stop_opacity, (SVGStop *)this, std::placeholders::_1);
        StopOpacity.set_getter(_getter_stop_opacity), StopOpacity.set_setter(_setter_stop_opacity);
        StopOpacity.callback_assign(_attr_on_assign[2]), StopOpacity.callback_bind_func(_attr_on_bind[2]), StopOpacity.callback_bind_ptr(_attr_on_bind[2]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIStop::get_tag() const {
        return "stop";
    }
    const std::string SVGIStop::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGIStop::commit() {
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
    std::shared_ptr<SVGElement> SVGIStop::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGIStop> SVGIStop::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIStop>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGIStop::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGIStop &SVGIStop::operator=(const SVGIStop &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));
        Offset = element.Offset;
        StopColor = element.StopColor;
        StopOpacity = element.StopOpacity;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIStop::operator-(const SVGElement &element) const {
        return SVGStop::operator-(element);
    }
}
