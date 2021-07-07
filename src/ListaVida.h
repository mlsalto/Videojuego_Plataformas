#pragma once
#define MAX_Vida 100
#include "Vida.h"
#include "Interaccion.h"
#include <memory>
#include <vector>
class ListaVida :public Vida
{
private:
	//Tile* lista[MAX_Vida];
	vector<shared_ptr<Tile>> lista;
	int numero;

public:
	ListaVida();
	virtual ~ListaVida();
	//bool agregar(Tile* b);	no hace falta con vector usas push back
	void dibuja();
	void mueve(float t);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Tile* b);
	int getnumero() { return numero; }

	Tile* colision(Personaje& p);
	//Tile* operator [](int i);
	friend class Mundo;

};
