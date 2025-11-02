#include <son8/cyrillic/alias.hxx>
#include <son8/cyrillic/decode/return.hxx>
#include <son8/cyrillic/state.hxx>

using namespace son8::cyrillic;

int main( ) {
    this_thread::state( Language::Ykrajinsqka );
    StringWord out;
    return not ( Error::None == decode( out, "test" ) );
}

