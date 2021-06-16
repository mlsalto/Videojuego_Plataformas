#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "ObjetoFijo.h"
using namespace ETSIDI;

class Bonus:public ObjetoFijo
{
public:
	Bonus();
	Bonus(float x, float y);

	void dibuja();
	void mueve(float t);

	virtual ~Bonus() {};

protected:

	SpriteSequence sprite{ "Texturas/Bonus.png", 1,2,500,true, posicion.x, posicion.y, ancho = 5, alto = 5};
	float ancho, alto;

	friend class Interaccion;
};

