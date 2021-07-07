#include "Boss.h"


Boss::Boss(void)
{
	//setPos(20, -10);// (10, -5);
	posicion.x = 110.0f;
	posicion.y = -16.0f; //cambiado por Lisa
	posicionx_max = 130.0f;// 20.0f; ///HAY QUE ARREGLAR, CAMBIADO POR LISA
	posicionx_min = 100.0f;// 0.0f;
	velocidad.x = 1.5f;
}

Boss::Boss(float x, float y)
{
	setPos(x, y);
	posicionx_max = x + 10.0f;
	posicionx_min = x - 10.0f;
	velocidad.x = 1.5f;
}

Boss::~Boss(void)
{

}

void Boss::mueve(float t)
{
	ObjetoMovil::mueve(t);

	switch (jefe) {
	case 1:
		if (posicion.x > posicionx_max)
			velocidad.x = -velocidad.x;
		if (posicion.x < posicionx_min)
			velocidad.x = -velocidad.x;
		posicion.x += velocidad.x * t;

		jefe1.loop();
		break;
	case 2:
		if (posicion.x > posicionx_max)
			velocidad.x = -velocidad.x;
		if (posicion.x < posicionx_min)
			velocidad.x = -velocidad.x;
		posicion.x += velocidad.x * t;

		jefe2.loop();
		break;
	case 3:
		if (posicion.x > posicionx_max)
			velocidad.x = -velocidad.x;
		if (posicion.x < posicionx_min - 100)
			velocidad.x = -velocidad.x;
		posicion.x += velocidad.x * t;

		jefe3.loop();
		break;

	case 4:
		setVel(0, 0);
		posicion.x = 110.0;
		posicion.y = -16.0;
		break;
	}
}


void Boss::dibuja()
{

	switch (jefe) {
	case 1:
		jefe1.setPos(posicion.x, posicion.y);
		if (velocidad.x > 0.01) jefe1.flip(false, false);
		if (velocidad.x < -0.01) jefe1.flip(true, false);
		jefe1.draw();
		break;

	case 2:
		jefe2.setPos(posicion.x, posicion.y);
		if (velocidad.x > 0.01) jefe2.flip(false, false);
		if (velocidad.x < -0.01) jefe2.flip(true, false);
		jefe2.draw();
		break;

	case 3:
		jefe3.setPos(posicion.x, posicion.y);
		if (velocidad.x > 0.01) jefe3.flip(false, false);
		if (velocidad.x < -0.01) jefe3.flip(true, false);
		jefe3.draw();
		break;

	case 4:
		jefe4.setPos(110.0, -16.0);
		if (velocidad.x == 0) jefe4.flip(false, false);
		//if (velocidad.x = -0.01) jefe4.flip(false, false);
		jefe4.draw();
		break;
	}
}

void Boss::restarVida()
{
	if (disparo.getObjeto() == 1 && jefe == 1) vida -= 2;
	if (disparo.getObjeto() == 2 && jefe == 2) vida -= 2;
	if (disparo.getObjeto() == 3 && jefe == 3) vida -= 2;
	if (disparo.getObjeto() == 4 && jefe == 4) vida -= 2;
	else vida -= 1;
}



int Boss::getVida()
{
	return vida;
}

void Boss::setVida(int x)
{
	vida = x;
}


void Boss::setJefe(int x)
{
	jefe = x;
}
