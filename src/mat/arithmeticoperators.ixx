export module rem.mat.arithmeticoperators;

export import rem.internal.common;
export import rem.mat.mat;

REM_NAMESPACE_START

export template <typename T, length_t A, length_t B, length_t C>
constexpr mat<T, A, C> mat_mult(const mat<T, A, B> &a, const mat<T, B, C> &b) {
    mat<T, A, C> res;
    for (length_t r = 0; r < A; r++) {
        for (length_t c = 0; c < C; c++) {
            res(r, c) = 0;
            for (length_t e = 0; e < B; e++) {
                res(r, c) += a(r, e) * b(e, c);
            }
        }
    }

    return res;
}

REM_NAMESPACE_END