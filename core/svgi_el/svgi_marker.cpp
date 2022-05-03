#include "svgi_marker.h"

namespace Lewzen {
    SVGIMarker::SVGIMarker(): SVGIElement() { SVGIMarker::_bind_getter_setter(); }
    void SVGIMarker::_bind_getter_setter() {
        std::function<const std::string()> _getter_marker_height = std::bind(&SVGMarker::get_marker_height, (SVGMarker *)this);
        std::function<void(const std::string &)> _setter_marker_height = std::bind(&SVGMarker::set_marker_height, (SVGMarker *)this, std::placeholders::_1);
        MarkerHeight.set_getter(_getter_marker_height), MarkerHeight.set_setter(_setter_marker_height);
        MarkerHeight.callback_assign(_attr_on_assign[0]), MarkerHeight.callback_bind_func(_attr_on_bind[0]), MarkerHeight.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_marker_units = std::bind(&SVGMarker::get_marker_units, (SVGMarker *)this);
        std::function<void(const std::string &)> _setter_marker_units = std::bind(&SVGMarker::set_marker_units, (SVGMarker *)this, std::placeholders::_1);
        MarkerUnits.set_getter(_getter_marker_units), MarkerUnits.set_setter(_setter_marker_units);
        MarkerUnits.callback_assign(_attr_on_assign[1]), MarkerUnits.callback_bind_func(_attr_on_bind[1]), MarkerUnits.callback_bind_ptr(_attr_on_bind[1]);
        std::function<const std::string()> _getter_marker_width = std::bind(&SVGMarker::get_marker_width, (SVGMarker *)this);
        std::function<void(const std::string &)> _setter_marker_width = std::bind(&SVGMarker::set_marker_width, (SVGMarker *)this, std::placeholders::_1);
        MarkerWidth.set_getter(_getter_marker_width), MarkerWidth.set_setter(_setter_marker_width);
        MarkerWidth.callback_assign(_attr_on_assign[2]), MarkerWidth.callback_bind_func(_attr_on_bind[2]), MarkerWidth.callback_bind_ptr(_attr_on_bind[2]);
        std::function<const std::string()> _getter_orient = std::bind(&SVGMarker::get_orient, (SVGMarker *)this);
        std::function<void(const std::string &)> _setter_orient = std::bind(&SVGMarker::set_orient, (SVGMarker *)this, std::placeholders::_1);
        Orient.set_getter(_getter_orient), Orient.set_setter(_setter_orient);
        Orient.callback_assign(_attr_on_assign[3]), Orient.callback_bind_func(_attr_on_bind[3]), Orient.callback_bind_ptr(_attr_on_bind[3]);
        std::function<const std::string()> _getter_preserve_aspect_ratio = std::bind(&SVGMarker::get_preserve_aspect_ratio, (SVGMarker *)this);
        std::function<void(const std::string &)> _setter_preserve_aspect_ratio = std::bind(&SVGMarker::set_preserve_aspect_ratio, (SVGMarker *)this, std::placeholders::_1);
        PreserveAspectRatio.set_getter(_getter_preserve_aspect_ratio), PreserveAspectRatio.set_setter(_setter_preserve_aspect_ratio);
        PreserveAspectRatio.callback_assign(_attr_on_assign[4]), PreserveAspectRatio.callback_bind_func(_attr_on_bind[4]), PreserveAspectRatio.callback_bind_ptr(_attr_on_bind[4]);
        std::function<const std::string()> _getter_ref_x = std::bind(&SVGMarker::get_ref_x, (SVGMarker *)this);
        std::function<void(const std::string &)> _setter_ref_x = std::bind(&SVGMarker::set_ref_x, (SVGMarker *)this, std::placeholders::_1);
        RefX.set_getter(_getter_ref_x), RefX.set_setter(_setter_ref_x);
        RefX.callback_assign(_attr_on_assign[5]), RefX.callback_bind_func(_attr_on_bind[5]), RefX.callback_bind_ptr(_attr_on_bind[5]);
        std::function<const std::string()> _getter_ref_y = std::bind(&SVGMarker::get_ref_y, (SVGMarker *)this);
        std::function<void(const std::string &)> _setter_ref_y = std::bind(&SVGMarker::set_ref_y, (SVGMarker *)this, std::placeholders::_1);
        RefY.set_getter(_getter_ref_y), RefY.set_setter(_setter_ref_y);
        RefY.callback_assign(_attr_on_assign[6]), RefY.callback_bind_func(_attr_on_bind[6]), RefY.callback_bind_ptr(_attr_on_bind[6]);
        std::function<const std::string()> _getter_view_box = std::bind(&SVGMarker::get_view_box, (SVGMarker *)this);
        std::function<void(const std::string &)> _setter_view_box = std::bind(&SVGMarker::set_view_box, (SVGMarker *)this, std::placeholders::_1);
        ViewBox.set_getter(_getter_view_box), ViewBox.set_setter(_setter_view_box);
        ViewBox.callback_assign(_attr_on_assign[7]), ViewBox.callback_bind_func(_attr_on_bind[7]), ViewBox.callback_bind_ptr(_attr_on_bind[7]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIMarker::get_tag() const {
        return "marker";
    }
    const std::string SVGIMarker::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGIMarker::commit() {
        std::stringstream ss;

        // attribute differ
        for (auto &i : bound) {
            auto &cmd = _attr_commit[i]();
            if (cmd != STR_NULL) ss << cmd  << std::endl;
        }
        for (auto &i : modified) {
            auto &cmd = _attr_commit[i]();
            if (cmd != STR_NULL) ss << cmd  << std::endl;
        }
        modified.clear();

        // base class
        ss << SVGIElement::commit();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGIMarker::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGIMarker> SVGIMarker::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIMarker>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGIMarker::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGIMarker &SVGIMarker::operator=(const SVGIMarker &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));
        MarkerHeight = element.MarkerHeight;
        MarkerUnits = element.MarkerUnits;
        MarkerWidth = element.MarkerWidth;
        Orient = element.Orient;
        PreserveAspectRatio = element.PreserveAspectRatio;
        RefX = element.RefX;
        RefY = element.RefY;
        ViewBox = element.ViewBox;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIMarker::operator-(const SVGElement &element) const {
        return SVGMarker::operator-(element);
    }
}
