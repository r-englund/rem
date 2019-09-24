#include <utility>

//import rem.vec.vec;
// import rem.vec.bitwiseoperators;
// import rem.vec.comparisonoperators;
// import rem.vec.arithmeticoperators;
 import rem;

//#include <iostream>
namespace rem {
void test() {

    using vec2 = vec<2, float>;
    using ivec5 = vec<5, int>;
    using ivec2 = vec<2, int>;
    {  // test constructors
        constexpr vec2 a;
        static_assert(a[0] == 0);
        static_assert(a[1] == 0);

        constexpr const vec2 b = a;
        static_assert(b[0] == 0);
        static_assert(b[1] == 0);

        constexpr vec2 c = std::move(b);
        static_assert(c[0] == 0);
        static_assert(c[1] == 0);

        constexpr const vec2 d(3.15f);
        static_assert(d[0] == 3.15f);
        static_assert(d[1] == 3.15f);

        constexpr const vec2 e(3);
        static_assert(e[0] == 3);
        static_assert(e[1] == 3);

        constexpr const vec2 f(4.3f, 5.6f);
        static_assert(f[0] == 4.3f);
        static_assert(f[1] == 5.6f);

        constexpr const vec2 g(4, 5);
        static_assert(g[0] == 4);
        static_assert(g[1] == 5);

        constexpr const ivec5 h(1, 2, 3, 4, 5);
        static_assert(h[0] == 1);
        static_assert(h[1] == 2);
        static_assert(h[2] == 3);
        static_assert(h[3] == 4);
        static_assert(h[4] == 5);

        // constexpr const vec2 i(4,5,6); // should not compile

        //    int dummy = 0;
    }
    {  // Test bool vecs
        using bvec2 = vec<2, bool>;
        constexpr const bvec2 aa(false, false);
        constexpr const bvec2 ab(true, false);
        constexpr const bvec2 ba(false, true);
        constexpr const bvec2 bb(true, true);

        static_assert(!aa);
        static_assert(!ab);
        static_assert(!ba);
        static_assert(bb);
    }

    {  // test mat

        using mat3x3 = mat<float, 3>;
        using mat3x2 = mat<float, 3, 2>;

        constexpr const mat3x3 a(1.0f);
        constexpr const mat3x3 b(1, 2, 3, 4, 5, 6, 7, 8, 9);
    }
}
}  // namespace rem

int main() { rem::test(); }