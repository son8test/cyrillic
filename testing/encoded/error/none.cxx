#include <son8/cyrillic/encoded.hxx>
#include <son8/cyrillic/state.hxx>

#include <cassert>

using namespace son8::cyrillic;

int main( ) {
    this_thread::state( Language::Russian );
    Encoded test{ u"тест" };
    return not ( test.out( ) == "test" );
}

