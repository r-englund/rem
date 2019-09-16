#include <utility>

// import rem.vec;
// import rem.vec.bitwiseoperators;
// import rem.vec.comparisonoperators;
// import rem.vec.arithmeticoperators;
import rem;

//#include <iostream>

int main() {

    using vec2 = rem::vec<2, float>;
    using vec3 = rem::vec<3, float>;
    using ivec2 = rem::vec<2, int>;
    { // test constructors
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

        // constexpr const vec2 g(4,5,6); // should not compile

        int dummy = 0;
    }
  
}
