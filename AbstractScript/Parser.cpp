#include <iostream>
#include <fstream>
#include <string>
#include <stdint.h>
#include "Print.cpp"


class Parser {
private:
    Print console;
	void parsing(std::string filename) {
        std::string line;
        std::ifstream rfile;
        rfile.open(filename);
        if (rfile.is_open()) {
            while (std::getline(rfile, line)) {
                this->console.log(line);
            }
            rfile.close();
        }
	}
public:
    Parser(std::string filename, Print console) {
        this->console = console;
        this->parsing(filename);
    }
};