#include <son8/cyrillic/alias.hxx>
#include <son8/cyrillic/error.hxx>
#include <son8/cyrillic/encode/return.hxx>

using namespace son8::cyrillic;

int main( ) {
    StringByte out;
    return not ( Error::Language == encode( out, u"тест" ) );
}
