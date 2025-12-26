#pragma once

#include "Prerequisites.h"

class Matriz4x4 {

public:

	// CONSTRUCTORES

	// Constructor por defecto. Inicializa la matriz como la identidad.
	Matriz4x4()
		: m00(1.0f), m01(0.0f), m02(0.0f), m03(0.0f),
		m10(0.0f), m11(1.0f), m12(0.0f), m13(0.0f),
		m20(0.0f), m21(0.0f), m22(1.0f), m23(0.0f),
		m30(0.0f), m31(0.0f), m32(0.0f), m33(1.0f) {
	}

	// Constructor principal.
	Matriz4x4(float a00, float a01, float a02, float a03,
		float a10, float a11, float a12, float a13,
		float a20, float a21, float a22, float a23,
		float a30, float a31, float a32, float a33)
		: m00(a00), m01(a01), m02(a02), m03(a03),
		m10(a10), m11(a11), m12(a12), m13(a13),
		m20(a20), m21(a21), m22(a22), m23(a23),
		m30(a30), m31(a31), m32(a32), m33(a33) {
	}

	// Constructor de copia.
	Matriz4x4(const Matriz4x4& other)
		: m00(other.m00), m01(other.m01), m02(other.m02), m03(other.m03),
		m10(other.m10), m11(other.m11), m12(other.m12), m13(other.m13),
		m20(other.m20), m21(other.m21), m22(other.m22), m23(other.m23),
		m30(other.m30), m31(other.m31), m32(other.m32), m33(other.m33) {
	}

	// Destructor de la clase
	~Matriz4x4() = default;

	// METODOS PUBLICOS

	// Getters
	float GetM00() const { return m00; }
	float GetM01() const { return m01; }
	float GetM02() const { return m02; }
	float GetM03() const { return m03; }
	float GetM10() const { return m10; }
	float GetM11() const { return m11; }
	float GetM12() const { return m12; }
	float GetM13() const { return m13; }
	float GetM20() const { return m20; }
	float GetM21() const { return m21; }
	float GetM22() const { return m22; }
	float GetM23() const { return m23; }
	float GetM30() const { return m30; }
	float GetM31() const { return m31; }
	float GetM32() const { return m32; }
	float GetM33() const { return m33; }

	// Setters
	void Set(float a00, float a01, float a02, float a03,
		float a10, float a11, float a12, float a13,
		float a20, float a21, float a22, float a23,
		float a30, float a31, float a32, float a33) {
		m00 = a00; m01 = a01; m02 = a02; m03 = a03;
		m10 = a10; m11 = a11; m12 = a12; m13 = a13;
		m20 = a20; m21 = a21; m22 = a22; m23 = a23;
		m30 = a30; m31 = a31; m32 = a32; m33 = a33;
	}

	void Set(const Matriz4x4& other) {
		m00 = other.m00; m01 = other.m01; m02 = other.m02; m03 = other.m03;
		m10 = other.m10; m11 = other.m11; m12 = other.m12; m13 = other.m13;
		m20 = other.m20; m21 = other.m21; m22 = other.m22; m23 = other.m23;
		m30 = other.m30; m31 = other.m31; m32 = other.m32; m33 = other.m33;
	}

	// UTILIDADES
	std::string ToString() const {
		return "[" + std::to_string(m00) + ", " + std::to_string(m01) + ", " + std::to_string(m02) + ", " + std::to_string(m03) + "]\n" +
			"[" + std::to_string(m10) + ", " + std::to_string(m11) + ", " + std::to_string(m12) + ", " + std::to_string(m13) + "]\n" +
			"[" + std::to_string(m20) + ", " + std::to_string(m21) + ", " + std::to_string(m22) + ", " + std::to_string(m23) + "]\n" +
			"[" + std::to_string(m30) + ", " + std::to_string(m31) + ", " + std::to_string(m32) + ", " + std::to_string(m33) + "]";
	}

	//Matriz transpuesta
	Matriz4x4 Transpose() const {
		return Matriz4x4(
			m00, m10, m20, m30,
			m01, m11, m21, m31,
			m02, m12, m22, m32,
			m03, m13, m23, m33
		);
	}

