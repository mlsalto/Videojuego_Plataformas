#pragma once
#define MAX_ObstaculoMovil 100
#include "ObstaculoMovil.h"
#include "Interaccion.h"
#include "Vida.h"
#include "Tile.h"
#include <memory>
#include <vector>

class ListaObstaculoMovil :public ObstaculoMovil
{
private:
	//Tile* lista[MAX_ObstaculoMovil];
	vector<shared_ptr<Tile>> lista;
	int numero;

public:
	ListaObstaculoMovil();
	virtual ~ListaObstaculoMovil();
	//bool agregar(Tile* m);
	void dibuja();
	void mueve(float t);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Tile* m);
	int getnumero() { return numero; }
	void setMax_Min();

	void rebote(Personaje& p);

	friend class Mundo;
};