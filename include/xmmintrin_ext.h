/*
 *  Copyright (C) 2017 mntone
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _INCLUDED_XMM_EXT
#define _INCLUDED_XMM_EXT

#ifdef _INCLUDED_MM2

#include "simdutil_base.h"

/*
 * SP, arithmetic
 */
DEF_FUNC_EXT(abs_ps, __m128)(__m128 x) {
	return _mm_andnot_ps(_mm_set1_ps(-0.0f), x);
}

#endif // _INCLUDED_MM2
#endif // _INCLUDED_XMM_EXT
