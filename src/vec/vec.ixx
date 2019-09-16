export module rem.vec;

#include <type_traits>
//#include <array>
//#include <algorithm>

namespace rem {

export using length_t = unsigned;

export template <length_t L, typename T>
struct vec {

    using value_type = T;
    using type = vec<2, T>;
    constexpr static inline length_t length = L;

    constexpr vec() : data{} {}
    constexpr explicit vec(T t) : data{} {
        for (length_t i = 0; i < L; i++) {
            data[i] = t;
        }
    }
    template <typename T2,
              typename = std::enable_if_t<!std::is_same_v<T, T2> && std::is_convertible_v<T2, T>>>
    constexpr explicit vec(T2 t) : data{} {
        for (length_t i = 0; i < L; i++) {
            data[i] = static_cast<T>(t);
        }
    }

    template <typename... TS, typename = std::enable_if_t<sizeof...(TS) == L &&
                                                          (std::is_convertible_v<TS, T> && ...)>>
    constexpr vec(TS... v) : data{static_cast<T>(v)...} {}

    constexpr vec(const vec& rhs) = default;
    constexpr vec(vec&& rhs) = default;
    constexpr vec& operator=(const vec& rhs) = default;
    constexpr vec& operator=(vec&& rhs) = default;

    constexpr T& operator[](length_t i) { return data[i]; }
    constexpr const T& operator[](length_t i) const { return data[i]; }

    constexpr auto compare(const vec& rhs) const {
        for (length_t i = 0; i < L; i++) {
            const auto v = data[i] - rhs.data[i];
            if (v != 0) return v;
        }
        return T{0};
    }

  /*  constexpr auto begin() { return std::begin(data); }
    constexpr auto end() { return std::end(data); }
    constexpr auto begin() const { return std::begin(data); }
    constexpr auto end() const { return std::end(data); } */

private:
    T data[L];
};

export template <length_t L, typename T, typename = std::enable_if_t<std::is_signed_v<T>>>
constexpr vec<L, T> operator-(vec<L, T> lhs) {  // negation operator
    for (length_t i = 0; i < L; i++) {
        lhs[i] = -lhs[i];
    }
    return lhs;
}

export template <length_t L, typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
constexpr vec<L, T> operator~(vec<L, T> lhs) {
    for (length_t i = 0; i < L; i++) {
        lhs[i] = ~lhs[i];
    }
    return lhs;
}

export template <length_t L, typename T>
constexpr vec<L, T>& operator+=(vec<L, T>& lhs, T rhs) {
    //for (auto& v : lhs) {
    //    v += rhs;
    //}
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

export template <length_t L, typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
constexpr vec<L, T>& operator&=(vec<L, T>& lhs, const vec<L, T>& rhs) {
    for (length_t i = 0; i < L; i++) {
        lhs[i] &= rhs[i];
    }
    return lhs;
}

export template <length_t L, typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
constexpr vec<L, T>& operator|=(vec<L, T>& lhs, const vec<L, T>& rhs) {
    for (length_t i = 0; i < L; i++) {
        lhs[i] &= rhs[i];
    }
    return lhs;
}

export template <length_t L, typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
constexpr vec<L, T>& operator^=(vec<L, T>& lhs, const vec<L, T>& rhs) {
    for (length_t i = 0; i < L; i++) {
        lhs[i] ^= rhs[i];
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
