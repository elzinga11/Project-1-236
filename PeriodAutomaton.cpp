//
// Created by Steven Elzinga on 9/11/21.
//

#include "PeriodAutomaton.h"


void PeriodAutomaton::S0(const std::string& input) {
    if (input[index] == '.') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}