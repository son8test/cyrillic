#include <son8/cyrillic.hxx>

using namespace son8::cyrillic;

int main( ) try {
    Decoded test{ "test" };
} catch ( Error code ) {
    if ( code != Error::Language ) return 8;
}
