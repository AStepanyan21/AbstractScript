#include <iostream>

class Operation {
public:
	static int intSum(int a, int b) {
		return a + b;
	}
	static float floatSum(float a, float b) {
		return a + b;
	}

	static int intSub(int a, int b) {
		return a - b;
	}
	static float floatSub(float a, float b) {
		return a - b;
	}

	static int intMul(int a, int b) {
		return a * b;
	}
	static float floatMul(float a, float b) {
		return a * b;
	}

	static int intDec(int a, int b) {
		if (b != 0) {
			return a / b;
		}
		else {
			0;
		}
	}

	static float floatDec(float a, float b) {
		if (b != 0) {
			return a / b;
		}
		else {
			0;
		}
	}

	static int intMod(int a, int b) {
		return a % b;
	}

	static int intPow(int a, int b) {
		return pow(a,b);
	}

	static int floatPow(float a, float b) {
		return pow(a, b);
	}

};