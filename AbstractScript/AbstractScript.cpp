#include <iostream>
#include "Parser.cpp"
#include "MathOperations.cpp"
#include "Variable.cpp"
#include "ConditionalOperators.cpp"


int main()
{
    Print console;
    std::vector<std::vector<std::string>> all_commands;
    std::map<std::string, VariableStructur> variables;
    Variable variable(variables);
    std::string filename = "test.ac";
    Parser parser(filename, console);
    all_commands = parser.getCommands();
    for(int i = 0; i < all_commands.size(); i++){
        for( int j = 0; j< all_commands[i].size(); j++){
            std::cout<<all_commands[i][j]<<std::endl;
        }
    }
}
