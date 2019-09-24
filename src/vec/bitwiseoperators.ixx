module;
#include <type_traits>
export module rem.vec.bitwiseoperators;

export import rem.vec.vec;

REM_NAMESPACE_START

export template <length_t L, typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
constexpr vec<L, T> operator~(vec<L, T> lhs) {
    for (length_t i = 0; i < L; i++) {
        lhs[i] = ~lhs[i];
    }
    return lhs;
}

export template <length_t L, typename T, typename = std2::enable_if_t<std::is_integral_v<T>>>
constexpr vec<L, T>& operator&=(vec<L, T>& lhs, const vec<L, T>& rhs) {
    for (length_t i = 0; i < L; i++) {
        lhs[i] &= rhs[i];
    }
    return lhs;
}

export template <length_t L, typename T, typename = std2::enable_if_t<std::is_integral_v<T>>>
constexpr vec<L, T>& operator|=(vec<L, T>& lhs, const vec<L, T>& rhs) {
    for (length_t i = 0; i < L; i++) {
        lhs[i] &= rhs[i];
    }
    return lhs;
}

export template <length_t L, typename T, typename = std2::enable_if_t<std::is_integral_v<T>>>
constexpr vec<L, T>& operator^=(vec<L, T>& lhs, const vec<L, T>& rhs) {
    for (length_t i = 0; i < L; i++) {
        lhs[i] ^= rhs[i];
    }
    return lhs;
}

REM_NAMESPACE_END
