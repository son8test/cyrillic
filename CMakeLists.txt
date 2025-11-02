cmake_minimum_required( VERSION 3.14...3.27 )
project( son8test VERSION 0.0.0 LANGUAGES CXX )

set( SON8PROJ son8__${PROJECT_NAME} )

set( testrepo cyrillic )
set( testhash 6121a5f16b5e168a488af2690be849ea689de13f )

include( FetchContent )

if ( NOT testrepo STREQUAL "REPO" AND NOT testhash STREQUAL "HASH" )
    add_subdirectory( source )
endif( )

enable_testing( )
add_subdirectory( testing )
