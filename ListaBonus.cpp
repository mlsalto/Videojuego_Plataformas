#include "ListaBonus.h"

ListaBonus::ListaBonus()
{
	numero = 0;
	for (int i = 0; i < MAX_Bonus; i++)
		lista[i] = 0;
}

ListaBonus::~ListaBonus()
{
}

bool ListaBonus::agregar(Bonus* b)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == b) return false;
	if (numero < MAX_Bonus)
		lista[numero++] = b; // ¨²ltimo puesto sin rellenar
	else
		return false; // capacidad m¨¢xima alcanzada
	return true;
}

void  ListaBonus::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaBonus::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaBonus::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaBonus::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaBonus::eliminar(Bonus* b)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == b)
		{
			eliminar(i);
			return;
		}
}

Bonus* ListaBonus::colision(Personaje& p)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(p, *(lista[i])))
			return lista[i];
	} return 0; //no hay colisión 
}

Bonus* ListaBonus::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima 
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}