#include "MatrizTile.h"
#include <iostream>
#include <fstream>
#include "Bonus.h"
#include "ListaBonus.h"
#include "ObstaculoFijo.h"	
#include "ListaObstaculoFijo.h"
#include "ObstaculoMovil.h"
#include "ListaObstaculoMovil.h"

using namespace std;

//void MatrizTile::cargarMatrix(int nivel)
//{
//	//mimatriz = new Tile[10][25];
//	//for (int i = 0; i < 10; i++) { mimatriz[i] = new Tile[25]; };		//reserva espacio para la memoria 10 filas 25 columnas
//	//for (auto& p:mimatriz) p= new Tile[10];		//reserva espacio para la memoria 10 filas 25 columnas
//	//to do dependiendo del nivel introducido leerá un fichero u otro
//	ifstream fichero("Texturas/Nivel_1.txt");
//	if (!fichero)return;
//	while (fichero.good()) {	//=!fichero.eof()
//		int num; 
//		//fichero >> num;
//		
//		for (int i1 = 0; i1 < 10; i1++) {
//			for (int j = 0; j < 25; j++) {
//				fichero >> num;
//				
//				(&mimatriz[i1][j])->setTipo(num);					//carga el tipo en cada tile de la matriz en base a lo que hay en el fichero
//				//(mimatriz +(i1*25)+ j)->
//				(&mimatriz[i1][j])->setColumna_Fila(i1, j);			//inicializo los valores de los indices en cada tile
//																	//setColumna_Fila llama a setPosicion() que actualiza la posicion del tile.
//			}
//		}
//	}
//}

