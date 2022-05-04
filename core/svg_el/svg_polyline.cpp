#include "svg_polyline.h"

namespace Lewzen {
    SVGPolyline::SVGPolyline() {
        _points = STR_NULL;
        _path_length = STR_NULL;
    }
    const std::string SVGPolyline::get_tag() const {
        return "polyline";
    }
    const std::string SVGPolyline::get_points() const {
        return _points;
    }
    void SVGPolyline::set_points(const std::string &points) {
        _points = points;
        update_attribute_hash();
    }
    const std::string SVGPolyline::get_path_length() const {
        return _path_length;
    }
    void SVGPolyline::set_path_length(const std::string &path_length) {
        _path_length = path_length;
        update_attribute_hash();
    }
    const std::string SVGPolyline::get_attributes() const {
        std::stringstream ss;

        if (_points != STR_NULL) ss << " points=\"" << _points << "\"";
        if (_path_length != STR_NULL) ss << " pathLength=\"" << _path_length << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGPolyline::clone() const {
        return clone(true);
    }
    std::shared_ptr<SVGPolyline> SVGPolyline::clone(bool identity) const {
        auto cloned =  std::make_shared<SVGPolyline>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGPolyline::operator=(const SVGElement &element) {
        return SVGElement::operator=(element);
    }
    SVGPolyline &SVGPolyline::operator=(const SVGPolyline &element) {
        SVGElement::operator=(element);
        return *this;

        _points = element.get_points();
        _path_length = element.get_path_length();
        return *this;
    }
    const std::string SVGPolyline::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = dynamic_cast<const SVGPolyline &>(element);

        // attribute differ
        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);

        return ss.str();
    }
    const std::string SVGPolyline::attribute_differ(const SVGPolyline &element) const {
        std::stringstream ss;

        if (_points != element.get_points()) {
            if (_points == STR_NULL) ss << "reset points" << std::endl;
            else ss << "modify points \"" << _points << "\"" << std::endl;
        }
        if (_path_length != element.get_path_length()) {
            if (_path_length == STR_NULL) ss << "reset pathLength" << std::endl;
            else ss << "modify pathLength \"" << _path_length << "\"" << std::endl;
        }

        return ss.str();
    }
}
