#include <iostream>
#include "Parser.h"
#include "Lexer.h"


int main(int argc, char* argv[])
{
    std::vector<varTab> all_commands;
    std::string filename = argv[1];
    std::map<std::string, VariableStructure>* variables = new std::map<std::string, VariableStructure>;
    VariableTable variable(variables);
    Parser parser(filename);
    all_commands = parser.getCommands();
    Lexer lex(all_commands, variable);
    delete variables;
}
