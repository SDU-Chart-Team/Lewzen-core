#include "svg_text.h"

namespace Lewzen {
    SVGText::SVGText() {
        _x = STR_NULL;
        _y = STR_NULL;
        _dx = STR_NULL;
        _dy = STR_NULL;
        _rotate = STR_NULL;
        _length_adjust = STR_NULL;
        _text_length = STR_NULL;
    }
    const std::string SVGText::get_tag() const {
        return "text";
    }
    const std::string SVGText::get_x() const {
        return _x;
    }
    void SVGText::set_x(const std::string &x) {
        _x = x;
        update_attribute_hash();
    }
    const std::string SVGText::get_y() const {
        return _y;
    }
    void SVGText::set_y(const std::string &y) {
        _y = y;
        update_attribute_hash();
    }
    const std::string SVGText::get_dx() const {
        return _dx;
    }
    void SVGText::set_dx(const std::string &dx) {
        _dx = dx;
        update_attribute_hash();
    }
    const std::string SVGText::get_dy() const {
        return _dy;
    }
    void SVGText::set_dy(const std::string &dy) {
        _dy = dy;
        update_attribute_hash();
    }
    const std::string SVGText::get_rotate() const {
        return _rotate;
    }
    void SVGText::set_rotate(const std::string &rotate) {
        _rotate = rotate;
        update_attribute_hash();
    }
    const std::string SVGText::get_length_adjust() const {
        return _length_adjust;
    }
    void SVGText::set_length_adjust(const std::string &length_adjust) {
        _length_adjust = length_adjust;
        update_attribute_hash();
    }
    const std::string SVGText::get_text_length() const {
        return _text_length;
    }
    void SVGText::set_text_length(const std::string &text_length) {
        _text_length = text_length;
        update_attribute_hash();
    }
    const std::string SVGText::get_attributes() const {
        std::stringstream ss;

        if (_x != STR_NULL) ss << " x=\"" << _x << "\"";
        if (_y != STR_NULL) ss << " y=\"" << _y << "\"";
        if (_dx != STR_NULL) ss << " dx=\"" << _dx << "\"";
        if (_dy != STR_NULL) ss << " dy=\"" << _dy << "\"";
        if (_rotate != STR_NULL) ss << " rotate=\"" << _rotate << "\"";
        if (_length_adjust != STR_NULL) ss << " lengthAdjust=\"" << _length_adjust << "\"";
        if (_text_length != STR_NULL) ss << " textLength=\"" << _text_length << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGText::clone() const {
        return clone(true);
    }
    std::shared_ptr<SVGText> SVGText::clone(bool identity) const {
        auto cloned =  std::make_shared<SVGText>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGText::operator=(const SVGElement &element) {
        return SVGElement::operator=(element);
    }
    SVGText &SVGText::operator=(const SVGText &element) {
        SVGElement::operator=(element);
        return *this;

        _x = element.get_x();
        _y = element.get_y();
        _dx = element.get_dx();
        _dy = element.get_dy();
        _rotate = element.get_rotate();
        _length_adjust = element.get_length_adjust();
        _text_length = element.get_text_length();
        return *this;
    }
    const std::string SVGText::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = dynamic_cast<const SVGText &>(element);

        // attribute differ
        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);

        return ss.str();
    }
    const std::string SVGText::attribute_differ(const SVGText &element) const {
        std::stringstream ss;

        if (_x != element.get_x()) {
            if (_x == STR_NULL) ss << "reset x" << std::endl;
            else ss << "modify x \"" << _x << "\"" << std::endl;
        }
        if (_y != element.get_y()) {
            if (_y == STR_NULL) ss << "reset y" << std::endl;
            else ss << "modify y \"" << _y << "\"" << std::endl;
        }
        if (_dx != element.get_dx()) {
            if (_dx == STR_NULL) ss << "reset dx" << std::endl;
            else ss << "modify dx \"" << _dx << "\"" << std::endl;
        }
        if (_dy != element.get_dy()) {
            if (_dy == STR_NULL) ss << "reset dy" << std::endl;
            else ss << "modify dy \"" << _dy << "\"" << std::endl;
        }
        if (_rotate != element.get_rotate()) {
            if (_rotate == STR_NULL) ss << "reset rotate" << std::endl;
            else ss << "modify rotate \"" << _rotate << "\"" << std::endl;
        }
        if (_length_adjust != element.get_length_adjust()) {
            if (_length_adjust == STR_NULL) ss << "reset lengthAdjust" << std::endl;
            else ss << "modify lengthAdjust \"" << _length_adjust << "\"" << std::endl;
        }
        if (_text_length != element.get_text_length()) {
            if (_text_length == STR_NULL) ss << "reset textLength" << std::endl;
            else ss << "modify textLength \"" << _text_length << "\"" << std::endl;
        }

        return ss.str();
    }
}
