#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum TokenType {
    COLON,
    COLON_DASH,
    ADD,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    EEOF
};

class Token
{
private:
    TokenType myType;
    std::string myDescription;
    int myLineNumber;

public:
    Token(TokenType type, std::string description, int line);
    std::string toString();
    std::string description();
    std::string lineNumber();
    
    // TODO: add other needed methods
};

#endif // TOKEN_H

