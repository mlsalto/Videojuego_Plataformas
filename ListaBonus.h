#pragma once

#define MAX_Bonus 100
#include "Bonus.h"
#include "Interaccion.h"

class ListaBonus
{
private:
	Bonus* lista[MAX_Bonus];
	int numero;

public:
	ListaBonus();
	virtual ~ListaBonus();
	bool agregar(Bonus* b);
	void dibuja();
	void mueve(float t);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Bonus* b);
	int getnumero() { return numero; }

	Bonus* colision(Personaje& p);
	Bonus* operator [](int i);
};

