#include "svg_polygon.h"

namespace Lewzen {
    SVGPolygon::SVGPolygon() {
        _points = STR_NULL;
        _path_length = NUM_NULL;
    }
    SVGPolygon::SVGPolygon(const SVGPolygon &element) {
        _points = element.get_points();
        _path_length = element.get_path_length();
        new (this)SVGElement(element);
    }
    const std::string SVGPolygon::get_tag() const {
        return "polygon";
    }
    const std::string SVGPolygon::get_points() const {
        return _points;
    }
    void SVGPolygon::set_points(const std::string &points) {
        _points = points;
    }
    double SVGPolygon::get_path_length() const {
        return _path_length;
    }
    void SVGPolygon::set_path_length(const double &path_length) {
        _path_length = path_length;
    }
    const std::string SVGPolygon::get_attributes() const {
        std::stringstream ss;

        if (_points != STR_NULL) ss << " points=\"" << _points << "\"";
        if (_path_length != NUM_NULL) ss << " pathLength=\"" << _path_length << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGPolygon::clone() const {
        return std::make_shared<SVGPolygon>(*this);
    }
    const std::string SVGPolygon::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = static_cast<const SVGPolygon &>(element);

        if (_points != _element.get_points()) {
            if (_points == STR_NULL) ss << "reset points" << std::endl;
            else ss << "modify points \"" << _points << "\"" << std::endl;
        }
        if (_path_length != _element.get_path_length()) {
            if (_path_length == NUM_NULL) ss << "reset pathLength" << std::endl;
            else ss << "modify pathLength " << _path_length << std::endl;
        }

        return ss.str();
    }
}
