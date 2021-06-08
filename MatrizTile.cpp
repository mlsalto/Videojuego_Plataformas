#include "MatrizTile.h"
#include <iostream>
#include <fstream>
#include "Interaccion.h"
using namespace std;

					
void MatrizTile::cargarMatrix(int nivel)
{
	mimatriz = new Tile[10][25];
	//for (int i = 0; i < 10; i++) { mimatriz[i] = new Tile[25]; };		//reserva espacio para la memoria 10 filas 25 columnas
	//for (auto& p:mimatriz) p= new Tile[10];		//reserva espacio para la memoria 10 filas 25 columnas
	//to do dependiendo del nivel introducido leerá un fichero u otro
	ifstream fichero("Texturas/Nivel_1.txt");
	if (!fichero)return;
	while (fichero.good()) {	//=!fichero.eof()
		int num; 
		//fichero >> num;
		
		for (int i1 = 0; i1 < 10; i1++) {
			for (int j = 0; j < 25; j++) {
				fichero >> num;
				
				(&mimatriz[i1][j])->setTipo(num);					//carga el tipo en cada tile de la matriz en base a lo que hay en el fichero
				//(mimatriz +(i1*25)+ j)->
				(&mimatriz[i1][j])->setColumna_Fila(i1, j);			//inicializo los valores de los indices en cada tile
																	//setColumna_Fila llama a setPosicion() que actualiza la posicion del tile.
				
			}
		}
	}
}

void MatrizTile::Dibuja()
{
	for (int i1 = 0; i1 < 10; i1++) {
		for (int j = 0; j < 25; j++) {
			(&mimatriz[i1][j])->Dibuja();							//llama a la funcion dibuja de la clase Tile para cada tile de la matriz
			
		}
	}
}

void MatrizTile::colision(Personaje p)
{
	for (int i1 = 0; i1 < 10; i1++) {
		for (int j = 0; j < 25; j++) {
			Interaccion::colision(*(&mimatriz[i1][j]), p);
		}
	}
}


