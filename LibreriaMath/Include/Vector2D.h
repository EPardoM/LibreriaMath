#pragma once

#include "Prerequisites.h"

class Vector2D {


public:

	//CONSTUCTORES

	//Constructor por defecto. Inicializa el vector en (0,0).
	Vector2D() : m_x(0.0f), m_y(0.0f) {}

	//Constructor principal.
	Vector2D(float x, float y) : m_x(x), m_y(y) {}

	//Constructor de copia.
	Vector2D(const Vector2D& other) : m_x(other.m_x), m_y(other.m_y) {}

	//Destructor de la clase
	~Vector2D() = default;


	//METODOS PUBLICOS

	//Getters y Setters
	float GetX() const {
		return m_x;
	}

	float GetY() const {
		return m_y;
	}

	//Setter que establece el valor de X o Y individualmente
	void SetX(float value) {
		m_x = value;
	}

	void SetY(float value) {
		m_y = value;
	}

	//Establece ambos valores del vector
	void Set(float newX, float newY) {
		m_x = newX; m_y = newY;
	}

	void Set(const Vector2D& other) {
		m_x = other.m_x; m_y = other.m_y;
	}

	Vector2D set() const {
		return Vector2D(m_x, m_y);
	}

	//Metodo para calcular la magnitud del vector
	float Magnitude() const {
		return sqrt(m_x * m_x + m_y * m_y);
	}

	//Metodo para calcular la magnitud al cuadrado del vector
	float SqrMagnitude() const {
		return m_x * m_x + m_y * m_y;
	}

	void Normalize() {
		float m = Magnitude();
		if (m > 0.0f) {
			m_x /= m;
			m_y /= m;
		}
	}

	Vector2D Normalized() const {
		float m = Magnitude();
		if (m == 0.0f) {
			return Vector2D(0.0f, 0.0f);
		}
		return Vector2D(m_x / m, m_y / m);
	}

	//OPERACIONES VECTORIALES

	//Producto punto entre este vector y otro
	float Dot(const Vector2D& other) const {
		return m_x * other.m_x + m_y * other.m_y;
	}

	//Distancia entre dos vectores.
	float Distance(const Vector2D& other) const {
		float dx = m_x - other.m_x;
		float dy = m_y - other.m_y;
		return sqrt(dx * dx + dy * dy);
	}

	//Devuelve un vector perpendicular a este vector (rotado 90 grados)
	Vector2D Perpendicular() const {
		return Vector2D(-m_y, m_x);
	}

	//Limita la magnitud del vector.
	void ClampMagnitude(float maxLength) {
		float m = Magnitude();
		if (m > maxLength) {
			Normalize();
			m_x *= maxLength;
			m_y *= maxLength;
		}
	}

	//SOBRECARGA DE OPERADORES

	//Suma de dos vectores
	Vector2D operator+(const Vector2D& rhs) const {
		return Vector2D(m_x + rhs.m_x, m_y + rhs.m_y);
	}

	//Resta de dos vectores
	Vector2D operator-(const Vector2D& rhs) const {
		return Vector2D(m_x - rhs.m_x, m_y - rhs.m_y);
	}

	//Suma directa al vector actual
	Vector2D operator+=(const Vector2D& rhs) {
		m_x += rhs.m_x; //Suma de igualación
		m_y += rhs.m_y; //Suma de igualación
		return *this;
	}

	//Resta directa al vector actual
	Vector2D operator-=(const Vector2D& rhs) {
		m_x -= rhs.m_x; //Resta de igualación
		m_y -= rhs.m_y; //Resta de igualación
		return *this;
	}

	//Multiplicación por un escalar
	Vector2D operator*(float scalar) const {
		return Vector2D(m_x * scalar, m_y * scalar);
	}

	//División por un escalar
	Vector2D operator/(float scalar) const {
		return Vector2D(m_x / scalar, m_y / scalar);
	}

	//Multiplicación directa por un escalar
	Vector2D operator*=(float scalar) {
		m_x *= scalar; //Multiplicación de igualación
		m_y *= scalar; //Multiplicación de igualación
		return *this;
	}

	//División directa por un escalar
	Vector2D operator/=(float scalar) {
		m_x /= scalar; //División de igualación
		m_y /= scalar; //División de igualación
		return *this;
	}

	//Operador unario negativo
	Vector2D operator-() const {
		return Vector2D(-m_x, -m_y);
	}

	//Comparador por igualdad
	bool operator==(const Vector2D& rhs) const {
		return (m_x == rhs.m_x) && (m_y == rhs.m_y);
	}

	//Comparador por desigualdad
	bool operator!=(const Vector2D& rhs) const {
		return !(*this == rhs);
	}

	//UTILIDADES

	//Interpolación lineal (lerp) entre dos vectores
	static Vector2D Lerp(const Vector2D& start, const Vector2D& end, float t) {
		if (t < 0.0f) t = 0.0f;
		if (t > 1.0f) t = 1.0f;
		return Vector2D(
			start.m_x + (end.m_x - start.m_x) * t,
			start.m_y + (end.m_y - start.m_y) * t
		);
	}

	//Devuelve un string con el formato del vector "(x, y)"
	std::string ToString() const {
		std::ostringstream os;
		os << "(" << m_x << ", " << m_y << ")";
		return os.str();
	}

private:
	float m_x;
	float m_y;

};