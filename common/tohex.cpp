#!/usr/bin/env cppsh

#include <iostream>
#include <string>
#include <iomanip>

void usage() {
    std::cout << "Usage" << std::endl;
    std::cout << "    tohex.cpp 0x12" << std::endl;
    std::cout << "    tohex.cpp 1234" << std::endl;
    std::cout << std::endl;
}

int main( int argc, char* argv[] ) {

    if( argc != 2 ) {
        usage();
        return 1;
    }

    std::string arg( argv[1] );

    long l = std::stol( arg, nullptr, 0 );

    std::cout << l << " : 0x" << std::hex << l << std::endl;

    return 0;
}

