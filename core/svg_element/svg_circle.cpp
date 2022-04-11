#include "svg_circle.h"

namespace Lewzen {
    SVGCircle::SVGCircle() {
        _cx = NUM_NULL;
        _cy = NUM_NULL;
        _r = NUM_NULL;
        _path_length = NUM_NULL;
    }
    SVGCircle::SVGCircle(const SVGCircle &element) {
        _cx = element.get_cx();
        _cy = element.get_cy();
        _r = element.get_r();
        _path_length = element.get_path_length();
        new (this)SVGElement(element);
    }
    const std::string SVGCircle::get_tag() const {
        return "circle";
    }
    double SVGCircle::get_cx() const {
        return _cx;
    }
    void SVGCircle::set_cx(const double &cx) {
        _cx = cx;
    }
    double SVGCircle::get_cy() const {
        return _cy;
    }
    void SVGCircle::set_cy(const double &cy) {
        _cy = cy;
    }
    double SVGCircle::get_r() const {
        return _r;
    }
    void SVGCircle::set_r(const double &r) {
        _r = r;
    }
    double SVGCircle::get_path_length() const {
        return _path_length;
    }
    void SVGCircle::set_path_length(const double &path_length) {
        _path_length = path_length;
    }
    const std::string SVGCircle::get_attributes() const {
        std::stringstream ss;

        if (_cx != NUM_NULL) ss << " cx=\"" << _cx << "\"";
        if (_cy != NUM_NULL) ss << " cy=\"" << _cy << "\"";
        if (_r != NUM_NULL) ss << " r=\"" << _r << "\"";
        if (_path_length != NUM_NULL) ss << " pathLength=\"" << _path_length << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGCircle::clone() const {
        return std::make_shared<SVGCircle>(*this);
    }
    const std::string SVGCircle::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = static_cast<const SVGCircle &>(element);

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
        if (_path_length != _element.get_path_length()) {
            if (_path_length == NUM_NULL) ss << "reset pathLength" << std::endl;
            else ss << "modify pathLength " << _path_length << std::endl;
        }

        return ss.str();
    }
}
