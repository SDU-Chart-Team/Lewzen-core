#include "svgi_g.h"

namespace Lewzen {
    SVGIG::SVGIG(): SVGIElement() {}
    void SVGIG::_bind_getter_setter() {
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIG::get_tag() const {
        return "g";
    }
    const std::string SVGIG::commit() {
        std::stringstream ss;

        // attribute differ
        for (auto &i : bound) ss << _attr_commit[i]() << std::endl;
        for (auto &i : modified) ss << _attr_commit[i]() << std::endl;
        modified.clear();

        // base class
        ss << SVGIElement::commit();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGIG::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        *cloned = static_cast<SVGG>(*this);
        return cloned;
    }
    std::shared_ptr<SVGIG> SVGIG::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIG>();
        *cloned = *this;
        return cloned;
    }
    SVGIG &SVGIG::operator=(const SVGIG &element) {
        SVGG::operator=(static_cast<SVGG>(*this));

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIG::operator-(const SVGElement &element) const {
        return SVGG::operator-(static_cast<SVGG>(*this));
    }
}
