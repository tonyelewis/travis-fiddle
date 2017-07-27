cmake_minimum_required (VERSION 2.8)

# For useful information on getting CMake to work with Boost, type the following command: cmake --help-module FindBoost
# 
# if( BUILD_SHARED_LIBS )
# 	add_definitions( -DBOOST_ALL_DYN_LINK )
# 	add_definitions( -DBOOST_LOG_DYN_LINK )
# 	set( GSL_LIB_SUFFIX ${GSL_LIBRARIES} )
# else()
# 	set( Boost_USE_STATIC_LIBS ON )
# 	SET( GSL_LIB_SUFFIX "${GSL_STATIC_LIB}" "${GSLCBLAS_STATIC_LIB}" )
# endif()
# 
# if ( ${LSB_RELEASE_CODE} STREQUAL "yakkety" )
# 	set( GSL_LIB_SUFFIX ${GSL_LIBRARIES} )
# endif()
# 
# find_library( RT_LIBRARY rt )

# add_definitions( -DBOOST_ALL_DYN_LINK )
# add_definitions( -DBOOST_LOG_DYN_LINK )
set( Boost_USE_STATIC_LIBS ON )

find_package(Boost 1.57 REQUIRED filesystem iostreams log_setup log program_options serialization system thread unit_test_framework)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Werror -Wextra -Wsign-compare -Wsign-conversion -Wcast-qual -Wconversion -Wnon-virtual-dtor -pedantic" )

# Append debug compiler flags with setting of _GLIBCXX_DEBUG
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

# For Clang, use libc++ and color-diagnostics
if ( CMAKE_CXX_COMPILER_ID STREQUAL "Clang" )
	#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -fcolor-diagnostics" )
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcolor-diagnostics" )
endif()



include_directories( SYSTEM ${Boost_INCLUDE_DIR} )

link_directories   (        ${Boost_LIBRARYDIR}  )
link_directories   (        ${Boost_LIBRARYDIR}  )

add_executable( travis-fiddle main.cpp )

target_link_libraries( travis-fiddle ${Boost_LIBRARIES} )
