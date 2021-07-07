#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "ObjetoMovil.h"
#include "Disparo.h"

using namespace ETSIDI;

class Boss: public ObjetoMovil
{
private:
	float posicionx_max;
	float posicionx_min;

	int jefe = 1;
	int vida = 14;

	Disparo disparo;

	SpriteSequence jefe1{ "Texturas/Jefes/boss1.png", 8, 1, 100, true, posicion.x, posicion.y, ancho = 46, alto = 30 };
	SpriteSequence jefe2{ "Texturas/Jefes/boss2.1.png", 3, 1, 100, true, posicion.x, posicion.y, ancho = 46, alto = 30 };
	SpriteSequence jefe3{ "Texturas/Jefes/boss3.png", 7, 1, 100, true, posicion.x, posicion.y, ancho = 46, alto = 30 };
	Sprite jefe4{ "Texturas/Jefes/boss4.png",110.0, -16.0, ancho = 46, alto = 30 };
	
	friend class Interaccion;
	friend class Mundo;

public:
	Boss(void);
	Boss(float x, float y);
	virtual ~Boss(void);

	void mueve(float t);
	void dibuja();
	//void setPos(float px, float py);
	void restarVida();

	void setVida(int x);
	void setJefe(int x);

	int getVida();
};

