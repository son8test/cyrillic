cmake_minimum_required( VERSION 3.14...3.27 )
project( son8test VERSION 0.0.0 LANGUAGES CXX )

set( SON8PROJ son8__${PROJECT_NAME} )

set( TESTUSER soneight CACHE STRING "FetchContent user andor organization" )
set( TESTREPO cyrillic CACHE STRING "FetchContent GIT_REPOSITORY project!" )
set( TESTHASH main     CACHE STRING "FetchContent GIT_TAG hash andor tag!" )

include( FetchContent )

if ( NOT ${TESTREPO} STREQUAL "testrepo" )
    add_subdirectory( source )
endif( )

enable_testing( )
add_subdirectory( testing )
