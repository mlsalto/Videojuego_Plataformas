#pragma once

#include "freeglut.h"
#include "ETSIDI.h"
using namespace ETSIDI;

class Personaje
{
public:
	Personaje();


	void dibujar();
	void mover(float t);
	void teclaEspecialAbajo(unsigned char key);

	void setVel(float vx, float vy);
	void setPos(float px, float py);
	Vector2D getPos();
	virtual ~Personaje() {}

private:


	SpriteSequence correr{ "Texturas/correrdcha.png", 8, 1, 100, true, posicion.x, posicion.y, ancho = 16, alto = 16 };
	SpriteSequence idle{ "Texturas/idle.png", 6, 1, 100, true, posicion.x, posicion.y,ancho = 16, alto = 16 };
	SpriteSequence saltar{ "Texturas/saltar.png",8,1,180,true,posicion.x,posicion.y,ancho = 16, alto = 16 }; //arreglar sprite

	float dcha;

	float ancho, alto;

	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

	friend class Interaccion;
};
