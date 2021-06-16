#include "Boss.h"

Boss::Boss()
{
	//posicion.x = posicion.y = -30;// -5;
	boss.setPos(100, 0);
	aceleracion.y = 0.0;// -9.8f;
	aceleracion.x = 0.0f; //no afectado por gravedad
	velocidad.x = velocidad.y = 0;
}

void Boss::dibujar()
{
	boss.draw();
}

void Boss::mover(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	boss.loop();
}

void Boss::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

void Boss::setPos(float px, float py)
{
	posicion.x = px;
	posicion.y = py;
}
