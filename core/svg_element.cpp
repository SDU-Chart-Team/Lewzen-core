#include <sstream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "svg_element.h"

namespace Lewzen {
    DOMRect::DOMRect(const double &x, const double &y, const double &width, const double &height): _x(x), _y(y), _width(width), _height(height) {}
    DOMRect::DOMRect(const DOMRect &rect): _x(rect.get_x()), _y(rect.get_y()), _width(rect.get_width()), _height(rect.get_height()) {}
    double DOMRect::get_x() const {
        return _x;
    }
    double DOMRect::set_x(const double &x) {
        _x = x;
    }
    double DOMRect::get_y() const {
        return _y;
    }
    double DOMRect::set_y(const double &y) {
        _y = y;
    }
    double DOMRect::get_width() const {
        return _width;
    }
    double DOMRect::set_width(const double &width) {
        _width = width;
    }
    double DOMRect::get_height() const {
        return _height;
    }
    double DOMRect::set_height(const double &height) {
        _height = height;
    }
    double DOMRect::get_top() const {
        return (_height >= 0) ? _y : _y + _height;
    }
    double DOMRect::set_top(const double &top) {
        double d = top - get_top();
        if (_height >= 0) _y += d, _height -= d;
        else _height += d;
    }
    double DOMRect::get_left() const {
        return (_width >= 0) ? _x : _x + _width;
    }
    double DOMRect::set_left(const double &left) {
        double d = left - get_left();
        if (_width >= 0) _x += d, _width -= d;
        else _width += d;
    }
    double DOMRect::get_bottom() const {
        return (_height < 0) ? _y : _y + _height;
    }
    double DOMRect::set_bottom(const double &bottom) {
        double d = bottom - get_bottom();
        if (_height < 0) _y += d, _height -= d;
        else _height += d;
    }
    double DOMRect::get_right() const {
        return (_width < 0) ? _x : _x + _width;
    }
    double DOMRect::set_right(const double &right) {
        double d = right - get_right();
        if (_width < 0) _x += d, _width -= d;
        else _width += d;
    }

    bool _is_identity_2d(const DOMMatrix &matrix) { // TODO
        return false;
    }
    DOMMatrix::DOMMatrix(const double &m11, const double &m12, const double &m13, const double &m14, const double &m21, const double &m22, const double &m23, const double &m24, const double &m31, const double &m32, const double &m33, const double &m34, const double &m41, const double &m42, const double &m43, const double &m44):
        _m11(m11), _m12(m12), _m13(m13), _m14(m14), _m21(m21), _m22(m22), _m23(m23), _m24(m24), _m31(m31), _m32(m32), _m33(m33), _m34(m34), _m41(m41), _m42(m42), _m43(m43), _m44(m44), _2d(false) {
        _identity = _is_identity_2d(*this);
    }
    DOMMatrix::DOMMatrix(const double &a, const double &b, const double &c, const double &d, const double &e, const double &f):
        _m11(a), _m12(b), _m21(c), _m22(d), _m41(e), _m42(f), _m33(1), _m44(1), _2d(true) {
        _identity = _is_identity_2d(*this);
    }
    DOMMatrix::DOMMatrix(const double *mat, int size) {
        set_matrix(mat, size);
    }
    DOMMatrix::DOMMatrix(const DOMMatrix &matrix) {
        set_matrix(matrix.get_matrix(), matrix.is2D() ? 6 : 16);
    }
    const bool DOMMatrix::is2D() const {
        return _2d;
    }
    const bool DOMMatrix::isIdentity() const {
        return _identity;
    }
    void DOMMatrix::set_matrix(const double *mat, int size) {
        if (size <= 6) {
            double _mat[6];
            for (int i = 0; i < size; i++) _mat[i] = mat[i];
            for (int i = size; i < 6; i++) _mat[i] = 0;
            _m11 = _mat[0], _m12 = _mat[1], _m21 = _mat[2], _m22 = _mat[3], _m41 = _mat[4], _m42 = _mat[5], _m33 = 1, _m44 = 1, _2d = true;
        } else {
            double _mat[6];
            for (int i = 0; i < size; i++) _mat[i] = mat[i];
            for (int i = size; i < 16; i++) _mat[i] = 0;
            _m11 = _mat[0], _m12 = _mat[1], _m13 = _mat[2], _m14 = _mat[3], _m21 = _mat[4], _m22 = _mat[5], _m23 = _mat[6], _m24 = _mat[7], _m31 = _mat[8], _m32 = _mat[9], _m33 = _mat[10], _m34 = _mat[11], _m41 = _mat[12], _m42 = _mat[13], _m43 = _mat[14], _m44 = _mat[15], _2d = false;
        }
        _identity = _is_identity_2d(*this);
    }
    const double *DOMMatrix::get_matrix() const { // TODO
        return new double[0];
    }
    DOMMatrix &DOMMatrix::invert_self() { // TODO
        return *this;
    }
    DOMMatrix &DOMMatrix::multiplySelf(const DOMMatrix &matrix) { // TODO
        return *this;
    }
    DOMMatrix &DOMMatrix::preMultiplySelf(const DOMMatrix &matrix) { // TODO
        return *this;
    }
    DOMMatrix &DOMMatrix::translateSelf(const double &v1, const double &v2, const double &v3) { // TODO
        return *this;
    }
    DOMMatrix &DOMMatrix::scaleSelf(const double &v1, const double &v2, const double &v3) { // TODO
        return *this;
    }
    DOMMatrix &DOMMatrix::scale3dSelf(const double &v1, const double &v2, const double &v3) { // TODO
        return *this;
    }
    DOMMatrix &DOMMatrix::rotateSelf(const double &thetaX, const double &thetY, const double &thetZ) { // TODO
        return *this;
    }
    DOMMatrix &DOMMatrix::rotateAxisAngleSelf(const double &v1, const double &v2, const double &v3, const double &theta) { // TODO
        return *this;
    }
    DOMMatrix &DOMMatrix::rotateFromVectorSelf(const double &v1, const double &v2, const double &v3, const double &theta) { // TODO
        return *this;
    }
    DOMMatrix &DOMMatrix::skewXSelf(const double &theta) { // TODO
        return *this;
    }
    DOMMatrix &DOMMatrix::skewYSelf(const double &theta) { // TODO
        return *this;
    }

