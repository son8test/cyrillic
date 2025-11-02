#include <son8/cyrillic/alias.hxx>
#include <son8/cyrillic/encode/return.hxx>
#include <son8/cyrillic/state.hxx>

using namespace son8::cyrillic;

int main( ) {
    this_thread::state( Language::Rysskui );
    StringByte out;
    return not ( Error::None == encode( out, u"тест" ) );
}

