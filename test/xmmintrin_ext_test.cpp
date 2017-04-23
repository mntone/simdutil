#include <xmmintrin.h>

#include "xmmintrin_ext.h"

#include <catch.hpp>
#include "testutil.hpp"

TEST_CASE("abs_ps") {
	__m128 x, e, a;
	LOOP_BASE(x.m128_f32[i] = -8, 2);

	INFO_FLOAT32x4("x", x);

	a = _mm_abs_ps_ext(x);
	LOOP_BASE(e.m128_f32[i] = std::abs(x.m128_f32[i]), 4);

	INFO_FLOAT32x4("actual", a);
	INFO_FLOAT32x4("expected", e);
	REQUIRE_FLOAT32x4(a, e);
}
