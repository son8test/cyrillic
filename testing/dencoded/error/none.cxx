#include <son8/cyrillic/encoded.hxx>
#include <son8/cyrillic/decoded.hxx>
#include <son8/cyrillic/state.hxx>

using namespace son8::cyrillic;

int main( ) {
    this_thread::state( Language::Russian );
    Encoded::In test_ru{u"Русский" };
    Encoded e_ru{ test_ru };
    bool ru = e_ru.out( ) == "Rysskui";
    Decoded d_ru{ e_ru.out( ) };

    this_thread::state( Language::Ukrainian );
    Encoded::In test_ua{u"Українська" };
    Encoded e_ua{ test_ua };
    bool ua = e_ua.out( ) == "Ykrajinsqka";
    Decoded d_ua{ e_ua.out( ) };

    return not ( ru && test_ru == d_ru.out( ) && ua && test_ua == d_ua.out( ) );
}
