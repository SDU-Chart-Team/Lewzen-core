#include "svg_foreign_object.h"

namespace Lewzen {
    SVGForeignObject::SVGForeignObject() {
        _width = STR_NULL;
        _height = STR_NULL;
        _x = STR_NULL;
        _y = STR_NULL;
    }
    const std::string SVGForeignObject::get_tag() const {
        return "foreignObject";
    }
    const std::string SVGForeignObject::get_width() const {
        return _width;
    }
    void SVGForeignObject::set_width(const std::string &width) {
        _width = width;
        update_attribute_hash();
    }
    const std::string SVGForeignObject::get_height() const {
        return _height;
    }
    void SVGForeignObject::set_height(const std::string &height) {
        _height = height;
        update_attribute_hash();
    }
    const std::string SVGForeignObject::get_x() const {
        return _x;
    }
    void SVGForeignObject::set_x(const std::string &x) {
        _x = x;
        update_attribute_hash();
    }
    const std::string SVGForeignObject::get_y() const {
        return _y;
    }
    void SVGForeignObject::set_y(const std::string &y) {
        _y = y;
        update_attribute_hash();
    }
    const std::string SVGForeignObject::get_attributes() const {
        std::stringstream ss;

        if (_width != STR_NULL) ss << " width=\"" << _width << "\"";
        if (_height != STR_NULL) ss << " height=\"" << _height << "\"";
        if (_x != STR_NULL) ss << " x=\"" << _x << "\"";
        if (_y != STR_NULL) ss << " y=\"" << _y << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGForeignObject::clone() const {
        return clone(true);
    }
    std::shared_ptr<SVGForeignObject> SVGForeignObject::clone(bool identity) const {
        auto cloned =  std::make_shared<SVGForeignObject>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGForeignObject::operator=(const SVGElement &element) {
        return SVGElement::operator=(element);
    }
    SVGForeignObject &SVGForeignObject::operator=(const SVGForeignObject &element) {
        SVGElement::operator=(element);
        return *this;

        _width = element.get_width();
        _height = element.get_height();
        _x = element.get_x();
        _y = element.get_y();
        return *this;
    }
    const std::string SVGForeignObject::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = dynamic_cast<const SVGForeignObject &>(element);

        // attribute differ
        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);

        return ss.str();
    }
    const std::string SVGForeignObject::attribute_differ(const SVGForeignObject &element) const {
        std::stringstream ss;

        if (_width != element.get_width()) {
            if (_width == STR_NULL) ss << "reset width" << std::endl;
            else ss << "modify width \"" << _width << "\"" << std::endl;
        }
        if (_height != element.get_height()) {
            if (_height == STR_NULL) ss << "reset height" << std::endl;
            else ss << "modify height \"" << _height << "\"" << std::endl;
        }
        if (_x != element.get_x()) {
            if (_x == STR_NULL) ss << "reset x" << std::endl;
            else ss << "modify x \"" << _x << "\"" << std::endl;
        }
        if (_y != element.get_y()) {
            if (_y == STR_NULL) ss << "reset y" << std::endl;
            else ss << "modify y \"" << _y << "\"" << std::endl;
        }

        return ss.str();
    }
}
