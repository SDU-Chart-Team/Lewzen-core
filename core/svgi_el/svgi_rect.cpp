#include "svgi_rect.h"

namespace Lewzen {
    SVGIRect::SVGIRect(): SVGIElement() { SVGIRect::_bind_getter_setter(); }
    void SVGIRect::_bind_getter_setter() {
        std::function<const std::string()> _getter_x = std::bind(&SVGRect::get_x, (SVGRect *)this);
        std::function<void(const std::string &)> _setter_x = std::bind(&SVGRect::set_x, (SVGRect *)this, std::placeholders::_1);
        X.set_getter(_getter_x), X.set_setter(_setter_x);
        X.callback_assign(_attr_on_assign[0]), X.callback_bind_func(_attr_on_bind[0]), X.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_y = std::bind(&SVGRect::get_y, (SVGRect *)this);
        std::function<void(const std::string &)> _setter_y = std::bind(&SVGRect::set_y, (SVGRect *)this, std::placeholders::_1);
        Y.set_getter(_getter_y), Y.set_setter(_setter_y);
        Y.callback_assign(_attr_on_assign[1]), Y.callback_bind_func(_attr_on_bind[1]), Y.callback_bind_ptr(_attr_on_bind[1]);
        std::function<const std::string()> _getter_width = std::bind(&SVGRect::get_width, (SVGRect *)this);
        std::function<void(const std::string &)> _setter_width = std::bind(&SVGRect::set_width, (SVGRect *)this, std::placeholders::_1);
        Width.set_getter(_getter_width), Width.set_setter(_setter_width);
        Width.callback_assign(_attr_on_assign[2]), Width.callback_bind_func(_attr_on_bind[2]), Width.callback_bind_ptr(_attr_on_bind[2]);
        std::function<const std::string()> _getter_height = std::bind(&SVGRect::get_height, (SVGRect *)this);
        std::function<void(const std::string &)> _setter_height = std::bind(&SVGRect::set_height, (SVGRect *)this, std::placeholders::_1);
        Height.set_getter(_getter_height), Height.set_setter(_setter_height);
        Height.callback_assign(_attr_on_assign[3]), Height.callback_bind_func(_attr_on_bind[3]), Height.callback_bind_ptr(_attr_on_bind[3]);
        std::function<const std::string()> _getter_rx = std::bind(&SVGRect::get_rx, (SVGRect *)this);
        std::function<void(const std::string &)> _setter_rx = std::bind(&SVGRect::set_rx, (SVGRect *)this, std::placeholders::_1);
        Rx.set_getter(_getter_rx), Rx.set_setter(_setter_rx);
        Rx.callback_assign(_attr_on_assign[4]), Rx.callback_bind_func(_attr_on_bind[4]), Rx.callback_bind_ptr(_attr_on_bind[4]);
        std::function<const std::string()> _getter_ry = std::bind(&SVGRect::get_ry, (SVGRect *)this);
        std::function<void(const std::string &)> _setter_ry = std::bind(&SVGRect::set_ry, (SVGRect *)this, std::placeholders::_1);
        Ry.set_getter(_getter_ry), Ry.set_setter(_setter_ry);
        Ry.callback_assign(_attr_on_assign[5]), Ry.callback_bind_func(_attr_on_bind[5]), Ry.callback_bind_ptr(_attr_on_bind[5]);
        std::function<const std::string()> _getter_path_length = std::bind(&SVGRect::get_path_length, (SVGRect *)this);
        std::function<void(const std::string &)> _setter_path_length = std::bind(&SVGRect::set_path_length, (SVGRect *)this, std::placeholders::_1);
        PathLength.set_getter(_getter_path_length), PathLength.set_setter(_setter_path_length);
        PathLength.callback_assign(_attr_on_assign[6]), PathLength.callback_bind_func(_attr_on_bind[6]), PathLength.callback_bind_ptr(_attr_on_bind[6]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIRect::get_tag() const {
        return "rect";
    }
    const std::string SVGIRect::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGIRect::commit() {
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
    std::shared_ptr<SVGElement> SVGIRect::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGIRect> SVGIRect::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIRect>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGIRect::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGIRect &SVGIRect::operator=(const SVGIRect &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));
        X = element.X;
        Y = element.Y;
        Width = element.Width;
        Height = element.Height;
        Rx = element.Rx;
        Ry = element.Ry;
        PathLength = element.PathLength;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIRect::operator-(const SVGElement &element) const {
        return SVGRect::operator-(element);
    }
}
