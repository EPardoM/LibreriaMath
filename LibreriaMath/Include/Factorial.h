#pragma once

#include <iostream>
#include <cmath>
#include "Prerequisites.h"


// Inline para calcular el factorial de un número entero no negativo
inline unsigned long long Factorial(int numFactorial) {
	if (numFactorial < 0) {
		throw std::runtime_error("Factorial indefinido para numeros negativos.");
	}
	unsigned long long result = 1;
	for (int i = 2; i <= numFactorial; ++i) {
		result *= i;
	}
	return result;
}


