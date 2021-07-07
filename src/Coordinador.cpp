#include "Coordinador.h"
Coordinador::Coordinador()
{
	estado = INICIO;

}
Coordinador::~Coordinador()
{

}

void Coordinador::teclaEspecial(unsigned char key)
{
	if (estado == INICIO)
		menus.teclas_inicio(key);

	else if (estado == JUEGO) {
		mundo.teclaEspecial(key);
	}
	else if (estado == JEFE) {
		mundo.teclaEspecial(key);
		mundo.teclaEspecialBoss(key);
	}
}

void Coordinador::tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == 13 && menus.getComenzar())
		{
			mundo.inicializa();
			estado = JUEGO;
			//mundo.inicializaJefe();
		}
		if (key == 13 && menus.getSalir()) 
		{
			exit(0);
		}
	}
	else if (estado == JUEGO)
	{
		if (key == 'p' || key == 'P')
			estado = PAUSA;
	}
	else if (estado == GAMEOVER) {
		if (key == ' ')
			estado = INICIO;
	}
	else if (estado == FIN)
	{
		if (key == ' ')
			estado = INICIO;
	}

	else if (estado == TIENDA)
	{
	menus.teclas_tienda(key);

		if ((menus.getObjeto()==1) && (key == 13)) { //apuntes
			mundo.setTipoDisparo(1);
			estado = JEFE;//le haces al boss lo que sea y ESTADO= JEFE
		}
		if ((menus.getObjeto()==2) && (key == 13) ){ //calculadora
			mundo.setTipoDisparo(2);
			estado = JEFE;//le haces al boss lo que sea y ESTADO= JEFE
		}
		if ((menus.getObjeto()==3) && (key == 13) ){ //regla
			mundo.setTipoDisparo(3);
			estado = JEFE;//le haces al boss lo que sea y ESTADO= JEFE
		}
		if ((menus.getObjeto()==4) && (key == 13)) { //portatil
			mundo.setTipoDisparo(4);
			estado = JEFE;//le haces al boss lo que sea y ESTADO= JEFE
		}
	
	}

	else if (estado == PAUSA)
	{
		if (key == 'r' || key == 'R')	
		estado = JUEGO;	
	}

	else if (estado == JEFE) {

		mundo.tecla(key);
		
	}
}

void Coordinador::mueve()
{
	if (estado == JUEGO)
	{
		mundo.mover();

		if (mundo.getFinNivel() == true)
		{
			mundo.cargarJefe();
			estado = TIENDA;//estado = TIENDA
		}
		if (mundo.getVidasPersonaje()==0)
		{
			estado = GAMEOVER; 
		}
	}

	if (estado == JEFE)
	{
		mundo.mover();

		if (mundo.getVidasJefe() == 0)
		{
				mundo.cargarNivel();
				estado = JUEGO;//estado = TIENDA
		}
		if (mundo.getVidasPersonaje() == 0)
		{
			estado = GAMEOVER;
		}
		if ((mundo.getVidasJefe() == 0) && mundo.getJefe() == 4)
		{
			estado = FIN;
		}
	}
}

void Coordinador::dibuja()
{
	if (estado == INICIO)
	{
		menus.dibuja_inicio();
	}
	else if (estado == JUEGO)
	{
		mundo.dibuja(true);
	}
	else if (estado == GAMEOVER)
	{
		menus.dibuja_gameover();	
	}
	else if (estado == FIN)
	{
		menus.dibuja_fin();
	}
	else if (estado == TIENDA)
	{
		menus.dibuja_tienda();
	}

	else if (estado == JEFE)
		
	{
		mundo.dibuja(false);
	}

	else if (estado == PAUSA)
	{
		menus.dibuja_pausa();
	}
}

int Coordinador::getEstado()
{
	
	if (estado == INICIO) return 1;
	if (estado == JUEGO) return 2;
	if (estado == GAMEOVER) return 3;
	if (estado == PAUSA) return 4;
	if (estado == TIENDA) return 5;
	if (estado == FIN) return 6;
	if (estado == JEFE) return 7;
	
}
