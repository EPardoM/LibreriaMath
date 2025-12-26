#pragma once
#include "Prerequisites.h"
#include <cmath>
#include <iostream>

// Funciones inline para potencias
inline float Potencia(float base, float exponente) {
	return powf(base, exponente);
}

//	Función inline para calcular la raíz cuadrada
inline float RaizCuadrada(float valor) {
	return sqrtf(valor);
}

// Función inline para calcular la raíz cúbica
inline float RaizCubica(float x) {
	if (x >= 0.0f)
		return powf(x, 1.0f / 3.0f);
	else
		return -powf(-x, 1.0f / 3.0f);
}

// Función inline para calcular la raíz n-ésima
inline float RaizNesima(float base, float n) {
	if (n == 0.0f) {
		// No se puede calcular la raíz de orden 0
		return 0.0f;
	}
	if (base < 0.0f && static_cast<int>(n) % 2 == 0) {
		// Raíz par de número negativo no está definida en los reales
		return 0.0f;
	}
	return std::pow(base, 1.0f / n);
}