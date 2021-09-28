#include "Lexer.h"
#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
    Lexer* lexer = new Lexer();
    std::ifstream myFile;
    myFile.open("test.txt");
    std::string test((std::istreambuf_iterator<char>(myFile)), std::istreambuf_iterator<char>());
    // TODOs
    lexer -> Run(test);

    delete lexer;

    return 0;
}