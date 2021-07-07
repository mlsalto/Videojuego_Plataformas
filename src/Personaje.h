#pragma once
#include <iostream>
#include "freeglut.h"
#include "ETSIDI.h"
#include "ObjetoMovil.h"

using namespace ETSIDI;

class Personaje:public ObjetoMovil
{
public:

	Personaje(void);
	//virtual ~Personaje(void);
	
	void dibujar();
	void dibujarvidas();
	void dibujarNumBonus();
	void mover(float t);
	void teclaEspecialAbajo(unsigned char key);
	void estadoVidas(int _vida);
	void estadoBonus(int _numbonus);


	void restarVida();
	void sumarVida();
	void sumarBonus();

	void estadoPersonaje1();
	void estadoPersonaje2();


	int getVida();
	int getBonus();

	float getSize();
	float getDireccion();
	Vector2D getVel();

	void setJefeTrue();
	void setJefeFalse();


	void setVida(int x);
	void setBonus(int x);

	virtual ~Personaje () {}

private:
	
	enum Estado {APOYADO,VOLANDO};
	Estado estado; 

	SpriteSequence correr{ "Texturas/Personaje/correrdcha.png", 8, 1, 100, true, posicion.x, posicion.y, ancho = 15, alto =15};
	SpriteSequence idle{ "Texturas/Personaje/idle.png", 6, 1, 100, true, posicion.x, posicion.y,ancho =15, alto = 15};
	SpriteSequence saltar{ "Texturas/Personaje/saltar.png",8,1,180,true,posicion.x,posicion.y,ancho = 15, alto = 15}; //arreglar sprite

	float dcha;
	float move;
	float ancho, alto;

	bool pepe;
	// parte de la vida del personaje

	int vida = 5;

	Sprite vida5{ "Texturas/Personaje/vida5.png" ,posicion.x ,posicion.y, ancho, alto };
	Sprite vida4{ "Texturas/Personaje/vida4.png" ,posicion.x ,posicion.y, ancho, alto };
	Sprite vida3{ "Texturas/Personaje/vida3.png" ,posicion.x ,posicion.y, ancho, alto };
	Sprite vida2{ "Texturas/Personaje/vida2.png" ,posicion.x ,posicion.y, ancho, alto };
	Sprite vida1{ "Texturas/Personaje/vida1.png" ,posicion.x ,posicion.y, ancho, alto };
	Sprite vida0{ "Texturas/Personaje/vida0.png" ,posicion.x ,posicion.y, ancho, alto };
	Sprite vidab{ "Texturas/Personaje/vidab.png" ,posicion.x ,posicion.y, ancho, alto };

	Sprite bonus{ "Texturas/Personaje/1Bonus.png", posicion.x, posicion.y, ancho, alto };

	int numbonus = 0;

	Sprite uno{ "Texturas/Numeros/1.png",posicion.x, posicion.y, ancho , alto };
	Sprite dos{ "Texturas/Numeros/2.png",posicion.x, posicion.y, ancho , alto };
	Sprite tres{ "Texturas/Numeros/3.png",posicion.x, posicion.y, ancho , alto };
	Sprite cuatro{ "Texturas/Numeros/4.png",posicion.x, posicion.y, ancho , alto };
	Sprite cinco{ "Texturas/Numeros/5.png",posicion.x, posicion.y, ancho , alto };
	Sprite seis{ "Texturas/Numeros/6.png",posicion.x, posicion.y, ancho , alto };
	Sprite siete{ "Texturas/Numeros/7.png",posicion.x, posicion.y, ancho , alto };
	Sprite ocho{ "Texturas/Numeros/8.png",posicion.x, posicion.y, ancho , alto };
	Sprite nueve{ "Texturas/Numeros/9.png",posicion.x, posicion.y, ancho , alto };
	Sprite diez{ "Texturas/Numeros/10.png",posicion.x, posicion.y, ancho , alto };
	Sprite once{ "Texturas/Numeros/12.png",posicion.x, posicion.y, ancho , alto };
	Sprite doce{ "Texturas/Numeros/13.png",posicion.x, posicion.y, ancho , alto };
	Sprite trece{ "Texturas/Numeros/14.png",posicion.x, posicion.y, ancho , alto };
	Sprite catorce{ "Texturas/Numeros/15.png",posicion.x, posicion.y, ancho , alto };
	Sprite quince{ "Texturas/Numeros/16.png",posicion.x, posicion.y, ancho , alto };
	Sprite dieciseis{ "Texturas/Numeros/17.png",posicion.x, posicion.y, ancho , alto };
	Sprite diecisiete{ "Texturas/Numeros/18.png",posicion.x, posicion.y, ancho , alto };
	Sprite dieciocho{ "Texturas/Numeros/19.png",posicion.x, posicion.y, ancho , alto };
	Sprite diecinueve{ "Texturas/Numeros/20.png",posicion.x, posicion.y, ancho , alto };
	Sprite veinte{ "Texturas/Numeros/21.png",posicion.x, posicion.y, ancho , alto };

	friend class Interaccion;
	friend class Mundo;
};

