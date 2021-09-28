//
// Created by Steven Elzinga on 9/11/21.
//

#ifndef PROJECT1_STARTER_CODE_EOFAUTOMATON_H
#define PROJECT1_STARTER_CODE_EOFAUTOMATON_H

#include "Automaton.h"

class EofAutomaton : public Automaton {
public:
	EofAutomaton() : Automaton(TokenType::EEOF) {}  // Call the base constructor

	void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_EOFAUTOMATON_H