	//Matriz inversa
	Matriz4x4 Inverse() const {
		float det = Determinante();
		if (det == 0.0f) {
			__noop("Matriz4x4", "Inversa", "Matriz no tiene Inversa (Su determinante es 0)");
			return Matriz4x4(); // Return identity matrix if not invertible
		}
		float invDet = 1.0f / det;

		// Helper lambda to compute the determinant of a 3x3 submatrix
		auto minor = [&](int r0, int r1, int r2, int c0, int c1, int c2) -> float {
			const float m[4][4] = {
				{m00, m01, m02, m03},
				{m10, m11, m12, m13},
				{m20, m21, m22, m23},
				{m30, m31, m32, m33}
			};
			return
				m[r0][c0] * (m[r1][c1] * m[r2][c2] - m[r1][c2] * m[r2][c1]) -
				m[r0][c1] * (m[r1][c0] * m[r2][c2] - m[r1][c2] * m[r2][c0]) +
				m[r0][c2] * (m[r1][c0] * m[r2][c1] - m[r1][c1] * m[r2][c0]);
			};

		float cof00 = minor(1, 2, 3, 1, 2, 3);
		float cof01 = -minor(1, 2, 3, 0, 2, 3);
		float cof02 = minor(1, 2, 3, 0, 1, 3);
		float cof03 = -minor(1, 2, 3, 0, 1, 2);

		float cof10 = -minor(0, 2, 3, 1, 2, 3);
		float cof11 = minor(0, 2, 3, 0, 2, 3);
		float cof12 = -minor(0, 2, 3, 0, 1, 3);
		float cof13 = minor(0, 2, 3, 0, 1, 2);

		float cof20 = minor(0, 1, 3, 1, 2, 3);
		float cof21 = -minor(0, 1, 3, 0, 2, 3);
		float cof22 = minor(0, 1, 3, 0, 1, 3);
		float cof23 = -minor(0, 1, 3, 0, 1, 2);

		float cof30 = -minor(0, 1, 2, 1, 2, 3);
		float cof31 = minor(0, 1, 2, 0, 2, 3);
		float cof32 = -minor(0, 1, 2, 0, 1, 3);
		float cof33 = minor(0, 1, 2, 0, 1, 2);

		return Matriz4x4(
			cof00 * invDet, cof01 * invDet, cof02 * invDet, cof03 * invDet,
			cof10 * invDet, cof11 * invDet, cof12 * invDet, cof13 * invDet,
			cof20 * invDet, cof21 * invDet, cof22 * invDet, cof23 * invDet,
			cof30 * invDet, cof31 * invDet, cof32 * invDet, cof33 * invDet
		).Transpose();
	}

	// Determinante de la matriz
	float Determinante() const {
		// Cálculo del determinante de una matriz 4x4 usando la regla de Sarrus o expansión por cofactores
		float det =
			m00 * (m11 * (m22 * m33 - m23 * m32) - m12 * (m21 * m33 - m23 * m31) + m13 * (m21 * m32 - m22 * m31)) -
			m01 * (m10 * (m22 * m33 - m23 * m32) - m12 * (m20 * m33 - m23 * m30) + m13 * (m20 * m32 - m22 * m30)) +
			m02 * (m10 * (m21 * m33 - m23 * m31) - m11 * (m20 * m33 - m23 * m30) + m13 * (m20 * m31 - m21 * m30)) -
			m03 * (m10 * (m21 * m32 - m22 * m31) - m11 * (m20 * m32 - m22 * m30) + m12 * (m20 * m31 - m21 * m30));
		return det;
	}

	//Suma de dos matrices 4x4
	Matriz4x4 operator+(const Matriz4x4& rhs) const {
		return Matriz4x4(
			m00 + rhs.m00, m01 + rhs.m01, m02 + rhs.m02, m03 + rhs.m03,
			m10 + rhs.m10, m11 + rhs.m11, m12 + rhs.m12, m13 + rhs.m13,
			m20 + rhs.m20, m21 + rhs.m21, m22 + rhs.m22, m23 + rhs.m23,
			m30 + rhs.m30, m31 + rhs.m31, m32 + rhs.m32, m33 + rhs.m33
		);
	}

	//Resta de dos matrices 4x4
	Matriz4x4 operator-(const Matriz4x4& rhs) const {
		return Matriz4x4(
			m00 - rhs.m00, m01 - rhs.m01, m02 - rhs.m02, m03 - rhs.m03,
			m10 - rhs.m10, m11 - rhs.m11, m12 - rhs.m12, m13 - rhs.m13,
			m20 - rhs.m20, m21 - rhs.m21, m22 - rhs.m22, m23 - rhs.m23,
			m30 - rhs.m30, m31 - rhs.m31, m32 - rhs.m32, m33 - rhs.m33
		);
	}

