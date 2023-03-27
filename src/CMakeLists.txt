
include_directories(${CMAKE_SOURCE_DIR}/Utils)
set(CMAKE_BUILD_TYPE Debug)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	link_libraries(ntl gmp pthread)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	include_directories( $ENV{NTL_ROOT}/include)
	link_directories( $ENV{NTL_ROOT}/lib)
	if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
		link_libraries(ntl_mdd)
	else()
		link_libraries(ntl_md)
	endif()
endif()

add_executable(ntlGuessDeterminA51 mainA51.cpp A51Impl.hpp Merge.hpp PracticalAttack.hpp)
target_link_libraries(ntlGuessDeterminA51 CommonUtils)



