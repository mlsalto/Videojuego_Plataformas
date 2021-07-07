#pragma once
#include <iostream>
#include "freeglut.h"
#include "ETSIDI.h"
#include "MatrizTile.h"
#include "Interaccion.h"
using namespace ETSIDI;

class Mapa
{
public:
	Mapa();
	//~Mapa();

	void cargarMapa(int nivel);
	//void dibujarMapa();

	void dibujarMapa();
	void dibujarMapaptr(Mapa* ptr);
	void reboteMapa(Personaje& p);
	bool comprobarSalto(Personaje& p);

	bool finalMapa(Personaje& p, int indice);

	int detectarBandera();
	//Tile* getTile(int indice);
private:
	int nivel;
	MatrizTile celdas;
	friend class Mundo;
};


