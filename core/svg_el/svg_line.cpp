#include "svg_line.h"

namespace Lewzen {
    SVGLine::SVGLine() {
        _xQ = STR_NULL;
        _xR = STR_NULL;
        _yQ = STR_NULL;
        _yR = STR_NULL;
        _path_length = STR_NULL;
    }
    const std::string SVGLine::get_tag() const {
        return "line";
    }
    const std::string SVGLine::get_xQ() const {
        return _xQ;
    }
    void SVGLine::set_xQ(const std::string &xQ) {
        _xQ = xQ;
        update_attribute_hash();
    }
    const std::string SVGLine::get_xR() const {
        return _xR;
    }
    void SVGLine::set_xR(const std::string &xR) {
        _xR = xR;
        update_attribute_hash();
    }
    const std::string SVGLine::get_yQ() const {
        return _yQ;
    }
    void SVGLine::set_yQ(const std::string &yQ) {
        _yQ = yQ;
        update_attribute_hash();
    }
    const std::string SVGLine::get_yR() const {
        return _yR;
    }
    void SVGLine::set_yR(const std::string &yR) {
        _yR = yR;
        update_attribute_hash();
    }
    const std::string SVGLine::get_path_length() const {
        return _path_length;
    }
    void SVGLine::set_path_length(const std::string &path_length) {
        _path_length = path_length;
        update_attribute_hash();
    }
    const std::string SVGLine::get_attributes() const {
        std::stringstream ss;

        if (_xQ != STR_NULL) ss << " x1=\"" << _xQ << "\"";
        if (_xR != STR_NULL) ss << " x2=\"" << _xR << "\"";
        if (_yQ != STR_NULL) ss << " y1=\"" << _yQ << "\"";
        if (_yR != STR_NULL) ss << " y2=\"" << _yR << "\"";
        if (_path_length != STR_NULL) ss << " pathLength=\"" << _path_length << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGLine::clone() const {
        return clone(true);
    }
    std::shared_ptr<SVGLine> SVGLine::clone(bool identity) const {
        auto cloned =  std::make_shared<SVGLine>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGLine::operator=(const SVGElement &element) {
        return SVGElement::operator=(element);
    }
    SVGLine &SVGLine::operator=(const SVGLine &element) {
        SVGElement::operator=(element);
        return *this;

        _xQ = element.get_xQ();
        _xR = element.get_xR();
        _yQ = element.get_yQ();
        _yR = element.get_yR();
        _path_length = element.get_path_length();
        return *this;
    }
    const std::string SVGLine::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = dynamic_cast<const SVGLine &>(element);

        // attribute differ
        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);

        return ss.str();
    }
    const std::string SVGLine::attribute_differ(const SVGLine &element) const {
        std::stringstream ss;

        if (_xQ != element.get_xQ()) {
            if (_xQ == STR_NULL) ss << "reset x1" << std::endl;
            else ss << "modify x1 \"" << _xQ << "\"" << std::endl;
        }
        if (_xR != element.get_xR()) {
            if (_xR == STR_NULL) ss << "reset x2" << std::endl;
            else ss << "modify x2 \"" << _xR << "\"" << std::endl;
        }
        if (_yQ != element.get_yQ()) {
            if (_yQ == STR_NULL) ss << "reset y1" << std::endl;
            else ss << "modify y1 \"" << _yQ << "\"" << std::endl;
        }
        if (_yR != element.get_yR()) {
            if (_yR == STR_NULL) ss << "reset y2" << std::endl;
            else ss << "modify y2 \"" << _yR << "\"" << std::endl;
        }
        if (_path_length != element.get_path_length()) {
            if (_path_length == STR_NULL) ss << "reset pathLength" << std::endl;
            else ss << "modify pathLength \"" << _path_length << "\"" << std::endl;
        }

        return ss.str();
    }
}
