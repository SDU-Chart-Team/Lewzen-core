#include "svgi_linear_gradient.h"

namespace Lewzen {
    SVGILinearGradient::SVGILinearGradient(): SVGIElement() { SVGILinearGradient::_bind_getter_setter(); }
    void SVGILinearGradient::_bind_getter_setter() {
        std::function<const std::string()> _getter_gradient_units = std::bind(&SVGLinearGradient::get_gradient_units, (SVGLinearGradient *)this);
        std::function<void(const std::string &)> _setter_gradient_units = std::bind(&SVGLinearGradient::set_gradient_units, (SVGLinearGradient *)this, std::placeholders::_1);
        GradientUnits.set_getter(_getter_gradient_units), GradientUnits.set_setter(_setter_gradient_units);
        GradientUnits.callback_assign(_attr_on_assign[0]), GradientUnits.callback_bind_func(_attr_on_bind[0]), GradientUnits.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_gradient_transform = std::bind(&SVGLinearGradient::get_gradient_transform, (SVGLinearGradient *)this);
        std::function<void(const std::string &)> _setter_gradient_transform = std::bind(&SVGLinearGradient::set_gradient_transform, (SVGLinearGradient *)this, std::placeholders::_1);
        GradientTransform.set_getter(_getter_gradient_transform), GradientTransform.set_setter(_setter_gradient_transform);
        GradientTransform.callback_assign(_attr_on_assign[1]), GradientTransform.callback_bind_func(_attr_on_bind[1]), GradientTransform.callback_bind_ptr(_attr_on_bind[1]);
        std::function<const std::string()> _getter_href = std::bind(&SVGLinearGradient::get_href, (SVGLinearGradient *)this);
        std::function<void(const std::string &)> _setter_href = std::bind(&SVGLinearGradient::set_href, (SVGLinearGradient *)this, std::placeholders::_1);
        Href.set_getter(_getter_href), Href.set_setter(_setter_href);
        Href.callback_assign(_attr_on_assign[2]), Href.callback_bind_func(_attr_on_bind[2]), Href.callback_bind_ptr(_attr_on_bind[2]);
        std::function<const std::string()> _getter_spread_method = std::bind(&SVGLinearGradient::get_spread_method, (SVGLinearGradient *)this);
        std::function<void(const std::string &)> _setter_spread_method = std::bind(&SVGLinearGradient::set_spread_method, (SVGLinearGradient *)this, std::placeholders::_1);
        SpreadMethod.set_getter(_getter_spread_method), SpreadMethod.set_setter(_setter_spread_method);
        SpreadMethod.callback_assign(_attr_on_assign[3]), SpreadMethod.callback_bind_func(_attr_on_bind[3]), SpreadMethod.callback_bind_ptr(_attr_on_bind[3]);
        std::function<const std::string()> _getter_xQ = std::bind(&SVGLinearGradient::get_xQ, (SVGLinearGradient *)this);
        std::function<void(const std::string &)> _setter_xQ = std::bind(&SVGLinearGradient::set_xQ, (SVGLinearGradient *)this, std::placeholders::_1);
        X1.set_getter(_getter_xQ), X1.set_setter(_setter_xQ);
        X1.callback_assign(_attr_on_assign[4]), X1.callback_bind_func(_attr_on_bind[4]), X1.callback_bind_ptr(_attr_on_bind[4]);
        std::function<const std::string()> _getter_xR = std::bind(&SVGLinearGradient::get_xR, (SVGLinearGradient *)this);
        std::function<void(const std::string &)> _setter_xR = std::bind(&SVGLinearGradient::set_xR, (SVGLinearGradient *)this, std::placeholders::_1);
        X2.set_getter(_getter_xR), X2.set_setter(_setter_xR);
        X2.callback_assign(_attr_on_assign[5]), X2.callback_bind_func(_attr_on_bind[5]), X2.callback_bind_ptr(_attr_on_bind[5]);
        std::function<const std::string()> _getter_yQ = std::bind(&SVGLinearGradient::get_yQ, (SVGLinearGradient *)this);
        std::function<void(const std::string &)> _setter_yQ = std::bind(&SVGLinearGradient::set_yQ, (SVGLinearGradient *)this, std::placeholders::_1);
        Y1.set_getter(_getter_yQ), Y1.set_setter(_setter_yQ);
        Y1.callback_assign(_attr_on_assign[6]), Y1.callback_bind_func(_attr_on_bind[6]), Y1.callback_bind_ptr(_attr_on_bind[6]);
        std::function<const std::string()> _getter_yR = std::bind(&SVGLinearGradient::get_yR, (SVGLinearGradient *)this);
        std::function<void(const std::string &)> _setter_yR = std::bind(&SVGLinearGradient::set_yR, (SVGLinearGradient *)this, std::placeholders::_1);
        Y2.set_getter(_getter_yR), Y2.set_setter(_setter_yR);
        Y2.callback_assign(_attr_on_assign[7]), Y2.callback_bind_func(_attr_on_bind[7]), Y2.callback_bind_ptr(_attr_on_bind[7]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGILinearGradient::get_tag() const {
        return "linearGradient";
    }
    const std::string SVGILinearGradient::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGILinearGradient::commit() {
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
    std::shared_ptr<SVGElement> SVGILinearGradient::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGILinearGradient> SVGILinearGradient::clone(bool identity) const {
        auto cloned = std::make_shared<SVGILinearGradient>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGILinearGradient::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGILinearGradient &SVGILinearGradient::operator=(const SVGILinearGradient &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));
        GradientUnits = element.GradientUnits;
        GradientTransform = element.GradientTransform;
        Href = element.Href;
        SpreadMethod = element.SpreadMethod;
        X1 = element.X1;
        X2 = element.X2;
        Y1 = element.Y1;
        Y2 = element.Y2;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGILinearGradient::operator-(const SVGElement &element) const {
        return SVGLinearGradient::operator-(element);
    }
}
