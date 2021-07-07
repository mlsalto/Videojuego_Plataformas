#include "ListaObstaculoMovil.h"
ListaObstaculoMovil::ListaObstaculoMovil()
{
	numero = 0;
	lista.clear();
	/*for (int i = 0; i < MAX_ObstaculoMovil; i++)
		lista[i] = 0;*/
}

ListaObstaculoMovil::~ListaObstaculoMovil()
{
}

//bool ListaObstaculoMovil::agregar(Tile* m)
//{
//	for (int i = 0; i < numero; i++)
//		if (lista[i] == m) return false;
//	if (numero < MAX_ObstaculoMovil)
//		lista[numero++] = m; // ¨²ltimo puesto sin rellenar
//	else
//		return false; // capacidad m¨¢xima alcanzada
//	return true;
//}

void ListaObstaculoMovil::dibuja()
{
	for (int i = 0; i < lista.size(); i++) {
		lista[i]->dibuja();
	}
	
}

void ListaObstaculoMovil::mueve(float t)
{
	for (int i = 0; i < lista.size(); i++) {
		lista[i]->mueve(t);
	}
		
}

void ListaObstaculoMovil::destruirContenido()
{
	lista.clear();
	//numero= 0; // vector ya tiene un atributo size que se pone a 0
	/*for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;*/
}

void ListaObstaculoMovil::eliminar(int index)
{
	lista.erase(lista.begin() + index);
	//numero--;	//no haria falta ya que erase modifica el atributo size de vector
	/*if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];*/
}

void ListaObstaculoMovil::eliminar(Tile* m)
{
	for (int i = 0; i < lista.size(); i++) {
		if (lista[i].get() == m)
		{
			eliminar(i);
			//return;
			break;
		}
	}
		
}

void ListaObstaculoMovil::setMax_Min()
{
	for (int i = 0; i < lista.size(); i++) {
	
		((ObstaculoMovil *)(lista[i].get()))->setMax_Min(); //downcasting
		//(lista.begin() + i)->setMax_Min();
		//((ObstaculoMovil*)lista[i])->setMax_Min();
	}
}

void ListaObstaculoMovil::rebote(Personaje& p)
{
	//for (int i = 0; i < numero; i++)
	for (int i = 0; i < lista.size(); i++)
	{
		if (Interaccion::rebote(p, lista[i].get())) {
			p.restarVida();
		}
	}

}

