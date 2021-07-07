#pragma once
#include <ETSIDI.h>
#include "Tile.h"

using namespace ETSIDI;

class ObjetoMovil:public Tile
{
protected:
	//Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

public:
	ObjetoMovil(void);
	virtual ~ObjetoMovil(void);
	virtual void mueve(float t);
	Vector2D getPos();
	void setVel(float vx, float vy);
	void setVel(Vector2D vel);
	void setPos(float x, float y);
	void setPos(Vector2D pos);
};
