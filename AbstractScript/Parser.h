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

struct Alias{
    std::wstring arm;
    std::wstring eng;
};

class Parser {
private:
    varTab commands;
    std::vector<varTab> splitting_commands;

    std::wstring findToken(std::wstring& code, const std::wstring& arm, const std::wstring& eng) {
        size_t nPos;
        nPos = code.find(arm);
        if (nPos != std::string::npos) {
            return code.replace(nPos, arm.length(), eng);
        }
        return code;
    }

    std::wstring translate(std::wstring code) {
        Alias Var;
        Var.arm = L"փոփ";
        Var.eng = L"VAR";
        Alias If;
        If.arm = L"եթե";
        If.eng = L"IF";
        Alias Print;
        Print.arm = L"տպել";
        Print.eng = L"PRINT";
        Alias While;
        While.arm = L"երբ";
        While.eng = L"WHILE";
        Alias EndIf;
        EndIf.arm = L"ապա-վերջ";
        EndIf.eng = L"ENDIF";
        Alias End;
        End.arm = L"վերջ";
        End.eng = L"END";


        code = findToken(code, Var.arm, Var.eng);
        code = findToken(code, If.arm, If.eng);
        code = findToken(code, Print.arm, Print.eng);
        code = findToken(code, While.arm, While.eng);
        code = findToken(code, EndIf.arm, EndIf.eng);
        code = findToken(code, End.arm, End.eng);
        
        return code;
    }

    std::wstring readFile(const char* filename)
    {
        std::wifstream wif(filename);
        
        std::wstring code;
        wif.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
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