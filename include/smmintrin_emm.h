/*
 *  Copyright (C) 2017 mntone
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _INCLUDED_SMM_EMM
#define _INCLUDED_SMM_EMM

#ifdef _INCLUDED_EMM
#if !defined(USE_COMPATIBLE) || !defined(_INCLUDED_SMM)

#include "simdutil_base.h"

/*
 * Integer 8-bit, arithmetic
 */
DEF_FUNC(max_epi8, __m128i, emm)(__m128i x,  __m128i y) {
	const __m128i mk = _mm_cmpgt_epi8(x, y);
	const __m128i sa = _mm_and_si128(mk, x);
	const __m128i sb = _mm_andnot_si128(mk, y);
	return _mm_or_si128(sa, sb);
}

DEF_FUNC(min_epi8, __m128i, emm)(__m128i x,  __m128i y) {
	const __m128i mk = _mm_cmpgt_epi8(x, y);
	const __m128i sa = _mm_andnot_si128(mk, x);
	const __m128i sb = _mm_and_si128(mk, y);
	return _mm_or_si128(sa, sb);
}

/*
 * Integer 16-bit, arithmetic
 */
DEF_FUNC(max_epi16, __m128i, emm)(__m128i x, __m128i y) {
	const __m128i mk = _mm_cmpgt_epi16(x, y);
	const __m128i sa = _mm_and_si128(mk, x);
	const __m128i sb = _mm_andnot_si128(mk, y);
	return _mm_or_si128(sa, sb);
}

DEF_FUNC(min_epi16, __m128i, emm)(__m128i x, __m128i y) {
	const __m128i mk = _mm_cmpgt_epi16(x, y);
	const __m128i sa = _mm_andnot_si128(mk, x);
	const __m128i sb = _mm_and_si128(mk, y);
	return _mm_or_si128(sa, sb);
}

/*
 * Integer 32-bit, arithmetic
 */
DEF_FUNC(max_epi32, __m128i, emm)(__m128i x,  __m128i y) {
	const __m128i mk = _mm_cmpgt_epi32(x, y);
	const __m128i sa = _mm_and_si128(mk, x);
	const __m128i sb = _mm_andnot_si128(mk, y);
	return _mm_or_si128(sa, sb);
}

DEF_FUNC(min_epi32, __m128i, emm)(__m128i x,  __m128i y) {
	const __m128i mk = _mm_cmpgt_epi32(x, y);
	const __m128i sa = _mm_andnot_si128(mk, x);
	const __m128i sb = _mm_and_si128(mk, y);
	return _mm_or_si128(sa, sb);
}

#endif // !defined(USE_COMPATIBLE) || !defined(_INCLUDED_SMM)
#endif // _INCLUDED_EMM
#endif // _INCLUDED_SMM_EMM
