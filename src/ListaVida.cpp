#include "ListaVida.h"

ListaVida::ListaVida()
{
	numero = 0;
	/*for (int i = 0; i < MAX_Vida; i++)
		lista[i] = 0;*/
	lista.clear();
}

ListaVida::~ListaVida()
{
}

//bool ListaVida::agregar(Tile* b)
//{
//	for (int i = 0; i < numero; i++)
//		if (lista[i] == b) return false;
//	if (numero < MAX_Vida)
//		lista[numero++] = b; // ¨²ltimo puesto sin rellenar
//	else
//		return false; // capacidad m¨¢xima alcanzada
//	return true;
//}

void  ListaVida::dibuja()
{
	for (int i = 0; i < lista.size(); i++) {
		lista[i]->dibuja();
	}
		
}

void ListaVida::mueve(float t)
{
	for (int i = 0; i < lista.size(); i++) {
		lista[i]->mueve(t);
	}
		
}

void ListaVida::destruirContenido()
{
	lista.clear();
	//numero =0;			vector tiene un atributo que se llama size que se pone a 0 al ejecutar clear

	/*for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;*/
}

void ListaVida::eliminar(int index)
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

void ListaVida::eliminar(Tile* b)
{
	for (int i = 0; i < lista.size(); i++) {
		if (lista[i].get() == b)
		{
			eliminar(i);
			//return;
			break;
		}
	}
		/*if (lista[i].get() == b)
		{
			eliminar(i);
			return;
		}*/// antes el for no tenia {}
}

Tile* ListaVida::colision(Personaje& p)
{
	//for (int i = 0; i < numero; i++)
	for (int i = 0; i < lista.size(); i++)
	{
		if (Interaccion::colision(p, *(lista[i])))
		{
			p.sumarVida();
			return lista[i].get();
			break;
		}
		
	} 
	return 0;//no hay colisión 
}

//Tile* ListaVida::operator [](int i)
//{
//	if (i >= numero)//si me paso, devuelvo la ultima 
//		i = numero - 1;
//	if (i < 0) //si el indice es negativo, devuelvo la primera
//		i = 0;
//	return lista[i];
//}