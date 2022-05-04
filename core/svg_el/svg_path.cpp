#include "svg_path.h"

namespace Lewzen {
    SVGPath::SVGPath() {
        _d = STR_NULL;
        _path_length = STR_NULL;
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
        return clone(true);
    }
    std::shared_ptr<SVGPath> SVGPath::clone(bool identity) const {
        auto cloned =  std::make_shared<SVGPath>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGPath::operator=(const SVGElement &element) {
        return SVGElement::operator=(element);
    }
    SVGPath &SVGPath::operator=(const SVGPath &element) {
        SVGElement::operator=(element);
        return *this;

        _d = element.get_d();
        _path_length = element.get_path_length();
        return *this;
    }
    const std::string SVGPath::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = dynamic_cast<const SVGPath &>(element);

        // attribute differ
        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);

        return ss.str();
    }
    const std::string SVGPath::attribute_differ(const SVGPath &element) const {
        std::stringstream ss;

        if (_d != element.get_d()) {
            if (_d == STR_NULL) ss << "reset d" << std::endl;
            else ss << "modify d \"" << _d << "\"" << std::endl;
        }
        if (_path_length != element.get_path_length()) {
            if (_path_length == STR_NULL) ss << "reset pathLength" << std::endl;
            else ss << "modify pathLength \"" << _path_length << "\"" << std::endl;
        }

        return ss.str();
    }
}
