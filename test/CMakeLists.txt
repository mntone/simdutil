project(simdutil-test)

include_directories(../deps/Catch/include/)
include_directories(../include/)

set(simdutil_HEADERS
	../include/simdutil_base.h
	../include/xmmintrin_ext.h
	../include/emmintrin_ext.h
	../include/smmintrin_emm.h
	../include/tmmintrin_emm.h
	../include/nmmintrin_ext.h
	)

set(simdutil-test_HEADERS
	testutil.hpp
	)

set(simdutil-test_SOURCES
	simdutil_test.cpp
	xmmintrin_ext_test.cpp
	emmintrin_ext_test.cpp
	smmintrin_emm_test.cpp
	tmmintrin_emm_test.cpp
	nmmintrin_ext_test.cpp
	)

add_executable(simdutil-test
	${simdutil_HEADERS}
	${simdutil-test_HEADERS}
	${simdutil-test_SOURCES}
	)
