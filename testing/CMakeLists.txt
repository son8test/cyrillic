set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

link_libraries( son8::cyrillic )

if ( MSVC )
    add_compile_options( /permissive- )
endif( )

# Add tests ⮟ HERE ⮟ that should NOT use extra warning flags

if ( MSVC )
    add_compile_options( /W4 )
else( )
    add_compile_options( -Wall -Wextra -Wpedantic )
endif( )

# Add tests ⮟ HERE ⮟ that SHOULD use extra warning flags
add_executable( test-encoded-error-language encoded/error/language.cxx )
add_test( NAME test-encoded-error-language COMMAND test-encoded-error-language )
add_executable( test-decoded-error-language decoded/error/language.cxx )
add_test( NAME test-decoded-error-language COMMAND test-decoded-error-language )
add_executable( test-encoded-error-none encoded/error/none.cxx )
add_test( NAME test-encoded-error-none COMMAND test-encoded-error-none )
add_executable( test-decoded-error-none decoded/error/none.cxx )
add_test( NAME test-decoded-error-none COMMAND test-decoded-error-none )
