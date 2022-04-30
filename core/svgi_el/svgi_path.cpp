#include "svgi_path.h"

namespace Lewzen {
    SVGIPath::SVGIPath(): SVGIElement() {}
    void SVGIPath::_bind_getter_setter() {
        std::function<const std::string()> _getter_d = std::bind(&SVGPath::get_d, (SVGPath *)this);
        std::function<void(const std::string &)> _setter_d = std::bind(&SVGPath::set_d, (SVGPath *)this, std::placeholders::_1);
        D.set_getter(_getter_d), D.set_setter(_setter_d);
        D.callback_assign(_attr_on_assign[0]), D.callback_bind_func(_attr_on_bind[0]), D.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_path_length = std::bind(&SVGPath::get_path_length, (SVGPath *)this);
        std::function<void(const std::string &)> _setter_path_length = std::bind(&SVGPath::set_path_length, (SVGPath *)this, std::placeholders::_1);
        PathLength.set_getter(_getter_path_length), PathLength.set_setter(_setter_path_length);
        PathLength.callback_assign(_attr_on_assign[1]), PathLength.callback_bind_func(_attr_on_bind[1]), PathLength.callback_bind_ptr(_attr_on_bind[1]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIPath::get_tag() const {
        return "path";
    }
    const std::string SVGIPath::inner_SVG() const {
        return SVGIElement::inner_SVG();
    }
    void SVGIPath::set_inner_text(const std::string &text) {
        SVGIElement::set_inner_text(text);
    }
    const std::string SVGIPath::get_inner_text() const {
        return SVGIElement::get_inner_text();
    }
    void SVGIPath::append(const std::shared_ptr<SVGIElement> &inner_element) {
        SVGIElement::add_inner_element(inner_element);
    }
    void SVGIPath::remove(const std::shared_ptr<SVGIElement> &inner_element, bool remove_all) {
        SVGIElement::remove_inner_element(inner_element, remove_all);
    }
    const std::vector<std::shared_ptr<SVGIElement>> SVGIPath::get_inner_elements() const {
        return SVGIElement::get_inner_elements();
    }
    void SVGIPath::set_inner_elements(const std::vector<std::shared_ptr<SVGIElement>> &inner_elements) {
        SVGIElement::set_inner_elements(inner_elements);
    }
    const std::string SVGIPath::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGIPath::commit() {
        std::stringstream ss;

        // attribute differ
        for (auto &i : bound) ss << _attr_commit[i]() << std::endl;
        for (auto &i : modified) ss << _attr_commit[i]() << std::endl;
        modified.clear();

        // base class
        ss << SVGIElement::commit();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGIPath::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGIPath> SVGIPath::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIPath>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGIPath::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGIPath &SVGIPath::operator=(const SVGIPath &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));
        D = element.D;
        PathLength = element.PathLength;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIPath::operator-(const SVGElement &element) const {
        return SVGPath::operator-(element);
    }
}
