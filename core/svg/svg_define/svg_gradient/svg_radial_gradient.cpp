#include "svg_radial_gradient.h"

namespace Lewzen {
    SVGRadialGradient::SVGRadialGradient() {
        _cx = _cy = _r = _fx = _fy = NUM_NULL;
        _spread_method = SVGRadialGradient::SpreadMethod::PAD;
        _gradient_units = SVGRadialGradient::GradientUnits::OBJECT_BOUNDING_BOX;
    }
    double SVGRadialGradient::get_cx() const {
        return _cx;
    }
    void SVGRadialGradient::set_cx(const double &cx) {
        _cx = cx;
    }
    double SVGRadialGradient::get_cy() const {
        return _cy;
    }
    void SVGRadialGradient::set_cy(const double &cy) {
        _cy = cy;
    }
    double SVGRadialGradient::get_r() const {
        return _r;
    }
    void SVGRadialGradient::set_r(const double &r) {
        _r = r;
    }
    double SVGRadialGradient::get_fx() const {
        return _fx;
    }
    void SVGRadialGradient::set_fx(const double &fx) {
        _fx = fx;
    }
    double SVGRadialGradient::get_fy() const {
        return _fy;
    }
    void SVGRadialGradient::set_fy(const double &fy) {
        _fy = fy;
    }
    const SVGRadialGradient::SpreadMethod &SVGRadialGradient::get_spread_method() const {
        return _spread_method;
    }
    void SVGRadialGradient::set_spread_method(const SVGRadialGradient::SpreadMethod &spread_method) {
        _spread_method = spread_method;
    }
    const SVGRadialGradient::GradientUnits &SVGRadialGradient::get_gradient_units() const {
        return _gradient_units;
    }
    void SVGRadialGradient::set_gradient_units(const SVGRadialGradient::GradientUnits &gradient_units) {
        _gradient_units = gradient_units;
    }
    std::string SVGRadialGradient::to_XML() const override {
        std::stringstream ss;
        ss << "<radialGradient";
        ss << " class=\".radial_gradient ." <<  _id << "\"";
        if (_cx != NUM_NULL) ss << " cx=\"" << _cx << "\"";
        if (_cy != NUM_NULL) ss << " cy=\"" << _cy << "\"";
        if (_r != NUM_NULL) ss << " r=\"" << _r << "\"";
        if (_fx != NUM_NULL) ss << " fx=\"" << _fx << "\"";
        if (_fy != NUM_NULL) ss << " fy=\"" << _fy << "\"";
        if (_spread_method == SVGRadialGradient::SpreadMethod::REFLECT) ss << " spreadMethod=\"reflect\"";
        else if (_spread_method == SVGRadialGradient::SpreadMethod::REPEAT) ss << " spreadMethod=\"repeat\"";
        if (_gradient_units == SVGRadialGradient::GradientUnits::USER_SPACE_ON_USE) ss << " gradientUnits=\"userSpaceOnUse\"";
        ss << ">" << std::endl;
        ss << SVGGradient::to_XML();
        ss << "</radialGradient>"<< std::endl;
        return ss.str();
    }
}