#pragma once
#include <ETSIDI.h>
#include "ObjetoFijo.h"

using ETSIDI::SpriteSequence;

class ObstaculoFijo :public ObjetoFijo
{
protected:
	//atributos
	Vector2D posicion;
	float alto, ancho;
	SpriteSequence fijo{ "Texturas/fuego.png", 4, 1, 100, true,posicion.x,posicion.y,ancho=10,alto=10};

	friend class Interaccion;

public:
	ObstaculoFijo();
	ObstaculoFijo(float x, float y);
	virtual ~ObstaculoFijo();

	void dibuja();
	void mueve(float t);
	//void setPos(float px, float py); //añadido por Lisa

};