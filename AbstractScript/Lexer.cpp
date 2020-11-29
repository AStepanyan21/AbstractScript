#include <iostream>
#include <vector>
#include <string>
#include "MathOperations.cpp"



class Lexer {
private:
    std::vector<std::vector<std::string>> all_commands;

    int toInt(std::string token){
        return std::stoi(token);
    }

    void addVarCommand(std::vector<std::string> commands) {
        if (commands.size() > 4) {
            if (commands[4] == "+") {
                std::cout << "VAR: " << commands[1] << " = " << Operation::sum(this->toInt(commands[3]), this->toInt(commands[5])) << std::endl;
            }
            else if (commands[4] == "-") {
                std::cout << "VAR: " << commands[1] << " = " << Operation::sub(this->toInt(commands[3]), this->toInt(commands[5])) << std::endl;
            }
            else if (commands[4] == "*") {
                std::cout << "VAR: " << commands[1] << " = " << Operation::mul(this->toInt(commands[3]), this->toInt(commands[5])) << std::endl;
            }
            else if (commands[4] == "/") {
                std::cout << "VAR: " << commands[1] << " = " << Operation::dec(this->toInt(commands[3]), this->toInt(commands[5])) << std::endl;
            }
            else if (commands[4] == "/") {
                std::cout << "VAR: " << commands[1] << " = " << Operation::mod(this->toInt(commands[3]), this->toInt(commands[5])) << std::endl;
            }
            else if (commands[4] == "^") {
                std::cout << "VAR: " << commands[1]<<" = " << Operation::pow(this->toInt(commands[3]), this->toInt(commands[5])) << std::endl;
            }
        }
       else{
           std::cout<<"VAR: "<<commands[1] << " = " <<this->toInt(commands[3])<<std::endl;
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
    Lexer(std::vector<std::vector<std::string>> all_commands) {
        this->all_commands = all_commands;
        this->commandsRead(this->all_commands);
    }
};