#pragma once

#include "Prerequisites.h"
#include <cmath>
#include <iostream>

// Inlines de funciones matemáticas
inline float valorAbsoluto(float n) {
	return n < 0.0f ? -n : n;
}

inline float valorMaximo(float a, float b) {
	return (a > b) ? a : b;
}

inline float valorMinimo(float a, float b) {
	return (a < b) ? a : b;
}

inline float Redondeo(float n) {
	return std::round(n);
}

inline float Techo(float n) {
	return std::ceil(n);
}

inline float Piso(float n) {
	return std::floor(n);
}

inline float Truncamiento(float n) {
	return std::trunc(n);
}