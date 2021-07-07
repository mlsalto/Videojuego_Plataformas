#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "ObjetoFijo.h"

using namespace ETSIDI;

class Vida :public ObjetoFijo
{
public:
	Vida();
	Vida(float x, float y);

	void dibuja();
	void mueve(float t);

	virtual ~Vida() {};

protected:

	SpriteSequence sprite{ "Texturas/Objetos/cafecito.png", 1,2,500,true, posicion.x, posicion.y, ancho = 5, alto = 5 };
	//float ancho, alto;

	friend class Interaccion;
};


