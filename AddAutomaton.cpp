//
// Created by Steven Elzinga on 9/11/21.
//

#include "AddAutomaton.h"

void AddAutomaton::S0(const std::string& input){
    if(input[index] == '+'){
        inputRead = 1;
    }
    else{
        Serr();
    }
}