    DOMPoint::DOMPoint(const double &x, const double &y, const double &z, const double &w): _x(x), _y(y), _z(z), _w(w) {}
    DOMPoint::DOMPoint(const DOMPoint &point): _x(point.get_x()), _y(point.get_y()), _z(point.get_z()), _w(point.get_w()) {}
    double DOMPoint::get_x() const {
        return _x;
    }
    double DOMPoint::set_x(const double &x) {
        _x = x;
    }
    double DOMPoint::get_y() const{
        return _y;
    }
    double DOMPoint::set_y(const double &y){
        _x = y;
    }
    double DOMPoint::get_z() const{
        return _z;
    }
    double DOMPoint::set_z(const double &z){
        _z = z;
    }
    double DOMPoint::get_w() const{
        return _w;
    }
    double DOMPoint::set_w(const double &w){
        _w = w;
    }

    SVGElement::SVGElement() {
        _clip_path = STR_NULL;
        _clip_rule = ClipRule::NONZERO;
        _color = STR_NULL;
        _color_interpolation = ColorInterpolation::S_RGB;
        _cursor = Cursor::AUTO;
        _display = STR_NULL;
        _fill = STR_NULL;
        _fill_opacity = NUM_NULL;
        _fill_rule = FillRule::NONZERO;
        _filter = STR_NULL;
        _mask = STR_NULL;
        _opacity = NUM_NULL;
        _pointer_events = PointerEvents::VISIBLE_PAINTED;
        _shape_rendering = ShapeRendering::AUTO;
        _stroke = STR_NULL;
        _stroke_dasharray = STR_NULL;
        _stroke_dashoffset = NUM_NULL;
        _stroke_linecap = StrokeLinecap::BUTT;
        _stroke_linejoin = StrokeLinejoin::MITER;
        _stroke_miterlimit = NUM_NULL;
        _stroke_opacity = NUM_NULL;
        _stroke_width = NUM_NULL;
        _transform = STR_NULL;
        _vector_effect = VectorEffect::NONE;
        _visibility = Visibility::VISIBLE;
    }
    SVGElement::SVGElement(const SVGElement &element) {
        _classes = element.get_classes();

        _clip_path = element.get_clip_path();
        _clip_rule = element.get_clip_rule();
        _color = element.get_color();
        _color_interpolation = element.get_color_interpolation();
        _cursor = element.get_cursor();
        _display = element.get_display();
        _fill = element.get_fill();
        _fill_opacity = element.get_fill_opacity();
        _fill_rule = element.get_fill_rule();
        _filter = element.get_filter();
        _mask = element.get_mask();
        _opacity = element.get_opacity();
        _pointer_events = element.get_pointer_events();
        _shape_rendering = element.get_shape_rendering();
        _stroke = element.get_stroke();
        _stroke_dasharray = element.get_stroke_dasharray();
        _stroke_dashoffset = element.get_stroke_dashoffset();
        _stroke_linecap = element.get_stroke_linecap();
        _stroke_linejoin = element.get_stroke_linejoin();
        _stroke_miterlimit = element.get_stroke_miterlimit();
        _stroke_opacity = element.get_stroke_opacity();
        _stroke_width = element.get_stroke_width();
        _transform = element.get_transform();
        _vector_effect = element.get_vector_effect();
        _visibility = element.get_visibility();

        _inner_text = element.get_inner_text();
        for (auto p : element.get_inner_elements()) {
            _inner_elements.push_back(p->clone());
        }

        _attribute_hash = element.get_attribute_hash();
        _inner_hash = element.get_inner_hash();
        _outer_hash = element.get_outer_hash();
    }

