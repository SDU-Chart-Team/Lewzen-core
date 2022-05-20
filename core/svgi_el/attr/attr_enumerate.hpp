#ifndef __LZ_ATTR_ENUMERATE__
#define __LZ_ATTR_ENUMERATE__
#ifdef debug
#undef debug
#define __debug
#endif
#include <tuple>
#include "../attr.hpp"

namespace Lewzen {
    template<typename... Ts>
    class AttrEnumerate {
    private:
        std::tuple<Ts...> _tuple;
        std::string _attr;
    private:
        const std::string _commit() const {
            return __commit<0, Ts...>();
        }
        template<std::size_t i, typename L>
        const std::string __commit() const {
            auto u = std::get<i>(_tuple);
            return __commit_impl(u);
        }
        template<std::size_t i, typename F, typename S, typename ...R>
        const std::string __commit() const {
            auto u = std::get<i>(_tuple);
            auto &s = __commit_impl(u);
            if (s != STR_NULL) return s;
            return __commit<i + 1, S, R...>();
        }
        template<typename I>
        const std::string __commit_impl(I &u) const {
            #ifdef __debug
            std::cout  << "Warning: " << "Found unsupported ctype \"" << typeid(u).name() << "\" in Enumerate, which only supports SVG attributes."<< std::endl;
            #endif
            return STR_NULL;
        }
        const std::string __commit_impl(AttrColor &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrCoordinate &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrAnything &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrInteger &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrListOfNumbers &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrURL &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrTransformList &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrPercentage &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrLength &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrIRI &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrPaint &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrName &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrAngle &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrOpacityValue &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrNumber &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrFuncIRI &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConst &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConst100 &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConst200 &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConst300 &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConst400 &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConst500 &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConst600 &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConst700 &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConst800 &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConst900 &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstAccumulate &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstAfterEdge &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstAll &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstAlphabetic &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstArcs &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstAuto &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstAutoStartReverse &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstBaseline &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstBeforeEdge &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstBevel &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstBlink &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstBold &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstBolder &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstBoundingBox &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstButt &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstCenter &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstCentral &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstCollapse &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstCrispEdges &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstCurrentcolor &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstDefault &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstEnd &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstEvenodd &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstFill &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstGeometricPrecision &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstHanging &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstHidden &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstIdeographic &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstInherit &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstItalic &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstLeft &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstLighter &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstLineThrough &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstLinearRGB &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstLr &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstLrTb &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstLtr &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstMathematical &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstMeet &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstMiddle &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstMiter &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstMiterClip &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstNew &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstNonScalingStroke &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstNone &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstNonezero &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstNonzero &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstNormal &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstObjectBoundingBox &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstOblique &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstOptimizeLegibility &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstOptimizeQuality &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstOptimizeSpeed &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstOverline &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstPad &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstPainted &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstPreserve &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstReflect &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstRepeat &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstRight &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstRl &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstRlTb &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstRound &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstRtl &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstSRGB &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstScroll &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstSlice &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstSpacing &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstSpacingAndGlyphs &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstSquare &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstStart &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstStroke &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstStrokeWidth &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstSub &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstSuper &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstTb &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstTbRl &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstTextAfterEdge &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstTextBeforeEdge &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstTextBottom &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstTextTop &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstUnderline &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstUserSpaceOnUse &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstVisible &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstVisibleFil &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstVisiblePainted &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstVisibleStroke &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstXMaxYMax &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstXMaxYMid &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstXMaxYMin &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstXMidYMax &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstXMidYMid &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstXMidYMin &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstXMinYMax &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstXMinYMid &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(AttrConstXMinYMin &u) const {
            return u.get_commit();
        }
        std::function<const std::string()> _getter;
        std::function<void(const std::string &)> _setter;
    public:
        /**
        * Empty Constructor of Enumerate.
        */
        AttrEnumerate() {}

        /**
        * Constructor of Enumerate
        */
        AttrEnumerate(std::function<const std::string()> getter, std::function<void(const std::string &)> setter): _getter(getter), _setter(setter) {
            _Enumerate<0, Ts...>(_getter, _setter);
        }
        template<std::size_t i, typename L>
        void _Enumerate(std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            auto &u = std::get<i>(_tuple);
            _EnumerateImpl(u, getter, setter);
        }
        template<std::size_t i, typename F, typename S, typename ...R>
        void _Enumerate(std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            auto &u = std::get<i>(_tuple);
            _EnumerateImpl(u, getter, setter);
            _Enumerate<i + 1, S, R...>(getter, setter);
        }
        template<typename I>
        void _EnumerateImpl(I &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            #ifdef __debug
            std::cout  << "Warning: " << "Found unsupported ctype \"" << typeid(u).name() << "\" in Enumerate, which only supports SVG attributes."<< std::endl;
            #endif
        }
        void _EnumerateImpl(AttrColor &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrCoordinate &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrAnything &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrInteger &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrListOfNumbers &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrURL &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrTransformList &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrPercentage &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrLength &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrIRI &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrPaint &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrName &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrAngle &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrOpacityValue &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrNumber &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrFuncIRI &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConst &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConst100 &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConst200 &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConst300 &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConst400 &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConst500 &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConst600 &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConst700 &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConst800 &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConst900 &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstAccumulate &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstAfterEdge &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstAll &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstAlphabetic &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstArcs &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstAuto &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstAutoStartReverse &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstBaseline &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstBeforeEdge &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstBevel &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstBlink &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstBold &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstBolder &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstBoundingBox &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstButt &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstCenter &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstCentral &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstCollapse &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstCrispEdges &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstCurrentcolor &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstDefault &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstEnd &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstEvenodd &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstFill &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstGeometricPrecision &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstHanging &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstHidden &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstIdeographic &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstInherit &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstItalic &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstLeft &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstLighter &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstLineThrough &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstLinearRGB &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstLr &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstLrTb &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstLtr &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstMathematical &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstMeet &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstMiddle &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstMiter &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstMiterClip &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstNew &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstNonScalingStroke &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstNone &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstNonezero &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstNonzero &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstNormal &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstObjectBoundingBox &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstOblique &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstOptimizeLegibility &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstOptimizeQuality &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstOptimizeSpeed &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstOverline &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstPad &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstPainted &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstPreserve &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstReflect &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstRepeat &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstRight &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstRl &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstRlTb &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstRound &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstRtl &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstSRGB &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstScroll &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstSlice &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstSpacing &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstSpacingAndGlyphs &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstSquare &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstStart &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstStroke &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstStrokeWidth &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstSub &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstSuper &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstTb &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstTbRl &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstTextAfterEdge &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstTextBeforeEdge &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstTextBottom &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstTextTop &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstUnderline &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstUserSpaceOnUse &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstVisible &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstVisibleFil &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstVisiblePainted &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstVisibleStroke &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstXMaxYMax &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstXMaxYMid &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstXMaxYMin &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstXMidYMax &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstXMidYMid &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstXMidYMin &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstXMinYMax &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstXMinYMid &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(AttrConstXMinYMin &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }

        /**
        * Set getter of Integer this attribute.
        * @param getter getter function
        */
        void set_getter(std::function<const std::string()> getter) {
            _getter = getter;
            _Enumerate<0, Ts...>(getter, _setter);
        }
        /**
        * Set setter of Integer this attribute.
        *
        * @param setter setter function
        */
        void set_setter(std::function<void(const std::string &)> setter) {
            _setter = setter;
            _Enumerate<0, Ts...>(_getter, setter);
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

    // Set
    public:
        /**
        * Set attribute from value, conver to string. This will break value binding with bind_func and bind_ptr. (This function will reset commit)
        *
        * @param attr attribute.
        */
        template <typename T>
        void set(const T &attr) {
            auto _last = get_commit();
            _set<T, 0, Ts...>(attr);
            _on_assign(_last);
        }
        template<typename T, std::size_t i, typename L>
        void _set(const T &attr) {
            auto &u = std::get<i>(_tuple);
            _set_impl(attr, u);
        }
        template<typename T, std::size_t i, typename F, typename S, typename ...R>
        void _set(const T &attr) {
            auto &u = std::get<i>(_tuple);
            _set_impl(attr, u);
            _set<T, i + 1, S, R...>(attr);
        }
        template<typename T, typename I>
        void _set_impl(const T &attr, const I &u) {
            #ifdef __debug
            std::cout  << "Warning: " << "Found unsupported ctype \"" << typeid(u).name() << "\" in Enumerate, which only supports SVG attributes."<< std::endl;
            #endif
        }
        template<typename T>
        void _set_impl(const T &attr, AttrColor &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrCoordinate &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrAnything &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrInteger &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrListOfNumbers &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrURL &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrTransformList &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrPercentage &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrLength &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrIRI &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrPaint &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrName &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrAngle &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrOpacityValue &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrNumber &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrFuncIRI &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConst &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConst100 &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConst200 &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConst300 &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConst400 &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConst500 &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConst600 &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConst700 &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConst800 &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConst900 &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstAccumulate &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstAfterEdge &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstAll &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstAlphabetic &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstArcs &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstAuto &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstAutoStartReverse &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstBaseline &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstBeforeEdge &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstBevel &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstBlink &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstBold &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstBolder &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstBoundingBox &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstButt &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstCenter &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstCentral &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstCollapse &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstCrispEdges &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstCurrentcolor &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstDefault &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstEnd &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstEvenodd &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstFill &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstGeometricPrecision &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstHanging &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstHidden &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstIdeographic &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstInherit &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstItalic &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstLeft &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstLighter &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstLineThrough &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstLinearRGB &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstLr &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstLrTb &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstLtr &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstMathematical &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstMeet &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstMiddle &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstMiter &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstMiterClip &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstNew &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstNonScalingStroke &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstNone &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstNonezero &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstNonzero &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstNormal &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstObjectBoundingBox &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstOblique &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstOptimizeLegibility &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstOptimizeQuality &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstOptimizeSpeed &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstOverline &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstPad &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstPainted &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstPreserve &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstReflect &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstRepeat &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstRight &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstRl &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstRlTb &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstRound &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstRtl &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstSRGB &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstScroll &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstSlice &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstSpacing &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstSpacingAndGlyphs &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstSquare &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstStart &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstStroke &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstStrokeWidth &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstSub &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstSuper &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstTb &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstTbRl &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstTextAfterEdge &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstTextBeforeEdge &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstTextBottom &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstTextTop &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstUnderline &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstUserSpaceOnUse &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstVisible &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstVisibleFil &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstVisiblePainted &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstVisibleStroke &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstXMaxYMax &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstXMaxYMid &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstXMaxYMin &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstXMidYMax &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstXMidYMid &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstXMidYMin &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstXMinYMax &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstXMinYMid &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, AttrConstXMinYMin &u) {
            u.set(attr);
        }
    
    // Operator1
    public:
        /**
        * Set attribute from value, conver to string.  This will break value binding with bind_func and bind_ptr. (This function will reset commit)
        *
        * @param attr attribute.
        */
        template <typename T>
        AttrEnumerate<Ts...> &operator=(const T &attr) {
            auto _last = get_commit();
            _op1<T, 0, Ts...>(attr);
            _on_assign(_last);
            return *this;
        }
        template<typename T, std::size_t i, typename L>
        void _op1(const T &attr) {
            auto &u = std::get<i>(_tuple);
            _op1_impl(attr, u);
        }
        template<typename T, std::size_t i, typename F, typename S, typename ...R>
        void _op1(const T &attr) {
            auto &u = std::get<i>(_tuple);
            _op1_impl(attr, u);
            _op1<T, i + 1, S, R...>(attr);
        }
        template<typename T, typename I>
        void _op1_impl(const T &attr, const I &u) {
            #ifdef __debug
            std::cout  << "Warning: " << "Found unsupported ctype \"" << typeid(u).name() << "\" in Enumerate, which only supports SVG attributes."<< std::endl;
            #endif
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrColor &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrCoordinate &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrAnything &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrInteger &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrListOfNumbers &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrURL &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrTransformList &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrPercentage &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrLength &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrIRI &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrPaint &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrName &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrAngle &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrOpacityValue &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrNumber &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrFuncIRI &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConst &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConst100 &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConst200 &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConst300 &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConst400 &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConst500 &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConst600 &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConst700 &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConst800 &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConst900 &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstAccumulate &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstAfterEdge &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstAll &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstAlphabetic &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstArcs &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstAuto &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstAutoStartReverse &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstBaseline &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstBeforeEdge &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstBevel &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstBlink &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstBold &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstBolder &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstBoundingBox &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstButt &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstCenter &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstCentral &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstCollapse &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstCrispEdges &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstCurrentcolor &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstDefault &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstEnd &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstEvenodd &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstFill &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstGeometricPrecision &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstHanging &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstHidden &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstIdeographic &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstInherit &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstItalic &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstLeft &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstLighter &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstLineThrough &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstLinearRGB &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstLr &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstLrTb &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstLtr &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstMathematical &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstMeet &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstMiddle &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstMiter &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstMiterClip &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstNew &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstNonScalingStroke &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstNone &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstNonezero &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstNonzero &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstNormal &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstObjectBoundingBox &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstOblique &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstOptimizeLegibility &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstOptimizeQuality &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstOptimizeSpeed &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstOverline &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstPad &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstPainted &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstPreserve &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstReflect &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstRepeat &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstRight &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstRl &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstRlTb &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstRound &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstRtl &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstSRGB &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstScroll &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstSlice &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstSpacing &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstSpacingAndGlyphs &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstSquare &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstStart &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstStroke &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstStrokeWidth &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstSub &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstSuper &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstTb &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstTbRl &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstTextAfterEdge &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstTextBeforeEdge &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstTextBottom &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstTextTop &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstUnderline &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstUserSpaceOnUse &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstVisible &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstVisibleFil &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstVisiblePainted &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstVisibleStroke &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstXMaxYMax &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstXMaxYMid &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstXMaxYMin &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstXMidYMax &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstXMidYMid &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstXMidYMin &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstXMinYMax &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstXMinYMid &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, AttrConstXMinYMin &u) {
            u = attr;
        }

    // Bind function
    public:
        /**
        * Bind attribute to a function. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_func binding function.
        */
        template <typename T>
        void bind(std::function<const T()>bind_func) {
            _bind1<T, 0, Ts...>(bind_func);
            _on_bind_func();
        }
        template <typename T>
        void bind(const T(*bind_func)()) {
            std::function<const T()> _bind_func = bind_func;
            bind(_bind_func);
        }
        template <typename T>
        void __bind(std::function<T()>bind_func) {
            _bind1<T, 0, Ts...>(bind_func);
        }
        template <typename T>
        void bind(T bind_func) {
            auto p = lambda_to_function(bind_func);
            __bind(p);
            _on_bind_func();
        }
        template<typename T, std::size_t i, typename L>
        void _bind1(std::function<const T()>bind_func) {
            auto &u = std::get<i>(_tuple);
            _bind1_impl(bind_func, u);
        }
        template<typename T, std::size_t i, typename F, typename S, typename ...R>
        void _bind1(std::function<const T()>bind_func) {
            auto &u = std::get<i>(_tuple);
            _bind1_impl(bind_func, u);
            _bind1<T, i + 1, S, R...>(bind_func);
        }
        template<typename T, typename I>
        void _bind1_impl(std::function<const T()>bind_func, const I &u) {
            #ifdef __debug
            std::cout  << "Warning: " << "Found unsupported ctype \"" << typeid(u).name() << "\" in Enumerate, which only supports SVG attributes."<< std::endl;
            #endif
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrColor &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrCoordinate &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrAnything &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrInteger &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrListOfNumbers &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrURL &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrTransformList &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrPercentage &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrLength &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrIRI &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrPaint &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrName &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrAngle &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrOpacityValue &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrNumber &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrFuncIRI &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConst &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConst100 &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConst200 &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConst300 &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConst400 &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConst500 &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConst600 &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConst700 &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConst800 &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConst900 &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstAccumulate &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstAfterEdge &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstAll &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstAlphabetic &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstArcs &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstAuto &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstAutoStartReverse &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstBaseline &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstBeforeEdge &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstBevel &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstBlink &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstBold &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstBolder &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstBoundingBox &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstButt &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstCenter &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstCentral &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstCollapse &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstCrispEdges &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstCurrentcolor &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstDefault &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstEnd &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstEvenodd &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstFill &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstGeometricPrecision &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstHanging &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstHidden &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstIdeographic &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstInherit &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstItalic &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstLeft &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstLighter &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstLineThrough &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstLinearRGB &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstLr &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstLrTb &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstLtr &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstMathematical &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstMeet &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstMiddle &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstMiter &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstMiterClip &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstNew &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstNonScalingStroke &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstNone &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstNonezero &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstNonzero &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstNormal &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstObjectBoundingBox &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstOblique &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstOptimizeLegibility &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstOptimizeQuality &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstOptimizeSpeed &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstOverline &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstPad &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstPainted &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstPreserve &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstReflect &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstRepeat &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstRight &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstRl &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstRlTb &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstRound &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstRtl &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstSRGB &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstScroll &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstSlice &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstSpacing &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstSpacingAndGlyphs &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstSquare &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstStart &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstStroke &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstStrokeWidth &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstSub &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstSuper &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstTb &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstTbRl &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstTextAfterEdge &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstTextBeforeEdge &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstTextBottom &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstTextTop &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstUnderline &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstUserSpaceOnUse &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstVisible &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstVisibleFil &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstVisiblePainted &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstVisibleStroke &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstXMaxYMax &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstXMaxYMid &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstXMaxYMin &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstXMidYMax &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstXMidYMid &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstXMidYMin &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstXMinYMax &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstXMinYMid &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, AttrConstXMinYMin &u) {
            u.bind(bind_func);
        }

    // Operator2
    public:
        /**
        * Bind attribute to a function. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_func binding function.
        */
        template <typename T>
        AttrEnumerate<Ts...> &operator[](std::function<const T()>bind_func) {
            _op2<T, 0, Ts...>(bind_func);
            _on_bind_func();
            return *this;
        }
        template <typename T>
        AttrEnumerate<Ts...> &operator[](const T(*bind_func)()) {
            std::function<const T()> _bind_func = bind_func;
            operator[](_bind_func);
        }
        template <typename T>
        void __op2(std::function<T()>bind_func) {
            _op2<T, 0, Ts...>(bind_func);
        }
        template <typename T>
        AttrEnumerate<Ts...> &operator[](T bind_func) {
            auto p = lambda_to_function(bind_func);
            __op2(p);
            _on_bind_func();
        }
        template<typename T, std::size_t i, typename L>
        void _op2(std::function<const T()>bind_func) {
            auto &u = std::get<i>(_tuple);
            _op2_impl(bind_func, u);
        }
        template<typename T, std::size_t i, typename F, typename S, typename ...R>
        void _op2(std::function<const T()>bind_func) {
            auto &u = std::get<i>(_tuple);
            _op2_impl(bind_func, u);
            _op2<T, i + 1, S, R...>(bind_func);
        }
        template<typename T, typename I>
        void _op2_impl(std::function<const T()>bind_func, const I &u) {
            #ifdef __debug
            std::cout  << "Warning: " << "Found unsupported ctype \"" << typeid(u).name() << "\" in Enumerate, which only supports SVG attributes."<< std::endl;
            #endif
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrColor &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrCoordinate &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrAnything &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrInteger &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrListOfNumbers &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrURL &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrTransformList &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrPercentage &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrLength &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrIRI &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrPaint &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrName &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrAngle &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrOpacityValue &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrNumber &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrFuncIRI &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConst &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConst100 &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConst200 &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConst300 &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConst400 &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConst500 &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConst600 &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConst700 &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConst800 &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConst900 &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstAccumulate &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstAfterEdge &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstAll &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstAlphabetic &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstArcs &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstAuto &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstAutoStartReverse &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstBaseline &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstBeforeEdge &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstBevel &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstBlink &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstBold &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstBolder &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstBoundingBox &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstButt &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstCenter &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstCentral &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstCollapse &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstCrispEdges &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstCurrentcolor &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstDefault &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstEnd &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstEvenodd &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstFill &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstGeometricPrecision &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstHanging &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstHidden &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstIdeographic &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstInherit &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstItalic &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstLeft &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstLighter &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstLineThrough &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstLinearRGB &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstLr &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstLrTb &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstLtr &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstMathematical &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstMeet &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstMiddle &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstMiter &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstMiterClip &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstNew &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstNonScalingStroke &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstNone &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstNonezero &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstNonzero &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstNormal &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstObjectBoundingBox &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstOblique &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstOptimizeLegibility &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstOptimizeQuality &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstOptimizeSpeed &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstOverline &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstPad &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstPainted &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstPreserve &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstReflect &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstRepeat &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstRight &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstRl &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstRlTb &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstRound &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstRtl &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstSRGB &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstScroll &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstSlice &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstSpacing &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstSpacingAndGlyphs &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstSquare &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstStart &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstStroke &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstStrokeWidth &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstSub &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstSuper &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstTb &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstTbRl &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstTextAfterEdge &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstTextBeforeEdge &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstTextBottom &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstTextTop &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstUnderline &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstUserSpaceOnUse &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstVisible &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstVisibleFil &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstVisiblePainted &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstVisibleStroke &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstXMaxYMax &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstXMaxYMid &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstXMaxYMin &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstXMidYMax &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstXMidYMid &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstXMidYMin &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstXMinYMax &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstXMinYMid &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, AttrConstXMinYMin &u) {
            u[bind_func];
        }

    // Bind pointer
    public:
        /**
        * Bind attribute to a pointer. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_ptr binding pointer.
        */
        template <typename T>
        void bind(const std::weak_ptr<T> &bind_ptr) {
            _bind2<T, 0, Ts...>(bind_ptr);
            _on_bind_ptr();
        }
        template<typename T, std::size_t i, typename L>
        void _bind2(const std::weak_ptr<T> &bind_ptr) {
            auto &u = std::get<i>(_tuple);
            _bind2_impl(bind_ptr, u);
        }
        template<typename T, std::size_t i, typename F, typename S, typename ...R>
        void _bind2(const std::weak_ptr<T> &bind_ptr) {
            auto &u = std::get<i>(_tuple);
            _bind2_impl(bind_ptr, u);
            _bind2<T, i + 1, S, R...>(bind_ptr);
        }
        template<typename T, typename I>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, const I &u) {
            #ifdef __debug
            std::cout  << "Warning: " << "Found unsupported ctype \"" << typeid(u).name() << "\" in Enumerate, which only supports SVG attributes."<< std::endl;
            #endif
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrColor &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrCoordinate &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrAnything &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrInteger &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrListOfNumbers &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrURL &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrTransformList &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrPercentage &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrLength &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrIRI &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrPaint &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrName &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrAngle &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrOpacityValue &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrNumber &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrFuncIRI &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConst &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConst100 &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConst200 &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConst300 &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConst400 &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConst500 &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConst600 &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConst700 &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConst800 &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConst900 &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstAccumulate &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstAfterEdge &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstAll &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstAlphabetic &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstArcs &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstAuto &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstAutoStartReverse &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstBaseline &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstBeforeEdge &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstBevel &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstBlink &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstBold &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstBolder &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstBoundingBox &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstButt &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstCenter &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstCentral &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstCollapse &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstCrispEdges &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstCurrentcolor &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstDefault &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstEnd &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstEvenodd &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstFill &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstGeometricPrecision &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstHanging &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstHidden &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstIdeographic &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstInherit &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstItalic &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstLeft &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstLighter &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstLineThrough &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstLinearRGB &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstLr &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstLrTb &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstLtr &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstMathematical &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstMeet &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstMiddle &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstMiter &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstMiterClip &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstNew &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstNonScalingStroke &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstNone &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstNonezero &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstNonzero &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstNormal &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstObjectBoundingBox &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstOblique &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstOptimizeLegibility &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstOptimizeQuality &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstOptimizeSpeed &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstOverline &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstPad &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstPainted &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstPreserve &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstReflect &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstRepeat &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstRight &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstRl &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstRlTb &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstRound &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstRtl &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstSRGB &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstScroll &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstSlice &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstSpacing &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstSpacingAndGlyphs &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstSquare &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstStart &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstStroke &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstStrokeWidth &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstSub &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstSuper &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstTb &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstTbRl &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstTextAfterEdge &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstTextBeforeEdge &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstTextBottom &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstTextTop &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstUnderline &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstUserSpaceOnUse &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstVisible &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstVisibleFil &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstVisiblePainted &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstVisibleStroke &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstXMaxYMax &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstXMaxYMid &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstXMaxYMin &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstXMidYMax &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstXMidYMid &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstXMidYMin &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstXMinYMax &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstXMinYMid &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, AttrConstXMinYMin &u) {
            u.bind(bind_ptr);
        }

    // Operator3
    public:
        /**
        * Bind attribute to a pointer. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_ptr binding pointer.
        */
        template <typename T>
        AttrEnumerate<Ts...> &operator[](const std::weak_ptr<T> &bind_ptr) {
            _op3<T, 0, Ts...>(bind_ptr);
            _on_bind_ptr();
            return *this;
        }
        template<typename T, std::size_t i, typename L>
        void _op3(const std::weak_ptr<T> &bind_ptr) {
            auto &u = std::get<i>(_tuple);
            _op3_impl(bind_ptr, u);
        }
        template<typename T, std::size_t i, typename F, typename S, typename ...R>
        void _op3(const std::weak_ptr<T> &bind_ptr) {
            auto &u = std::get<i>(_tuple);
            _op3_impl(bind_ptr, u);
            _op3<T, i + 1, S, R...>(bind_ptr);
        }
        template<typename T, typename I>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, const I &u) {
            #ifdef __debug
            std::cout  << "Warning: " << "Found unsupported ctype \"" << typeid(u).name() << "\" in Enumerate, which only supports SVG attributes."<< std::endl;
            #endif
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrColor &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrCoordinate &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrAnything &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrInteger &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrListOfNumbers &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrURL &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrTransformList &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrPercentage &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrLength &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrIRI &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrPaint &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrName &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrAngle &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrOpacityValue &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrNumber &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrFuncIRI &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConst &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConst100 &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConst200 &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConst300 &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConst400 &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConst500 &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConst600 &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConst700 &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConst800 &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConst900 &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstAccumulate &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstAfterEdge &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstAll &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstAlphabetic &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstArcs &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstAuto &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstAutoStartReverse &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstBaseline &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstBeforeEdge &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstBevel &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstBlink &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstBold &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstBolder &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstBoundingBox &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstButt &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstCenter &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstCentral &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstCollapse &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstCrispEdges &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstCurrentcolor &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstDefault &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstEnd &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstEvenodd &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstFill &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstGeometricPrecision &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstHanging &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstHidden &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstIdeographic &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstInherit &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstItalic &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstLeft &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstLighter &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstLineThrough &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstLinearRGB &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstLr &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstLrTb &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstLtr &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstMathematical &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstMeet &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstMiddle &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstMiter &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstMiterClip &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstNew &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstNonScalingStroke &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstNone &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstNonezero &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstNonzero &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstNormal &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstObjectBoundingBox &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstOblique &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstOptimizeLegibility &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstOptimizeQuality &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstOptimizeSpeed &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstOverline &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstPad &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstPainted &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstPreserve &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstReflect &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstRepeat &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstRight &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstRl &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstRlTb &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstRound &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstRtl &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstSRGB &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstScroll &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstSlice &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstSpacing &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstSpacingAndGlyphs &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstSquare &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstStart &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstStroke &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstStrokeWidth &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstSub &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstSuper &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstTb &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstTbRl &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstTextAfterEdge &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstTextBeforeEdge &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstTextBottom &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstTextTop &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstUnderline &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstUserSpaceOnUse &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstVisible &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstVisibleFil &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstVisiblePainted &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstVisibleStroke &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstXMaxYMax &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstXMaxYMid &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstXMaxYMin &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstXMidYMax &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstXMidYMid &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstXMidYMin &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstXMinYMax &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstXMinYMid &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, AttrConstXMinYMin &u) {
            u[bind_ptr];
        }

    /// Callback
    private:
        std::function<void(const std::string &)> _on_assign = [](const std::string &last){};
        std::function<void()> _on_bind_func = [](){};
        std::function<void()> _on_bind_ptr = [](){};
    public:
        /**
        * Set callback for assignment operation.
        *
        * @param on_assign callback function.
        */
        void callback_assign(std::function<void(const std::string &)> on_assign) { _on_assign = on_assign; }
        /**
        * Remove callback for assignment operation.
        */
        void callback_assign() { _on_assign = [](const std::string &last){}; }
        /**
        * Set callback for binding function operation.
        *
        * @param on_bind_func callback function.
        */
        void callback_bind_func(std::function<void()> on_bind_func) { _on_bind_func = on_bind_func; }
        /**
        * Remove callback for binding function operation.
        */
        void callback_bind_func() { _on_bind_func = [](){}; }
        /**
        * Set callback for binding pointer operation.
        *
        * @param on_bind_ptr callback function.
        */
        void callback_bind_ptr(std::function<void()> on_bind_ptr) { _on_bind_ptr = on_bind_ptr; }
        /**
        * Remove callback for binding pointer operation.
        */
        void callback_bind_ptr() { _on_bind_ptr = [](){}; }
    };
}
#ifdef __debug
#undef __debug
#define debug
#endif
#endif
