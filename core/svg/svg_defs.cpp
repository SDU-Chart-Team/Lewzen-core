#include "svg_defs.h"

namespace Lewzen {
    SVGDefs::SVGDefs() {
    }
    SVGDefs::SVGDefs(const SVGDefs &element) {
        new (this)XMLElement(element);
    }
    const std::string SVGDefs::get_tag() const {
        return "defs";
    }
    const std::string SVGDefs::get_attributes() const {
        std::stringstream ss;

        ss << XMLElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<XMLElement> SVGDefs::clone() const {
        return std::make_shared<SVGDefs>(*this);
    }
    const std::string SVGDefs::operator-(const XMLElement &element) const {
        std::stringstream ss;

        ss << XMLElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = static_cast<const SVGDefs &>(element);


        return ss.str();
    }
}
