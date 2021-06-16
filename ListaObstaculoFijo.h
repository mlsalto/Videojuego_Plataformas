#pragma once

#define MAX_ObstaculoFijo 100
#include "ObstaculoFijo.h"
#include "Interaccion.h"
//#include

class ListaObstaculoFijo
{
private:
	ObstaculoFijo* lista[MAX_ObstaculoFijo];
	int numero;

public:
	ListaObstaculoFijo();
	virtual ~ListaObstaculoFijo();
	bool agregar(ObstaculoFijo* o);
	void dibuja();
	void mueve(float t);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(ObstaculoFijo* o);
	int getnumero() { return numero; }

	void rebote(Personaje& p);

};

