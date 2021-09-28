//
// Created by Steven Elzinga on 9/11/21.
//

#include "CommentAutomaton.h"
#include <iostream>

void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S4(input);
    }
    else if (input[index] == '\0') {
    }
    else if (input[index] == '\n') {
    }
    else {
        inputRead++;
        index++;
        S3(input);
    }
}

void CommentAutomaton::S2(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
    }
    else if (input[index] == '\0') {
        inputRead = -1;
    }
    else {
        S4(input);
    }
}

void CommentAutomaton::S3(const std::string& input) {
    if (input[index] == '\0' || input[index] == '\n') {
    }
    else {
        inputRead++;
        index++;
        S3(input);
    }
}

void CommentAutomaton::S4(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '\0') {
        inputRead = -1;
    }
    else if (input[index] == '\n') {
        newLines++;
        inputRead++;
        index++;
        S4(input);
    }
    else {
        inputRead++;
        index++;
        S4(input);
    }
}
