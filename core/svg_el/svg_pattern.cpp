#include "svg_pattern.h"

namespace Lewzen {
    SVGPattern::SVGPattern() {
        _height = STR_NULL;
        _href = STR_NULL;
        _pattern_content_units = STR_NULL;
        _pattern_transform = STR_NULL;
        _pattern_units = STR_NULL;
        _preserve_aspect_ratio = STR_NULL;
        _view_box = STR_NULL;
        _width = STR_NULL;
        _x = STR_NULL;
        _y = STR_NULL;
    }
    const std::string SVGPattern::get_tag() const {
        return "pattern";
    }
    const std::string SVGPattern::get_height() const {
        return _height;
    }
    void SVGPattern::set_height(const std::string &height) {
        _height = height;
        update_attribute_hash();
    }
    const std::string SVGPattern::get_href() const {
        return _href;
    }
    void SVGPattern::set_href(const std::string &href) {
        _href = href;
        update_attribute_hash();
    }
    const std::string SVGPattern::get_pattern_content_units() const {
        return _pattern_content_units;
    }
    void SVGPattern::set_pattern_content_units(const std::string &pattern_content_units) {
        _pattern_content_units = pattern_content_units;
        update_attribute_hash();
    }
    const std::string SVGPattern::get_pattern_transform() const {
        return _pattern_transform;
    }
    void SVGPattern::set_pattern_transform(const std::string &pattern_transform) {
        _pattern_transform = pattern_transform;
        update_attribute_hash();
    }
    const std::string SVGPattern::get_pattern_units() const {
        return _pattern_units;
    }
    void SVGPattern::set_pattern_units(const std::string &pattern_units) {
        _pattern_units = pattern_units;
        update_attribute_hash();
    }
    const std::string SVGPattern::get_preserve_aspect_ratio() const {
        return _preserve_aspect_ratio;
    }
    void SVGPattern::set_preserve_aspect_ratio(const std::string &preserve_aspect_ratio) {
        _preserve_aspect_ratio = preserve_aspect_ratio;
        update_attribute_hash();
    }
    const std::string SVGPattern::get_view_box() const {
        return _view_box;
    }
    void SVGPattern::set_view_box(const std::string &view_box) {
        _view_box = view_box;
        update_attribute_hash();
    }
    const std::string SVGPattern::get_width() const {
        return _width;
    }
    void SVGPattern::set_width(const std::string &width) {
        _width = width;
        update_attribute_hash();
    }
    const std::string SVGPattern::get_x() const {
        return _x;
    }
    void SVGPattern::set_x(const std::string &x) {
        _x = x;
        update_attribute_hash();
    }
    const std::string SVGPattern::get_y() const {
        return _y;
    }
    void SVGPattern::set_y(const std::string &y) {
        _y = y;
        update_attribute_hash();
    }
    const std::string SVGPattern::get_attributes() const {
        std::stringstream ss;

        if (_height != STR_NULL) ss << " height=\"" << _height << "\"";
        if (_href != STR_NULL) ss << " href=\"" << _href << "\"";
        if (_pattern_content_units != STR_NULL) ss << " patternContentUnits=\"" << _pattern_content_units << "\"";
        if (_pattern_transform != STR_NULL) ss << " patternTransform=\"" << _pattern_transform << "\"";
        if (_pattern_units != STR_NULL) ss << " patternUnits=\"" << _pattern_units << "\"";
        if (_preserve_aspect_ratio != STR_NULL) ss << " preserveAspectRatio=\"" << _preserve_aspect_ratio << "\"";
        if (_view_box != STR_NULL) ss << " viewBox=\"" << _view_box << "\"";
        if (_width != STR_NULL) ss << " width=\"" << _width << "\"";
        if (_x != STR_NULL) ss << " x=\"" << _x << "\"";
        if (_y != STR_NULL) ss << " y=\"" << _y << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGPattern::clone() const {
        return clone(true);
    }
    std::shared_ptr<SVGPattern> SVGPattern::clone(bool identity) const {
        auto cloned =  std::make_shared<SVGPattern>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGPattern::operator=(const SVGElement &element) {
        return SVGElement::operator=(element);
    }
    SVGPattern &SVGPattern::operator=(const SVGPattern &element) {
        SVGElement::operator=(element);
        return *this;

        _height = element.get_height();
        _href = element.get_href();
        _pattern_content_units = element.get_pattern_content_units();
        _pattern_transform = element.get_pattern_transform();
        _pattern_units = element.get_pattern_units();
        _preserve_aspect_ratio = element.get_preserve_aspect_ratio();
        _view_box = element.get_view_box();
        _width = element.get_width();
        _x = element.get_x();
        _y = element.get_y();
        return *this;
    }
    const std::string SVGPattern::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = dynamic_cast<const SVGPattern &>(element);

        // attribute differ
        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);

        return ss.str();
    }
    const std::string SVGPattern::attribute_differ(const SVGPattern &element) const {
        std::stringstream ss;

        if (_height != element.get_height()) {
            if (_height == STR_NULL) ss << "reset height" << std::endl;
            else ss << "modify height \"" << _height << "\"" << std::endl;
        }
        if (_href != element.get_href()) {
            if (_href == STR_NULL) ss << "reset href" << std::endl;
            else ss << "modify href \"" << _href << "\"" << std::endl;
        }
        if (_pattern_content_units != element.get_pattern_content_units()) {
            if (_pattern_content_units == STR_NULL) ss << "reset patternContentUnits" << std::endl;
            else ss << "modify patternContentUnits \"" << _pattern_content_units << "\"" << std::endl;
        }
        if (_pattern_transform != element.get_pattern_transform()) {
            if (_pattern_transform == STR_NULL) ss << "reset patternTransform" << std::endl;
            else ss << "modify patternTransform \"" << _pattern_transform << "\"" << std::endl;
        }
        if (_pattern_units != element.get_pattern_units()) {
            if (_pattern_units == STR_NULL) ss << "reset patternUnits" << std::endl;
            else ss << "modify patternUnits \"" << _pattern_units << "\"" << std::endl;
        }
        if (_preserve_aspect_ratio != element.get_preserve_aspect_ratio()) {
            if (_preserve_aspect_ratio == STR_NULL) ss << "reset preserveAspectRatio" << std::endl;
            else ss << "modify preserveAspectRatio \"" << _preserve_aspect_ratio << "\"" << std::endl;
        }
        if (_view_box != element.get_view_box()) {
            if (_view_box == STR_NULL) ss << "reset viewBox" << std::endl;
            else ss << "modify viewBox \"" << _view_box << "\"" << std::endl;
        }
        if (_width != element.get_width()) {
            if (_width == STR_NULL) ss << "reset width" << std::endl;
            else ss << "modify width \"" << _width << "\"" << std::endl;
        }
        if (_x != element.get_x()) {
            if (_x == STR_NULL) ss << "reset x" << std::endl;
            else ss << "modify x \"" << _x << "\"" << std::endl;
        }
        if (_y != element.get_y()) {
            if (_y == STR_NULL) ss << "reset y" << std::endl;
            else ss << "modify y \"" << _y << "\"" << std::endl;
        }

        return ss.str();
    }
}
