
include_directories(${CMAKE_SOURCE_DIR}/Utils)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	set(CMAKE_BUILD_TYPE Debug)
	link_libraries(ntl gmp pthread)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	include_directories( $ENV{NTL_ROOT}/include)
	link_directories( $ENV{NTL_ROOT}/lib)
	message(${CMAKE_BUILD_TYPE})
	if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
		message("Debug")
		link_libraries(ntl_mdd)
	else()
		message("Release")
		link_libraries(ntl_md)
	endif()
endif()

add_executable(ntlGuessDeterminA51 mainA51.cpp A51Impl.hpp Merge.hpp PracticalAttack.hpp)
target_link_libraries(ntlGuessDeterminA51 CommonUtils)



