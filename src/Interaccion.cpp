#include "Interaccion.h"
#include <iostream>
#include <math.h>//bueno

bool Interaccion::rebote(Personaje& p, Tile* o)//alpacas
{
	//suponiendo que el punto de posicion del personaje es el centro y del Obstaculo Fijo también
	float xmin = (o->getPos()).x - (o->getAncho()) / 2;
	float ymin = (o->getPos()).y - (o->getAlto()) / 2;
	float xmax = (o->getPos()).x + (o->getAncho()) / 2;
	float ymax = (o->getPos()).y + (o->getAlto()) / 2;

	// el numero sirve para arreglar el pequeño error de ajuste
	if (p.posicion.x > xmin && p.posicion.x < xmin + 1 && p.posicion.y < ymax && p.posicion.y > ymin) { p.posicion.x = xmin - 5; ETSIDI::play("Texturas/Sonidos/choquetornillos1.mp3"); return true; }// interacción izquierda
	if (p.posicion.x < xmax && p.posicion.x > xmax - 1 && p.posicion.y < ymax && p.posicion.y > ymin) { p.posicion.x = xmax + 5; ETSIDI::play("Texturas/Sonidos/choquetornillos1.mp3"); return true; }// interacción derecha
	if (p.posicion.y < ymax + 1 && p.posicion.y > ymin && p.posicion.x > xmin && p.posicion.x < xmax) { p.posicion.y = ymax + 5; ETSIDI::play("Texturas/Sonidos/choquetornillos1.mp3"); return true; } //interacción arriba
	if (p.posicion.y > ymin - 1 && p.posicion.y < ymin && p.posicion.x > xmin && p.posicion.x < xmax) { p.posicion.y = ymin - 5; ETSIDI::play("Texturas/Sonidos/choquetornillos1.mp3"); return true; }//interacción abajo

	return false;
}

bool Interaccion::rebote1(Personaje& p, Tile* o) ///rebote con tile cuadrada
{
	// el numero sirve para arreglar el pequeño error de ajuste
	float xmin = (o->getPos()).x - ((o->getAncho()) / 2);
	float ymin = (o->getPos()).y - ((o->getAlto()) / 2);
	float xmax = (o->getPos()).x + ((o->getAncho()) / 2);
	float ymax = (o->getPos()).y + ((o->getAlto()) / 2);

	if (o->getTipo() == 2 || o->getTipo() == 3 || o->getTipo() == 22 || o->getTipo() == 23 || o->getTipo() == 32 || o->getTipo() == 33 || o->getTipo() == 42 || o->getTipo() == 43) {
		// el numero sirve para arreglar el pequeño error de ajuste
		if (p.posicion.x > xmin - 4 && p.posicion.x < xmin && p.posicion.y < ymax && p.posicion.y > ymin) { p.posicion.x = xmin - 4; return true; }// interacción izquierda
		if (p.posicion.x < xmax + 0.5 && p.posicion.x > xmax && p.posicion.y < ymax && p.posicion.y > ymin) { p.posicion.x = xmax + 0.5; return true; }// interacción derecha
		if (p.posicion.y < ymax + 1.6 && p.posicion.y > ymin && p.posicion.x > xmin - 4 && p.posicion.x < xmax) { p.posicion.y = ymax + 1.6; p.estadoPersonaje1(); return true; } //interacción arriba
		if (p.posicion.y > ymin - 0.6 && p.posicion.y < ymin && p.posicion.x > xmin - 4 && p.posicion.x < xmax) { p.posicion.y = ymin - 0.6;; return true; } //interacción abajo
	}
	else if (o->getTipo() == 4 || o->getTipo() == 24 || o->getTipo() == 34 || o->getTipo() == 44 ) {
		if (p.posicion.x > xmin - 6 && p.posicion.x < xmin && p.posicion.y < ymax && p.posicion.y > ymin) { p.posicion.x = xmin - 6; return true; }// interacción izquierda
		if (p.posicion.x < xmax + 6 && p.posicion.x > xmax && p.posicion.y < ymax && p.posicion.y > ymin) { p.posicion.x = xmax + 6;return true; }// interacción derecha
		if (p.posicion.y < ymax + 3.6 && p.posicion.y > ymin && p.posicion.x > xmin - 6 && p.posicion.x < xmax + 6) { p.posicion.y = ymax + 3.6; p.estadoPersonaje1(); return true; }//interacción arriba
		if (p.posicion.y > ymin - 1.6 && p.posicion.y < ymin && p.posicion.x > xmin - 6 && p.posicion.x < xmax + 6) { p.posicion.y = ymin - 1.6;return true; }//interacción abajo
	}
	else if (o->getTipo() == 6) {
		if (p.posicion.x > xmin - 0.5 && p.posicion.x < xmin && p.posicion.y < ymax && p.posicion.y > ymin ) { p.posicion.x = xmin - 0.5; return true; }// interacción izquierda
		if (p.posicion.x < xmax + 0.5 && p.posicion.x > xmax && p.posicion.y < ymax && p.posicion.y > ymin ) { p.posicion.x = xmax + 0.5; return true; }// interacción derecha
		if (p.posicion.y < ymax + 2.0 && p.posicion.y > ymin && p.posicion.x > xmin - 0.5 && p.posicion.x < xmax ) { p.posicion.y = ymax + 2.0; p.estadoPersonaje1(); return true; }//interacción arriba
		if (p.posicion.y > ymin - 2.0 && p.posicion.y < ymin && p.posicion.x > xmin - 0.5 && p.posicion.x < xmax ) { p.posicion.y = ymin - 2.0;  return true; }//interacción abajo
	}
	else { //p.estadoPersonaje2(); 
		return false; 
	}
}


