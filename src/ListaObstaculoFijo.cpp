#include "ListaObstaculoFijo.h"

ListaObstaculoFijo::ListaObstaculoFijo()
{
	numero = 0;
	/*for (int i = 0; i < MAX_ObstaculoFijo; i++)
		lista[i] = 0;*/
	lista.clear();
}

ListaObstaculoFijo::~ListaObstaculoFijo()
{
}

//bool ListaObstaculoFijo::agregar(Tile* o)
//{
//	for (int i = 0; i < numero; i++)
//		if (lista[i] == o) return false;
//	if (numero < MAX_ObstaculoFijo)
//		lista[numero++] = o; // ¨²ltimo puesto sin rellenar
//	else
//		return false; // capacidad m¨¢xima alcanzada
//	return true;
//}

void ListaObstaculoFijo::dibuja()
{
	for (int i = 0; i < lista.size(); i++)
		lista[i]->dibuja();
}

void ListaObstaculoFijo::mueve(float t)
{
	for (int i = 0; i < lista.size(); i++)
		lista[i]->mueve(t);
}

void ListaObstaculoFijo::destruirContenido()
{
	lista.clear();//
	//numero = 0;	//no haria falta ya que los vector tienen un atributo size

	/*for (int i = 0; i < numero; i++)
		delete lista[i];
		//lista.erase(lista.begin() + i);
	numero = 0;*/
}

void ListaObstaculoFijo::eliminar(int index)
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

void ListaObstaculoFijo::eliminar(ObstaculoFijo* o)
{
	for (int i = 0; i < lista.size(); i++) {
		if (lista[i].get() == o)
		{
			eliminar(i);
			//return;ç
			break;
		}
	}
		
}

void ListaObstaculoFijo::rebote(Personaje& p)
{
	//for (int i = 0; i < numero; i++)
	for (int i = 0; i < lista.size(); i++) {
		Interaccion::rebote1(p, lista[i].get());
	}
		
}