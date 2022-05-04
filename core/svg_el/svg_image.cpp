#include "svg_image.h"

namespace Lewzen {
    SVGImage::SVGImage() {
        _width = STR_NULL;
        _height = STR_NULL;
        _x = STR_NULL;
        _y = STR_NULL;
        _href = STR_NULL;
        _xlinkZhref = STR_NULL;
        _preserve_aspect_ratio = STR_NULL;
        _crossorigin = STR_NULL;
    }
    const std::string SVGImage::get_tag() const {
        return "image";
    }
    const std::string SVGImage::get_width() const {
        return _width;
    }
    void SVGImage::set_width(const std::string &width) {
        _width = width;
        update_attribute_hash();
    }
    const std::string SVGImage::get_height() const {
        return _height;
    }
    void SVGImage::set_height(const std::string &height) {
        _height = height;
        update_attribute_hash();
    }
    const std::string SVGImage::get_x() const {
        return _x;
    }
    void SVGImage::set_x(const std::string &x) {
        _x = x;
        update_attribute_hash();
    }
    const std::string SVGImage::get_y() const {
        return _y;
    }
    void SVGImage::set_y(const std::string &y) {
        _y = y;
        update_attribute_hash();
    }
    const std::string SVGImage::get_href() const {
        return _href;
    }
    void SVGImage::set_href(const std::string &href) {
        _href = href;
        update_attribute_hash();
    }
    const std::string SVGImage::get_xlinkZhref() const {
        return _xlinkZhref;
    }
    void SVGImage::set_xlinkZhref(const std::string &xlinkZhref) {
        _xlinkZhref = xlinkZhref;
        update_attribute_hash();
    }
    const std::string SVGImage::get_preserve_aspect_ratio() const {
        return _preserve_aspect_ratio;
    }
    void SVGImage::set_preserve_aspect_ratio(const std::string &preserve_aspect_ratio) {
        _preserve_aspect_ratio = preserve_aspect_ratio;
        update_attribute_hash();
    }
    const std::string SVGImage::get_crossorigin() const {
        return _crossorigin;
    }
    void SVGImage::set_crossorigin(const std::string &crossorigin) {
        _crossorigin = crossorigin;
        update_attribute_hash();
    }
    const std::string SVGImage::get_attributes() const {
        std::stringstream ss;

        if (_width != STR_NULL) ss << " width=\"" << _width << "\"";
        if (_height != STR_NULL) ss << " height=\"" << _height << "\"";
        if (_x != STR_NULL) ss << " x=\"" << _x << "\"";
        if (_y != STR_NULL) ss << " y=\"" << _y << "\"";
        if (_href != STR_NULL) ss << " href=\"" << _href << "\"";
        if (_xlinkZhref != STR_NULL) ss << " xlink:href=\"" << _xlinkZhref << "\"";
        if (_preserve_aspect_ratio != STR_NULL) ss << " preserveAspectRatio=\"" << _preserve_aspect_ratio << "\"";
        if (_crossorigin != STR_NULL) ss << " crossorigin=\"" << _crossorigin << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGImage::clone() const {
        return clone(true);
    }
    std::shared_ptr<SVGImage> SVGImage::clone(bool identity) const {
        auto cloned =  std::make_shared<SVGImage>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGImage::operator=(const SVGElement &element) {
        return SVGElement::operator=(element);
    }
    SVGImage &SVGImage::operator=(const SVGImage &element) {
        SVGElement::operator=(element);
        return *this;

        _width = element.get_width();
        _height = element.get_height();
        _x = element.get_x();
        _y = element.get_y();
        _href = element.get_href();
        _xlinkZhref = element.get_xlinkZhref();
        _preserve_aspect_ratio = element.get_preserve_aspect_ratio();
        _crossorigin = element.get_crossorigin();
        return *this;
    }
    const std::string SVGImage::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = dynamic_cast<const SVGImage &>(element);

        // attribute differ
        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);

        return ss.str();
    }
    const std::string SVGImage::attribute_differ(const SVGImage &element) const {
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
        if (_href != element.get_href()) {
            if (_href == STR_NULL) ss << "reset href" << std::endl;
            else ss << "modify href \"" << _href << "\"" << std::endl;
        }
        if (_xlinkZhref != element.get_xlinkZhref()) {
            if (_xlinkZhref == STR_NULL) ss << "reset xlink:href" << std::endl;
            else ss << "modify xlink:href \"" << _xlinkZhref << "\"" << std::endl;
        }
        if (_preserve_aspect_ratio != element.get_preserve_aspect_ratio()) {
            if (_preserve_aspect_ratio == STR_NULL) ss << "reset preserveAspectRatio" << std::endl;
            else ss << "modify preserveAspectRatio \"" << _preserve_aspect_ratio << "\"" << std::endl;
        }
        if (_crossorigin != element.get_crossorigin()) {
            if (_crossorigin == STR_NULL) ss << "reset crossorigin" << std::endl;
            else ss << "modify crossorigin \"" << _crossorigin << "\"" << std::endl;
        }

        return ss.str();
    }
}
