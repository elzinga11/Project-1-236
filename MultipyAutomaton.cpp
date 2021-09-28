//
// Created by Steven Elzinga on 9/11/21.
//

#include "MultipyAutomaton.h"

void MultiplyAutomaton::S0(const std::string& input) {
    if (input[index] == '*') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}