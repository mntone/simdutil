#include <emmintrin.h>

#include "pmmintrin_emm.h"
#include <pmmintrin.h>

#include <catch.hpp>
#include "testutil.hpp"

TEST_CASE("addsub_ps [emm emulation]") {
	__m128 e, a;
	__m128 x = _mm_setr_ps(4.0f, 2.0f, 2.0f, 4.0f);
	__m128 y = _mm_setr_ps(3.0f, 6.0f, 6.0f, 3.0f);
	INFO_FLOAT32x4("x", x);
	INFO_FLOAT32x4("y", y);

	a = _mm_addsub_ps_emm(x, y);
	e = _mm_addsub_ps(x, y);

	INFO_FLOAT32x4("actual", a);
	INFO_FLOAT32x4("expected", e);
	REQUIRE_FLOAT32x4(a, e);
}

TEST_CASE("addsub_pd [emm emulation]") {
	__m128d e, a;
	__m128d x = _mm_setr_pd(4.0, 2.0);
	__m128d y = _mm_setr_pd(3.0, 6.0);
	INFO_FLOAT64x2("x", x);
	INFO_FLOAT64x2("y", y);

	a = _mm_addsub_pd_emm(x, y);
	e = _mm_addsub_pd(x, y);

	INFO_FLOAT64x2("actual", a);
	INFO_FLOAT64x2("expected", e);
	REQUIRE_FLOAT64x2(a, e);
}
