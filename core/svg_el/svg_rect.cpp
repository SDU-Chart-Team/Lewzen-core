#include "svg_rect.h"

namespace Lewzen {
    SVGRect::SVGRect() {
        _x = STR_NULL;
        _y = STR_NULL;
        _width = STR_NULL;
        _height = STR_NULL;
        _preserve_aspect_ratio = STR_NULL;
        _view_box = STR_NULL;
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
    const std::string SVGRect::get_preserve_aspect_ratio() const {
        return _preserve_aspect_ratio;
    }
    void SVGRect::set_preserve_aspect_ratio(const std::string &preserve_aspect_ratio) {
        _preserve_aspect_ratio = preserve_aspect_ratio;
        update_attribute_hash();
    }
    const std::string SVGRect::get_view_box() const {
        return _view_box;
    }
    void SVGRect::set_view_box(const std::string &view_box) {
        _view_box = view_box;
        update_attribute_hash();
    }
    const std::string SVGRect::get_attributes() const {
        std::stringstream ss;

        if (_x != STR_NULL) ss << " x=\"" << _x << "\"";
        if (_y != STR_NULL) ss << " y=\"" << _y << "\"";
        if (_width != STR_NULL) ss << " width=\"" << _width << "\"";
        if (_height != STR_NULL) ss << " height=\"" << _height << "\"";
        if (_preserve_aspect_ratio != STR_NULL) ss << " preserveAspectRatio=\"" << _preserve_aspect_ratio << "\"";
        if (_view_box != STR_NULL) ss << " viewBox=\"" << _view_box << "\"";
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
        _preserve_aspect_ratio = element.get_preserve_aspect_ratio();
        _view_box = element.get_view_box();
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
        if (_preserve_aspect_ratio != element.get_preserve_aspect_ratio()) {
            if (_preserve_aspect_ratio == STR_NULL) ss << "reset preserveAspectRatio" << std::endl;
            else ss << "modify preserveAspectRatio \"" << _preserve_aspect_ratio << "\"" << std::endl;
        }
        if (_view_box != element.get_view_box()) {
            if (_view_box == STR_NULL) ss << "reset viewBox" << std::endl;
            else ss << "modify viewBox \"" << _view_box << "\"" << std::endl;
        }

        return ss.str();
    }
}
