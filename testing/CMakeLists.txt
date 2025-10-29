set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

link_libraries( son8::cyrillic )

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
