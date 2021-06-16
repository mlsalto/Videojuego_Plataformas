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

	else if (estado == JUEGO)
		mundo.teclaEspecial(key);
	
}
void Coordinador::tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key = '13' && menus.getComenzar())
			estado = JUEGO;
			mundo.inicializa();
		if (key == '13' && menus.getSalir())
			exit(0);
	}
	else if (estado == JUEGO)
	{
		if (key == 'p')
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
	if (key == '13') {
		if (menus.getApuntes()) {
			//le haces al boss lo que sea y ESTADO= JEFE
		}
		if (menus.getCalculadora()) {
			//le haces al boss lo que sea y ESTADO= JEFE
		}
		if (menus.getRegla()) {
			//le haces al boss lo que sea y ESTADO= JEFE
		}
		if (menus.getPortatil()) {
			//le haces al boss lo que sea y ESTADO= JEFE
		}
	
	}
	}
	else if (estado == PAUSA)
	{
		if (key == 'r')
			estado = JUEGO;
	}

}

void Coordinador::mueve()
{
	if (estado == JUEGO)
	{
		mundo.mover();
			/*if (!mundo.cargarNivel());
			estado = FIN;*/
		
		//if (mundo.getVidas()==0)
		/*{
			estado = GAMEOVER;
		}*/
	}
}
void Coordinador::dibuja()
{
	if (estado == INICIO)
	{

		/*gluLookAt(130, 65, 100, // posicion del ojo 
			130, 65, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)*/

		menus.dibuja_inicio();

	}

	else if (estado == JUEGO)
	{
		mundo.dibuja();
	}
	else if (estado == GAMEOVER)
	{
		mundo.dibuja();
		menus.dibuja_gameover();
		
	}
	else if (estado == FIN)
	{
		mundo.dibuja();
		menus.dibuja_fin();
		
	}
	else if (estado == TIENDA)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo 
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		menus.dibuja_tienda();
	}
	else if (estado == PAUSA)
	{
		menus.dibuja_pausa();
		//mundo.dibuja();
	}
}