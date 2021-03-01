#ifndef LEXER_H
#define LEXER_H
#include <iostream>
#include <vector>
#include <sstream> 
#include <string>
#include "ConditionalOperations.h"
#include "MathOperations.h"
#include "Print.h"
#include "Variable.h"


using varTab = std::vector<std::string>;


class Lexer {
private:
    std::vector<varTab> all_commands;
    VariableTable variable;
    std::string intermediate_code;

    float toNumber(std::string token){
        std::stringstream geek(token);
        float num = 0;
        geek >> num;
        return num;
    }

    std::string serchOnVars(std::string token){
        if (variable.get(token).name == ""){
            return token;
        } else {
            if(variable.get(token).type == "number"){
                return variable.get(token).value;
            }
            else{
                return variable.get(token).value;
            }
        }
    }


    void createNumberVar(std::string varName, std::string varValue){
        VariableStructure var;
        var.name = varName;
        var.value = varValue;
        var.type = "number";
        this->variable.set(var.name, var);
    }

    void createStringVar(std::string varName, std::string varValue){
        VariableStructure var;
        var.name = varName;
        var.value = varValue;
        var.type = "string";
        this->variable.set(var.name, var);
    }

    bool conditionalOperations(varTab commands){
        for ( int i = 0; i < commands.size(); ++i) {
            if (commands[i] == "<"){
                return Conditional::less(this->toNumber(this->serchOnVars(commands[i - 1])),this->toNumber(this->serchOnVars(commands[i + 1])));
            }
            else if (commands[i] == "<="){
                return Conditional::lessThanEqual(this->toNumber(this->serchOnVars(commands[i - 1])),this->toNumber(this->serchOnVars(commands[i + 1])));
            }
            else if (commands[i] == ">"){
                return Conditional::greater(this->toNumber(this->serchOnVars(commands[i - 1])),this->toNumber(this->serchOnVars(commands[i + 1])));
            }
            else if (commands[i] == ">="){
                return Conditional::greaterThanEquals(this->toNumber(this->serchOnVars(commands[i - 1])),this->toNumber(this->serchOnVars(commands[i + 1])));
            }
            else if (commands[i] == "=="){
                return Conditional::equally(this->toNumber(this->serchOnVars(commands[i - 1])),this->toNumber(this->serchOnVars(commands[i + 1])));
            }
            else if (commands[i] == "!="){
                return Conditional::notEqual(this->toNumber(this->serchOnVars(commands[i - 1])),this->toNumber(this->serchOnVars(commands[i + 1])));
            }
        }
        return false;
    }
    void ifCommand( std::vector<varTab> command){
        if(this->conditionalOperations(command[0]) == true){
            command.erase(command.begin());
            this->tokenAnalis(command);
        }
    }

    void whileCommand( std::vector<varTab> command){
        varTab state = command[0];
        bool whlieState = this->conditionalOperations(state);
        command.erase(command.begin());
        while( whlieState == true ){
            this->tokenAnalis(command);
            whlieState = conditionalOperations(state);
        }
    }

    void mathOperations(varTab commands){
        for ( int i = 0; i < commands.size(); ++i) {
            if (commands[i] == "+") {
                this->createNumberVar(commands[i - 3], std::to_string(Operation::sum(this->toNumber(this->serchOnVars(commands[i - 1])),this->toNumber(this->serchOnVars(commands[i + 1])))));
            }
            else if (commands[i] == "-") {
                this->createNumberVar(commands[i - 3], std::to_string(Operation::sub(this->toNumber(this->serchOnVars(commands[i - 1])),this->toNumber(this->serchOnVars(commands[i + 1])))));
            }
            else if (commands[i] == "*") {
                this->createNumberVar(commands[i - 3], std::to_string(Operation::mul(this->toNumber(this->serchOnVars(commands[i - 1])),this->toNumber(this->serchOnVars(commands[i + 1])))));
            }
            else if (commands[i] == "/") {
                this->createNumberVar(commands[i - 3], std::to_string(Operation::dec(this->toNumber(this->serchOnVars(commands[i - 1])),this->toNumber(this->serchOnVars(commands[i + 1])))));
            }
            else if (commands[i] == "%") {
                this->createNumberVar(commands[i - 3], std::to_string(Operation::mod(this->toNumber(this->serchOnVars(commands[i - 1])),this->toNumber(this->serchOnVars(commands[i + 1])))));
            }
            else if (commands[i] == "^") {
                this->createNumberVar(commands[i - 3], std::to_string(Operation::pow(this->toNumber(this->serchOnVars(commands[i - 1])),this->toNumber(this->serchOnVars(commands[i + 1])))));
            }
        }
    }
    void addVarCommand(varTab commands) {
        std::string str = "";
        for( int i = 0; i < commands.size(); ++i ){
            if(commands[i] == " \""){
                for( int j=i+1; j < commands.size(); ++j, ++i){
                    if(commands[j] != "\""){
                        str = str + commands[j] + " ";

                    }else if(commands[j] == "\""){
                        break;
                    }
                }
                this->createStringVar(commands[1], str);
                continue;
            }else if (commands.size() <= 4){
                this->createNumberVar(commands[1], this->serchOnVars(commands[3]));
                return;
            }
            else{
                this->mathOperations(commands);
            }
        }
        
    }
   
    void tokenAnalis(std::vector<varTab> commands) {
        for (int i = 0; i < commands.size(); ++i) {
            if (commands[i][0] == "VAR") {
                this->addVarCommand(commands[i]);
            }
            if (commands[i][0] == "IF"){
                std::vector<varTab> ifCommands;
                for(int j = i ; j < commands.size();++j,++i){
                    if(commands[j][0] != "ENDIF"){
                       ifCommands.push_back(commands[j]);
                    }
                    else if (commands[j][0] == "ENDIF"){
                       break;
                    }
                }
                this->ifCommand(ifCommands);
                continue;           
            }
            if (commands[i][0] == "WHILE"){
                std::vector<varTab> whileCommands;
                for(int j = i ; j < commands.size();++j,++i){
                    if(commands[j][0] != "END"){
                       whileCommands.push_back(commands[j]);
                    }
                    else if (commands[j][0] == "END"){
                       break;
                    }
                }
                this->whileCommand(whileCommands);
                continue;           
            }
            if(commands[i][0] == "PRINT"){
                Print::log(this->serchOnVars(commands[i][1]));
            }
            else{
                this->mathOperations(commands[i]);
            }
        }
    }
    void commandsRead(std::vector<varTab> all_commands) {
        this->tokenAnalis(all_commands); 
    }

public:
    Lexer(std::vector<varTab> all_commands, VariableTable variable) {
        this->all_commands = all_commands;
        this->variable = variable;
        this->commandsRead(this->all_commands);
        this->intermediate_code = "";
    }
};
#endif