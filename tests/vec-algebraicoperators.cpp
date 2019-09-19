
import rem.vec.algebraicoperators;
import rem.vec.comparisonoperators;

#include <iostream>

int main() {
    using ivec3 = rem::vec<3, int>;
    using vec3 = rem::vec<3, float>;

    constexpr const ivec3 a(1, 2, 3);
    constexpr const ivec3 b(2, 4, 5);

    static_assert(rem::dot(a, b) == 25);

    constexpr const ivec3 e0(1, 0, 0);
    constexpr const ivec3 e1(0, 1, 0);
    constexpr const ivec3 e2 = rem::cross(e0, e1);

    static_assert(e2 == ivec3{0, 0, 1});

    constexpr const ivec3 Z(0, 0, 0);
    constexpr const ivec3 Ix(1, 0, 0);
    constexpr const ivec3 Iy(0, 1, 0);
    constexpr const ivec3 Iz(0, 0, 1);
    constexpr const ivec3 I(1);
    constexpr const float sqrt3 = 1.73205080757f;
    constexpr const vec3 I3(1.0f / sqrt3);

    static_assert(rem::length2(Ix) == 1);
    static_assert(rem::length2(Iy) == 1);
    static_assert(rem::length2(Iy) == 1);

    static_assert(rem::length(Ix) == 1);
    static_assert(rem::length(Iy) == 1);
    static_assert(rem::length(Iy) == 1);
    auto abs = [](auto a) { return a >= 0 ? a : -a; };
    static_assert(abs(rem::length(I) - sqrt3) < 0.000001f);
    static_assert(rem::length(I3) == 1);

    static_assert(rem::distance2(Z, Ix) == 1);
    static_assert(rem::distance2(Z, Iy) == 1);
    static_assert(rem::distance2(Z, Iz) == 1);

    static_assert(rem::distance(Z, Ix) == 1);
    static_assert(rem::distance(Z, Iy) == 1);
    static_assert(rem::distance(Z, Iz) == 1);

    constexpr const vec3 fa(1.0f);
    constexpr const auto fb = rem::normalize(fa);
    static_assert(abs(rem::length2(fb) - 1.0f) < 0.000001f);
}
