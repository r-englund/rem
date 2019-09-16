export module rem.vec.comparisonoperators;
export import rem.vec;

namespace rem {

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
    for (length_t i = 0; i < L; i++) {
        if (!v[i]) return false;
    }
    return true;
}

export template <length_t L>
constexpr bool any(const vec<L, bool>& v) {
    for (length_t i = 0; i < L; i++) {
        if (v[i]) return true;
    }
    return false;
}

#ifdef HAS_SPACESHIP
export constexpr auto operator<=>(const vec& lhs, const vec& rhs) { return lhs.compare(rhs); }
#endif

}  // namespace rem