    const std::string SVGElement::get_tag() const {
        return "?";
    }

    void SVGElement::add_class(const std::string &cls) {
        _classes.insert(cls);
        update_hash();
    }
    void SVGElement::remove_class(const std::string &cls) {
        _classes.erase(_classes.end());
        update_hash();
    }
    const std::set<std::string> SVGElement::get_classes() const {
        return _classes;
    }
    void SVGElement::set_inner_elements(const std::set<std::string> &cls_list) {
        _classes = cls_list;
        update_hash();
    }
    const std::string SVGElement::get_class_attributes() const {
        std::stringstream ss;
        ss << "class=\"";
        for (auto &_cls : _classes) {
            ss << "." <<_cls << " ";
        }
        ss << "\"";
        return ss.str();
    }

    const std::string SVGElement::get_clip_path() const {
        return _clip_path;
    }
    void SVGElement::set_clip_path(const std::string &clip_path) {
        _clip_path = clip_path;
    }
    const SVGElement::ClipRule SVGElement::get_clip_rule() const {
        return _clip_rule;
    }
    void SVGElement::set_clip_rule(const SVGElement::ClipRule &clip_rule) {
        _clip_rule = clip_rule;
    }
    const std::string SVGElement::get_color() const {
        return _color;
    }
    void SVGElement::set_color(const std::string &color) {
        _color = color;
    }
    const SVGElement::ColorInterpolation SVGElement::get_color_interpolation() const {
        return _color_interpolation;
    }
    void SVGElement::set_color_interpolation(const SVGElement::ColorInterpolation &color_interpolation) {
        _color_interpolation = color_interpolation;
    }
    const SVGElement::Cursor SVGElement::get_cursor() const {
        return _cursor;
    }
    void SVGElement::set_cursor(const SVGElement::Cursor &cursor) {
        _cursor = cursor;
    }
    const std::string SVGElement::get_display() const {
        return _display;
    }
    void SVGElement::set_display(const std::string &display) {
        _display = display;
    }
    const std::string SVGElement::get_fill() const {
        return _fill;
    }
    void SVGElement::set_fill(const std::string &fill) {
        _fill = fill;
    }
    double SVGElement::get_fill_opacity() const {
        return _fill_opacity;
    }
    void SVGElement::set_fill_opacity(const double &fill_opacity) {
        _fill_opacity = fill_opacity;
    }
    const SVGElement::FillRule SVGElement::get_fill_rule() const {
        return _fill_rule;
    }
    void SVGElement::set_fill_rule(const SVGElement::FillRule &fill_rule) {
        _fill_rule = fill_rule;
    }
    const std::string SVGElement::get_filter() const {
        return _filter;
    }
    void SVGElement::set_filter(const std::string &filter) {
        _filter = filter;
    }
    const std::string SVGElement::get_mask() const {
        return _mask;
    }
    void SVGElement::set_mask(const std::string &mask) {
        _mask = mask;
    }
    double SVGElement::get_opacity() const {
        return _opacity;
    }
    void SVGElement::set_opacity(const double &opacity) {
        _opacity = opacity;
    }
    const SVGElement::PointerEvents SVGElement::get_pointer_events() const {
        return _pointer_events;
    }
    void SVGElement::set_pointer_events(const SVGElement::PointerEvents &pointer_events) {
        _pointer_events = pointer_events;
    }
    const SVGElement::ShapeRendering SVGElement::get_shape_rendering() const {
        return _shape_rendering;
    }
    void SVGElement::set_shape_rendering(const SVGElement::ShapeRendering &shape_rendering) {
        _shape_rendering = shape_rendering;
    }
    const std::string SVGElement::get_stroke() const {
        return _stroke;
    }
    void SVGElement::set_stroke(const std::string &stroke) {
        _stroke = stroke;
    }
    const std::string SVGElement::get_stroke_dasharray() const {
        return _stroke_dasharray;
    }
    void SVGElement::set_stroke_dasharray(const std::string &stroke_dasharray) {
        _stroke_dasharray = stroke_dasharray;
    }
    double SVGElement::get_stroke_dashoffset() const {
        return _stroke_dashoffset;
    }
    void SVGElement::set_stroke_dashoffset(const double &stroke_dashoffset) {
        _stroke_dashoffset = stroke_dashoffset;
    }
    const SVGElement::StrokeLinecap SVGElement::get_stroke_linecap() const {
        return _stroke_linecap;
    }
    void SVGElement::set_stroke_linecap(const SVGElement::StrokeLinecap &stroke_linecap) {
        _stroke_linecap = stroke_linecap;
    }
    const SVGElement::StrokeLinejoin SVGElement::get_stroke_linejoin() const {
        return _stroke_linejoin;
    }
    void SVGElement::set_stroke_linejoin(const SVGElement::StrokeLinejoin &stroke_linejoin) {
        _stroke_linejoin = stroke_linejoin;
    }
    double SVGElement::get_stroke_miterlimit() const {
        return _stroke_miterlimit;
    }
    void SVGElement::set_stroke_miterlimit(const double &stroke_miterlimit) {
        _stroke_miterlimit = stroke_miterlimit;
    }
    double SVGElement::get_stroke_opacity() const {
        return _stroke_opacity;
    }
    void SVGElement::set_stroke_opacity(const double &stroke_opacity) {
        _stroke_opacity = stroke_opacity;
    }
    double SVGElement::get_stroke_width() const {
        return _stroke_width;
    }
    void SVGElement::set_stroke_width(const double &stroke_width) {
        _stroke_width = stroke_width;
    }
    const std::string SVGElement::get_transform() const {
        return _transform;
    }
    void SVGElement::set_transform(const std::string &transform) {
        _transform = transform;
    }
    const SVGElement::VectorEffect SVGElement::get_vector_effect() const {
        return _vector_effect;
    }
    void SVGElement::set_vector_effect(const SVGElement::VectorEffect &vector_effect) {
        _vector_effect = vector_effect;
    }
    const SVGElement::Visibility SVGElement::get_visibility() const {
        return _visibility;
    }
    void SVGElement::set_visibility(const SVGElement::Visibility &visibility) {
        _visibility = visibility;
    }

