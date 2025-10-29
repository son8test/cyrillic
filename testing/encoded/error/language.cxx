#include <son8/cyrillic.hxx>

using namespace son8::cyrillic;

int main( ) try {
    Encoded test{ u"test" };
} catch ( Error code ) {
    if ( code != Error::Language ) return 8;
}
