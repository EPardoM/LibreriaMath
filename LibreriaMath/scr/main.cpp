#include <iostream>
#include <cmath>
#include "Prerequisites.h"
#include "Vector2D.h"
#include "Vector3D.h"
#include "Vector4D.h"
#include "Matriz2x2.h"
#include "Matriz3x3.h"
#include "Matriz4x4.h"
#include "PotenciasRaices.h"
#include "Valores.h"
#include "Trigonometricas.h"
#include "Logaritmicas.h"	
#include "Geometria.h"
#include "Factorial.h"



using namespace std;


int main() {

	std::cout << "-----------------------------------------------------------------------\n";
	std::cout << "VECTOR 2D\n";
	std::cout << "-----------------------------------------------------------------------\n\n";

	// Crear dos vectores
	Vector2D vec1(3.0f, 4.0f);
	Vector2D vec2(1.0f, 2.0f);

	std::cout << "V1: " << vec1.ToString() << "\n";
	std::cout << "V2: " << vec2.ToString() << "\n\n";

	//Magnitud
	std::cout << "Magnitud V1: " << vec1.Magnitude() << "\n";
	std::cout << "Magnitud V2: " << vec2.Magnitude() << "\n\n";

	//Magnitud al cuadrado
	std::cout << "Magnitud al cuadrado V1: " << vec1.SqrMagnitude() << "\n";
	std::cout << "Magnitud al cuadrado V2: " << vec2.SqrMagnitude() << "\n\n";

	//Normalización
	Vector2D normVec1 = vec1.Normalized();
	std::cout << "Normalizacion V1: " << normVec1.ToString() << "\n";
	Vector2D normVec2 = vec2.Normalized();
	std::cout << "Normalizacion V2: " << normVec2.ToString() << "\n\n";

	//Suma
	Vector2D sumVec = vec1 + vec2;
	std::cout << "Suma V1+V2: " << sumVec.ToString() << "\n";

	//Resta
	Vector2D diffVec = vec1 - vec2;
	std::cout << "Resta V1-V2: " << diffVec.ToString() << "\n\n";

	//Multiplicación por escalar
	Vector2D scaledVec = vec1 * 3.0f;
	std::cout << "Multiplicacion V1*3: " << scaledVec.ToString() << "\n";
	Vector2D scaledVec2 = vec2 * 5.0f;
	std::cout << "Multiplicacion V2*5: " << scaledVec2.ToString() << "\n\n";

	//División por escalar
	Vector2D divVec = vec1 / 2.0f;
	std::cout << "Division V1/2: " << divVec.ToString() << "\n";
	Vector2D divVec2 = vec2 / 0.5f;
	std::cout << "Division V2/0.5: " << divVec2.ToString() << "\n\n";

	//Multiplicacion directa por escalar
	vec1 *= 2.0f;
	std::cout << "Multiplicacion directa V1*=2: " << vec1.ToString() << "\n";
	vec2 *= 3.0f;
	std::cout << "Multiplicacion directa V2*=3: " << vec2.ToString() << "\n\n";

	//División directa por escalar
	vec1 /= 2.0f;
	std::cout << "Division directa V1/=2: " << vec1.ToString() << "\n";
	vec2 /= 0.5f;
	std::cout << "Division directa V2/=0.5: " << vec2.ToString() << "\n\n";

	//Operador unario negativo
	Vector2D negVec1 = -vec1;
	std::cout << "Negativo de V1: " << negVec1.ToString() << "\n";
	Vector2D negVec2 = -vec2;
	std::cout << "Negativo de V2: " << negVec2.ToString() << "\n\n";

	// Comparador por igualdad
	bool areEqual = (vec1 == vec2);
	std::cout << "V1 y V2 son iguales? " << (areEqual ? "Si" : "No") << "\n";

	// Comparador por desigualdad
	bool areNotEqual = (vec1 != vec2);
	std::cout << "V1 y V2 son diferentes? " << (areNotEqual ? "Si" : "No") << "\n\n";

	//Distancia entre vectores
	std::cout << "Distancia V1 a V2: " << vec1.Distance(vec2) << "\n\n";

	// Producto punto
	float dot = vec1.Dot(vec2);
	std::cout << "Producto punto V1 y V2: " << dot << "\n\n";

	// Vector perpendicular
	Vector2D perpVec1 = vec1.Perpendicular();
	std::cout << "Perpendicular a V1: " << perpVec1.ToString() << "\n";
	Vector2D perpVec2 = vec2.Perpendicular();
	std::cout << "Perpendicular a V2: " << perpVec2.ToString() << "\n\n";

	// Clamp Magnitud
	Vector2D clampedVect(10.0f, 5.0f);
	std::cout << "V1 original: " << clampedVect.ToString() << "\n";
	clampedVect.ClampMagnitude(5.0f);
	std::cout << "V1 con magnitud limitada a 5: " << clampedVect.ToString() << "\n\n";

	// Interpolación lineal
	Vector2D lerpVec = Vector2D::Lerp(vec1, vec2, 0.5f);
	std::cout << "Lerp {(V1, V2, 0.5): " << lerpVec.ToString() << "\n\n\n";


	std::cout << "-----------------------------------------------------------------------\n";
	std::cout << "VECTOR 3D\n";
	std::cout << "-----------------------------------------------------------------------\n\n";

	// Crear dos vectores 3D
	Vector3D vec3D1(3.0f, 4.0f, 5.0f);
	Vector3D vec3D2(1.0f, 2.0f, 3.0f);

	std::cout << "V1: " << vec3D1.ToString() << "\n";
	std::cout << "V2: " << vec3D2.ToString() << "\n\n";

	//Magnitud
	std::cout << "Magnitud V1: " << vec3D1.Magnitude() << "\n";
	std::cout << "Magnitud V2: " << vec3D2.Magnitude() << "\n\n";

	//Magnitud al cuadrado
	std::cout << "Magnitud al cuadrado V1: " << vec3D1.SqrMagnitude() << "\n";
	std::cout << "Magnitud al cuadrado V2: " << vec3D2.SqrMagnitude() << "\n\n";

	//Normalización
	Vector3D normVec3D1 = vec3D1.Normalized();
	std::cout << "Normalizacion V1: " << normVec3D1.ToString() << "\n";
	Vector3D normVec3D2 = vec3D2.Normalized();
	std::cout << "Normalizacion V2: " << normVec3D2.ToString() << "\n\n";

	//Suma
	Vector3D sumVec3D = vec3D1 + vec3D2;
	std::cout << "Suma V1+V2: " << sumVec3D.ToString() << "\n";

	//Resta
	Vector3D diffVec3D = vec3D1 - vec3D2;
	std::cout << "Resta V1-V2: " << diffVec3D.ToString() << "\n\n";

	//Multiplicación por escalar
	Vector3D scaledVec3D = vec3D1 * 3.0f;
	std::cout << "Multiplicacion V1*3: " << scaledVec3D.ToString() << "\n";
	Vector3D scaledVec32 = vec3D2 * 5.0f;
	std::cout << "Multiplicacion V2*5: " << scaledVec32.ToString() << "\n\n";

	//División por escalar
	Vector3D divVec3D = vec3D1 / 2.0f;
	std::cout << "Division V1/2: " << divVec3D.ToString() << "\n";
	Vector3D divVec32 = vec3D2 / 0.5f;
	std::cout << "Division V2/0.5: " << divVec32.ToString() << "\n\n";

	//Multiplicacion directa por escalar
	vec3D1 *= 2.0f;
	std::cout << "Multiplicacion directa V1*=2: " << vec3D1.ToString() << "\n";
	vec3D2 *= 3.0f;
	std::cout << "Multiplicacion directa V2*=3: " << vec3D2.ToString() << "\n\n";

	//División directa por escalar
	vec3D1 /= 2.0f;
	std::cout << "Division directa V1/=2: " << vec3D1.ToString() << "\n";
	vec3D2 /= 0.5f;
	std::cout << "Division directa V2/=0.5: " << vec3D2.ToString() << "\n\n";

	//Distancia entre vectores
	std::cout << "Distancia V1 a V2: " << vec3D1.Distance(vec3D2) << "\n\n";

	// Producto punto
	float dot3D = vec3D1.Dot(vec3D2);
	std::cout << "Producto punto V1 y V2: " << dot3D << "\n";

	// Producto cruz
	Vector3D crossVec = vec3D1.Cross(vec3D2);
	std::cout << "Producto cruz V1 x V2: " << crossVec.ToString() << "\n\n";

	//Operador unario negativo
	Vector3D negVec3D1 = -vec3D1;
	std::cout << "Negativo de V1: " << negVec3D1.ToString() << "\n";
	Vector3D negVec3D2 = -vec3D2;
	std::cout << "Negativo de V2: " << negVec3D2.ToString() << "\n\n";

	// Comparador por igualdad
	bool isEqual3D = (vec3D1 == vec3D2);
	std::cout << "V1 y V2 son iguales?: " << (isEqual3D ? "Si" : "No") << "\n";

	// Comparador por desigualdad
	bool isNotEqual3D = (vec3D1 != vec3D2);
	std::cout << "V1 y V2 son diferentes?: " << (isNotEqual3D ? "Si" : "No") << "\n\n";

	// Clamp Magnitud
	Vector3D clampedVec3D(10.0f, 5.0f, 2.0f);
	std::cout << "V1 original: " << clampedVec3D.ToString() << "\n";
	clampedVec3D.ClampMagnitude(5.0f);
	std::cout << "V1 con magnitud limitada a 5: " << clampedVec3D.ToString() << "\n\n";

	// Interpolación lineal
	Vector3D lerpVec3D = Vector3D::Lerp(vec3D1, vec3D2, 0.5f);
	std::cout << "Lerp (V1, V2, 0.5): " << lerpVec3D.ToString() << "\n\n\n";


	std::cout << "-----------------------------------------------------------------------\n";
	std::cout << "VECTOR 4D\n";
	std::cout << "-----------------------------------------------------------------------\n\n";

	// Crear dos vectores 4D
	Vector4D vec4D1(3.0f, 4.0f, 5.0f, 6.0f);
	Vector4D vec4D2(1.0f, 2.0f, 3.0f, 4.0f);

	std::cout << "V1: " << vec4D1.ToString() << "\n";
	std::cout << "V2: " << vec4D2.ToString() << "\n\n";

	//Magnitud
	std::cout << "Magnitud V1: " << vec4D1.Magnitude() << "\n";
	std::cout << "Magnitud V2: " << vec4D2.Magnitude() << "\n\n";

	//Magnitud al cuadrado
	std::cout << "Magnitud al cuadrado V1: " << vec4D1.SqrMagnitude() << "\n";
	std::cout << "Magnitud al cuadrado V2: " << vec4D2.SqrMagnitude() << "\n\n";

	//Normalización
	Vector4D normVec4D1 = vec4D1.Normalized();
	std::cout << "Normalizacion V1: " << normVec4D1.ToString() << "\n";
	Vector4D normVec4D2 = vec4D2.Normalized();
	std::cout << "Normalizacion V2: " << normVec4D2.ToString() << "\n\n";

	//Suma
	Vector4D sumVec4D = vec4D1 + vec4D2;
	std::cout << "Suma V1+V2: " << sumVec4D.ToString() << "\n";

	//Resta
	Vector4D diffVec4D = vec4D1 - vec4D2;
	std::cout << "Resta V1-V2: " << diffVec4D.ToString() << "\n\n";

	//Multiplicación por escalar
	Vector4D scaledVec4D = vec4D1 * 3.0f;
	std::cout << "Multiplicacion V1*3: " << scaledVec4D.ToString() << "\n";
	Vector4D scaledVec42 = vec4D2 * 5.0f;
	std::cout << "Multiplicacion V2*5: " << scaledVec42.ToString() << "\n\n";

	//División por escalar
	Vector4D divVec4D = vec4D1 / 2.0f;
	std::cout << "Division V1/2: " << divVec4D.ToString() << "\n";
	Vector4D divVec42 = vec4D2 / 0.5f;
	std::cout << "Division V2/0.5: " << divVec42.ToString() << "\n\n";

	//Multiplicacion directa por escalar
	vec4D1 * 2.0f;
	std::cout << "Multiplicacion directa V1*=2: " << vec4D1.ToString() << "\n";
	vec4D2 * 3.0f;
	std::cout << "Multiplicacion directa V2*=3: " << vec4D2.ToString() << "\n\n";

	//División directa por escalar
	vec4D1 / 2.0f;
	std::cout << "Division directa V1/=2: " << vec4D1.ToString() << "\n";
	vec4D2 / 0.5f;
	std::cout << "Division directa V2/=0.5: " << vec4D2.ToString() << "\n\n";

	//Distancia entre vectores
	std::cout << "Distancia V1 a V2: " << vec4D1.Distance(vec4D2) << "\n\n";

	// Producto punto
	float dot4D = vec4D1.Dot(vec4D2);
	std::cout << "Producto punto V1 y V2: " << dot4D << "\n\n";

	//Operador unario negativo
	Vector4D negVec4D1 = -vec4D1;
	std::cout << "Negativo de V1: " << negVec4D1.ToString() << "\n";
	Vector4D negVec4D2 = -vec4D2;
	std::cout << "Negativo de V2: " << negVec4D2.ToString() << "\n\n";

	// Comparador por igualdad
	bool isEqual4D = (vec4D1 == vec4D2);
	std::cout << "V1 y V2 son iguales?: " << (isEqual4D ? "Si" : "No") << "\n";

	// Comparador por desigualdad
	bool isNotEqual4D = (vec4D1 != vec4D2);
	std::cout << "V1 y V2 son diferentes?: " << (isNotEqual4D ? "Si" : "No") << "\n\n";

	// Clamp Magnitud
	Vector4D clampedVec4D(10.0f, 5.0f, 2.0f, 1.0f);
	std::cout << "V1 original: " << clampedVec4D.ToString() << "\n";
	clampedVec4D.ClampMagnitude(5.0f);
	std::cout << "V1 con magnitud limitada a 5: " << clampedVec4D.ToString() << "\n\n";

	// Interpolación lineal
	Vector4D lerpVec4D = Vector4D::Lerp(vec4D1, vec4D2, 0.5f);
	std::cout << "Lerp (V1, V2, 0.5): " << lerpVec4D.ToString() << "\n\n\n";

	std::cout << "-----------------------------------------------------------------------\n";
	std::cout << "MATRIZ 2X2\n";
	std::cout << "-----------------------------------------------------------------------\n\n";

	// Crear dos matrices 2x2
	Matriz2x2 mat1(
		1.0f, 2.0f,
		3.0f, 4.0f);
	Matriz2x2 mat2(
		5.0f, 6.0f,
		7.0f, 8.0f);

	std::cout << "Matriz 1:\n";
	std::cout << "[" << mat1.GetM00() << ", " << mat1.GetM01() << "]\n";
	std::cout << "[" << mat1.GetM10() << ", " << mat1.GetM11() << "]\n\n";
	std::cout << "Matriz 2:\n";
	std::cout << "[" << mat2.GetM00() << ", " << mat2.GetM01() << "]\n";
	std::cout << "[" << mat2.GetM10() << ", " << mat2.GetM11() << "]\n\n";

	//Suma
	Matriz2x2 sumMat = mat1 + mat2;
	std::cout << "Suma Mat1 + Mat2:\n";
	std::cout << "[" << sumMat.GetM00() << ", " << sumMat.GetM01() << "]\n";
	std::cout << "[" << sumMat.GetM10() << ", " << sumMat.GetM11() << "]\n\n";

	//Resta
	Matriz2x2 diffMat = mat1 - mat2;
	std::cout << "Resta Mat1 - Mat2:\n";
	std::cout << "[" << diffMat.GetM00() << ", " << diffMat.GetM01() << "]\n";
	std::cout << "[" << diffMat.GetM10() << ", " << diffMat.GetM11() << "]\n\n";

	//Multiplicación
	Matriz2x2 prodMat = mat1 * mat2;
	std::cout << "Multiplicacion Mat1 * Mat2:\n";
	std::cout << "[" << prodMat.GetM00() << ", " << prodMat.GetM01() << "]\n";
	std::cout << "[" << prodMat.GetM10() << ", " << prodMat.GetM11() << "]\n\n";

	//Multiplicación por escalar
	Matriz2x2 scaledMat = mat1 * 2.0f;
	std::cout << "Multiplicacion Mat1 * 2:\n";
	std::cout << "[" << scaledMat.GetM00() << ", " << scaledMat.GetM01() << "]\n";
	std::cout << "[" << scaledMat.GetM10() << ", " << scaledMat.GetM11() << "]\n\n";

	Matriz2x2 scaledMat2 = mat2 * 0.5f;
	std::cout << "Multiplicacion Mat2 * 0.5:\n";
	std::cout << "[" << scaledMat2.GetM00() << ", " << scaledMat2.GetM01() << "]\n";
	std::cout << "[" << scaledMat2.GetM10() << ", " << scaledMat2.GetM11() << "]\n\n";

	//División por escalar
	Matriz2x2 divMat = mat1 / 2.0f;
	std::cout << "Division Mat1 / 2:\n";
	std::cout << "[" << divMat.GetM00() << ", " << divMat.GetM01() << "]\n";
	std::cout << "[" << divMat.GetM10() << ", " << divMat.GetM11() << "]\n\n";

	Matriz2x2 divMat2 = mat2 / 0.5f;
	std::cout << "Division Mat2 / 0.5:\n";
	std::cout << "[" << divMat2.GetM00() << ", " << divMat2.GetM01() << "]\n";
	std::cout << "[" << divMat2.GetM10() << ", " << divMat2.GetM11() << "]\n\n";

	//Multiplicacion directa por escalar
	mat1 *= 2.0f;
	std::cout << "Multiplicacion directa Mat1 *= 2:\n";
	std::cout << "[" << mat1.GetM00() << ", " << mat1.GetM01() << "]\n";
	std::cout << "[" << mat1.GetM10() << ", " << mat1.GetM11() << "]\n\n";
	mat2 *= 0.5f;
	std::cout << "Multiplicacion directa Mat2 *= 0.5:\n";
	std::cout << "[" << mat2.GetM00() << ", " << mat2.GetM01() << "]\n";
	std::cout << "[" << mat2.GetM10() << ", " << mat2.GetM11() << "]\n\n";

	//División directa por escalar
	mat1 /= 2.0f;
	std::cout << "Division directa Mat1 /= 2:\n";
	std::cout << "[" << mat1.GetM00() << ", " << mat1.GetM01() << "]\n";
	std::cout << "[" << mat1.GetM10() << ", " << mat1.GetM11() << "]\n\n";
	mat2 /= 0.5f;
	std::cout << "Division directa Mat2 /= 0.5:\n";
	std::cout << "[" << mat2.GetM00() << ", " << mat2.GetM01() << "]\n";
	std::cout << "[" << mat2.GetM10() << ", " << mat2.GetM11() << "]\n\n";

	//Matriz transpuesta
	Matriz2x2 transMat1 = mat1.Transpose();
	std::cout << "Transpuesta de Mat1:\n";
	std::cout << "[" << transMat1.GetM00() << ", " << transMat1.GetM01() << "]\n";
	std::cout << "[" << transMat1.GetM10() << ", " << transMat1.GetM11() << "]\n\n";

	Matriz2x2 transMat2 = mat2.Transpose();
	std::cout << "Transpuesta de Mat2:\n";
	std::cout << "[" << transMat2.GetM00() << ", " << transMat2.GetM01() << "]\n";
	std::cout << "[" << transMat2.GetM10() << ", " << transMat2.GetM11() << "]\n\n\n";

	//Determinante de la matriz
	std::cout << "Determinante de Mat1: " << mat1.Determinante() << "\n";
	std::cout << "Determinante de Mat2: " << mat2.Determinante() << "\n\n\n";


	std::cout << "-----------------------------------------------------------------------\n";
	std::cout << "MATRIZ 3X3\n";
	std::cout << "-----------------------------------------------------------------------\n\n";

	// Crear dos matrices 3x3
	Matriz3x3 mat3x3_1(
		1.0f, 2.0f, 3.0f,
		4.0f, 5.0f, 6.0f,
		7.0f, 8.0f, 9.0f);
	Matriz3x3 mat3x3_2(
		9.0f, 8.0f, 7.0f,
		6.0f, 5.0f, 4.0f,
		3.0f, 2.0f, 1.0f);

	std::cout << "Matriz 1:\n";
	std::cout << "[" << mat3x3_1.GetM00() << ", " << mat3x3_1.GetM01() << ", " << mat3x3_1.GetM02() << "]\n";
	std::cout << "[" << mat3x3_1.GetM10() << ", " << mat3x3_1.GetM11() << ", " << mat3x3_1.GetM12() << "]\n";
	std::cout << "[" << mat3x3_1.GetM20() << ", " << mat3x3_1.GetM21() << ", " << mat3x3_1.GetM22() << "]\n\n";
	std::cout << "Matriz 2:\n";
	std::cout << "[" << mat3x3_2.GetM00() << ", " << mat3x3_2.GetM01() << ", " << mat3x3_2.GetM02() << "]\n";
	std::cout << "[" << mat3x3_2.GetM10() << ", " << mat3x3_2.GetM11() << ", " << mat3x3_2.GetM12() << "]\n";
	std::cout << "[" << mat3x3_2.GetM20() << ", " << mat3x3_2.GetM21() << ", " << mat3x3_2.GetM22() << "]\n\n";

	//Suma
	Matriz3x3 sumMat3x3 = mat3x3_1 + mat3x3_2;
	std::cout << "Suma Mat1 + Mat2:\n";
	std::cout << "[" << sumMat3x3.GetM00() << ", " << sumMat3x3.GetM01() << ", " << sumMat3x3.GetM02() << "]\n";
	std::cout << "[" << sumMat3x3.GetM10() << ", " << sumMat3x3.GetM11() << ", " << sumMat3x3.GetM12() << "]\n";
	std::cout << "[" << sumMat3x3.GetM20() << ", " << sumMat3x3.GetM21() << ", " << sumMat3x3.GetM22() << "]\n\n";

	//Resta
	Matriz3x3 diffMat3x3 = mat3x3_1 - mat3x3_2;
	std::cout << "Resta Mat1 - Mat2:\n";
	std::cout << "[" << diffMat3x3.GetM00() << ", " << diffMat3x3.GetM01() << ", " << diffMat3x3.GetM02() << "]\n";
	std::cout << "[" << diffMat3x3.GetM10() << ", " << diffMat3x3.GetM11() << ", " << diffMat3x3.GetM12() << "]\n";
	std::cout << "[" << diffMat3x3.GetM20() << ", " << diffMat3x3.GetM21() << ", " << diffMat3x3.GetM22() << "]\n\n";

	//Multiplicación
	Matriz3x3 prodMat3x3 = mat3x3_1 * mat3x3_2;
	std::cout << "Multiplicacion Mat1 * Mat2:\n";
	std::cout << "[" << prodMat3x3.GetM00() << ", " << prodMat3x3.GetM01() << ", " << prodMat3x3.GetM02() << "]\n";
	std::cout << "[" << prodMat3x3.GetM10() << ", " << prodMat3x3.GetM11() << ", " << prodMat3x3.GetM12() << "]\n";
	std::cout << "[" << prodMat3x3.GetM20() << ", " << prodMat3x3.GetM21() << ", " << prodMat3x3.GetM22() << "]\n\n";

	//Multiplicación por escalar
	Matriz3x3 scaledMat3x3 = mat3x3_1 * 2.0f;
	std::cout << "Multiplicacion Mat1 * 2:\n";
	std::cout << "[" << scaledMat3x3.GetM00() << ", " << scaledMat3x3.GetM01() << ", " << scaledMat3x3.GetM02() << "]\n";
	std::cout << "[" << scaledMat3x3.GetM10() << ", " << scaledMat3x3.GetM11() << ", " << scaledMat3x3.GetM12() << "]\n";
	std::cout << "[" << scaledMat3x3.GetM20() << ", " << scaledMat3x3.GetM21() << ", " << scaledMat3x3.GetM22() << "]\n\n";

	Matriz3x3 scaledMat32 = mat3x3_2 * 0.5f;
	std::cout << "Multiplicacion Mat2 * 0.5:\n";
	std::cout << "[" << scaledMat32.GetM00() << ", " << scaledMat32.GetM01() << ", " << scaledMat32.GetM02() << "]\n";
	std::cout << "[" << scaledMat32.GetM10() << ", " << scaledMat32.GetM11() << ", " << scaledMat32.GetM12() << "]\n";
	std::cout << "[" << scaledMat32.GetM20() << ", " << scaledMat32.GetM21() << ", " << scaledMat32.GetM22() << "]\n\n";

	//División por escalar
	Matriz3x3 divMat3x3 = mat3x3_1 / 2.0f;
	std::cout << "Division Mat1 / 2:\n";
	std::cout << "[" << divMat3x3.GetM00() << ", " << divMat3x3.GetM01() << ", " << divMat3x3.GetM02() << "]\n";
	std::cout << "[" << divMat3x3.GetM10() << ", " << divMat3x3.GetM11() << ", " << divMat3x3.GetM12() << "]\n";
	std::cout << "[" << divMat3x3.GetM20() << ", " << divMat3x3.GetM21() << ", " << divMat3x3.GetM22() << "]\n\n";

	Matriz3x3 divMat32 = mat3x3_2 / 0.5f;
	std::cout << "Division Mat2 / 0.5:\n";
	std::cout << "[" << divMat32.GetM00() << ", " << divMat32.GetM01() << ", " << divMat32.GetM02() << "]\n";
	std::cout << "[" << divMat32.GetM10() << ", " << divMat32.GetM11() << ", " << divMat32.GetM12() << "]\n";
	std::cout << "[" << divMat32.GetM20() << ", " << divMat32.GetM21() << ", " << divMat32.GetM22() << "]\n\n";

	//Multiplicacion directa por escalar
	mat3x3_1 *= 2.0f;
	std::cout << "Multiplicacion directa Mat1 *= 2:\n";
	std::cout << "[" << mat3x3_1.GetM00() << ", " << mat3x3_1.GetM01() << ", " << mat3x3_1.GetM02() << "]\n";
	std::cout << "[" << mat3x3_1.GetM10() << ", " << mat3x3_1.GetM11() << ", " << mat3x3_1.GetM12() << "]\n";
	std::cout << "[" << mat3x3_1.GetM20() << ", " << mat3x3_1.GetM21() << ", " << mat3x3_1.GetM22() << "]\n\n";

	mat3x3_2 *= 0.5f;
	std::cout << "Multiplicacion directa Mat2 *= 0.5:\n";
	std::cout << "[" << mat3x3_2.GetM00() << ", " << mat3x3_2.GetM01() << ", " << mat3x3_2.GetM02() << "]\n";
	std::cout << "[" << mat3x3_2.GetM10() << ", " << mat3x3_2.GetM11() << ", " << mat3x3_2.GetM12() << "]\n";
	std::cout << "[" << mat3x3_2.GetM20() << ", " << mat3x3_2.GetM21() << ", " << mat3x3_2.GetM22() << "]\n\n";

	//División directa por escalar
	mat3x3_1 /= 2.0f;
	std::cout << "Division directa Mat1 /= 2:\n";
	std::cout << "[" << mat3x3_1.GetM00() << ", " << mat3x3_1.GetM01() << ", " << mat3x3_1.GetM02() << "]\n";
	std::cout << "[" << mat3x3_1.GetM10() << ", " << mat3x3_1.GetM11() << ", " << mat3x3_1.GetM12() << "]\n";
	std::cout << "[" << mat3x3_1.GetM20() << ", " << mat3x3_1.GetM21() << ", " << mat3x3_1.GetM22() << "]\n\n";

	mat3x3_2 /= 0.5f;
	std::cout << "Division directa Mat2 /= 0.5:\n";
	std::cout << "[" << mat3x3_2.GetM00() << ", " << mat3x3_2.GetM01() << ", " << mat3x3_2.GetM02() << "]\n";
	std::cout << "[" << mat3x3_2.GetM10() << ", " << mat3x3_2.GetM11() << ", " << mat3x3_2.GetM12() << "]\n";
	std::cout << "[" << mat3x3_2.GetM20() << ", " << mat3x3_2.GetM21() << ", " << mat3x3_2.GetM22() << "]\n\n";

	//Matriz transpuesta
	Matriz3x3 transMat3x3_1 = mat3x3_1.Transpose();
	std::cout << "Transpuesta de Mat1:\n";
	std::cout << "[" << transMat3x3_1.GetM00() << ", " << transMat3x3_1.GetM01() << ", " << transMat3x3_1.GetM02() << "]\n";
	std::cout << "[" << transMat3x3_1.GetM10() << ", " << transMat3x3_1.GetM11() << ", " << transMat3x3_1.GetM12() << "]\n";
	std::cout << "[" << transMat3x3_1.GetM20() << ", " << transMat3x3_1.GetM21() << ", " << transMat3x3_1.GetM22() << "]\n\n";

	Matriz3x3 transMat3x3_2 = mat3x3_2.Transpose();
	std::cout << "Transpuesta de Mat2:\n";
	std::cout << "[" << transMat3x3_2.GetM00() << ", " << transMat3x3_2.GetM01() << ", " << transMat3x3_2.GetM02() << "]\n";
	std::cout << "[" << transMat3x3_2.GetM10() << ", " << transMat3x3_2.GetM11() << ", " << transMat3x3_2.GetM12() << "]\n";
	std::cout << "[" << transMat3x3_2.GetM20() << ", " << transMat3x3_2.GetM21() << ", " << transMat3x3_2.GetM22() << "]\n\n";

	//Matriz inversa
	Matriz3x3 invMat3x3_1 = mat3x3_1.Inverse();
	std::cout << "Inversa de Mat1:\n";
	std::cout << "[" << invMat3x3_1.GetM00() << ", " << invMat3x3_1.GetM01() << ", " << invMat3x3_1.GetM02() << "]\n";
	std::cout << "[" << invMat3x3_1.GetM10() << ", " << invMat3x3_1.GetM11() << ", " << invMat3x3_1.GetM12() << "]\n";
	std::cout << "[" << invMat3x3_1.GetM20() << ", " << invMat3x3_1.GetM21() << ", " << invMat3x3_1.GetM22() << "]\n\n";

	Matriz3x3 invMat3x3_2 = mat3x3_2.Inverse();
	std::cout << "Inversa de Mat2:\n";
	std::cout << "[" << invMat3x3_2.GetM00() << ", " << invMat3x3_2.GetM01() << ", " << invMat3x3_2.GetM02() << "]\n";
	std::cout << "[" << invMat3x3_2.GetM10() << ", " << invMat3x3_2.GetM11() << ", " << invMat3x3_2.GetM12() << "]\n";
	std::cout << "[" << invMat3x3_2.GetM20() << ", " << invMat3x3_2.GetM21() << ", " << invMat3x3_2.GetM22() << "]\n\n";

	//Matriz determinante
	float detMat3x3_1 = mat3x3_1.Determinant();
	std::cout << "Determinante de Mat1: " << detMat3x3_1 << "\n";
	float detMat3x3_2 = mat3x3_2.Determinant();
	std::cout << "Determinante de Mat2: " << detMat3x3_2 << "\n\n\n";


	std::cout << "-----------------------------------------------------------------------\n";
	std::cout << "MATRIZ 4X4\n";
	std::cout << "-----------------------------------------------------------------------\n\n";


	// Crear dos matrices 4x4
	Matriz4x4 mat4x4_1(
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f);
	Matriz4x4 mat4x4_2(
		16.0f, 15.0f, 14.0f, 13.0f,
		12.0f, 11.0f, 10.0f, 9.0f,
		8.0f, 7.0f, 6.0f, 5.0f,
		4.0f, 3.0f, 2.0f, 1.0f);

	std::cout << "Matriz 1:\n";
	std::cout << "[" << mat4x4_1.GetM00() << ", " << mat4x4_1.GetM01() << ", " << mat4x4_1.GetM02() << ", " << mat4x4_1.GetM03() << "]\n";
	std::cout << "[" << mat4x4_1.GetM10() << ", " << mat4x4_1.GetM11() << ", " << mat4x4_1.GetM12() << ", " << mat4x4_1.GetM13() << "]\n";
	std::cout << "[" << mat4x4_1.GetM20() << ", " << mat4x4_1.GetM21() << ", " << mat4x4_1.GetM22() << ", " << mat4x4_1.GetM23() << "]\n";
	std::cout << "[" << mat4x4_1.GetM30() << ", " << mat4x4_1.GetM31() << ", " << mat4x4_1.GetM32() << ", " << mat4x4_1.GetM33() << "]\n\n";

	std::cout << "Matriz 2:\n";
	std::cout << "[" << mat4x4_2.GetM00() << ", " << mat4x4_2.GetM01() << ", " << mat4x4_2.GetM02() << ", " << mat4x4_2.GetM03() << "]\n";
	std::cout << "[" << mat4x4_2.GetM10() << ", " << mat4x4_2.GetM11() << ", " << mat4x4_2.GetM12() << ", " << mat4x4_2.GetM13() << "]\n";
	std::cout << "[" << mat4x4_2.GetM20() << ", " << mat4x4_2.GetM21() << ", " << mat4x4_2.GetM22() << ", " << mat4x4_2.GetM23() << "]\n";
	std::cout << "[" << mat4x4_2.GetM30() << ", " << mat4x4_2.GetM31() << ", " << mat4x4_2.GetM32() << ", " << mat4x4_2.GetM33() << "]\n\n";

	//Suma
	Matriz4x4 sumMat4x4 = mat4x4_1 + mat4x4_2;
	std::cout << "Suma Mat1 + Mat2:\n";
	std::cout << "[" << sumMat4x4.GetM00() << ", " << sumMat4x4.GetM01() << ", " << sumMat4x4.GetM02() << ", " << sumMat4x4.GetM03() << "]\n";
	std::cout << "[" << sumMat4x4.GetM10() << ", " << sumMat4x4.GetM11() << ", " << sumMat4x4.GetM12() << ", " << sumMat4x4.GetM13() << "]\n";
	std::cout << "[" << sumMat4x4.GetM20() << ", " << sumMat4x4.GetM21() << ", " << sumMat4x4.GetM22() << ", " << sumMat4x4.GetM23() << "]\n";
	std::cout << "[" << sumMat4x4.GetM30() << ", " << sumMat4x4.GetM31() << ", " << sumMat4x4.GetM32() << ", " << sumMat4x4.GetM33() << "]\n\n";

	//Resta
	Matriz4x4 diffMat4x4 = mat4x4_1 - mat4x4_2;
	std::cout << "Resta Mat1 - Mat2:\n";
	std::cout << "[" << diffMat4x4.GetM00() << ", " << diffMat4x4.GetM01() << ", " << diffMat4x4.GetM02() << ", " << diffMat4x4.GetM03() << "]\n";
	std::cout << "[" << diffMat4x4.GetM10() << ", " << diffMat4x4.GetM11() << ", " << diffMat4x4.GetM12() << ", " << diffMat4x4.GetM13() << "]\n";
	std::cout << "[" << diffMat4x4.GetM20() << ", " << diffMat4x4.GetM21() << ", " << diffMat4x4.GetM22() << ", " << diffMat4x4.GetM23() << "]\n";
	std::cout << "[" << diffMat4x4.GetM30() << ", " << diffMat4x4.GetM31() << ", " << diffMat4x4.GetM32() << ", " << diffMat4x4.GetM33() << "]\n\n";

	//Multiplicación
	Matriz4x4 prodMat4x4 = mat4x4_1 * mat4x4_2;
	std::cout << "Multiplicacion Mat1 * Mat2:\n";
	std::cout << "[" << prodMat4x4.GetM00() << ", " << prodMat4x4.GetM01() << ", " << prodMat4x4.GetM02() << ", " << prodMat4x4.GetM03() << "]\n";
	std::cout << "[" << prodMat4x4.GetM10() << ", " << prodMat4x4.GetM11() << ", " << prodMat4x4.GetM12() << ", " << prodMat4x4.GetM13() << "]\n";
	std::cout << "[" << prodMat4x4.GetM20() << ", " << prodMat4x4.GetM21() << ", " << prodMat4x4.GetM22() << ", " << prodMat4x4.GetM23() << "]\n";
	std::cout << "[" << prodMat4x4.GetM30() << ", " << prodMat4x4.GetM31() << ", " << prodMat4x4.GetM32() << ", " << prodMat4x4.GetM33() << "]\n\n";

	//Multiplicación por escalar
	Matriz4x4 scaledMat4x4 = mat4x4_1 * 2.0f;
	std::cout << "Multiplicacion Mat1 * 2:\n";
	std::cout << "[" << scaledMat4x4.GetM00() << ", " << scaledMat4x4.GetM01() << ", " << scaledMat4x4.GetM02() << ", " << scaledMat4x4.GetM03() << "]\n";
	std::cout << "[" << scaledMat4x4.GetM10() << ", " << scaledMat4x4.GetM11() << ", " << scaledMat4x4.GetM12() << ", " << scaledMat4x4.GetM13() << "]\n";
	std::cout << "[" << scaledMat4x4.GetM20() << ", " << scaledMat4x4.GetM21() << ", " << scaledMat4x4.GetM22() << ", " << scaledMat4x4.GetM23() << "]\n";
	std::cout << "[" << scaledMat4x4.GetM30() << ", " << scaledMat4x4.GetM31() << ", " << scaledMat4x4.GetM32() << ", " << scaledMat4x4.GetM33() << "]\n\n";

	Matriz4x4 scaledMat42 = mat4x4_2 * 0.5f;
	std::cout << "Multiplicacion Mat2 * 0.5:\n";
	std::cout << "[" << scaledMat42.GetM00() << ", " << scaledMat42.GetM01() << ", " << scaledMat42.GetM02() << ", " << scaledMat42.GetM03() << "]\n";
	std::cout << "[" << scaledMat42.GetM10() << ", " << scaledMat42.GetM11() << ", " << scaledMat42.GetM12() << ", " << scaledMat42.GetM13() << "]\n";
	std::cout << "[" << scaledMat42.GetM20() << ", " << scaledMat42.GetM21() << ", " << scaledMat42.GetM22() << ", " << scaledMat42.GetM23() << "]\n";
	std::cout << "[" << scaledMat42.GetM30() << ", " << scaledMat42.GetM31() << ", " << scaledMat42.GetM32() << ", " << scaledMat42.GetM33() << "]\n\n";

	//División por escalar
	Matriz4x4 divMat4x4 = mat4x4_1 / 2.0f;
	std::cout << "Division Mat1 / 2:\n";
	std::cout << "[" << divMat4x4.GetM00() << ", " << divMat4x4.GetM01() << ", " << divMat4x4.GetM02() << ", " << divMat4x4.GetM03() << "]\n";
	std::cout << "[" << divMat4x4.GetM10() << ", " << divMat4x4.GetM11() << ", " << divMat4x4.GetM12() << ", " << divMat4x4.GetM13() << "]\n";
	std::cout << "[" << divMat4x4.GetM20() << ", " << divMat4x4.GetM21() << ", " << divMat4x4.GetM22() << ", " << divMat4x4.GetM23() << "]\n";
	std::cout << "[" << divMat4x4.GetM30() << ", " << divMat4x4.GetM31() << ", " << divMat4x4.GetM32() << ", " << divMat4x4.GetM33() << "]\n\n";

	Matriz4x4 divMat42 = mat4x4_2 / 0.5f;
	std::cout << "Division Mat2 / 0.5:\n";
	std::cout << "[" << divMat42.GetM00() << ", " << divMat42.GetM01() << ", " << divMat42.GetM02() << ", " << divMat42.GetM03() << "]\n";
	std::cout << "[" << divMat42.GetM10() << ", " << divMat42.GetM11() << ", " << divMat42.GetM12() << ", " << divMat42.GetM13() << "]\n";
	std::cout << "[" << divMat42.GetM20() << ", " << divMat42.GetM21() << ", " << divMat42.GetM22() << ", " << divMat42.GetM23() << "]\n";
	std::cout << "[" << divMat42.GetM30() << ", " << divMat42.GetM31() << ", " << divMat42.GetM32() << ", " << divMat42.GetM33() << "]\n\n";

	//Multiplicacion directa por escalar
	mat4x4_1 *= 2.0f;
	std::cout << "Multiplicacion directa Mat1 *= 2:\n";
	std::cout << "[" << mat4x4_1.GetM00() << ", " << mat4x4_1.GetM01() << ", " << mat4x4_1.GetM02() << ", " << mat4x4_1.GetM03() << "]\n";
	std::cout << "[" << mat4x4_1.GetM10() << ", " << mat4x4_1.GetM11() << ", " << mat4x4_1.GetM12() << ", " << mat4x4_1.GetM13() << "]\n";
	std::cout << "[" << mat4x4_1.GetM20() << ", " << mat4x4_1.GetM21() << ", " << mat4x4_1.GetM22() << ", " << mat4x4_1.GetM23() << "]\n";
	std::cout << "[" << mat4x4_1.GetM30() << ", " << mat4x4_1.GetM31() << ", " << mat4x4_1.GetM32() << ", " << mat4x4_1.GetM33() << "]\n\n";

	mat4x4_2 *= 0.5f;
	std::cout << "Multiplicacion directa Mat2 *= 0.5:\n";
	std::cout << "[" << mat4x4_2.GetM00() << ", " << mat4x4_2.GetM01() << ", " << mat4x4_2.GetM02() << ", " << mat4x4_2.GetM03() << "]\n";
	std::cout << "[" << mat4x4_2.GetM10() << ", " << mat4x4_2.GetM11() << ", " << mat4x4_2.GetM12() << ", " << mat4x4_2.GetM13() << "]\n";
	std::cout << "[" << mat4x4_2.GetM20() << ", " << mat4x4_2.GetM21() << ", " << mat4x4_2.GetM22() << ", " << mat4x4_2.GetM23() << "]\n";
	std::cout << "[" << mat4x4_2.GetM30() << ", " << mat4x4_2.GetM31() << ", " << mat4x4_2.GetM32() << ", " << mat4x4_2.GetM33() << "]\n\n";

	//División directa por escalar
	mat4x4_1 /= 2.0f;
	std::cout << "Division directa Mat1 /= 2:\n";
	std::cout << "[" << mat4x4_1.GetM00() << ", " << mat4x4_1.GetM01() << ", " << mat4x4_1.GetM02() << ", " << mat4x4_1.GetM03() << "]\n";
	std::cout << "[" << mat4x4_1.GetM10() << ", " << mat4x4_1.GetM11() << ", " << mat4x4_1.GetM12() << ", " << mat4x4_1.GetM13() << "]\n";
	std::cout << "[" << mat4x4_1.GetM20() << ", " << mat4x4_1.GetM21() << ", " << mat4x4_1.GetM22() << ", " << mat4x4_1.GetM23() << "]\n";
	std::cout << "[" << mat4x4_1.GetM30() << ", " << mat4x4_1.GetM31() << ", " << mat4x4_1.GetM32() << ", " << mat4x4_1.GetM33() << "]\n\n";

	mat4x4_2 /= 0.5f;
	std::cout << "Division directa Mat2 /= 0.5:\n";
	std::cout << "[" << mat4x4_2.GetM00() << ", " << mat4x4_2.GetM01() << ", " << mat4x4_2.GetM02() << ", " << mat4x4_2.GetM03() << "]\n";
	std::cout << "[" << mat4x4_2.GetM10() << ", " << mat4x4_2.GetM11() << ", " << mat4x4_2.GetM12() << ", " << mat4x4_2.GetM13() << "]\n";
	std::cout << "[" << mat4x4_2.GetM20() << ", " << mat4x4_2.GetM21() << ", " << mat4x4_2.GetM22() << ", " << mat4x4_2.GetM23() << "]\n";
	std::cout << "[" << mat4x4_2.GetM30() << ", " << mat4x4_2.GetM31() << ", " << mat4x4_2.GetM32() << ", " << mat4x4_2.GetM33() << "]\n\n";

	//Matriz transpuesta
	Matriz4x4 transMat4x4_1 = mat4x4_1.Transpose();
	std::cout << "Transpuesta de Mat1:\n";
	std::cout << "[" << transMat4x4_1.GetM00() << ", " << transMat4x4_1.GetM01() << ", " << transMat4x4_1.GetM02() << ", " << transMat4x4_1.GetM03() << "]\n";
	std::cout << "[" << transMat4x4_1.GetM10() << ", " << transMat4x4_1.GetM11() << ", " << transMat4x4_1.GetM12() << ", " << transMat4x4_1.GetM13() << "]\n";
	std::cout << "[" << transMat4x4_1.GetM20() << ", " << transMat4x4_1.GetM21() << ", " << transMat4x4_1.GetM22() << ", " << transMat4x4_1.GetM23() << "]\n";
	std::cout << "[" << transMat4x4_1.GetM30() << ", " << transMat4x4_1.GetM31() << ", " << transMat4x4_1.GetM32() << ", " << transMat4x4_1.GetM33() << "]\n\n";

	Matriz4x4 transMat4x4_2 = mat4x4_2.Transpose();
	std::cout << "Transpuesta de Mat2:\n";
	std::cout << "[" << transMat4x4_2.GetM00() << ", " << transMat4x4_2.GetM01() << ", " << transMat4x4_2.GetM02() << ", " << transMat4x4_2.GetM03() << "]\n";
	std::cout << "[" << transMat4x4_2.GetM10() << ", " << transMat4x4_2.GetM11() << ", " << transMat4x4_2.GetM12() << ", " << transMat4x4_2.GetM13() << "]\n";
	std::cout << "[" << transMat4x4_2.GetM20() << ", " << transMat4x4_2.GetM21() << ", " << transMat4x4_2.GetM22() << ", " << transMat4x4_2.GetM23() << "]\n";
	std::cout << "[" << transMat4x4_2.GetM30() << ", " << transMat4x4_2.GetM31() << ", " << transMat4x4_2.GetM32() << ", " << transMat4x4_2.GetM33() << "]\n\n";

	//Matriz inversa
	Matriz4x4 invMat4x4_1 = mat4x4_1.Inverse();
	std::cout << "Inversa de Mat1:\n";
	std::cout << "[" << invMat4x4_1.GetM00() << ", " << invMat4x4_1.GetM01() << ", " << invMat4x4_1.GetM02() << ", " << invMat4x4_1.GetM03() << "]\n";
	std::cout << "[" << invMat4x4_1.GetM10() << ", " << invMat4x4_1.GetM11() << ", " << invMat4x4_1.GetM12() << ", " << invMat4x4_1.GetM13() << "]\n";
	std::cout << "[" << invMat4x4_1.GetM20() << ", " << invMat4x4_1.GetM21() << ", " << invMat4x4_1.GetM22() << ", " << invMat4x4_1.GetM23() << "]\n";
	std::cout << "[" << invMat4x4_1.GetM30() << ", " << invMat4x4_1.GetM31() << ", " << invMat4x4_1.GetM32() << ", " << invMat4x4_1.GetM33() << "]\n\n";

	Matriz4x4 invMat4x4_2 = mat4x4_2.Inverse();
	std::cout << "Inversa de Mat2:\n";
	std::cout << "[" << invMat4x4_2.GetM00() << ", " << invMat4x4_2.GetM01() << ", " << invMat4x4_2.GetM02() << ", " << invMat4x4_2.GetM03() << "]\n";
	std::cout << "[" << invMat4x4_2.GetM10() << ", " << invMat4x4_2.GetM11() << ", " << invMat4x4_2.GetM12() << ", " << invMat4x4_2.GetM13() << "]\n";
	std::cout << "[" << invMat4x4_2.GetM20() << ", " << invMat4x4_2.GetM21() << ", " << invMat4x4_2.GetM22() << ", " << invMat4x4_2.GetM23() << "]\n";
	std::cout << "[" << invMat4x4_2.GetM30() << ", " << invMat4x4_2.GetM31() << ", " << invMat4x4_2.GetM32() << ", " << invMat4x4_2.GetM33() << "]\n\n";

	//Matriz determinante
	float detMat4x4_1 = mat4x4_1.Determinante();
	std::cout << "Determinante de Mat1: " << detMat4x4_1 << "\n";

	float detMat4x4_2 = mat4x4_2.Determinante();
	std::cout << "Determinante de Mat2: " << detMat4x4_2 << "\n\n\n";


	std::cout << "-----------------------------------------------------------------------\n";
	std::cout << "POTENCIAS Y RAICES\n";
	std::cout << "-----------------------------------------------------------------------\n\n";


	//Introducir numeros
	float numeroBase(15.0f);
	float numeroExponente(3.0f);
	float numeroRadical(3375.0f);
	float numeroRadical2(3375.0f);
	float numeroIndice(3.0f);

	////Calcular potencia
	float resultadoPotencia = Potencia(numeroBase, numeroExponente);
	std::cout << numeroBase << " elevado a la potencia " << numeroExponente << " es: " << resultadoPotencia << "\n\n";

	//Calcular raiz cuadrada	
	float resultadoRaiz = RaizCuadrada(numeroRadical);
	std::cout << "La raiz cuadrada de " << numeroRadical << " es: " << resultadoRaiz << "\n\n";

	//Calcular raiz cubica
	float resultadoRaizCubica = RaizCubica(numeroRadical);
	std::cout << "La raiz cubica de " << numeroRadical << " es: " << resultadoRaizCubica << "\n\n";

	////Calcular raiz n-esima

	float resultadoRaizNesima = RaizNesima(numeroRadical2, numeroIndice);
	std::cout << "La raiz indice " << numeroIndice << " del radical " << numeroRadical2 << " es: " << resultadoRaizNesima << "\n\n\n";


	std::cout << "-----------------------------------------------------------------------\n";
	std::cout << "VALORES\n";
	std::cout << "-----------------------------------------------------------------------\n\n";


	//Introducir valores a calcular
	float n_Absoluto(-45.62f);
	float n_Maximo(69.0f);
	float n_Minimo(45.0f);
	float n_Redondeo(65.236f);
	float n_Techo(65.689f);
	float n_Piso(65.689f);
	float n_Trunc(65.689f);

	//Calcular valor absoluto
	float resultadoAbsoluto = valorAbsoluto(n_Absoluto);
	std::cout << "El valor absoluto de " << n_Absoluto << " es: " << resultadoAbsoluto << "\n\n";

	//Calcular el valor maximo y minimo de dos numeros
	float resultadoMaximo = valorMaximo(n_Maximo, n_Minimo);
	std::cout << "El valor maximo entre " << n_Maximo << " y " << n_Minimo << " es: " << resultadoMaximo << "\n\n";
	float resultadoMinimo = valorMinimo(n_Maximo, n_Minimo);
	std::cout << "El valor minimo entre " << n_Maximo << " y " << n_Minimo << " es: " << resultadoMinimo << "\n\n";

	//Calcular redondeo, techo, piso y truncamiento
	float resultadoRedondeo = Redondeo(n_Redondeo);
	std::cout << "El redondeo de " << n_Redondeo << " es: " << resultadoRedondeo << "\n\n";

	float resultadoTecho = Techo(n_Techo);
	std::cout << "El techo de " << n_Redondeo << " es: " << resultadoTecho << "\n\n";

	float resultadoPiso = Piso(n_Piso);
	std::cout << "El piso de " << n_Redondeo << " es: " << resultadoPiso << "\n\n";

	float resultadoTruncamiento = Truncamiento(n_Trunc);
	std::cout << "El truncamiento de " << n_Redondeo << " es: " << resultadoTruncamiento << "\n\n\n";


	std::cout << "-----------------------------------------------------------------------\n";
	std::cout << "FUNCIONES TRIGONOMETRICAS\n";
	std::cout << "-----------------------------------------------------------------------\n\n";

	//Introducir angulo en grados
	double x(45);

	//Introducir valor para arco trigonométricas
	double y(0.5);


	//Calcular seno, coseno y tangente
	double ResultadoSinf = a_Seno(x);
	std::cout << "El seno de " << x << " grados es: " << ResultadoSinf << "\n";

	double ResultadoCosf = a_Coseno(x);
	std::cout << "El coseno de " << x << " grados es: " << ResultadoCosf << "\n";

	double ResultadoTanf = a_Tangente(x);
	std::cout << "La tangente de " << x << " grados es: " << ResultadoTanf << "\n\n";


	//Calcular secante, cosecante y cotangente
	double ResultadoSecf = a_Secante(x);
	std::cout << "La secante de " << x << " grados es: " << ResultadoSecf << "\n";

	double ResultadoCosecf = a_Cosecante(x);
	std::cout << "La cosecante de " << x << " grados es: " << ResultadoCosecf << "\n";

	double ResultadoCotanf = a_Cotangente(x);
	std::cout << "La cotangente de " << x << " grados es: " << ResultadoCotanf << "\n\n";


	//Calcular arco seno, arco coseno y arco tangente
	double ResultadoASinf = a_ArcoSeno(y);
	std::cout << "El arco seno de " << y << " es: " << ResultadoASinf << " grados\n";

	double ResultadoACosf = a_ArcoCoseno(y);
	std::cout << "El arco coseno de " << y << " es: " << ResultadoACosf << " grados\n";

	double ResultadoATanf = a_ArcoTangente(y);
	std::cout << "El arco tangente de " << y << " es: " << ResultadoATanf << " grados\n\n";



	//Convertir grados a radianes
	double radianes = GradosARadianes(x);
	std::cout << x << " grados son " << radianes << " radianes.\n";


	//Convertir radianes a grados
	double grados = RadianesAGrados(y);
	std::cout << y << " radianes son " << grados << " grados.\n\n\n";


	std::cout << "-----------------------------------------------------------------------\n";
	std::cout << "FUNCIONES EXPONENCIALES Y LOGARITMICAS\n";
	std::cout << "-----------------------------------------------------------------------\n\n";

	//Introducir numeros
	double xy(5.0);
	double base(2.0);


	//Calcular logaritmo natural
	double resultadoLogaritmoNatural = a_LogaritmoNatural(xy);
	std::cout << "El logaritmo natural de " << xy << " es: " << resultadoLogaritmoNatural << "\n";

	//Calcular logaritmo base 10
	double resultadoLogaritmoBase10 = a_LogaritmoBase10(xy);
	std::cout << "El logaritmo base 10 de " << xy << " es: " << resultadoLogaritmoBase10 << "\n\n";

	//Calcular exponencial
	double resultadoExponencial = a_Exponencial(xy);
	std::cout << "El exponencial e^" << xy << " es: " << resultadoExponencial << "\n\n\n";


	std::cout << "-----------------------------------------------------------------------\n";
	std::cout << "FUNCIONES DE GEOMETRIA\n";
	std::cout << "-----------------------------------------------------------------------\n\n";

	//introducir valores
	float radioCirculo(7.0);
	float anchoRectangulo(4.0f);
	float ladoRectangulo(3.0f);
	float baseTriangulo(6.0f);
	float alturaTriangulo(4.0f);
	float ladoTriangulo1(5.0f);
	float ladoTriangulo2(7.0f);
	float ladoTriangulo3(10.0f);
	float ladoCuadrado(8.0f);
	float baseMayor(10.0f);
	float baseMenor(6.0f);
	float alturaTrapecio(5.0f);
	float ladoTrapecio1(4.0f);
	float ladoTrapecio2(5.0f);
	float ladoCubo(4.0f);
	float radioEsfera(9.0f);
	float radioCilindro(5.0f);
	float alturaCilindro(10.0f);
	float radioCono(3.0f);
	float alturaCono(7.0f);
	float ladoPiramide(6.0f);
	float alturaPiramide(9.0f);
	float anchoPiramide(8.0f);


	//Calcular el perimetro de un circulo
	double perimetroCirculo = PerimetroCirculo(radioCirculo);
	std::cout << "El perimetro de un circulo de radio " << radioCirculo << " es: " << perimetroCirculo << "\n\n";

	//Calcular el area de un circulo
	double areaCirculo = AreaCirculo(radioCirculo);
	std::cout << "El area de un circulo de radio " << radioCirculo << " es: " << areaCirculo << "\n\n";

	//Calcular el perimetro de un cuadrado
	float perimetroCuadrado = PerimetroCuadrado(ladoCuadrado);
	std::cout << "El perimetro de un cuadrado de lado " << ladoCuadrado << " es: " << perimetroCuadrado << "\n\n";

	//Calcular el area de un cuadrado
	float areaCuadrado = AreaCuadrado(ladoCuadrado);
	std::cout << "El area de un cuadrado de lado " << ladoCuadrado << " es: " << areaCuadrado << "\n\n";

	//Calcular el perimetro de un rectangulo
	float perimetroRectangulo = PerimetroRectangulo(anchoRectangulo, ladoRectangulo);
	std::cout << "El perimetro de un rectangulo de ancho " << anchoRectangulo << " y lado " << ladoRectangulo << " es: " << perimetroRectangulo << "\n\n";

	//Calcular el area de un rectangulo
	float areaRectangulo = AreaRectangulo(anchoRectangulo, ladoRectangulo);
	std::cout << "El area de un rectangulo de ancho " << anchoRectangulo << " y lado " << ladoRectangulo << " es: " << areaRectangulo << "\n\n";

	//Calcular el perimetro de un triangulo
	float perimetroTriangulo = PerimetroTriangulo(ladoTriangulo1, ladoTriangulo2, ladoTriangulo3);
	std::cout << "El perimetro de un triangulo de lados " << ladoTriangulo1 << ", " << ladoTriangulo2 << " y " << ladoTriangulo3 << " es: " << perimetroTriangulo << "\n\n";

	//Calcular el area de un triangulo
	float areaTriangulo = AreaTriangulo(baseTriangulo, alturaTriangulo);
	std::cout << "El area de un triangulo de base " << baseTriangulo << " y altura " << alturaTriangulo << " es: " << areaTriangulo << "\n\n";

	//Calcular el perimetro de un trapecio
	float perimetroTrapecio = PerimetroTrapecio(baseMayor, baseMenor, ladoTrapecio1, ladoTrapecio2);

	//Calcular el area de un trapecio
	float areaTrapecio = AreaTrapecio(baseMayor, baseMenor, alturaTrapecio);
	std::cout << "El area de un trapecio de base mayor " << baseMayor << ", base menor " << baseMenor << " y altura " << alturaTrapecio << " es: " << areaTrapecio << "\n\n";


	//Calcular el area de una esfera
	double areaEsfera = AreaSuperficieEsfera(radioEsfera);
	std::cout << "El area de una esfera de radio " << radioEsfera << " es: " << areaEsfera << "\n\n";

	//Calcular el volumen de una esfera
	double volumenEsfera = VolumenEsfera(radioEsfera);
	std::cout << "El volumen de una esfera de radio " << radioEsfera << " es: " << volumenEsfera << "\n\n";

	//Calcular el area de un cubo
	float areaCubo = AreaSuperficieCubo(ladoCubo);
	std::cout << "El area de un cubo de lado " << ladoCubo << " es: " << areaCubo << "\n\n";

	//Calcular el volumen de un cubo
	float volumenCubo = VolumenCubo(ladoCubo);
	std::cout << "El volumen de un cubo de lado " << ladoCubo << " es: " << volumenCubo << "\n\n";

	//Calcular el area de un cilindro
	double areaCilindro = AreaSuperficieCilindro(radioCilindro, alturaCilindro);
	std::cout << "El area de un cilindro de radio " << radioCilindro << " y altura " << alturaCilindro << " es: " << areaCilindro << "\n\n";

	//Calcular el volumen de un cilindro
	double volumenCilindro = VolumenCilindro(radioCilindro, alturaCilindro);
	std::cout << "El volumen de un cilindro de radio " << radioCilindro << " y altura " << alturaCilindro << " es: " << volumenCilindro << "\n\n";

	//Calcular el area de un cono
	double areaCono = AreaSuperficieCono(radioCono, alturaCono);
	std::cout << "El area de un cono de radio " << radioCono << " y altura " << alturaCono << " es: " << areaCono << "\n\n";

	//Calcular el volumen de un cono
	double volumenCono = VolumenCono(radioCono, alturaCono);
	std::cout << "El volumen de un cono de radio " << radioCono << " y altura " << alturaCono << " es: " << volumenCono << "\n\n";

	//Calcular el area de una piramide cuadrangular
	float areaPiramide = AreaSuperficiePiramideCuadrada(ladoPiramide, alturaPiramide);
	std::cout << "El area de una piramide cuadrangular de lado " << ladoPiramide << " y altura " << alturaPiramide << " es: " << areaPiramide << "\n\n";

	//Calcular el volumen de una piramide cuadrangular
	float volumenPiramide = VolumenPiramideCuadrada(ladoPiramide, alturaPiramide);
	std::cout << "El volumen de una piramide cuadrangular de lado " << ladoPiramide << " y altura " << alturaPiramide << " es: " << volumenPiramide << "\n\n";

	//Calcular el area de una piramide rectangular
	float areaPiramideRect = AreaSuperficiePiramideRectangular(anchoPiramide, ladoPiramide, alturaPiramide);
	std::cout << "El area de una piramide rectangular de ancho " << anchoPiramide << ", lado " << ladoPiramide << " y altura " << alturaPiramide << " es: " << areaPiramideRect << "\n\n";

	//Calcular el volumen de una piramide rectangular
	float volumenPiramideRect = VolumenPiramideRectangular(anchoPiramide, ladoPiramide, alturaPiramide);
	std::cout << "El volumen de una piramide rectangular de ancho " << anchoPiramide << ", lado " << ladoPiramide << " y altura " << alturaPiramide << " es: " << volumenPiramideRect << "\n\n\n";


	std::cout << "-----------------------------------------------------------------------\n";
	std::cout << "FACTORIALES\n";
	std::cout << "-----------------------------------------------------------------------\n\n";

	//Introducir numero
	int numFactorial(25);

	//Calcular factorial
	unsigned long long resultadoFactorial = Factorial(numFactorial);
	std::cout << "El factorial de " << numFactorial << "! es: " << resultadoFactorial << "\n\n";


	return 0;

}