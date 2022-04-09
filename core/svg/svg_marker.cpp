#include "svg_marker.h"

namespace Lewzen {
    SVGMarker::SVGMarker() {
        _marker_width = NUM_NULL;
        _marker_height = NUM_NULL;
        _ref_x = NUM_NULL;
        _ref_y = NUM_NULL;
        _orient = STR_NULL;
        _preserve_aspect_ratio = STR_NULL;
        _view_box = STR_NULL;
        _marker_units = MarkerUnits::STROKE_WIDTH;
    }
    SVGMarker::SVGMarker(const SVGMarker &element) {
        _marker_width = element.get_marker_width();
        _marker_height = element.get_marker_height();
        _ref_x = element.get_ref_x();
        _ref_y = element.get_ref_y();
        _orient = element.get_orient();
        _preserve_aspect_ratio = element.get_preserve_aspect_ratio();
        _view_box = element.get_view_box();
        _marker_units = element.get_marker_units();
        new (this)XMLElement(element);
    }
    const std::string SVGMarker::get_tag() const {
        return "marker";
    }
    double SVGMarker::get_marker_width() const {
        return _marker_width;
    }
    void SVGMarker::set_marker_width(const double &marker_width) {
        _marker_width = marker_width;
    }
    double SVGMarker::get_marker_height() const {
        return _marker_height;
    }
    void SVGMarker::set_marker_height(const double &marker_height) {
        _marker_height = marker_height;
    }
    double SVGMarker::get_ref_x() const {
        return _ref_x;
    }
    void SVGMarker::set_ref_x(const double &ref_x) {
        _ref_x = ref_x;
    }
    double SVGMarker::get_ref_y() const {
        return _ref_y;
    }
    void SVGMarker::set_ref_y(const double &ref_y) {
        _ref_y = ref_y;
    }
    const std::string SVGMarker::get_orient() const {
        return _orient;
    }
    void SVGMarker::set_orient(const std::string &orient) {
        _orient = orient;
    }
    const std::string SVGMarker::get_preserve_aspect_ratio() const {
        return _preserve_aspect_ratio;
    }
    void SVGMarker::set_preserve_aspect_ratio(const std::string &preserve_aspect_ratio) {
        _preserve_aspect_ratio = preserve_aspect_ratio;
    }
    const std::string SVGMarker::get_view_box() const {
        return _view_box;
    }
    void SVGMarker::set_view_box(const std::string &view_box) {
        _view_box = view_box;
    }
    const SVGMarker::MarkerUnits SVGMarker::get_marker_units() const {
        return _marker_units;
    }
    void SVGMarker::set_marker_units(const SVGMarker::MarkerUnits &marker_units) {
        _marker_units = marker_units;
    }
    const std::string SVGMarker::get_attributes() const {
        std::stringstream ss;

        if (_marker_width != NUM_NULL) ss << " markerWidth=\"" << _marker_width << "\"";
        if (_marker_height != NUM_NULL) ss << " markerHeight=\"" << _marker_height << "\"";
        if (_ref_x != NUM_NULL) ss << " refX=\"" << _ref_x << "\"";
        if (_ref_y != NUM_NULL) ss << " refY=\"" << _ref_y << "\"";
        if (_orient != STR_NULL) ss << " orient=\"" << _orient << "\"";
        if (_preserve_aspect_ratio != STR_NULL) ss << " preserveAspectRatio=\"" << _preserve_aspect_ratio << "\"";
        if (_view_box != STR_NULL) ss << " viewBox=\"" << _view_box << "\"";
        if (_marker_units == MarkerUnits::USER_SPACE_ON_USE) ss << " markerUnits=\"userSpaceOnUse\"";
        ss << XMLElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<XMLElement> SVGMarker::clone() const {
        return std::make_shared<SVGMarker>(*this);
    }
    const std::string SVGMarker::operator-(const XMLElement &element) const {
        std::stringstream ss;

        ss << XMLElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = static_cast<const SVGMarker &>(element);

        if (_marker_width != _element.get_marker_width()) {
            if (_marker_width == NUM_NULL) ss << "reset markerWidth" << std::endl;
            else ss << "modify markerWidth " << _marker_width << std::endl;
        }
        if (_marker_height != _element.get_marker_height()) {
            if (_marker_height == NUM_NULL) ss << "reset markerHeight" << std::endl;
            else ss << "modify markerHeight " << _marker_height << std::endl;
        }
        if (_ref_x != _element.get_ref_x()) {
            if (_ref_x == NUM_NULL) ss << "reset refX" << std::endl;
            else ss << "modify refX " << _ref_x << std::endl;
        }
        if (_ref_y != _element.get_ref_y()) {
            if (_ref_y == NUM_NULL) ss << "reset refY" << std::endl;
            else ss << "modify refY " << _ref_y << std::endl;
        }
        if (_orient != _element.get_orient()) {
            if (_orient == STR_NULL) ss << "reset orient" << std::endl;
            else ss << "modify orient \"" << _orient << "\"" << std::endl;
        }
        if (_preserve_aspect_ratio != _element.get_preserve_aspect_ratio()) {
            if (_preserve_aspect_ratio == STR_NULL) ss << "reset preserveAspectRatio" << std::endl;
            else ss << "modify preserveAspectRatio \"" << _preserve_aspect_ratio << "\"" << std::endl;
        }
        if (_view_box != _element.get_view_box()) {
            if (_view_box == STR_NULL) ss << "reset viewBox" << std::endl;
            else ss << "modify viewBox \"" << _view_box << "\"" << std::endl;
        }
        if (_marker_units != _element.get_marker_units()) {
            if (_marker_units == MarkerUnits::STROKE_WIDTH) ss << "reset markerUnits" << std::endl;
            else if (_marker_units == MarkerUnits::USER_SPACE_ON_USE) ss << "modify markerUnits \"userSpaceOnUse\"" << std::endl;
        }

        return ss.str();
    }
}
