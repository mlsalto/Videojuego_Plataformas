#include "Bonus.h"
#include "freeglut.h"

Bonus::Bonus()
{
	//setPos(10, -10);// (15, -5);
	//posicion.x = posicion.y = 10;
}

Bonus::Bonus(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}
//se podria eliminar
Bonus::Bonus(const Bonus& r)
{
	//copia de todos los atributos de l
	//tile
	tipo= r.tipo;							//tipo de tile (suelo, agua... ) TODO implementacion con enum
	columna = r.columna; fila=r.fila;					//índices en el vector de vectores de asignación dinámica de memoria
	lado= r.lado;
	ancho = r.ancho; alto=r.alto;					//dimensión del lado del cuadrado
	posicion= r.posicion;					//posicion central del "cuadrado", se determina a partir de los indices columna y fila y la dimension lado utilizada

	bloque0 = r.bloque0;
	bloque1 = r.bloque1; bloque11 = r.bloque11; bloque12 = r.bloque12;
	bloque2 = r.bloque2; bloque2_1 = r.bloque2_1; bloque2_2 = r.bloque2_2;
	bloque3 = r.bloque3; bloque3_1 = r.bloque3_1; bloque3_2 = r.bloque3_2;
	bloque4 = r.bloque4; bloque4_1 = r.bloque4_1;	bloque4_2 = r.bloque4_2;
	bandera = r.bandera;

	//bonus
	sprite = r.sprite;
	//float ancho, alto;no se si se usan o no
}


void Bonus::dibuja()
{
	sprite.setPos(posicion.x, posicion.y);
	sprite.draw();
}


void Bonus::mueve(float t) 
{
	sprite.loop();
}

