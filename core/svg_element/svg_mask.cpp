#include "svg_mask.h"

namespace Lewzen {
    SVGMask::SVGMask() {
        _width = NUM_NULL;
        _height = NUM_NULL;
        _x = NUM_NULL;
        _y = NUM_NULL;
        _mask_content_units = MaskContentUnits::USER_SPACE_ON_USE;
        _mask_units = MaskUnits::OBJECT_BOUNDING_BOX;
    }
    SVGMask::SVGMask(const SVGMask &element) {
        _width = element.get_width();
        _height = element.get_height();
        _x = element.get_x();
        _y = element.get_y();
        _mask_content_units = element.get_mask_content_units();
        _mask_units = element.get_mask_units();
        new (this)SVGElement(element);
    }
    const std::string SVGMask::get_tag() const {
        return "mask";
    }
    double SVGMask::get_width() const {
        return _width;
    }
    void SVGMask::set_width(const double &width) {
        _width = width;
    }
    double SVGMask::get_height() const {
        return _height;
    }
    void SVGMask::set_height(const double &height) {
        _height = height;
    }
    double SVGMask::get_x() const {
        return _x;
    }
    void SVGMask::set_x(const double &x) {
        _x = x;
    }
    double SVGMask::get_y() const {
        return _y;
    }
    void SVGMask::set_y(const double &y) {
        _y = y;
    }
    const SVGMask::MaskContentUnits SVGMask::get_mask_content_units() const {
        return _mask_content_units;
    }
    void SVGMask::set_mask_content_units(const SVGMask::MaskContentUnits &mask_content_units) {
        _mask_content_units = mask_content_units;
    }
    const SVGMask::MaskUnits SVGMask::get_mask_units() const {
        return _mask_units;
    }
    void SVGMask::set_mask_units(const SVGMask::MaskUnits &mask_units) {
        _mask_units = mask_units;
    }
    const std::string SVGMask::get_attributes() const {
        std::stringstream ss;

        if (_width != NUM_NULL) ss << " width=\"" << _width << "\"";
        if (_height != NUM_NULL) ss << " height=\"" << _height << "\"";
        if (_x != NUM_NULL) ss << " x=\"" << _x << "\"";
        if (_y != NUM_NULL) ss << " y=\"" << _y << "\"";
        if (_mask_content_units == MaskContentUnits::OBJECT_BOUNDING_BOX) ss << " maskContentUnits=\"objectBoundingBox\"";
        if (_mask_units == MaskUnits::USER_SPACE_ON_USE) ss << " maskUnits=\"userSpaceOnUse\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGMask::clone() const {
        return std::make_shared<SVGMask>(*this);
    }
    const std::string SVGMask::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = static_cast<const SVGMask &>(element);

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
        if (_mask_content_units != _element.get_mask_content_units()) {
            if (_mask_content_units == MaskContentUnits::USER_SPACE_ON_USE) ss << "reset maskContentUnits" << std::endl;
            else if (_mask_content_units == MaskContentUnits::OBJECT_BOUNDING_BOX) ss << "modify maskContentUnits \"objectBoundingBox\"" << std::endl;
        }
        if (_mask_units != _element.get_mask_units()) {
            if (_mask_units == MaskUnits::OBJECT_BOUNDING_BOX) ss << "reset maskUnits" << std::endl;
            else if (_mask_units == MaskUnits::USER_SPACE_ON_USE) ss << "modify maskUnits \"userSpaceOnUse\"" << std::endl;
        }

        return ss.str();
    }
}
