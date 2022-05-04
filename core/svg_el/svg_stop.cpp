#include "svg_stop.h"

namespace Lewzen {
    SVGStop::SVGStop() {
        _offset = STR_NULL;
        _stop_color = STR_NULL;
        _stop_opacity = STR_NULL;
    }
    const std::string SVGStop::get_tag() const {
        return "stop";
    }
    const std::string SVGStop::get_offset() const {
        return _offset;
    }
    void SVGStop::set_offset(const std::string &offset) {
        _offset = offset;
        update_attribute_hash();
    }
    const std::string SVGStop::get_stop_color() const {
        return _stop_color;
    }
    void SVGStop::set_stop_color(const std::string &stop_color) {
        _stop_color = stop_color;
        update_attribute_hash();
    }
    const std::string SVGStop::get_stop_opacity() const {
        return _stop_opacity;
    }
    void SVGStop::set_stop_opacity(const std::string &stop_opacity) {
        _stop_opacity = stop_opacity;
        update_attribute_hash();
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
        return clone(true);
    }
    std::shared_ptr<SVGStop> SVGStop::clone(bool identity) const {
        auto cloned =  std::make_shared<SVGStop>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGStop::operator=(const SVGElement &element) {
        return SVGElement::operator=(element);
    }
    SVGStop &SVGStop::operator=(const SVGStop &element) {
        SVGElement::operator=(element);
        return *this;

        _offset = element.get_offset();
        _stop_color = element.get_stop_color();
        _stop_opacity = element.get_stop_opacity();
        return *this;
    }
    const std::string SVGStop::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = dynamic_cast<const SVGStop &>(element);

        // attribute differ
        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);

        return ss.str();
    }
    const std::string SVGStop::attribute_differ(const SVGStop &element) const {
        std::stringstream ss;

        if (_offset != element.get_offset()) {
            if (_offset == STR_NULL) ss << "reset offset" << std::endl;
            else ss << "modify offset \"" << _offset << "\"" << std::endl;
        }
        if (_stop_color != element.get_stop_color()) {
            if (_stop_color == STR_NULL) ss << "reset stop-color" << std::endl;
            else ss << "modify stop-color \"" << _stop_color << "\"" << std::endl;
        }
        if (_stop_opacity != element.get_stop_opacity()) {
            if (_stop_opacity == STR_NULL) ss << "reset stop-opacity" << std::endl;
            else ss << "modify stop-opacity \"" << _stop_opacity << "\"" << std::endl;
        }

        return ss.str();
    }
}
