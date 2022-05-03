#include "svgi_pattern.h"

namespace Lewzen {
    SVGIPattern::SVGIPattern(): SVGIElement() { SVGIPattern::_bind_getter_setter(); }
    void SVGIPattern::_bind_getter_setter() {
        std::function<const std::string()> _getter_height = std::bind(&SVGPattern::get_height, (SVGPattern *)this);
        std::function<void(const std::string &)> _setter_height = std::bind(&SVGPattern::set_height, (SVGPattern *)this, std::placeholders::_1);
        Height.set_getter(_getter_height), Height.set_setter(_setter_height);
        Height.callback_assign(_attr_on_assign[0]), Height.callback_bind_func(_attr_on_bind[0]), Height.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_href = std::bind(&SVGPattern::get_href, (SVGPattern *)this);
        std::function<void(const std::string &)> _setter_href = std::bind(&SVGPattern::set_href, (SVGPattern *)this, std::placeholders::_1);
        Href.set_getter(_getter_href), Href.set_setter(_setter_href);
        Href.callback_assign(_attr_on_assign[1]), Href.callback_bind_func(_attr_on_bind[1]), Href.callback_bind_ptr(_attr_on_bind[1]);
        std::function<const std::string()> _getter_pattern_content_units = std::bind(&SVGPattern::get_pattern_content_units, (SVGPattern *)this);
        std::function<void(const std::string &)> _setter_pattern_content_units = std::bind(&SVGPattern::set_pattern_content_units, (SVGPattern *)this, std::placeholders::_1);
        PatternContentUnits.set_getter(_getter_pattern_content_units), PatternContentUnits.set_setter(_setter_pattern_content_units);
        PatternContentUnits.callback_assign(_attr_on_assign[2]), PatternContentUnits.callback_bind_func(_attr_on_bind[2]), PatternContentUnits.callback_bind_ptr(_attr_on_bind[2]);
        std::function<const std::string()> _getter_pattern_transform = std::bind(&SVGPattern::get_pattern_transform, (SVGPattern *)this);
        std::function<void(const std::string &)> _setter_pattern_transform = std::bind(&SVGPattern::set_pattern_transform, (SVGPattern *)this, std::placeholders::_1);
        PatternTransform.set_getter(_getter_pattern_transform), PatternTransform.set_setter(_setter_pattern_transform);
        PatternTransform.callback_assign(_attr_on_assign[3]), PatternTransform.callback_bind_func(_attr_on_bind[3]), PatternTransform.callback_bind_ptr(_attr_on_bind[3]);
        std::function<const std::string()> _getter_pattern_units = std::bind(&SVGPattern::get_pattern_units, (SVGPattern *)this);
        std::function<void(const std::string &)> _setter_pattern_units = std::bind(&SVGPattern::set_pattern_units, (SVGPattern *)this, std::placeholders::_1);
        PatternUnits.set_getter(_getter_pattern_units), PatternUnits.set_setter(_setter_pattern_units);
        PatternUnits.callback_assign(_attr_on_assign[4]), PatternUnits.callback_bind_func(_attr_on_bind[4]), PatternUnits.callback_bind_ptr(_attr_on_bind[4]);
        std::function<const std::string()> _getter_preserve_aspect_ratio = std::bind(&SVGPattern::get_preserve_aspect_ratio, (SVGPattern *)this);
        std::function<void(const std::string &)> _setter_preserve_aspect_ratio = std::bind(&SVGPattern::set_preserve_aspect_ratio, (SVGPattern *)this, std::placeholders::_1);
        PreserveAspectRatio.set_getter(_getter_preserve_aspect_ratio), PreserveAspectRatio.set_setter(_setter_preserve_aspect_ratio);
        PreserveAspectRatio.callback_assign(_attr_on_assign[5]), PreserveAspectRatio.callback_bind_func(_attr_on_bind[5]), PreserveAspectRatio.callback_bind_ptr(_attr_on_bind[5]);
        std::function<const std::string()> _getter_view_box = std::bind(&SVGPattern::get_view_box, (SVGPattern *)this);
        std::function<void(const std::string &)> _setter_view_box = std::bind(&SVGPattern::set_view_box, (SVGPattern *)this, std::placeholders::_1);
        ViewBox.set_getter(_getter_view_box), ViewBox.set_setter(_setter_view_box);
        ViewBox.callback_assign(_attr_on_assign[6]), ViewBox.callback_bind_func(_attr_on_bind[6]), ViewBox.callback_bind_ptr(_attr_on_bind[6]);
        std::function<const std::string()> _getter_width = std::bind(&SVGPattern::get_width, (SVGPattern *)this);
        std::function<void(const std::string &)> _setter_width = std::bind(&SVGPattern::set_width, (SVGPattern *)this, std::placeholders::_1);
        Width.set_getter(_getter_width), Width.set_setter(_setter_width);
        Width.callback_assign(_attr_on_assign[7]), Width.callback_bind_func(_attr_on_bind[7]), Width.callback_bind_ptr(_attr_on_bind[7]);
        std::function<const std::string()> _getter_x = std::bind(&SVGPattern::get_x, (SVGPattern *)this);
        std::function<void(const std::string &)> _setter_x = std::bind(&SVGPattern::set_x, (SVGPattern *)this, std::placeholders::_1);
        X.set_getter(_getter_x), X.set_setter(_setter_x);
        X.callback_assign(_attr_on_assign[8]), X.callback_bind_func(_attr_on_bind[8]), X.callback_bind_ptr(_attr_on_bind[8]);
        std::function<const std::string()> _getter_y = std::bind(&SVGPattern::get_y, (SVGPattern *)this);
        std::function<void(const std::string &)> _setter_y = std::bind(&SVGPattern::set_y, (SVGPattern *)this, std::placeholders::_1);
        Y.set_getter(_getter_y), Y.set_setter(_setter_y);
        Y.callback_assign(_attr_on_assign[9]), Y.callback_bind_func(_attr_on_bind[9]), Y.callback_bind_ptr(_attr_on_bind[9]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIPattern::get_tag() const {
        return "pattern";
    }
    const std::string SVGIPattern::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGIPattern::commit() {
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
    std::shared_ptr<SVGElement> SVGIPattern::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGIPattern> SVGIPattern::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIPattern>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGIPattern::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGIPattern &SVGIPattern::operator=(const SVGIPattern &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));
        Height = element.Height;
        Href = element.Href;
        PatternContentUnits = element.PatternContentUnits;
        PatternTransform = element.PatternTransform;
        PatternUnits = element.PatternUnits;
        PreserveAspectRatio = element.PreserveAspectRatio;
        ViewBox = element.ViewBox;
        Width = element.Width;
        X = element.X;
        Y = element.Y;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIPattern::operator-(const SVGElement &element) const {
        return SVGPattern::operator-(element);
    }
}
