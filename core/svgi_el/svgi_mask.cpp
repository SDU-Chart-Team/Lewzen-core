#include "svgi_mask.h"

namespace Lewzen {
    SVGIMask::SVGIMask(): SVGIElement() { SVGIMask::_bind_getter_setter(); }
    void SVGIMask::_bind_getter_setter() {
        std::function<const std::string()> _getter_height = std::bind(&SVGMask::get_height, (SVGMask *)this);
        std::function<void(const std::string &)> _setter_height = std::bind(&SVGMask::set_height, (SVGMask *)this, std::placeholders::_1);
        Height.set_getter(_getter_height), Height.set_setter(_setter_height);
        Height.callback_assign(_attr_on_assign[0]), Height.callback_bind_func(_attr_on_bind[0]), Height.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_mask_content_units = std::bind(&SVGMask::get_mask_content_units, (SVGMask *)this);
        std::function<void(const std::string &)> _setter_mask_content_units = std::bind(&SVGMask::set_mask_content_units, (SVGMask *)this, std::placeholders::_1);
        MaskContentUnits.set_getter(_getter_mask_content_units), MaskContentUnits.set_setter(_setter_mask_content_units);
        MaskContentUnits.callback_assign(_attr_on_assign[1]), MaskContentUnits.callback_bind_func(_attr_on_bind[1]), MaskContentUnits.callback_bind_ptr(_attr_on_bind[1]);
        std::function<const std::string()> _getter_mask_units = std::bind(&SVGMask::get_mask_units, (SVGMask *)this);
        std::function<void(const std::string &)> _setter_mask_units = std::bind(&SVGMask::set_mask_units, (SVGMask *)this, std::placeholders::_1);
        MaskUnits.set_getter(_getter_mask_units), MaskUnits.set_setter(_setter_mask_units);
        MaskUnits.callback_assign(_attr_on_assign[2]), MaskUnits.callback_bind_func(_attr_on_bind[2]), MaskUnits.callback_bind_ptr(_attr_on_bind[2]);
        std::function<const std::string()> _getter_x = std::bind(&SVGMask::get_x, (SVGMask *)this);
        std::function<void(const std::string &)> _setter_x = std::bind(&SVGMask::set_x, (SVGMask *)this, std::placeholders::_1);
        X.set_getter(_getter_x), X.set_setter(_setter_x);
        X.callback_assign(_attr_on_assign[3]), X.callback_bind_func(_attr_on_bind[3]), X.callback_bind_ptr(_attr_on_bind[3]);
        std::function<const std::string()> _getter_y = std::bind(&SVGMask::get_y, (SVGMask *)this);
        std::function<void(const std::string &)> _setter_y = std::bind(&SVGMask::set_y, (SVGMask *)this, std::placeholders::_1);
        Y.set_getter(_getter_y), Y.set_setter(_setter_y);
        Y.callback_assign(_attr_on_assign[4]), Y.callback_bind_func(_attr_on_bind[4]), Y.callback_bind_ptr(_attr_on_bind[4]);
        std::function<const std::string()> _getter_width = std::bind(&SVGMask::get_width, (SVGMask *)this);
        std::function<void(const std::string &)> _setter_width = std::bind(&SVGMask::set_width, (SVGMask *)this, std::placeholders::_1);
        Width.set_getter(_getter_width), Width.set_setter(_setter_width);
        Width.callback_assign(_attr_on_assign[5]), Width.callback_bind_func(_attr_on_bind[5]), Width.callback_bind_ptr(_attr_on_bind[5]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIMask::get_tag() const {
        return "mask";
    }
    const std::string SVGIMask::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGIMask::commit() {
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
    std::shared_ptr<SVGElement> SVGIMask::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGIMask> SVGIMask::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIMask>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGIMask::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGIMask &SVGIMask::operator=(const SVGIMask &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));
        Height = element.Height;
        MaskContentUnits = element.MaskContentUnits;
        MaskUnits = element.MaskUnits;
        X = element.X;
        Y = element.Y;
        Width = element.Width;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIMask::operator-(const SVGElement &element) const {
        return SVGMask::operator-(element);
    }
}
