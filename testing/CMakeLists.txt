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

# exception
add_executable( testing-encoded-exception-language encoded/exception/language.cxx )
add_test( NAME test-encoded-exception-language COMMAND testing-encoded-exception-language )
add_executable( testing-decoded-exception-language decoded/exception/language.cxx )
add_test( NAME test-decoded-exception-language COMMAND testing-decoded-exception-language )
add_executable( testing-encoded-exception-none encoded/exception/none.cxx )
add_test( NAME test-encoded-exception-none COMMAND testing-encoded-exception-none )
add_executable( testing-decoded-exception-none decoded/exception/none.cxx )
add_test( NAME test-decoded-exception-none COMMAND testing-decoded-exception-none )
# error
# -- language
add_executable( testing-encoded-error-language encoded/error/language.cxx )
add_test( NAME test-encoded-error-language COMMAND testing-encoded-error-language )
add_executable( testing-decoded-error-language decoded/error/language.cxx )
add_test( NAME test-decoded-error-language COMMAND testing-decoded-error-language )
# -- none
add_executable( testing-encoded-error-none encoded/error/none.cxx )
add_test( NAME test-encoded-error-none COMMAND testing-encoded-error-none )
add_executable( testing-decoded-error-none decoded/error/none.cxx )
add_test( NAME test-decoded-error-none COMMAND testing-decoded-error-none )
# -- invalid word (encoded)
add_executable( testing-encoded-error-invalid_word encoded/error/invalid_word.cxx )
add_test( NAME test-encoded-error-invalid_word COMMAND testing-encoded-error-invalid_word )
# -- invalid byte (decoded) TODO
# dencoded
add_executable( testing-dencoded-error-none dencoded/error/none.cxx )
add_test( NAME test-dencoded-error-none COMMAND testing-dencoded-error-none )
# filehack
add_executable( test-filehack filehack.cxx )
add_test( NAME test-filehack COMMAND test-filehack )
