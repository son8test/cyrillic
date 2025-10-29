#include <son8/cyrillic/encoded.hxx>
#include <son8/cyrillic/exception.hxx>

using namespace son8::cyrillic;

int main( ) try {
    Encoded test{ u"test" };
} catch ( Exception const &e ) {
    if ( e.code( ) != Error::Language ) return 8;
}
