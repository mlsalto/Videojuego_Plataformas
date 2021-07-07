#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "Personaje.h"
#include "Menu.h"
#include "ObstaculoFijo.h"
#include "ObstaculoMovil.h"
#include "Bonus.h"
#include "Boss.h"
#include "Tile.h"
#include "Disparo.h"

//using namespace ETSIDI;

class Interaccion
{
public:
	//using namespace ETSIDI;
	//static void rebote(Personaje& p, Menu m);

	/*static void rebote(Personaje& p, ObstaculoFijo o);
	static bool rebote(Personaje& p, ObstaculoMovil& o);
	static bool colision(Personaje& p, Bonus b);
	static bool rebote(Personaje& p, Boss& b);
	static bool colision(Disparo& p, Boss& b);*/

	static bool rebote(Personaje& p, Tile* o); //alpacas
	static bool rebote1(Personaje& p, Tile* o); //ladrillos cuadrados
	//static void rebote2(Personaje& p, Tile* o); //ladrillos rectangulares


	static bool colision(Personaje& p, Tile& b);  // vida y bonus
	static bool colision1(Personaje& p, Tile& b); //banderita final
	static void colision(Personaje& p, Tile* o); 

	static bool rebote(Disparo& d, Boss& b);
	static bool rebote(Disparo& d, Personaje& p);
};

