#include <type_traits>

import rem.mat;

namespace rem {
void test() {
    using mat3 = mat<int, 3, 3>;
    using MA = mat<int, 1, 2>;
    using MB = mat<int, 2, 3>;
    using MC = mat<int, 1, 3>;
    {
        constexpr const mat3 I(1);
        constexpr const mat3 I2(2);
        constexpr const mat3 I4(4);
        constexpr auto R = mat_mult(I, I);
        constexpr auto R2 = mat_mult(I, I2);
        constexpr auto R4 = mat_mult(I2, I2);

        static_assert(all(R == I));
        static_assert(all(R2 == I2));
        static_assert(all(R4 == I4));
    }
    {
        constexpr const MA A(1, 2);
        constexpr const MB B(1, 2, 3, 4, 5, 6);
        constexpr const MC C(5, 11, 17);
        constexpr const auto D = mat_mult(A, B);

        static_assert(std::is_same_v<decltype(C), decltype(D)>);
        static_assert(D(0, 0) == 5);
        static_assert(D(0, 1) == 11);
        static_assert(D(0, 2) == 17);
        static_assert(all(C == D));
        int dummy = 0;
    }

}

}  // namespace rem

int main() { rem::test(); }
