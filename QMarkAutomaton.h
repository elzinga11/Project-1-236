//
// Created by Steven Elzinga on 9/11/21.
//

#ifndef PROJECT1_STARTER_CODE_Q_MARKAUTOMATON_H
#define PROJECT1_STARTER_CODE_Q_MARKAUTOMATON_H
#include "Automaton.h"


class QMarkAutomaton : public Automaton {
public:
    QMarkAutomaton() : Automaton(TokenType::Q_MARK) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //PROJECT1_STARTER_CODE_Q_MARKAUTOMATON_H
