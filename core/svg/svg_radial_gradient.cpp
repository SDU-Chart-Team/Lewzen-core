#include "svg_radial_gradient.h"

namespace Lewzen {
    SVGRadialGradient::SVGRadialGradient() {
        _cx = NUM_NULL;
        _cy = NUM_NULL;
        _r = NUM_NULL;
        _fx = NUM_NULL;
        _fy = NUM_NULL;
        _spread_method = SpreadMethod::PAD;
        _gradient_units = GradientUnits::OBJECT_BOUNDING_BOX;
    }
    SVGRadialGradient::SVGRadialGradient(const SVGRadialGradient &element) {
        _cx = element.get_cx();
        _cy = element.get_cy();
        _r = element.get_r();
        _fx = element.get_fx();
        _fy = element.get_fy();
        _spread_method = element.get_spread_method();
        _gradient_units = element.get_gradient_units();
        new (this)XMLElement(element);
    }
    const std::string SVGRadialGradient::get_tag() const {
        return "radialGradient";
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
    const SVGRadialGradient::SpreadMethod SVGRadialGradient::get_spread_method() const {
        return _spread_method;
    }
    void SVGRadialGradient::set_spread_method(const SVGRadialGradient::SpreadMethod &spread_method) {
        _spread_method = spread_method;
    }
    const SVGRadialGradient::GradientUnits SVGRadialGradient::get_gradient_units() const {
        return _gradient_units;
    }
    void SVGRadialGradient::set_gradient_units(const SVGRadialGradient::GradientUnits &gradient_units) {
        _gradient_units = gradient_units;
    }
    const std::string SVGRadialGradient::get_attributes() const {
        std::stringstream ss;

        if (_cx != NUM_NULL) ss << " cx=\"" << _cx << "\"";
        if (_cy != NUM_NULL) ss << " cy=\"" << _cy << "\"";
        if (_r != NUM_NULL) ss << " r=\"" << _r << "\"";
        if (_fx != NUM_NULL) ss << " fx=\"" << _fx << "\"";
        if (_fy != NUM_NULL) ss << " fy=\"" << _fy << "\"";
        if (_spread_method == SpreadMethod::REFLECT) ss << " spreadMethod=\"reflect\"";
        if (_spread_method == SpreadMethod::REPEAT) ss << " spreadMethod=\"repeat\"";
        if (_gradient_units == GradientUnits::USER_SPACE_ON_USE) ss << " gradientUnits=\"userSpaceOnUse\"";
        ss << XMLElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<XMLElement> SVGRadialGradient::clone() const {
        return std::make_shared<SVGRadialGradient>(*this);
    }
    const std::string SVGRadialGradient::operator-(const XMLElement &element) const {
        std::stringstream ss;

        ss << XMLElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = static_cast<const SVGRadialGradient &>(element);

        if (_cx != _element.get_cx()) {
            if (_cx == NUM_NULL) ss << "reset cx" << std::endl;
            else ss << "modify cx " << _cx << std::endl;
        }
        if (_cy != _element.get_cy()) {
            if (_cy == NUM_NULL) ss << "reset cy" << std::endl;
            else ss << "modify cy " << _cy << std::endl;
        }
        if (_r != _element.get_r()) {
            if (_r == NUM_NULL) ss << "reset r" << std::endl;
            else ss << "modify r " << _r << std::endl;
        }
        if (_fx != _element.get_fx()) {
            if (_fx == NUM_NULL) ss << "reset fx" << std::endl;
            else ss << "modify fx " << _fx << std::endl;
        }
        if (_fy != _element.get_fy()) {
            if (_fy == NUM_NULL) ss << "reset fy" << std::endl;
            else ss << "modify fy " << _fy << std::endl;
        }
        if (_spread_method != _element.get_spread_method()) {
            if (_spread_method == SpreadMethod::PAD) ss << "reset spreadMethod" << std::endl;
            else if (_spread_method == SpreadMethod::REFLECT) ss << "modify spreadMethod \"reflect\"" << std::endl;
            else if (_spread_method == SpreadMethod::REPEAT) ss << "modify spreadMethod \"repeat\"" << std::endl;
        }
        if (_gradient_units != _element.get_gradient_units()) {
            if (_gradient_units == GradientUnits::OBJECT_BOUNDING_BOX) ss << "reset gradientUnits" << std::endl;
            else if (_gradient_units == GradientUnits::USER_SPACE_ON_USE) ss << "modify gradientUnits \"userSpaceOnUse\"" << std::endl;
        }

        return ss.str();
    }
}
