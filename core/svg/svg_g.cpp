#include "svg_g.h"

namespace Lewzen {
    SVGG::SVGG() {
    }
    SVGG::SVGG(const SVGG &element) {
        new (this)XMLElement(element);
    }
    const std::string SVGG::get_tag() const {
        return "g";
    }
    const std::string SVGG::get_attributes() const {
        std::stringstream ss;

        ss << XMLElement::get_attributes();

        return ss.str();
    }
    std::shared_ptr<XMLElement> SVGG::clone() const {
        return std::make_shared<SVGG>(*this);
    }
    const std::string SVGG::operator-(const XMLElement &element) const {
        std::stringstream ss;

        ss << XMLElement::operator-(element);
        if (get_tag() != element.get_tag()) return ss.str();
        auto _element = static_cast<const SVGG &>(element);


        return ss.str();
    }
}
