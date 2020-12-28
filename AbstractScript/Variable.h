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
    VariableTable(const std::map<std::string, VariableStructure>* variables) {
        this->variables = *variables;
    }

    void set(const std::string varName, const VariableStructure var) {
        this->variables[varName] = var;
    }

    VariableStructure get(const std::string varName) {
        return this->variables[varName];
    }

    void delate( const std::string varName) {
        variables.erase(varName);
    }
};
#endif