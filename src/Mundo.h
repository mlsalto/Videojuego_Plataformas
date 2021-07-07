#pragma once
#include <dos.h>
#include "freeglut.h"
#include "ETSIDI.h"
#include "Mapa.h"
#include "Personaje.h"
#include "Tile.h"
#include "MatrizTile.h"
#include "Menu.h"
#include "Boss.h"
#include "Interaccion.h"
#include "ObstaculoMovil.h"
#include "ObstaculoFijo.h"
#include "ListaObstaculoMovil.h"
#include "ListaObstaculoFijo.h"
#include "Bonus.h"
#include "ListaBonus.h"
#include "Vida.h"
#include "ListaVida.h"
#include "Disparo.h"
#include "ListaDisparo.h"
#include "ListaBoss.h"	//actual
#include "Fondo.h"
class Mundo
{
private:

	int nivel;
	int jefe;
	int num = 0;
	bool finNivel = false;
	int tipodisparo;

	bool valor;
	//int finNivel;

	Mapa apuntando;
	Personaje universitario;


	//ObstaculoFijo fuego;
	//ObstaculoMovil llama;

	ListaObstaculoFijo mesa;
	ListaObstaculoMovil robot;
	//ListaBoss boss;

	Boss boss;
	Menu menu;
	Disparo disparo;

	ListaBonus carnet;
	ListaVida cafe;

	ListaDisparo disparos1;
	ListaDisparo disparos2;

	Fondo fondo;
	//Bonus tarjeta;
	//GLTexture facultad;
public:
	Mundo();
	void dibuja(bool selector);//selector hace la diferencia entre niveles selector==true de tipo juego y selector==false de tipo BOSS
	void mover();
	void inicializa();

	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void teclaEspecialBoss(unsigned char key);

	int getVidasPersonaje();
	int getVidasJefe();
	bool getFinNivel();
	int getNivel();
	int getJefe();
	int getTipoDisparo();

	void setTipoDisparo(int x);

	bool cargarNivel();
	bool cargarJefe();
	void agregarListas();
	virtual ~Mundo();
};