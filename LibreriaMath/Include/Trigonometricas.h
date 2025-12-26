#pragma once

#include <iostream>
#include <cmath>
#include "Prerequisites.h"



constexpr double PIb = 3.14159265358979323846;

// Inlines de funciones trigonométricas

// Convertir grados a radianes y viceversa
inline double GradosARadianes(double x) {
	return x * (PIb / 180.0f);
}

inline double RadianesAGrados(double y) {
	return y * (180.0f / PIb);
}

/*
Metodo para calcular el seno usando la serie de Taylor
Resultado en decimales
sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
*/

inline double a_Seno(double x) {
	x = x * (PIb / 180); // Convertir grados a radianes
	double term = x; // Primer término de la serie
	double sum = term; // Inicializar la suma con el primer término
	int n = 1; // Contador de términos
	while (fabs(term) > 1e-10f) { // Continuar hasta que el término sea suficientemente pequeño
		term *= -x * x / ((2 * n) * (2 * n + 1)); // Calcular el siguiente término
		sum += term; // Añadir el término a la suma
		n++; // Incrementar el contador de términos
	}
	return sum;
}

/*
Metodo para calcular el coseno usando la serie de Taylor
Resultado en decimales
cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ...
*/

inline double a_Coseno(double x) {
	x = x * (PIb / 180); // Convertir grados a radianes
	double term = 1.0;  // Primer término
	double sum = term;
	int n = 1;
	while (fabs(term) > 1e-10) {
		term *= -x * x / ((2 * n - 1) * (2 * n));
		sum += term;
		n++;
	}
	return sum;
}

/*
Metodo para calcular la tangente como seno/coseno
Resultado en decimales
*/

inline double a_Tangente(double x) {
	double seno = a_Seno(x);
	double coseno = a_Coseno(x);
	if (coseno == 0.0) {
		throw std::runtime_error("Tangente indefinida para este angulo.");
	}
	return seno / coseno;
}

/*
Metodo para calcular la secante como 1/coseno
Resultado en decimales
*/

inline double a_Secante(double x) {
	double coseno = a_Coseno(x);
	if (coseno == 0.0) {
		throw std::runtime_error("Secante indefinida para este angulo.");
	}
	return 1.0 / coseno;
}

/*
Metodo para calcular la cosecante como 1/seno
Resultado en decimales
*/

inline double a_Cosecante(double x) {
	double seno = a_Seno(x);
	if (seno == 0.0) {
		throw std::runtime_error("Cosecante indefinida para este angulo.");
	}
	return 1.0 / seno;
}

/*
Metodo para calcular la cotangente como 1/tangente
Resultado en decimales
*/

inline double a_Cotangente(double x) {
	double tangente = a_Tangente(x);
	if (tangente == 0.0) {
		throw std::runtime_error("Cotangente indefinida para este angulo.");
	}
	return 1.0 / tangente;
}

/*
Metodo para calcular el arco seno usando la serie de Taylor
Resultado en grados
Valores de entrada deben estar en el rango [-1, 1]
*/

inline double a_ArcoSeno(double y) {
	if (y < -1.0 || y > 1.0) {
		throw std::runtime_error("Entrada fuera del rango para arco seno.");
	}
	double term = y; // Primer término
	double sum = term;
	int n = 1;
	while (fabs(term) > 1e-10) {
		term *= ((2 * n - 1) * (2 * n - 1) * y * y) / ((2 * n) * (2 * n + 1));
		sum += term;
		n++;
	}
	return RadianesAGrados(sum);
}

/*
Metodo para calcular el arco coseno usando la relacion con arco seno
Resultado en grados
Valores de entrada deben estar en el rango [-1, 1]
*/

inline double a_ArcoCoseno(double y) {
	return 90.0 - a_ArcoSeno(y);
}

/*
Metodo para calcular el arco tangente usando la serie de Taylor
Resultado en grados
Valores de entrada deben estar en el rango [-1, 1]
*/

inline double a_ArcoTangente(double y) {
	double term = y; // Primer término
	double sum = term;
	int n = 1;
	while (fabs(term) > 1e-10) {
		term *= -y * y;
		sum += term / (2 * n + 1);
		n++;
	}
	return RadianesAGrados(sum);
}