void Interaccion::colision(Personaje& p, Tile* o)
{
	//suponiendo que el punto de posicion del personaje es el centro y del Obstaculo Fijo también
	float xmin = (o->getPos()).x - ((o->getAncho()) / 2);
	float ymin = (o->getPos()).y - ((o->getAlto()) / 2);
	float xmax = (o->getPos()).x + ((o->getAncho()) / 2);
	float ymax = (o->getPos()).y + ((o->getAlto()) / 2);

	// el numero sirve para arreglar el pequeño error de ajuste
	if (p.posicion.x > xmin - 2 && p.posicion.x < xmin && p.posicion.y < ymax && p.posicion.y > ymin);// interacción izquierda
	if (p.posicion.x < xmax + 0.5 && p.posicion.x > xmax && p.posicion.y < ymax && p.posicion.y > ymin);// interacción derecha
	if (p.posicion.y < ymax + 1.6 && p.posicion.y > ymin && p.posicion.x > xmin - 2 && p.posicion.x < xmax); //interacción arriba
	if (p.posicion.y > ymin - 1.6 && p.posicion.y < ymin && p.posicion.x > xmin - 2 && p.posicion.x < xmax); //interacción abajo
}

bool Interaccion::colision1(Personaje& p, Tile& b)    //////////////ESTE ES EL DE LA BANDERITA
{
	//suponiendo que el punto de posicion del personaje es el centro y del Obstaculo Fijo también
	float xmin = (b.getPos()).x - (b.getAncho()) / 2;
	float ymin = (b.getPos()).y - (b.getAlto()) / 2;
	float xmax = (b.getPos()).x + (b.getAncho()) / 2;
	float ymax = (b.getPos()).y + (b.getAlto()) / 2;

	// el numero sirve para arreglar el pequeño error de ajuste
	if (p.posicion.x > xmin && p.posicion.x < xmin && p.posicion.y < ymax && p.posicion.y > ymin) { p.posicion.x = xmin - 5; return true; }// interacción izquierda
	if (p.posicion.x < xmax && p.posicion.x > xmax && p.posicion.y < ymax && p.posicion.y > ymin) { p.posicion.x = xmax + 5; return true; }// interacción derecha
	if (p.posicion.y < ymax + 1 && p.posicion.y > ymin && p.posicion.x > xmin && p.posicion.x < xmax) { p.posicion.x = ymax + 5; return true; } //interacción arriba
	if (p.posicion.y > ymin - 1 && p.posicion.y < ymin && p.posicion.x > xmin && p.posicion.x < xmax) { p.posicion.x = ymin - 5; return true; } //interacción abajo
	return false;
}

