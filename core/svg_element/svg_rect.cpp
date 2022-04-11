#include "svg_rect.h"

namespace Lewzen {
    SVGRect::SVGRect() {
        _x = NUM_NULL;
        _y = NUM_NULL;
        _width = NUM_NULL;
        _height = NUM_NULL;
        _rx = NUM_NULL;
        _ry = NUM_NULL;
        _path_length = NUM_NULL;
    }
    SVGRect::SVGRect(const SVGRect &element) {
        _x = element.get_x();
        _y = element.get_y();
        _width = element.get_width();
        _height = element.get_height();
        _rx = element.get_rx();
        _ry = element.get_ry();
        _path_length = element.get_path_length();
        new (this)SVGElement(element);
    }
    const std::string SVGRect::get_tag() const {
        return "rect";
    }
    double SVGRect::get_x() const {
        return _x;
    }
    void SVGRect::set_x(const double &x) {
        _x = x;
    }
    double SVGRect::get_y() const {
        return _y;
    }
    void SVGRect::set_y(const double &y) {
        _y = y;
    }
    double SVGRect::get_width() const {
        return _width;
    }
    void SVGRect::set_width(const double &width) {
        _width = width;
    }
    double SVGRect::get_height() const {
        return _height;
    }
    void SVGRect::set_height(const double &height) {
        _height = height;
    }
    double SVGRect::get_rx() const {
        return _rx;
    }
    void SVGRect::set_rx(const double &rx) {
        _rx = rx;
    }
    double SVGRect::get_ry() const {
        return _ry;
    }
    void SVGRect::set_ry(const double &ry) {
        _ry = ry;
    }
    double SVGRect::get_path_length() const {
        return _path_length;
    }
    void SVGRect::set_path_length(const double &path_length) {
        _path_length = path_length;
    }
    const std::string SVGRect::get_attributes() const {
        std::stringstream ss;

        if (_x != NUM_NULL) ss << " x=\"" << _x << "\"";
        if (_y != NUM_NULL) ss << " y=\"" << _y << "\"";
        if (_width != NUM_NULL) ss << " width=\"" << _width << "\"";
        if (_height != NUM_NULL) ss << " height=\"" << _height << "\"";
        if (_rx != NUM_NULL) ss << " rx=\"" << _rx << "\"";
        if (_ry != NUM_NULL) ss << " ry=\"" << _ry << "\"";
        if (_path_length != NUM_NULL) ss << " pathLength=\"" << _path_length << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGRect::clone() const {
        return std::make_shared<SVGRect>(*this);
    }
    const std::string SVGRect::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = static_cast<const SVGRect &>(element);

        if (_x != _element.get_x()) {
            if (_x == NUM_NULL) ss << "reset x" << std::endl;
            else ss << "modify x " << _x << std::endl;
        }
        if (_y != _element.get_y()) {
            if (_y == NUM_NULL) ss << "reset y" << std::endl;
            else ss << "modify y " << _y << std::endl;
        }
        if (_width != _element.get_width()) {
            if (_width == NUM_NULL) ss << "reset width" << std::endl;
            else ss << "modify width " << _width << std::endl;
        }
        if (_height != _element.get_height()) {
            if (_height == NUM_NULL) ss << "reset height" << std::endl;
            else ss << "modify height " << _height << std::endl;
        }
        if (_rx != _element.get_rx()) {
            if (_rx == NUM_NULL) ss << "reset rx" << std::endl;
            else ss << "modify rx " << _rx << std::endl;
        }
        if (_ry != _element.get_ry()) {
            if (_ry == NUM_NULL) ss << "reset ry" << std::endl;
            else ss << "modify ry " << _ry << std::endl;
        }
        if (_path_length != _element.get_path_length()) {
            if (_path_length == NUM_NULL) ss << "reset pathLength" << std::endl;
            else ss << "modify pathLength " << _path_length << std::endl;
        }

        return ss.str();
    }
}
