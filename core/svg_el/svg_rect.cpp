#include "svg_rect.h"

namespace Lewzen {
    SVGRect::SVGRect() {
        _x = STR_NULL;
        _y = STR_NULL;
        _width = STR_NULL;
        _height = STR_NULL;
        _rx = STR_NULL;
        _ry = STR_NULL;
        _path_length = STR_NULL;
    }
    const std::string SVGRect::get_tag() const {
        return "rect";
    }
    const std::string SVGRect::get_x() const {
        return _x;
    }
    void SVGRect::set_x(const std::string &x) {
        _x = x;
        update_attribute_hash();
    }
    const std::string SVGRect::get_y() const {
        return _y;
    }
    void SVGRect::set_y(const std::string &y) {
        _y = y;
        update_attribute_hash();
    }
    const std::string SVGRect::get_width() const {
        return _width;
    }
    void SVGRect::set_width(const std::string &width) {
        _width = width;
        update_attribute_hash();
    }
    const std::string SVGRect::get_height() const {
        return _height;
    }
    void SVGRect::set_height(const std::string &height) {
        _height = height;
        update_attribute_hash();
    }
    const std::string SVGRect::get_rx() const {
        return _rx;
    }
    void SVGRect::set_rx(const std::string &rx) {
        _rx = rx;
        update_attribute_hash();
    }
    const std::string SVGRect::get_ry() const {
        return _ry;
    }
    void SVGRect::set_ry(const std::string &ry) {
        _ry = ry;
        update_attribute_hash();
    }
    const std::string SVGRect::get_path_length() const {
        return _path_length;
    }
    void SVGRect::set_path_length(const std::string &path_length) {
        _path_length = path_length;
        update_attribute_hash();
    }
    const std::string SVGRect::get_attributes() const {
        std::stringstream ss;

        if (_x != STR_NULL) ss << " x=\"" << _x << "\"";
        if (_y != STR_NULL) ss << " y=\"" << _y << "\"";
        if (_width != STR_NULL) ss << " width=\"" << _width << "\"";
        if (_height != STR_NULL) ss << " height=\"" << _height << "\"";
        if (_rx != STR_NULL) ss << " rx=\"" << _rx << "\"";
        if (_ry != STR_NULL) ss << " ry=\"" << _ry << "\"";
        if (_path_length != STR_NULL) ss << " pathLength=\"" << _path_length << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGRect::clone() const {
        return clone(true);
    }
    std::shared_ptr<SVGRect> SVGRect::clone(bool identity) const {
        auto cloned =  std::make_shared<SVGRect>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGRect::operator=(const SVGElement &element) {
        return SVGElement::operator=(element);
    }
    SVGRect &SVGRect::operator=(const SVGRect &element) {
        SVGElement::operator=(element);
        return *this;

        _x = element.get_x();
        _y = element.get_y();
        _width = element.get_width();
        _height = element.get_height();
        _rx = element.get_rx();
        _ry = element.get_ry();
        _path_length = element.get_path_length();
        return *this;
    }
    const std::string SVGRect::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = dynamic_cast<const SVGRect &>(element);

        // attribute differ
        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);

        return ss.str();
    }
    const std::string SVGRect::attribute_differ(const SVGRect &element) const {
        std::stringstream ss;

        if (_x != element.get_x()) {
            if (_x == STR_NULL) ss << "reset x" << std::endl;
            else ss << "modify x \"" << _x << "\"" << std::endl;
        }
        if (_y != element.get_y()) {
            if (_y == STR_NULL) ss << "reset y" << std::endl;
            else ss << "modify y \"" << _y << "\"" << std::endl;
        }
        if (_width != element.get_width()) {
            if (_width == STR_NULL) ss << "reset width" << std::endl;
            else ss << "modify width \"" << _width << "\"" << std::endl;
        }
        if (_height != element.get_height()) {
            if (_height == STR_NULL) ss << "reset height" << std::endl;
            else ss << "modify height \"" << _height << "\"" << std::endl;
        }
        if (_rx != element.get_rx()) {
            if (_rx == STR_NULL) ss << "reset rx" << std::endl;
            else ss << "modify rx \"" << _rx << "\"" << std::endl;
        }
        if (_ry != element.get_ry()) {
            if (_ry == STR_NULL) ss << "reset ry" << std::endl;
            else ss << "modify ry \"" << _ry << "\"" << std::endl;
        }
        if (_path_length != element.get_path_length()) {
            if (_path_length == STR_NULL) ss << "reset pathLength" << std::endl;
            else ss << "modify pathLength \"" << _path_length << "\"" << std::endl;
        }

        return ss.str();
    }
}
