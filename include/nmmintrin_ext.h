/*
 *  Copyright (C) 2017 mntone
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _INCLUDED_NMM_EXT
#define _INCLUDED_NMM_EXT

#ifdef _INCLUDED_NMM

#include "simdutil_base.h"

/*
 * Integer 64-bit, arithmetic
 */
DEF_FUNC_EXT(max_epi64, __m128i)(__m128i x,  __m128i y) {
	const __m128i mk = _mm_cmpgt_epi64(x, y);
	const __m128i sa = _mm_and_si128(mk, x);
	const __m128i sb = _mm_andnot_si128(mk, y);
	return _mm_or_si128(sa, sb);
}

DEF_FUNC_EXT(min_epi64, __m128i)(__m128i x,  __m128i y) {
	const __m128i mk = _mm_cmpgt_epi64(x, y);
	const __m128i sa = _mm_andnot_si128(mk, x);
	const __m128i sb = _mm_and_si128(mk, y);
	return _mm_or_si128(sa, sb);
}

DEF_FUNC_EXT(abs_epi64, __m128i)(__m128i x) {
	const __m128i zero = _mm_setzero_si128();
	const __m128i tmp = _mm_cmpgt_epi64(zero, x);
	return _mm_sub_epi64(_mm_xor_si128(x, tmp), tmp);
}

#endif // _INCLUDED_NMM
#endif // _INCLUDED_NMM_EXT
