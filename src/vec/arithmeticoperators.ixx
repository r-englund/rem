export module rem.vec.arithmeticoperators;

import rem.internal.common;

export import rem.vec.vec;

REM_NAMESPACE_START

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

REM_NAMESPACE_END
