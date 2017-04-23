cmake_minimum_required(VERSION 2.8)

project(simdutil)

option(BUILD_CAPTIONS "Build captions" FALSE)

if(MSVC AND NOT EXISTS "${CMAKE_BINARY_DIR}/ALL_BUILD.vcxproj.user")
	file(GENERATE
		OUTPUT "${CMAKE_BINARY_DIR}/ALL_BUILD.vcxproj.user"
		INPUT "${CMAKE_SOURCE_DIR}/cmake/ALL_BUILD.vcxproj.user.in")
endif()

if(${CMAKE_C_COMPILER_ID} MATCHES "Clang" OR ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
	set(CMAKE_COMPILER_IS_CLANG TRUE)
endif()

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG)
	set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-function -Werror-implicit-function-declaration -Wno-missing-field-initializers ${CMAKE_CXX_FLAGS} -fno-strict-aliasing")
	set(CMAKE_C_FLAGS "-Wall -Wextra -Wno-unused-function -Werror-implicit-function-declaration -Wno-missing-braces -Wno-missing-field-initializers ${CMAKE_C_FLAGS} -std=gnu99 -fno-strict-aliasing")

	option(USE_LIBC++ "Use libc++ instead of libstdc++" ${APPLE})
	if(USE_LIBC++)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
	endif()
elseif(MSVC)
	if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
endif()

if(WIN32)
	add_definitions(-DUNICODE -D_UNICODE)
endif()

if(MSVC)
	set(CMAKE_C_FLAGS_DEBUG "/DDEBUG=1 /D_DEBUG=1 ${CMAKE_C_FLAGS_DEBUG}")
	set(CMAKE_CXX_FLAGS_DEBUG "/DDEBUG=1 /D_DEBUG=1 ${CMAKE_CXX_FLAGS_DEBUG}")

	if(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
		set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")
		set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /SAFESEH:NO")
		set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /SAFESEH:NO")
	endif()
endif()

add_subdirectory(test)
