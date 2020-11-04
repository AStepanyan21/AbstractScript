#include <iostream>
#include "Parser.cpp"
#include "MathOperations.cpp"
#include "Variable.cpp"
#include "ConditionalOperators.cpp"



int main()
{
    Print console;
    std::map<std::string, VariableStructur> variables;
    Variable variable(variables);
    std::string filename = "test.ac";
    Parser parser(filename, console);
}
