#include <nmmintrin.h>

#include "nmmintrin_ext.h"

#include <catch.hpp>
#include "testutil.hpp"

TEST_CASE("epi64") {
	__m128i x, y, a, e;

	for (auto i = 0; i < 2; ++i) {
		x.m128i_i64[i] = 1;
		y.m128i_i64[i] = 126;
	}

	INFO_INT64x2("x", x);
	INFO_INT64x2("y", y);

	SECTION("max") {
		a = _mm_max_epi64_ext(x, y);
		e.m128i_i64[0] = std::max(x.m128i_i64[0], y.m128i_i64[0]);
		e.m128i_i64[1] = std::max(x.m128i_i64[1], y.m128i_i64[1]);

		INFO_INT64x2("actual", a);
		INFO_INT64x2("expected", e);
		REQUIRE_INT64x2(a, e);
	}

	SECTION("min") {
		a = _mm_min_epi64_ext(x, y);
		e.m128i_i64[0] = std::min(x.m128i_i64[0], y.m128i_i64[0]);
		e.m128i_i64[1] = std::min(x.m128i_i64[1], y.m128i_i64[1]);

		INFO_INT64x2("actual", a);
		INFO_INT64x2("expected", e);
		REQUIRE_INT64x2(a, e);
	}
}

TEST_CASE("abs_epi64") {
	__m128i x, e, a;

	for (auto i = 0; i < 2; ++i) {
		x.m128i_i32[i] = -8;
	}

	INFO_INT32x4("x", x);

	a = _mm_abs_epi64_ext(x);
	e.m128i_i64[0] = std::abs(x.m128i_i64[0]);
	e.m128i_i64[1] = std::abs(x.m128i_i64[1]);

	INFO_INT32x4("actual", a);
	INFO_INT32x4("expected", e);
	REQUIRE_INT32x4(a, e);
}