void MatrizTile::cargarMatrix(int nivel)
{
	//dependiendo del nivel introducido abrirá un txt u otro, switch case TO-DO
	if (nivel == 1) {
		ifstream fichero("Texturas/Niveles/Nivel_1.txt");					//abro el fichero correspondiente
		while (fichero.good()) {	//=!fichero.eof()
			int num;
			//fichero >> num;

			for (int k = 0; k < MAX_TILES; (k + 0)) {
				for (int i1 = 0; i1 < 10; i1++) {
					for (int j = 0; j < 50; j++) {
						fichero >> num;										//coge el tipo que sea

						//switch-case en funcion del tipo realizará un new distinto.
						switch (num)
						{
						case 0: //aire-vacio
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 1: //bloque negro
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 2:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 3: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 4:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 5:	//bonus
						{
							mimatriz.push_back(shared_ptr<Tile>(new Bonus()));
							//mimatriz[k] = new Bonus;
							break;
						}
						case 6: //obstaculoFijo
						{
							mimatriz.push_back(shared_ptr<Tile>(new ObstaculoFijo()));
							//mimatriz[k] = new ObstaculoFijo;
							break;
						}
						case 7: //obstaculoMovil
						{
							mimatriz.push_back(shared_ptr<Tile>(new ObstaculoMovil()));
							//mimatriz[k] = new ObstaculoMovil;
							break;
						}
						case 8:	//vida
						{
							mimatriz.push_back(shared_ptr<Tile>(new Vida()));
							//mimatriz[k] = new Vida;
							break;
						}
						case 9: //Boss
						{
							mimatriz.push_back(shared_ptr<Tile>(new Boss()));
							//(mimatriz[k]) = new Boss;
							break;
						}
						case 10: //Banderita
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 22:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 23: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 24:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 32:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 33: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 34:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 42:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 43: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 44:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						default:
							break;

						}
						//por ultimo ejecuta las funciones que caracterizan las propiedades del tile.

						//(&mimatriz[i1][j])->setTipo(num);					//carga el tipo en cada tile de la matriz en base a lo que hay en el fichero
						(mimatriz[k].get())->setTipo(num);
						//(&mimatriz[i1][j])->setColumna_Fila(i1, j);		//inicializo los valores de los indices en cada tile
						(mimatriz[k].get())->setColumna_Fila(i1, j);				//setColumna_Fila llama a setPosicion() que actualiza la posicion del tile.

						k++;												//aumento el índice
					}
				}
			}

		}
	}

	if (nivel == 2) {
		ifstream fichero("Texturas/Niveles/Nivel_2.txt");					//abro el fichero correspondiente
		while (fichero.good()) {	//=!fichero.eof()
			int num;
			//fichero >> num;

			for (int k = 0; k < MAX_TILES; (k + 0)) {
				for (int i1 = 0; i1 < 10; i1++) {
					for (int j = 0; j < 50; j++) {
						fichero >> num;										//coge el tipo que sea

						//switch-case en funcion del tipo realizará un new distinto.
						switch (num)
						{
						case 0: //aire-vacio
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 1: //bloque negro
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 2:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 3: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 4:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 5:	//bonus
						{
							mimatriz.push_back(shared_ptr<Tile>(new Bonus()));
							//mimatriz[k] = new Bonus;
							break;
						}
						case 6: //obstaculoFijo
						{
							mimatriz.push_back(shared_ptr<Tile>(new ObstaculoFijo()));
							//mimatriz[k] = new ObstaculoFijo;
							break;
						}
						case 7: //obstaculoMovil
						{
							mimatriz.push_back(shared_ptr<Tile>(new ObstaculoMovil()));
							//mimatriz[k] = new ObstaculoMovil;
							break;
						}
						case 8:	//vida
						{
							mimatriz.push_back(shared_ptr<Tile>(new Vida()));
							//mimatriz[k] = new Vida;
							break;
						}
						case 9: //Boss
						{
							mimatriz.push_back(shared_ptr<Tile>(new Boss()));
							//(mimatriz[k]) = new Boss;
							break;
						}
						case 10: //Banderita
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 22:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 23: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 24:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 32:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 33: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 34:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 42:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 43: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 44:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						default:
							break;

						}
						//por ultimo ejecuta las funciones que caracterizan las propiedades del tile.

						//(&mimatriz[i1][j])->setTipo(num);					//carga el tipo en cada tile de la matriz en base a lo que hay en el fichero
						mimatriz[k]->setTipo(num);
						//(&mimatriz[i1][j])->setColumna_Fila(i1, j);		//inicializo los valores de los indices en cada tile
						mimatriz[k]->setColumna_Fila(i1, j);				//setColumna_Fila llama a setPosicion() que actualiza la posicion del tile.

						k++;												//aumento el índice
					}
				}
			}
		}
	}

	if (nivel == 3) {
		ifstream fichero("Texturas/Niveles/Nivel_3.txt");					//abro el fichero correspondiente
		while (fichero.good()) {	//=!fichero.eof()
			int num;
			//fichero >> num;

			for (int k = 0; k < MAX_TILES; (k + 0)) {
				for (int i1 = 0; i1 < 10; i1++) {
					for (int j = 0; j < 50; j++) {
						fichero >> num;										//coge el tipo que sea

						//switch-case en funcion del tipo realizará un new distinto.
						switch (num)
						{
						case 0: //aire-vacio
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 1: //bloque negro
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 2:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 3: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 4:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 5:	//bonus
						{
							mimatriz.push_back(shared_ptr<Tile>(new Bonus()));
							//mimatriz[k] = new Bonus;
							break;
						}
						case 6: //obstaculoFijo
						{
							mimatriz.push_back(shared_ptr<Tile>(new ObstaculoFijo()));
							//mimatriz[k] = new ObstaculoFijo;
							break;
						}
						case 7: //obstaculoMovil
						{
							mimatriz.push_back(shared_ptr<Tile>(new ObstaculoMovil()));
							//mimatriz[k] = new ObstaculoMovil;
							break;
						}
						case 8:	//vida
						{
							mimatriz.push_back(shared_ptr<Tile>(new Vida()));
							//mimatriz[k] = new Vida;
							break;
						}
						case 9: //Boss
						{
							mimatriz.push_back(shared_ptr<Tile>(new Boss()));
							//(mimatriz[k]) = new Boss;
							break;
						}
						case 10: //Banderita
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 22:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 23: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 24:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 32:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 33: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 34:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 42:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 43: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 44:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						default:
							break;

						}
						//por ultimo ejecuta las funciones que caracterizan las propiedades del tile.

						//(&mimatriz[i1][j])->setTipo(num);					//carga el tipo en cada tile de la matriz en base a lo que hay en el fichero
						mimatriz[k]->setTipo(num);
						//(&mimatriz[i1][j])->setColumna_Fila(i1, j);		//inicializo los valores de los indices en cada tile
						mimatriz[k]->setColumna_Fila(i1, j);				//setColumna_Fila llama a setPosicion() que actualiza la posicion del tile.

						k++;												//aumento el índice
					}
				}
			}
		}
	}

	if (nivel == 4) {
		ifstream fichero("Texturas/Niveles/Nivel_4.txt");					//abro el fichero correspondiente
		while (fichero.good()) {	//=!fichero.eof()
			int num;
			//fichero >> num;

			for (int k = 0; k < MAX_TILES; (k + 0)) {
				for (int i1 = 0; i1 < 10; i1++) {
					for (int j = 0; j < 50; j++) {
						fichero >> num;										//coge el tipo que sea

						//switch-case en funcion del tipo realizará un new distinto.
						switch (num)
						{
						case 0: //aire-vacio
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 1: //bloque negro
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 2:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 3: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 4:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 5:	//bonus
						{
							mimatriz.push_back(shared_ptr<Tile>(new Bonus()));
							//mimatriz[k] = new Bonus;
							break;
						}
						case 6: //obstaculoFijo
						{
							mimatriz.push_back(shared_ptr<Tile>(new ObstaculoFijo()));
							//mimatriz[k] = new ObstaculoFijo;
							break;
						}
						case 7: //obstaculoMovil
						{
							mimatriz.push_back(shared_ptr<Tile>(new ObstaculoMovil()));
							//mimatriz[k] = new ObstaculoMovil;
							break;
						}
						case 8:	//vida
						{
							mimatriz.push_back(shared_ptr<Tile>(new Vida()));
							//mimatriz[k] = new Vida;
							break;
						}
						case 9: //Boss
						{
							mimatriz.push_back(shared_ptr<Tile>(new Boss()));
							//(mimatriz[k]) = new Boss;
							break;
						}
						case 10: //Banderita
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 22:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 23: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 24:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 32:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 33: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 34:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 42:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 43: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 44:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						default:
							break;

						}
						//por ultimo ejecuta las funciones que caracterizan las propiedades del tile.

						//(&mimatriz[i1][j])->setTipo(num);					//carga el tipo en cada tile de la matriz en base a lo que hay en el fichero
						mimatriz[k]->setTipo(num);
						//(&mimatriz[i1][j])->setColumna_Fila(i1, j);		//inicializo los valores de los indices en cada tile
						mimatriz[k]->setColumna_Fila(i1, j);				//setColumna_Fila llama a setPosicion() que actualiza la posicion del tile.

						k++;												//aumento el índice
					}
				}
			}
		}
	}

	if (nivel == 5) {
		ifstream fichero("Texturas/Niveles/BOSS.txt");					//abro el fichero correspondiente
		while (fichero.good()) {	//=!fichero.eof()
			int num;
			//fichero >> num;

			for (int k = 0; k < MAX_TILES; (k + 0)) {
				for (int i1 = 0; i1 < 10; i1++) {
					for (int j = 0; j < 50; j++) {
						fichero >> num;										//coge el tipo que sea

						//switch-case en funcion del tipo realizará un new distinto.
						switch (num)
						{
						case 0: //aire-vacio
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 1: //bloque negro
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 2:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 3: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 4:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 5:	//bonus
						{
							mimatriz.push_back(shared_ptr<Tile>(new Bonus()));
							//mimatriz[k] = new Bonus;
							break;
						}
						case 6: //obstaculoFijo
						{
							mimatriz.push_back(shared_ptr<Tile>(new ObstaculoFijo()));
							//mimatriz[k] = new ObstaculoFijo;
							break;
						}
						case 7: //obstaculoMovil
						{
							mimatriz.push_back(shared_ptr<Tile>(new ObstaculoMovil()));
							//mimatriz[k] = new ObstaculoMovil;
							break;
						}
						case 8:	//vida
						{
							mimatriz.push_back(shared_ptr<Tile>(new Vida()));
							//mimatriz[k] = new Vida;
							break;
						}
						case 9: //Boss
						{
							mimatriz.push_back(shared_ptr<Tile>(new Boss()));
							//(mimatriz[k]) = new Boss;
							break;
						}
						case 10: //Banderita
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 22:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 23: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 24:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 32:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 33: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 34:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 42:	//bloque gris 1
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 43: //bloque gris 2
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						case 44:  //bloque gris 3
						{
							mimatriz.push_back(shared_ptr<Tile>(new Tile()));
							//(mimatriz[k]) = new Tile;
							break;
						}
						default:
							break;

						}
						//por ultimo ejecuta las funciones que caracterizan las propiedades del tile.

						//(&mimatriz[i1][j])->setTipo(num);					//carga el tipo en cada tile de la matriz en base a lo que hay en el fichero
						mimatriz[k]->setTipo(num);
						//(&mimatriz[i1][j])->setColumna_Fila(i1, j);		//inicializo los valores de los indices en cada tile
						mimatriz[k]->setColumna_Fila(i1, j);				//setColumna_Fila llama a setPosicion() que actualiza la posicion del tile.

						k++;												//aumento el índice
					}
				}
			}
		}
	}
}

