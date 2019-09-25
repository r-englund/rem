module;
#include <array>
#include <type_traits>
export module rem.mat.mat;

export import rem.internal.common;

import rem.internal.util;

import rem.vec.vec;

REM_NAMESPACE_START

export template <typename T, length_t R, length_t C = R>
struct mat {
    static_assert(R > 0);
    static_assert(C > 0);
    using value_type = T;
    using type = mat<T, R, C>;
    using col_type = vec<C, T>;
    using row_type = vec<R, T>;
    using transpose_type = mat<T, C, R>;
    constexpr static inline length_t rows = R;
    constexpr static inline length_t cols = C;
    constexpr mat() : data{} {}

    template <typename = std::enable_if_t<R == C>>
    constexpr explicit mat(T t) : data{createDiagonalMatrix<C, R>(t)} {}

    template <typename... TS,
              typename = std::enable_if_t<sizeof...(TS) == C * R
                                          //       &&
                                          // std::conjunction_v<std::is_convertible<TS,
                                          // T>...>
                                          //   (std::is_convertible_v<TS,T>
                                          //   && ...)
                                          >>
    constexpr mat(TS... v) : data{static_cast<T>(v)...} {}

    constexpr mat(const mat &rhs) = default;
    constexpr mat(mat &&rhs) = default;
    constexpr mat &operator=(const mat &rhs) = default;
    constexpr mat &operator=(mat &&rhs) = default;

    constexpr T &operator()(index_t row, index_t col) {
        // todo needs testing
        return data[index(row, col)];
    }
    constexpr const T &operator()(index_t row, index_t col) const {
        // todo needs testing
        return data[index(row, col)];
    }

    constexpr auto begin() { return std::begin(data); }
    constexpr auto end() { return std::end(data); }
    constexpr auto begin() const { return std::begin(data); }
    constexpr auto end() const { return std::end(data); }

private:
    constexpr auto index(index_t row, index_t col) const {
        return col * R + row;
    }

    std::array<T, R * C> data;
};

REM_NAMESPACE_END
