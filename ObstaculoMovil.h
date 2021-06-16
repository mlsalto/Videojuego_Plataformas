
#pragma once
#include "ObjetoMovil.h"
#include <ETSIDI.h>
	using ETSIDI::SpriteSequence;

class ObstaculoMovil : public ObjetoMovil
{
private:
	float posicionx_max;
	float posicionx_min;
	float ancho, alto;

	SpriteSequence paso{ "Texturas/llama.png", 5,1,50,true,posicion.x,posicion.y,ancho=10,alto=10};

	friend class Interaccion;

public:
	ObstaculoMovil(void);
	ObstaculoMovil(float x, float y);
	virtual ~ObstaculoMovil(void);

	void mueve(float t);
	void dibuja();
	void setPos(float px, float py);
};



