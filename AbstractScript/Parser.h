#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <stdint.h>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <vector>


using varTab = std::vector<std::string>;


class Parser {
private:
    varTab commands;
    std::vector<varTab> splitting_commands;

    varTab splitting(std::string text){
        varTab commands;
        std::string intermediate;
        std::stringstream check1(text);
        while(std::getline(check1, intermediate, ';')){
            commands.push_back(intermediate);
        }
        return commands;
    }

    varTab splitCommand(std::string s){
        std::regex reg("\\s*(\")|(([a-zA-Z]+)(\\d*)|[+*/-])|([0-9]+).([0-9]+)|([0-9]+)|!=|<=|>=|==|[=]|<|>|%\\s*");
        varTab v;
        std::sregex_token_iterator iter(s.begin(), s.end(), reg, 0);
        std::sregex_token_iterator end;
        while(iter != end){
            v.push_back(*iter);
            ++iter;
        }
        return v;
    }

    std::vector<varTab> parsingCommands(varTab command){
        std::vector<varTab> splitting_commands;
        for(int i = 0; i < command.size(); i++){
            splitting_commands.push_back(this->splitCommand(command[i]));
        }
        return splitting_commands;
    }

    std::string delete_tabs_and_newline(std::string& line){
        std::regex reg("\n|\t");
        std::string text = "" ;
        text = std::regex_replace(line, reg, "");
        return text;
    }

    void parsing(std::string filename) {
        std::string line;
        std::ifstream rfile;
        std::string all_code = "";
        rfile.open(filename);
        if (rfile.is_open()) {
            while (std::getline(rfile, line)) {
                all_code = all_code + line;
            }
            rfile.close();
            std::string code = this->delete_tabs_and_newline(all_code);
            this->commands = this->splitting(code);
            this->splitting_commands = this->parsingCommands(this->commands);
        }
	}
    
public:
    Parser(std::string filename) {
        this->parsing(filename);
    }
    std::vector<varTab> getCommands(){
        return this->splitting_commands;
    }
};
#endif