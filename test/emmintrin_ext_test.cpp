#include <emmintrin.h>

#include "emmintrin_ext.h"

#include <catch.hpp>
#include "testutil.hpp"

TEST_CASE("abs_pd") {
	__m128d x, e, a;
	LOOP_BASE(x.m128d_f64[i] = -8, 2);

	INFO_FLOAT64x2("x", x);

	a = _mm_abs_pd_ext(x);
	LOOP_BASE(e.m128d_f64[i] = std::abs(x.m128d_f64[i]), 2);

	INFO_FLOAT64x2("actual", a);
	INFO_FLOAT64x2("expected", e);
	REQUIRE_FLOAT64x2(a, e);
}

TEST_CASE("not_si128") {
	__m128i e, a;
	__m128i x = _mm_set1_epi64x(0xf0f0f0f0c3c3c3c3);

	INFO_INT64x2("x", x);

	a = _mm_not_si128_ext(x);
	LOOP_BASE(e.m128i_u64[i] = ~x.m128i_u64[i], 2);

	INFO_INT64x2("actual", a);
	INFO_INT64x2("expected", e);
	REQUIRE_INT64x2(a, e);
}

TEST_CASE("epu8") {
	__m128i a, e;
	__m128i x = _mm_setr_epi8(0, 6, 2, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i y = _mm_setr_epi8(0, 6, 8, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	INFO_UINT8x16("x", x);
	INFO_UINT8x16("y", y);

	SECTION("cmple") {
		a = _mm_cmple_epu8_ext(x, y);
		LOOP_BASE(e.m128i_u8[i] = std::less_equal<uint8_t>()(x.m128i_u8[i], y.m128i_u8[i])
			? (uint8_t)0xff : (uint8_t)0x00, 16);

		INFO_UINT8x16("actual", a);
		INFO_UINT8x16("expected", e);
		REQUIRE_UINT8x16(a, e);
	}

	SECTION("cmpge") {
		a = _mm_cmpge_epu8_ext(x, y);
		LOOP_BASE(e.m128i_u8[i] = std::greater_equal<uint8_t>()(x.m128i_u8[i], y.m128i_u8[i])
			? (uint8_t)0xff : (uint8_t)0x00, 16);

		INFO_UINT8x16("actual", a);
		INFO_UINT8x16("expected", e);
		REQUIRE_UINT8x16(a, e);
	}

	SECTION("cmpgt") {
		a = _mm_cmpgt_epu8_ext(x, y);
		LOOP_BASE(e.m128i_u8[i] = std::greater<uint8_t>()(x.m128i_u8[i], y.m128i_u8[i])
			? (uint8_t)0xff : (uint8_t)0x00, 16);

		INFO_UINT8x16("actual", a);
		INFO_UINT8x16("expected", e);
		REQUIRE_UINT8x16(a, e);
	}

	SECTION("cmplt") {
		a = _mm_cmplt_epu8_ext(x, y);
		LOOP_BASE(e.m128i_u8[i] = std::less<uint8_t>()(x.m128i_u8[i], y.m128i_u8[i])
			? (uint8_t)0xff : (uint8_t)0x00, 16);

		INFO_UINT8x16("actual", a);
		INFO_UINT8x16("expected", e);
		REQUIRE_UINT8x16(a, e);
	}
}

TEST_CASE("epu16") {
	__m128i a, e;
	__m128i x = _mm_setr_epi16(0, 6, 2, 6, 0, 0, 0, 0);
	__m128i y = _mm_setr_epi16(0, 6, 8, 4, 0, 0, 0, 0);

	INFO_UINT16x8("x", x);
	INFO_UINT16x8("y", y);

	SECTION("cmple") {
		a = _mm_cmple_epu16_ext(x, y);
		LOOP_BASE(e.m128i_u16[i] = std::less_equal<uint16_t>()(x.m128i_u16[i], y.m128i_u16[i])
			? (uint16_t)0xffff : (uint16_t)0x00, 8);

		INFO_UINT16x8("actual", a);
		INFO_UINT16x8("expected", e);
		REQUIRE_UINT16x8(a, e);
	}

	SECTION("cmpge") {
		a = _mm_cmpge_epu16_ext(x, y);
		LOOP_BASE(e.m128i_u16[i] = std::greater_equal<uint16_t>()(x.m128i_u16[i], y.m128i_u16[i])
			? (uint16_t)0xffff : (uint16_t)0x00, 8);

		INFO_UINT16x8("actual", a);
		INFO_UINT16x8("expected", e);
		REQUIRE_UINT16x8(a, e);
	}

	SECTION("cmpgt") {
		a = _mm_cmpgt_epu16_ext(x, y);
		LOOP_BASE(e.m128i_u16[i] = std::greater<uint16_t>()(x.m128i_u16[i], y.m128i_u16[i])
			? (uint16_t)0xffff : (uint16_t)0x00, 8);

		INFO_UINT16x8("actual", a);
		INFO_UINT16x8("expected", e);
		REQUIRE_UINT16x8(a, e);
	}

	SECTION("cmplt") {
		a = _mm_cmplt_epu16_ext(x, y);
		LOOP_BASE(e.m128i_u16[i] = std::less<uint16_t>()(x.m128i_u16[i], y.m128i_u16[i])
			? (uint16_t)0xffff : (uint16_t)0x00, 8);

		INFO_UINT16x8("actual", a);
		INFO_UINT16x8("expected", e);
		REQUIRE_UINT16x8(a, e);
	}
}
