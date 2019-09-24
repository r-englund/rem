module;
#include <array>
export module rem.internal.util;

import rem.internal.common;

REM_NAMESPACE_START

export template <std::size_t N, typename T>
constexpr T passthrough_the_value_helper(T t) {
    return t;
}

export template <typename T, std::size_t... I>
constexpr auto createFilledArrayHelper(T t, std::index_sequence<I...>) {
    return std::array<T, sizeof...(I)>{passthrough_the_value_helper<I>(t)...};
}

export template <std::size_t N, typename T, typename Indices = std::make_index_sequence<N>>
constexpr std::array<T, N> createFilledArray(T t) {
    return createFilledArrayHelper(t, Indices{});
}

export template <std::size_t N, length_t C, typename T>
constexpr T passthrough_the_value_helper(T t) {
    if constexpr (N / C == N % C) {
        return t;
    } else {
        return {0};
    }
}

export template <length_t C, typename T, std::size_t... I>
constexpr auto createDiagonalMatrixHelper(T t, std::index_sequence<I...>) {
    return std::array<T, sizeof...(I)>{passthrough_the_value_helper<I, C>(t)...};
}

export template <length_t C, length_t R, typename T,
                 typename Indices = std::make_index_sequence<C * R>>
constexpr std::array<T, C * R> createDiagonalMatrix(T t) {
    static_assert(C == R, "Only works for square matrices");
    return createDiagonalMatrixHelper<R>(t, Indices{});
}

REM_NAMESPACE_END