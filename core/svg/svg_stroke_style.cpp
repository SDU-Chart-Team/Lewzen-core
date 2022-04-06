#include "svg_stroke_style.h"

namespace Lewzen {
    SVGStrokeStyle::SVGStrokeStyle() {
        _stroke = _stroke_dasharray = STR_NULL;
        _stroke_width = _stroke_opacity = _stroke_miterlimit = _stroke_dashoffset = NUM_NULL;
        _stroke_linecap = SVGStrokeStyle::StrokeLinecap::BUTT;
        _stroke_linejoin = SVGStrokeStyle::StrokeLinejoin::MITER;
    }
    const std::string &SVGStrokeStyle::get_stroke() const {
        return _stroke;
    }
    void SVGStrokeStyle::set_stroke(const std::string &stroke) {
        _stroke = stroke;
    }
    double SVGStrokeStyle::get_stroke_width() const {
        return _stroke_width;
    }
    void SVGStrokeStyle::set_stroke_width(const double &stroke_width) {
        _stroke_width = stroke_width;
    }
    double SVGStrokeStyle::get_stroke_opacity() const {
        return _stroke_opacity;
    }
    void SVGStrokeStyle::set_stroke_opacity(const double &stroke_opacity) {
        _stroke_opacity = stroke_opacity;
    }
    const SVGStrokeStyle::StrokeLinecap &SVGStrokeStyle::get_stroke_linecap() const {
        return _stroke_linecap;
    }
    void SVGStrokeStyle::set_stroke_linecap(const SVGStrokeStyle::StrokeLinecap &stroke_linecap) {
        _stroke_linecap = stroke_linecap;
    }
    const SVGStrokeStyle::StrokeLinejoin &SVGStrokeStyle::get_stroke_linejoin() const {
        return _stroke_linejoin;
    }
    void SVGStrokeStyle::set_stroke_linejoin(const SVGStrokeStyle::StrokeLinejoin &stroke_linejoin) {
        _stroke_linejoin = stroke_linejoin;
    }
    double get_stroke_miterlimit() const {
        return _stroke_miterlimit;
    }
    void set_stroke_miterlimit(const double &stroke_miterlimit) {
        _stroke_miterlimit = stroke_miterlimit;
    }
    const std::string &SVGStrokeStyle::get_stroke_dasharray() const {
        return _stroke_dasharray;
    }
    void SVGStrokeStyle::set_stroke_dasharray(const std::string &stroke_dasharray) {
        _stroke_dasharray = stroke_dasharray;
    }
    double SVGStrokeStyle::get_stroke_dashoffset() const {
        return _stroke_dashoffset;
    }
    void SVGStrokeStyle::set_stroke_dashoffset(const double &stroke_dashoffset) {
        _stroke_dashoffset = stroke_dashoffset;
    }
    const std::string &SVGFillStyle::to_properties() const override {
        std::stringstream ss;
        ss << " ";
        if (_stroke != STR_NULL) ss << "stroke=\"" << _stroke << "\" ";
        if (_stroke_width != NUM_NULL) ss << "stroke-width=\"" << _stroke_width << "\" ";
        if (_stroke_opacity != NUM_NULL) ss << "stroke-opacity=\"" << _stroke_opacity << "\" ";
        if (_stroke_linecap == SVGStrokeStyle::StrokeLinecap::SQUARE) ss << "stroke-linecap=\"square" << "\" ";
        if (_stroke_linecap == SVGStrokeStyle::StrokeLinecap::ROUND) ss << "stroke-linecap=\"round" << "\" ";
        if (_stroke_linejoin == SVGStrokeStyle::StrokeLinejoin::ROUND) ss << "stroke-linejoin=\"round" << "\" ";
        if (_stroke_linejoin == SVGStrokeStyle::StrokeLinejoin::BEVEL) ss << "stroke-linejoin=\"bevel" << "\" ";
        if (_stroke_miterlimit != NUM_NULL) ss << "stroke-miterlimit=\"" << _stroke_miterlimit << "\" ";
        if (_stroke_dasharray != STR_NULL) ss << "stroke-dasharray=\"" << _stroke_dasharray << "\" ";
        if (_stroke_dashoffset != NUM_NULL) ss << "stroke-dashoffset=\"" << _stroke_dashoffset << "\" ";
        return ss.str();
    }
}