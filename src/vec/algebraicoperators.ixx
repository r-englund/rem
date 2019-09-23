#ifndef _MSC_VER
module;
#endif
#include <limits>
#include <type_traits>
#include <numeric>
#include <cmath>
#include <compare>
export module rem.vec.algebraicoperators;

import rem.internal.common;

export import rem.vec;
export import rem.vec.arithmeticoperators;

namespace rem {

#ifdef has_is_constant_evaluated
constexpr bool is_constant_evaluated() { return std::is_constant_evaluated(); }
#else
constexpr bool is_constant_evaluated() { return true; }
#endif

template <typename T>
constexpr T sqrtNewtonRaphson(T x, T curr, T prev) {
    return curr == prev ? curr : sqrtNewtonRaphson(x, T{0.5} * (curr + x / curr), curr);
}

template <typename T>
constexpr T sqrt(T x) {
    if (is_constant_evaluated()) {
        return x >= 0 && x < std::numeric_limits<T>::infinity()
                   ? sqrtNewtonRaphson(x, x, T{0})
                   : std::numeric_limits<T>::quiet_NaN();
    } else {
        return std::sqrt(x);
    }
}

export template <typename T>
struct float_type {
    using type = std::common_type_t<T, double>;
};

export template <>
struct float_type<float> {
    using type = float;
};

export template <length_t L, typename T>
constexpr T dot(const vec<L, T>& lhs, const vec<L, T>& rhs) {
    // TODO test
    T res{0};
    for (length_t i = 0; i < L; i++) {
        res += lhs[i] * rhs[i];
    }
    return res;
}

export template <length_t L, typename T>
constexpr T length2(const vec<L, T>& v) {
    return dot(v, v);
}

export template <length_t L, typename T, typename F = typename float_type<T>::type>
constexpr F length(const vec<L, T>& v) {
    //  using F = typename float_type<T>::type;  // TODO, use as tempalte argument
    static_assert(std::is_floating_point_v<F>);
    return sqrt(static_cast<F>(dot(v, v)));
}

export template <length_t L, typename T>
constexpr auto distance(const vec<L, T>& a, const vec<L, T>& b) {
    return length(a - b);
}

export template <length_t L, typename T>
constexpr auto distance2(const vec<L, T>& a, const vec<L, T>& b) {
    return length2(a - b);
}

export template <length_t L, typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
constexpr vec<L, T> normalize(vec<L, T> v) {
    return v /= length(v);
}

export template <typename T>
constexpr vec<3, T> cross(const vec<3, T>& lhs, const vec<3, T>& rhs) {
    return vec<3, T>{lhs[1] * rhs[2] - rhs[1] * lhs[2], lhs[2] * rhs[0] - rhs[2] * lhs[0],
                     lhs[0] * rhs[1] - rhs[0] * lhs[1]};
}

}  // namespace rem