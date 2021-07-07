#pragma once
#include "ETSIDI.h"
using namespace ETSIDI;

class Tile
{
protected:
	int tipo;							//tipo de tile (suelo, agua... ) TODO implementacion con enum
	int columna, fila;					//índices en el vector de vectores de asignación dinámica de memoria
	float lado;
	float ancho, alto;					//dimensión del lado del cuadrado
	Vector2D posicion;					//posicion central del "cuadrado", se determina a partir de los indices columna y fila y la dimension lado utilizada


	Sprite bloque0{ "Texturas/Bloques/bloque0.png", posicion.x, posicion.y, ancho = 8, alto = 8 };//bloque negro

	Sprite bloque1{ "Texturas/Bloques/bloque1.png", posicion.x, posicion.y, ancho = 8, alto = 8 }; //bloques grises
	Sprite bloque11{ "Texturas/Bloques/bloque1.1.png", posicion.x, posicion.y, ancho = 8, alto = 8 };
	Sprite bloque12{ "Texturas/Bloques/bloque1.2.png", posicion.x, posicion.y, ancho = 16, alto = 4 };

	Sprite bloque2{ "Texturas/Bloques/bloque2.png", posicion.x, posicion.y, ancho = 8, alto = 8 };  //bloques marrones
	Sprite bloque2_1{ "Texturas/Bloques/bloque2.1.png", posicion.x, posicion.y, ancho = 8, alto = 8 };
	Sprite bloque2_2{ "Texturas/Bloques/bloque2.2.png", posicion.x, posicion.y, ancho = 16, alto = 4 };

	Sprite bloque3{ "Texturas/Bloques/bloque3.png", posicion.x, posicion.y, ancho = 8, alto = 8 }; //bloques azules
	Sprite bloque3_1{ "Texturas/Bloques/bloque3.1.png", posicion.x, posicion.y, ancho = 8, alto = 8 };
	Sprite bloque3_2{ "Texturas/Bloques/bloque3.2.png", posicion.x, posicion.y, ancho = 16, alto = 4 };

	Sprite bloque4{ "Texturas/Bloques/bloque4.png", posicion.x, posicion.y, ancho = 8, alto = 8 }; //vloques verdes
	Sprite bloque4_1{ "Texturas/Bloques/bloque4.1.png", posicion.x, posicion.y, ancho = 8, alto = 8 };
	Sprite bloque4_2{ "Texturas/Bloques/bloque4.2.png", posicion.x, posicion.y, ancho = 16, alto = 4 };

	Sprite bandera{ "Texturas/Objetos/banderitafinal.png", posicion.x, posicion.y, ancho = 8, alto = 16 }; //CAMBIAR, BANDERITA FINAL


public:
	Tile();
	void setTipo(int _tipo);
	void setColumna_Fila(int _fila, int _columna);
	void setPosicion();
	virtual void dibuja();
	int getTipo();
	float getAncho();
	float getAlto();
	Vector2D getPos();
	virtual void mueve(float t);
};