	//Multiplicación de dos matrices 4x4
	Matriz4x4 operator*(const Matriz4x4& rhs) const {
		return Matriz4x4(
			m00 * rhs.m00 + m01 * rhs.m10 + m02 * rhs.m20 + m03 * rhs.m30,
			m00 * rhs.m01 + m01 * rhs.m11 + m02 * rhs.m21 + m03 * rhs.m31,
			m00 * rhs.m02 + m01 * rhs.m12 + m02 * rhs.m22 + m03 * rhs.m32,
			m00 * rhs.m03 + m01 * rhs.m13 + m02 * rhs.m23 + m03 * rhs.m33,
			m10 * rhs.m00 + m11 * rhs.m10 + m12 * rhs.m20 + m13 * rhs.m30,
			m10 * rhs.m01 + m11 * rhs.m11 + m12 * rhs.m21 + m13 * rhs.m31,
			m10 * rhs.m02 + m11 * rhs.m12 + m12 * rhs.m22 + m13 * rhs.m32,
			m10 * rhs.m03 + m11 * rhs.m13 + m12 * rhs.m23 + m13 * rhs.m33,
			m20 * rhs.m00 + m21 * rhs.m10 + m22 * rhs.m20 + m23 * rhs.m30,
			m20 * rhs.m01 + m21 * rhs.m11 + m22 * rhs.m21 + m23 * rhs.m31,
			m20 * rhs.m02 + m21 * rhs.m12 + m22 * rhs.m22 + m23 * rhs.m32,
			m20 * rhs.m03 + m21 * rhs.m13 + m22 * rhs.m23 + m23 * rhs.m33,
			m30 * rhs.m00 + m31 * rhs.m10 + m32 * rhs.m20 + m33 * rhs.m30,
			m30 * rhs.m01 + m31 * rhs.m11 + m32 * rhs.m21 + m33 * rhs.m31,
			m30 * rhs.m02 + m31 * rhs.m12 + m32 * rhs.m22 + m33 * rhs.m32,
			m30 * rhs.m03 + m31 * rhs.m13 + m32 * rhs.m23 + m33 * rhs.m33
		);
	}

	// Multiplicación de la matriz por un escalar
	Matriz4x4 operator*(float scalar) const {
		return Matriz4x4(
			m00 * scalar, m01 * scalar, m02 * scalar, m03 * scalar,
			m10 * scalar, m11 * scalar, m12 * scalar, m13 * scalar,
			m20 * scalar, m21 * scalar, m22 * scalar, m23 * scalar,
			m30 * scalar, m31 * scalar, m32 * scalar, m33 * scalar
		);
	}

	// Division de la matriz entre un escalar
	Matriz4x4 operator/(float scalar) const {
		if (scalar == 0.0f) {
			__noop("Matriz4x4", "operator/", "Division by zero scalar");
			return Matriz4x4(); // Retorna matriz identidad si se intenta dividir por cero
		}
		return Matriz4x4(
			m00 / scalar, m01 / scalar, m02 / scalar, m03 / scalar,
			m10 / scalar, m11 / scalar, m12 / scalar, m13 / scalar,
			m20 / scalar, m21 / scalar, m22 / scalar, m23 / scalar,
			m30 / scalar, m31 / scalar, m32 / scalar, m33 / scalar
		);
	}

	// Add this operator to Matriz4x4 to support *= with a scalar
	Matriz4x4& operator*=(float scalar) {
		m00 *= scalar; m01 *= scalar; m02 *= scalar; m03 *= scalar;
		m10 *= scalar; m11 *= scalar; m12 *= scalar; m13 *= scalar;
		m20 *= scalar; m21 *= scalar; m22 *= scalar; m23 *= scalar;
		m30 *= scalar; m31 *= scalar; m32 *= scalar; m33 *= scalar;
		return *this;
	}

	// Add this operator to Matriz4x4 to support /= with a scalar
	Matriz4x4& operator/=(float scalar) {
		if (scalar == 0.0f) {
			__noop("Matriz4x4", "operator/=", "Division by zero scalar");

			// Set to identity matrix on division by zero
			m00 = 1.0f; m01 = 0.0f; m02 = 0.0f; m03 = 0.0f;
			m10 = 0.0f; m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
			m20 = 0.0f; m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
			m30 = 0.0f; m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
			return *this;
		}
		m00 /= scalar; m01 /= scalar; m02 /= scalar; m03 /= scalar;
		m10 /= scalar; m11 /= scalar; m12 /= scalar; m13 /= scalar;
		m20 /= scalar; m21 /= scalar; m22 /= scalar; m23 /= scalar;
		m30 /= scalar; m31 /= scalar; m32 /= scalar; m33 /= scalar;
		return *this;
	}


private:
	float m00, m01, m02, m03;
	float m10, m11, m12, m13;
	float m20, m21, m22, m23;
	float m30, m31, m32, m33;
};