    const std::string SVGElement::inner_SVG() const {
        std::stringstream ss;
        ss << _inner_text << std::endl;
        for (auto &p : _inner_elements) {
            ss << p->outer_SVG() << std::endl;
        }
        return ss.str();
    }
    void SVGElement::set_inner_text(const std::string &text) {
        _inner_text = text;
        update_hash();
    }
    const std::string SVGElement::get_inner_text() const {
        return _inner_text;
    }
    void SVGElement::add_inner_element(const std::shared_ptr<SVGElement> &inner_element) {
        _inner_elements.push_back(inner_element);
        update_hash();
    }
    void SVGElement::remove_inner_element(const std::shared_ptr<SVGElement> &inner_element) {
        _inner_elements.erase(std::remove(_inner_elements.begin(), _inner_elements.end(), inner_element), _inner_elements.end());
        update_hash();
    }
    const std::vector<std::shared_ptr<SVGElement>> SVGElement::get_inner_elements() const {
        return _inner_elements;
    }
    void SVGElement::set_inner_elements(const std::vector<std::shared_ptr<SVGElement>> &inner_elements) {
        _inner_elements = inner_elements;
        update_hash();
    }

    const std::string SVGElement::get_attributes() const {
        std::stringstream ss;

        const std::string _class_attributes = get_class_attributes();
        if (_class_attributes != "") ss << " " << _class_attributes;
        
        if (_clip_path != STR_NULL) ss << " clip-path=\"" << _clip_path << "\"";
        if (_clip_rule == ClipRule::EVENODD) ss << " clip-rule=\"evenodd\"";
        if (_clip_rule == ClipRule::INHERIT) ss << " clip-rule=\"inherit\"";
        if (_color != STR_NULL) ss << " color=\"" << _color << "\"";
        if (_color_interpolation == ColorInterpolation::AUTO) ss << " color-interpolation=\"auto\"";
        if (_color_interpolation == ColorInterpolation::LINEAR_RGB) ss << " color-interpolation=\"linearRGB\"";
        if (_cursor == Cursor::CROSSHAIR) ss << " cursor=\"crosshair\"";
        if (_cursor == Cursor::DEFAULT) ss << " cursor=\"default\"";
        if (_cursor == Cursor::POINTER) ss << " cursor=\"pointer\"";
        if (_cursor == Cursor::MOVE) ss << " cursor=\"move\"";
        if (_cursor == Cursor::E_RESIZE) ss << " cursor=\"e-resize\"";
        if (_cursor == Cursor::NE_RESIZE) ss << " cursor=\"ne-resize\"";
        if (_cursor == Cursor::NW_RESIZE) ss << " cursor=\"nw-resize\"";
        if (_cursor == Cursor::N_RESIZE) ss << " cursor=\"n-resize\"";
        if (_cursor == Cursor::SE_RESIZE) ss << " cursor=\"se-resize\"";
        if (_cursor == Cursor::SW_RESIZE) ss << " cursor=\"sw-resize\"";
        if (_cursor == Cursor::S_RESIZE) ss << " cursor=\"s-resize\"";
        if (_cursor == Cursor::W_RESIZE) ss << " cursor=\"w-resize\"";
        if (_cursor == Cursor::TEXT) ss << " cursor=\"text\"";
        if (_cursor == Cursor::WAIT) ss << " cursor=\"wait\"";
        if (_cursor == Cursor::HELP) ss << " cursor=\"help\"";
        if (_cursor == Cursor::INHERIT) ss << " cursor=\"inherit\"";
        if (_display != STR_NULL) ss << " display=\"" << _display << "\"";
        if (_fill != STR_NULL) ss << " fill=\"" << _fill << "\"";
        if (_fill_opacity != NUM_NULL) ss << " fill-opacity=\"" << _fill_opacity << "\"";
        if (_fill_rule == FillRule::EVENODD) ss << " fill-rule=\"evenodd\"";
        if (_filter != STR_NULL) ss << " filter=\"" << _filter << "\"";
        if (_mask != STR_NULL) ss << " mask=\"" << _mask << "\"";
        if (_opacity != NUM_NULL) ss << " opacity=\"" << _opacity << "\"";
        if (_pointer_events == PointerEvents::BOUNDING_BOX) ss << " pointer-events=\"bounding-box\"";
        if (_pointer_events == PointerEvents::VISIBLE_FILL) ss << " pointer-events=\"visibleFill\"";
        if (_pointer_events == PointerEvents::VISIBLE_STROKE) ss << " pointer-events=\"visibleStroke\"";
        if (_pointer_events == PointerEvents::VISIBLE) ss << " pointer-events=\"visible\"";
        if (_pointer_events == PointerEvents::PAINTED) ss << " pointer-events=\"painted\"";
        if (_pointer_events == PointerEvents::FILL) ss << " pointer-events=\"fill\"";
        if (_pointer_events == PointerEvents::STROKE) ss << " pointer-events=\"stroke\"";
        if (_pointer_events == PointerEvents::ALL) ss << " pointer-events=\"all\"";
        if (_pointer_events == PointerEvents::NONE) ss << " pointer-events=\"none\"";
        if (_shape_rendering == ShapeRendering::OPTIMIZE_SPEED) ss << " shape-rendering=\"optimizeSpeed\"";
        if (_shape_rendering == ShapeRendering::CRISP_EDGES) ss << " shape-rendering=\"crispEdges\"";
        if (_shape_rendering == ShapeRendering::GEOMETRIC_PRECISION) ss << " shape-rendering=\"geometricPrecision\"";
        if (_stroke != STR_NULL) ss << " stroke=\"" << _stroke << "\"";
        if (_stroke_dasharray != STR_NULL) ss << " stroke-dasharray=\"" << _stroke_dasharray << "\"";
        if (_stroke_dashoffset != NUM_NULL) ss << " stroke-dashoffset=\"" << _stroke_dashoffset << "\"";
        if (_stroke_linecap == StrokeLinecap::ROUND) ss << " stroke-linecap=\"round\"";
        if (_stroke_linecap == StrokeLinecap::SQUARE) ss << " stroke-linecap=\"square\"";
        if (_stroke_linejoin == StrokeLinejoin::ARCS) ss << " stroke-linejoin=\"arcs\"";
        if (_stroke_linejoin == StrokeLinejoin::BEVEL) ss << " stroke-linejoin=\"bevel\"";
        if (_stroke_linejoin == StrokeLinejoin::MITER_CLIP) ss << " stroke-linejoin=\"miter-clip\"";
        if (_stroke_linejoin == StrokeLinejoin::ROUND) ss << " stroke-linejoin=\"round\"";
        if (_stroke_miterlimit != NUM_NULL) ss << " stroke-miterlimit=\"" << _stroke_miterlimit << "\"";
        if (_stroke_opacity != NUM_NULL) ss << " stroke-opacity=\"" << _stroke_opacity << "\"";
        if (_stroke_width != NUM_NULL) ss << " stroke-width=\"" << _stroke_width << "\"";
        if (_transform != STR_NULL) ss << " transform=\"" << _transform << "\"";
        if (_vector_effect == VectorEffect::NON_SCALING_STROKE) ss << " vector-effect=\"non-scaling-stroke\"";
        if (_vector_effect == VectorEffect::NON_SCALING_SIZE) ss << " vector-effect=\"non-scaling-size\"";
        if (_vector_effect == VectorEffect::NON_ROTATION) ss << " vector-effect=\"non-rotation\"";
        if (_vector_effect == VectorEffect::FIXED_POSITION) ss << " vector-effect=\"fixed-position\"";
        if (_visibility == Visibility::HIDDEN) ss << " visibility=\"hidden\"";
        if (_visibility == Visibility::COLLAPSE) ss << " visibility=\"collapse\"";
        
        return ss.str();
    }

