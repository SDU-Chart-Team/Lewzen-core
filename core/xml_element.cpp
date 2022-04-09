#include <sstream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "xml_element.h"

namespace Lewzen {
    XMLElement::XMLElement() {
        _fill = STR_NULL;
        _fill_opacity = NUM_NULL;
        _fill_rule = XMLElement::FillRule::NONEZERO;
        _stroke = _stroke_dasharray = STR_NULL;
        _stroke_width = _stroke_opacity = _stroke_miterlimit = _stroke_dashoffset = NUM_NULL;
        _stroke_linecap = XMLElement::StrokeLinecap::BUTT;
        _stroke_linejoin = XMLElement::StrokeLinejoin::MITER;
    }
    XMLElement::XMLElement(const XMLElement &element) {
        _classes = element.get_classes();
        _fill = element.get_fill();
        _fill_opacity = element.get_fill_opacity();
        _fill_rule = element.get_fill_rule();
        _stroke = element.get_stroke();
        _stroke_width = element.get_stroke_width();
        _stroke_opacity = element.get_stroke_opacity();
        _stroke_linecap = element.get_stroke_linecap();
        _stroke_linejoin = element.get_stroke_linejoin();
        _stroke_miterlimit = element.get_stroke_miterlimit();
        _stroke_dasharray = element.get_stroke_dasharray();
        _stroke_dashoffset = element.get_stroke_dashoffset();
        _inner_text = element.get_inner_text();
        for (auto p : element.get_inner_elements()) {
            _inner_elements.push_back(p->clone());
        }
        _attribute_hash = element.get_attribute_hash();
        _inner_hash = element.get_inner_hash();
        _outer_hash = element.get_outer_hash();
    }

    const std::string XMLElement::get_tag() const {
        return "?";
    }

    void XMLElement::add_class(const std::string &cls) {
        _classes.insert(cls);
        update_hash();
    }
    void XMLElement::remove_class(const std::string &cls) {
        _classes.erase(_classes.end());
        update_hash();
    }
    const std::set<std::string> XMLElement::get_classes() const {
        return _classes;
    }
    void XMLElement::set_inner_elements(const std::set<std::string> &cls_list) {
        _classes = cls_list;
        update_hash();
    }
    const std::string XMLElement::get_class_attributes() const {
        std::stringstream ss;
        ss << "class=\"";
        for (auto &_cls : _classes) {
            ss << "." <<_cls << " ";
        }
        ss << "\"";
        return ss.str();
    }

    const std::string XMLElement::get_fill() const {
        return _fill;
    }
    void XMLElement::set_fill(const std::string &fill) {
        _fill = fill;
        update_hash();
    }
    double XMLElement::get_fill_opacity() const {
        return _fill_opacity;
    }
    void XMLElement::set_fill_opacity(const double &fill_opacity) {
        _fill_opacity = fill_opacity;
        update_hash();
    }
    const XMLElement::FillRule XMLElement::get_fill_rule() const {
        return _fill_rule;
    }
    void XMLElement::set_fill_rule(const XMLElement::FillRule &fill_rule) {
        _fill_rule = fill_rule;
        update_hash();
    }
    const std::string XMLElement::get_fill_attributes() const {
        std::stringstream ss;
        if (_fill != STR_NULL) ss << "fill=\"" << _fill << "\" ";
        if (_fill_opacity != NUM_NULL) ss << "fill-opacity=\"" << _fill_opacity << "\" ";
        if (_fill_rule == XMLElement::FillRule::EVENODD) ss << "fill-rule=\"evenodd" << "\" ";
        return ss.str();
    }

