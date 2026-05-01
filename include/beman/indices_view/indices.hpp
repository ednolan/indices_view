// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef BEMAN_INDICES_VIEW_INDICES_HPP
#define BEMAN_INDICES_VIEW_INDICES_HPP

#include <ranges>

namespace beman::indices_view {

#if defined(_LIBCPP_VERSION)
    #include <__iterator/concepts.h>
template <class _Ty>
concept _Integer_like = std::__integer_like<_Ty>;
#elif defined(__GLIBCXX__)
    #include <bits/iterator_concepts.h>
template <class _Ty>
concept _Integer_like = std::ranges::__detail::__is_integer_like<_Ty>;
#elif defined(_MSC_VER) && defined(_MSVC_STL_UPDATE)
    #include <__msvc_iter_core.hpp>
template <class _Ty>
concept _Integer_like = std::_Integer_like<_Ty>;
#endif

inline constexpr auto indices = []<_Integer_like I>(I n) { return std::views::iota(I{}, n); };

} // namespace beman::indices_view

#endif // BEMAN_INDICES_VIEW_INDICES_HPP
