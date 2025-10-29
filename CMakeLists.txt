cmake_minimum_required( VERSION 3.14...3.27 )
project( son8test VERSION 0.0.0 LANGUAGES CXX )

set( SON8PROJ son8__${PROJECT_NAME} )

set( testrepo cyrillic )
set( testhash 5e91cc6f5faef1972e6e4152ca6f37c3105aca0f )

include( FetchContent )

if ( NOT testrepo STREQUAL "REPO" AND NOT testhash STREQUAL "HASH" )
    add_subdirectory( source )
endif( )

enable_testing( )
add_subdirectory( testing )
