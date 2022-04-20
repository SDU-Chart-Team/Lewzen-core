#ifndef __LZ_UTILS_LAMBDA_FUNC__
#define __LZ_UTILS_LAMBDA_FUNC__
#include <algorithm>
#include <functional>
#include <iostream>
#include <typeinfo>

namespace detail {
    template <typename F>
    struct function_traits : public function_traits<decltype(&F::operator())> {};

    template <typename R, typename C, typename... Args>
    struct function_traits<R (C::*)(Args...) const>
    {
        using function_type = std::function<R (Args...)>;
    };
}

namespace Lewzen {
    template <typename F>
    using function_type_t = typename detail::function_traits<F>::function_type;

    template <typename F>
    function_type_t<F> lambda_to_function(F & lambda) {
        return static_cast<function_type_t<F>>(lambda);
    }
}
#endif