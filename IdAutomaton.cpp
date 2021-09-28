//
// Created by Steven Elzinga on 9/11/21.
//

#include "IdAutomaton.h"


void IdAutomaton::S0(const std::string& input) {
    if (isalpha(input[inputRead])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IdAutomaton::S1(const std::string& input) {
    if ((isdigit(input[index]) || isalpha(input[index])) && !isspace((input[index])) && !input[index] == '\0') {
        inputRead++;
        index++;
        S1(input);
    }
    else if (isspace((input[inputRead])) || input[inputRead] == '\0') {
        
    }
    else if (!(isdigit(input[index]) || isalpha(input[index]))) {}
    else {
        Serr();
    }
}