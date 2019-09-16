#ifndef _MSC_VER
module;
#endif
#include <array>
#include <type_traits>

export module rem.vec;

// import stdstuff;
//#include <array>
//#include <algorithm>

namespace rem {

export using length_t = unsigned;

template <length_t L, typename T> constexpr auto create_filled_array(T t) {
  std::array<T, L> data = {};
  for (length_t i = 0; i < L; i++) {
    data[i] = t;
  }
  return data;
}

template <std::size_t N, typename T>
constexpr T passthrough_the_value_helper(T t) {
  return t;
}

template <typename T, std::size_t... I>
constexpr auto createFilledArrayHelper(T t, std::index_sequence<I...>) {
  return std::array<T, sizeof...(I)>{passthrough_the_value_helper<I>(t)...};
}

template <std::size_t N, typename T,
          typename Indices = std::make_index_sequence<N>>
constexpr std::array<T, N> createFilledArray(T t) {
  return createFilledArrayHelper(t, Indices{});
}

export template <length_t L, typename T> struct vec {

  using value_type = T;
  using type = vec<2, T>;
  constexpr static inline length_t length = L;

  constexpr vec() : data{} {}

  constexpr explicit vec(T t) : data{createFilledArray<L>(t)} {}

  template <typename... TS, typename = std::enable_if_t<sizeof...(TS) == L
                                                        //       &&
                                                        // std::conjunction_v<std::is_convertible<TS,
                                                        // T>...>
                                                        //   (std::is_convertible_v<TS,
                                                        //   T> && ...)
                                                        >>
  constexpr vec(TS... v) : data{static_cast<T>(v)...} {}

  constexpr vec(const vec &rhs) = default;
  constexpr vec(vec &&rhs) = default;
  constexpr vec &operator=(const vec &rhs) = default;
  constexpr vec &operator=(vec &&rhs) = default;

  constexpr T &operator[](length_t i) { return data[i]; }
  constexpr const T &operator[](length_t i) const { return data[i]; }

  constexpr auto compare(const vec &rhs) const {
    for (length_t i = 0; i < L; i++) {
      const auto v = data[i] - rhs.data[i];
      if (v != 0)
        return v;
    }
    return T{0};
  }

  /*  constexpr auto begin() { return std::begin(data); }
    constexpr auto end() { return std::end(data); }
    constexpr auto begin() const { return std::begin(data); }
    constexpr auto end() const { return std::end(data); } */

private:
  std::array<T, L> data;
};

} // namespace rem
