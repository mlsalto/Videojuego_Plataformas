#include "ListaObstaculoMovil.h"

ListaObstaculoMovil::ListaObstaculoMovil()
{
	numero = 0;
	for (int i = 0; i < MAX_ObstaculoMovil; i++)
		lista[i] = 0;
}

ListaObstaculoMovil::~ListaObstaculoMovil()
{
}

bool ListaObstaculoMovil::agregar(ObstaculoMovil* m)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == m) return false;
	if (numero < MAX_ObstaculoMovil)
		lista[numero++] = m; // ¨²ltimo puesto sin rellenar
	else
		return false; // capacidad m¨¢xima alcanzada
	return true;
}

void ListaObstaculoMovil::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaObstaculoMovil::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaObstaculoMovil::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaObstaculoMovil::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaObstaculoMovil::eliminar(ObstaculoMovil* m)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == m)
		{
			eliminar(i);
			return;
		}
}

bool ListaObstaculoMovil::rebote(Personaje& p)
{
	for (int i = 0; i < numero; i++)
	{
		if(Interaccion::rebote(p, *(lista[i]))) return true;
		else return false;
	}
}