    const std::string XMLElement::get_stroke() const {
        return _stroke;
    }
    void XMLElement::set_stroke(const std::string &stroke) {
        _stroke = stroke;
        update_hash();
    }
    double XMLElement::get_stroke_width() const {
        return _stroke_width;
    }
    void XMLElement::set_stroke_width(const double &stroke_width) {
        _stroke_width = stroke_width;
        update_hash();
    }
    double XMLElement::get_stroke_opacity() const {
        return _stroke_opacity;
    }
    void XMLElement::set_stroke_opacity(const double &stroke_opacity) {
        _stroke_opacity = stroke_opacity;
        update_hash();
    }
    const XMLElement::StrokeLinecap XMLElement::get_stroke_linecap() const {
        return _stroke_linecap;
    }
    void XMLElement::set_stroke_linecap(const XMLElement::StrokeLinecap &stroke_linecap) {
        _stroke_linecap = stroke_linecap;
        update_hash();
    }
    const XMLElement::StrokeLinejoin XMLElement::get_stroke_linejoin() const {
        return _stroke_linejoin;
    }
    void XMLElement::set_stroke_linejoin(const XMLElement::StrokeLinejoin &stroke_linejoin) {
        _stroke_linejoin = stroke_linejoin;
        update_hash();
    }
    double XMLElement::get_stroke_miterlimit() const {
        return _stroke_miterlimit;
    }
    void XMLElement::set_stroke_miterlimit(const double &stroke_miterlimit) {
        _stroke_miterlimit = stroke_miterlimit;
        update_hash();
    }
    const std::string XMLElement::get_stroke_dasharray() const {
        return _stroke_dasharray;
    }
    void XMLElement::set_stroke_dasharray(const std::string &stroke_dasharray) {
        _stroke_dasharray = stroke_dasharray;
        update_hash();
    }
    double XMLElement::get_stroke_dashoffset() const {
        return _stroke_dashoffset;
    }
    void XMLElement::set_stroke_dashoffset(const double &stroke_dashoffset) {
        _stroke_dashoffset = stroke_dashoffset;
        update_hash();
    }
    const std::string XMLElement::get_stroke_attributes() const {
        std::stringstream ss;
        if (_stroke != STR_NULL) ss << "stroke=\"" << _stroke << "\" ";
        if (_stroke_width != NUM_NULL) ss << "stroke-width=\"" << _stroke_width << "\" ";
        if (_stroke_opacity != NUM_NULL) ss << "stroke-opacity=\"" << _stroke_opacity << "\" ";
        if (_stroke_linecap == XMLElement::StrokeLinecap::SQUARE) ss << "stroke-linecap=\"square" << "\" ";
        if (_stroke_linecap == XMLElement::StrokeLinecap::ROUND) ss << "stroke-linecap=\"round" << "\" ";
        if (_stroke_linejoin == XMLElement::StrokeLinejoin::ROUND) ss << "stroke-linejoin=\"round" << "\" ";
        if (_stroke_linejoin == XMLElement::StrokeLinejoin::BEVEL) ss << "stroke-linejoin=\"bevel" << "\" ";
        if (_stroke_miterlimit != NUM_NULL) ss << "stroke-miterlimit=\"" << _stroke_miterlimit << "\" ";
        if (_stroke_dasharray != STR_NULL) ss << "stroke-dasharray=\"" << _stroke_dasharray << "\" ";
        if (_stroke_dashoffset != NUM_NULL) ss << "stroke-dashoffset=\"" << _stroke_dashoffset << "\" ";
        return ss.str();
    }

    const std::string XMLElement::inner_XML() const {
        std::stringstream ss;
        ss << _inner_text << std::endl;
        for (auto &p : _inner_elements) {
            ss << p->outer_XML() << std::endl;
        }
        return ss.str();
    }
    void XMLElement::set_inner_text(const std::string &text) {
        _inner_text = text;
        update_hash();
    }
    const std::string XMLElement::get_inner_text() const {
        return _inner_text;
    }
    void XMLElement::add_inner_element(const std::shared_ptr<XMLElement> &inner_element) {
        _inner_elements.push_back(inner_element);
        update_hash();
    }
    void XMLElement::remove_inner_element(const std::shared_ptr<XMLElement> &inner_element) {
        _inner_elements.erase(std::remove(_inner_elements.begin(), _inner_elements.end(), inner_element), _inner_elements.end());
        update_hash();
    }
    const std::vector<std::shared_ptr<XMLElement>> XMLElement::get_inner_elements() const {
        return _inner_elements;
    }
    void XMLElement::set_inner_elements(const std::vector<std::shared_ptr<XMLElement>> &inner_elements) {
        _inner_elements = inner_elements;
        update_hash();
    }

