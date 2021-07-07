#include "ListaBoss.h"

ListaBoss::ListaBoss()
{
	numero = 0;
	lista.clear();
	/*for (int i = 0; i < MAX_Boss; i++)
		lista[i] = 0;*/
}

ListaBoss::~ListaBoss()
{
}

//bool ListaBoss::agregar(Tile* b)
//{
//	for (int i = 0; i < numero; i++)
//		if (lista[i] == b) return false;
//	if (numero < MAX_Boss)
//		lista[numero++] = b; // ¨²ltimo puesto sin rellenar
//	else
//		return false; // capacidad m¨¢xima alcanzada
//	return true;
//}

void ListaBoss::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaBoss::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaBoss::destruirContenido()
{
	lista.clear();
	numero = 0;
	/*for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;*/
}

void ListaBoss::eliminar(int index)
{
	lista.erase(lista.begin() + index);
	/*if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];*/
}

//void ListaBoss::eliminar(Tile* b)
//{
//	for (int i = 0; i < numero; i++)
//		if (lista[i] == b)
//		{
//			eliminar(i);
//			return;
//		}
//}


Tile* ListaBoss::rebote(Personaje& p)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::rebote(p, (lista[i].get())))
		{
			p.restarVida();
			return lista[i].get();
		}
		return 0;
	}
}

//Tile* ListaBoss::operator [](int i)
//{
//	if (i >= numero)//si me paso, devuelvo la ultima 
//		i = numero - 1;
//	if (i < 0) //si el indice es negativo, devuelvo la primera
//		i = 0;
//	return lista[i];
//}
