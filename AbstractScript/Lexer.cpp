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

    void mathOperations(std::vector<std::string> commands){
        for ( int i = 0; i < commands.size(); i++) {
            if (commands[i] == "+") {
                this->createVar(commands[i - 3], std::to_string(Operation::sum(this->serchOnVars(commands[i - 1]), this->serchOnVars(commands[i + 1]))));
            }
            else if (commands[i] == "-") {
                this->createVar(commands[i - 3], std::to_string(Operation::sub(this->serchOnVars(commands[i - 1]), this->serchOnVars(commands[i + 1]))));
            }
            else if (commands[i] == "*") {
                this->createVar(commands[i - 3], std::to_string(Operation::mul(this->serchOnVars(commands[i - 1]), this->serchOnVars(commands[i + 1]))));
            }
            else if (commands[i] == "/") {
                this->createVar(commands[i - 3], std::to_string(Operation::dec(this->serchOnVars(commands[i - 1]), this->serchOnVars(commands[i + 1]))));
            }
            else if (commands[i] == "%") {
                this->createVar(commands[i - 3], std::to_string(Operation::mod(this->serchOnVars(commands[i - 1]), this->serchOnVars(commands[i + 1]))));
            }
            else if (commands[i] == "^") {
                this->createVar(commands[i - 3], std::to_string(Operation::pow(this->serchOnVars(commands[i - 1]), this->serchOnVars(commands[i + 1]))));
            }
        }
    }
    void addVarCommand(std::vector<std::string> commands) {
        if (commands.size() <= 4){
                this->createVar(commands[1], std::to_string(this->serchOnVars(commands[3])));
                return;
            }
        else{
            this->mathOperations(commands);
        }
    }
   
    void tokenAnalis(std::vector<std::vector<std::string>> commands) {
        for (int i = 0; i < all_commands.size(); i++) {
            if (commands[i][0] == "VAR") {
                this->addVarCommand(commands[i]);
            }
            if (commands[i][0] == "IF"){
               std::vector<std::vector<std::string>> ifCommands;
               for(int j = i ; j < all_commands.size();j++){
                    if(commands[j][0] != "ENDIF"){
                        ifCommands.push_back(commands[j]);
                    }
                    else{
                        i = j;
                        break;
                    }
               }
            }
            if(commands[i][0] == "PRINT"){
                std::cout<<this->serchOnVars(commands[i][1]);
            }
            else{
                this->mathOperations(commands[i]);
            }
        }
    }
    void commandsRead(std::vector<std::vector<std::string>> all_commands) {
        this->tokenAnalis(all_commands); 
    }

public:
    Lexer(std::vector<std::vector<std::string>> all_commands, Variable variable) {
        this->all_commands = all_commands;
        this->variable = variable;
        this->commandsRead(this->all_commands);
    }
};