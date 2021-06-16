#pragma once
#include "freeglut.h"
#include "ETSIDI.h"


using namespace ETSIDI;

class Menu
{
public:
	Menu();
	void dibuja_inicio();
	void dibuja_tienda();
	void dibuja_pausa();
	void dibuja_fin();
	void dibuja_gameover();
	void teclas_inicio(int key);
	void teclas_tienda(unsigned char key);
	bool getComenzar();
	bool getSalir();
	bool getApuntes();
	bool getCalculadora();
	bool getRegla();
	bool getPortatil();
	void setPos(float px, float py);
	
private:

	bool salir;
	bool comenzar;
	bool apuntes;
	bool calculadora;
	bool regla;
	bool portatil;
	float ancho, alto;

	Vector2D posicion;


	Sprite menu_inicio{"Texturas/FONDO.png",posicion.x,posicion.y,ancho, alto};
	Sprite menu_inicio_comenzar{"Texturas/FONDO_comenzar.png",posicion.x,posicion.y,ancho, alto };
	Sprite menu_inicio_salir{"Texturas/FONDO_salir.png",posicion.x,posicion.y,ancho, alto };
	Sprite tienda{"Texturas/TIENDA.png",posicion.x,posicion.y,ancho, alto };
	Sprite tienda_apuntes{"Texturas/TIENDA_apuntes.png",posicion.x,posicion.y,ancho, alto };
	Sprite tienda_calculadora{"Texturas/TIENDA_calculadora.png",posicion.x,posicion.y,ancho, alto };
	Sprite tienda_regla{"Texturas/TIENDA_regla.png",posicion.x,posicion.y,ancho, alto };
	Sprite tienda_portatil{"Texturas/TIENDA_portatil.png",posicion.x,posicion.y,ancho, alto };
	Sprite pausa{ "Texturas/PAUSA.png",posicion.x,posicion.y,ancho, alto };
	Sprite fin{ "Texturas/FIN.png",posicion.x,posicion.y,ancho, alto };
	Sprite gameover{ "Texturas/GAMEOVER.png",posicion.x,posicion.y,ancho, alto };

};

