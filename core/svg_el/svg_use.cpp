#include "svg_use.h"

namespace Lewzen {
    SVGUse::SVGUse() {
        _href = STR_NULL;
        _x = STR_NULL;
        _y = STR_NULL;
        _width = STR_NULL;
        _height = STR_NULL;
    }
    const std::string SVGUse::get_tag() const {
        return "use";
    }
    const std::string SVGUse::get_href() const {
        return _href;
    }
    void SVGUse::set_href(const std::string &href) {
        _href = href;
        update_attribute_hash();
    }
    const std::string SVGUse::get_x() const {
        return _x;
    }
    void SVGUse::set_x(const std::string &x) {
        _x = x;
        update_attribute_hash();
    }
    const std::string SVGUse::get_y() const {
        return _y;
    }
    void SVGUse::set_y(const std::string &y) {
        _y = y;
        update_attribute_hash();
    }
    const std::string SVGUse::get_width() const {
        return _width;
    }
    void SVGUse::set_width(const std::string &width) {
        _width = width;
        update_attribute_hash();
    }
    const std::string SVGUse::get_height() const {
        return _height;
    }
    void SVGUse::set_height(const std::string &height) {
        _height = height;
        update_attribute_hash();
    }
    const std::string SVGUse::get_attributes() const {
        std::stringstream ss;

        if (_href != STR_NULL) ss << " href=\"" << _href << "\"";
        if (_x != STR_NULL) ss << " x=\"" << _x << "\"";
        if (_y != STR_NULL) ss << " y=\"" << _y << "\"";
        if (_width != STR_NULL) ss << " width=\"" << _width << "\"";
        if (_height != STR_NULL) ss << " height=\"" << _height << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGUse::clone() const {
        return clone(true);
    }
    std::shared_ptr<SVGUse> SVGUse::clone(bool identity) const {
        auto cloned =  std::make_shared<SVGUse>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGUse::operator=(const SVGElement &element) {
        return SVGElement::operator=(element);
    }
    SVGUse &SVGUse::operator=(const SVGUse &element) {
        SVGElement::operator=(element);
        return *this;

        _href = element.get_href();
        _x = element.get_x();
        _y = element.get_y();
        _width = element.get_width();
        _height = element.get_height();
        return *this;
    }
    const std::string SVGUse::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = dynamic_cast<const SVGUse &>(element);

        // attribute differ
        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);

        return ss.str();
    }
    const std::string SVGUse::attribute_differ(const SVGUse &element) const {
        std::stringstream ss;

        if (_href != element.get_href()) {
            if (_href == STR_NULL) ss << "reset href" << std::endl;
            else ss << "modify href \"" << _href << "\"" << std::endl;
        }
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

        return ss.str();
    }
}
