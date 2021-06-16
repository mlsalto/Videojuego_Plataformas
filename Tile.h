#pragma once
#include "ETSIDI.h"
using namespace ETSIDI;

class Tile
{	
private:
	int tipo;							//tipo de tile (suelo, agua... ) TODO implementacion con enum
	int columna, fila;					//índices en el vector de vectores de asignación dinámica de memoria
	float lado;		
	float ancho, alto;//dimensión del lado del cuadrado
	Vector2D posicion;			//posicion central del "cuadrado", se determina a partir de los indices columna y fila y la dimension lado utilizada
	GLTexture textura;

	Sprite ladrillo{"Texturas/textura1.png", posicion.x, posicion.y, ancho, alto};
	

public:
	Tile();
	void setTipo(int _tipo);
	void setColumna_Fila(int _fila, int _columna);
	void setPosicion();
	void Dibuja();
};

