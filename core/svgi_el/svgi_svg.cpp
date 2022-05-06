#include "svgi_svg.h"

namespace Lewzen {
    SVGISvg::SVGISvg(): SVGIElement() { SVGISvg::_bind_getter_setter(); }
    void SVGISvg::_bind_getter_setter() {
        std::function<const std::string()> _getter_x = std::bind(&SVGSvg::get_x, (SVGSvg *)this);
        std::function<void(const std::string &)> _setter_x = std::bind(&SVGSvg::set_x, (SVGSvg *)this, std::placeholders::_1);
        X.set_getter(_getter_x), X.set_setter(_setter_x);
        X.callback_assign(_attr_on_assign[0]), X.callback_bind_func(_attr_on_bind[0]), X.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_y = std::bind(&SVGSvg::get_y, (SVGSvg *)this);
        std::function<void(const std::string &)> _setter_y = std::bind(&SVGSvg::set_y, (SVGSvg *)this, std::placeholders::_1);
        Y.set_getter(_getter_y), Y.set_setter(_setter_y);
        Y.callback_assign(_attr_on_assign[1]), Y.callback_bind_func(_attr_on_bind[1]), Y.callback_bind_ptr(_attr_on_bind[1]);
        std::function<const std::string()> _getter_width = std::bind(&SVGSvg::get_width, (SVGSvg *)this);
        std::function<void(const std::string &)> _setter_width = std::bind(&SVGSvg::set_width, (SVGSvg *)this, std::placeholders::_1);
        Width.set_getter(_getter_width), Width.set_setter(_setter_width);
        Width.callback_assign(_attr_on_assign[2]), Width.callback_bind_func(_attr_on_bind[2]), Width.callback_bind_ptr(_attr_on_bind[2]);
        std::function<const std::string()> _getter_height = std::bind(&SVGSvg::get_height, (SVGSvg *)this);
        std::function<void(const std::string &)> _setter_height = std::bind(&SVGSvg::set_height, (SVGSvg *)this, std::placeholders::_1);
        Height.set_getter(_getter_height), Height.set_setter(_setter_height);
        Height.callback_assign(_attr_on_assign[3]), Height.callback_bind_func(_attr_on_bind[3]), Height.callback_bind_ptr(_attr_on_bind[3]);
        std::function<const std::string()> _getter_preserve_aspect_ratio = std::bind(&SVGSvg::get_preserve_aspect_ratio, (SVGSvg *)this);
        std::function<void(const std::string &)> _setter_preserve_aspect_ratio = std::bind(&SVGSvg::set_preserve_aspect_ratio, (SVGSvg *)this, std::placeholders::_1);
        PreserveAspectRatio.set_getter(_getter_preserve_aspect_ratio), PreserveAspectRatio.set_setter(_setter_preserve_aspect_ratio);
        PreserveAspectRatio.callback_assign(_attr_on_assign[4]), PreserveAspectRatio.callback_bind_func(_attr_on_bind[4]), PreserveAspectRatio.callback_bind_ptr(_attr_on_bind[4]);
        std::function<const std::string()> _getter_view_box = std::bind(&SVGSvg::get_view_box, (SVGSvg *)this);
        std::function<void(const std::string &)> _setter_view_box = std::bind(&SVGSvg::set_view_box, (SVGSvg *)this, std::placeholders::_1);
        ViewBox.set_getter(_getter_view_box), ViewBox.set_setter(_setter_view_box);
        ViewBox.callback_assign(_attr_on_assign[5]), ViewBox.callback_bind_func(_attr_on_bind[5]), ViewBox.callback_bind_ptr(_attr_on_bind[5]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGISvg::get_tag() const {
        return "svg";
    }
    const std::string SVGISvg::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGISvg::commit() {
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
    std::shared_ptr<SVGElement> SVGISvg::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGISvg> SVGISvg::clone(bool identity) const {
        auto cloned = std::make_shared<SVGISvg>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGISvg::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGISvg &SVGISvg::operator=(const SVGISvg &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));
        X = element.X;
        Y = element.Y;
        Width = element.Width;
        Height = element.Height;
        PreserveAspectRatio = element.PreserveAspectRatio;
        ViewBox = element.ViewBox;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGISvg::operator-(const SVGElement &element) const {
        return SVGSvg::operator-(element);
    }
}
