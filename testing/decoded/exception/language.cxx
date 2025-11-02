#include <son8/cyrillic/decoded.hxx>
#include <son8/cyrillic/exception.hxx>

using namespace son8::cyrillic;

int main( ) try {
    Decoded test{ "test" };
} catch ( Exception const &e ) {
    return not ( Error::Language == e.code( ) );
}
