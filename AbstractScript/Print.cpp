#include <iostream>

class Print {
public:
    template <class T>
	void log(T logName) {
        std::cout << logName << std::endl;
	}

    template <class T>
	void error(T logName) {
        std::cout << logName << std::endl;
	}

    template <class T>
	void success(T logName) {
	std::cout << logName << std::endl;
	}
};
