#include <son8/cyrillic/alias.hxx>
#include <son8/cyrillic/error.hxx>
#include <son8/cyrillic/decode/return.hxx>

using namespace son8::cyrillic;

int main( ) {
    StringWord out;
    return not ( Error::Language == decode( out, "test" ) );
}
