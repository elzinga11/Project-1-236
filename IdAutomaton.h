//
// Created by Steven Elzinga on 9/11/21.
//

#ifndef PROJECT1_STARTER_CODE_IDAUTOMATON_H
#define PROJECT1_STARTER_CODE_IDAUTOMATON_H
#include "Automaton.h"

class IdAutomaton : public Automaton {
private:
    void S1(const std::string& input);
public:
    IdAutomaton() : Automaton(TokenType::ID) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_IDAUTOMATON_H
