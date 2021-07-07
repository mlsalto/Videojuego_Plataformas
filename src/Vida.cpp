#include "Vida.h"
#include "freeglut.h"

Vida::Vida()
{
	//setPos(10, -10);// (15, -5);
	posicion.x = posicion.y = 10;
}

Vida::Vida(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}


void Vida::dibuja()
{
	/*glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	sprite.draw();
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();*/
	sprite.setPos(posicion.x, posicion.y);
	sprite.draw();
}


void Vida::mueve(float t)
{
	sprite.loop();
}