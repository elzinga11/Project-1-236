//
// Created by Steven Elzinga on 9/11/21.
//

#ifndef PROJECT1_STARTER_CODE_UNDEFINEDAUTOMATON_H
#define PROJECT1_STARTER_CODE_UNDEFINEDAUTOMATON_H
#include "Automaton.h"


class UndefinedAutomaton : public Automaton {
public:
	UndefinedAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

	void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_UNDEFINEDAUTOMATON_H