bool Interaccion::colision(Personaje& p, Tile& b)    //////////////BONUS + VIDA
{
	//suponiendo que el punto de posicion del personaje es el centro y del Obstaculo Fijo también
	float xmin = (b.getPos()).x - (b.getAncho()) / 2;
	float ymin = (b.getPos()).y - (b.getAlto()) / 2;
	float xmax = (b.getPos()).x + (b.getAncho()) / 2;
	float ymax = (b.getPos()).y + (b.getAlto()) / 2;

	// el numero sirve para arreglar el pequeño error de ajuste
	if (p.posicion.x > xmin && p.posicion.x < xmin + 1 && p.posicion.y < ymax && p.posicion.y > ymin)  return true; // interacción izquierda
	if (p.posicion.x < xmax && p.posicion.x > xmax - 1 && p.posicion.y < ymax && p.posicion.y > ymin)  return true; // interacción derecha
	if (p.posicion.y < ymax + 1 && p.posicion.y > ymin && p.posicion.x > xmin && p.posicion.x < xmax)  return true;  //interacción arriba
	if (p.posicion.y > ymin - 1 && p.posicion.y < ymin && p.posicion.x > xmin && p.posicion.x < xmax)  return true; //interacción abajo
	return false;
}

bool Interaccion::rebote(Disparo& d, Boss& b)
{
	//suponiendo que el punto de posicion del personaje es el centro y del Obstaculo Fijo también
	float xmin = b.posicion.x - b.ancho / 2;
	float ymin = b.posicion.y - b.alto / 2;
	float xmax = b.posicion.x + b.ancho / 2;
	float ymax = b.posicion.y + b.alto / 2;

	// el numero sirve para arreglar el pequeño error de ajuste
	if (d.posicion.x > xmin && d.posicion.x < xmin + 1 && d.posicion.y < ymax && d.posicion.y > ymin) { d.posicion.x = xmax + 1000; b.restarVida(); return true; }// interacción izquierda
	if (d.posicion.x < xmax && d.posicion.x > xmax - 1 && d.posicion.y < ymax && d.posicion.y > ymin) { d.posicion.x = xmax - 1000; b.restarVida(); return true; }// interacción derecha
	if (d.posicion.y < ymax + 1 && d.posicion.y > ymin && d.posicion.x > xmin && d.posicion.x < xmax) { d.posicion.y = ymax - 1000; b.restarVida(); return true; } //interacción arriba
	if (d.posicion.y > ymin - 1 && d.posicion.y < ymin && d.posicion.x > xmin && d.posicion.x < xmax) { d.posicion.y = ymin + 1000; b.restarVida(); return true; }//interacción abajo
	return false;
}


bool Interaccion::rebote(Disparo& d, Personaje& p)
{
	//suponiendo que el punto de posicion del personaje es el centro y del Obstaculo Fijo también
	float xmin = p.posicion.x - p.ancho / 2;
	float ymin = p.posicion.y - p.alto / 2;
	float xmax = p.posicion.x + p.ancho / 2;
	float ymax = p.posicion.y + p.alto / 2;

	// el numero sirve para arreglar el pequeño error de ajuste
	if (d.posicion.x > xmin && d.posicion.x < xmin + 1 && d.posicion.y < ymax && d.posicion.y > ymin) { d.posicion.x = xmax + 1000; p.restarVida(); return true; }// interacción izquierda
	if (d.posicion.x < xmax && d.posicion.x > xmax - 1 && d.posicion.y < ymax && d.posicion.y > ymin) { d.posicion.x = xmax - 1000; p.restarVida(); return true; }// interacción derecha
	if (d.posicion.y < ymax + 1 && d.posicion.y > ymin && d.posicion.x > xmin && d.posicion.x < xmax) { d.posicion.y = ymax - 1000; p.restarVida(); return true; } //interacción arriba
	if (d.posicion.y > ymin - 1 && d.posicion.y < ymin && d.posicion.x > xmin && d.posicion.x < xmax) { d.posicion.y = ymin + 1000; p.restarVida(); return true; }//interacción abajo
	return false;
}