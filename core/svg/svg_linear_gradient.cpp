#include "svg_linear_gradient.h"

namespace Lewzen {
    SVGLinearGradient::SVGLinearGradient() {
        _x1 = _y1 = _x2 = _y2 = NUM_NULL;
    }
    double SVGLinearGradient::get_x1() const {
        return _x1;
    }
    void SVGLinearGradient::set_x1(const double &x1) {
        _x1 = x1;
    }
    double SVGLinearGradient::get_y1() const {
        return _y1;
    }
    void SVGLinearGradient::set_y1(const double &y1) {
        _y1 = y1;
    }
    double SVGLinearGradient::get_x2() const {
        return _x2;
    }
    void SVGLinearGradient::set_x2(const double &x2) {
        _x2 = x2;
    }
    double SVGLinearGradient::get_y2() const {
        return _y2;
    }
    void SVGLinearGradient::set_y2(const double &y2) {
        _y2 = y2;
    }
    const std::string SVGLinearGradient::outer_XML() const override {
        std::stringstream ss;
        if (_x1 != NUM_NULL) ss << " x1=\"" << _x1 << "\"";
        if (_y1 != NUM_NULL) ss << " y1=\"" << _y1 << "\"";
        if (_x2 != NUM_NULL) ss << " x2=\"" << _x2 << "\"";
        if (_y2 != NUM_NULL) ss << " y2=\"" << _y2 << "\"";
        return outer_XML("linearGradient", ss.str());
    }
}