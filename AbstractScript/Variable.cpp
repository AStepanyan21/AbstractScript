#include <iostream>
#include <map>

struct VariableStructur
{
    std::string name;
    std::string value;
    std::string type;
};

class Variable {
private:
    std::map<std::string, VariableStructur> variables;

public:
    Variable() {

    }
    Variable(std::map<std::string, VariableStructur> variables) {
        this->variables = variables;
    }

    void set(std::string varName, VariableStructur var) {
        this->variables[varName] = var;
    }

    VariableStructur get(std::string varName) {
        return this->variables[varName];
    }

    void delate(std::string varName) {
        variables.erase(varName);
    }
};