#include "svg_linear_gradient.h"

namespace Lewzen {
    SVGLinearGradient::SVGLinearGradient() {
        _xQ = NUM_NULL;
        _yQ = NUM_NULL;
        _xR = NUM_NULL;
        _yR = NUM_NULL;
    }
    SVGLinearGradient::SVGLinearGradient(const SVGLinearGradient &element) {
        _xQ = element.get_xQ();
        _yQ = element.get_yQ();
        _xR = element.get_xR();
        _yR = element.get_yR();
        new (this)XMLElement(element);
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
    const std::string SVGLinearGradient::get_attributes() const {
        std::stringstream ss;

        if (_xQ != NUM_NULL) ss << " x1=\"" << _xQ << "\"";
        if (_yQ != NUM_NULL) ss << " y1=\"" << _yQ << "\"";
        if (_xR != NUM_NULL) ss << " x2=\"" << _xR << "\"";
        if (_yR != NUM_NULL) ss << " y2=\"" << _yR << "\"";
        ss << XMLElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<XMLElement> SVGLinearGradient::clone() const {
        return std::make_shared<SVGLinearGradient>(*this);
    }
    const std::string SVGLinearGradient::operator-(const XMLElement &element) const {
        std::stringstream ss;

        ss << XMLElement::operator-(element);
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

        return ss.str();
    }
}
