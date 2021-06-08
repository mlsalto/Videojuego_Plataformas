#pragma once
#include "math.h"

class Vector2D
{
public:
	float x;
	float y;

	Vector2D(float xv = 0.0f, float yv = 0.0f);
	virtual ~Vector2D() {}

	float modulo();				// modulo del vector
	float argumento();			// argumento del vector
	Vector2D unitario();		// devuelve un vector unitario
	Vector2D operator-(Vector2D v);//resta de vectores
	Vector2D operator+(Vector2D v);//suma de vectores
	float operator*(Vector2D v);//producto escalar de vectores
	Vector2D operator* (float esc);//producto por un escalar
};