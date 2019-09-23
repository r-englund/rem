export module rem.mat.transform;

export import rem.internal.common;
export import rem.mat;

namespace rem {

export template <typename T = float, typename T2 = T>
constexpr mat<T, 4, 4> translate(T2 dx, T2 dy, T2 dz);

export template <typename T = float, typename T2 = T>
constexpr mat<T, 4, 4> scale(T2 sx, T2 sy, T2 sz);

export template <typename T = float, typename T2 = T>
constexpr mat<T, 4, 4> scale(T2 s);

}  // namespace rem