#include <iostream>
#include "Parser.cpp"
#include "Print.cpp"
#include "Lexer.cpp"


int main()
{
    Print console;
    std::vector<std::vector<std::string>> all_commands;
    std::string filename = "test.ac";
    std::map<std::string, VariableStructur>* variables = new std::map<std::string, VariableStructur>;
    Variable variable(variables);
    Parser parser(filename);
    all_commands = parser.getCommands();
    Lexer lex(all_commands, variable);
    delete variables;
}
