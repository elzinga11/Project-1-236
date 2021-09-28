#include "Token.h"
#include <iostream>
#include <string>


Token::Token(TokenType type, std::string description, int line) {
    myType = type;
    myDescription = description;
    myLineNumber = line;
}

std::string Token::toString() {
    switch (myType) {
    case COLON: return "COLON"; break;
    case COLON_DASH: return "COLON_DASH"; break;
    case ADD: return "ADD"; break;
    case COMMA: return "COMMA"; break;
    case PERIOD: return "PERIOD"; break;
    case Q_MARK: return "Q_MARK"; break;
    case LEFT_PAREN: return "LEFT_PAREN"; break;
    case RIGHT_PAREN: return "RIGHT_PAREN"; break;
    case MULTIPLY: return "MULTIPLY"; break;
    case SCHEMES: return "SCHEMES"; break;
    case FACTS: return "FACTS"; break;
    case RULES: return "RULES"; break;
    case QUERIES: return "QUERIES"; break;
    case ID: return "ID"; break; 
    case STRING: return "STRING"; break;
    case COMMENT: return "COMMENT"; break;
    case UNDEFINED: return "UNDEFINED"; break;
    case EEOF: return "EOF"; break;
    }
}

std::string Token::description() {
    return myDescription;
}

std::string Token::lineNumber() {
    return std::to_string(myLineNumber);
}