#ifndef CONDITIONALOPERATIONS_H
#define CONDITIONALOPERATIONS_H
#include <iostream>

class Conditional {
public:
	template <class T,class R>
	static bool equally(T a, R b) {
		return a == b;
	}

	template <class T,class R>
	static bool notEqual(T a, R b) {
		return a != b;
	}

	template <class T,class R>
	static bool greaterThanEquals(T a, R b) {
		return a >= b;
	}

	template <class T,class R>
	static bool lessThanEqual(T a, R b) {
		return a <= b;
	}

	template <class T,class R>
	static bool greater(T a, R b) {
		return a > b;
	}
	
	template <class T,class R>
	static bool less(T a, R b) {
		return a < b;
	}
};
#endif