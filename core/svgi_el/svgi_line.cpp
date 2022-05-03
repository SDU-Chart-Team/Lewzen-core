#include "svgi_line.h"

namespace Lewzen {
    SVGILine::SVGILine(): SVGIElement() { SVGILine::_bind_getter_setter(); }
    void SVGILine::_bind_getter_setter() {
        std::function<const std::string()> _getter_xQ = std::bind(&SVGLine::get_xQ, (SVGLine *)this);
        std::function<void(const std::string &)> _setter_xQ = std::bind(&SVGLine::set_xQ, (SVGLine *)this, std::placeholders::_1);
        X1.set_getter(_getter_xQ), X1.set_setter(_setter_xQ);
        X1.callback_assign(_attr_on_assign[0]), X1.callback_bind_func(_attr_on_bind[0]), X1.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_xR = std::bind(&SVGLine::get_xR, (SVGLine *)this);
        std::function<void(const std::string &)> _setter_xR = std::bind(&SVGLine::set_xR, (SVGLine *)this, std::placeholders::_1);
        X2.set_getter(_getter_xR), X2.set_setter(_setter_xR);
        X2.callback_assign(_attr_on_assign[1]), X2.callback_bind_func(_attr_on_bind[1]), X2.callback_bind_ptr(_attr_on_bind[1]);
        std::function<const std::string()> _getter_yQ = std::bind(&SVGLine::get_yQ, (SVGLine *)this);
        std::function<void(const std::string &)> _setter_yQ = std::bind(&SVGLine::set_yQ, (SVGLine *)this, std::placeholders::_1);
        Y1.set_getter(_getter_yQ), Y1.set_setter(_setter_yQ);
        Y1.callback_assign(_attr_on_assign[2]), Y1.callback_bind_func(_attr_on_bind[2]), Y1.callback_bind_ptr(_attr_on_bind[2]);
        std::function<const std::string()> _getter_yR = std::bind(&SVGLine::get_yR, (SVGLine *)this);
        std::function<void(const std::string &)> _setter_yR = std::bind(&SVGLine::set_yR, (SVGLine *)this, std::placeholders::_1);
        Y2.set_getter(_getter_yR), Y2.set_setter(_setter_yR);
        Y2.callback_assign(_attr_on_assign[3]), Y2.callback_bind_func(_attr_on_bind[3]), Y2.callback_bind_ptr(_attr_on_bind[3]);
        std::function<const std::string()> _getter_path_length = std::bind(&SVGLine::get_path_length, (SVGLine *)this);
        std::function<void(const std::string &)> _setter_path_length = std::bind(&SVGLine::set_path_length, (SVGLine *)this, std::placeholders::_1);
        PathLength.set_getter(_getter_path_length), PathLength.set_setter(_setter_path_length);
        PathLength.callback_assign(_attr_on_assign[4]), PathLength.callback_bind_func(_attr_on_bind[4]), PathLength.callback_bind_ptr(_attr_on_bind[4]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGILine::get_tag() const {
        return "line";
    }
    const std::string SVGILine::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGILine::commit() {
        std::stringstream ss;

        // attribute differ
        for (auto &i : bound) {
            auto &cmd = _attr_commit[i]();
            if (cmd != STR_NULL) ss << cmd  << std::endl;
        }
        for (auto &i : modified) {
            auto &cmd = _attr_commit[i]();
            if (cmd != STR_NULL) ss << cmd  << std::endl;
        }
        modified.clear();

        // base class
        ss << SVGIElement::commit();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGILine::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGILine> SVGILine::clone(bool identity) const {
        auto cloned = std::make_shared<SVGILine>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGILine::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGILine &SVGILine::operator=(const SVGILine &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));
        X1 = element.X1;
        X2 = element.X2;
        Y1 = element.Y1;
        Y2 = element.Y2;
        PathLength = element.PathLength;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGILine::operator-(const SVGElement &element) const {
        return SVGLine::operator-(element);
    }
}
