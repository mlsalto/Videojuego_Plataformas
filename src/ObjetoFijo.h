#pragma once
#include <ETSIDI.h>
#include "Tile.h"

using namespace ETSIDI;

class ObjetoFijo:public Tile
{
protected:
	//Vector2D posicion;
	//float ancho, alto;

public:
	ObjetoFijo(void);
	virtual ~ObjetoFijo(void);

	Vector2D getPos();
	void setPos(float x, float y);
	//void setPos(Vector2D pos);
};
