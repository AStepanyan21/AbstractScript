#ifndef PRINT_H
#define PRINT_H
#include <iostream>

class Print {
public:
    template <typename T>
	static void log(const T logName) {
        std::cout << logName << std::endl;
	}
};
#endif