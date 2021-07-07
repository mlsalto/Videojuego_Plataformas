#include "Disparo.h"
Disparo::Disparo(void)
{
	setVel(10, 0);
    //posicion real
	//posicion.x = posicion.y = 10.0f;
}

Disparo::Disparo(float x, float y)
{
	setPos(x, y);
	velocidad.x = 10.0f;
}


Disparo::~Disparo(void)
{

}

void Disparo::mueve(float t)
{
	ObjetoMovil::mueve(t);
	slime.loop();
	rayo.loop();
}

void Disparo::dibuja1() //disparo del personaje
{

	switch(objeto)
	{
	case 1: //apuntes
		setVel(10.0f, 0.0f);
		apuntes.setPos(posicion.x, posicion.y); //apuntes
		if (velocidad.x > 0.01) apuntes.flip(false, false);
		if (velocidad.x < -0.01) apuntes.flip(true, false);
		apuntes.draw();
		break;
	case 2: //calculadora
		calculadora.setPos(posicion.x, posicion.y); //calculadora
		if (velocidad.x > 0.01) calculadora.flip(false, false);
		if (velocidad.x < -0.01) calculadora.flip(true, false);
		calculadora.draw();
		break;
	case 3: //regla
		regla.setPos(posicion.x, posicion.y); //regla
		if (velocidad.x > 0.01) regla.flip(false, false);
		if (velocidad.x < -0.01) regla.flip(true, false);
		regla.draw();
		break;
	case 4: //ordenador
		portatil.setPos(posicion.x, posicion.y);   //portatil
		if (velocidad.x > 0.01) portatil.flip(false, false);
		if (velocidad.x < -0.01) portatil.flip(true, false);
		portatil.draw();
		break;
	}
}

void Disparo::dibuja2() //disparo del personaje
{
	switch (jefe)
	{
	case 1: //apuntes
		setVel(-17.0f, 0.0f);
		slime.setPos(posicion.x, posicion.y); //apuntes
		if (velocidad.x > 0.01) slime.flip(false, false);
		if (velocidad.x < -0.01) slime.flip(true, false);
		slime.draw();
		break;
	case 2: //calculadora
		setVel(0.0f, -17.0f);
		avion.setPos(posicion.x, posicion.y); //calculadora
		if (velocidad.x > 0.01) avion.flip(false, false);
		if (velocidad.x < -0.01) avion.flip(true, false);
		avion.draw();
		break;
	case 3: //regla
		setVel(-17.0f, 0.0f);
		rayo.setPos(posicion.x, posicion.y); //regla
		if (velocidad.x > 0.01) rayo.flip(false, false);
		if (velocidad.x < -0.01) rayo.flip(true, false);
		rayo.draw();
		break;
	case 4: //ordenador
		setVel(0.0f, -17.0f);
		error.setPos(posicion.x, posicion.y);   //portatil
		if (velocidad.x > 0.01) error.flip(false, false);
		if (velocidad.x < -0.01) error.flip(true, false);
		error.draw();
		break;
	}
}

void Disparo::setPos(float px, float py) //añadido por lisa
{
	posicion.x = px;
	posicion.y = py;
}

void Disparo::setPos(Vector2D pos)
{
	posicion = pos;
}

Vector2D Disparo::getPos()
{
	return posicion;
}

int Disparo::getObjeto()
{
	return objeto;
}

void Disparo::setDisparoJefe(int x)
{
	jefe = x;
}

void Disparo::setDisparoObjeto(int x)
{
	objeto = x;
}
