//
// Created by Steven Elzinga on 9/11/21.
//

#ifndef PROJECT1_STARTER_CODE_MULTIPYAUTOMATON_H
#define PROJECT1_STARTER_CODE_MULTIPYAUTOMATON_H
#include "Automaton.h"

class MultiplyAutomaton : public Automaton {
public:
    MultiplyAutomaton() : Automaton(TokenType::MULTIPLY) {}  // Call the base constructor

    void S0(const std::string& input);
};



#endif //PROJECT1_STARTER_CODE_MULTIPYAUTOMATON_H
