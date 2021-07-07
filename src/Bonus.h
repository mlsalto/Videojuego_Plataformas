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
	Bonus(const Bonus& r);//constructor copia se podria eliminar


	void dibuja();
	void mueve(float t);

	virtual ~Bonus() {};

protected:

	SpriteSequence sprite{ "Texturas/Objetos/Bonus.png", 1,2,500,true, posicion.x, posicion.y, ancho = 5, alto = 5}; //bonus
	float ancho, alto;

	friend class Interaccion;
};

