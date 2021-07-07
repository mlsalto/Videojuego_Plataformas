#pragma once
#define MAX_ObstaculoFijo 100
#include "ObstaculoFijo.h"
#include "Tile.h"
#include "Interaccion.h"
#include <memory>
#include <vector>

class ListaObstaculoFijo :public ObstaculoFijo
{
private:
	//Tile* lista[MAX_ObstaculoFijo];
	vector<shared_ptr<Tile>> lista;
	int numero;

public:
	ListaObstaculoFijo();
	virtual ~ListaObstaculoFijo();
	//bool agregar(Tile* o);
	void dibuja();
	void mueve(float t);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(ObstaculoFijo* o);
	int getnumero() { return numero; }

	void rebote(Personaje& p);
	friend class MatrizTile;
	friend class Mundo;

};

