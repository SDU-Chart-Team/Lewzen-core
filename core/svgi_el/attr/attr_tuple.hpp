#ifndef __LZ_ATTR_TUPLE__
#define __LZ_ATTR_TUPLE__
#include <array>
#include <tuple>
#include <sstream>
#include "../attr.hpp"

namespace Lewzen {
    template<typename... Ts>
    class AttrTuple {
    private:
        std::tuple<Ts...> _tuple;
        std::array<std::string, sizeof...(Ts)> _attrs;
        std::array<std::function<const std::string()>, sizeof...(Ts)> _getts;
        std::array<std::function<void(const std::string &)>, sizeof...(Ts)> _setts;
        std::string _seperator;
    private:
        const std::string _commit() const {
        __commit<0, Ts...>();
        std::stringstream ss;
            for (int i = 0; i < sizeof...(Ts); i++) {
                ss << _attrs[i];
                if (i < sizeof...(Ts) - 1) ss << _seperator;
            }
            return ss.str();
        }
        template<std::size_t i, typename L>
        void __commit() const {
            auto u = std::get<i>(_tuple);
            __commit_impl(u);
        }
        template<std::size_t i, typename F, typename S, typename ...R>
        void __commit() const {
            auto u = std::get<i>(_tuple);
            __commit_impl(u);
            __commit<i + 1, S, R...>();
        }
        template<typename I>
        void __commit_impl(I &u) const {
            _LZ_WARNING("Found unsupported ctype \"" << typeid(u).name() << "\" in Tuple, which only supports SVG attributes.");
        }
        void __commit_impl(AttrColor &u) const {
            u.commit();
        }
        void __commit_impl(AttrCoordinate &u) const {
            u.commit();
        }
        void __commit_impl(AttrAnything &u) const {
            u.commit();
        }
        void __commit_impl(AttrInteger &u) const {
            u.commit();
        }
        void __commit_impl(AttrListOfNumbers &u) const {
            u.commit();
        }
        void __commit_impl(AttrURL &u) const {
            u.commit();
        }
        void __commit_impl(AttrTransformList &u) const {
            u.commit();
        }
        void __commit_impl(AttrPercentage &u) const {
            u.commit();
        }
        void __commit_impl(AttrLength &u) const {
            u.commit();
        }
        void __commit_impl(AttrIRI &u) const {
            u.commit();
        }
        void __commit_impl(AttrPaint &u) const {
            u.commit();
        }
        void __commit_impl(AttrName &u) const {
            u.commit();
        }
        void __commit_impl(AttrAngle &u) const {
            u.commit();
        }
        void __commit_impl(AttrOpacityValue &u) const {
            u.commit();
        }
        void __commit_impl(AttrNumber &u) const {
            u.commit();
        }
        void __commit_impl(AttrFuncIRI &u) const {
            u.commit();
        }
        void __commit_impl(AttrConst &u) const {
            u.commit();
        }
        void __commit_impl(AttrConst100 &u) const {
            u.commit();
        }
        void __commit_impl(AttrConst200 &u) const {
            u.commit();
        }
        void __commit_impl(AttrConst300 &u) const {
            u.commit();
        }
        void __commit_impl(AttrConst400 &u) const {
            u.commit();
        }
        void __commit_impl(AttrConst500 &u) const {
            u.commit();
        }
        void __commit_impl(AttrConst600 &u) const {
            u.commit();
        }
        void __commit_impl(AttrConst700 &u) const {
            u.commit();
        }
        void __commit_impl(AttrConst800 &u) const {
            u.commit();
        }
        void __commit_impl(AttrConst900 &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstAccumulate &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstAfterEdge &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstAll &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstAlphabetic &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstArcs &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstAuto &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstAutoStartReverse &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstBaseline &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstBeforeEdge &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstBevel &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstBlink &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstBold &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstBolder &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstBoundingBox &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstButt &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstCenter &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstCentral &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstCollapse &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstCrispEdges &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstCurrentcolor &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstDefault &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstEnd &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstEvenodd &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstFill &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstGeometricPrecision &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstHanging &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstHidden &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstIdeographic &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstInherit &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstItalic &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstLeft &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstLighter &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstLineThrough &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstLinearRGB &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstLr &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstLrTb &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstLtr &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstMathematical &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstMeet &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstMiddle &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstMiter &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstMiterClip &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstNew &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstNonScalingStroke &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstNone &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstNonezero &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstNonzero &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstNormal &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstObjectBoundingBox &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstOblique &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstOptimizeLegibility &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstOptimizeQuality &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstOptimizeSpeed &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstOverline &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstPad &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstPainted &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstPreserve &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstReflect &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstRepeat &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstRight &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstRl &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstRlTb &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstRound &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstRtl &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstSRGB &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstScroll &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstSlice &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstSpacing &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstSpacingAndGlyphs &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstSquare &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstStart &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstStroke &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstStrokeWidth &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstSub &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstSuper &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstTb &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstTbRl &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstTextAfterEdge &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstTextBeforeEdge &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstTextBottom &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstTextTop &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstUnderline &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstUserSpaceOnUse &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstVisible &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstVisibleFil &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstVisiblePainted &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstVisibleStroke &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstXMaxYMax &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstXMaxYMid &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstXMaxYMin &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstXMidYMax &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstXMidYMid &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstXMidYMin &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstXMinYMax &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstXMinYMid &u) const {
            u.commit();
        }
        void __commit_impl(AttrConstXMinYMin &u) const {
            u.commit();
        }
        std::function<const std::string()> _getter;
        std::function<void(const std::string &)> _setter;
    public:
        /**
        * Empty Constructor of Tuple.
        */
        AttrTuple() {}

