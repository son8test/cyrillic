#include <son8/cyrillic/encoded.hxx>
#include <son8/cyrillic/state.hxx>

using namespace son8::cyrillic;

int main( ) {
    this_thread::state( Language::Rysskui );
    Encoded test{ u"" };
}
