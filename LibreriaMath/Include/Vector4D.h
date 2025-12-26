#pragma once

#include "Prerequisites.h"

class Vector4D {

public:

	//CONSTUCTORES

	//Constructor por defecto. Inicializa el vector en (0,0,0,0).
	Vector4D() : m_x(0.0f), m_y(0.0f), m_z(0.0f), m_w(0.0f) {}

	//Constructor principal.
	Vector4D(float x, float y, float z, float w) : m_x(x), m_y(y), m_z(z), m_w(w) {}

	//Constructor de copia.
	Vector4D(const Vector4D& other) : m_x(other.m_x), m_y(other.m_y), m_z(other.m_z), m_w(other.m_w) {}

	//Destructor de la clase
	~Vector4D() = default;


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

	float GetW() const {
		return m_w;
	}

	//Setter que establece el valor de X, Y, Z o W individualmente
	void SetX(float value) {
		m_x = value;
	}

	void SetY(float value) {
		m_y = value;
	}

	void SetZ(float value) {
		m_z = value;
	}

	void SetW(float value) {
		m_w = value;
	}

	//Establece los valores del vector
	void Set(float newX, float newY, float newZ, float newW) {
		m_x = newX; m_y = newY; m_z = newZ; m_w = newW;
	}

	void Set(const Vector4D& other) {
		m_x = other.m_x; m_y = other.m_y; m_z = other.m_z; m_w = other.m_w;
	}

	Vector4D set() const {
		return Vector4D(m_x, m_y, m_z, m_w);
	}

	//Metodo para calcular la magnitud del vector
	float Magnitude() const {
		return sqrt(m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w);
	}

	//Metodo para calcular la magnitud al cuadrado del vector
	float SqrMagnitude() const {
		return m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w;
	}

	//Metodo para normalizar el vector
	void Normalize() {
		float m = Magnitude();
		if (m > 0.0f) {
			m_x /= m;
			m_y /= m;
			m_z /= m;
			m_w /= m;
		}
	}

	//Metodo para devolver el vector normalizado sin modificar el original
	Vector4D Normalized() const {
		float m = Magnitude();
		if (m == 0.0f) {
			return Vector4D(0.0f, 0.0f, 0.0f, 0.0f);
		}
		return Vector4D(m_x / m, m_y / m, m_z / m, m_w / m);
	}

	//OPERACIONES VECTORIALES

	//Producto punto entre este vector y otro
	float Dot(const Vector4D& other) const {
		return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z + m_w * other.m_w;
	}

	//Distancia entre dos vectores.
	float Distance(const Vector4D& other) const {
		float dx = m_x - other.m_x;
		float dy = m_y - other.m_y;
		float dz = m_z - other.m_z;
		float dw = m_w - other.m_w;
		return sqrt(dx * dx + dy * dy + dz * dz + dw * dw);
	}

	//Limita la magnitud del vector.
	void ClampMagnitude(float maxLength) {
		float sqrMag = SqrMagnitude();
		if (sqrMag > maxLength * maxLength) {
			float factor = maxLength / sqrt(sqrMag);
			m_x *= factor;
			m_y *= factor;
			m_z *= factor;
			m_w *= factor;
		}
	}


	//SOBRECARGA DE OPERADORES

	//Suma de dos vectores
	Vector4D operator+(const Vector4D& rhs) const {
		return Vector4D(m_x + rhs.m_x, m_y + rhs.m_y, m_z + rhs.m_z, m_w + rhs.m_w);
	}

	//Resta de dos vectores
	Vector4D operator-(const Vector4D& rhs) const {
		return Vector4D(m_x - rhs.m_x, m_y - rhs.m_y, m_z - rhs.m_z, m_w - rhs.m_w);
	}

	//Suma directa al vector actual
	Vector4D operator+=(const Vector4D& rhs) {
		m_x += rhs.m_x; //Suma de igualación
		m_y += rhs.m_y; //Suma de igualación
		m_z += rhs.m_z; //Suma de igualación
		m_w += rhs.m_w; //Suma de igualación
		return *this;
	}

	//Resta directa al vector actual
	Vector4D operator-=(const Vector4D& rhs) {
		m_x -= rhs.m_x; //Resta de igualación
		m_y -= rhs.m_y; //Resta de igualación
		m_z -= rhs.m_z; //Resta de igualación
		m_w -= rhs.m_w; //Resta de igualación
		return *this;
	}

	//Multiplicación por un escalar
	Vector4D operator*(float scalar) const {
		return Vector4D(m_x * scalar, m_y * scalar, m_z * scalar, m_w * scalar);
	}

	//División por un escalar
	Vector4D operator/(float scalar) const {
		if (scalar != 0.0f) {
			return Vector4D(m_x / scalar, m_y / scalar, m_z / scalar, m_w / scalar);
		}
		else {
			__noop("Vector4D", "operator/", "Division by zero");
			return Vector4D(0.0f, 0.0f, 0.0f, 0.0f); // Return zero vector on division by zero
		}
	}

	//Operador unario negativo
	Vector4D operator-() const {
		return Vector4D(-m_x, -m_y, -m_z, -m_w);
	}

	//Comparador por igualdad
	bool operator==(const Vector4D& rhs) const {
		return (m_x == rhs.m_x) && (m_y == rhs.m_y) && (m_z == rhs.m_z) && (m_w == rhs.m_w);
	}

	//Comparador por desigualdad
	bool operator!=(const Vector4D& rhs) const {
		return !(*this == rhs);
	}


	//	UTILIDADES

	//Interpolación lineal (lerp) entre dos vectores
	static Vector4D Lerp(const Vector4D& start, const Vector4D& end, float t) {
		if (t < 0.0f) t = 0.0f;
		if (t > 1.0f) t = 1.0f;
		return Vector4D(
			start.m_x + (end.m_x - start.m_x) * t,
			start.m_y + (end.m_y - start.m_y) * t,
			start.m_z + (end.m_z - start.m_z) * t,
			start.m_w + (end.m_w - start.m_w) * t
		);
	}

	//Devuelve un string con la representación del vector "(x, y, z, w)"
	std::string ToString() const {
		std::ostringstream os;
		os << "(" << m_x << ", " << m_y << ", " << m_z << ", " << m_w << ")";
		return os.str();
	}

private:
	float m_x;
	float m_y;
	float m_z;
	float m_w;

};
