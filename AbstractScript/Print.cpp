#include <iostream>
#include <windows.h>

enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

class Print {
    
private:
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    void setColor(ConsoleColor text, ConsoleColor background)
    {
        SetConsoleTextAttribute(this->hConsole, (WORD)((background << 4) | text));
    }
public:
    template <class T>
	void log(T logName) {
        this->setColor(White, Black);
        std::cout << logName << std::endl;
	}

    template <class T>
	void error(T logName) {
        this->setColor(Red, Black);
        std::cout << logName << std::endl;
        this->setColor(White, Black);
	}

    template <class T>
	void success(T logName) {
        this->setColor(Green, Black);
		std::cout << logName << std::endl;
        this->setColor(White, Black);
	}
};