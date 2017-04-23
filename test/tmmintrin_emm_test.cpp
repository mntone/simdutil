#include <emmintrin.h>

#include "tmmintrin_emm.h"
#include <tmmintrin.h>

#include <catch.hpp>
#include "testutil.hpp"

TEST_CASE("abs_epi8 [emm emulation]") {
	__m128i x, e, a;

	for (auto i = 0; i < 2; ++i) {
		x.m128i_i8[i] = -8;
	}

	INFO_INT8x16("x", x);

	a = _mm_abs_epi8_emm(x);
	e = _mm_abs_epi8(x);

	INFO_INT8x16("actual", a);
	INFO_INT8x16("expected", e);
	REQUIRE_INT8x16(a, e);
}

TEST_CASE("abs_epi16 [emm emulation]") {
	__m128i x, e, a;

	for (auto i = 0; i < 2; ++i) {
		x.m128i_i16[i] = -8;
	}

	INFO_INT16x8("x", x);

	a = _mm_abs_epi16_emm(x);
	e = _mm_abs_epi16(x);

	INFO_INT16x8("actual", a);
	INFO_INT16x8("expected", e);
	REQUIRE_INT16x8(a, e);
}

TEST_CASE("abs_epi32 [emm emulation]") {
	__m128i x, e, a;

	for (auto i = 0; i < 2; ++i) {
		x.m128i_i32[i] = -8;
	}

	INFO_INT32x4("x", x);

	a = _mm_abs_epi32_emm(x);
	e = _mm_abs_epi32(x);

	INFO_INT32x4("actual", a);
	INFO_INT32x4("expected", e);
	REQUIRE_INT32x4(a, e);
}

