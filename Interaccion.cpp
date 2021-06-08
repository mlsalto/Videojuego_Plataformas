#include "Interaccion.h"
#include <math.h>

void Interaccion::colision(Tile& t, Personaje p)
{
	float xmax1 = p.posicion.x;
	float xmax2 = t.posicion.x;
	float ymax1 = p.posicion.y;
	float ymax2 = t.posicion.y;

	float ancho = (p.ancho + t.ancho) / 2;
	float alto = (p.alto + t.altura) / 2;

	//if (xmax2 < xmax1 + ancho)p.posicion.x = xmax1;
	//if (xmax1 < xmax2 + ancho)p.posicion.x = xmax1;

	if (ymax1 > ymax2 - alto)p.setPos(p.getPos().x, ymax2+t.altura/2);
	if (ymax1 < ymax2 + alto)p.setPos(p.getPos().x, ymax2+t.altura/2);

}
