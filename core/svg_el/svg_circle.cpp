#include "svg_circle.h"

namespace Lewzen {
    SVGCircle::SVGCircle() {
        _cx = STR_NULL;
        _cy = STR_NULL;
        _r = STR_NULL;
        _path_length = STR_NULL;
    }
    const std::string SVGCircle::get_tag() const {
        return "circle";
    }
    const std::string SVGCircle::get_cx() const {
        return _cx;
    }
    void SVGCircle::set_cx(const std::string &cx) {
        _cx = cx;
        update_attribute_hash();
    }
    const std::string SVGCircle::get_cy() const {
        return _cy;
    }
    void SVGCircle::set_cy(const std::string &cy) {
        _cy = cy;
        update_attribute_hash();
    }
    const std::string SVGCircle::get_r() const {
        return _r;
    }
    void SVGCircle::set_r(const std::string &r) {
        _r = r;
        update_attribute_hash();
    }
    const std::string SVGCircle::get_path_length() const {
        return _path_length;
    }
    void SVGCircle::set_path_length(const std::string &path_length) {
        _path_length = path_length;
        update_attribute_hash();
    }
    const std::string SVGCircle::get_attributes() const {
        std::stringstream ss;

        if (_cx != STR_NULL) ss << " cx=\"" << _cx << "\"";
        if (_cy != STR_NULL) ss << " cy=\"" << _cy << "\"";
        if (_r != STR_NULL) ss << " r=\"" << _r << "\"";
        if (_path_length != STR_NULL) ss << " pathLength=\"" << _path_length << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGCircle::clone() const {
        return clone(true);
    }
    std::shared_ptr<SVGCircle> SVGCircle::clone(bool identity) const {
        auto cloned =  std::make_shared<SVGCircle>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGCircle::operator=(const SVGElement &element) {
        return SVGElement::operator=(element);
    }
    SVGCircle &SVGCircle::operator=(const SVGCircle &element) {
        SVGElement::operator=(element);
        return *this;

        _cx = element.get_cx();
        _cy = element.get_cy();
        _r = element.get_r();
        _path_length = element.get_path_length();
        return *this;
    }
    const std::string SVGCircle::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = dynamic_cast<const SVGCircle &>(element);

        // attribute differ
        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);

        return ss.str();
    }
    const std::string SVGCircle::attribute_differ(const SVGCircle &element) const {
        std::stringstream ss;

        if (_cx != element.get_cx()) {
            if (_cx == STR_NULL) ss << "reset cx" << std::endl;
            else ss << "modify cx \"" << _cx << "\"" << std::endl;
        }
        if (_cy != element.get_cy()) {
            if (_cy == STR_NULL) ss << "reset cy" << std::endl;
            else ss << "modify cy \"" << _cy << "\"" << std::endl;
        }
        if (_r != element.get_r()) {
            if (_r == STR_NULL) ss << "reset r" << std::endl;
            else ss << "modify r \"" << _r << "\"" << std::endl;
        }
        if (_path_length != element.get_path_length()) {
            if (_path_length == STR_NULL) ss << "reset pathLength" << std::endl;
            else ss << "modify pathLength \"" << _path_length << "\"" << std::endl;
        }

        return ss.str();
    }
}
