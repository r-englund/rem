#ifndef _MSC_VER
module;
#endif
export module rem.vec.arithmeticoperators;

import rem.internal.common;

export import rem.vec;

namespace rem {

template <length_t L, typename T>
struct vec;

export template <length_t L, typename T>
constexpr vec<L, T> operator-(vec<L, T> lhs) {  // negation operator
    for (auto& v : lhs) {
        v = -v;
    }
    return lhs;
}

export template <length_t L, typename T>
constexpr vec<L, T>& operator+=(vec<L, T>& lhs, T rhs) {
    for (auto& v : lhs) {
        v += rhs;
    }
    return lhs;
}

export template <length_t L, typename T>
constexpr vec<L, T>& operator-=(vec<L, T>& lhs, T rhs) {
    for (auto& v : lhs) {
        v -= rhs;
    }
    return lhs;
}

export template <length_t L, typename T>
constexpr vec<L, T>& operator*=(vec<L, T>& lhs, T rhs) {
    for (auto& v : lhs) {
        v *= rhs;
    }
    return lhs;
}

export template <length_t L, typename T>
constexpr vec<L, T>& operator/=(vec<L, T>& lhs, T rhs) {
    for (auto& v : lhs) {
        v /= rhs;
    }
    return lhs;
}

export template <length_t L, typename T>
constexpr vec<L, T>& operator+=(vec<L, T>& lhs, const vec<L, T> rhs) {
    for (length_t i = 0; i < L; i++) {
        lhs[i] += rhs[i];
    }
    return lhs;
}

export template <length_t L, typename T>
constexpr vec<L, T>& operator-=(vec<L, T>& lhs, const vec<L, T> rhs) {
    for (length_t i = 0; i < L; i++) {
        lhs[i] -= rhs[i];
    }
    return lhs;
}

export template <length_t L, typename T>
constexpr vec<L, T>& operator*=(vec<L, T>& lhs, const vec<L, T> rhs) {
    for (length_t i = 0; i < L; i++) {
        lhs[i] *= rhs[i];
    }
    return lhs;
}

export template <length_t L, typename T>
constexpr vec<L, T>& operator/=(vec<L, T>& lhs, const vec<L, T> rhs) {
    for (length_t i = 0; i < L; i++) {
        lhs[i] /= rhs[i];
    }
    return lhs;
}

export template <length_t L, typename T, typename T2>
constexpr vec<L, T> operator+(vec<L, T> lhs, const T2& rhs) {
    return lhs += rhs;
}
export template <length_t L, typename T>
constexpr vec<L, T> operator-(vec<L, T> lhs, const vec<L, T>& rhs) {
    return lhs -= rhs;
}
export template <length_t L, typename T>
constexpr vec<L, T> operator*(vec<L, T> lhs, const vec<L, T>& rhs) {
    return lhs *= rhs;
}
export template <length_t L, typename T>
constexpr vec<L, T> operator/(vec<L, T> lhs, const vec<L, T>& rhs) {
    return lhs /= rhs;
}

}  // namespace rem