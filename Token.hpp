#ifndef KANASCRIPT_TOKEN_HPP
#define KANASCRIPT_TOKEN_HPP

#include <iostream>
#include <string>
#include <utility>

struct Token {
    enum class TokenType {
        KEYWORD,
        STRING,
        SYMBOL,
    };

    TokenType type;
    std::string value;

    Token(TokenType type, std::string  value) :
            type(type), value(std::move(value)) {}
};

void printToken(const Token& t);

#endif //KANASCRIPT_TOKEN_HPP
