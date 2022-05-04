#include "svg_marker.h"

namespace Lewzen {
    SVGMarker::SVGMarker() {
        _marker_height = STR_NULL;
        _marker_units = STR_NULL;
        _marker_width = STR_NULL;
        _orient = STR_NULL;
        _preserve_aspect_ratio = STR_NULL;
        _ref_x = STR_NULL;
        _ref_y = STR_NULL;
        _view_box = STR_NULL;
    }
    const std::string SVGMarker::get_tag() const {
        return "marker";
    }
    const std::string SVGMarker::get_marker_height() const {
        return _marker_height;
    }
    void SVGMarker::set_marker_height(const std::string &marker_height) {
        _marker_height = marker_height;
        update_attribute_hash();
    }
    const std::string SVGMarker::get_marker_units() const {
        return _marker_units;
    }
    void SVGMarker::set_marker_units(const std::string &marker_units) {
        _marker_units = marker_units;
        update_attribute_hash();
    }
    const std::string SVGMarker::get_marker_width() const {
        return _marker_width;
    }
    void SVGMarker::set_marker_width(const std::string &marker_width) {
        _marker_width = marker_width;
        update_attribute_hash();
    }
    const std::string SVGMarker::get_orient() const {
        return _orient;
    }
    void SVGMarker::set_orient(const std::string &orient) {
        _orient = orient;
        update_attribute_hash();
    }
    const std::string SVGMarker::get_preserve_aspect_ratio() const {
        return _preserve_aspect_ratio;
    }
    void SVGMarker::set_preserve_aspect_ratio(const std::string &preserve_aspect_ratio) {
        _preserve_aspect_ratio = preserve_aspect_ratio;
        update_attribute_hash();
    }
    const std::string SVGMarker::get_ref_x() const {
        return _ref_x;
    }
    void SVGMarker::set_ref_x(const std::string &ref_x) {
        _ref_x = ref_x;
        update_attribute_hash();
    }
    const std::string SVGMarker::get_ref_y() const {
        return _ref_y;
    }
    void SVGMarker::set_ref_y(const std::string &ref_y) {
        _ref_y = ref_y;
        update_attribute_hash();
    }
    const std::string SVGMarker::get_view_box() const {
        return _view_box;
    }
    void SVGMarker::set_view_box(const std::string &view_box) {
        _view_box = view_box;
        update_attribute_hash();
    }
    const std::string SVGMarker::get_attributes() const {
        std::stringstream ss;

        if (_marker_height != STR_NULL) ss << " markerHeight=\"" << _marker_height << "\"";
        if (_marker_units != STR_NULL) ss << " markerUnits=\"" << _marker_units << "\"";
        if (_marker_width != STR_NULL) ss << " markerWidth=\"" << _marker_width << "\"";
        if (_orient != STR_NULL) ss << " orient=\"" << _orient << "\"";
        if (_preserve_aspect_ratio != STR_NULL) ss << " preserveAspectRatio=\"" << _preserve_aspect_ratio << "\"";
        if (_ref_x != STR_NULL) ss << " refX=\"" << _ref_x << "\"";
        if (_ref_y != STR_NULL) ss << " refY=\"" << _ref_y << "\"";
        if (_view_box != STR_NULL) ss << " viewBox=\"" << _view_box << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGMarker::clone() const {
        return clone(true);
    }
    std::shared_ptr<SVGMarker> SVGMarker::clone(bool identity) const {
        auto cloned =  std::make_shared<SVGMarker>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGMarker::operator=(const SVGElement &element) {
        return SVGElement::operator=(element);
    }
    SVGMarker &SVGMarker::operator=(const SVGMarker &element) {
        SVGElement::operator=(element);
        return *this;

        _marker_height = element.get_marker_height();
        _marker_units = element.get_marker_units();
        _marker_width = element.get_marker_width();
        _orient = element.get_orient();
        _preserve_aspect_ratio = element.get_preserve_aspect_ratio();
        _ref_x = element.get_ref_x();
        _ref_y = element.get_ref_y();
        _view_box = element.get_view_box();
        return *this;
    }
    const std::string SVGMarker::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = dynamic_cast<const SVGMarker &>(element);

        // attribute differ
        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);

        return ss.str();
    }
    const std::string SVGMarker::attribute_differ(const SVGMarker &element) const {
        std::stringstream ss;

        if (_marker_height != element.get_marker_height()) {
            if (_marker_height == STR_NULL) ss << "reset markerHeight" << std::endl;
            else ss << "modify markerHeight \"" << _marker_height << "\"" << std::endl;
        }
        if (_marker_units != element.get_marker_units()) {
            if (_marker_units == STR_NULL) ss << "reset markerUnits" << std::endl;
            else ss << "modify markerUnits \"" << _marker_units << "\"" << std::endl;
        }
        if (_marker_width != element.get_marker_width()) {
            if (_marker_width == STR_NULL) ss << "reset markerWidth" << std::endl;
            else ss << "modify markerWidth \"" << _marker_width << "\"" << std::endl;
        }
        if (_orient != element.get_orient()) {
            if (_orient == STR_NULL) ss << "reset orient" << std::endl;
            else ss << "modify orient \"" << _orient << "\"" << std::endl;
        }
        if (_preserve_aspect_ratio != element.get_preserve_aspect_ratio()) {
            if (_preserve_aspect_ratio == STR_NULL) ss << "reset preserveAspectRatio" << std::endl;
            else ss << "modify preserveAspectRatio \"" << _preserve_aspect_ratio << "\"" << std::endl;
        }
        if (_ref_x != element.get_ref_x()) {
            if (_ref_x == STR_NULL) ss << "reset refX" << std::endl;
            else ss << "modify refX \"" << _ref_x << "\"" << std::endl;
        }
        if (_ref_y != element.get_ref_y()) {
            if (_ref_y == STR_NULL) ss << "reset refY" << std::endl;
            else ss << "modify refY \"" << _ref_y << "\"" << std::endl;
        }
        if (_view_box != element.get_view_box()) {
            if (_view_box == STR_NULL) ss << "reset viewBox" << std::endl;
            else ss << "modify viewBox \"" << _view_box << "\"" << std::endl;
        }

        return ss.str();
    }
}
