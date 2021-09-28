//
// Created by Steven Elzinga on 9/11/21.
//

#include "FactsAutomaton.h"


void FactsAutomaton::S0(const std::string& input) {
    if (input[index] == 'F') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void FactsAutomaton::S1(const std::string& input) {
    if (input[index] == 'a') {
        inputRead++;
        S2(input);
    }
    else {
        Serr();
    }
}


void FactsAutomaton::S2(const std::string& input) {
    if (input[index] == 'c') {
        inputRead++;
        S3(input);
    }
    else {
        Serr();
    }
}


void FactsAutomaton::S3(const std::string& input) {
    if (input[index] == 't') {
        inputRead++;
        S4(input);
    }
    else {
        Serr();
    }
}


void FactsAutomaton::S4(const std::string& input) {
    if (input[index] == 's') {
        inputRead++;
    }
    else {
        Serr();
    }
}