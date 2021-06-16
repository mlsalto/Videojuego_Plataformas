#include "ObjetoFijo.h"
#include <math.h>
#include "ETSIDI.h"
#include <stdlib.h>

ObjetoFijo::ObjetoFijo()
{

}

ObjetoFijo::~ObjetoFijo(void)
{

}

void ObjetoFijo::setPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}

Vector2D ObjetoFijo::getPos()
{
	return posicion;
}