#include <iostream>
#include <stdint.h>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <vector>
#include "Print.cpp"


class Parser {
private:
    Print console;
    std::vector<std::string> spliting(std::string text){
        std::vector<std::string> commands;
        std::string intermediate;
        std::stringstream check1(text);
        while(std::getline(check1, intermediate, ';')){
            commands.push_back(intermediate);
        }
        return commands;

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
            this->spliting(code);
        }
	}
public:
    Parser(std::string filename, Print console) {
        this->console = console;
        this->parsing(filename);
    }
};