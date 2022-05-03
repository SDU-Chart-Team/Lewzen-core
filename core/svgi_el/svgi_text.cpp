#include "svgi_text.h"

namespace Lewzen {
    SVGIText::SVGIText(): SVGIElement() { SVGIText::_bind_getter_setter(); }
    void SVGIText::_bind_getter_setter() {
        std::function<const std::string()> _getter_x = std::bind(&SVGText::get_x, (SVGText *)this);
        std::function<void(const std::string &)> _setter_x = std::bind(&SVGText::set_x, (SVGText *)this, std::placeholders::_1);
        X.set_getter(_getter_x), X.set_setter(_setter_x);
        X.callback_assign(_attr_on_assign[0]), X.callback_bind_func(_attr_on_bind[0]), X.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_y = std::bind(&SVGText::get_y, (SVGText *)this);
        std::function<void(const std::string &)> _setter_y = std::bind(&SVGText::set_y, (SVGText *)this, std::placeholders::_1);
        Y.set_getter(_getter_y), Y.set_setter(_setter_y);
        Y.callback_assign(_attr_on_assign[1]), Y.callback_bind_func(_attr_on_bind[1]), Y.callback_bind_ptr(_attr_on_bind[1]);
        std::function<const std::string()> _getter_dx = std::bind(&SVGText::get_dx, (SVGText *)this);
        std::function<void(const std::string &)> _setter_dx = std::bind(&SVGText::set_dx, (SVGText *)this, std::placeholders::_1);
        Dx.set_getter(_getter_dx), Dx.set_setter(_setter_dx);
        Dx.callback_assign(_attr_on_assign[2]), Dx.callback_bind_func(_attr_on_bind[2]), Dx.callback_bind_ptr(_attr_on_bind[2]);
        std::function<const std::string()> _getter_dy = std::bind(&SVGText::get_dy, (SVGText *)this);
        std::function<void(const std::string &)> _setter_dy = std::bind(&SVGText::set_dy, (SVGText *)this, std::placeholders::_1);
        Dy.set_getter(_getter_dy), Dy.set_setter(_setter_dy);
        Dy.callback_assign(_attr_on_assign[3]), Dy.callback_bind_func(_attr_on_bind[3]), Dy.callback_bind_ptr(_attr_on_bind[3]);
        std::function<const std::string()> _getter_rotate = std::bind(&SVGText::get_rotate, (SVGText *)this);
        std::function<void(const std::string &)> _setter_rotate = std::bind(&SVGText::set_rotate, (SVGText *)this, std::placeholders::_1);
        Rotate.set_getter(_getter_rotate), Rotate.set_setter(_setter_rotate);
        Rotate.callback_assign(_attr_on_assign[4]), Rotate.callback_bind_func(_attr_on_bind[4]), Rotate.callback_bind_ptr(_attr_on_bind[4]);
        std::function<const std::string()> _getter_length_adjust = std::bind(&SVGText::get_length_adjust, (SVGText *)this);
        std::function<void(const std::string &)> _setter_length_adjust = std::bind(&SVGText::set_length_adjust, (SVGText *)this, std::placeholders::_1);
        LengthAdjust.set_getter(_getter_length_adjust), LengthAdjust.set_setter(_setter_length_adjust);
        LengthAdjust.callback_assign(_attr_on_assign[5]), LengthAdjust.callback_bind_func(_attr_on_bind[5]), LengthAdjust.callback_bind_ptr(_attr_on_bind[5]);
        std::function<const std::string()> _getter_text_length = std::bind(&SVGText::get_text_length, (SVGText *)this);
        std::function<void(const std::string &)> _setter_text_length = std::bind(&SVGText::set_text_length, (SVGText *)this, std::placeholders::_1);
        TextLength.set_getter(_getter_text_length), TextLength.set_setter(_setter_text_length);
        TextLength.callback_assign(_attr_on_assign[6]), TextLength.callback_bind_func(_attr_on_bind[6]), TextLength.callback_bind_ptr(_attr_on_bind[6]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIText::get_tag() const {
        return "text";
    }
    const std::string SVGIText::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGIText::commit() {
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
    std::shared_ptr<SVGElement> SVGIText::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGIText> SVGIText::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIText>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGIText::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGIText &SVGIText::operator=(const SVGIText &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));
        X = element.X;
        Y = element.Y;
        Dx = element.Dx;
        Dy = element.Dy;
        Rotate = element.Rotate;
        LengthAdjust = element.LengthAdjust;
        TextLength = element.TextLength;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIText::operator-(const SVGElement &element) const {
        return SVGText::operator-(element);
    }
}
