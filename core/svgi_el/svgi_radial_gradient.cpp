#include "svgi_radial_gradient.h"

namespace Lewzen {
    SVGIRadialGradient::SVGIRadialGradient(): SVGIElement() { SVGIRadialGradient::_bind_getter_setter(); }
    void SVGIRadialGradient::_bind_getter_setter() {
        std::function<const std::string()> _getter_cx = std::bind(&SVGRadialGradient::get_cx, (SVGRadialGradient *)this);
        std::function<void(const std::string &)> _setter_cx = std::bind(&SVGRadialGradient::set_cx, (SVGRadialGradient *)this, std::placeholders::_1);
        Cx.set_getter(_getter_cx), Cx.set_setter(_setter_cx);
        Cx.callback_assign(_attr_on_assign[0]), Cx.callback_bind_func(_attr_on_bind[0]), Cx.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_cy = std::bind(&SVGRadialGradient::get_cy, (SVGRadialGradient *)this);
        std::function<void(const std::string &)> _setter_cy = std::bind(&SVGRadialGradient::set_cy, (SVGRadialGradient *)this, std::placeholders::_1);
        Cy.set_getter(_getter_cy), Cy.set_setter(_setter_cy);
        Cy.callback_assign(_attr_on_assign[1]), Cy.callback_bind_func(_attr_on_bind[1]), Cy.callback_bind_ptr(_attr_on_bind[1]);
        std::function<const std::string()> _getter_fr = std::bind(&SVGRadialGradient::get_fr, (SVGRadialGradient *)this);
        std::function<void(const std::string &)> _setter_fr = std::bind(&SVGRadialGradient::set_fr, (SVGRadialGradient *)this, std::placeholders::_1);
        Fr.set_getter(_getter_fr), Fr.set_setter(_setter_fr);
        Fr.callback_assign(_attr_on_assign[2]), Fr.callback_bind_func(_attr_on_bind[2]), Fr.callback_bind_ptr(_attr_on_bind[2]);
        std::function<const std::string()> _getter_fx = std::bind(&SVGRadialGradient::get_fx, (SVGRadialGradient *)this);
        std::function<void(const std::string &)> _setter_fx = std::bind(&SVGRadialGradient::set_fx, (SVGRadialGradient *)this, std::placeholders::_1);
        Fx.set_getter(_getter_fx), Fx.set_setter(_setter_fx);
        Fx.callback_assign(_attr_on_assign[3]), Fx.callback_bind_func(_attr_on_bind[3]), Fx.callback_bind_ptr(_attr_on_bind[3]);
        std::function<const std::string()> _getter_fy = std::bind(&SVGRadialGradient::get_fy, (SVGRadialGradient *)this);
        std::function<void(const std::string &)> _setter_fy = std::bind(&SVGRadialGradient::set_fy, (SVGRadialGradient *)this, std::placeholders::_1);
        Fy.set_getter(_getter_fy), Fy.set_setter(_setter_fy);
        Fy.callback_assign(_attr_on_assign[4]), Fy.callback_bind_func(_attr_on_bind[4]), Fy.callback_bind_ptr(_attr_on_bind[4]);
        std::function<const std::string()> _getter_gradient_units = std::bind(&SVGRadialGradient::get_gradient_units, (SVGRadialGradient *)this);
        std::function<void(const std::string &)> _setter_gradient_units = std::bind(&SVGRadialGradient::set_gradient_units, (SVGRadialGradient *)this, std::placeholders::_1);
        GradientUnits.set_getter(_getter_gradient_units), GradientUnits.set_setter(_setter_gradient_units);
        GradientUnits.callback_assign(_attr_on_assign[5]), GradientUnits.callback_bind_func(_attr_on_bind[5]), GradientUnits.callback_bind_ptr(_attr_on_bind[5]);
        std::function<const std::string()> _getter_gradient_transform = std::bind(&SVGRadialGradient::get_gradient_transform, (SVGRadialGradient *)this);
        std::function<void(const std::string &)> _setter_gradient_transform = std::bind(&SVGRadialGradient::set_gradient_transform, (SVGRadialGradient *)this, std::placeholders::_1);
        GradientTransform.set_getter(_getter_gradient_transform), GradientTransform.set_setter(_setter_gradient_transform);
        GradientTransform.callback_assign(_attr_on_assign[6]), GradientTransform.callback_bind_func(_attr_on_bind[6]), GradientTransform.callback_bind_ptr(_attr_on_bind[6]);
        std::function<const std::string()> _getter_href = std::bind(&SVGRadialGradient::get_href, (SVGRadialGradient *)this);
        std::function<void(const std::string &)> _setter_href = std::bind(&SVGRadialGradient::set_href, (SVGRadialGradient *)this, std::placeholders::_1);
        Href.set_getter(_getter_href), Href.set_setter(_setter_href);
        Href.callback_assign(_attr_on_assign[7]), Href.callback_bind_func(_attr_on_bind[7]), Href.callback_bind_ptr(_attr_on_bind[7]);
        std::function<const std::string()> _getter_r = std::bind(&SVGRadialGradient::get_r, (SVGRadialGradient *)this);
        std::function<void(const std::string &)> _setter_r = std::bind(&SVGRadialGradient::set_r, (SVGRadialGradient *)this, std::placeholders::_1);
        R.set_getter(_getter_r), R.set_setter(_setter_r);
        R.callback_assign(_attr_on_assign[8]), R.callback_bind_func(_attr_on_bind[8]), R.callback_bind_ptr(_attr_on_bind[8]);
        std::function<const std::string()> _getter_spread_method = std::bind(&SVGRadialGradient::get_spread_method, (SVGRadialGradient *)this);
        std::function<void(const std::string &)> _setter_spread_method = std::bind(&SVGRadialGradient::set_spread_method, (SVGRadialGradient *)this, std::placeholders::_1);
        SpreadMethod.set_getter(_getter_spread_method), SpreadMethod.set_setter(_setter_spread_method);
        SpreadMethod.callback_assign(_attr_on_assign[9]), SpreadMethod.callback_bind_func(_attr_on_bind[9]), SpreadMethod.callback_bind_ptr(_attr_on_bind[9]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIRadialGradient::get_tag() const {
        return "radialGradient";
    }
    const std::string SVGIRadialGradient::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGIRadialGradient::commit() {
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
    std::shared_ptr<SVGElement> SVGIRadialGradient::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGIRadialGradient> SVGIRadialGradient::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIRadialGradient>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGIRadialGradient::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGIRadialGradient &SVGIRadialGradient::operator=(const SVGIRadialGradient &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));
        Cx = element.Cx;
        Cy = element.Cy;
        Fr = element.Fr;
        Fx = element.Fx;
        Fy = element.Fy;
        GradientUnits = element.GradientUnits;
        GradientTransform = element.GradientTransform;
        Href = element.Href;
        R = element.R;
        SpreadMethod = element.SpreadMethod;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIRadialGradient::operator-(const SVGElement &element) const {
        return SVGRadialGradient::operator-(element);
    }
}
