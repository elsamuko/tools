#!/usr/bin/env cppsh

#include <iostream>
#include <string>
#include <iomanip>
#include <bitset>

void usage() {
    std::cout << "Usage" << std::endl;
    std::cout << "    tohex.cpp 0x123" << std::endl;
    std::cout << "    tohex.cpp 0b101" << std::endl;
    std::cout << "    tohex.cpp 12345" << std::endl;
    std::cout << std::endl;
    exit( 0 );
}

unsigned long long parse( const std::string arg ) {
    unsigned long long parsed = 0;
    std::string prefix = arg.substr( 0, 2 );

    try {
        if( prefix == "0b" || prefix == "0B" ) {
            parsed = std::stoull( arg.substr( 2 ), nullptr, 2 );
        } else {
            parsed = std::stoull( arg, nullptr, 0 );
        }
    } catch( const std::exception& e ) {
        std::cout << "Could not parse [" << arg << "]" << std::endl;
        exit( 0 );
    }

    return parsed;
}

size_t widthOf( const unsigned long long& parsed ) {
    size_t width = 8;

    if( parsed > 255ull ) {
        width = 16;
    }

    if( parsed > 65535ull ) {
        width = 32;
    }

    if( parsed > 4294967295ull ) {
        width = 64;
    }

    return width;
}

void printDEC( const unsigned long long& parsed, const size_t& width ) {
    std::cout << "DEC   ";
    std::cout.fill( ' ' );
    std::cout.width( width );
    std::cout << parsed << std::endl;
}

void printHEX( const unsigned long long& parsed, const size_t& width ) {
    std::stringstream hex;
    hex << "0x" << std::hex << parsed;
    std::cout << "HEX ";
    std::cout.fill( ' ' );
    std::cout.width( width + 2 );
    std::cout << hex.str() << std::endl;
}

void printBIN( const unsigned long long& parsed, const size_t& width ) {
    switch( width ) {
        case 8:
            std::cout << "BIN 0b" << std::bitset<8>( parsed ) << std::endl;
            break;

        case 16:
            std::cout << "BIN 0b" << std::bitset<16>( parsed ) << std::endl;
            break;

        case 32:
            std::cout << "BIN 0b" << std::bitset<32>( parsed ) << std::endl;
            break;

        case 64:
            std::cout << "BIN 0b" << std::bitset<64>( parsed ) << std::endl;
            break;

        default:
            break;
    }
}

int main( int argc, char* argv[] ) {

    if( argc != 2 ) {
        usage();
    }

    std::string arg( argv[1] );

    if( arg[0] == '-' ) {
        std::cout << "Can parse only unsigned integers" << std::endl;
        return 0;
    }

    unsigned long long parsed = parse( arg );
    size_t width = widthOf( parsed );

    printDEC( parsed, width );
    printHEX( parsed, width );
    printBIN( parsed, width );

    return 0;
}
