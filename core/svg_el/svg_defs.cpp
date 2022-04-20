#include "svg_defs.h"

namespace Lewzen {
    SVGDefs::SVGDefs() {
    }
    SVGDefs::SVGDefs(const SVGDefs &element) {
        new (this)SVGElement(element);
    }
    const std::string SVGDefs::get_tag() const {
        return "defs";
    }
    const std::string SVGDefs::get_attributes() const {
        std::stringstream ss;

        ss << SVGElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGDefs::clone() const {
        return std::make_shared<SVGDefs>(*this);
    }
    const std::string SVGDefs::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = static_cast<const SVGDefs &>(element);


        return ss.str();
    }
}
