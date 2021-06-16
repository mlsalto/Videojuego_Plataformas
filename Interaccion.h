#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "Personaje.h"
#include "Menu.h"
#include "ObstaculoFijo.h"
#include "ObstaculoMovil.h"
#include "Bonus.h"

//using namespace ETSIDI;

class Interaccion
{
public:
	//using namespace ETSIDI;
	//static void rebote(Personaje& p, Menu m);
	static void rebote(Personaje& p, ObstaculoFijo o);
	static bool rebote(Personaje& p, ObstaculoMovil& o);
	static bool colision(Personaje& p, Bonus b);
};

