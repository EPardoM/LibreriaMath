#pragma once

#include <iostream>
#include <cmath>
#include "Prerequisites.h"

constexpr double PIa = 3.14159265358979323846;

//Calcular el área de un círculo dado su radio
inline double AreaCirculo(float radioCirculo) {
	return PIa * radioCirculo * radioCirculo;
}

//Calcular el perímetro de un círculo dado su radio
inline double PerimetroCirculo(float radioCirculo) {
	return 2.0f * PIa * radioCirculo;
}

//Calcular el área de un rectángulo dado su ancho y alto
inline float AreaRectangulo(float anchoRectangulo, float ladoRectangulo) {
	return anchoRectangulo * ladoRectangulo;
}

//Calcular el perímetro de un rectángulo dado su ancho y alto
inline float PerimetroRectangulo(float anchoRectangulo, float ladoRectangulo) {
	return 2.0f * (anchoRectangulo + ladoRectangulo);
}

//Calcular el área de un triángulo dado su base y altura
inline float AreaTriangulo(float baseTriangulo, float alturaTriangulo) {
	return 0.5f * baseTriangulo * alturaTriangulo;
}

//Calcular el perímetro de un triángulo dado sus tres lados
inline float PerimetroTriangulo(float ladoTriangulo1, float ladoTriangulo2, float ladoTriangulo3) {
	return ladoTriangulo1 + ladoTriangulo2 + ladoTriangulo3;
}

//Calcular el área de un cuadrado dado su lado
inline float AreaCuadrado(float ladoCuadrado) {
	return ladoCuadrado * ladoCuadrado;
}

//Calcular el perímetro de un cuadrado dado su lado
inline float PerimetroCuadrado(float ladoCuadrado) {
	return 4.0f * ladoCuadrado;
}
//Calcular el perímetro de un trapecio dado sus cuatro lados
inline float PerimetroTrapecio(float baseMayor, float baseMenor, float ladoTrapecio1, float ladoTrapecio2) {
	return baseMayor + baseMenor + ladoTrapecio1 + ladoTrapecio2;
}

//Calcular el área de un trapecio dado sus cuatro lado y altura
inline float AreaTrapecio(float baseMayor, float baseMenor, float alturaTrapecio) {
	return ((baseMayor + baseMenor) / 2.0f) * alturaTrapecio;
}

//Calcular el perímetro de un rombo dado su lado
inline float PerimetroRombo(float ladoRombo) {
	return 4.0f * ladoRombo;
}

//Calcular el área de un rombo dado sus diagonales
inline float AreaRombo(float diagonalMayor, float diagonalMenor) {
	return (diagonalMayor * diagonalMenor) / 2.0f;
}

//Calcular el volumen de una esfera dado su radio
inline double VolumenEsfera(float radioEsfera) {
	return (4.0f / 3.0f) * PIa * radioEsfera * radioEsfera * radioEsfera;
}

//Calcular el área de la superficie de una esfera dado su radio
inline double AreaSuperficieEsfera(float radioEsfera) {
	return 4.0f * PIa * radioEsfera * radioEsfera;
}

//Calcular el volumen de un cubo dado su lado
inline float VolumenCubo(float ladoCubo) {
	return ladoCubo * ladoCubo * ladoCubo;
}

//Calcular el área de la superficie de un cubo dado su lado
inline float AreaSuperficieCubo(float ladoCubo) {
	return 6.0f * ladoCubo * ladoCubo;
}

//Calcular el volumen de un cilindro dado su radio y altura
inline double VolumenCilindro(float radioCilindro, float alturaCilindro) {
	return PIa * radioCilindro * radioCilindro * alturaCilindro;
}

//Calcular el área de la superficie de un cilindro dado su radio y altura
inline double AreaSuperficieCilindro(float radioCilindro, float alturaCilindro) {
	return 2.0f * PIa * radioCilindro * (radioCilindro + alturaCilindro);
}

//Calcular el área de la superficie de un cono dado su radio y altura
inline double AreaSuperficieCono(float radioCono, float alturaCono) {
	float generatriz = sqrt(radioCono * radioCono + alturaCono * alturaCono);
	return PIa * radioCono * (radioCono + generatriz);
}

//Calcular el volumen de un cono dado su radio y altura
inline double VolumenCono(float radioCono, float alturaCono) {
	return (1.0f / 3.0f) * PIa * radioCono * radioCono * alturaCono;
}

//Calcular el área de la superficie de una pirámide base cuadrada dado su lado y altura
inline float AreaSuperficiePiramideCuadrada(float ladoPiramide, float alturaPiramide) {
	float apotema = sqrt((ladoPiramide / 2.0f) * (ladoPiramide / 2.0f) + alturaPiramide * alturaPiramide);
	return (ladoPiramide * ladoPiramide) + (2.0f * ladoPiramide * apotema);
}

//Calcular el volumen de una pirámide base cuadrada dado su lado y la altura
inline float VolumenPiramideCuadrada(float ladoPiramide, float alturaPiramide) {
	return (1.0f / 3.0f) * ladoPiramide * ladoPiramide * alturaPiramide;
}

//Calcular el área de la superficie de una pirámide base rectangular dado su lado, ancho y altura
inline float AreaSuperficiePiramideRectangular(float ladoPiramide, float anchoPiramide, float alturaPiramide) {
	float apotemaLado = sqrt((ladoPiramide / 2.0f) * (ladoPiramide / 2.0f) + alturaPiramide * alturaPiramide);
	float apotemaAncho = sqrt((anchoPiramide / 2.0f) * (anchoPiramide / 2.0f) + alturaPiramide * alturaPiramide);
	return (ladoPiramide * anchoPiramide) + (ladoPiramide * apotemaLado) + (anchoPiramide * apotemaAncho);
}

//Calcular el volumen de una pirámide base rectangular dado su lado, ancho y altura
inline float VolumenPiramideRectangular(float ladoPiramide, float anchoPiramide, float alturaPiramide) {
	return (1.0f / 3.0f) * ladoPiramide * anchoPiramide * alturaPiramide;
}
