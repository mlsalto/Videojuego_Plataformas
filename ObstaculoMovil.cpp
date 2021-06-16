#include "ObstaculoMovil.h"
using namespace ETSIDI;

ObstaculoMovil::ObstaculoMovil(void)
{
	//setPos(20, -10);// (10, -5);
	posicion.x = posicion.y = -5; //cambiado por Lisa
	posicionx_max = 0.0f;// 20.0f; ///HAY QUE ARREGLAR, CAMBIADO POR LISA
	posicionx_min = -10.0f;// 0.0f;
	velocidad.x = 1.5f;
}

ObstaculoMovil::ObstaculoMovil(float x, float y)
{
	setPos(x, y);
	posicionx_max = x + 10.0f;
	posicionx_min = x - 10.0f;
	velocidad.x = 1.5f;
}

ObstaculoMovil::~ObstaculoMovil(void)
{

}

void ObstaculoMovil::mueve(float t)
{
	ObjetoMovil::mueve(t);

	if (posicion.x > posicionx_max)
		velocidad.x = -velocidad.x;
	if (posicion.x < posicionx_min)
		velocidad.x = -velocidad.x;
	posicion.x += velocidad.x * t;

	paso.loop();
}


void ObstaculoMovil::dibuja()
{
	//glPushMatrix();
	//glTranslatef(posicion.x, posicion.y, 0);
	//gestion de direccion y animacion 
	paso.setPos(posicion.x, posicion.y);
	if (velocidad.x > 0.01) paso.flip(false, false);
	if (velocidad.x < -0.01) paso.flip(true, false);
	paso.draw();
	glPopMatrix();
}

void ObstaculoMovil::setPos(float px, float py) //añadido por lisa
{
	posicion.x = px;
	posicion.y = py;
}