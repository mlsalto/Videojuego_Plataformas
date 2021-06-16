#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "Mapa.h"
#include "Personaje.h"
#include "Tile.h"
#include "MatrizTile.h"
#include "Menu.h"
#include "Boss.h"
#include "Interaccion.h"
#include "ObstaculoMovil.h"
#include "ObstaculoFijo.h"
#include "ListaObstaculoMovil.h"
#include "ListaObstaculoFijo.h"
#include "Bonus.h"
#include "ListaBonus.h"
#include "Vida.h"

class Mundo
{
private:

	int nivel;

	Mapa apuntando;
	Personaje universitario;

	MatrizTile bloques;

	ObstaculoFijo fuego;
	ObstaculoMovil llama;

	ListaObstaculoFijo fuegos;
	ListaObstaculoMovil llamas;

	Boss boss;
	Menu menu;

	Vida cafe;

	ListaBonus carnet;
	//Bonus tarjeta;

public:
	void dibuja();
	void mover();
	void inicializa();

	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	int getVidasPersonaje();

	bool cargarNivel();

	virtual ~Mundo();
};
