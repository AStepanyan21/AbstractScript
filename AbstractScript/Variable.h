#ifndef VARIABLE_H
#define VARIABLE_H
#include <iostream>
#include <map>

struct VariableStructure
{
    std::string name;
    std::string value;
    std::string type;
};

class VariableTable {
private:
    std::map<std::string, VariableStructure> variables;

public:
    VariableTable() {

    }
    VariableTable(std::map<std::string, VariableStructure>* variables) {
        this->variables = *variables;
    }

    void set(std::string varName, VariableStructure var) {
        this->variables[varName] = var;
    }

    VariableStructure get(std::string varName) {
        return this->variables[varName];
    }

    void delate(std::string varName) {
        variables.erase(varName);
    }
};
#endif