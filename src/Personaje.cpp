#include "Personaje.h"


Personaje::Personaje(void)
{

	//sprite.setCenter(pos, 1);
	//sprite.setSize(16, 16);
	estado = APOYADO;

	posicion.x = posicion.y = 0;// -5;
	aceleracion.y = -9.8f;
	aceleracion.x = 0.0f; 
	velocidad.x = velocidad.y = 0;
	correr.setSize(0, 0);
	saltar.setSize(0, 0);

	vida = 5;
	vida4.setSize(0, 0);
	vida3.setSize(0, 0);
	vida2.setSize(0, 0);
	vida1.setSize(0, 0);
	vida0.setSize(0, 0);

	numbonus = 0;
	uno.setSize(0, 0);
	dos.setSize(0, 0);
	tres.setSize(0, 0);
	cuatro.setSize(0, 0);
	cinco.setSize(0, 0);
	seis.setSize(0, 0);
	siete.setSize(0, 0);
	ocho.setSize(0, 0);
	nueve.setSize(0, 0);
	diez.setSize(0, 0);
	once.setSize(0, 0);
	doce.setSize(0, 0);
	trece.setSize(0, 0);
	catorce.setSize(0, 0);
	quince.setSize(0, 0);
	dieciseis.setSize(0, 0);
	diecisiete.setSize(0, 0);
	dieciocho.setSize(0, 0);
	diecinueve.setSize(0, 0);
	veinte.setSize(0, 0);
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
	if (dcha == 1)saltar.flip(false, false);  // gira a un lado y a otro
	if (dcha == 0)saltar.flip(true, false);
	saltar.draw();

}
void Personaje::teclaEspecialAbajo(unsigned char key)
{
	idle.setSize(0, 0);
	correr.setSize(0, 0);
	saltar.setSize(0, 0);
	move = 0;

	if (estado == APOYADO)
	{
		switch (key) {
		case GLUT_KEY_LEFT:
			correr.setSize(ancho, alto);
			setVel(-15.0f, 0.0f);
			dcha = 0;
			move = 1;
			break;

		case GLUT_KEY_RIGHT:
			correr.setSize(ancho, alto);
			setVel(15.0f, 0.0f);
			dcha = 1;
			move = 1;
			break;
		case GLUT_KEY_UP:
			if (dcha == 1) {
				saltar.setSize(ancho, alto);
				setVel(7.0f, 17.0f);
				ETSIDI::play("Texturas/Sonidos/salto.mp3");
				estadoPersonaje2();
			}
			if (dcha == 0) {
				saltar.setSize(ancho, alto);
				setVel(-7.0f, 17.0f);
				ETSIDI::play("Texturas/Sonidos/salto.mp3");
				estadoPersonaje2();
			}
			break;

		case GLUT_KEY_DOWN:
			idle.setSize(ancho, alto);
			setVel(0.0f, 0.0f);
			move = 0;
			break;
		}
	}


	else if (estado == VOLANDO)
	{
		switch (key)
		{
		case GLUT_KEY_LEFT:
			saltar.setSize(ancho, alto);
			idle.setSize(0, 0);
			correr.setSize(0, 0);
			dcha = 0;
			break;

		case GLUT_KEY_RIGHT:
			saltar.setSize(ancho, alto);;
			idle.setSize(0, 0);
			correr.setSize(0, 0);
			dcha = 1;
			break;

		case GLUT_KEY_DOWN:
			saltar.setSize(ancho, alto);
			setVel(0.0f, -5.0f);
			idle.setSize(0, 0);
			break;

		case GLUT_KEY_UP:
			saltar.setSize(ancho, alto);
			idle.setSize(0, 0);
			correr.setSize(0, 0);
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

void Personaje::estadoPersonaje1()
{
	estado = APOYADO;
	//cout << "apoyado" << endl;
}

void Personaje::estadoPersonaje2()
{
	estado = VOLANDO;
	//cout << "volando" << endl;
}

void Personaje::dibujarvidas()
{
	estadoVidas(vida);

	if (pepe == false) {
		vida5.setPos(posicion.x - 55, posicion.y + 40);
		vida5.draw();

		vida4.setPos(posicion.x - 55, posicion.y + 40);
		vida4.draw();

		vida3.setPos(posicion.x - 55, posicion.y + 40);
		vida3.draw();

		vida2.setPos(posicion.x - 55, posicion.y + 40);
		vida2.draw();

		vida1.setPos(posicion.x - 55, posicion.y + 40);
		vida1.draw();

		vida0.setPos(posicion.x - 55, posicion.y + 40);
		vida0.draw();

		bonus.setPos(posicion.x + 55, posicion.y + 43);
		bonus.setSize(8, 8);
		bonus.draw();
	}

	if (pepe == true) {
		vida5.setPos(15, 30);
		vida5.draw();

		vida4.setPos(15, 30);
		vida4.draw();

		vida3.setPos(15, 30);
		vida3.draw();

		vida2.setPos(15, 30);
		vida2.draw();

		vida1.setPos(15, 30);
		vida1.draw();

		vida0.setPos(15, 30);
		vida0.draw();

		bonus.setPos(131, 33);
		bonus.setSize(8, 8);
		bonus.draw();
	}
}

void Personaje::estadoVidas(int _vida)
{
	vida5.setSize(0, 0);
	vida4.setSize(0, 0);
	vida3.setSize(0, 0);
	vida2.setSize(0, 0);
	vida1.setSize(0, 0);
	vida0.setSize(0, 0);

	switch (_vida)
	{
	case 5:
		vida5.setSize(ancho, alto);
		break;
	case 4:
		vida4.setSize(ancho, alto);
		break;
	case 3:
		vida3.setSize(ancho, alto);
		break;
	case 2:
		vida2.setSize(ancho, alto);
		break;
	case 1:
		vida1.setSize(ancho, alto);
		break;
	case 0:
		vida0.setSize(ancho, alto);
		break;
	default:
		vida5.setSize(ancho, alto);
		break;
	}

}

void Personaje::dibujarNumBonus()
{
	estadoBonus(numbonus);

	if (pepe == false) {
		uno.setPos(posicion.x + 50, posicion.y + 44.9);
		uno.draw();

		dos.setPos(posicion.x + 50, posicion.y + 44.9);
		dos.draw();

		tres.setPos(posicion.x + 50, posicion.y + 44.9);
		tres.draw();

		cuatro.setPos(posicion.x + 50, posicion.y + 44.9);
		cuatro.draw();

		cinco.setPos(posicion.x + 50, posicion.y + 44.9);
		cinco.draw();

		seis.setPos(posicion.x + 50, posicion.y + 44.9);
		seis.draw();

		siete.setPos(posicion.x + 50, posicion.y + 44.9);
		siete.draw();

		ocho.setPos(posicion.x + 50, posicion.y + 44.9);
		ocho.draw();

		nueve.setPos(posicion.x + 50, posicion.y + 44.9);
		nueve.draw();

		diez.setPos(posicion.x + 50, posicion.y + 44.9);
		diez.draw();

		once.setPos(posicion.x + 50, posicion.y + 44.9);
		once.draw();

		doce.setPos(posicion.x + 50, posicion.y + 44.9);
		doce.draw();

		trece.setPos(posicion.x + 50, posicion.y + 44.9);
		trece.draw();

		catorce.setPos(posicion.x + 50, posicion.y + 44.9);
		catorce.draw();

		quince.setPos(posicion.x + 50, posicion.y + 44.9);
		quince.draw();

		dieciseis.setPos(posicion.x + 50, posicion.y + 44.9);
		dieciseis.draw();

		diecisiete.setPos(posicion.x + 50, posicion.y + 44.9);
		diecisiete.draw();

		dieciocho.setPos(posicion.x + 50, posicion.y + 44.9);
		dieciocho.draw();

		diecinueve.setPos(posicion.x + 50, posicion.y + 44.9);
		diecinueve.draw();

		veinte.setPos(posicion.x + 50, posicion.y + 44.9);
		veinte.draw();
	}
	if (pepe == true) {
		uno.setPos(126, 34.9);
		uno.draw();

		dos.setPos(126, 34.9);
		dos.draw();

		tres.setPos(126, 34.9);
		tres.draw();

		cuatro.setPos(126, 34.9);
		cuatro.draw();

		cinco.setPos(126, 34.9);
		cinco.draw();

		seis.setPos(126, 34.9);
		seis.draw();

		siete.setPos(126, 34.9);
		siete.draw();

		ocho.setPos(126, 34.9);
		ocho.draw();

		nueve.setPos(126, 34.9);
		nueve.draw();

		diez.setPos(126, 34.9);
		diez.draw();

		once.setPos(126, 34.9);
		once.draw();

		doce.setPos(126, 34.9);
		doce.draw();

		trece.setPos(126, 34.9);
		trece.draw();

		catorce.setPos(126, 34.9);
		catorce.draw();

		quince.setPos(126, 34.9);
		quince.draw();

		dieciseis.setPos(126, 34.9);
		dieciseis.draw();

		diecisiete.setPos(126, 34.9);
		diecisiete.draw();

		dieciocho.setPos(126, 34.9);
		dieciocho.draw();

		diecinueve.setPos(126, 34.9);
		diecinueve.draw();

		veinte.setPos(126, 34.9);
		veinte.draw();
	}
}

void Personaje::estadoBonus( int _numbonus)
{
	uno.setSize(0, 0);
	dos.setSize(0, 0);
	tres.setSize(0, 0);
	cuatro.setSize(0, 0);
	cinco.setSize(0, 0);
	seis.setSize(0, 0);
	siete.setSize(0, 0);
	ocho.setSize(0, 0);
	nueve.setSize(0, 0);
	diez.setSize(0, 0);
	once.setSize(0, 0);
	doce.setSize(0, 0);
	trece.setSize(0, 0);
	catorce.setSize(0, 0);
	quince.setSize(0, 0);
	dieciseis.setSize(0, 0);
	diecisiete.setSize(0, 0);
	dieciocho.setSize(0, 0);
	diecinueve.setSize(0, 0);
	veinte.setSize(0, 0);

	switch (_numbonus)
	{
	case 1:
		uno.setSize(4, 4);
		break;
	case 2:
		dos.setSize(4, 4);
		break;
	case 3:
		tres.setSize(4, 4);
		break;
	case 4:
		cuatro.setSize(4, 4);
		break;
	case 5:
		cinco.setSize(4, 4);
		break;
	case 6:
		seis.setSize(4, 4);
		break;
	case 7:
		siete.setSize(4, 4);
		break;
	case 8:
		ocho.setSize(4, 4);
		break;
	case 9:
		nueve.setSize(4, 4);
		break;
	case 10:
		diez.setSize(4, 4);
		break;
	case 11:
		once.setSize(4, 4);
		break;
	case 12:
		doce.setSize(4, 4);
		break;
	case 13:
		trece.setSize(4, 4);
		break;
	case 14:
		catorce.setSize(4, 4);
		break;
	case 15:
		quince.setSize(4, 4);
		break;
	case 16:
		dieciseis.setSize(4, 4);
		break;
	case 17:
		diecisiete.setSize(4, 4);
		break;
	case 18:
		dieciocho.setSize(4, 4);
		break;
	case 19:
		diecinueve.setSize(4, 4);
		break;
	case 20:
		veinte.setSize(4, 4);
		break;
	}
}


float Personaje::getSize()
{
	return ancho;
}

void Personaje::restarVida()
{
	vida -= 1;
}

void Personaje::sumarVida()
{
	vida += 1;
}

void Personaje::sumarBonus()
{
	numbonus += 1;
}

int Personaje::getVida()
{
	return vida;
}

int Personaje::getBonus()
{
	return numbonus;
}

float Personaje::getDireccion()
{
	return dcha;
}

Vector2D Personaje::getVel()
{
	return velocidad;
}

void Personaje::setVida(int x)
{
	vida = x;
}

void Personaje::setBonus(int x)
{
	numbonus = x;
}

void Personaje::setJefeTrue()
{
	pepe = true;
}

void Personaje::setJefeFalse()
{
	pepe = false;
}