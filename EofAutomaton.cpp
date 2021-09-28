//
// Created by Steven Elzinga on 9/11/21.
//

#include "EofAutomaton.h"

void EofAutomaton::S0(const std::string& input) {
    if (input.size() == 0) {
        inputRead = 1;
    }
    else {
        Serr();
    }
}