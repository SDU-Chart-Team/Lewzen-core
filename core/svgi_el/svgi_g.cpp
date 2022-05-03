#include "svgi_g.h"

namespace Lewzen {
    SVGIG::SVGIG(): SVGIElement() { SVGIG::_bind_getter_setter(); }
    void SVGIG::_bind_getter_setter() {
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIG::get_tag() const {
        return "g";
    }
    const std::string SVGIG::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGIG::commit() {
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
    std::shared_ptr<SVGElement> SVGIG::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGIG> SVGIG::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIG>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGIG::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGIG &SVGIG::operator=(const SVGIG &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIG::operator-(const SVGElement &element) const {
        return SVGG::operator-(element);
    }
}