    const DOMRect SVGElement::getBBox() const {
#ifndef SVGElement_getBBox
#define SVGElement_getBBox \
        return DOMRect();
#endif
        SVGElement_getBBox
    }
    const DOMMatrix SVGElement::getCTM() const {
#ifndef SVGElement_getCTM
#define SVGElement_getCTM \
        return DOMMatrix();
#endif
        SVGElement_getCTM
    }
    const DOMMatrix SVGElement::getScreenCTM() const {
#ifndef SVGElement_getScreenCTM
#define SVGElement_getScreenCTM \
        return DOMMatrix();
#endif
        SVGElement_getScreenCTM
    }
    const bool SVGElement::isPointInFill() const {
#ifndef SVGElement_isPointInFill
#define SVGElement_isPointInFill \
        return false;
#endif
        SVGElement_isPointInFill
    }
    const bool SVGElement::isPointInStroke() const {
#ifndef SVGElement_isPointInStroke
#define SVGElement_isPointInStroke \
        return false;
#endif
        SVGElement_isPointInStroke
    }
    const double SVGElement::getTotalLength() const {
#ifndef SVGElement_getTotalLength
#define SVGElement_getTotalLength \
        return 0;
#endif
        SVGElement_getTotalLength
    }
    const DOMPoint SVGElement::getPointAtLength() const {
#ifndef SVGElement_getPointAtLength
#define SVGElement_getPointAtLength \
        return DOMPoint();
#endif
        SVGElement_getPointAtLength
    }

