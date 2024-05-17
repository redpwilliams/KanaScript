#include <iostream>
#include <fstream>
#include <string>
#include "Lexer.hpp"

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

    Lexer lex;
    std::string line;
    while (getline(sourceFile, line)) {
       lex.tokenize(line);
    }
    sourceFile.close();
    return 0;
}

// TODO - Add a ks config file in yaml that specifies settings
// One setting might be to clarify what counts as an indent?