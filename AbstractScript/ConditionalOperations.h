#ifndef CONDITIONALOPERATIONS_H
#define CONDITIONALOPERATIONS_H
#include <iostream>

class Conditional {
public:
	template <typename T, typename R>
	static bool equally(const T a, const R b) {
		return a == b;
	}

	template <typename T, typename R>
	static bool notEqual(const T a, const R b) {
		return a != b;
	}

	template <typename T, typename R>
	static bool greaterThanEquals(const T a, const R b) {
		return a >= b;
	}

	template <typename T, typename R>
	static bool lessThanEqual(const T a, const R b) {
		return a <= b;
	}

	template <typename T, typename R>
	static bool greater(const T a, const R b) {
		return a > b;
	}
	
	template <typename T, typename R>
	static bool less(const T a, const R b) {
		return a < b;
	}
};
#endif