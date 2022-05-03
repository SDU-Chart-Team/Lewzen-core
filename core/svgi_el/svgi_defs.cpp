#include "svgi_defs.h"

namespace Lewzen {
    SVGIDefs::SVGIDefs(): SVGIElement() { SVGIDefs::_bind_getter_setter(); }
    void SVGIDefs::_bind_getter_setter() {
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIDefs::get_tag() const {
        return "defs";
    }
    const std::string SVGIDefs::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGIDefs::commit() {
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
    std::shared_ptr<SVGElement> SVGIDefs::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGIDefs> SVGIDefs::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIDefs>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGIDefs::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGIDefs &SVGIDefs::operator=(const SVGIDefs &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIDefs::operator-(const SVGElement &element) const {
        return SVGDefs::operator-(element);
    }
}
