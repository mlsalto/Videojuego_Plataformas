#pragma once
#include "ObjetoMovil.h"
#include "Interaccion.h"
#include "Personaje.h"
#include "ListaObstaculoMovil.h"

class Vida: public ObjetoMovil
{
public:
	Vida();
	//Vida(float x, float y);
	virtual ~Vida() {};

	void Estadovida(int vidareal);

	void mueve(float t);
	void dibuja();
	void mueve();

private:
	//static int vidareal;
	float ancho, alto;
	int vidareal;

	enum Estado{VIDA5, VIDA4, VIDA3, VIDA2, VIDA1, VIDA0};
	Estado vida;

	Sprite vida5{ "Texturas/vida5.png" ,posicion.x ,posicion.y, ancho, alto};
	Sprite vida4{ "Texturas/vida4.png" ,posicion.x ,posicion.y, ancho, alto };
	Sprite vida3{ "Texturas/vida3.png" ,posicion.x ,posicion.y, ancho, alto };
	Sprite vida2{ "Texturas/vida2.png" ,posicion.x ,posicion.y, ancho, alto };
	Sprite vida1{ "Texturas/vida1.png" ,posicion.x ,posicion.y, ancho, alto };
	Sprite vida0{ "Texturas/vida0.png" ,posicion.x ,posicion.y, ancho, alto };
	Sprite vidab{ "Texturas/vidab.png" ,posicion.x ,posicion.y, ancho, alto };

	friend class Mundo;
};

