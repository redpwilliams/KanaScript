#include "Lexer.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <iterator>

void Lexer::tokenize(std::string& input) {
    std::vector<char> chars(input.begin(), input.end());
    // Get character iterators
    std::string::const_iterator it = input.begin();
    std::string::const_iterator end = input.end();

// Loop using iterators
    while (it != end) {
        std::cout << *it << std::endl;
        std::advance(it, 1); // Move the iterator to the next character (multi-byte aware)
    }
}
