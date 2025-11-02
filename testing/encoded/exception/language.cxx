#include <son8/cyrillic/encoded.hxx>
#include <son8/cyrillic/exception.hxx>

using namespace son8::cyrillic;

int main( ) try {
    Encoded test{ u"тест" };
} catch ( Exception const &e ) {
    return not ( e.code( ) == Error::Language );
}
