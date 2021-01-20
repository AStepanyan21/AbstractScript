#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <stdint.h>
#include <fstream>
#include <codecvt>
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


    std::wstring translate(std::wstring code) {
        size_t nPos;
        std::wstring VAR = L"փոփ";
        std::wstring newVAR = L"VAR";
        std::wstring IF = L"եթե";
        std::wstring newIF = L"IF";
        std::wstring PRINT = L"տպել";
        std::wstring newPRINT = L"PRINT";
        std::wstring WHILE = L"երբ";
        std::wstring newWHILE = L"WHILE";
        std::wstring ENDIF = L"ապա-վերջ";
        std::wstring newENDIF = L"ENDIF";
        std::wstring END = L"վերջ";
        std::wstring newEND = L"END";
        try {
            nPos = code.find(VAR);
            code = code.replace(nPos, VAR.length(), newVAR);
        }
        catch(int e){
        }
        try {
            nPos = code.find(IF);
            code = code.replace(nPos, IF.length(), newIF);
        }
        catch (int e) {
        }
        try {
            nPos = code.find(PRINT);
            code = code.replace(nPos, PRINT.length(), newPRINT);
        }
        catch (int e) {
        }
        try {
            nPos = code.find(WHILE);
            code = code.replace(nPos, WHILE.length(), newWHILE);
        }
        catch (int e) {
        }
        try {
            nPos = code.find(ENDIF);
            code = code.replace(nPos, ENDIF.length(), newENDIF);
        }
        catch (int e) {
        }
        try {
            nPos = code.find(END);
            code = code.replace(nPos, END.length(), newEND);
        }
        catch (int e) {
        }
        return code;
    }

    std::wstring readFile(const char* filename)
    {
        std::wifstream wif(filename);
        
        std::wstring code;
        wif.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
        std::wstringstream wss;
        wss << wif.rdbuf();
        code = this->translate(wss.str());
        return code;
    }

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

    void parsing(char* filename) {
        std::string line;
        std::ifstream rfile;
        std::wstring uCode = this->readFile(filename);
        std::string all_code(uCode.begin(), uCode.end());
        std::string code = this->delete_tabs_and_newline(all_code);
        this->commands = this->splitting(code);
        this->splitting_commands = this->parsingCommands(this->commands);
	}
    
public:
    Parser(char* filename) {
        this->parsing(filename);
        
    }
    std::vector<varTab> getCommands(){
        return this->splitting_commands;
    }
};
#endif