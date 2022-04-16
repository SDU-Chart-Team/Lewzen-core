#ifndef __LZ_ATTR_TUPLE__
#define __LZ_ATTR_TUPLE__
#include <string>
#include <memory>
#include <iostream>
#include "../../utils.h"

template<typename... Ts>
class Tuple {
private:
    std::tuple<Ts...> _tuple;
public:
    template<typename U>
    Tuple(U u) {
        std::get<sizeof...(Ts) - 1>(_tuple) = u;
    }
    template<typename U, class... Us>
    Tuple(U u, Us... us): Tuple(us...) {
        std::get<sizeof...(Ts) - sizeof...(Us) - 1>(_tuple) = u;
    }
    Tuple() {}
    
    template<typename I>
    void _OrImpl(const I &u) {}
    void _OrImpl(const A &u) {
        u.print();
    }
    template<std::size_t i, typename L>
    void _Or() {
        auto u = std::get<i>(_tuple);
        _OrImpl(u);
    }
    template<std::size_t i, typename F, typename S, typename ...R>
    void _Or() {
        auto u = std::get<i>(_tuple);
        _OrImpl(u);
        _Or<i + 1, S, R...>();
    }
    void Or() {
        _Or<0, Ts...>();
    }
};