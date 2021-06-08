#pragma once
#include <iostream>
#include "freeglut.h"
#include "ETSIDI.h"
#include "MatrizTile.h"
#include "Personaje.h"

using namespace ETSIDI;

class Mapa
{
public:
	Mapa();
	//~Mapa();

	/*void cargarMapa();
	void dibujarMapa();*/

	void dibujarMapa();
	void dibujarMapaptr(Mapa* ptr);
	void mover();
	void teclaEspecial(unsigned char key);

private:

	GLTexture facultad;
	MatrizTile celdas;
	Personaje universitario;

	//GLTexture ladrillo;//1
	//GLTexture agua;//2
	//GLTexture persona;//3
	//GLTexture aire;//0
	//GLTexture facultad;
	//TO DO implementacion con asignacion dinamica de mem en funcion de las dimensiones del nivel del txt donde este
	//diseñado el mapa
	//
	/*int nivel[10][25]  {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{3,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
	};*/

};

