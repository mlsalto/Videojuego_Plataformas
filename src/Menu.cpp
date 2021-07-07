#include "Menu.h"


Menu::Menu()
{
	ancho = 130 ;
	alto = 75 ;
	posicion.x = 1000;
	posicion.y = 1000;
	menu_inicio.setSize(ancho, alto);
	menu_inicio_comenzar.setSize(0, 0);
	menu_inicio_salir.setSize(0, 0);

	tienda.setSize(ancho, alto);
	tienda_apuntes.setSize(0, 0);
	tienda_calculadora.setSize(0, 0);
	tienda_regla.setSize(0, 0);
	tienda_portatil.setSize(0, 0);

	pausa.setSize(ancho, alto);
	fin.setSize(ancho, alto);
	gameover.setSize(ancho, alto);
}

void Menu::dibuja_inicio()
{ 
	float centrox = posicion.x + ancho / 2;
	float centroy = posicion.y + alto / 2;

	gluLookAt(centrox,centroy, 100, // posicion del ojo 
		centrox, centroy, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

	menu_inicio_comenzar.setPos(posicion.x,posicion.y);
	menu_inicio.setPos(posicion.x, posicion.y);
	menu_inicio_salir.setPos(posicion.x, posicion.y);

	menu_inicio_comenzar.draw();
	menu_inicio.draw();
	menu_inicio_salir.draw();
}

void Menu::dibuja_pausa()
{
	float centrox = posicion.x + ancho / 2 - 1000;
	float centroy = posicion.y + alto / 2 - 1000;

	gluLookAt(centrox + 5, centroy + 5, 100, // posicion del ojo 
		centrox + 5, centroy + 5, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	pausa.setSize(ancho, alto);
	//pausa.setPos(0, 0);
	pausa.draw();
}

void Menu::dibuja_fin()
{
	float centrox = posicion.x + ancho / 2 - 1000;
	float centroy = posicion.y + alto / 2 - 1000;

	gluLookAt(centrox + 5, centroy + 5, 100, // posicion del ojo 
		centrox + 5, centroy + 5, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

	fin.setSize(ancho, alto);
	//fin.setPos(0, 0);
	fin.draw();
}

void Menu::dibuja_gameover()
{
	float centrox = posicion.x + ancho / 2 - 1000;
	float centroy = posicion.y + alto / 2 - 1000;

	gluLookAt(centrox + 5, centroy + 5, 100, // posicion del ojo 
		centrox + 5, centroy + 5, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	gameover.setSize(ancho, alto);
	gameover.draw();
}

void Menu::dibuja_tienda()
{
	float centrox = posicion.x + ancho / 2;
	float centroy = posicion.y + alto / 2;

	gluLookAt(centrox, centroy, 100, // posicion del ojo 
		centrox, centroy, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)


	tienda.setPos(posicion.x, posicion.y);
	tienda_apuntes.setPos(posicion.x, posicion.y);
	tienda_calculadora.setPos(posicion.x, posicion.y);
	tienda_regla.setPos(posicion.x, posicion.y);
	tienda_portatil.setPos(posicion.x, posicion.y);

    tienda.draw();
	tienda_regla.draw();
	tienda_apuntes.draw();
	tienda_calculadora.draw();
	tienda_portatil.draw();
}

void Menu::teclas_inicio(int key)
{
	comenzar = salir = false;
	switch (key) 
	{
	case GLUT_KEY_UP:
		menu_inicio.setSize(0, 0);
		menu_inicio_comenzar.setSize(ancho, alto);
		menu_inicio_salir.setSize(0, 0);
		comenzar = true;
		salir = false;
		break;
	
	case GLUT_KEY_DOWN:
		menu_inicio.setSize(0, 0);
		menu_inicio_comenzar.setSize(0, 0);
		menu_inicio_salir.setSize(ancho, alto);
		comenzar = false;
		salir = true;
		break;
	}
}
bool Menu::getComenzar()
{
	return comenzar;
}

bool Menu::getSalir()
{
	return salir;
}

int Menu::getObjeto()
{
	return objeto;
}
	
void Menu::teclas_tienda(unsigned char key)
{
	tienda.setSize(ancho, alto);
	tienda_apuntes.setSize(0, 0);
	tienda_calculadora.setSize(0, 0);
	tienda_regla.setSize(0, 0);
	tienda_portatil.setSize(0, 0);

	switch (key) {
	case '1':
		tienda_apuntes.setSize(ancho  , alto );
		tienda.setSize(0 ,0);
		objeto = 1; //apuntes
		break;
	case '2':
		tienda_calculadora.setSize(ancho, alto);
		tienda.setSize(0, 0);
		objeto = 2; //calculadora
		break;
	case '3':
		tienda_regla.setSize(ancho, alto);
		tienda.setSize(0, 0);
		objeto = 3; //regla
		break;
	case '4':
		tienda_portatil.setSize(ancho, alto);
		tienda.setSize(0, 0);
		objeto = 4; //portatil
		break;
	}
}


void Menu::setPos(float px, float py)
{
	posicion.x = px;
	posicion.y = py;
}
	