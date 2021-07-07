#include "ObstaculoFijo.h"

ObstaculoFijo::ObstaculoFijo()
{
	//setPos(10, -10);// (15, -5);
	posicion.x = posicion.y = 0;
}

ObstaculoFijo::ObstaculoFijo(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}

ObstaculoFijo::~ObstaculoFijo()
{
}

void ObstaculoFijo::dibuja()
{
	//glPushMatrix();
	//glTranslatef(posicion.x, posicion.y, 0);
	fijo.setPos(posicion.x - 1.0, posicion.y - 1.0);
	fijo.draw();
	//glPopMatrix();
}

void ObstaculoFijo::mueve(float t)
{
	//ObjetoMovil::mueve(t);
	fijo.loop();
}
