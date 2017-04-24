/*
 *  Copyright (C) 2017 mntone
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _INCLUDED_PMM_EMM
#define _INCLUDED_PMM_EMM

#ifdef _INCLUDED_EMM
#if !defined(USE_COMPATIBLE) || !defined(_INCLUDED_EMM)

#include "simdutil_base.h"

DEF_FUNC(addsub_ps, __m128, emm)(__m128 x, __m128 y) {
	const __m128 mk = _mm_setr_ps(-1.0f, 1.0f, -1.0f, 1.0f);
	return _mm_add_ps(x, _mm_mul_ps(y, mk));
}

DEF_FUNC(addsub_pd, __m128d, emm)(__m128d x, __m128d y) {
	const __m128d mk = _mm_setr_pd(-1.0, 1.0);
	return _mm_add_pd(x, _mm_mul_pd(y, mk));
}

#endif // defined(USE_COMPATIBLE) && !defined(_INCLUDED_EMM)
#endif // _INCLUDED_EMM
#endif // _INCLUDED_PMM_EMM
