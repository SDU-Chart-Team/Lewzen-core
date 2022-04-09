#include "svg_stop.h"

namespace Lewzen {
    SVGStop::SVGStop() {
        _offset = _stop_opacity = NUM_NULL;
        _stop_color = "";
    }
    double SVGStop::get_offset() const {
        return _offset;
    }
    void SVGStop::set_offset(const double &offset) {
        _offset = offset
    }
    const std::string &SVGStop::get_stop_color() const {
        return _stop_color;
    }
    void SVGStop::set_stop_color(const std::string &stop_color) {
        _stop_color = stop_color;
    }
    double SVGStop::get_stop_opacity() const {
        return _stop_opacity;
    }
    void SVGStop::set_stop_opacity(const double &stop_opacity) {
        _stop_opacity = stop_opacity;
    }
    std::string SVGStop::to_XML() const {
        std::stringstream ss;
        ss << "<stop";
        if (_offset != NUM_NULL) ss << " offset=\"" << _offset << "\"";
        if (_stop_color != "") ss << " stop-color=\"" << _stop_color << "\"";
        if (_stop_opacity != NUM_NULL) ss << " stop-opacity=\"" << _stop_opacity << "\"";
        ss << "/>" << std::endl;
        return ss.str();
    }
}