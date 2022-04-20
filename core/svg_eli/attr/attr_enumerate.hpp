#ifndef __LZ_ATTR_ENUMERATE__
#define __LZ_ATTR_ENUMERATE__
#ifdef debug
#undef debug
#define __debug
#endif
#include <tuple>
#include "../attr.h"

namespace Lewzen {
    template<typename... Ts>
    class Enumerate {
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
            _LZ_WARNING("Found unsupported ctype \"" << typeid(u).name() << "\" in Enumerate, which only supports SVG attributes.");
            return STR_NULL;
        }
        const std::string __commit_impl(Percentage &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(Length &u) const {
            return u.get_commit();
        }
        const std::string __commit_impl(Number &u) const {
            return u.get_commit();
        }
        std::function<const std::string()> _getter;
        std::function<void(const std::string &)> _setter;
    public:
        /**
        * Empty Constructor of Enumerate.
        */
        Enumerate() {}

        /**
        * Constructor of Enumerate
        */
        Enumerate(std::function<const std::string()> getter, std::function<void(const std::string &)> setter): _getter(getter), _setter(setter) {
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
            #define debug
            _LZ_WARNING("Found unsupported ctype \"" << typeid(u).name() << "\" in Enumerate, which only supports SVG attributes.");
            #undef debug
            #endif
        }
        void _EnumerateImpl(Percentage &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(Length &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
        }
        void _EnumerateImpl(Number &u, std::function<const std::string()> getter, std::function<void(const std::string &)> setter) {
            u.set_getter(getter), u.set_setter(setter);
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
            _set<T, 0, Ts...>(attr);
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
            #define debug
            _LZ_WARNING("Found unsupported ctype \"" << typeid(u).name() << "\" in Enumerate, which only supports SVG attributes.");
            #undef debug
            #endif
        }
        template<typename T>
        void _set_impl(const T &attr, Percentage &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, Length &u) {
            u.set(attr);
        }
        template<typename T>
        void _set_impl(const T &attr, Number &u) {
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
        Enumerate<Ts...> &operator=(const T &attr) {
            _op1<T, 0, Ts...>(attr);
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
            #define debug
            _LZ_WARNING("Found unsupported ctype \"" << typeid(u).name() << "\" in Enumerate, which only supports SVG attributes.");
            #undef debug
            #endif
        }
        template<typename T>
        void _op1_impl(const T &attr, Percentage &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, Length &u) {
            u = attr;
        }
        template<typename T>
        void _op1_impl(const T &attr, Number &u) {
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
            #define debug
            _LZ_WARNING("Found unsupported ctype \"" << typeid(u).name() << "\" in Enumerate, which only supports SVG attributes.");
            #undef debug
            #endif
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, Percentage &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, Length &u) {
            u.bind(bind_func);
        }
        template<typename T>
        void _bind1_impl(std::function<const T()>bind_func, Number &u) {
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
        Enumerate<Ts...> &operator[](std::function<const T()>bind_func) {
            _op2<T, 0, Ts...>(bind_func);
            return *this;
        }
        template <typename T>
        Enumerate<Ts...> &operator[](const T(*bind_func)()) {
            std::function<const T()> _bind_func = bind_func;
            operator[](_bind_func);
        }
        template <typename T>
        void __op2(std::function<T()>bind_func) {
            _op2<T, 0, Ts...>(bind_func);
        }
        template <typename T>
        Enumerate<Ts...> &operator[](T bind_func) {
            auto p = lambda_to_function(bind_func);
            __op2(p);
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
            #define debug
            _LZ_WARNING("Found unsupported ctype \"" << typeid(u).name() << "\" in Enumerate, which only supports SVG attributes.");
            #undef debug
            #endif
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, Percentage &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, Length &u) {
            u[bind_func];
        }
        template<typename T>
        void _op2_impl(std::function<const T()>bind_func, Number &u) {
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
            #define debug
            _LZ_WARNING("Found unsupported ctype \"" << typeid(u).name() << "\" in Enumerate, which only supports SVG attributes.");
            #undef debug
            #endif
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, Percentage &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, Length &u) {
            u.bind(bind_ptr);
        }
        template<typename T>
        void _bind2_impl(const std::weak_ptr<T> &bind_ptr, Number &u) {
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
        Enumerate<Ts...> &operator[](const std::weak_ptr<T> &bind_ptr) {
            _op3<T, 0, Ts...>(bind_ptr);
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
            #define debug
            _LZ_WARNING("Found unsupported ctype \"" << typeid(u).name() << "\" in Enumerate, which only supports SVG attributes.");
            #undef debug
            #endif
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, Percentage &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, Length &u) {
            u[bind_ptr];
        }
        template<typename T>
        void _op3_impl(const std::weak_ptr<T> &bind_ptr, Number &u) {
            u[bind_ptr];
        }
    };
}
#ifdef __debug
#undef __debug
#define debug
#endif
#endif
