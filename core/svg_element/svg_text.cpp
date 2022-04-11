#include "svg_text.h"

namespace Lewzen {
    SVGText::SVGText() {
        _x = NUM_NULL;
        _y = NUM_NULL;
        _dx = NUM_NULL;
        _dy = NUM_NULL;
        _rotate = STR_NULL;
        _length_adjust = LengthAdjust::SPACING;
        _text_length = NUM_NULL;
    }
    SVGText::SVGText(const SVGText &element) {
        _x = element.get_x();
        _y = element.get_y();
        _dx = element.get_dx();
        _dy = element.get_dy();
        _rotate = element.get_rotate();
        _length_adjust = element.get_length_adjust();
        _text_length = element.get_text_length();
        new (this)SVGElement(element);
    }
    const std::string SVGText::get_tag() const {
        return "text";
    }
    double SVGText::get_x() const {
        return _x;
    }
    void SVGText::set_x(const double &x) {
        _x = x;
    }
    double SVGText::get_y() const {
        return _y;
    }
    void SVGText::set_y(const double &y) {
        _y = y;
    }
    double SVGText::get_dx() const {
        return _dx;
    }
    void SVGText::set_dx(const double &dx) {
        _dx = dx;
    }
    double SVGText::get_dy() const {
        return _dy;
    }
    void SVGText::set_dy(const double &dy) {
        _dy = dy;
    }
    const std::string SVGText::get_rotate() const {
        return _rotate;
    }
    void SVGText::set_rotate(const std::string &rotate) {
        _rotate = rotate;
    }
    const SVGText::LengthAdjust SVGText::get_length_adjust() const {
        return _length_adjust;
    }
    void SVGText::set_length_adjust(const SVGText::LengthAdjust &length_adjust) {
        _length_adjust = length_adjust;
    }
    double SVGText::get_text_length() const {
        return _text_length;
    }
    void SVGText::set_text_length(const double &text_length) {
        _text_length = text_length;
    }
    const std::string SVGText::get_attributes() const {
        std::stringstream ss;

        if (_x != NUM_NULL) ss << " x=\"" << _x << "\"";
        if (_y != NUM_NULL) ss << " y=\"" << _y << "\"";
        if (_dx != NUM_NULL) ss << " dx=\"" << _dx << "\"";
        if (_dy != NUM_NULL) ss << " dy=\"" << _dy << "\"";
        if (_rotate != STR_NULL) ss << " rotate=\"" << _rotate << "\"";
        if (_length_adjust == LengthAdjust::SPACING_AND_GLYPHS) ss << " lengthAdjust=\"spacingAndGlyphs\"";
        if (_text_length != NUM_NULL) ss << " textLength=\"" << _text_length << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGText::clone() const {
        return std::make_shared<SVGText>(*this);
    }
    const std::string SVGText::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = static_cast<const SVGText &>(element);

        if (_x != _element.get_x()) {
            if (_x == NUM_NULL) ss << "reset x" << std::endl;
            else ss << "modify x " << _x << std::endl;
        }
        if (_y != _element.get_y()) {
            if (_y == NUM_NULL) ss << "reset y" << std::endl;
            else ss << "modify y " << _y << std::endl;
        }
        if (_dx != _element.get_dx()) {
            if (_dx == NUM_NULL) ss << "reset dx" << std::endl;
            else ss << "modify dx " << _dx << std::endl;
        }
        if (_dy != _element.get_dy()) {
            if (_dy == NUM_NULL) ss << "reset dy" << std::endl;
            else ss << "modify dy " << _dy << std::endl;
        }
        if (_rotate != _element.get_rotate()) {
            if (_rotate == STR_NULL) ss << "reset rotate" << std::endl;
            else ss << "modify rotate \"" << _rotate << "\"" << std::endl;
        }
        if (_length_adjust != _element.get_length_adjust()) {
            if (_length_adjust == LengthAdjust::SPACING) ss << "reset lengthAdjust" << std::endl;
            else if (_length_adjust == LengthAdjust::SPACING_AND_GLYPHS) ss << "modify lengthAdjust \"spacingAndGlyphs\"" << std::endl;
        }
        if (_text_length != _element.get_text_length()) {
            if (_text_length == NUM_NULL) ss << "reset textLength" << std::endl;
            else ss << "modify textLength " << _text_length << std::endl;
        }

        return ss.str();
    }
}
