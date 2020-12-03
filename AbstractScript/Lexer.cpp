#include <iostream>
#include <vector>
#include <sstream> 
#include <string>
#include "MathOperations.cpp"
#include "Variable.cpp"


class Lexer {
private:
    std::vector<std::vector<std::string>> all_commands;
    Variable variable;

    float toNumber(std::string token){
        std::stringstream geek(token);
        float num = 0;
        geek >> num;
        return num;
    }

    float serchOnVars(std::string token){
        if(variable.get(token).name == ""){
            return this->toNumber(token);
        }else{
            return this->toNumber(variable.get(token).value);
        }
    }

    std::string setVarType(std::string value){
        return "number";
    }

    void createVar(std::string varName, std::string varValue){
        VariableStructur var;
        var.name = varName;
        var.value = varValue;
        var.type = this->setVarType(var.value);
        this->variable.set(var.name, var);
    }

    void addVarCommand(std::vector<std::string> commands) {
        if (commands.size() > 4) {
            if (commands[4] == "+") {
                this->createVar(commands[1], std::to_string(Operation::sum(this->serchOnVars(commands[3]), this->serchOnVars(commands[5]))));
            }
            else if (commands[4] == "-") {
                this->createVar(commands[1], std::to_string(Operation::sub(this->serchOnVars(commands[3]), this->serchOnVars(commands[5]))));
            }
            else if (commands[4] == "*") {
                this->createVar(commands[1], std::to_string(Operation::mul(this->serchOnVars(commands[3]), this->serchOnVars(commands[5]))));
            }
            else if (commands[4] == "/") {
                this->createVar(commands[1], std::to_string(Operation::dec(this->serchOnVars(commands[3]), this->serchOnVars(commands[5]))));
            }
            else if (commands[4] == "/") {
                this->createVar(commands[1], std::to_string(Operation::mod(this->serchOnVars(commands[3]), this->serchOnVars(commands[5]))));
            }
            else if (commands[4] == "^") {
                this->createVar(commands[1], std::to_string(Operation::pow(this->serchOnVars(commands[3]), this->serchOnVars(commands[5]))));
            }
        }
       else{
           this->createVar(commands[1], std::to_string(this->serchOnVars(commands[3])));
            
       }
    }
   
    void tokenAnalis(std::vector<std::string> commands) {
        if (commands[0] == "VAR") {
            this->addVarCommand(commands);
        }
        if(commands[0] == "PRINT"){
            std::cout<<this->serchOnVars(commands[1]);
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