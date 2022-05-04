#include "svg_g.h"

namespace Lewzen {
    SVGG::SVGG() {
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
        return clone(true);
    }
    std::shared_ptr<SVGG> SVGG::clone(bool identity) const {
        auto cloned =  std::make_shared<SVGG>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGG::operator=(const SVGElement &element) {
        return SVGElement::operator=(element);
    }
    SVGG &SVGG::operator=(const SVGG &element) {
        SVGElement::operator=(element);
        return *this;

        return *this;
    }
    const std::string SVGG::operator-(const SVGElement &element) const {
        std::stringstream ss;

        ss << SVGElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = dynamic_cast<const SVGG &>(element);

        // attribute differ
        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);

        return ss.str();
    }
    const std::string SVGG::attribute_differ(const SVGG &element) const {
        std::stringstream ss;


        return ss.str();
    }
}
