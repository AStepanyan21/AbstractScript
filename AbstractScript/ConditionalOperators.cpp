#include <iostream>

class Conditional {
public:
	static bool equallyString(std::string a, std::string b) {
		return a == b;
	}

	static bool notEqualString(std::string a, std::string b) {
		return a != b;
	}

	static bool equally(float a, float b) {
		return a == b;
	}

	static bool notEqual(float a, float b) {
		return a != b;
	}

	static bool greaterThanEquals(float a, float b) {
		return a >= b;
	}

	static bool lessThanEqual(float a, float b) {
		return a <= b;
	}

	static bool greater(float a, float b) {
		return a > b;
	}

	static bool less(float a, float b) {
		return a < b;
	}
};