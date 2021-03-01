#include <iostream>
#include <vector>
#include <sstream> 
#include <string>
#include "Constants.h"
#include "Print.h"

using varTab = std::vector<std::string>;

class VirtualMachine{
public:
    VirtualMachine(std::vector<varTab> commands){
        this->commands = commands;
    }
private:
    std::vector<varTab> commands;
    int line = 0;
    float eax = 0;
    float ebx = 0;
    float ecx = 0;
    float edx = 0;
    std::string eay = "";
    std::string eby = "";
    std::string ecy = "";
    std::string edy = "";

    void SUM(float &a, float &b){
        a = a + b;
    }
    void SUB(float &a, float &b){
        a = a - b;
    }
    void MUL(float &a, float &b){
        a = a * b;
    }
    void DEC(float &a, float &b){
        if(b !=0){
            a = a / b;
        }
    }
    
    float* return_on_registers(std::string regist_name){
        if (regist_name == "eax"){
            return &this->eax;
        } else if (regist_name == "ebx"){
            return &this->ebx;
        } else if (regist_name == "ecx"){
            return &this->ecx;
        } else if (regist_name == "edx"){
            return &this->edx;
        }
    }
    void addStringVariable(std::string var, std::string registor){
        if (registor == "eay"){
            this->eay = var;
        } else if (registor == "eby"){
            this->eby = var;
        } else if (registor == "ecy"){
            this->ecy = var;
        } else if (registor == "edy"){
            this->edy = var;
        }
    }
    float toNumber(std::string token){
        std::stringstream geek(token);
        float num = 0;
        geek >> num;
        return num;
    }
    int toInt(std::string token){
        std::stringstream geek(token);
        int num = 0;
        geek >> num;
        return num;
    }
    void addNumberVariable(float var, std::string registor ){
        if( registor == "eax"){
            this->eax = var;
        } else if (registor == "ebx"){
            this->ebx = var;
        } else if (registor == "ecx"){
            this->ecx = var;
        } else if (registor == "edx"){
            this->edx = var;
        }
    }
    std::string CON(float a, float b){
        if ( a - b == 0 ){
            return equally;
        } else if ( a - b != 0 ){
            return notEqual;
        } else if ( a - b >= 0){
            return greaterThanEquals;
        } else if ( a - b > 0 ){
            return greater;
        } else if ( a - b <= 0 ){
            return lessThanEqual;
        } else if ( a - b < 0 ){
            return less;
        }
    }
    void JUMP(int jump_to){
        this->line = jump_to;
    }
    void read(){
        for(this->line; this->line<this->commands.size(); ++this->line){
            if(this->commands[this->line][0] == ADD_S ){
                this->addStringVariable(this->commands[this->line][2],this->commands[this->line][1]);
            } else if(this->commands[this->line][0] == ADD_N){
                this->addNumberVariable(this->toNumber(this->commands[this->line][2]),this->commands[this->line][1]);
            } else if (this->commands[this->line][0] == C_SUM){   
                this->SUM(*this->return_on_registers(this->commands[this->line][1]),
                            *this->return_on_registers(this->commands[this->line][2]));
            } else if (this->commands[this->line][0] == C_SUB){   
                this->SUB(*this->return_on_registers(this->commands[this->line][1]),
                        *this->return_on_registers(this->commands[this->line][2]));
            } else if (this->commands[this->line][0] == C_DEC){   
                this->DEC(*this->return_on_registers(this->commands[this->line][1]),
                        *this->return_on_registers(this->commands[this->line][2]));
            } else if (this->commands[this->line][0] == C_MUL){   
                this->MUL(*this->return_on_registers(this->commands[this->line][1]),
                        *this->return_on_registers(this->commands[this->line][2]));
            } else if (this->commands[this->line][0] == C_JUMP){
                this->JUMP(this->toInt(this->commands[this->line][1]));
            } else if (this->commands[this->line][0] == PRINT){
                Print::log(this->commands[this->line][1]);
            }
            
        }
    }

};

int main(){

}