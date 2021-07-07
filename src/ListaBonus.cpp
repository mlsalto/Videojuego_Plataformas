#include "ListaBonus.h"

ListaBonus::ListaBonus()
{
	numero = 0;
	lista.clear();
	//for (int i = 0; i < MAX_Bonus; i++)	//ADAPTARLO A VECTOR ¿clear()? comprobar en la bibliografia
	//	lista[i] = 0;
}

ListaBonus::~ListaBonus()
{
}

//bool ListaBonus::agregar(Tile* b)
//{
//	
//	//for (int i = 0; i < numero; i++)
//	//	if (lista[i] == b) return false;
//	//if (numero < MAX_Bonus) {
//	//	lista[numero++] = b;
//	//	//lista[numero++] = new Bonus(static_cast<Bonus>(&b)); // ¨²ltimo puesto sin rellenar	// = Tile*(const&b) lo que quiero es que agregue una copia a partir del construct copia
//	//	//lista[numero++] = new Bonus(); //crearía 
//	//	//lista[numero] = b;//faltaria que no copiase la direccion
//	//	//lista[numero].tengo que meterle los valores de b
//	//	//lista[numero]el problema es que ahora lo tengo metido como un bonus
//	//	//funcion conversion de tipos que copie los valores de los atributos de b
//	//}
//	//	
//	//
//	//else
//	//	return false; // capacidad m¨¢xima alcanzada
//	//return true;
//}

void  ListaBonus::dibuja()
{
	for (int i = 0; i < lista.size(); i++) {
		lista[i]->dibuja();
		//((Bonus*)(lista[i].get()))->dibuja();
	}
		
}

void ListaBonus::mueve(float t)
{
	for (int i = 0; i < lista.size(); i++)
		lista[i]->mueve(t);
}

void ListaBonus::destruirContenido()
{
	lista.clear();//
	//numero = 0;	//no haria falta ya que los vector tienen un atributo size

	/*for (int i = 0; i < numero; i++)
		delete lista[i];
		//lista.erase(lista.begin() + i);
	numero = 0;*/
}

void ListaBonus::eliminar(int index)
{
	//(lista[index].get()).erase();
	lista.erase(lista.begin() + index);
	//numero--;	//no haria falta ya que erase modifica el atributo size de vector
	/*if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];*/
}

//int ListaBonus::colision(Personaje& p)
//{
//		for (int i = 0; i < numero; i++)
//	{
//		if (Interaccion::colision(p,*(lista[i])))
//		{
//			p.sumarBonus();
//			return i;
//		}
//		else return 0;
//	}
//}

void ListaBonus::eliminar(Tile* b)
{
	for (int i = 0; i < lista.size(); i++) {
		if (lista[i].get() == b)
		{
			eliminar(i);
			//return;		//así estaba antes
			break;
		}
	}
		/*if (lista[i].get() == b)
		{
			eliminar(i);
			return;
		}*/
}

Tile* ListaBonus::colision(Personaje& p)
{
	//for (int i = 0; i < numero; i++)
	for (int i = 0; i < (lista.size()); i++)
	{
		if (Interaccion::colision(p, *(lista[i])))
		{
			p.sumarBonus();
			
			return lista[i].get();//buena
			break;
		}
	
	}
	return 0;
}


//Tile* ListaBonus::operator [](int i)
//{
//	if (i >= numero)//si me paso, devuelvo la ultima 
//		i = numero - 1;
//	if (i < 0) //si el indice es negativo, devuelvo la primera
//		i = 0;
//	return lista[i];
//}