#include "svgi_circle.h"

namespace Lewzen {
    SVGICircle::SVGICircle(): SVGIElement() { SVGICircle::_bind_getter_setter(); }
    void SVGICircle::_bind_getter_setter() {
        std::function<const std::string()> _getter_cx = std::bind(&SVGCircle::get_cx, (SVGCircle *)this);
        std::function<void(const std::string &)> _setter_cx = std::bind(&SVGCircle::set_cx, (SVGCircle *)this, std::placeholders::_1);
        Cx.set_getter(_getter_cx), Cx.set_setter(_setter_cx);
        Cx.callback_assign(_attr_on_assign[0]), Cx.callback_bind_func(_attr_on_bind[0]), Cx.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_cy = std::bind(&SVGCircle::get_cy, (SVGCircle *)this);
        std::function<void(const std::string &)> _setter_cy = std::bind(&SVGCircle::set_cy, (SVGCircle *)this, std::placeholders::_1);
        Cy.set_getter(_getter_cy), Cy.set_setter(_setter_cy);
        Cy.callback_assign(_attr_on_assign[1]), Cy.callback_bind_func(_attr_on_bind[1]), Cy.callback_bind_ptr(_attr_on_bind[1]);
        std::function<const std::string()> _getter_r = std::bind(&SVGCircle::get_r, (SVGCircle *)this);
        std::function<void(const std::string &)> _setter_r = std::bind(&SVGCircle::set_r, (SVGCircle *)this, std::placeholders::_1);
        R.set_getter(_getter_r), R.set_setter(_setter_r);
        R.callback_assign(_attr_on_assign[2]), R.callback_bind_func(_attr_on_bind[2]), R.callback_bind_ptr(_attr_on_bind[2]);
        std::function<const std::string()> _getter_path_length = std::bind(&SVGCircle::get_path_length, (SVGCircle *)this);
        std::function<void(const std::string &)> _setter_path_length = std::bind(&SVGCircle::set_path_length, (SVGCircle *)this, std::placeholders::_1);
        PathLength.set_getter(_getter_path_length), PathLength.set_setter(_setter_path_length);
        PathLength.callback_assign(_attr_on_assign[3]), PathLength.callback_bind_func(_attr_on_bind[3]), PathLength.callback_bind_ptr(_attr_on_bind[3]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGICircle::get_tag() const {
        return "circle";
    }
    const std::string SVGICircle::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGICircle::commit() {
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
    std::shared_ptr<SVGElement> SVGICircle::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGICircle> SVGICircle::clone(bool identity) const {
        auto cloned = std::make_shared<SVGICircle>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGICircle::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGICircle &SVGICircle::operator=(const SVGICircle &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));
        Cx = element.Cx;
        Cy = element.Cy;
        R = element.R;
        PathLength = element.PathLength;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGICircle::operator-(const SVGElement &element) const {
        return SVGCircle::operator-(element);
    }
}
