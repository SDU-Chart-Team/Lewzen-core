#include "svg_g.h"

namespace Lewzen {
    SVGG::SVGG() {
    }
    SVGG::SVGG(const SVGG &element) {
        new (this)SVGElement(element);
    }
    const std::string SVGG::get_tag() const {
        return "g";
    }
    const std::string SVGG::get_attributes() const {
        std::stringstream ss;

        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGG::clone() const {
        return std::make_shared<SVGG>(*this);
    }
    const std::string SVGG::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = static_cast<const SVGG &>(element);


        return ss.str();
    }
}
