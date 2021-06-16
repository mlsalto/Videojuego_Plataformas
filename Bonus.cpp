#include "Bonus.h"
#include "freeglut.h"

Bonus::Bonus()
{
	//setPos(10, -10);// (15, -5);
	posicion.x = posicion.y = 10;
}

Bonus::Bonus(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}


void Bonus::dibuja()
{
	/*glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	sprite.draw();
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();*/
	sprite.setPos(posicion.x, posicion.y);
	sprite.draw();
}


void Bonus::mueve(float t) 
{
	sprite.loop();
}

/*float Bonus::distancia(Vector2D punto, Vector2D* direccion)
{
	Vector2D posicion(posicionx, posiciony);
	Vector2D u = (punto - posicion);
	Vector2D v = posicion.unit();
	float longitud = posicion.module();
	Vector2D dir(0, 0);
	float valor = u * v;
	float distancia = 0;
	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - posicion);
	else
		dir = u - v * valor;
	distancia = dir.module();
	if (direccion != 0) //si nos dan un vector… 
		*direccion = dir.unit();
	return distancia;
} */