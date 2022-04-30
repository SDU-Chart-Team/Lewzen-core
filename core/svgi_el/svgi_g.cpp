#include "svgi_g.h"

namespace Lewzen {
    SVGIG::SVGIG(): SVGIElement() {}
    void SVGIG::_bind_getter_setter() {
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIG::get_tag() const {
        return "g";
    }
    const std::string SVGIG::inner_SVG() const {
        return SVGIElement::inner_SVG();
    }
    void SVGIG::set_inner_text(const std::string &text) {
        SVGIElement::set_inner_text(text);
    }
    const std::string SVGIG::get_inner_text() const {
        return SVGIElement::get_inner_text();
    }
    void SVGIG::append(const std::shared_ptr<SVGIElement> &inner_element) {
        SVGIElement::add_inner_element(inner_element);
    }
    void SVGIG::remove(const std::shared_ptr<SVGIElement> &inner_element, bool remove_all) {
        SVGIElement::remove_inner_element(inner_element, remove_all);
    }
    const std::vector<std::shared_ptr<SVGIElement>> SVGIG::get_inner_elements() const {
        return SVGIElement::get_inner_elements();
    }
    void SVGIG::set_inner_elements(const std::vector<std::shared_ptr<SVGIElement>> &inner_elements) {
        SVGIElement::set_inner_elements(inner_elements);
    }
    const std::string SVGIG::outer_SVG() const {
        return SVGIElement::outer_SVG();
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