        /**
        * Constructor of Tuple
        */
        AttrTuple(std::function<const std::string()> getter, std::function<void(const std::string &)> setter, std::string seperator = " "): _getter(getter), _setter(setter), _seperator(seperator) {
            _Tuple<0, Ts...>();
        }
        template<std::size_t i, typename L>
        void _Tuple() {
            auto &u = std::get<i>(_tuple);
            _getts[i] = [this](){return _attrs[i];}, _setts[i] = [this](const std::string &attr){_attrs[i] = attr;};
            _TupleImpl(u, _getts[i], _setts[i]);
        }
        template<std::size_t i, typename F, typename S, typename ...R>
        void _Tuple() {
            auto &u = std::get<i>(_tuple);
            _getts[i] = [this](){return _attrs[i];}, _setts[i] = [this](const std::string &attr){_attrs[i] = attr;};
            _TupleImpl(u, _getts[i], _setts[i]);
            _Tuple<i + 1, S, R...>();
        }
        template<typename I>
        void _TupleImpl(I &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            _LZ_WARNING("Found unsupported ctype \"" << typeid(u).name() << "\" in Tuple, which only supports SVG attributes.");
        }
        void _TupleImpl(AttrColor &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrCoordinate &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrAnything &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrInteger &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrListOfNumbers &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrURL &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrTransformList &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrPercentage &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrLength &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrIRI &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrPaint &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrName &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrAngle &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrOpacityValue &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrNumber &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrFuncIRI &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConst &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConst100 &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConst200 &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConst300 &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConst400 &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConst500 &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConst600 &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConst700 &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConst800 &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConst900 &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstAccumulate &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstAfterEdge &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstAll &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstAlphabetic &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstArcs &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstAuto &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstAutoStartReverse &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstBaseline &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstBeforeEdge &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstBevel &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstBlink &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstBold &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstBolder &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstBoundingBox &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstButt &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstCenter &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstCentral &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstCollapse &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstCrispEdges &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstCurrentcolor &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstDefault &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstEnd &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstEvenodd &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstFill &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstGeometricPrecision &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstHanging &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstHidden &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstIdeographic &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstInherit &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstItalic &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstLeft &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstLighter &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstLineThrough &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstLinearRGB &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstLr &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstLrTb &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstLtr &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstMathematical &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstMeet &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstMiddle &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstMiter &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstMiterClip &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstNew &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstNonScalingStroke &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstNone &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstNonezero &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstNonzero &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstNormal &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstObjectBoundingBox &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstOblique &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstOptimizeLegibility &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstOptimizeQuality &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstOptimizeSpeed &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstOverline &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstPad &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstPainted &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstPreserve &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstReflect &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstRepeat &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstRight &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstRl &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstRlTb &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstRound &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstRtl &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstSRGB &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstScroll &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstSlice &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstSpacing &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstSpacingAndGlyphs &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstSquare &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstStart &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstStroke &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstStrokeWidth &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstSub &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstSuper &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstTb &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstTbRl &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstTextAfterEdge &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstTextBeforeEdge &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstTextBottom &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstTextTop &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstUnderline &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstUserSpaceOnUse &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstVisible &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstVisibleFil &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstVisiblePainted &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstVisibleStroke &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstXMaxYMax &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstXMaxYMid &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstXMaxYMin &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstXMidYMax &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstXMidYMid &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstXMidYMin &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstXMinYMax &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstXMinYMid &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _TupleImpl(AttrConstXMinYMin &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }

        /**
        * Set getter of Integer this attribute.
        * @param getter getter function
        */
        void set_getter(std::function<const std::string()> getter) {
            _getter = getter;
        }
        /**
        * Set setter of Integer this attribute.
        *
        * @param setter setter function
        */
        void set_setter(std::function<void(const std::string &)> setter) {
            _setter = setter;
        }

        /**
        * Return attribute string, from getter.
        *
        * @return attribute string.
        */
        const std::string get() const {
            if (!_getter) return STR_NULL;
            return _getter();
        }
        /**
        * Return attribute string to be committed.
        *
        * @return attribute string.
        */
        const std::string get_commit() const {
            return _commit();   
        }
        /**
        * Commit binding or value by setter.
        */
        void commit() {
            if (!_setter) return;
            _setter(_commit());
        }

    // Array-like operations
    public:
        template<int i>
        decltype(std::get<i>(_tuple)) &at() {
            return std::get<i>(_tuple);
        }

    /// Callback
    public:
        /**
        * Set callback for assignment operation.
        *
        * @param on_assign callback function.
        */
        void callback_assign(std::function<void(const std::string &)> on_assign) { __callback_assign<0, Ts...>(on_assign); }
        /**
        * Remove callback for assignment operation.
        */
        void callback_assign() { __callback_assign<0, Ts...>([](const std::string &last){}); }
        template<std::size_t i, typename L>
        void __callback_assign(std::function<void(const std::string &)> on_assign) const {
            auto u = std::get<i>(_tuple);
            __callback_assign_impl(u, on_assign);
        }
        template<std::size_t i, typename F, typename S, typename ...R>
        void __callback_assign(std::function<void(const std::string &)> on_assign) const {
            auto u = std::get<i>(_tuple);
            __callback_assign_impl(u, on_assign);
            __callback_assign<i + 1, S, R...>(on_assign);
        }
        template<typename I>
        void __callback_assign_impl(I &u, std::function<void(const std::string &)> on_assign) const {
            _LZ_WARNING("Found unsupported ctype \"" << typeid(u).name() << "\" in Tuple, which only supports SVG attributes.");
        }
        void __callback_assign_impl(AttrColor &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrCoordinate &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrAnything &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrInteger &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrListOfNumbers &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrURL &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrTransformList &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrPercentage &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrLength &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrIRI &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrPaint &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrName &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrAngle &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrOpacityValue &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrNumber &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrFuncIRI &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConst &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConst100 &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConst200 &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConst300 &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConst400 &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConst500 &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConst600 &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConst700 &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConst800 &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConst900 &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstAccumulate &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstAfterEdge &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstAll &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstAlphabetic &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstArcs &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstAuto &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstAutoStartReverse &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstBaseline &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstBeforeEdge &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstBevel &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstBlink &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstBold &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstBolder &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstBoundingBox &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstButt &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstCenter &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstCentral &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstCollapse &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstCrispEdges &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstCurrentcolor &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstDefault &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstEnd &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstEvenodd &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstFill &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstGeometricPrecision &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstHanging &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstHidden &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstIdeographic &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstInherit &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstItalic &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstLeft &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstLighter &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstLineThrough &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstLinearRGB &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstLr &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstLrTb &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstLtr &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstMathematical &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstMeet &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstMiddle &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstMiter &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstMiterClip &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstNew &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstNonScalingStroke &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstNone &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstNonezero &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstNonzero &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstNormal &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstObjectBoundingBox &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstOblique &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstOptimizeLegibility &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstOptimizeQuality &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstOptimizeSpeed &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstOverline &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstPad &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstPainted &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstPreserve &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstReflect &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstRepeat &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstRight &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstRl &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstRlTb &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstRound &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstRtl &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstSRGB &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstScroll &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstSlice &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstSpacing &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstSpacingAndGlyphs &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstSquare &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstStart &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstStroke &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstStrokeWidth &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstSub &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstSuper &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstTb &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstTbRl &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstTextAfterEdge &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstTextBeforeEdge &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstTextBottom &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstTextTop &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstUnderline &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstUserSpaceOnUse &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstVisible &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstVisibleFil &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstVisiblePainted &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstVisibleStroke &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstXMaxYMax &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstXMaxYMid &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstXMaxYMin &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstXMidYMax &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstXMidYMid &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstXMidYMin &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstXMinYMax &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstXMinYMid &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        void __callback_assign_impl(AttrConstXMinYMin &u, std::function<void(const std::string &)> on_assign) const {
            u.callback_assign(on_assign);
        }
        /**
        * Set callback for binding function operation.
        *
        * @param on_bind_func callback function.
        */
        void callback_bind_func(std::function<void()> on_bind_func) { __callback_bind_func<0, Ts...>(on_bind_func); }
        /**
        * Remove callback for binding function operation.
        */
        void callback_bind_func() { __callback_bind_func<0, Ts...>([](){}); }
        template<std::size_t i, typename L>
        void __callback_bind_func(std::function<void()> on_bind_func) const {
            auto u = std::get<i>(_tuple);
            __callback_bind_func_impl(u, on_bind_func);
        }
        template<std::size_t i, typename F, typename S, typename ...R>
        void __callback_bind_func(std::function<void()> on_bind_func) const {
            auto u = std::get<i>(_tuple);
            __callback_bind_func_impl(u, on_bind_func);
            __callback_bind_func<i + 1, S, R...>(on_bind_func);
        }
        template<typename I>
        void __callback_bind_func_impl(I &u, std::function<void()> on_bind_func) const {
            _LZ_WARNING("Found unsupported ctype \"" << typeid(u).name() << "\" in Tuple, which only supports SVG attributes.");
        }
        void __callback_bind_func_impl(AttrColor &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrCoordinate &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrAnything &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrInteger &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrListOfNumbers &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrURL &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrTransformList &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrPercentage &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrLength &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrIRI &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrPaint &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrName &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrAngle &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrOpacityValue &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrNumber &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrFuncIRI &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConst &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConst100 &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConst200 &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConst300 &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConst400 &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConst500 &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConst600 &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConst700 &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConst800 &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConst900 &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstAccumulate &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstAfterEdge &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstAll &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstAlphabetic &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstArcs &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstAuto &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstAutoStartReverse &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstBaseline &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstBeforeEdge &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstBevel &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstBlink &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstBold &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstBolder &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstBoundingBox &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstButt &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstCenter &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstCentral &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstCollapse &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstCrispEdges &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstCurrentcolor &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstDefault &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstEnd &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstEvenodd &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstFill &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstGeometricPrecision &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstHanging &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstHidden &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstIdeographic &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstInherit &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstItalic &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstLeft &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstLighter &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstLineThrough &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstLinearRGB &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstLr &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstLrTb &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstLtr &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstMathematical &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstMeet &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstMiddle &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstMiter &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstMiterClip &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstNew &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstNonScalingStroke &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstNone &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstNonezero &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstNonzero &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstNormal &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstObjectBoundingBox &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstOblique &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstOptimizeLegibility &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstOptimizeQuality &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstOptimizeSpeed &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstOverline &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstPad &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstPainted &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstPreserve &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstReflect &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstRepeat &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstRight &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstRl &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstRlTb &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstRound &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstRtl &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstSRGB &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstScroll &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstSlice &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstSpacing &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstSpacingAndGlyphs &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstSquare &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstStart &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstStroke &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstStrokeWidth &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstSub &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstSuper &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstTb &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstTbRl &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstTextAfterEdge &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstTextBeforeEdge &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstTextBottom &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstTextTop &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstUnderline &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstUserSpaceOnUse &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstVisible &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstVisibleFil &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstVisiblePainted &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstVisibleStroke &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstXMaxYMax &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstXMaxYMid &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstXMaxYMin &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstXMidYMax &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstXMidYMid &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstXMidYMin &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstXMinYMax &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstXMinYMid &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        void __callback_bind_func_impl(AttrConstXMinYMin &u, std::function<void()> on_bind_func) const {
            u.callback_bind_func(on_bind_func);
        }
        /**
        * Set callback for binding pointer operation.
        *
        * @param on_bind_ptr callback function.
        */
        void callback_bind_ptr(std::function<void()> on_bind_ptr) { __callback_bind_ptr<0, Ts...>(on_bind_ptr); }
        /**
        * Remove callback for binding pointer operation.
        */
        void callback_bind_ptr() { __callback_bind_ptr<0, Ts...>([](){}); }
        template<std::size_t i, typename L>
        void __callback_bind_ptr(std::function<void()> on_bind_ptr) const {
            auto u = std::get<i>(_tuple);
            __callback_bind_ptr_impl(u, on_bind_ptr);
        }
        template<std::size_t i, typename F, typename S, typename ...R>
        void __callback_bind_ptr(std::function<void()> on_bind_ptr) const {
            auto u = std::get<i>(_tuple);
            __callback_bind_ptr_impl(u, on_bind_ptr);
            __callback_bind_ptr<i + 1, S, R...>(on_bind_ptr);
        }
        template<typename I>
        void __callback_bind_ptr_impl(I &u, std::function<void()> on_bind_ptr) const {
            _LZ_WARNING("Found unsupported ctype \"" << typeid(u).name() << "\" in Tuple, which only supports SVG attributes.");
        }
        void __callback_bind_ptr_impl(AttrColor &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrCoordinate &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrAnything &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrInteger &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrListOfNumbers &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrURL &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrTransformList &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrPercentage &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrLength &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrIRI &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrPaint &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrName &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrAngle &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrOpacityValue &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrNumber &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrFuncIRI &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConst &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConst100 &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConst200 &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConst300 &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConst400 &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConst500 &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConst600 &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConst700 &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConst800 &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConst900 &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstAccumulate &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstAfterEdge &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstAll &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstAlphabetic &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstArcs &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstAuto &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstAutoStartReverse &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstBaseline &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstBeforeEdge &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstBevel &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstBlink &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstBold &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstBolder &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstBoundingBox &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstButt &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstCenter &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstCentral &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstCollapse &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstCrispEdges &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstCurrentcolor &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstDefault &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstEnd &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstEvenodd &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstFill &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstGeometricPrecision &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstHanging &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstHidden &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstIdeographic &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstInherit &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstItalic &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstLeft &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstLighter &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstLineThrough &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstLinearRGB &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstLr &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstLrTb &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstLtr &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstMathematical &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstMeet &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstMiddle &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstMiter &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstMiterClip &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstNew &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstNonScalingStroke &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstNone &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstNonezero &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstNonzero &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstNormal &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstObjectBoundingBox &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstOblique &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstOptimizeLegibility &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstOptimizeQuality &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstOptimizeSpeed &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstOverline &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstPad &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstPainted &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstPreserve &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstReflect &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstRepeat &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstRight &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstRl &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstRlTb &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstRound &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstRtl &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstSRGB &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstScroll &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstSlice &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstSpacing &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstSpacingAndGlyphs &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstSquare &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstStart &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstStroke &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstStrokeWidth &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstSub &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstSuper &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstTb &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstTbRl &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstTextAfterEdge &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstTextBeforeEdge &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstTextBottom &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstTextTop &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstUnderline &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstUserSpaceOnUse &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstVisible &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstVisibleFil &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstVisiblePainted &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstVisibleStroke &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstXMaxYMax &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstXMaxYMid &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstXMaxYMin &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstXMidYMax &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstXMidYMid &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstXMidYMin &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstXMinYMax &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstXMinYMid &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
        void __callback_bind_ptr_impl(AttrConstXMinYMin &u, std::function<void()> on_bind_ptr) const {
            u.callback_bind_ptr(on_bind_ptr);
        }
    };
}
#endif
