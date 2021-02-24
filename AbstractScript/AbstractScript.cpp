#include <iostream>
#include "Parser.h"
#include "Lexer.h"

using varTab = std::vector<std::string>;


int main(int argc, char* argv[])
{
    std::vector<varTab> all_commands;
    char* filename = argv[1];
    std::map<std::string, VariableStructure>* variables = new std::map<std::string, VariableStructure>;
    VariableTable variable(variables);
    Parser parser(filename);
    all_commands = parser.getCommands();
    Lexer lex(all_commands, variable);
    delete variables;
}
