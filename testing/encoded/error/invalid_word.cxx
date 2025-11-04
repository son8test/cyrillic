#include <son8/cyrillic/alias.hxx>
#include <son8/cyrillic/encode/return.hxx>
#include <son8/cyrillic/error.hxx>
#include <son8/cyrillic/state.hxx>
// std
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace son8::cyrillic;

std::vector< StringWordView > const Invalid_Words {
    u"Pусский", u"Укpаїнська", // en 'P', 'р'
    u"Aлкаш"  , u"Зaдолиз",    // en 'A' , 'a'
    u"U"      , u"Повiя",      // en 'U', 'і'
    u"Xуйло"  , u"Оxрініти"    // en 'X', 'x'
};

template< Language T >
struct FailedData {
    std::string data;
    static constexpr Language const lang = T;
};
using FailedDataRU = FailedData< Language::Rysskui >;
using FailedDataUA = FailedData< Language::Ykrajinsqka >;

int main( ) {
    auto test = []( auto &fail ) {
        this_thread::state( fail.lang );
        StringByte unused;
        unsigned idx{ 0 };
        for ( auto iw : Invalid_Words ) {
            if ( encode( unused, iw ) != Error::InvalidWord ) fail.data.append( "index: " + std::to_string( idx ) + "\n" );
            ++idx;
        }
    };

    FailedDataRU failedRU;
    FailedDataUA failedUA;

    test( failedRU );
    test( failedUA );

    if ( not failedRU.data.empty( ) or not failedUA.data.empty( ) ) {
        std::cerr << "Failed RU:\n" << failedRU.data << "Failed UA:\n" << failedUA.data << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
