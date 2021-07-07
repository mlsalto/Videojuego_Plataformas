#include "Mapa.h"

Mapa::Mapa()
{
	celdas.cargarMatrix(nivel);									//he puesto el numero 1 porque es el nivel 1 habrá que modificarlo
	//facultad= getTexture("Texturas/facultad.png");

}

void Mapa::cargarMapa(int nivel)
{
	celdas.cargarMatrix(nivel);
}


void Mapa::dibujarMapa()
{

	celdas.cargarMatrix(nivel);
	celdas.dibuja();									//MatrizTile Dibujar

}

void Mapa::dibujarMapaptr(Mapa* ptr)
{
	(*ptr).dibujarMapa();
}

void Mapa::reboteMapa(Personaje& p)
{
	for (int i = 0; i < MAX_TILES; i++)
	{
		if ((celdas.mimatriz[i])->getTipo() == 2 || (celdas.mimatriz[i])->getTipo() == 3 || (celdas.mimatriz[i])->getTipo() == 4 || (celdas.mimatriz[i])->getTipo() == 22 || (celdas.mimatriz[i])->getTipo() == 23 || (celdas.mimatriz[i])->getTipo() == 24 || (celdas.mimatriz[i])->getTipo() == 32 || (celdas.mimatriz[i])->getTipo() == 33 || (celdas.mimatriz[i])->getTipo() == 34 || (celdas.mimatriz[i])->getTipo() == 42 || (celdas.mimatriz[i])->getTipo() == 43 || (celdas.mimatriz[i])->getTipo() == 44)
		{
			Interaccion::rebote1(p, (celdas.mimatriz[i].get()));
		}
	}
	//for (int i = 0; i < MAX_TILES; i++)
	//{
	//	if ((celdas.mimatriz[i])->getTipo() == 2 || (celdas.mimatriz[i])->getTipo() == 3)
	//	{
	//		if (Interaccion::rebote1(p, (celdas.mimatriz[i].get())) == true) {
	//			p.estadoPersonaje1();
	//			//break;
	//		}
	//		else {
	//			p.estadoPersonaje2();
	//			//break;
	//		}   //interacción con ladrillo
	//	}
	//
	//	if (celdas.mimatriz[i]->getTipo() == 4) 
	//	{
	//		Interaccion::rebote2(p, &(celdas.mimatriz[i]));            //interacción con ladrillo
	//	}
	//}
}

bool Mapa::comprobarSalto(Personaje& p)
{
	/*bool Mapa::comprobarSalto(Personaje& p)
{
	for (int i = 0; i < MAX_TILES; i++)
	{
		if (celdas[i]->getTipo() == 2 || celdas[i]->getTipo() == 3 || celdas[i]->getTipo() == 4)
		{
			if (Interaccion::rebote1(p, celdas[i]) == true) {
				p.estadoPersonaje1();
				cout << "bien" << endl;
				return true;
			}
		}
	}
	p.estadoPersonaje2();
	cout << "mal" << endl;
	return false;
}*/
	return false;
}

bool Mapa::finalMapa(Personaje& p, int indice)
{
	if (Interaccion::colision(p, *(celdas.mimatriz[indice]))&& p.getBonus()>=2 )   //añadir indice nivel 2 (banderita)
		return true;
	else return false;
}

int Mapa::detectarBandera()
{
	for (int i = 0; i < MAX_TILES; i++)
	{
		if ((celdas.mimatriz[i])->getTipo() == 10) {
			return i;           //interacción con ladrillo
		}
	}
}

//Tile* Mapa::getTile(int indice)
//{
//	if (indice < MAX_TILES) {
//		return celdas.getTile(indice);
//	}
//
//}



