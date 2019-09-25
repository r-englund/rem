
import rem.mat.transform;

namespace rem {
void test() {
    constexpr auto t = translate(1.0f, 2.0f, 3.0f);
    constexpr auto s1 = scale(1, 2, 3);
    constexpr auto s2 = scale(2);
}

}  // namespace rem

int main() { 
    rem::test(); 
}

