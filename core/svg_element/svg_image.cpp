#include "svg_image.h"

namespace Lewzen {
    SVGImage::SVGImage() {
        _width = NUM_NULL;
        _height = NUM_NULL;
        _x = NUM_NULL;
        _y = NUM_NULL;
        _href = STR_NULL;
        _preserve_aspect_ratio = STR_NULL;
        _crossorigin = STR_NULL;
    }
    SVGImage::SVGImage(const SVGImage &element) {
        _width = element.get_width();
        _height = element.get_height();
        _x = element.get_x();
        _y = element.get_y();
        _href = element.get_href();
        _preserve_aspect_ratio = element.get_preserve_aspect_ratio();
        _crossorigin = element.get_crossorigin();
        new (this)SVGElement(element);
    }
    const std::string SVGImage::get_tag() const {
        return "image";
    }
    double SVGImage::get_width() const {
        return _width;
    }
    void SVGImage::set_width(const double &width) {
        _width = width;
    }
    double SVGImage::get_height() const {
        return _height;
    }
    void SVGImage::set_height(const double &height) {
        _height = height;
    }
    double SVGImage::get_x() const {
        return _x;
    }
    void SVGImage::set_x(const double &x) {
        _x = x;
    }
    double SVGImage::get_y() const {
        return _y;
    }
    void SVGImage::set_y(const double &y) {
        _y = y;
    }
    const std::string SVGImage::get_href() const {
        return _href;
    }
    void SVGImage::set_href(const std::string &href) {
        _href = href;
    }
    const std::string SVGImage::get_preserve_aspect_ratio() const {
        return _preserve_aspect_ratio;
    }
    void SVGImage::set_preserve_aspect_ratio(const std::string &preserve_aspect_ratio) {
        _preserve_aspect_ratio = preserve_aspect_ratio;
    }
    const std::string SVGImage::get_crossorigin() const {
        return _crossorigin;
    }
    void SVGImage::set_crossorigin(const std::string &crossorigin) {
        _crossorigin = crossorigin;
    }
    const std::string SVGImage::get_attributes() const {
        std::stringstream ss;

        if (_width != NUM_NULL) ss << " width=\"" << _width << "\"";
        if (_height != NUM_NULL) ss << " height=\"" << _height << "\"";
        if (_x != NUM_NULL) ss << " x=\"" << _x << "\"";
        if (_y != NUM_NULL) ss << " y=\"" << _y << "\"";
        if (_href != STR_NULL) ss << " href=\"" << _href << "\"";
        if (_preserve_aspect_ratio != STR_NULL) ss << " preserveAspectRatio=\"" << _preserve_aspect_ratio << "\"";
        if (_crossorigin != STR_NULL) ss << " crossorigin=\"" << _crossorigin << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGImage::clone() const {
        return std::make_shared<SVGImage>(*this);
    }
    const std::string SVGImage::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = static_cast<const SVGImage &>(element);

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
        if (_preserve_aspect_ratio != _element.get_preserve_aspect_ratio()) {
            if (_preserve_aspect_ratio == STR_NULL) ss << "reset preserveAspectRatio" << std::endl;
            else ss << "modify preserveAspectRatio \"" << _preserve_aspect_ratio << "\"" << std::endl;
        }
        if (_crossorigin != _element.get_crossorigin()) {
            if (_crossorigin == STR_NULL) ss << "reset crossorigin" << std::endl;
            else ss << "modify crossorigin \"" << _crossorigin << "\"" << std::endl;
        }

        return ss.str();
    }
}
