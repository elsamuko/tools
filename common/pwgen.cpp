#!/usr/bin/env cppsh

#include <random>
#include <iostream>
#include <vector>

int main() {

    std::vector<char> special_a = { '[', '{', '<', '!', '(', '*', '$', '_', '+' };
    std::vector<char> special_b = { ']', '}', '>', '?', ')', '*', '$', '_', '-' };

    std::vector<char> numbers = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    std::vector<char> k_upper = { 'Q', 'W', 'R', 'T', 'Y', 'P',
                                  'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
                                  'Z', 'X', 'C', 'V', 'B', 'N', 'M'
                                };

    std::vector<char> vocals = { 'a', 'e', 'i', 'o', 'u' };

    std::vector<char> k_lower = { 'q', 'w', 'r', 't', 'y', 'p',
                                  's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
                                  'z', 'x', 'c', 'v', 'b', 'n', 'm'
                                };


    // mt has a good distribution, but is not cryptographically secure
    std::random_device rd;
    std::mt19937 gen( rd() );

    std::uniform_int_distribution<> dis_s( 0, special_a.size() - 1 );
    std::uniform_int_distribution<> dis_n( 0, numbers.size() - 1 );
    std::uniform_int_distribution<> dis_u( 0, k_upper.size() - 1 );
    std::uniform_int_distribution<> dis_v( 0, vocals.size() - 1 );
    std::uniform_int_distribution<> dis_l( 0, k_lower.size() - 1 );

    auto genpw = [&]() {

        int i_s = dis_s( gen );
        std::cout << special_a[i_s];

        int count = 1;

        while( count-- ) {
            char n = numbers[dis_n( gen )];
            char u = k_upper[dis_u( gen )];
            char v = vocals[dis_v( gen )];
            char l = k_lower[dis_l( gen )];
            char v2 = vocals[dis_v( gen )];
            char l2 = k_lower[dis_l( gen )];
            char v3 = vocals[dis_v( gen )];
            char l3 = k_lower[dis_l( gen )];

            std::cout << u << v << l << v2 << l2 << v3 << l3 << n;
        }

        std::cout << special_b[i_s];

        std::cout << std::endl;
    };

    genpw();

    return 0;
}
