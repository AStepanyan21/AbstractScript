#ifndef PRINT_H
#define PRINT_H
#include <iostream>

class Print {
public:
    template <class T>
	static void log(T logName) {
        std::cout << logName << std::endl;
	}

    template <class T>
	static void error(T logName) {
        std::cout << logName << std::endl;
	}

    template <class T>
	static void success(T logName) {
		std::cout << logName << std::endl;
	}
};
#endif