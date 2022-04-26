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
            auto u = std::get<i>(_tuple);
            _EnumerateImpl(u, getter, setter);
        }
        template<std::size_t i, typename F, typename S, typename ...R>
        void _Enumerate(std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            auto u = std::get<i>(_tuple);
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