    const std::string XMLElement::get_attributes() const {
        std::stringstream ss;

        const std::string _class_attributes = get_class_attributes();
        const std::string _fill_attributes = get_fill_attributes();
        const std::string _stroke_attributes = get_stroke_attributes();
        if (_class_attributes != "") ss << " " << _class_attributes;
        if (_fill_attributes != "") ss << " " << _fill_attributes;
        if (_stroke_attributes != "") ss << " " << _stroke_attributes;
        
        return ss.str();
    }

    const std::string XMLElement::outer_XML() const {
        std::stringstream ss;

        ss << "<" << get_tag();

        const std::string _attributes = get_attributes();
        if (_attributes != "") ss << " " << _attributes;

        auto _inner_xml = inner_XML();
        if (_inner_xml == "") {
            ss << "/>";
        } else {
            ss << ">" << std::endl << _inner_xml << std::endl << "</" << get_tag() << ">";
        }

        return ss.str();
    }

    void XMLElement::update_hash() {
        std::stringstream ss, sc;

        _attribute_hash = str_hash(get_attributes());

        sc << get_inner_text() << ",";
        for (auto p : _inner_elements) sc << p->get_outer_hash() << ",";
        _inner_hash = str_hash(sc.str());

        ss << get_tag() << ",";
        ss << get_attributes() << ",";
        ss << sc.str();
        _outer_hash = str_hash(ss.str());
    }
    const HASH_CODE XMLElement::get_attribute_hash() const {
        return _attribute_hash;
    }
    const HASH_CODE XMLElement::get_inner_hash() const {
        return _inner_hash;
    }
    const HASH_CODE XMLElement::get_outer_hash() const {
        return _outer_hash;
    }

    std::shared_ptr<XMLElement> XMLElement::clone() const {
        return std::make_shared<XMLElement>(*this);
    }
    bool XMLElement::operator==(const XMLElement &element) const {
        return element.get_outer_hash() == get_outer_hash();
    }
    const std::string XMLElement::operator-(const XMLElement &element) const {
        std::stringstream ss;

        if (get_tag() != element.get_tag()) {
            ss << "replace " << xml.size() << std::endl << xml << std::endl;
        }

        if (_classes != element.get_classes()) {
            if (_classes.size() == 0) ss << "reset class" << std::endl;
            else ss << "modify class \"" << get_class_attributes() << "\"" << std::endl;
        }

        if (_fill != element.get_fill()) {
            if (_fill == STR_NULL) ss << "reset fill" << std::endl;
            else ss << "modify fill \"" << _fill << "\"" << std::endl;
        }
        if (_fill_opacity != element.get_fill_opacity()) {
            if (_fill_opacity == NUM_NULL) ss << "reset fill-opacity" << std::endl;
            else ss << "modify fill-opacity " << _fill_opacity << std::endl;
        }
        if (_fill_rule != element.get_fill_rule()) {
            if (_fill_rule == XMLElement::FillRule::NONEZERO) ss << "reset fill-rule" << std::endl;
            else ss << "modify fill-opacity \"evenodd\"" << std::endl;
        }

        if (_stroke != STR_NULL) ss << "stroke=\"" << _stroke << "\" ";
        if (_stroke_width != NUM_NULL) ss << "stroke-width=\"" << _stroke_width << "\" ";
        if (_stroke_opacity != NUM_NULL) ss << "stroke-opacity=\"" << _stroke_opacity << "\" ";
        if (_stroke_linecap == XMLElement::StrokeLinecap::SQUARE) ss << "stroke-linecap=\"square" << "\" ";
        if (_stroke_linecap == XMLElement::StrokeLinecap::ROUND) ss << "stroke-linecap=\"round" << "\" ";
        if (_stroke_linejoin == XMLElement::StrokeLinejoin::ROUND) ss << "stroke-linejoin=\"round" << "\" ";
        if (_stroke_linejoin == XMLElement::StrokeLinejoin::BEVEL) ss << "stroke-linejoin=\"bevel" << "\" ";
        if (_stroke_miterlimit != NUM_NULL) ss << "stroke-miterlimit=\"" << _stroke_miterlimit << "\" ";
        if (_stroke_dasharray != STR_NULL) ss << "stroke-dasharray=\"" << _stroke_dasharray << "\" ";
        if (_stroke_dashoffset != NUM_NULL) ss << "stroke-dashoffset=\"" << _stroke_dashoffset << "\" ";

        return ss.str();
    }
}