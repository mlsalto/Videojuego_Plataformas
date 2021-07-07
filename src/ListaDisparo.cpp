#include "ListaDisparo.h"

ListaDisparo::ListaDisparo()
{
	numero = 0;
	for (int i = 0; i < MAX_Disparo; i++)
		lista[i] = 0;
}

ListaDisparo::~ListaDisparo()
{
}

bool ListaDisparo::agregar(Disparo* b)
{
	for (int i = 0; i < numero; i++)
	{
		if (lista[i] == b) return false;
	}
	
	if (numero < MAX_Disparo) {
		lista[numero++] = b; // ¨²ltimo puesto sin rellenar
	}
	else {
		return false;
	}// capacidad m¨¢xima alcanzada
	return true;
}

void ListaDisparo::dibujaDisparoPersonaje() //disparos de el personaje
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja1();
}

void ListaDisparo::dibujaDisparoJefe() //disparo del  boss
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja2();
}

void ListaDisparo::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaDisparo::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaDisparo::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaDisparo::eliminar(Disparo* b)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == b)
		{
			eliminar(i);
			return;
		}
}

void ListaDisparo::colision1(Boss& p)
{
	for (int i = 0; i < numero; i++)
	{
		Interaccion::rebote(*(lista[i]), p);
	}
}

void ListaDisparo::colision2(Personaje& p)
{
	for (int i = 0; i < numero; i++)
	{
		Interaccion::rebote(*(lista[i]), p);
	}
}

Disparo* ListaDisparo::operator[](int i)
{
	if (i >= numero)
		i = numero - 1;

	if (i < 0)
		i = 0;

	return lista[i];
}