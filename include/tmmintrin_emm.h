/*
 *  Copyright (C) 2017 mntone
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _INCLUDED_TMM_EMM
#define _INCLUDED_TMM_EMM

#ifdef _INCLUDED_EMM
#if !defined(USE_COMPATIBLE) || !defined(_INCLUDED_TMM)

#include "simdutil_base.h"

DEF_FUNC(abs_epi8, __m128i, emm)(__m128i x) {
	const __m128i zero = _mm_setzero_si128();
	const __m128i tmp = _mm_cmpgt_epi8(zero, x);
	return _mm_sub_epi8(_mm_xor_si128(x, tmp), tmp);
}

DEF_FUNC(abs_epi16, __m128i, emm)(__m128i x) {
	const __m128i zero = _mm_setzero_si128();
	const __m128i tmp = _mm_cmpgt_epi16(zero, x);
	return _mm_sub_epi16(_mm_xor_si128(x, tmp), tmp);
}

DEF_FUNC(abs_epi32, __m128i, emm)(__m128i x) {
	const __m128i zero = _mm_setzero_si128();
	const __m128i tmp = _mm_cmpgt_epi32(zero, x);
	return _mm_sub_epi32(_mm_xor_si128(x, tmp), tmp);
}

#endif // defined(USE_COMPATIBLE) && !defined(_INCLUDED_TMM)
#endif // _INCLUDED_EMM
#endif // _INCLUDED_TMM_EMM
