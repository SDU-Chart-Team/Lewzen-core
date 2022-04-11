#include "svg_use.h"

namespace Lewzen {
    SVGUse::SVGUse() {
        _width = NUM_NULL;
        _height = NUM_NULL;
        _x = NUM_NULL;
        _y = NUM_NULL;
        _href = STR_NULL;
    }
    SVGUse::SVGUse(const SVGUse &element) {
        _width = element.get_width();
        _height = element.get_height();
        _x = element.get_x();
        _y = element.get_y();
        _href = element.get_href();
        new (this)SVGElement(element);
    }
    const std::string SVGUse::get_tag() const {
        return "use";
    }
    double SVGUse::get_width() const {
        return _width;
    }
    void SVGUse::set_width(const double &width) {
        _width = width;
    }
    double SVGUse::get_height() const {
        return _height;
    }
    void SVGUse::set_height(const double &height) {
        _height = height;
    }
    double SVGUse::get_x() const {
        return _x;
    }
    void SVGUse::set_x(const double &x) {
        _x = x;
    }
    double SVGUse::get_y() const {
        return _y;
    }
    void SVGUse::set_y(const double &y) {
        _y = y;
    }
    const std::string SVGUse::get_href() const {
        return _href;
    }
    void SVGUse::set_href(const std::string &href) {
        _href = href;
    }
    const std::string SVGUse::get_attributes() const {
        std::stringstream ss;

        if (_width != NUM_NULL) ss << " width=\"" << _width << "\"";
        if (_height != NUM_NULL) ss << " height=\"" << _height << "\"";
        if (_x != NUM_NULL) ss << " x=\"" << _x << "\"";
        if (_y != NUM_NULL) ss << " y=\"" << _y << "\"";
        if (_href != STR_NULL) ss << " href=\"" << _href << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGUse::clone() const {
        return std::make_shared<SVGUse>(*this);
    }
    const std::string SVGUse::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = static_cast<const SVGUse &>(element);

        if (_width != _element.get_width()) {
            if (_width == NUM_NULL) ss << "reset width" << std::endl;
            else ss << "modify width " << _width << std::endl;
        }
        if (_height != _element.get_height()) {
            if (_height == NUM_NULL) ss << "reset height" << std::endl;
            else ss << "modify height " << _height << std::endl;
        }
        if (_x != _element.get_x()) {
            if (_x == NUM_NULL) ss << "reset x" << std::endl;
            else ss << "modify x " << _x << std::endl;
        }
        if (_y != _element.get_y()) {
            if (_y == NUM_NULL) ss << "reset y" << std::endl;
            else ss << "modify y " << _y << std::endl;
        }
        if (_href != _element.get_href()) {
            if (_href == STR_NULL) ss << "reset href" << std::endl;
            else ss << "modify href \"" << _href << "\"" << std::endl;
        }

        return ss.str();
    }
}
