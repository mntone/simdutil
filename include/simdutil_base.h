/*
 *  Copyright (C) 2017 mntone
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef _INCLUDED_SIMD_UTILBASE
#define _INCLUDED_SIMD_UTILBASE

#if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
#define FORCEINLINE __attribute__((always_inline)) 
#elif defined(_MSC_VER)
#define FORCEINLINE __forceinline
#endif

#ifdef USE_COMPATIBLE
#define GET_FUNC(NAME, ENUM)         _mm_##NAME
#define GET_FUNC_EXT(NAME)           _mm_##NAME##_ext
#define DEF_FUNC(NAME, RETURN, ENUM) FORCEINLINE RETURN _mm_##NAME
#define DEF_FUNC_EXT(NAME, RETURN)   FORCEINLINE RETURN _mm_##NAME##_ext
#else
#define GET_FUNC(NAME, ENUM)         _mm_##NAME##_##ENUM
#define GET_FUNC_EXT(NAME)           _mm_##NAME##_ext
#define DEF_FUNC(NAME, RETURN, ENUM) FORCEINLINE RETURN _mm_##NAME##_##ENUM
#define DEF_FUNC_EXT(NAME, RETURN)   FORCEINLINE RETURN _mm_##NAME##_ext
#endif

#endif // _INCLUDED_SIMD_UTILBASE
