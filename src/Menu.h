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
	/*bool getApuntes();
	bool getCalculadora();
	bool getRegla();
	bool getPortatil();*/

	int getObjeto();
	void setPos(float px, float py);
	
private:

	bool salir;
	bool comenzar;
	/*bool apuntes;
	bool calculadora;
	bool regla;
	bool portatil;*/;
	int objeto;
	float ancho, alto;

	Vector2D posicion;


	Sprite menu_inicio{"Texturas/Pantalla/FONDO.png",posicion.x,posicion.y,ancho, alto};
	Sprite menu_inicio_comenzar{"Texturas/Pantalla/FONDO_comenzar.png",posicion.x,posicion.y,ancho, alto };
	Sprite menu_inicio_salir{"Texturas/Pantalla/FONDO_salir.png",posicion.x,posicion.y,ancho, alto };
	Sprite tienda{"Texturas/Pantalla/TIENDA.png",posicion.x,posicion.y,ancho, alto };
	Sprite tienda_apuntes{"Texturas/Pantalla/TIENDA_apuntes.png",posicion.x,posicion.y,ancho, alto };
	Sprite tienda_calculadora{"Texturas/Pantalla/TIENDA_calculadora.png",posicion.x,posicion.y,ancho, alto };
	Sprite tienda_regla{"Texturas/Pantalla/TIENDA_regla.png",posicion.x,posicion.y,ancho, alto };
	Sprite tienda_portatil{"Texturas/Pantalla/TIENDA_portatil.png",posicion.x,posicion.y,ancho, alto };
	Sprite pausa{ "Texturas/Pantalla/PAUSA.png",posicion.x,posicion.y,ancho, alto };
	Sprite fin{ "Texturas/Pantalla/FIN.png",posicion.x,posicion.y,ancho, alto };
	Sprite gameover{ "Texturas/Pantalla/GAMEOVER.png",posicion.x,posicion.y,ancho, alto };

};

