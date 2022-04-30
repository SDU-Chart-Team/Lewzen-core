#include "svgi_defs.h"

namespace Lewzen {
    SVGIDefs::SVGIDefs(): SVGIElement() {}
    void SVGIDefs::_bind_getter_setter() {
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIDefs::get_tag() const {
        return "defs";
    }
    const std::string SVGIDefs::inner_SVG() const {
        return SVGIElement::inner_SVG();
    }
    void SVGIDefs::set_inner_text(const std::string &text) {
        SVGIElement::set_inner_text(text);
    }
    const std::string SVGIDefs::get_inner_text() const {
        return SVGIElement::get_inner_text();
    }
    void SVGIDefs::append(const std::shared_ptr<SVGIElement> &inner_element) {
        SVGIElement::add_inner_element(inner_element);
    }
    void SVGIDefs::remove(const std::shared_ptr<SVGIElement> &inner_element, bool remove_all) {
        SVGIElement::remove_inner_element(inner_element, remove_all);
    }
    const std::vector<std::shared_ptr<SVGIElement>> SVGIDefs::get_inner_elements() const {
        return SVGIElement::get_inner_elements();
    }
    void SVGIDefs::set_inner_elements(const std::vector<std::shared_ptr<SVGIElement>> &inner_elements) {
        SVGIElement::set_inner_elements(inner_elements);
    }
    const std::string SVGIDefs::outer_SVG() const {
        return SVGIElement::outer_SVG();
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
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGIDefs> SVGIDefs::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIDefs>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGIDefs::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
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
