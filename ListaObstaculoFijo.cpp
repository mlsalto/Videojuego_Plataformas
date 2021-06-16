#include "ListaObstaculoFijo.h"

ListaObstaculoFijo::ListaObstaculoFijo()
{
	numero = 0;
	for (int i = 0; i < MAX_ObstaculoFijo; i++)
		lista[i] = 0;
}

ListaObstaculoFijo::~ListaObstaculoFijo()
{
}

bool ListaObstaculoFijo::agregar(ObstaculoFijo* o)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == o) return false;
	if (numero < MAX_ObstaculoFijo)
		lista[numero++] = o; // ¨²ltimo puesto sin rellenar
	else
		return false; // capacidad m¨¢xima alcanzada
	return true;
}

void ListaObstaculoFijo::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaObstaculoFijo::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaObstaculoFijo::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaObstaculoFijo::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaObstaculoFijo::eliminar(ObstaculoFijo* o)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == o)
		{
			eliminar(i);
			return;
		}
}

void ListaObstaculoFijo::rebote(Personaje& p)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(p, *(lista[i]));
}