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
    };
}
#endif
