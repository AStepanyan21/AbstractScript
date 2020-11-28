#include <iostream>
#include <math.h>

class Operation {
public:
	template <class T,class R>
	static T sum(T a, R b) {
		return a + b;
	}

	template <class T,class R>
	static T sub(T a, R b) {
		return a - b;
	}

	template <class T,class R>
	static T mul(T a, R b) {
		return a * b;
	}

	template <class T,class R>
	static T dec(T a, R b) {
		if (b != 0) {
			return a / b;
		}
		else {
			0;
		}
	}

	template <class T,class R>
	static T mod(T a, R b) {
		return a % b;
	}

	template <class T,class R>
	static T pow(T a, R b) {
		return pow(a, b);
	}
};