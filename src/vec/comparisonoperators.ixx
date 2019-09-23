export module rem.vec.comparisonoperators;

export import rem.vec;

namespace rem {
template <length_t L, typename T>
struct vec;

export template <length_t L, typename T>
constexpr auto operator>(const vec<L, T>& lhs, const vec<L, T>& rhs) {
    vec<L, bool> res;
    for (length_t i = 0; i < L; i++) {
        res[i] = rhs[i] > lhs[i];
    }
    return res;
}

export template <length_t L, typename T>
constexpr auto operator<=(const vec<L, T>& lhs, const vec<L, T>& rhs) {
    vec<L, bool> res;
    for (length_t i = 0; i < L; i++) {
        res[i] = rhs[i] <= lhs[i];
    }
    return res;
}

export template <length_t L, typename T>
constexpr auto operator>=(const vec<L, T>& lhs, const vec<L, T>& rhs) {
    vec<L, bool> res;
    for (length_t i = 0; i < L; i++) {
        res[i] = rhs[i] >= lhs[i];
    }
    return res;
}

export template <length_t L, typename T>
constexpr auto operator==(const vec<L, T>& lhs, const vec<L, T>& rhs) {
    vec<L, bool> res;
    for (length_t i = 0; i < L; i++) {
        res[i] = rhs[i] == lhs[i];
    }
    return res;
}

export template <length_t L, typename T>
constexpr auto operator!=(const vec<L, T>& lhs, const vec<L, T>& rhs) {
    vec<L, bool> res;
    for (length_t i = 0; i < L; i++) {
        res[i] = rhs[i] != lhs[i];
    }
    return res;
}

export template <length_t L, typename T>
constexpr auto operator<(const vec<L, T>& lhs, const vec<L, T>& rhs) {
    vec<L, bool> res;
    for (length_t i = 0; i < L; i++) {
        res[i] = rhs[i] < lhs[i];
    }
    return res;
}

export template <length_t L>
constexpr bool all(const vec<L, bool>& v) {
    return v ? true : false;
}

export template <length_t L>
constexpr bool none(const vec<L, bool>& v) {
    return !v;
}

export template <length_t L>
constexpr bool any(const vec<L, bool>& v) {
    for (bool b : v) {
        if (b) return true;
    }
    return false;
}

#ifdef HAS_3WAY_COMP
export template <length_t L, typename T>
constexpr auto operator<=>(const vec<L,T>& lhs, const vec<L,T>& rhs) { return lhs.compare(rhs); }
#endif

}  // namespace rem