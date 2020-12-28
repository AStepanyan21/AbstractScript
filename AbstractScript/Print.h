#ifndef PRINT_H
#define PRINT_H
#include <iostream>

class Print {
public:
    template <typename T>
	static void log(const T logName) {
        std::cout << logName << std::endl;
	}

    template <typename T>
	static void error(const T logName) {
        std::cout << logName << std::endl;
	}

    template <typename T>
	static void success(const T logName) {
		std::cout << logName << std::endl;
	}
};
#endif