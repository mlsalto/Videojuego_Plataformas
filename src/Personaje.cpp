#include "Personaje.h"



Personaje::Personaje()
{

	//sprite.setCenter(pos, 1);
	//sprite.setSize(16, 16);
	posicion.x = posicion.y = -5;
	aceleracion.y = -9.8f;
	aceleracion.x = 0.0f; //no afectado por gravedad
	velocidad.x = velocidad.y = 0;
	correr.setSize(0, 0);
	saltar.setSize(0, 0);
}

void Personaje::dibujar()
{

	    correr.setPos(posicion.x, posicion.y);   //PERSONAJE CORRIENDO
	    // giro de sprite de correr
	    if (velocidad.x > 0.01)correr.flip(false, false);  // gira a un lado y a otro
	    if (velocidad.x < -0.01)correr.flip(true, false);
	    if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		correr.setState(0);
	    else if (correr.getState() == 0)
		correr.setState(1, false);
	    correr.draw();
	   
		idle.setPos(posicion.x, posicion.y);  //PERSONAJE PARADO
		//giro sprite parado
		if (dcha == 1)idle.flip(false, false);  // gira a un lado y a otro
		if (dcha == 0)idle.flip(true, false);
		idle.draw();

		saltar.setPos(posicion.x, posicion.y); //PRESONAJE SALTANDO
		//giro sprite salto
		if (dcha == 1)idle.flip(false, false);  // gira a un lado y a otro
		if (dcha == 0)idle.flip(true, false);
		saltar.draw();


}


void Personaje::teclaEspecialAbajo(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		correr.setSize(16,16);
		//posicion.x -= 0.5f;
		setVel(-15.0f, 0.0f);
		idle.setSize(0, 0);
		saltar.setSize(0, 0);
		dcha = 0;
		break;

	case GLUT_KEY_RIGHT:
		correr.setSize(16, 16);
		setVel(15.0f, 0.0f);
		idle.setSize(0, 0);
		saltar.setSize(0, 0);
		dcha = 1;
		break;

	case GLUT_KEY_DOWN:
		idle.setSize(16, 16);
		setVel(0.0f, 0.0f);
		correr.setSize(0, 0);
		saltar.setSize(0, 0);
		break;

	case GLUT_KEY_UP:
		saltar.setSize(16, 16);
		setVel(0.0f, 10.0f); 
		correr.setSize(0, 0);
		idle.setSize(0, 0);
		break;
	}
	

	//setVel(0.015f, 0.0f);
}



void Personaje::mover(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	correr.loop();
	idle.loop();
	saltar.loop();
}

void Personaje::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

void Personaje::setPos(float px, float py)
{
	posicion.x = px;
	posicion.y = py;
}