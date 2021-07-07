
#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "ObjetoMovil.h"
#include "Personaje.h"
#include "Menu.h"

using namespace ETSIDI;

class Disparo : public ObjetoMovil
{
private:

	Personaje personaje; //??????????
	Menu menu;

	int objeto; //debe estar a 0
	int jefe;
	//SpriteSequence boss{ "Texturas/boss1.png", 7, 1, 100, true, posicion.x, posicion.y, ancho = 48, alto = 32 };

	Sprite apuntes{ "Texturas/Objetos/apuntes.png", posicion.x, posicion.y, ancho = 5, alto = 5 };
	Sprite calculadora{ "Texturas/Objetos/calculadora.png", posicion.x, posicion.y, ancho = 5, alto = 5 };
	Sprite regla{ "Texturas/Objetos/regla.png", posicion.x, posicion.y, ancho = 5, alto = 5 };
	Sprite portatil{ "Texturas/Objetos/portatil.png", posicion.x, posicion.y, ancho = 5, alto = 5 };

	SpriteSequence slime{ "Texturas/Jefes/boss1.2.png", 4, 1, 50, true, posicion.x, posicion.y, ancho = 6, alto = 4 };
	SpriteSequence rayo{ "Texturas/Jefes/boss3.1.png", 13, 1,100,true, posicion.x, posicion.y, ancho = 10, alto = 10 };
	Sprite error{ "Texturas/Jefes/boss4.1.png", posicion.x, posicion.y, ancho = 8, alto = 4 };
	Sprite avion{ "Texturas/Jefes/avion.png", posicion.x, posicion.y, ancho = 4, alto = 4 };

	friend class Interaccion;

public:
	Disparo(void);
	Disparo(float x, float y);
	virtual ~Disparo(void);

	void mueve(float t);
	void dibuja1();
	void dibuja2();

	void setDisparoJefe(int x);
	void setDisparoObjeto(int x);

	void setPos(float px, float py);
	void setPos(Vector2D pos);
	int getObjeto();
	Vector2D getPos();

	//void TeclaAbajo(unsigned char key);

};


