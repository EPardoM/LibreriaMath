#pragma once
#include "Prerequisites.h"

class Matriz2x2 {
public:
	// CONSTRUCTORES

	// Constructor por defecto. Inicializa la matriz como la identidad.
	Matriz2x2()
		: m00(1.0f), m01(0.0f),
		m10(0.0f), m11(1.0f) {
	}

	// Constructor principal.
	Matriz2x2(float a00, float a01,
		float a10, float a11)
		: m00(a00), m01(a01),
		m10(a10), m11(a11) {
	}

	// Constructor de copia.
	Matriz2x2(const Matriz2x2& other)
		: m00(other.m00), m01(other.m01),
		m10(other.m10), m11(other.m11) {
	}

	// Destructor de la clase
	~Matriz2x2() = default;

	// METODOS PUBLICOS

	// Getters
	float GetM00() const { return m00; }
	float GetM01() const { return m01; }
	float GetM10() const { return m10; }
	float GetM11() const { return m11; }

	//Setters
	void SetM00(float value) { m00 = value; }
	void SetM01(float value) { m01 = value; }
	void SetM10(float value) { m10 = value; }
	void SetM11(float value) { m11 = value; }

	// Establece los valores de la matriz
	void Set(float a00, float a01,
		float a10, float a11) {
		m00 = a00; m01 = a01;
		m10 = a10; m11 = a11;
	}

	void Set(const Matriz2x2& other) {
		m00 = other.m00; m01 = other.m01;
		m10 = other.m10; m11 = other.m11;
	}

	Matriz2x2 set() const {
		return Matriz2x2(m00, m01,
			m10, m11);
	}

	//Suma de dos matrices
	Matriz2x2 operator+(const Matriz2x2& rhs) const {
		return Matriz2x2(
			m00 + rhs.m00, m01 + rhs.m01,
			m10 + rhs.m10, m11 + rhs.m11
		);
	}
	//Resta de dos matrices
	Matriz2x2 operator-(const Matriz2x2& rhs) const {
		return Matriz2x2(
			m00 - rhs.m00, m01 - rhs.m01,
			m10 - rhs.m10, m11 - rhs.m11
		);
	}
	//Multiplicación de dos matrices
	Matriz2x2 operator*(const Matriz2x2& rhs) const {
		return Matriz2x2(
			m00 * rhs.m00 + m01 * rhs.m10, m00 * rhs.m01 + m01 * rhs.m11,
			m10 * rhs.m00 + m11 * rhs.m10, m10 * rhs.m01 + m11 * rhs.m11
		);
	}
	//Multiplicación por un escalar
	Matriz2x2 operator*(float scalar) const {
		return Matriz2x2(
			m00 * scalar, m01 * scalar,
			m10 * scalar, m11 * scalar
		);
	}

	//Division entre dos matrices
	Matriz2x2 operator/(const Matriz2x2& rhs) const {
		// Calcular el determinante de la matriz rhs
		float det = rhs.m00 * rhs.m11 - rhs.m01 * rhs.m10;
		if (det == 0.0f) {
			__noop("Matriz2x2", "operator/", "Division by zero matrix");
			return Matriz2x2(); // Retornar la matriz identidad en caso de división por cero
		}
		// Calcular la inversa de rhs
		Matriz2x2 invRhs(
			rhs.m11 / det, -rhs.m01 / det,
			-rhs.m10 / det, rhs.m00 / det
		);
		// Multiplicar esta matriz por la inversa de rhs
		return (*this) * invRhs;
	}

	//Division por un escalar
	Matriz2x2 operator/(float scalar) const {
		if (scalar == 0.0f) {
			__noop("Matriz2x2", "operator/", "Division by zero scalar");
			return Matriz2x2(); // Retornar la matriz identidad en caso de división por cero
		}
		return Matriz2x2(
			m00 / scalar, m01 / scalar,
			m10 / scalar, m11 / scalar
		);
	}

	// Division directa entre esta matriz y otra matriz a través del operador /=
	Matriz2x2& operator/=(const Matriz2x2& rhs) {
		// Calcular el determinante de la matriz rhs
		float det = rhs.m00 * rhs.m11 - rhs.m01 * rhs.m10;
		if (det == 0.0f) {
			__noop("Matriz2x2", "operator/=", "Division by zero matrix");
			m00 = 1.0f; m01 = 0.0f;
			m10 = 0.0f; m11 = 1.0f; // Retornar la matriz identidad en caso de división por cero
			return *this;
		}
		// Calcular la inversa de rhs
		Matriz2x2 invRhs(
			rhs.m11 / det, -rhs.m01 / det,
			-rhs.m10 / det, rhs.m00 / det
		);
		// Multiplicar esta matriz por la inversa de rhs
		return (*this) *= invRhs;
	}

	// Agregar operador de división directa por escalar a Matriz2x2
	Matriz2x2& operator/=(float scalar) {
		if (scalar == 0.0f) {
			__noop("Matriz2x2", "operator/=", "Division by zero scalar");
			m00 = 1.0f; m01 = 0.0f;
			m10 = 0.0f; m11 = 1.0f; // Retornar la matriz identidad en caso de división por cero
			return *this;
		}
		m00 /= scalar;
		m01 /= scalar;
		m10 /= scalar;
		m11 /= scalar;
		return *this;
	}

	// Multiplicación directa por un escalar
	Matriz2x2& operator*=(float scalar) {
		m00 *= scalar;
		m01 *= scalar;
		m10 *= scalar;
		m11 *= scalar;
		return *this;
	}

	// Multiplicación directa por otra matriz
	Matriz2x2& operator*=(const Matriz2x2& rhs) {
		float nm00 = m00 * rhs.m00 + m01 * rhs.m10;
		float nm01 = m00 * rhs.m01 + m01 * rhs.m11;
		float nm10 = m10 * rhs.m00 + m11 * rhs.m10;
		float nm11 = m10 * rhs.m01 + m11 * rhs.m11;
		m00 = nm00;
		m01 = nm01;
		m10 = nm10;
		m11 = nm11;
		return *this;
	}

	//Matriz transpuesta
	Matriz2x2 Transpose() const {
		return Matriz2x2(
			m00, m10,
			m01, m11
		);
	}

	//Matriz inversa
	Matriz2x2 Inverse() const {
		float det = Determinante();
		if (det == 0.0f) {
			__noop("Matriz2x2", "Inverse", "Matrix is not invertible (determinant is zero)");
			return Matriz2x2(); // Retornar la matriz identidad en caso de no ser invertible
		}
		return Matriz2x2(
			m11 / det, -m01 / det,
			-m10 / det, m00 / det
		);
	}

	//Determinante de la matriz
	float Determinante() const {
		return m00 * m11 - m01 * m10;
	}

	//UTILIDADES

	//Devuelve un string con la representación de la matriz
	std::string ToString() const {
		return "[" + std::to_string(m00) + ", " + std::to_string(m01) + "]\n" +
			"[" + std::to_string(m10) + ", " + std::to_string(m11) + "]";
	}

private:
	float m00, m01, m10, m11;
};


