#include "svg_linear_gradient.h"

namespace Lewzen {
    SVGLinearGradient::SVGLinearGradient() {
        _gradient_units = STR_NULL;
        _gradient_transform = STR_NULL;
        _href = STR_NULL;
        _spread_method = STR_NULL;
        _xQ = STR_NULL;
        _xR = STR_NULL;
        _yQ = STR_NULL;
        _yR = STR_NULL;
    }
    SVGLinearGradient::SVGLinearGradient(const SVGLinearGradient &element) {
        _gradient_units = element.get_gradient_units();
        _gradient_transform = element.get_gradient_transform();
        _href = element.get_href();
        _spread_method = element.get_spread_method();
        _xQ = element.get_xQ();
        _xR = element.get_xR();
        _yQ = element.get_yQ();
        _yR = element.get_yR();
        new (this)SVGElement(element);
    }
    const std::string SVGLinearGradient::get_tag() const {
        return "linearGradient";
    }
    const std::string SVGLinearGradient::get_gradient_units() const {
        return _gradient_units;
    }
    void SVGLinearGradient::set_gradient_units(const std::string &gradient_units) {
        _gradient_units = gradient_units;
        update_attribute_hash();
    }
    const std::string SVGLinearGradient::get_gradient_transform() const {
        return _gradient_transform;
    }
    void SVGLinearGradient::set_gradient_transform(const std::string &gradient_transform) {
        _gradient_transform = gradient_transform;
        update_attribute_hash();
    }
    const std::string SVGLinearGradient::get_href() const {
        return _href;
    }
    void SVGLinearGradient::set_href(const std::string &href) {
        _href = href;
        update_attribute_hash();
    }
    const std::string SVGLinearGradient::get_spread_method() const {
        return _spread_method;
    }
    void SVGLinearGradient::set_spread_method(const std::string &spread_method) {
        _spread_method = spread_method;
        update_attribute_hash();
    }
    const std::string SVGLinearGradient::get_xQ() const {
        return _xQ;
    }
    void SVGLinearGradient::set_xQ(const std::string &xQ) {
        _xQ = xQ;
        update_attribute_hash();
    }
    const std::string SVGLinearGradient::get_xR() const {
        return _xR;
    }
    void SVGLinearGradient::set_xR(const std::string &xR) {
        _xR = xR;
        update_attribute_hash();
    }
    const std::string SVGLinearGradient::get_yQ() const {
        return _yQ;
    }
    void SVGLinearGradient::set_yQ(const std::string &yQ) {
        _yQ = yQ;
        update_attribute_hash();
    }
    const std::string SVGLinearGradient::get_yR() const {
        return _yR;
    }
    void SVGLinearGradient::set_yR(const std::string &yR) {
        _yR = yR;
        update_attribute_hash();
    }
    const std::string SVGLinearGradient::get_attributes() const {
        std::stringstream ss;

        if (_gradient_units != STR_NULL) ss << " gradientUnits=\"" << _gradient_units << "\"";
        if (_gradient_transform != STR_NULL) ss << " gradientTransform=\"" << _gradient_transform << "\"";
        if (_href != STR_NULL) ss << " href=\"" << _href << "\"";
        if (_spread_method != STR_NULL) ss << " spreadMethod=\"" << _spread_method << "\"";
        if (_xQ != STR_NULL) ss << " x1=\"" << _xQ << "\"";
        if (_xR != STR_NULL) ss << " x2=\"" << _xR << "\"";
        if (_yQ != STR_NULL) ss << " y1=\"" << _yQ << "\"";
        if (_yR != STR_NULL) ss << " y2=\"" << _yR << "\"";
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

        if (_gradient_units != _element.get_gradient_units()) {
            if (_gradient_units == STR_NULL) ss << "reset gradientUnits" << std::endl;
            else ss << "modify gradientUnits \"" << _gradient_units << "\"" << std::endl;
        }
        if (_gradient_transform != _element.get_gradient_transform()) {
            if (_gradient_transform == STR_NULL) ss << "reset gradientTransform" << std::endl;
            else ss << "modify gradientTransform \"" << _gradient_transform << "\"" << std::endl;
        }
        if (_href != _element.get_href()) {
            if (_href == STR_NULL) ss << "reset href" << std::endl;
            else ss << "modify href \"" << _href << "\"" << std::endl;
        }
        if (_spread_method != _element.get_spread_method()) {
            if (_spread_method == STR_NULL) ss << "reset spreadMethod" << std::endl;
            else ss << "modify spreadMethod \"" << _spread_method << "\"" << std::endl;
        }
        if (_xQ != _element.get_xQ()) {
            if (_xQ == STR_NULL) ss << "reset x1" << std::endl;
            else ss << "modify x1 \"" << _xQ << "\"" << std::endl;
        }
        if (_xR != _element.get_xR()) {
            if (_xR == STR_NULL) ss << "reset x2" << std::endl;
            else ss << "modify x2 \"" << _xR << "\"" << std::endl;
        }
        if (_yQ != _element.get_yQ()) {
            if (_yQ == STR_NULL) ss << "reset y1" << std::endl;
            else ss << "modify y1 \"" << _yQ << "\"" << std::endl;
        }
        if (_yR != _element.get_yR()) {
            if (_yR == STR_NULL) ss << "reset y2" << std::endl;
            else ss << "modify y2 \"" << _yR << "\"" << std::endl;
        }

        return ss.str();
    }
}
