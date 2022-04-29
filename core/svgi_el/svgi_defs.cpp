#include "svgi_defs.h"

namespace Lewzen {
    SVGIDefs::SVGIDefs(): SVGIElement() {}
    void SVGIDefs::_bind_getter_setter() {
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIDefs::get_tag() const {
        return "defs";
    }
    const std::string SVGIDefs::commit() {
        std::stringstream ss;

        // attribute differ
        for (auto &i : bound) ss << _attr_commit[i]() << std::endl;
        for (auto &i : modified) ss << _attr_commit[i]() << std::endl;
        modified.clear();

        // base class
        ss << SVGIElement::commit();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGIDefs::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        *cloned = static_cast<SVGDefs>(*this);
        return cloned;
    }
    std::shared_ptr<SVGIDefs> SVGIDefs::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIDefs>();
        *cloned = *this;
        return cloned;
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
