#pragma once
#include "ETSIDI.h"


class Tile
{	
private:
	int tipo;							//tipo de tile (suelo, agua... ) TODO implementacion con enum
	int columna, fila;					//índices en el vector de vectores de asignación dinámica de memoria
	//float lado;							//dimensión del lado del cuadrado
	float ancho;
	float altura;

	ETSIDI::Vector2D posicion;			//posicion central del "cuadrado", se determina a partir de los indices columna y fila y la dimension lado utilizada
	ETSIDI::GLTexture textura;

	//ETSIDI::GLTexture ladrillo;//1
	//ETSIDI::GLTexture agua;//2
	//ETSIDI::GLTexture persona;//3
	//ETSIDI::GLTexture aire;//0
	//ETSIDI::GLTexture facultad;

public:
	Tile();
	void setTipo(int _tipo);
	void setColumna_Fila(int _fila, int _columna);
	void setPosicion();
	void Dibuja();

	friend class Interaccion;
};

