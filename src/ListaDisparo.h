#pragma once

#define MAX_Disparo 200
#include "Disparo.h"
#include "Interaccion.h"

class ListaDisparo: public Disparo
{
private:
	Disparo* lista[MAX_Disparo];
	int numero;

public:
	ListaDisparo();
	virtual ~ListaDisparo();
	bool agregar(Disparo* b);

	void dibujaDisparoPersonaje();
	void dibujaDisparoJefe();

	void mueve(float t);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Disparo* b);
	int getnumero() { return numero; }
	Disparo* operator[](int i);

	void colision1(Boss& p);
	void colision2(Personaje& p);
};