    const std::string SVGElement::outer_SVG() const {
        std::stringstream ss;

        ss << "<" << get_tag();

        const std::string _attributes = get_attributes();
        if (_attributes != "") ss << " " << _attributes;

        auto _inner_svg = inner_SVG();
        if (_inner_svg == "") {
            ss << "/>";
        } else {
            ss << ">" << std::endl << _inner_svg << std::endl << "</" << get_tag() << ">";
        }

        return ss.str();
    }

    void SVGElement::update_hash() {
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
    const HASH_CODE SVGElement::get_attribute_hash() const {
        return _attribute_hash;
    }
    const HASH_CODE SVGElement::get_inner_hash() const {
        return _inner_hash;
    }
    const HASH_CODE SVGElement::get_outer_hash() const {
        return _outer_hash;
    }

    std::shared_ptr<SVGElement> SVGElement::clone() const {
        return std::make_shared<SVGElement>(*this);
    }
    bool SVGElement::operator==(const SVGElement &element) const {
        return element.get_outer_hash() == get_outer_hash();
    }
    const std::string SVGElement::operator-(const SVGElement &element) const {
        std::stringstream ss;

        if (get_tag() != element.get_tag()) {
            auto svg = outer_SVG();
            ss << "replace " << svg.size() << std::endl << svg << std::endl;
        }

        if (_classes != element.get_classes()) {
            if (_classes.size() == 0) ss << "reset class" << std::endl;
            else ss << "modify class \"" << get_class_attributes() << "\"" << std::endl;
        }

        if (_clip_path != element.get_clip_path()) {
            if (_clip_path == STR_NULL) ss << "reset clip-path" << std::endl;
            else ss << "modify clip-path \"" << _clip_path << "\"" << std::endl;
        }
        if (_clip_rule != element.get_clip_rule()) {
            if (_clip_rule == ClipRule::NONZERO) ss << "reset clip-rule" << std::endl;
            else if (_clip_rule == ClipRule::EVENODD) ss << "modify clip-rule \"evenodd\"" << std::endl;
            else if (_clip_rule == ClipRule::INHERIT) ss << "modify clip-rule \"inherit\"" << std::endl;
        }
        if (_color != element.get_color()) {
            if (_color == STR_NULL) ss << "reset color" << std::endl;
            else ss << "modify color \"" << _color << "\"" << std::endl;
        }
        if (_color_interpolation != element.get_color_interpolation()) {
            if (_color_interpolation == ColorInterpolation::S_RGB) ss << "reset color-interpolation" << std::endl;
            else if (_color_interpolation == ColorInterpolation::AUTO) ss << "modify color-interpolation \"auto\"" << std::endl;
            else if (_color_interpolation == ColorInterpolation::LINEAR_RGB) ss << "modify color-interpolation \"linearRGB\"" << std::endl;
        }
        if (_cursor != element.get_cursor()) {
            if (_cursor == Cursor::AUTO) ss << "reset cursor" << std::endl;
            else if (_cursor == Cursor::CROSSHAIR) ss << "modify cursor \"crosshair\"" << std::endl;
            else if (_cursor == Cursor::DEFAULT) ss << "modify cursor \"default\"" << std::endl;
            else if (_cursor == Cursor::POINTER) ss << "modify cursor \"pointer\"" << std::endl;
            else if (_cursor == Cursor::MOVE) ss << "modify cursor \"move\"" << std::endl;
            else if (_cursor == Cursor::E_RESIZE) ss << "modify cursor \"e-resize\"" << std::endl;
            else if (_cursor == Cursor::NE_RESIZE) ss << "modify cursor \"ne-resize\"" << std::endl;
            else if (_cursor == Cursor::NW_RESIZE) ss << "modify cursor \"nw-resize\"" << std::endl;
            else if (_cursor == Cursor::N_RESIZE) ss << "modify cursor \"n-resize\"" << std::endl;
            else if (_cursor == Cursor::SE_RESIZE) ss << "modify cursor \"se-resize\"" << std::endl;
            else if (_cursor == Cursor::SW_RESIZE) ss << "modify cursor \"sw-resize\"" << std::endl;
            else if (_cursor == Cursor::S_RESIZE) ss << "modify cursor \"s-resize\"" << std::endl;
            else if (_cursor == Cursor::W_RESIZE) ss << "modify cursor \"w-resize\"" << std::endl;
            else if (_cursor == Cursor::TEXT) ss << "modify cursor \"text\"" << std::endl;
            else if (_cursor == Cursor::WAIT) ss << "modify cursor \"wait\"" << std::endl;
            else if (_cursor == Cursor::HELP) ss << "modify cursor \"help\"" << std::endl;
            else if (_cursor == Cursor::INHERIT) ss << "modify cursor \"inherit\"" << std::endl;
        }
        if (_display != element.get_display()) {
            if (_display == STR_NULL) ss << "reset display" << std::endl;
            else ss << "modify display \"" << _display << "\"" << std::endl;
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
            if (_fill_rule == FillRule::NONZERO) ss << "reset fill-rule" << std::endl;
            else if (_fill_rule == FillRule::EVENODD) ss << "modify fill-rule \"evenodd\"" << std::endl;
        }
        if (_filter != element.get_filter()) {
            if (_filter == STR_NULL) ss << "reset filter" << std::endl;
            else ss << "modify filter \"" << _filter << "\"" << std::endl;
        }
        if (_mask != element.get_mask()) {
            if (_mask == STR_NULL) ss << "reset mask" << std::endl;
            else ss << "modify mask \"" << _mask << "\"" << std::endl;
        }
        if (_opacity != element.get_opacity()) {
            if (_opacity == NUM_NULL) ss << "reset opacity" << std::endl;
            else ss << "modify opacity " << _opacity << std::endl;
        }
        if (_pointer_events != element.get_pointer_events()) {
            if (_pointer_events == PointerEvents::VISIBLE_PAINTED) ss << "reset pointer-events" << std::endl;
            else if (_pointer_events == PointerEvents::BOUNDING_BOX) ss << "modify pointer-events \"bounding-box\"" << std::endl;
            else if (_pointer_events == PointerEvents::VISIBLE_FILL) ss << "modify pointer-events \"visibleFill\"" << std::endl;
            else if (_pointer_events == PointerEvents::VISIBLE_STROKE) ss << "modify pointer-events \"visibleStroke\"" << std::endl;
            else if (_pointer_events == PointerEvents::VISIBLE) ss << "modify pointer-events \"visible\"" << std::endl;
            else if (_pointer_events == PointerEvents::PAINTED) ss << "modify pointer-events \"painted\"" << std::endl;
            else if (_pointer_events == PointerEvents::FILL) ss << "modify pointer-events \"fill\"" << std::endl;
            else if (_pointer_events == PointerEvents::STROKE) ss << "modify pointer-events \"stroke\"" << std::endl;
            else if (_pointer_events == PointerEvents::ALL) ss << "modify pointer-events \"all\"" << std::endl;
            else if (_pointer_events == PointerEvents::NONE) ss << "modify pointer-events \"none\"" << std::endl;
        }
        if (_shape_rendering != element.get_shape_rendering()) {
            if (_shape_rendering == ShapeRendering::AUTO) ss << "reset shape-rendering" << std::endl;
            else if (_shape_rendering == ShapeRendering::OPTIMIZE_SPEED) ss << "modify shape-rendering \"optimizeSpeed\"" << std::endl;
            else if (_shape_rendering == ShapeRendering::CRISP_EDGES) ss << "modify shape-rendering \"crispEdges\"" << std::endl;
            else if (_shape_rendering == ShapeRendering::GEOMETRIC_PRECISION) ss << "modify shape-rendering \"geometricPrecision\"" << std::endl;
        }
        if (_stroke != element.get_stroke()) {
            if (_stroke == STR_NULL) ss << "reset stroke" << std::endl;
            else ss << "modify stroke \"" << _stroke << "\"" << std::endl;
        }
        if (_stroke_dasharray != element.get_stroke_dasharray()) {
            if (_stroke_dasharray == STR_NULL) ss << "reset stroke-dasharray" << std::endl;
            else ss << "modify stroke-dasharray \"" << _stroke_dasharray << "\"" << std::endl;
        }
        if (_stroke_dashoffset != element.get_stroke_dashoffset()) {
            if (_stroke_dashoffset == NUM_NULL) ss << "reset stroke-dashoffset" << std::endl;
            else ss << "modify stroke-dashoffset " << _stroke_dashoffset << std::endl;
        }
        if (_stroke_linecap != element.get_stroke_linecap()) {
            if (_stroke_linecap == StrokeLinecap::BUTT) ss << "reset stroke-linecap" << std::endl;
            else if (_stroke_linecap == StrokeLinecap::ROUND) ss << "modify stroke-linecap \"round\"" << std::endl;
            else if (_stroke_linecap == StrokeLinecap::SQUARE) ss << "modify stroke-linecap \"square\"" << std::endl;
        }
        if (_stroke_linejoin != element.get_stroke_linejoin()) {
            if (_stroke_linejoin == StrokeLinejoin::MITER) ss << "reset stroke-linejoin" << std::endl;
            else if (_stroke_linejoin == StrokeLinejoin::ARCS) ss << "modify stroke-linejoin \"arcs\"" << std::endl;
            else if (_stroke_linejoin == StrokeLinejoin::BEVEL) ss << "modify stroke-linejoin \"bevel\"" << std::endl;
            else if (_stroke_linejoin == StrokeLinejoin::MITER_CLIP) ss << "modify stroke-linejoin \"miter-clip\"" << std::endl;
            else if (_stroke_linejoin == StrokeLinejoin::ROUND) ss << "modify stroke-linejoin \"round\"" << std::endl;
        }
        if (_stroke_miterlimit != element.get_stroke_miterlimit()) {
            if (_stroke_miterlimit == NUM_NULL) ss << "reset stroke-miterlimit" << std::endl;
            else ss << "modify stroke-miterlimit " << _stroke_miterlimit << std::endl;
        }
        if (_stroke_opacity != element.get_stroke_opacity()) {
            if (_stroke_opacity == NUM_NULL) ss << "reset stroke-opacity" << std::endl;
            else ss << "modify stroke-opacity " << _stroke_opacity << std::endl;
        }
        if (_stroke_width != element.get_stroke_width()) {
            if (_stroke_width == NUM_NULL) ss << "reset stroke-width" << std::endl;
            else ss << "modify stroke-width " << _stroke_width << std::endl;
        }
        if (_transform != element.get_transform()) {
            if (_transform == STR_NULL) ss << "reset transform" << std::endl;
            else ss << "modify transform \"" << _transform << "\"" << std::endl;
        }
        if (_vector_effect != element.get_vector_effect()) {
            if (_vector_effect == VectorEffect::NONE) ss << "reset vector-effect" << std::endl;
            else if (_vector_effect == VectorEffect::NON_SCALING_STROKE) ss << "modify vector-effect \"non-scaling-stroke\"" << std::endl;
            else if (_vector_effect == VectorEffect::NON_SCALING_SIZE) ss << "modify vector-effect \"non-scaling-size\"" << std::endl;
            else if (_vector_effect == VectorEffect::NON_ROTATION) ss << "modify vector-effect \"non-rotation\"" << std::endl;
            else if (_vector_effect == VectorEffect::FIXED_POSITION) ss << "modify vector-effect \"fixed-position\"" << std::endl;
        }
        if (_visibility != element.get_visibility()) {
            if (_visibility == Visibility::VISIBLE) ss << "reset visibility" << std::endl;
            else if (_visibility == Visibility::HIDDEN) ss << "modify visibility \"hidden\"" << std::endl;
            else if (_visibility == Visibility::COLLAPSE) ss << "modify visibility \"collapse\"" << std::endl;
        }

        // inner..

        return ss.str();
    }
}