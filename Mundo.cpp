#include "Mundo.h"
#include "freeglut.h"
#include "mundo.h"
#include "math.h"


Mundo::~Mundo()
{
}

void Mundo::dibuja()
{
	gluLookAt(universitario.posicion.x, universitario.posicion.y + 10, 100, // posicion del ojo
		universitario.posicion.x, universitario.posicion.y + 10, 0.0, // hacia que punto mira (0,0,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)*/
	universitario.dibujar();
	boss.dibujar();
	apuntando.dibujarMapa();

	fuego.dibuja();
	fuegos.dibuja();
	llama.dibuja();
	llamas.dibuja();
	carnet.dibuja();
}

void Mundo::mover()
{
	universitario.mover(0.025f);	
	boss.mover(0.025f);

	fuego.mueve(0.025f);
	fuegos.mueve(0.025f);
	llama.mueve(0.025f);
	llamas.mueve(0.025f);

	carnet.mueve(0.025f);

	//Interaccion::rebote(universitario, menu);
	Interaccion::rebote(universitario, fuego);
	Interaccion::rebote(universitario, llama);
	//Interaccion::rebote(universitario, boss);
	//if (Interaccion::colision(universitario, tarjeta));

	fuegos.rebote(universitario); //interaccions lista objeto fijo

	if (llamas.rebote(universitario) )
	{
		cafe.vidareal--;
	}

    Bonus* aux = carnet.colision(universitario);
	if (aux != 0)
	{
        carnet.eliminar(aux);
	}
}

void Mundo::tecla(unsigned char key)
{
	
}

void Mundo::inicializa()
{
	//inicializa();
	//Mapa map;
	//inicialice el puntero con el valor del mapa
	//apuntando = &map;
	nivel == 0;
	cargarNivel();
}

void Mundo::teclaEspecial(unsigned char key)
{
	universitario.teclaEspecialAbajo(key);
	menu.teclas_inicio(key);
}

bool Mundo::cargarNivel()
{
	nivel++;
	fuegos.destruirContenido();

	if (nivel == 1)
	{
		ObstaculoFijo* o1 = new ObstaculoFijo(25, -5);
		fuegos.agregar(o1);

		ObstaculoFijo* o2 = new ObstaculoFijo(35, -5);
		fuegos.agregar(o2);

		ObstaculoMovil* m1 = new ObstaculoMovil(25, -10);
		llamas.agregar(m1);

		ObstaculoMovil* m2 = new ObstaculoMovil(45, -10);
		llamas.agregar(m2);

		Bonus* b1 = new Bonus(10, 10);
		carnet.agregar(b1);

		return true;
	}
	if (nivel == 2)
	{
		//lo que sea 
		return true;
	}
	if (nivel>2)
	return false;
}

int Mundo::getVidasPersonaje()
{
	return universitario.getVidas();
}