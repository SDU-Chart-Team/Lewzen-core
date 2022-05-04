#include "svg_defs.h"

namespace Lewzen {
    SVGDefs::SVGDefs() {
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
        return clone(true);
    }
    std::shared_ptr<SVGDefs> SVGDefs::clone(bool identity) const {
        auto cloned =  std::make_shared<SVGDefs>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGDefs::operator=(const SVGElement &element) {
        return SVGElement::operator=(element);
    }
    SVGDefs &SVGDefs::operator=(const SVGDefs &element) {
        SVGElement::operator=(element);
        return *this;

        return *this;
    }
    const std::string SVGDefs::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = dynamic_cast<const SVGDefs &>(element);

        // attribute differ
        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);

        return ss.str();
    }
    const std::string SVGDefs::attribute_differ(const SVGDefs &element) const {
        std::stringstream ss;


        return ss.str();
    }
}
