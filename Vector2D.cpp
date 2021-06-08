#include "Vector2D.h"

Vector2D::Vector2D(float xv, float yv) {
	x = xv;
	y = yv;
}

//devuelve modulo del vector
float Vector2D::modulo()
{
	return (float)sqrt((double)x * x + (double)y * y);
}

//devuelve argumento del vector
float Vector2D::argumento() {
	return (float)atan2(y, x);
}

// devuelve un vector unitario
Vector2D Vector2D::unitario()
{
	Vector2D retorno(x, y);//el vector retorno es una copia de el vector al q se le aplica unitario
	float mod = modulo();
	//te aseguras de q el mod sea no nulo.
	if (mod > 0.00001) {
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}

//devuelve resta de dos vectores
Vector2D Vector2D::operator-(Vector2D v) {
	Vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}

//devuelve la suma de dos vectores
Vector2D Vector2D::operator+(Vector2D v)
{
	Vector2D res;
	res.x = x + v.x;
	res.y = y + v.y;
	return res;
}
//devuelve el producto escalar de dos vectores
float Vector2D::operator*(Vector2D v)
{
	float prodesc = ((x * v.x) + (y * v.y));
	return prodesc;
}
//devuelve el producto por un escalar de un vector
Vector2D Vector2D::operator*(float esc)
{
	Vector2D res(x, y);
	res.x *= esc;
	res.y *= esc;
	return res;
}

