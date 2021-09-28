//
// Created by Steven Elzinga on 9/11/21.
//

#include "StringAutomaton.h"
#include <iostream>

void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input) {
    if (input[index] != '\'' && input[index] != '\0' && input[index] != '\n') {
        inputRead++;
        index++;
        S1(input);
    }
    else if (input[index] == '\'') {
        if (input[index + 1] == '\'') {
            inputRead += 2;
            index += 2;
            S1(input);
        }
        else {
            inputRead++;
        }
    }
    else if (input[index] == '\n') {
        newLines++;
        inputRead++;
        index++;
        S1(input);

    }
    else if (input[index] == '\0') {
        std::cout << "here";
        inputRead = -1;
    }
    else {
        Serr();
    }
}
