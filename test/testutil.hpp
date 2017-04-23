#pragma once

#include <functional>
#include <sstream>

#define INFO_BASE(v, x, param, count, len, type) \
	::std::stringstream stream_##x; \
	stream_##x << ::std::setw(8) << v << ": "; \
	for (size_t i = 0; i < count; ++i) { \
		stream_##x << ::std::setw(len) \
			   << ::std::right \
			   << ::std::hex \
			   << (type)x.param[i] \
			   << "; "; \
	} \
	INFO(stream_##x.str());

#define INFO_INT(v, x, param, count, len)   INFO_BASE(v, x, param, count, len, int64_t)
#define INFO_UINT(v, x, param, count, len)  INFO_BASE(v, x, param, count, len, uint64_t)
#define INFO_FLOAT(v, x, param, count, len) INFO_BASE(v, x, param, count, len, double)

#define INFO_INT8x16(v, x)   INFO_INT(v, x, m128i_i8,  16,  2);
#define INFO_INT16x8(v, x)   INFO_INT(v, x, m128i_i16,  8,  4);
#define INFO_INT32x4(v, x)   INFO_INT(v, x, m128i_i32,  4,  8);
#define INFO_INT64x2(v, x)   INFO_INT(v, x, m128i_i64,  2, 16);

#define INFO_UINT8x16(v, x)  INFO_UINT(v, x, m128i_u8,  16,  2);
#define INFO_UINT16x8(v, x)  INFO_UINT(v, x, m128i_u16,  8,  4);
#define INFO_UINT32x4(v, x)  INFO_UINT(v, x, m128i_u32,  4,  8);
#define INFO_UINT64x2(v, x)  INFO_UINT(v, x, m128i_u64,  2, 16);

#define INFO_FLOAT32x4(v, x) INFO_FLOAT(v, x, m128_f32,  4,  8);
#define INFO_FLOAT64x2(v, x) INFO_FLOAT(v, x, m128d_f64, 2,  8);

#define REQUIRE_BASE(x, y, param, count) \
	for (size_t i = 0; i < count; ++i) { \
		REQUIRE(x.param[i] == y.param[i]); \
	}

#define REQUIRE_INT8x16(x, y)   REQUIRE_BASE(x, y, m128i_i8,  16);
#define REQUIRE_INT16x8(x, y)   REQUIRE_BASE(x, y, m128i_i16,  8);
#define REQUIRE_INT32x4(x, y)   REQUIRE_BASE(x, y, m128i_i32,  4);
#define REQUIRE_INT64x2(x, y)   REQUIRE_BASE(x, y, m128i_i64,  2);

#define REQUIRE_UINT8x16(x, y)  REQUIRE_BASE(x, y, m128i_u8,  16);
#define REQUIRE_UINT16x8(x, y)  REQUIRE_BASE(x, y, m128i_u16,  8);
#define REQUIRE_UINT32x4(x, y)  REQUIRE_BASE(x, y, m128i_u32,  4);
#define REQUIRE_UINT64x2(x, y)  REQUIRE_BASE(x, y, m128i_u64,  2);

#define REQUIRE_FLOAT32x4(x, y) REQUIRE_BASE(x, y, m128_f32,   4);
#define REQUIRE_FLOAT64x2(x, y) REQUIRE_BASE(x, y, m128d_f64,  2);

#define LOOP_BASE(syntax, count) \
	for (size_t i = 0; i < count; ++i) { \
		syntax; \
	}

