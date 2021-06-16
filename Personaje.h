#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "ObjetoMovil.h"

using namespace ETSIDI;

class Personaje:public ObjetoMovil
{
public:

	Personaje(void);
	//virtual ~Personaje(void);
	
	void dibujar();
	void mover(float t);
	void teclaEspecialAbajo(unsigned char key);

	int getVidas();

	float getSize();

	virtual ~Personaje () {}

private:
	
	enum Estado {APOYADO,VOLANDO};
	Estado estado; 

	SpriteSequence correr{ "Texturas/correrdcha.png", 8, 1, 100, true, posicion.x, posicion.y, ancho = 15, alto =15};
	SpriteSequence idle{ "Texturas/idle.png", 6, 1, 100, true, posicion.x, posicion.y,ancho =15, alto = 15};
	SpriteSequence saltar{ "Texturas/saltar.png",8,1,180,true,posicion.x,posicion.y,ancho = 15, alto = 15}; //arreglar sprite

	float dcha;
	int vidas;

	float ancho, alto;


	friend class Interaccion;
	friend class Mundo;
};

