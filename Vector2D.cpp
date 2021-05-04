#include "Vector2D.h"
#include "math.h"

Vector2D::Vector2D(float xv, float yv)
{
	x = xv;
	y = yv;
}

float Vector2D::modulo()
{
	return (float) sqrt((x * x)+(y * y));
}
float Vector2D::argumento()
{
	float resultado;
	return resultado= atan(x / y);
}
Vector2D Vector2D::unitario()
{
	Vector2D resultado(x,y);
	resultado.x = x / modulo();
	resultado.y = y / modulo();
	return resultado;
}

Vector2D Vector2D::operator+(Vector2D op)
{
	Vector2D resultado(x,y);
	resultado.x = x + op.x;
	resultado.y = y + op.y;
	return resultado;
}
Vector2D Vector2D::operator-(Vector2D op)
{
	Vector2D resultado(x,y);
	resultado.x = x - op.x;
	resultado.y = y - op.y;
	return resultado;
}
float Vector2D::operator *(Vector2D op)
{
	float resultado;
	resultado = (x * op.x) + (y * op.y);
	return resultado;
}
Vector2D Vector2D::operator *(float n)
{
	Vector2D resultado(x,y);
	resultado.x = x * n;
	resultado.y = y * n;
	return resultado;
}