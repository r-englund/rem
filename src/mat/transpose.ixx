export module rem.mat.transpose;

export import rem.internal.common;

export import rem.mat.mat;

REM_NAMESPACE_START

//template <typename T, length_t C, length_t R>
//struct mat;

export template <
    typename M
    //typename T, length_t C, length_t R
    //,typename Ret = typename mat<T, C, R>::transpose_type
>
constexpr auto transpose(const M& m) {
    return M{};
}

REM_NAMESPACE_END