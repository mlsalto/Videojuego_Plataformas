#pragma once
#include <ETSIDI.h>
#include "ObjetoFijo.h"

using ETSIDI::SpriteSequence;

class ObstaculoFijo :public ObjetoFijo
{
protected:
	//atributos
	//Vector2D posicion;
	//float alto, ancho;
	SpriteSequence fijo{ "Texturas/Objetos/mesa.png", 9, 1, 100, true,posicion.x,posicion.y,ancho=12,alto=7};

	friend class Interaccion;

public:
	ObstaculoFijo();
	ObstaculoFijo(float x, float y);
	virtual ~ObstaculoFijo();

	void dibuja();
	void mueve(float t);
	//void setPos(float px, float py); //añadido por Lisa

};