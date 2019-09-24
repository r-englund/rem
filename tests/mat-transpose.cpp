import rem.mat.transpose;

namespace rem {

void test() {
    using mat3 = mat<float, 3, 3>;
    constexpr const mat3 a(1);
    constexpr const mat3::transpose_type b = transpose(a);
}

}  // namespace rem

int main() { rem::test(); }
