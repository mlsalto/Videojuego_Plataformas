#pragma once
#include "Mundo.h"
#include "Menu.h"

class Coordinador
{
public:
	Coordinador();
	virtual ~Coordinador();
	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();

protected:
	Mundo mundo;
	Menu menus;
	enum Estado { INICIO, JUEGO, GAMEOVER, PAUSA, TIENDA,FIN, JEFE };
	Estado estado;
};

