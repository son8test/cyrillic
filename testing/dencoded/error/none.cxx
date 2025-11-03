#include <son8/cyrillic/decode.hxx>
#include <son8/cyrillic/decoded.hxx>
#include <son8/cyrillic/encode.hxx>
#include <son8/cyrillic/encoded.hxx>
#include <son8/cyrillic/error.hxx>
#include <son8/cyrillic/exception.hxx>
#include <son8/cyrillic/state.hxx>
// std
#include <array> // array
#include <functional> // ref
#include <iostream> // cerr
#include <string> // string, to_string
#include <string_view> // string_view
#include <thread> // thread

using namespace son8::cyrillic;

using ArrayDataSet = std::array< Encoded::In, 8 >;
constexpr ArrayDataSet const Data_Set{{
    u"Русский", u"Українська",
    u"Ъъ"     , u"Ґґ",
    u"ЁёЭэЫы" , u"ЇїЄєІі",
    u"ЖЧЩЮЯ"  , u"жчщюя",
}};

using In = Encoded::In;

bool return_func( In );
bool output_func( In );
bool thread_func( In );
bool except_func( In );

std::string message( Language lang, std::string_view name, unsigned idx ) {
    using s = std::string;
    auto langtext = Language::Rysskui == lang ? s { "RU" } : s { "UA" };
    return "[" + langtext + "] false " + std::string{ name } + " with index: " + std::to_string( idx ) + "\n";
}

int main( ) {
    using FailedData = std::string;
    auto test = []( Language lang, FailedData &failed ) {
        this_thread::state( lang );
        auto i = 0u;
        auto failed_message = [&i,lang,&failed]( std::string_view f ) { failed.append( message( lang, f, i ) ); };
        for ( auto data : Data_Set ) {
            if ( not return_func( data ) ) failed_message( "return_func" );
            if ( not output_func( data ) ) failed_message( "output_func" );
            if ( not thread_func( data ) ) failed_message( "thread_func" );
            if ( not except_func( data ) ) failed_message( "except_func" );
            ++i;
        }
    };
    FailedData failedDataRU;
    FailedData failedDataUA;

    std::thread thread_ru{ test, Language::Rysskui, std::ref( failedDataRU ) };
    std::thread thread_ua{ test, Language::Ykrajinsqka, std::ref( failedDataUA ) };

    thread_ru.join( );
    thread_ua.join( );

    if ( failedDataRU.empty( ) && failedDataUA.empty( ) ) return 0;
    std::cerr << failedDataRU << failedDataUA;
    return 1;
}

bool return_func( In in ) {
    Encoded::Data e_out;
    Error error = encode( e_out, in );
    if ( Error::None != error ) return false;
    Decoded::Data d_out;
    error = decode( d_out, e_out );
    if ( Error::None != error ) return false;
    if ( in != d_out ) return false;
    return true;
}
bool output_func( In in ) {
    Error error;
    Encoded encoded = encode( in, error );
    if ( error != Error::None ) return false;
    Decoded decoded = decode( encoded, error );
    if ( error != Error::None ) return false;
    if ( in != decoded ) return false;
    return true;
}
bool thread_func( In in ) {
    Encoded encoded = encode( in );
    if ( this_thread::state_error( ) != Error::None ) return false;
    Decoded decoded = decode( encoded );
    if ( this_thread::state_error( ) != Error::None ) return false;
    if ( in != decoded ) return false;
    return true;
}
bool except_func( In in ) try {
    Encoded encoded{ in };
    Decoded decoded{ encoded };
    if ( in != decoded ) return false;
    return true;
} catch ( Exception const &e ) {
    return false;
}

