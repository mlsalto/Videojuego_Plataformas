#include "Personaje.h"


Personaje::Personaje(void)
{

	//sprite.setCenter(pos, 1);
	//sprite.setSize(16, 16);
	posicion.x = posicion.y = 0;// -5;
	aceleracion.y = -9.8f;
	aceleracion.x = 0.0f; 
	velocidad.x = velocidad.y = 0;
	correr.setSize(0, 0);
	saltar.setSize(0, 0);
	vidas = 5;
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
	if (estado == APOYADO) 
	{
		switch (key)
		{
		case GLUT_KEY_LEFT:
			correr.setSize(ancho, alto);
			//posicion.x -= 0.5f;
			setVel(-15.0f, 0.0f);
			idle.setSize(0, 0);
			saltar.setSize(0, 0);
			dcha = 0;
			break;

		case GLUT_KEY_RIGHT:
			correr.setSize(ancho, alto);
			setVel(15.0f, 0.0f);
			idle.setSize(0, 0);
			saltar.setSize(0, 0);
			dcha = 1;
			break;

		case GLUT_KEY_DOWN:
			idle.setSize(ancho, alto);
			setVel(0.0f, 0.0f);
			correr.setSize(0, 0);
			saltar.setSize(0, 0);
			break;

		case GLUT_KEY_UP:
			saltar.setSize(ancho, alto);
			setVel(0.0f, 10.0f);
			correr.setSize(0, 0);
			idle.setSize(0, 0);
			break;
		}
	}

	else if (estado == VOLANDO)
	{
		switch (key)
		{
		case GLUT_KEY_LEFT:
			saltar.setSize(ancho, alto);
			//posicion.x -= 0.5f;
			setVel(-15.0f, 0.0f);
			idle.setSize(0, 0);
			correr.setSize(0, 0);
			dcha = 0;
			break;

		case GLUT_KEY_RIGHT:
			saltar.setSize(ancho, alto);
			setVel(15.0f, 0.0f);
			idle.setSize(0, 0);
			correr.setSize(0, 0);
			dcha = 1;
			break;

		case GLUT_KEY_DOWN:
			saltar.setSize(ancho, alto);
			setVel(0.0f, -5.0f);
			idle.setSize(0, 0);
			saltar.setSize(0, 0);
			break;
		}
	}
	
}


void Personaje::mover(float t)
{
	ObjetoMovil::mueve(t);

	correr.loop();
	idle.loop();
	saltar.loop();
}


float Personaje::getSize()
{
	return ancho;
}
int Personaje::getVidas()
{
	return vidas;
}
