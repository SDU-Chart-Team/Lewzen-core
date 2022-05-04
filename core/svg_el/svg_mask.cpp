#include "svg_mask.h"

namespace Lewzen {
    SVGMask::SVGMask() {
        _height = STR_NULL;
        _mask_content_units = STR_NULL;
        _mask_units = STR_NULL;
        _x = STR_NULL;
        _y = STR_NULL;
        _width = STR_NULL;
    }
    const std::string SVGMask::get_tag() const {
        return "mask";
    }
    const std::string SVGMask::get_height() const {
        return _height;
    }
    void SVGMask::set_height(const std::string &height) {
        _height = height;
        update_attribute_hash();
    }
    const std::string SVGMask::get_mask_content_units() const {
        return _mask_content_units;
    }
    void SVGMask::set_mask_content_units(const std::string &mask_content_units) {
        _mask_content_units = mask_content_units;
        update_attribute_hash();
    }
    const std::string SVGMask::get_mask_units() const {
        return _mask_units;
    }
    void SVGMask::set_mask_units(const std::string &mask_units) {
        _mask_units = mask_units;
        update_attribute_hash();
    }
    const std::string SVGMask::get_x() const {
        return _x;
    }
    void SVGMask::set_x(const std::string &x) {
        _x = x;
        update_attribute_hash();
    }
    const std::string SVGMask::get_y() const {
        return _y;
    }
    void SVGMask::set_y(const std::string &y) {
        _y = y;
        update_attribute_hash();
    }
    const std::string SVGMask::get_width() const {
        return _width;
    }
    void SVGMask::set_width(const std::string &width) {
        _width = width;
        update_attribute_hash();
    }
    const std::string SVGMask::get_attributes() const {
        std::stringstream ss;

        if (_height != STR_NULL) ss << " height=\"" << _height << "\"";
        if (_mask_content_units != STR_NULL) ss << " maskContentUnits=\"" << _mask_content_units << "\"";
        if (_mask_units != STR_NULL) ss << " maskUnits=\"" << _mask_units << "\"";
        if (_x != STR_NULL) ss << " x=\"" << _x << "\"";
        if (_y != STR_NULL) ss << " y=\"" << _y << "\"";
        if (_width != STR_NULL) ss << " width=\"" << _width << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGMask::clone() const {
        return clone(true);
    }
    std::shared_ptr<SVGMask> SVGMask::clone(bool identity) const {
        auto cloned =  std::make_shared<SVGMask>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGMask::operator=(const SVGElement &element) {
        return SVGElement::operator=(element);
    }
    SVGMask &SVGMask::operator=(const SVGMask &element) {
        SVGElement::operator=(element);
        return *this;

        _height = element.get_height();
        _mask_content_units = element.get_mask_content_units();
        _mask_units = element.get_mask_units();
        _x = element.get_x();
        _y = element.get_y();
        _width = element.get_width();
        return *this;
    }
    const std::string SVGMask::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = dynamic_cast<const SVGMask &>(element);

        // attribute differ
        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);

        return ss.str();
    }
    const std::string SVGMask::attribute_differ(const SVGMask &element) const {
        std::stringstream ss;

        if (_height != element.get_height()) {
            if (_height == STR_NULL) ss << "reset height" << std::endl;
            else ss << "modify height \"" << _height << "\"" << std::endl;
        }
        if (_mask_content_units != element.get_mask_content_units()) {
            if (_mask_content_units == STR_NULL) ss << "reset maskContentUnits" << std::endl;
            else ss << "modify maskContentUnits \"" << _mask_content_units << "\"" << std::endl;
        }
        if (_mask_units != element.get_mask_units()) {
            if (_mask_units == STR_NULL) ss << "reset maskUnits" << std::endl;
            else ss << "modify maskUnits \"" << _mask_units << "\"" << std::endl;
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

        return ss.str();
    }
}
