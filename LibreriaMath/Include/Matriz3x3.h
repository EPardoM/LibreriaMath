
#pragma once
#include "Prerequisites.h"

class Matriz3x3 {
public:
    // CONSTRUCTORES

    // Constructor por defecto. Inicializa la matriz como la identidad.
    Matriz3x3()
        : m00(1.0f), m01(0.0f), m02(0.0f),
        m10(0.0f), m11(1.0f), m12(0.0f),
        m20(0.0f), m21(0.0f), m22(1.0f) {
    }

    // Constructor principal.
    Matriz3x3(float a00, float a01, float a02,
        float a10, float a11, float a12,
        float a20, float a21, float a22)
        : m00(a00), m01(a01), m02(a02),
        m10(a10), m11(a11), m12(a12),
        m20(a20), m21(a21), m22(a22) {
    }

    // Constructor de copia.
    Matriz3x3(const Matriz3x3& other)
        : m00(other.m00), m01(other.m01), m02(other.m02),
        m10(other.m10), m11(other.m11), m12(other.m12),
        m20(other.m20), m21(other.m21), m22(other.m22) {
    }

    // Destructor de la clase
    ~Matriz3x3() = default;

    // Getters
    float GetM00() const { return m00; }
    float GetM01() const { return m01; }
    float GetM02() const { return m02; }
    float GetM10() const { return m10; }
    float GetM11() const { return m11; }
    float GetM12() const { return m12; }
    float GetM20() const { return m20; }
    float GetM21() const { return m21; }
    float GetM22() const { return m22; }

    // Setters
    void Set(float a00, float a01, float a02,
        float a10, float a11, float a12,
        float a20, float a21, float a22) {
        m00 = a00; m01 = a01; m02 = a02;
        m10 = a10; m11 = a11; m12 = a12;
        m20 = a20; m21 = a21; m22 = a22;
    }

    void Set(const Matriz3x3& other) {
        m00 = other.m00; m01 = other.m01; m02 = other.m02;
        m10 = other.m10; m11 = other.m11; m12 = other.m12;
        m20 = other.m20; m21 = other.m21; m22 = other.m22;
    }

    // UTILIDADES
    std::string ToString() const {
        return "[" + std::to_string(m00) + ", " + std::to_string(m01) + ", " + std::to_string(m02) + "]\n" +
            "[" + std::to_string(m10) + ", " + std::to_string(m11) + ", " + std::to_string(m12) + "]\n" +
            "[" + std::to_string(m20) + ", " + std::to_string(m21) + ", " + std::to_string(m22) + "]";
    }

    // Matriz transpuesta
    Matriz3x3 Transpose() const {
        return Matriz3x3(
            m00, m10, m20,
            m01, m11, m21,
            m02, m12, m22
        );
    }

    // Matriz inversa
    Matriz3x3 Inverse() const {
        float det =
            m00 * (m11 * m22 - m12 * m21) -
            m01 * (m10 * m22 - m12 * m20) +
            m02 * (m10 * m21 - m11 * m20);

        if (det == 0.0f) {
            __noop("Matriz3x3", "Inverse", "Matrix is not invertible (determinant is zero)");
            return Matriz3x3(); // Return identity matrix if not invertible
        }

        float invDet = 1.0f / det;

        return Matriz3x3(
            (m11 * m22 - m12 * m21) * invDet,
            (m02 * m21 - m01 * m22) * invDet,
            (m01 * m12 - m02 * m11) * invDet,

            (m12 * m20 - m10 * m22) * invDet,
            (m00 * m22 - m02 * m20) * invDet,
            (m02 * m10 - m00 * m12) * invDet,

            (m10 * m21 - m11 * m20) * invDet,
            (m01 * m20 - m00 * m21) * invDet,
            (m00 * m11 - m01 * m10) * invDet
        );
    }

    // Determinante
    float Determinant() const {
        return m00 * (m11 * m22 - m12 * m21)
            - m01 * (m10 * m22 - m12 * m20)
            + m02 * (m10 * m21 - m11 * m20);
    }

