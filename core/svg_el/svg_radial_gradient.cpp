#include "svg_radial_gradient.h"

namespace Lewzen {
    SVGRadialGradient::SVGRadialGradient() {
        _cx = STR_NULL;
        _cy = STR_NULL;
        _fr = STR_NULL;
        _fx = STR_NULL;
        _fy = STR_NULL;
        _gradient_units = STR_NULL;
        _gradient_transform = STR_NULL;
        _href = STR_NULL;
        _r = STR_NULL;
        _spread_method = STR_NULL;
    }
    const std::string SVGRadialGradient::get_tag() const {
        return "radialGradient";
    }
    const std::string SVGRadialGradient::get_cx() const {
        return _cx;
    }
    void SVGRadialGradient::set_cx(const std::string &cx) {
        _cx = cx;
        update_attribute_hash();
    }
    const std::string SVGRadialGradient::get_cy() const {
        return _cy;
    }
    void SVGRadialGradient::set_cy(const std::string &cy) {
        _cy = cy;
        update_attribute_hash();
    }
    const std::string SVGRadialGradient::get_fr() const {
        return _fr;
    }
    void SVGRadialGradient::set_fr(const std::string &fr) {
        _fr = fr;
        update_attribute_hash();
    }
    const std::string SVGRadialGradient::get_fx() const {
        return _fx;
    }
    void SVGRadialGradient::set_fx(const std::string &fx) {
        _fx = fx;
        update_attribute_hash();
    }
    const std::string SVGRadialGradient::get_fy() const {
        return _fy;
    }
    void SVGRadialGradient::set_fy(const std::string &fy) {
        _fy = fy;
        update_attribute_hash();
    }
    const std::string SVGRadialGradient::get_gradient_units() const {
        return _gradient_units;
    }
    void SVGRadialGradient::set_gradient_units(const std::string &gradient_units) {
        _gradient_units = gradient_units;
        update_attribute_hash();
    }
    const std::string SVGRadialGradient::get_gradient_transform() const {
        return _gradient_transform;
    }
    void SVGRadialGradient::set_gradient_transform(const std::string &gradient_transform) {
        _gradient_transform = gradient_transform;
        update_attribute_hash();
    }
    const std::string SVGRadialGradient::get_href() const {
        return _href;
    }
    void SVGRadialGradient::set_href(const std::string &href) {
        _href = href;
        update_attribute_hash();
    }
    const std::string SVGRadialGradient::get_r() const {
        return _r;
    }
    void SVGRadialGradient::set_r(const std::string &r) {
        _r = r;
        update_attribute_hash();
    }
    const std::string SVGRadialGradient::get_spread_method() const {
        return _spread_method;
    }
    void SVGRadialGradient::set_spread_method(const std::string &spread_method) {
        _spread_method = spread_method;
        update_attribute_hash();
    }
    const std::string SVGRadialGradient::get_attributes() const {
        std::stringstream ss;

        if (_cx != STR_NULL) ss << " cx=\"" << _cx << "\"";
        if (_cy != STR_NULL) ss << " cy=\"" << _cy << "\"";
        if (_fr != STR_NULL) ss << " fr=\"" << _fr << "\"";
        if (_fx != STR_NULL) ss << " fx=\"" << _fx << "\"";
        if (_fy != STR_NULL) ss << " fy=\"" << _fy << "\"";
        if (_gradient_units != STR_NULL) ss << " gradientUnits=\"" << _gradient_units << "\"";
        if (_gradient_transform != STR_NULL) ss << " gradientTransform=\"" << _gradient_transform << "\"";
        if (_href != STR_NULL) ss << " href=\"" << _href << "\"";
        if (_r != STR_NULL) ss << " r=\"" << _r << "\"";
        if (_spread_method != STR_NULL) ss << " spreadMethod=\"" << _spread_method << "\"";
        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGRadialGradient::clone() const {
        return clone(true);
    }
    std::shared_ptr<SVGRadialGradient> SVGRadialGradient::clone(bool identity) const {
        auto cloned =  std::make_shared<SVGRadialGradient>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGRadialGradient::operator=(const SVGElement &element) {
        return SVGElement::operator=(element);
    }
    SVGRadialGradient &SVGRadialGradient::operator=(const SVGRadialGradient &element) {
        SVGElement::operator=(element);
        return *this;

        _cx = element.get_cx();
        _cy = element.get_cy();
        _fr = element.get_fr();
        _fx = element.get_fx();
        _fy = element.get_fy();
        _gradient_units = element.get_gradient_units();
        _gradient_transform = element.get_gradient_transform();
        _href = element.get_href();
        _r = element.get_r();
        _spread_method = element.get_spread_method();
        return *this;
    }
    const std::string SVGRadialGradient::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = dynamic_cast<const SVGRadialGradient &>(element);

        // attribute differ
        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);

        return ss.str();
    }
    const std::string SVGRadialGradient::attribute_differ(const SVGRadialGradient &element) const {
        std::stringstream ss;

        if (_cx != element.get_cx()) {
            if (_cx == STR_NULL) ss << "reset cx" << std::endl;
            else ss << "modify cx \"" << _cx << "\"" << std::endl;
        }
        if (_cy != element.get_cy()) {
            if (_cy == STR_NULL) ss << "reset cy" << std::endl;
            else ss << "modify cy \"" << _cy << "\"" << std::endl;
        }
        if (_fr != element.get_fr()) {
            if (_fr == STR_NULL) ss << "reset fr" << std::endl;
            else ss << "modify fr \"" << _fr << "\"" << std::endl;
        }
        if (_fx != element.get_fx()) {
            if (_fx == STR_NULL) ss << "reset fx" << std::endl;
            else ss << "modify fx \"" << _fx << "\"" << std::endl;
        }
        if (_fy != element.get_fy()) {
            if (_fy == STR_NULL) ss << "reset fy" << std::endl;
            else ss << "modify fy \"" << _fy << "\"" << std::endl;
        }
        if (_gradient_units != element.get_gradient_units()) {
            if (_gradient_units == STR_NULL) ss << "reset gradientUnits" << std::endl;
            else ss << "modify gradientUnits \"" << _gradient_units << "\"" << std::endl;
        }
        if (_gradient_transform != element.get_gradient_transform()) {
            if (_gradient_transform == STR_NULL) ss << "reset gradientTransform" << std::endl;
            else ss << "modify gradientTransform \"" << _gradient_transform << "\"" << std::endl;
        }
        if (_href != element.get_href()) {
            if (_href == STR_NULL) ss << "reset href" << std::endl;
            else ss << "modify href \"" << _href << "\"" << std::endl;
        }
        if (_r != element.get_r()) {
            if (_r == STR_NULL) ss << "reset r" << std::endl;
            else ss << "modify r \"" << _r << "\"" << std::endl;
        }
        if (_spread_method != element.get_spread_method()) {
            if (_spread_method == STR_NULL) ss << "reset spreadMethod" << std::endl;
            else ss << "modify spreadMethod \"" << _spread_method << "\"" << std::endl;
        }

        return ss.str();
    }
}
