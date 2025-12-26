#pragma once

#include "Prerequisites.h"

class Vector3D {

public:
	//CONSTUCTORES

	//Constructor por defecto. Inicializa el vector en (0,0,0).
	Vector3D() : m_x(0.0f), m_y(0.0f), m_z(0.0f) {}

	//Constructor principal.
	Vector3D(float x, float y, float z) : m_x(x), m_y(y), m_z(z) {}

	//Constructor de copia.
	Vector3D(const Vector3D& other) : m_x(other.m_x), m_y(other.m_y), m_z(other.m_z) {}

	//Destructor de la clase
	~Vector3D() = default;

	//METODOS PUBLICOS

	//Getters y Setters
	float GetX() const {
		return m_x;
	}

	float GetY() const {
		return m_y;
	}

	float GetZ() const {
		return m_z;
	}

	//Setter que establece el valor de X, Y o Z individualmente
	void SetX(float value) {
		m_x = value;
	}

	void SetY(float value) {
		m_y = value;
	}

	void SetZ(float value) {
		m_z = value;
	}

	//Establece los valores del vector
	void Set(float newX, float newY, float newZ) {
		m_x = newX; m_y = newY; m_z = newZ;
	}

	void Set(const Vector3D& other) {
		m_x = other.m_x; m_y = other.m_y; m_z = other.m_z;
	}

	Vector3D set() const {
		return Vector3D(m_x, m_y, m_z);
	}

	//Metodo para calcular la magnitud del vector
	float Magnitude() const {
		return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
	}

	//Metodo para calcular la magnitud al cuadrado del vector
	float SqrMagnitude() const {
		return m_x * m_x + m_y * m_y + m_z * m_z;
	}

	//Metodo para normalizar el vector
	void Normalize() {
		float m = Magnitude();
		if (m > 0.0f) {
			m_x /= m;
			m_y /= m;
			m_z /= m;
		}
	}

	//Metodo para devolver el vector normalizado sin modificar el original
	Vector3D Normalized() const {
		float m = Magnitude();
		if (m == 0.0f) {
			return Vector3D(0.0f, 0.0f, 0.0f);
		}
		return Vector3D(m_x / m, m_y / m, m_z / m);
	}

	//OPERACIONES VECTORIALES

	//Producto punto entre este vector y otro
	float Dot(const Vector3D& other) const {
		return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
	}

	//Distancia entre dos vectores.
	float Distance(const Vector3D& other) const {
		float dx = m_x - other.m_x;
		float dy = m_y - other.m_y;
		float dz = m_z - other.m_z;
		return sqrt(dx * dx + dy * dy + dz * dz);
	}

	//Devuelve un vector perpendicular a este vector (producto cruz)
	Vector3D Cross(const Vector3D& other) const {
		return Vector3D(
			m_y * other.m_z - m_z * other.m_y,
			m_z * other.m_x - m_x * other.m_z,
			m_x * other.m_y - m_y * other.m_x
		);
	}

	//Limita la magnitud del vector.
	void ClampMagnitude(float maxLength) {
		float sqrMag = SqrMagnitude();
		if (sqrMag > maxLength * maxLength) {
			float factor = maxLength / sqrt(sqrMag);
			m_x *= factor;
			m_y *= factor;
			m_z *= factor;
		}
	}

	//SOBRECARGA DE OPERADORES

	//Suma de dos vectores
	Vector3D operator+(const Vector3D& rhs) const {
		return Vector3D(m_x + rhs.m_x, m_y + rhs.m_y, m_z + rhs.m_z);
	}

	//Resta de dos vectores
	Vector3D operator-(const Vector3D& rhs) const {
		return Vector3D(m_x - rhs.m_x, m_y - rhs.m_y, m_z - rhs.m_z);
	}

	//Suma directa al vector actual
	Vector3D operator+=(const Vector3D& rhs) {
		m_x += rhs.m_x; //Suma de igualación
		m_y += rhs.m_y; //Suma de igualación
		m_z += rhs.m_z; //Suma de igualación
		return *this;
	}

	//Resta directa al vector actual
	Vector3D operator-=(const Vector3D& rhs) {
		m_x -= rhs.m_x; //Resta de igualación
		m_y -= rhs.m_y; //Resta de igualación
		m_z -= rhs.m_z; //Resta de igualación
		return *this;
	}

	//Multiplicación por un escalar
	Vector3D operator*(float scalar) const {
		return Vector3D(m_x * scalar, m_y * scalar, m_z * scalar);
	}

	//División por un escalar
	Vector3D operator/(float scalar) const {
		if (scalar != 0.0f) {
			return Vector3D(m_x / scalar, m_y / scalar, m_z / scalar);
		}
		else {
			__noop("Vector3D", "operator/", "Division by zero");
			return Vector3D(0.0f, 0.0f, 0.0f); // Return zero vector on division by zero
		}
	}

	//Multiplicación directa por un escalar
	Vector3D operator*=(float scalar) {
		m_x *= scalar;
		m_y *= scalar;
		m_z *= scalar;
		return *this;
	}

	//División directa por un escalar
	Vector3D operator/=(float scalar) {
		if (scalar != 0.0f) {
			m_x /= scalar;
			m_y /= scalar;
			m_z /= scalar;
		}
		else {
			__noop("Vector3D", "operator/=", "Division by zero");
			m_x = 0.0f;
			m_y = 0.0f;
			m_z = 0.0f; // Set to zero vector on division by zero
		}
		return *this;
	}

	//Operador unario negativo
	Vector3D operator-() const {
		return Vector3D(-m_x, -m_y, -m_z);
	}

	//Comparador por igualdad
	bool operator==(const Vector3D& rhs) const {
		return (m_x == rhs.m_x) && (m_y == rhs.m_y) && (m_z == rhs.m_z);
	}

	//Comparador por desigualdad
	bool operator!=(const Vector3D& rhs) const {
		return !(*this == rhs);
	}

	//UTILIDADES

	//Interpolación lineal (lerp) entre dos vectores
	static Vector3D Lerp(const Vector3D& start, const Vector3D& end, float t) {
		if (t < 0.0f) t = 0.0f;
		if (t > 1.0f) t = 1.0f;
		return Vector3D(
			start.m_x + (end.m_x - start.m_x) * t,
			start.m_y + (end.m_y - start.m_y) * t,
			start.m_z + (end.m_z - start.m_z) * t
		);
	}

	//Devuelve un string con el formato del vector "(x, y, z)"
	std::string ToString() const {
		std::ostringstream os;
		os << "(" << m_x << ", " << m_y << ", " << m_z << ")";
		return os.str();
	}

private:
	float m_x;
	float m_y;
	float m_z;

};