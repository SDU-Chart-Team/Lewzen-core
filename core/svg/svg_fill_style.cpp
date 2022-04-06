#include "svg_fill_style.h"

namespace Lewzen {
    SVGFillStyle::SVGFillStyle() {
        _fill = STR_NULL;
        _fill_opacity = NUM_NULL;
        _fill_rule = SVGFillStyle::FillRule::NONEZERO;
    }
    const std::string &SVGFillStyle::get_fill() const {
        return _fill;
    }
    void SVGFillStyle::set_fill(const std::string &fill) {
        _fill = fill;
    }
    double SVGFillStyle::get_fill_opacity() const {
        return _fill_opacity;
    }
    void SVGFillStyle::set_fill_opacity(const double &fill_opacity) {
        _fill_opacity = fill_opacity;
    }
    const SVGFillStyle::FillRule &SVGFillStyle::get_fill_rule() const {
        return _fill_rule;
    }
    void SVGFillStyle::set_fill_rule(const SVGFillStyle::FillRule &fill_rule) {
        _fill_rule = fill_rule;
    }
    const std::string &SVGFillStyle::to_properties() const override {
        std::stringstream ss;
        ss << " ";
        if (_fill != STR_NULL) ss << "fill=\"" << _fill << "\" ";
        if (_fill_opacity != NUM_NULL) ss << "fill-opacity=\"" << _fill_opacity << "\" ";
        if (_fill_rule == SVGFillStyle::FillRule::EVENODD) ss << "fill-rule=\"evenodd" << "\" ";
        return ss.str();
    }
}