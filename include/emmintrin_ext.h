/*
 *  Copyright (C) 2017 mntone
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _INCLUDED_EMM_EXT
#define _INCLUDED_EMM_EXT

#ifdef _INCLUDED_EMM

#include "simdutil_base.h"

/*
 * DP, arithmetic
 */
DEF_FUNC_EXT(abs_pd, __m128d)(__m128d x) {
	return _mm_andnot_pd(_mm_set1_pd(-0.0), x);
}

/*
 * Integer, logicals
 */
DEF_FUNC_EXT(not_si128, __m128i)(__m128i x) {
	return _mm_xor_si128(x, _mm_set1_epi32(0xffffffff));
}

/*
 * Integer 8-bit, comparisons
 */
DEF_FUNC_EXT(cmple_epu8, __m128i)(__m128i x, __m128i y) {
	return _mm_cmpeq_epi8(
		_mm_subs_epu8(x, y),
		_mm_setzero_si128());
}

DEF_FUNC_EXT(cmpge_epu8, __m128i)(__m128i x, __m128i y) {
	return GET_FUNC_EXT(cmple_epu8)(y, x);
}

DEF_FUNC_EXT(cmpgt_epu8, __m128i)(__m128i x, __m128i y) {
	return _mm_xor_si128(
		GET_FUNC_EXT(cmple_epu8)(x, y),
		_mm_set1_epi8(-1));
}

DEF_FUNC_EXT(cmplt_epu8, __m128i)(__m128i x, __m128i y) {
	return GET_FUNC_EXT(cmpgt_epu8)(y, x);
}

/*
 * Integer 16-bit, comparisons
 */
DEF_FUNC_EXT(cmple_epu16, __m128i)(__m128i x, __m128i y) {
	return _mm_cmpeq_epi16(
		_mm_subs_epu16(x, y),
		_mm_setzero_si128());
}

DEF_FUNC_EXT(cmpge_epu16, __m128i)(__m128i x, __m128i y) {
	return GET_FUNC_EXT(cmple_epu16)(y, x);
}

DEF_FUNC_EXT(cmpgt_epu16, __m128i)(__m128i x, __m128i y) {
	return _mm_xor_si128(
		GET_FUNC_EXT(cmple_epu16)(x, y),
		_mm_set1_epi8(-1));
}

DEF_FUNC_EXT(cmplt_epu16, __m128i)(__m128i x, __m128i y) {
	return GET_FUNC_EXT(cmpgt_epu16)(y, x);
}

#endif // _INCLUDED_EMM
#endif // _INCLUDED_EMM_EXT
