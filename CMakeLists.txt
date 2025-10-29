cmake_minimum_required( VERSION 3.14...3.27 )
project( son8test VERSION 0.0.0 LANGUAGES CXX )

set( SON8PROJ son8__${PROJECT_NAME} )

set( testrepo cyrillic )
set( testhash 2be7872048b230ee69be7e2a7cded883e6902078 )

include( FetchContent )

if ( NOT testrepo STREQUAL "REPO" AND NOT testhash STREQUAL "HASH" )
    add_subdirectory( source )
endif( )

enable_testing( )
add_subdirectory( testing )
