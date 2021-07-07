#pragma once
#define MAX_Bonus 100
#include "Bonus.h"
#include "Tile.h"
#include "Interaccion.h"
#include <memory>
#include <vector>

class ListaBonus :public Bonus
{
private:
	//Tile* lista[MAX_Bonus];
	vector<shared_ptr<Tile>> lista;
	int numero;

public:
	ListaBonus();
	virtual ~ListaBonus();
	//bool agregar(Tile* b);//lista.push_back(o)
	void dibuja();		
	void mueve(float t);
	void destruirContenido();		//implementar con vector
	void eliminar(int index);
	void eliminar(Tile* b);		//consultar si es necesaria o no
	int getnumero() { return numero; }

	Tile* colision(Personaje& p);
	
	//int colision(Personaje& p);
	//Tile* operator [](int i); //no es necesario vector ya lo tiene

	friend class MatrizTile;
	friend class Mundo;
};
