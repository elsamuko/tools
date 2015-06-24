#!/usr/bin/env cppsh

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>

void usage() {
    std::cout << "Usage" << std::endl;
    std::cout << "    tocpp.cpp <file>" << std::endl;
    std::cout << std::endl;
}

std::string fromFile( const std::string& filename ) {
    std::ifstream file( filename.c_str(), std::ifstream::binary );
    return std::string( ( std::istreambuf_iterator<char>( file ) ), ( std::istreambuf_iterator<char>() ) );
}

std::string toValidVarName( const std::string& filename ) {
    std::string varName = filename;
    std::replace_if( varName.begin(), varName.end(), []( char c ) {
        return !std::isalnum( c );
    }, '_' );
    return varName;
}

std::string convert( const std::string& data ) {
    std::stringstream ss;
    int i = 0;
    ss << "{";

    for( const unsigned char & c : data ) {
        if( i % 16 == 0 ) {
            ss << "\n    ";
            // mark offset
            ss << "/* " << std::setfill( '0' ) << std::setw( 8 ) << std::hex << i << " */  ";
        } else if( i % 8 == 0 ) {
            ss << "  ";
        }
        i++;
        ss << "0x";
        ss << std::setfill( '0' ) << std::setw( 2 ) << std::hex << ( int )c << ",";
    }

    // mark end
    ss << "\n    /* " << std::setfill( '0' ) << std::setw( 8 ) << std::hex << i << " */";

    ss << "\n}";
    return ss.str();
}

int main( int argc, char* argv[] ) {

    if( argc != 2 ) {
        usage();
        return 1;
    }

    std::string filename = argv[1];
    std::string var = toValidVarName( filename );
    std::string data = fromFile( filename );

    std::cout << "// " << filename << std::endl;
    std::cout << "const unsigned char " << var << "[] = " << convert( data ) << ";" << std::endl;

    return 0;
}
