#include "svg_pattern.h"

namespace Lewzen {
    SVGPattern::SVGPattern() {
        _x = _y = _width = _height = NUM_NULL;
        _pattern_content_units = SVGPattern::PatternContentUnits::USER_SPACE_ON_USE;
        _pattern_units = SVGPattern::PatternContentUnits::OBJECT_BOUNDING_BOX;
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
    void SVGPattern::set_pattern_content_units(const SVGPattern::PatternContentUnits &pattern_content_units) [
        _pattern_content_units = pattern_content_units;
    ]
    const SVGPattern::PatternUnits SVGPattern::get_pattern_units() const {
        return _pattern_units;
    }
    void SVGPattern::set_pattern_units(const SVGPattern::PatternUnits &pattern_units) {
        _pattern_units = pattern_units;
    }
    const std::string outer_XML() const override {
        std::stringstream ss;
        if (_x != NUM_NULL) ss << " x=\"" << _x << "\"";
        if (_y != NUM_NULL) ss << " y=\"" << _y << "\"";
        if (_width != NUM_NULL) ss << " width=\"" << _width << "\"";
        if (_height != NUM_NULL) ss << " height=\"" << _height << "\"";
        if (_pattern_content_units == SVGPattern::PatternContentUnits::OBJECT_BOUNDING_BOX) ss << " patternContentUnits=\"objectBoundingBox\"";
        if (_pattern_units == SVGPattern::PatternUnits::USER_SPACE_ON_USE) ss << " patternUnits=\"userSpaceOnUse\"";
        return outer_XML("pattern", ss.str());
    }
}