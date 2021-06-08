#pragma once
#include "Tile.h"
#include "Personaje.h"

class MatrizTile
{

private:
	Tile (*mimatriz)[25];		//10 "filas" de vectores
public:
	void cargarMatrix(int nivel);		//cargar en matriz los tipos de los tiles del fichero nivel
	void Dibuja();
	void colision(Personaje p);
};


