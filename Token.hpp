#ifndef KANASCRIPT_TOKEN_HPP
#define KANASCRIPT_TOKEN_HPP

enum class TokenType  {
    Keyword,
    Identifier,
    Operator,
    Separator,
    Literal
};

class Token {
private:
    TokenType _type;

public:
    /**
     * Returns the TokenType/Type of Token this object represents.
     * @return This token's TokenType.
     */
    [[nodiscard]] TokenType getType() const;
};
#endif //KANASCRIPT_TOKEN_HPP
