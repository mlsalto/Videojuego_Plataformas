#pragma once
#include "Tile.h"
#include <memory>
#include <vector>
#define MAX_TILES 500				//10*largo del maga

class MatrizTile
{

private:

	//Tile (*mimatriz)[25];		//10 "filas" de vectores
	vector<shared_ptr<Tile>> mimatriz;
	//Tile* mimatriz[MAX_TILES];			//vector de 10 "filas"	la buena y confiable
public:
	//void cargarMatrix(int nivel);		//cargar en matriz los tipos de los tiles del fichero nivel
	void cargarMatrix(int nivel);		//funcion pensada para abarcar todos los tipo de tiles
	void dibuja();
	void destruirContenido();
	//Tile* operator [](int i);			//ya no es necesario se puede borrar

	friend class Mapa;
	friend class Mundo;
};

