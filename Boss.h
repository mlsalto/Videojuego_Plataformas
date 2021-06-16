#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "ObjetoMovil.h"

using namespace ETSIDI;

class Boss: public ObjetoMovil
{
public:

	Boss();

	void dibujar();
	void mover(float t);

	void setVel(float vx, float vy);
	void setPos(float px, float py);

	virtual ~Boss() {}

private:

	SpriteSequence boss{ "Texturas/boss1.png", 7, 1, 100, true, posicion.x, posicion.y, ancho = 48, alto = 32 };

	float dcha;

	float ancho, alto;

	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
};

