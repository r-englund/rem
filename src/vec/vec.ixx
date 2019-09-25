module;
#include <array>
#include <type_traits>
export module rem.vec.vec;

export import rem.internal.common;
export import rem.internal.util;

REM_NAMESPACE_START

export template <length_t L, typename T>
struct vec {
    static_assert(L > 0);
    using value_type = T;
    using type = vec<L, T>;
    constexpr static inline length_t length = L;

    constexpr vec() noexcept : data{} {}

    constexpr explicit vec(T t) noexcept : data{createFilledArray<L>(t)} {}

    template <typename... TS,
              typename = std::enable_if_t<sizeof...(TS) == L
                                          //       &&
                                          // std::conjunction_v<std::is_convertible<TS,
                                          // T>...>
                                          //   (std::is_convertible_v<TS,
                                          //   T> && ...)
                                          >>
    constexpr vec(TS... v) noexcept : data{static_cast<T>(v)...} {}

    constexpr vec(const vec &rhs) noexcept  = default;
    constexpr vec(vec &&rhs) noexcept = default;
    constexpr vec &operator=(const vec &rhs) noexcept = default;
    constexpr vec &operator=(vec &&rhs) noexcept = default;

    constexpr T &operator[](length_t i) noexcept { return data[i]; }
    constexpr const T &operator[](length_t i) const noexcept { return data[i]; }

    constexpr auto compare(const vec &rhs) const noexcept {
        for (length_t i = 0; i < L; i++) {
            const auto v = data[i] - rhs.data[i];
            if (v != 0) return v;
        }
        return T{0};
    }

    template <typename U = T, typename = std::enable_if<std::is_same_v<bool, U>>::type>
    constexpr explicit operator bool() const noexcept {
        for (bool b : *this)
            if (!b) return false;
        return true;
    }

    constexpr auto begin() { return std::begin(data); }
    constexpr auto end() { return std::end(data); }
    constexpr auto begin() const { return std::begin(data); }
    constexpr auto end() const { return std::end(data); }

private:
    std::array<T, L> data;
};

REM_NAMESPACE_END



