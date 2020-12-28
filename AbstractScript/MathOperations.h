#ifndef MATHOPERATIONS_H
#define MATHOPERATIONS_H
#include <iostream>
#include <math.h>

class Operation {
public:
	template <typename T,typename R>
	static T sum(const T a, const R b) {
		return a + b;
	}

	template <typename T,typename R>
	static T sub(const T a, const R b) {
		return a - b;
	}

	template <typename T,typename R>
	static T mul(const T a, const R b) {
		return a * b;
	}

	template <typename T,typename R>
	static T dec(const T a, const R b) {
		if (b != 0) {
			return a / b;
		}
		else {
			0;
		}
	}

	static int mod(int a, int b) {
		return a % b;
	}

	template <typename T,typename R>
	static T pow(T a, R b) {
		return pow(a, b);
	}
};
#endif