//
// Created by redexe on 5/15/2024.
//

#ifndef KANASCRIPT_LEXER_HPP
#define KANASCRIPT_LEXER_HPP

#include <vector>
#include "Token.hpp"
#include <string>

class Lexer
{
private:
    std::vector<Token> _tokens;
public:
    static void tokenize(std::string& input);
};


#endif //KANASCRIPT_LEXER_HPP
