#include <iostream>
#include <vector>
#include <string>
#include "MathOperations.cpp"
#include "Variable.cpp"


class Lexer {
private:
    std::vector<std::vector<std::string>> all_commands;
    Variable variable;

    int toInt(std::string token){
        return std::stoi(token);
    }

    std::string setVarType(std::string value){
        return value;
    }

    void createVar(std::string varName, std::string varValue){
        VariableStructur var;
        var.name = varName;
        var.value = varValue;
        var.type = setVarType(var.value);
        this->variable.set(var.name, var);
    }

    void addVarCommand(std::vector<std::string> commands) {
        if (commands.size() > 4) {
            if (commands[4] == "+") {
                this->createVar(commands[1], std::to_string(Operation::sum(toInt(commands[3]), this->toInt(commands[5]))));
            }
            else if (commands[4] == "-") {
                this->createVar(commands[1], std::to_string(Operation::sub(toInt(commands[3]), this->toInt(commands[5]))));
            }
            else if (commands[4] == "*") {
                this->createVar(commands[1], std::to_string(Operation::mul(toInt(commands[3]), this->toInt(commands[5]))));
            }
            else if (commands[4] == "/") {
                this->createVar(commands[1], std::to_string(Operation::dec(toInt(commands[3]), this->toInt(commands[5]))));
            }
            else if (commands[4] == "/") {
                this->createVar(commands[1], std::to_string(Operation::mod(toInt(commands[3]), this->toInt(commands[5]))));
            }
            else if (commands[4] == "^") {
                this->createVar(commands[1], std::to_string(Operation::pow(toInt(commands[3]), this->toInt(commands[5]))));
            }
        }
       else{
            this->createVar(commands[1], commands[3]);
            
       }
    }
   
    void tokenAnalis(std::vector<std::string> commands) {
        if (commands[0] == "VAR") {
            addVarCommand(commands);
        }
        
    }
    void commandsRead(std::vector<std::vector<std::string>> all_commands) {
        for (int i = 0; i < all_commands.size(); i++) {
            this->tokenAnalis(all_commands[i]);
        }
    }

public:
    Lexer(std::vector<std::vector<std::string>> all_commands, Variable variable) {
        this->all_commands = all_commands;
        this->variable = variable;
        this->commandsRead(this->all_commands);
    }
};