    // Sobrecarga del operador /= para la división por un escalar
    Matriz3x3& operator/=(float scalar) {
        if (scalar == 0.0f) {
            __noop("Matriz3x3", "operator/=", "Division by zero scalar");
            // Establecer como matriz identidad en caso de división por cero
            m00 = 1.0f; m01 = 0.0f; m02 = 0.0f;
            m10 = 0.0f; m11 = 1.0f; m12 = 0.0f;
            m20 = 0.0f; m21 = 0.0f; m22 = 1.0f;
            return *this;
        }
        m00 /= scalar; m01 /= scalar; m02 /= scalar;
        m10 /= scalar; m11 /= scalar; m12 /= scalar;
        m20 /= scalar; m21 /= scalar; m22 /= scalar;
        return *this;
    }

    // Add this operator to Matriz3x3 to support *= with a scalar
    Matriz3x3& operator*=(float scalar) {
        m00 *= scalar; m01 *= scalar; m02 *= scalar;
        m10 *= scalar; m11 *= scalar; m12 *= scalar;
        m20 *= scalar; m21 *= scalar; m22 *= scalar;
        return *this;
    }

    // Add this operator to Matriz3x3 to support division by a scalar
    Matriz3x3 operator/(float scalar) const {
        if (scalar == 0.0f) {
            __noop("Matriz3x3", "operator/", "Division by zero scalar");
            return Matriz3x3(); // Return identity matrix if division by zero
        }
        return Matriz3x3(
            m00 / scalar, m01 / scalar, m02 / scalar,
            m10 / scalar, m11 / scalar, m12 / scalar,
            m20 / scalar, m21 / scalar, m22 / scalar
        );
    }

    // Add this operator to Matriz3x3 to support multiplication by a scalar
    Matriz3x3 operator*(float scalar) const {
        return Matriz3x3(
            m00 * scalar, m01 * scalar, m02 * scalar,
            m10 * scalar, m11 * scalar, m12 * scalar,
            m20 * scalar, m21 * scalar, m22 * scalar
        );
    }

    // Suma de dos matrices 3x3
    Matriz3x3 operator+(const Matriz3x3& rhs) const {
        return Matriz3x3(
            m00 + rhs.m00, m01 + rhs.m01, m02 + rhs.m02,
            m10 + rhs.m10, m11 + rhs.m11, m12 + rhs.m12,
            m20 + rhs.m20, m21 + rhs.m21, m22 + rhs.m22
        );
    }

    // Resta de dos matrices 3x3
    Matriz3x3 operator-(const Matriz3x3& rhs) const {
        return Matriz3x3(
            m00 - rhs.m00, m01 - rhs.m01, m02 - rhs.m02,
            m10 - rhs.m10, m11 - rhs.m11, m12 - rhs.m12,
            m20 - rhs.m20, m21 - rhs.m21, m22 - rhs.m22
        );
    }

    // Multiplicación de dos matrices 3x3
    Matriz3x3 operator*(const Matriz3x3& rhs) const {
        return Matriz3x3(
            m00 * rhs.m00 + m01 * rhs.m10 + m02 * rhs.m20,
            m00 * rhs.m01 + m01 * rhs.m11 + m02 * rhs.m21,
            m00 * rhs.m02 + m01 * rhs.m12 + m02 * rhs.m22,

            m10 * rhs.m00 + m11 * rhs.m10 + m12 * rhs.m20,
            m10 * rhs.m01 + m11 * rhs.m11 + m12 * rhs.m21,
            m10 * rhs.m02 + m11 * rhs.m12 + m12 * rhs.m22,

            m20 * rhs.m00 + m21 * rhs.m10 + m22 * rhs.m20,
            m20 * rhs.m01 + m21 * rhs.m11 + m22 * rhs.m21,
            m20 * rhs.m02 + m21 * rhs.m12 + m22 * rhs.m22
        );
    }

private:
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};