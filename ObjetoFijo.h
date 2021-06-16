#pragma once
#include <ETSIDI.h>
using namespace ETSIDI;

class ObjetoFijo
{
protected:
	Vector2D posicion;

public:
	ObjetoFijo(void);
	virtual ~ObjetoFijo(void);

	Vector2D getPos();
	void setPos(float x, float y);
	//void setPos(Vector2D pos);
};
