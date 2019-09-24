#include <utility>

// import rem.vec;
// import rem.vec.bitwiseoperators;
// import rem.vec.comparisonoperators;
// import rem.vec.arithmeticoperators;
import rem;


namespace rem {
void test() { 
    using vec2 = vec<2, float>;
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

        // constexpr const vec2 g(4,5,6); // should not compile
    }
    {
        // test equals
        constexpr const vec2 f(4, 5);

        constexpr auto a = f == f;
        constexpr auto b = f != f;

        static_assert(a[0]);
        static_assert(a[1]);
        static_assert(!b[0]);
        static_assert(!b[1]);

        static_assert(all(a));
        static_assert(!all(b));

        static_assert(any(a));
        static_assert(!any(b));
    }
    {
        // test negation
        constexpr ivec2 a(1);
        constexpr auto b = -a;
        static_assert(b[0] == -1);
        static_assert(b[1] == -1);
    }

    {
        // test add
        constexpr ivec2 a(1);
        constexpr ivec2 b(1, 2);
        constexpr ivec2 c = a + b;

        static_assert(c[0] == 2);
        static_assert(c[1] == 3);
    }

    {
        vec2 v1;
        vec2 vm(v1);
        const vec2 v2(std::move(vm));

        v1 += 1.0f;

        auto b = v1[1];

        auto c = v1 == v2;
     
    }

}

}  // namespace rem


int main() { rem::test();
    
}
