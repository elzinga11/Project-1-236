//
// Created by Steven Elzinga on 9/11/21.
//

#ifndef PROJECT1_STARTER_CODE_LEFT_PARENAUTOMATON_H
#define PROJECT1_STARTER_CODE_LEFT_PARENAUTOMATON_H
#include "Automaton.h"

class LeftParenAutomaton : public Automaton {
public:
    LeftParenAutomaton() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //PROJECT1_STARTER_CODE_LEFT_PARENAUTOMATON_H
