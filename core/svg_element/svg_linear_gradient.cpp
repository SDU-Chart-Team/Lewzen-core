#include "svg_linear_gradient.h"

namespace Lewzen {
    SVGLinearGradient::SVGLinearGradient() {
        _xQ = NUM_NULL;
        _yQ = NUM_NULL;
        _xR = NUM_NULL;
        _yR = NUM_NULL;
        _spread_method = SpreadMethod::PAD;
        _gradient_units = GradientUnits::OBJECT_BOUNDING_BOX;
        _gradient_transform = STR_NULL;
        _href = STR_NULL;
    }
    SVGLinearGradient::SVGLinearGradient(const SVGLinearGradient &element) {
        _xQ = element.get_xQ();
        _yQ = element.get_yQ();
        _xR = element.get_xR();
        _yR = element.get_yR();
        _spread_method = element.get_spread_method();
        _gradient_units = element.get_gradient_units();
        _gradient_transform = element.get_gradient_transform();
        _href = element.get_href();
        new (this)SVGElement(element);
    }
    const std::string SVGLinearGradient::get_tag() const {
        return "linearGradient";
    }
    double SVGLinearGradient::get_xQ() const {
        return _xQ;
    }
    void SVGLinearGradient::set_xQ(const double &xQ) {
        _xQ = xQ;
    }
    double SVGLinearGradient::get_yQ() const {
        return _yQ;
    }
    void SVGLinearGradient::set_yQ(const double &yQ) {
        _yQ = yQ;
    }
    double SVGLinearGradient::get_xR() const {
        return _xR;
    }
    void SVGLinearGradient::set_xR(const double &xR) {
        _xR = xR;
    }
    double SVGLinearGradient::get_yR() const {
        return _yR;
    }
    void SVGLinearGradient::set_yR(const double &yR) {
        _yR = yR;
    }
    const SVGLinearGradient::SpreadMethod SVGLinearGradient::get_spread_method() const {
        return _spread_method;
    }
    void SVGLinearGradient::set_spread_method(const SVGLinearGradient::SpreadMethod &spread_method) {
        _spread_method = spread_method;
    }
    const SVGLinearGradient::GradientUnits SVGLinearGradient::get_gradient_units() const {
        return _gradient_units;
    }
    void SVGLinearGradient::set_gradient_units(const SVGLinearGradient::GradientUnits &gradient_units) {
        _gradient_units = gradient_units;
    }
    const std::string SVGLinearGradient::get_gradient_transform() const {
        return _gradient_transform;
    }
    void SVGLinearGradient::set_gradient_transform(const std::string &gradient_transform) {
        _gradient_transform = gradient_transform;
    }
    const std::string SVGLinearGradient::get_href() const {
        return _href;
    }
    void SVGLinearGradient::set_href(const std::string &href) {
        _href = href;
    }
    const std::string SVGLinearGradient::get_attributes() const {
        std::stringstream ss;

        if (_xQ != NUM_NULL) ss << " x1=\"" << _xQ << "\"";
        if (_yQ != NUM_NULL) ss << " y1=\"" << _yQ << "\"";
        if (_xR != NUM_NULL) ss << " x2=\"" << _xR << "\"";
        if (_yR != NUM_NULL) ss << " y2=\"" << _yR << "\"";
        if (_spread_method == SpreadMethod::REFLECT) ss << " spreadMethod=\"reflect\"";
        if (_spread_method == SpreadMethod::REPEAT) ss << " spreadMethod=\"repeat\"";
        if (_gradient_units == GradientUnits::USER_SPACE_ON_USE) ss << " gradientUnits=\"userSpaceOnUse\"";
        if (_gradient_transform != STR_NULL) ss << " gradientTransform=\"" << _gradient_transform << "\"";
        if (_href != STR_NULL) ss << " href=\"" << _href << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGLinearGradient::clone() const {
        return std::make_shared<SVGLinearGradient>(*this);
    }
    const std::string SVGLinearGradient::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = static_cast<const SVGLinearGradient &>(element);

        if (_xQ != _element.get_xQ()) {
            if (_xQ == NUM_NULL) ss << "reset x1" << std::endl;
            else ss << "modify x1 " << _xQ << std::endl;
        }
        if (_yQ != _element.get_yQ()) {
            if (_yQ == NUM_NULL) ss << "reset y1" << std::endl;
            else ss << "modify y1 " << _yQ << std::endl;
        }
        if (_xR != _element.get_xR()) {
            if (_xR == NUM_NULL) ss << "reset x2" << std::endl;
            else ss << "modify x2 " << _xR << std::endl;
        }
        if (_yR != _element.get_yR()) {
            if (_yR == NUM_NULL) ss << "reset y2" << std::endl;
            else ss << "modify y2 " << _yR << std::endl;
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
        if (_gradient_transform != _element.get_gradient_transform()) {
            if (_gradient_transform == STR_NULL) ss << "reset gradientTransform" << std::endl;
            else ss << "modify gradientTransform \"" << _gradient_transform << "\"" << std::endl;
        }
        if (_href != _element.get_href()) {
            if (_href == STR_NULL) ss << "reset href" << std::endl;
            else ss << "modify href \"" << _href << "\"" << std::endl;
        }

        return ss.str();
    }
}
