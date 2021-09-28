#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "AddAutomaton.h"
#include "CommentAutomaton.h"
#include "UndefinedAutomaton.h"
#include "FactsAutomaton.h"
#include "CommaAutomaton.h"
#include "EofAutomaton.h"
#include "IdAutomaton.h"
#include "LeftParenAutomaton.h"
#include "MultipyAutomaton.h"
#include "PeriodAutomaton.h"
#include "QMarkAutomaton.h"
#include "QueriesAutomaton.h"
#include "RightParenAutomaton.h"
#include "RulesAutomaton.h"
#include "SchemesAutomaton.h"
#include "StringAutomaton.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>

using namespace std;

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {
    tokens = {};
    automata = {};
    int inputRead = 0;
    AddAutomaton* addAutomaton = new AddAutomaton;
    ColonAutomaton* colonAuto = new ColonAutomaton;
    ColonDashAutomaton* colonDashAuto = new ColonDashAutomaton;
    CommaAutomaton* commaAutomaton = new CommaAutomaton;
    CommentAutomaton* commentAutomaton = new CommentAutomaton;
    EofAutomaton* eAutomaton = new EofAutomaton;
    FactsAutomaton* factsAutomaton = new FactsAutomaton;
    IdAutomaton* idAutomaton = new IdAutomaton;
    MultiplyAutomaton* multiplyAutomaton = new MultiplyAutomaton;
    PeriodAutomaton* periodAutomaton = new PeriodAutomaton;
    QMarkAutomaton* qMarkAutomaton = new QMarkAutomaton;
    QueriesAutomaton* queriesAutomaton = new QueriesAutomaton;
    RightParenAutomaton* rightParenAutomaton = new RightParenAutomaton;
    RulesAutomaton* rulesAutomaton = new RulesAutomaton;
    SchemesAutomaton* schemesAutomaton = new SchemesAutomaton;
    StringAutomaton* stringAutomaton = new StringAutomaton;
    UndefinedAutomaton* undefinedAutomaton = new UndefinedAutomaton;
    LeftParenAutomaton* leftParenAutomaton = new LeftParenAutomaton;

    Automaton* maxAutomaton = colonAuto;
    automata.push_back(schemesAutomaton);
    automata.push_back(factsAutomaton);
    automata.push_back(rulesAutomaton);
    automata.push_back(queriesAutomaton);
    automata.push_back(addAutomaton);
    automata.push_back(commaAutomaton);
    automata.push_back(colonAuto);
    automata.push_back(colonDashAuto);
    automata.push_back(periodAutomaton);
    automata.push_back(multiplyAutomaton);
    automata.push_back(qMarkAutomaton);
    automata.push_back(stringAutomaton);
    automata.push_back(leftParenAutomaton);
    automata.push_back(rightParenAutomaton);
    automata.push_back(commentAutomaton);
    automata.push_back(eAutomaton);
    automata.push_back(idAutomaton);

    int inputStart = 0;
    bool addEof = true;
    while (input.size() > 0) {
        bool whiteSpace = true;
        int deleteWhitespace = 0;
        while (whiteSpace) {
            if (isspace(input[inputStart])) {
                if (input[inputStart] == '\n') {
                    lineNumber++;
                }
                deleteWhitespace++;
                inputStart++;
            }
            else {
                input.erase(0, deleteWhitespace);
                whiteSpace = false;
                inputStart = 0;
            }
        }
        int maxRead = 0;
        //        for inputRead = automaton.Start(input)
        for (unsigned int i = 0; i < automata.size(); i++) {
            inputRead = automata[i]->Start(input);
            if (inputRead == -1) {
                maxRead = inputRead;
                maxAutomaton = automata[i];
            }
            if (inputRead > maxRead&& maxRead != -1) {
                maxRead = inputRead;
                maxAutomaton = automata[i];
            }
        }
        if (maxRead > 0) {
            if (maxAutomaton == eAutomaton) {
                addEof = false;
            }
            Token* newToken = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
            input.erase(0, maxRead);
        }
        else {
            if (maxRead == -1) {
                maxRead = 1;
                Token* newToken = undefinedAutomaton->CreateToken(input.substr(0, input.size()), lineNumber);
                lineNumber += maxAutomaton->NewLinesRead();
                tokens.push_back(newToken);
                input.clear();
                break;
            }
            else {
                maxRead = 1;
                Token* newToken = undefinedAutomaton->CreateToken(input.substr(0, 1), lineNumber);
                tokens.push_back(newToken);
                input.erase(0, 1);
            }

        }
    }
    if (addEof) {
        Token* newToken = eAutomaton->CreateToken("", lineNumber);
        tokens.push_back(newToken);
    }


    for (unsigned i = 0; i < tokens.size(); i++) {
        std::cout << "(" + tokens[i]->toString() + ",\"" + tokens[i]->description() + "\"," + tokens[i]->lineNumber() + ")\n";
    }
    cout << "Total Tokens = " + std::to_string(tokens.size());
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    /*
    set lineNumber to 1
    // While there are more characters to tokenize
    loop while input.size() > 0 {
        set maxRead to 0
        set maxAutomaton to the first automaton in automata

        // TODO: you need to handle whitespace inbetween tokens

        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        foreach automaton in automata {
            inputRead = automaton.Start(input)
            if (inputRead > maxRead) {
                set maxRead to inputRead
                set maxAutomaton to automaton
            }
        }
        // Here is the "Max" part of the algorithm
        if maxRead > 0 {
            set newToken to maxAutomaton.CreateToken(...)
                increment lineNumber by maxAutomaton.NewLinesRead()
                add newToken to collection of all tokens
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
            set maxRead to 1
                set newToken to a  new undefined Token
                (with first character of input)
                add newToken to collection of all tokens
        }
        // Update `input` by removing characters read to create Token
        remove maxRead characters from input
    }
    add end of file token to all tokens
    */
}
