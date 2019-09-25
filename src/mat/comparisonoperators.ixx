export module rem.mat.comparisonoperators;

export import rem.internal.common;
export import rem.mat.mat;

REM_NAMESPACE_START

export template <typename T, length_t R, length_t C>
constexpr auto operator>(const mat<T, R, C>& lhs, const mat<T, R, C>& rhs) {
    mat<bool, R, C> res;
    for (length_t r = 0; r < R; r++) {
        for (length_t c = 0; c < C; c++) {
            res(r, c) = rhs(r, c) >= lhs(r, c);
        }
    }
    return res;
}

export template <typename T, length_t R, length_t C>
constexpr auto operator<(const mat<T, R, C>& lhs, const mat<T, R, C>& rhs) {
    mat<bool, R, C> res;
    for (length_t r = 0; r < R; r++) {
        for (length_t c = 0; c < C; c++) {
            res(r, c) = rhs(r, c) <= lhs(r, c);
        }
    }
    return res;
}

export template <typename T, length_t R, length_t C>
constexpr auto operator<=(const mat<T, R, C>& lhs, const mat<T, R, C>& rhs) {
    mat<bool, R, C> res;
    for (length_t r = 0; r < R; r++) {
        for (length_t c = 0; c < C; c++) {
            res(r, c) = rhs(r, c) <= lhs(r, c);
        }
    }
    return res;
}

export template <typename T, length_t R, length_t C>
constexpr auto operator>=(const mat<T, R, C>& lhs, const mat<T, R, C>& rhs) {
    mat<bool, R, C> res;
    for (length_t r = 0; r < R; r++) {
        for (length_t c = 0; c < C; c++) {
            res(r, c) = rhs(r, c) >= lhs(r, c);
        }
    }
    return res;
}

export template <typename T, length_t R, length_t C>
constexpr auto operator==(const mat<T, R, C>& lhs, const mat<T, R, C>& rhs) {
    mat<bool, R, C> res;
    for (length_t r = 0; r < R; r++) {
        for (length_t c = 0; c < C; c++) {
            res(r, c) = rhs(r, c) == lhs(r, c);
        }
    }
    return res;
}

export template <typename T, length_t R, length_t C>
constexpr auto operator!=(const mat<T, R, C>& lhs, const mat<T, R, C>& rhs) {
    mat<bool, R, C> res;
    for (length_t r = 0; r < R; r++) {
        for (length_t c = 0; c < C; c++) {
            res(r, c) = rhs(r, c) != lhs(r, c);
        }
    }
    return res;
}

export template <length_t R, length_t C>
constexpr bool all(const mat<bool, R, C>& v) {
    for (length_t r = 0; r < R; r++) {
        for (length_t c = 0; c < C; c++) {
            if (!v(r, c)) return false;
        }
    }
    return true;
}

export template <length_t R, length_t C>
constexpr bool none(const mat<bool, R, C>& v) {
    for (length_t r = 0; r < R; r++) {
        for (length_t c = 0; c < C; c++) {
            if (v(r, c)) return false;
        }
    }
    return true;
}

export template <length_t R, length_t C>
constexpr bool any(const mat<bool, R, C>& v) {
    for (length_t r = 0; r < R; r++) {
        for (length_t c = 0; c < C; c++) {
            if (v(r, c)) return true;
        }
    }
    return false;
}

REM_NAMESPACE_END