void MatrizTile::dibuja()
{
	for (int i = 0; i < MAX_TILES; i++) {
		if (mimatriz[i]->getTipo() == 0 || mimatriz[i]->getTipo() == 1 || mimatriz[i]->getTipo() == 2 || mimatriz[i]->getTipo() == 3 || mimatriz[i]->getTipo() == 4 || mimatriz[i]->getTipo() == 10
			|| mimatriz[i]->getTipo() == 22 || mimatriz[i]->getTipo() == 23 || mimatriz[i]->getTipo() == 24 || mimatriz[i]->getTipo() == 32 || mimatriz[i]->getTipo() == 33 || mimatriz[i]->getTipo() == 34
			|| mimatriz[i]->getTipo() == 42 || mimatriz[i]->getTipo() == 43 || mimatriz[i]->getTipo() == 44)
		{
			mimatriz[i]->dibuja();	//solo pinta lo que no se agrupa en listas 
		}
	}
	//ANTIGUO
	//for (int i1 = 0; i1 < 10; i1++) {
	//	for (int j = 0; j < 25; j++) {
	//		//(&mimatriz[i1][j])->dibuja();							//llama a la funcion dibuja de la clase Tile para cada tile de la matriz
	//		mimatriz[i1][j].dibuja();								//mediante polimorfismo llama a la funcion dibuja que corresponda seguna la clase
	//																//todos los punteros son a la clase base Tile
	//	}
	//}
}

void MatrizTile::destruirContenido()
{
	mimatriz.clear();
}

//Tile* MatrizTile::operator[](int i)
//{
//	return mimatriz[i];
//}