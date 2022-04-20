#include "svg_path.h"

namespace Lewzen {
    SVGPath::SVGPath() {
        _d = STR_NULL;
        _path_length = STR_NULL;
    }
    SVGPath::SVGPath(const SVGPath &element) {
        _d = element.get_d();
        _path_length = element.get_path_length();
        new (this)SVGElement(element);
    }
    const std::string SVGPath::get_tag() const {
        return "path";
    }
    const std::string SVGPath::get_d() const {
        return _d;
    }
    void SVGPath::set_d(const std::string &d) {
        _d = d;
        update_attribute_hash();
    }
    const std::string SVGPath::get_path_length() const {
        return _path_length;
    }
    void SVGPath::set_path_length(const std::string &path_length) {
        _path_length = path_length;
        update_attribute_hash();
    }
    const std::string SVGPath::get_attributes() const {
        std::stringstream ss;

        if (_d != STR_NULL) ss << " d=\"" << _d << "\"";
        if (_path_length != STR_NULL) ss << " pathLength=\"" << _path_length << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGPath::clone() const {
        return std::make_shared<SVGPath>(*this);
    }
    const std::string SVGPath::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = static_cast<const SVGPath &>(element);

        if (_d != _element.get_d()) {
            if (_d == STR_NULL) ss << "reset d" << std::endl;
            else ss << "modify d \"" << _d << "\"" << std::endl;
        }
        if (_path_length != _element.get_path_length()) {
            if (_path_length == STR_NULL) ss << "reset pathLength" << std::endl;
            else ss << "modify pathLength \"" << _path_length << "\"" << std::endl;
        }

        return ss.str();
    }
}
