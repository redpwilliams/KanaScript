#include "Lexer.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <cstring>
#include <cstdint>
#include "lib/utf8.h"

void Lexer::tokenize(std::string& input) {
    std::vector<char> chars(input.begin(), input.end());
    // Get character iterators
    std::string::const_iterator it = input.begin();
    std::string::const_iterator end = input.end();

// Loop using iterators
    while (it != end) {
        std::cout << *it ;
        std::advance(it, 1); // Move the iterator to the next character (multi-byte aware)
    }


    char* str = (char*)input.c_str();    // utf-8 string
    char* str_i = str;                  // string iterator
    char* endl = str+strlen(str)+1;      // end iterator

    do
    {
        uint32_t code = utf8::next(str_i, endl); // get 32 bit code of an utf-8 symbol
        if (code == 0)
            continue;

        unsigned char symbol[5] = {0};
        utf8::append(code, symbol); // copy code to symbol

        std::cout << symbol;
    }
    while ( str_i < endl );
}
