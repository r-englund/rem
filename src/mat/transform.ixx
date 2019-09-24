export module rem.mat.transform;

export import rem.internal.common;
export import rem.mat.mat;

REM_NAMESPACE_START

export template <typename T = float>
constexpr mat<T, 4, 4> translate(T dx, T dy, T dz) {
    return mat<T, 4, 4>{
        1,  0,  0,  0,  // col 0
        0,  1,  0,  0,  // col 1
        0,  0,  1,  0,  // col 2
        dx, dy, dz, 1   // col 3
    };
}
////
//export template <typename T = float, typename T2 = T>
//constexpr mat<T, 4, 4> scale(T2 sx, T2 sy, T2 sz);
//
//export template <typename T = float, typename T2 = T>
//constexpr mat<T, 4, 4> scale(T2 s);

REM_NAMESPACE_END