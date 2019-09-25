export module rem.mat.transform;

export import rem.internal.common;
export import rem.mat.mat;

REM_NAMESPACE_START

export template <typename T = float>
constexpr mat<T, 4, 4> translate(T dx, T dy, T dz);

export template <typename T = float>
constexpr mat<T, 4, 4> scale(T sx, T sy, T sz);
//
export template <typename T = float>
constexpr mat<T, 4, 4> scale(T s);

export constexpr int qwer() { return 123; }
export constexpr int qwer2();

REM_NAMESPACE_END