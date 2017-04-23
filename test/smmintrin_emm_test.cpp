#include <emmintrin.h>

#include "smmintrin_emm.h"
#include <smmintrin.h>

#include <catch.hpp>
#include "testutil.hpp"

TEST_CASE("epi8") {
	__m128i x, y, a, e;

	for (auto i = 0; i < 16; ++i) {
		x.m128i_i8[i] = 1;
		y.m128i_i8[i] = 126;
	}

	INFO_INT8x16("x", x);
	INFO_INT8x16("y", y);

	SECTION("max") {
		a = _mm_max_epi8_emm(x, y);
		e = _mm_max_epi8(x, y);

		INFO_INT8x16("actual", a);
		INFO_INT8x16("expected", e);
		REQUIRE_INT8x16(a, e);
	}

	SECTION("min") {
		a = _mm_min_epi8_emm(x, y);
		e = _mm_min_epi8(x, y);

		INFO_INT8x16("actual", a);
		INFO_INT8x16("expected", e);
		REQUIRE_INT8x16(a, e);
	}
}

TEST_CASE("epi16") {
	__m128i x, y, a, e;

	for (auto i = 0; i < 8; ++i) {
		x.m128i_i16[i] = 1;
		y.m128i_i16[i] = 126;
	}

	INFO_INT16x8("x", x);
	INFO_INT16x8("y", y);

	SECTION("max") {
		a = _mm_max_epi16_emm(x, y);
		e = _mm_max_epi16(x, y);

		INFO_INT16x8("actual", a);
		INFO_INT16x8("expected", e);
		REQUIRE_INT16x8(a, e);
	}

	SECTION("min") {
		a = _mm_min_epi16_emm(x, y);
		e = _mm_min_epi16(x, y);

		INFO_INT16x8("actual", a);
		INFO_INT16x8("expected", e);
		REQUIRE_INT16x8(a, e);
	}
}

TEST_CASE("epi32") {
	__m128i x, y, a, e;

	for (auto i = 0; i < 4; ++i) {
		x.m128i_i32[i] = 1;
		y.m128i_i32[i] = 126;
	}

	INFO_INT32x4("x", x);
	INFO_INT32x4("y", y);

	SECTION("max") {
		a = _mm_max_epi32_emm(x, y);
		e = _mm_max_epi32(x, y);

		INFO_INT32x4("actual", a);
		INFO_INT32x4("expected", e);
		REQUIRE_INT32x4(a, e);
	}

	SECTION("min") {
		a = _mm_min_epi32_emm(x, y);
		e = _mm_min_epi32(x, y);

		INFO_INT32x4("actual", a);
		INFO_INT32x4("expected", e);
		REQUIRE_INT32x4(a, e);
	}
}
