#pragma once

#include <iostream>
#include <cmath>
#include "Prerequisites.h"

constexpr double E = 2.71828182845904523536f;

// Inlines de funciones logarítmicas


inline double a_LogaritmoNatural(double xy) {
	if (xy <= 0.0) {
		throw std::runtime_error("Logaritmo natural indefinido para valores <= 0.");
	}
	double result = 0.0;
	double term = (xy - 1) / (xy + 1);
	double term_squared = term * term;
	double current_term = term;
	int n = 1;
	while (fabs(current_term) > 1e-10) {
		result += current_term / (2 * n - 1);
		current_term *= term_squared;
		n++;
	}
	return 2 * result;
}

inline double a_LogaritmoBase10(double xy) {
	if (xy <= 0.0) {
		throw std::runtime_error("Logaritmo base 10 indefinido para valores <= 0.");
	}
	return a_LogaritmoNatural(xy) / a_LogaritmoNatural(10.0);
}

inline double a_LogaritmoBaseN(double xy, double base) {
	if (xy <= 0.0 || base <= 1.0) {
		throw std::runtime_error("Logaritmo base N indefinido para valores invalidos.");
	}
	return a_LogaritmoNatural(xy) / a_LogaritmoNatural(base);
}

// Metodo para calcular la exponencial usando la serie de Taylor
inline double a_Exponencial(double xy) {
	double term = 1.0; // Primer término
	double sum = term; // Inicializar la suma con el primer término
	int n = 1; // Contador de términos
	while (fabs(term) > 1e-10f) { // Continuar hasta que el término sea suficientemente pequeño
		term *= xy / n; // Calcular el siguiente término
		sum += term; // Añadir el término a la suma
		n++; // Incrementar el contador de términos
	}
	return sum;
}



