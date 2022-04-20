#include "svg_stop.h"

namespace Lewzen {
    SVGStop::SVGStop() {
        _offset = STR_NULL;
        _stop_color = STR_NULL;
        _stop_opacity = STR_NULL;
    }
    SVGStop::SVGStop(const SVGStop &element) {
        _offset = element.get_offset();
        _stop_color = element.get_stop_color();
        _stop_opacity = element.get_stop_opacity();
        new (this)SVGElement(element);
    }
    const std::string SVGStop::get_tag() const {
        return "stop";
    }
    const std::string SVGStop::get_offset() const {
        return _offset;
    }
    void SVGStop::set_offset(const std::string &offset) {
        _offset = offset;
        update_hash();
    }
    const std::string SVGStop::get_stop_color() const {
        return _stop_color;
    }
    void SVGStop::set_stop_color(const std::string &stop_color) {
        _stop_color = stop_color;
        update_hash();
    }
    const std::string SVGStop::get_stop_opacity() const {
        return _stop_opacity;
    }
    void SVGStop::set_stop_opacity(const std::string &stop_opacity) {
        _stop_opacity = stop_opacity;
        update_hash();
    }
    const std::string SVGStop::get_attributes() const {
        std::stringstream ss;

        if (_offset != STR_NULL) ss << " offset=\"" << _offset << "\"";
        if (_stop_color != STR_NULL) ss << " stop-color=\"" << _stop_color << "\"";
        if (_stop_opacity != STR_NULL) ss << " stop-opacity=\"" << _stop_opacity << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGStop::clone() const {
        return std::make_shared<SVGStop>(*this);
    }
    const std::string SVGStop::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = static_cast<const SVGStop &>(element);

        if (_offset != _element.get_offset()) {
            if (_offset == STR_NULL) ss << "reset offset" << std::endl;
            else ss << "modify offset \"" << _offset << "\"" << std::endl;
        }
        if (_stop_color != _element.get_stop_color()) {
            if (_stop_color == STR_NULL) ss << "reset stop-color" << std::endl;
            else ss << "modify stop-color \"" << _stop_color << "\"" << std::endl;
        }
        if (_stop_opacity != _element.get_stop_opacity()) {
            if (_stop_opacity == STR_NULL) ss << "reset stop-opacity" << std::endl;
            else ss << "modify stop-opacity \"" << _stop_opacity << "\"" << std::endl;
        }

        return ss.str();
    }
}
