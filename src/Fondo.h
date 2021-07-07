#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Tile.h"


class Fondo :public Tile
{
public:
	void nivel1();
	void nivel2();
	void nivel3();
	void nivel4();

	void jefe1();
	void jefe2();
	void jefe3();
	void jefe4();

	//void dibujarJefe()

	void dibujarNivel(int nivel);
	void dibujarJefe(int jefe);

private:

	int nivel;
	int jefe;

	Sprite pared1{ "Texturas/Fondo/fondo1.png", 12, 12, 40,20 };
	Sprite puerta1{ "Texturas/Fondo/fondo1_puerta.png", 12, 12, 40,20 };

	Sprite pared2{ "Texturas/Fondo/fondo2.png", 12, 12, 40,20 };
	Sprite puerta2{ "Texturas/Fondo/fondo2_puerta.png", 12, 12, 40,20 };

	Sprite pared3{ "Texturas/Fondo/fondo3.png", 12, 12, 40,20 };
	Sprite puerta3{ "Texturas/Fondo/fondo3_puerta.png", 12, 12, 40,20 };

	Sprite pared4{ "Texturas/Fondo/fondo4.png", 12, 12, 40,20 };
	Sprite puerta4{ "Texturas/Fondo/fondo4_puerta.png", 12, 12, 40,20 };
};

