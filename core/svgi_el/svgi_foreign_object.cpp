#include "svgi_foreign_object.h"

namespace Lewzen {
    SVGIForeignObject::SVGIForeignObject(): SVGIElement() { SVGIForeignObject::_bind_getter_setter(); }
    void SVGIForeignObject::_bind_getter_setter() {
        std::function<const std::string()> _getter_width = std::bind(&SVGForeignObject::get_width, (SVGForeignObject *)this);
        std::function<void(const std::string &)> _setter_width = std::bind(&SVGForeignObject::set_width, (SVGForeignObject *)this, std::placeholders::_1);
        Width.set_getter(_getter_width), Width.set_setter(_setter_width);
        Width.callback_assign(_attr_on_assign[0]), Width.callback_bind_func(_attr_on_bind[0]), Width.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_height = std::bind(&SVGForeignObject::get_height, (SVGForeignObject *)this);
        std::function<void(const std::string &)> _setter_height = std::bind(&SVGForeignObject::set_height, (SVGForeignObject *)this, std::placeholders::_1);
        Height.set_getter(_getter_height), Height.set_setter(_setter_height);
        Height.callback_assign(_attr_on_assign[1]), Height.callback_bind_func(_attr_on_bind[1]), Height.callback_bind_ptr(_attr_on_bind[1]);
        std::function<const std::string()> _getter_x = std::bind(&SVGForeignObject::get_x, (SVGForeignObject *)this);
        std::function<void(const std::string &)> _setter_x = std::bind(&SVGForeignObject::set_x, (SVGForeignObject *)this, std::placeholders::_1);
        X.set_getter(_getter_x), X.set_setter(_setter_x);
        X.callback_assign(_attr_on_assign[2]), X.callback_bind_func(_attr_on_bind[2]), X.callback_bind_ptr(_attr_on_bind[2]);
        std::function<const std::string()> _getter_y = std::bind(&SVGForeignObject::get_y, (SVGForeignObject *)this);
        std::function<void(const std::string &)> _setter_y = std::bind(&SVGForeignObject::set_y, (SVGForeignObject *)this, std::placeholders::_1);
        Y.set_getter(_getter_y), Y.set_setter(_setter_y);
        Y.callback_assign(_attr_on_assign[3]), Y.callback_bind_func(_attr_on_bind[3]), Y.callback_bind_ptr(_attr_on_bind[3]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIForeignObject::get_tag() const {
        return "foreignObject";
    }
    const std::string SVGIForeignObject::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGIForeignObject::commit() {
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
    std::shared_ptr<SVGElement> SVGIForeignObject::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGIForeignObject> SVGIForeignObject::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIForeignObject>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGIForeignObject::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGIForeignObject &SVGIForeignObject::operator=(const SVGIForeignObject &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));
        Width = element.Width;
        Height = element.Height;
        X = element.X;
        Y = element.Y;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIForeignObject::operator-(const SVGElement &element) const {
        return SVGForeignObject::operator-(element);
    }
}
