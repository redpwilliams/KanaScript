#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdint>
#include "Lexer.hpp"
#include <io.h>
#include <fcntl.h>
#include "lib/utf8/checked.h"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        std::cerr << "Usage: kanascript <source_file>" << std::endl;
        return 1;
    }

    std::ifstream sourceFile(argv[1]);
    if (!sourceFile.is_open()) {
        std::cerr << "Error: Could not open source file: " << argv[1] << std::endl;
        return 1;
    }

//    _setmode(_fileno(stdout), _O_U16TEXT);

    std::string line;
    while (getline(sourceFile, line)) {
       Lexer::tokenize(line);
    }
    sourceFile.close();

    std::string ex{"書く"};
    Token t(Token::TokenType::KEYWORD, ex.substr(0, 2));
    printToken(t);

    std::cout << "\nIs valid? " << utf8::is_valid(ex) << std::endl;

    char* str = (char*)ex.c_str();    // utf-8 string
    char* str_i = str;                  // string iterator
    char* end = str+strlen(str)+1;      // end iterator

    do
    {
        uint32_t code = utf8::next(str_i, end); // get 32 bit code of an utf-8 symbol
        if (code == 0)
            continue;

        unsigned char symbol[5] = {0};
        utf8::append(code, symbol); // copy code to symbol

        std::cout << symbol << std::endl;
        // ... do something with symbol
    }
    while ( str_i < end );

}

// TODO - Add a ks config file in yaml that specifies settings
// One setting might be to clarify what counts as an indent?