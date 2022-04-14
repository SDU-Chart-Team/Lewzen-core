#include "svg_ellipse.h"

namespace Lewzen {
    SVGEllipse::SVGEllipse() {
        _cx = STR_NULL;
        _cy = STR_NULL;
        _rx = STR_NULL;
        _ry = STR_NULL;
        _path_length = STR_NULL;
    }
    SVGEllipse::SVGEllipse(const SVGEllipse &element) {
        _cx = element.get_cx();
        _cy = element.get_cy();
        _rx = element.get_rx();
        _ry = element.get_ry();
        _path_length = element.get_path_length();
        new (this)SVGElement(element);
    }
    const std::string SVGEllipse::get_tag() const {
        return "ellipse";
    }
    const std::string SVGEllipse::get_cx() const {
        return _cx;
    }
    void SVGEllipse::set_cx(const std::string &cx) {
        _cx = cx;
        update_hash();
    }
    const std::string SVGEllipse::get_cy() const {
        return _cy;
    }
    void SVGEllipse::set_cy(const std::string &cy) {
        _cy = cy;
        update_hash();
    }
    const std::string SVGEllipse::get_rx() const {
        return _rx;
    }
    void SVGEllipse::set_rx(const std::string &rx) {
        _rx = rx;
        update_hash();
    }
    const std::string SVGEllipse::get_ry() const {
        return _ry;
    }
    void SVGEllipse::set_ry(const std::string &ry) {
        _ry = ry;
        update_hash();
    }
    const std::string SVGEllipse::get_path_length() const {
        return _path_length;
    }
    void SVGEllipse::set_path_length(const std::string &path_length) {
        _path_length = path_length;
        update_hash();
    }
    const std::string SVGEllipse::get_attributes() const {
        std::stringstream ss;

        if (_cx != STR_NULL) ss << " cx=\"" << _cx << "\"";
        if (_cy != STR_NULL) ss << " cy=\"" << _cy << "\"";
        if (_rx != STR_NULL) ss << " rx=\"" << _rx << "\"";
        if (_ry != STR_NULL) ss << " ry=\"" << _ry << "\"";
        if (_path_length != STR_NULL) ss << " pathLength=\"" << _path_length << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGEllipse::clone() const {
        return std::make_shared<SVGEllipse>(*this);
    }
    const std::string SVGEllipse::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = static_cast<const SVGEllipse &>(element);

        if (_cx != _element.get_cx()) {
            if (_cx == STR_NULL) ss << "reset cx" << std::endl;
            else ss << "modify cx \"" << _cx << "\"" << std::endl;
        }
        if (_cy != _element.get_cy()) {
            if (_cy == STR_NULL) ss << "reset cy" << std::endl;
            else ss << "modify cy \"" << _cy << "\"" << std::endl;
        }
        if (_rx != _element.get_rx()) {
            if (_rx == STR_NULL) ss << "reset rx" << std::endl;
            else ss << "modify rx \"" << _rx << "\"" << std::endl;
        }
        if (_ry != _element.get_ry()) {
            if (_ry == STR_NULL) ss << "reset ry" << std::endl;
            else ss << "modify ry \"" << _ry << "\"" << std::endl;
        }
        if (_path_length != _element.get_path_length()) {
            if (_path_length == STR_NULL) ss << "reset pathLength" << std::endl;
            else ss << "modify pathLength \"" << _path_length << "\"" << std::endl;
        }

        return ss.str();
    }
}
