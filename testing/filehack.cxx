#include <son8/cyrillic.hxx>

#include <iostream>
#include <fstream>
#include <type_traits>
#include <stdexcept>

namespace app {
    using namespace son8::cyrillic;
    using WordType = StringWord::value_type;
    using BufIter = std::istreambuf_iterator< WordType >;
    using word_ifstream = std::basic_ifstream< WordType >;
    using byte_ofstream = std::ofstream;

    constexpr bool Input = true;
    constexpr bool Output = false;

}

template< bool IsInput >
auto file( std::string name ) {
    using FileType = std::conditional_t< IsInput
        , app::word_ifstream
        , app::byte_ofstream >;
    FileType f{ name, std::ios::binary };
    if ( not f ) throw std::runtime_error{ "could not open " + name + " file" };
    return f;
}

int main( ) {
    app::this_thread::state( app::Language::Ukrainian );

    std::string bytes{ "ПривітСвіт" };
    std::string name{ "filehack.txt" };

    auto output = file< app::Output >( name );

    output << bytes;
    output.close( );

    auto input = file< app::Input >( name );
    app::StringWord words{
        app::BufIter( input ),
        app::BufIter( )
    };
    input.close( );

    app::Encoded encoded{ words };
    std::cout << encoded.ref( );
    return not ( encoded.ref( ) == "PruvjutSvjut" );
}
