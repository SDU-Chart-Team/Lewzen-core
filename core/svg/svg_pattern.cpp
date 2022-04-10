#include "svg_pattern.h"

namespace Lewzen {
    SVGPattern::SVGPattern() {
        _x = NUM_NULL;
        _y = NUM_NULL;
        _width = NUM_NULL;
        _height = NUM_NULL;
        _pattern_content_units = PatternContentUnits::USER_SPACE_ON_USE;
        _pattern_units = PatternUnits::OBJECT_BOUNDING_BOX;
    }
    SVGPattern::SVGPattern(const SVGPattern &element) {
        _x = element.get_x();
        _y = element.get_y();
        _width = element.get_width();
        _height = element.get_height();
        _pattern_content_units = element.get_pattern_content_units();
        _pattern_units = element.get_pattern_units();
        new (this)XMLElement(element);
    }
    const std::string SVGPattern::get_tag() const {
        return "pattern";
    }
    double SVGPattern::get_x() const {
        return _x;
    }
    void SVGPattern::set_x(const double &x) {
        _x = x;
    }
    double SVGPattern::get_y() const {
        return _y;
    }
    void SVGPattern::set_y(const double &y) {
        _y = y;
    }
    double SVGPattern::get_width() const {
        return _width;
    }
    void SVGPattern::set_width(const double &width) {
        _width = width;
    }
    double SVGPattern::get_height() const {
        return _height;
    }
    void SVGPattern::set_height(const double &height) {
        _height = height;
    }
    const SVGPattern::PatternContentUnits SVGPattern::get_pattern_content_units() const {
        return _pattern_content_units;
    }
    void SVGPattern::set_pattern_content_units(const SVGPattern::PatternContentUnits &pattern_content_units) {
        _pattern_content_units = pattern_content_units;
    }
    const SVGPattern::PatternUnits SVGPattern::get_pattern_units() const {
        return _pattern_units;
    }
    void SVGPattern::set_pattern_units(const SVGPattern::PatternUnits &pattern_units) {
        _pattern_units = pattern_units;
    }
    const std::string SVGPattern::get_attributes() const {
        std::stringstream ss;

        if (_x != NUM_NULL) ss << " x=\"" << _x << "\"";
        if (_y != NUM_NULL) ss << " y=\"" << _y << "\"";
        if (_width != NUM_NULL) ss << " width=\"" << _width << "\"";
        if (_height != NUM_NULL) ss << " height=\"" << _height << "\"";
        if (_pattern_content_units == PatternContentUnits::OBJECT_BOUNDING_BOX) ss << " patternContentUnits=\"objectBoundingBox\"";
        if (_pattern_units == PatternUnits::USER_SPACE_ON_USE) ss << " patternUnits=\"userSpaceOnUse\"";
        ss << XMLElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<XMLElement> SVGPattern::clone() const {
        return std::make_shared<SVGPattern>(*this);
    }
    const std::string SVGPattern::operator-(const XMLElement &element) const {
        std::stringstream ss;

        ss << XMLElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = static_cast<const SVGPattern &>(element);

        if (_x != _element.get_x()) {
            if (_x == NUM_NULL) ss << "reset x" << std::endl;
            else ss << "modify x " << _x << std::endl;
        }
        if (_y != _element.get_y()) {
            if (_y == NUM_NULL) ss << "reset y" << std::endl;
            else ss << "modify y " << _y << std::endl;
        }
        if (_width != _element.get_width()) {
            if (_width == NUM_NULL) ss << "reset width" << std::endl;
            else ss << "modify width " << _width << std::endl;
        }
        if (_height != _element.get_height()) {
            if (_height == NUM_NULL) ss << "reset height" << std::endl;
            else ss << "modify height " << _height << std::endl;
        }
        if (_pattern_content_units != _element.get_pattern_content_units()) {
            if (_pattern_content_units == PatternContentUnits::USER_SPACE_ON_USE) ss << "reset patternContentUnits" << std::endl;
            else if (_pattern_content_units == PatternContentUnits::OBJECT_BOUNDING_BOX) ss << "modify patternContentUnits \"objectBoundingBox\"" << std::endl;
        }
        if (_pattern_units != _element.get_pattern_units()) {
            if (_pattern_units == PatternUnits::OBJECT_BOUNDING_BOX) ss << "reset patternUnits" << std::endl;
            else if (_pattern_units == PatternUnits::USER_SPACE_ON_USE) ss << "modify patternUnits \"userSpaceOnUse\"" << std::endl;
        }

        return ss.str();
    }
}
