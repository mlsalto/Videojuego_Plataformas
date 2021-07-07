#pragma once
#define MAX_Boss 5
#include "Boss.h"
#include "Interaccion.h"
#include "Vida.h"
#include <memory>
#include <vector>
class ListaBoss :public Boss
{
private:
	//Tile* lista[MAX_Boss];
	vector<shared_ptr<Tile>>lista;
	int numero;

public:
	ListaBoss();
	virtual ~ListaBoss();
	//bool agregar(Tile* b);
	void dibuja();
	void mueve(float t);
	void destruirContenido();
	void eliminar(int index);
	//void eliminar(Tile* b);
	int getnumero() { return numero; }


	Tile* rebote(Personaje& p);
	//Tile* operator [](int i);
	friend class Mundo;
};