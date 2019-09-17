export module rem.mat.transpose;

export import rem.internal.common;
export import rem.mat;

namespace rem {

template <typename T, length_t C, length_t R, typename M = mat<T, C, R>,
          typename Ret = M::transpose_type>
Ret transpose(const M& m) {
    return {};
}

}  // namespace rem