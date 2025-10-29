#include <son8/cyrillic/decoded.hxx>
#include <son8/cyrillic/state.hxx>

using namespace son8::cyrillic;

int main( ) {
    this_thread::state( Language::Ukrainian );
    Decoded test{ "test" };
}

