#include "Tile.h"
#include "freeglut.h"
#include <iostream>

using namespace ETSIDI;

Tile::Tile()
{
	tipo = 0;
	columna = 0;
	fila = 0;
	lado = 4.0f;
	alto = 4.0f;
	ancho = 4.0f;
	//defino la posicion mediante los índices columna y fila que hace las veces de la coordenada superior izquierda del cuadrado
	//la posicion será la suma de la mitad del lado a la coumna por el valor establecido para el lado
	posicion.x = (double)lado * ((double)columna + 0.5f);
	posicion.y = (double)lado * ((double)-fila - 0.5f);
}

void Tile::setTipo(int _tipo)
{
	tipo = _tipo;
}

void Tile::setColumna_Fila(int _fila, int _columna)
{
	fila = _fila;
	columna = _columna;
	setPosicion();					//al modificar los indices en la matriz se modifica la posicion del tile
}

void Tile::setPosicion()
{
	//defino la posicion mediante los índices columna y fila que hace las veces de la coordenada superior izquierda del cuadrado
	//la posicion será la suma de la mitad del lado a la coumna por el valor establecido para el lado
	posicion.x = (double)lado * ((double)columna + 0.5f);
	posicion.y = (double)lado * ((double)-fila - 0.5f);
}

void Tile::dibuja()
{
	switch (tipo)
	{
	case 0:
		//en el caso de a textura no se pinta nada //la textura es vacia para mostrar el fondo, la imagen de la facultad
		//cout << "DIbujo 0 aire" << endl;
		break;

	case 1: //BLOQUE NEGRO
	{
		this->bloque0.setPos(posicion.x, posicion.y); 
		this->bloque0.setSize(ancho, alto);
		this->bloque0.draw();
		break;
	}
	case 2: //BLOQUE GRIS 1
	{
		this->bloque1.setPos(posicion.x, posicion.y);												//los case para las otras clases solo son necesarios en la funcion cargar
		this->bloque1.setSize(ancho, alto);
		this->bloque1.draw();																		//mediante polimorfismo, al invocar el dibuja de cada tile , dependiendo de la clase hará la llamada a la suya
		break;
	}		
	case 3: //BLOQUE GRIS 2
	{
		this->bloque11.setPos(posicion.x, posicion.y);												//los case para las otras clases solo son necesarios en la funcion cargar
		this->bloque11.setSize(ancho, alto);
		this->bloque11.draw();
		break;
	}
	case 4: //BLOQUE GRIS 3
	{
		this->bloque12.setPos(posicion.x, posicion.y);												//los case para las otras clases solo son necesarios en la funcion cargar
		this->bloque12.setSize(16, 4);
		this->bloque12.draw();
		break;

	}	           
	//case 5: //BONUS
	//{
	//	this->dibuja();
	//	break;
	//
	//}
	//case 6: //OBSTACULO FIJO
	//{
	//	this->dibuja();
	//
	//	break;
	//}
	//case 7: // OBSTACULO MOVIL
	//{
	//	this->dibuja();
	//	break;
	//}
	//case 8: //  VIDA
	//{
	//	this->dibuja();
	//	break;
	//}
	//case 9: //   BOSS
	//{
	//	this->dibuja();
	//	break;
	//}
	case 10: // BANDERITA
	{
		this->bandera.setPos(posicion.x, posicion.y);
		this->bandera.setSize(4, 8);
		this->bandera.draw();
		break;
	}
	case 22: //BLOQUE MARRON 1
	{
		this->bloque2.setPos(posicion.x, posicion.y);												//los case para las otras clases solo son necesarios en la funcion cargar
		this->bloque2.setSize(ancho, alto);
		this->bloque2.draw();																		//mediante polimorfismo, al invocar el dibuja de cada tile , dependiendo de la clase hará la llamada a la suya
		break;
	}
	case 23: //BLOQUE MARRON 2
	{
		this->bloque2_1.setPos(posicion.x, posicion.y);												//los case para las otras clases solo son necesarios en la funcion cargar
		this->bloque2_1.setSize(ancho, alto);
		this->bloque2_1.draw();
		break;
	}
	case 24: //BLOQUE MARRON 3
	{
		this->bloque2_2.setPos(posicion.x, posicion.y);												//los case para las otras clases solo son necesarios en la funcion cargar
		this->bloque2_2.setSize(16, 4);
		this->bloque2_2.draw();
		break;

	}
	case 32: //BLOQUE AZUL 1
	{
		this->bloque3.setPos(posicion.x, posicion.y);												//los case para las otras clases solo son necesarios en la funcion cargar
		this->bloque3.setSize(ancho, alto);
		this->bloque3.draw();																		//mediante polimorfismo, al invocar el dibuja de cada tile , dependiendo de la clase hará la llamada a la suya
		break;
	}
	case 33: //BLOQUE AZUL 2
	{
		this->bloque3_1.setPos(posicion.x, posicion.y);												//los case para las otras clases solo son necesarios en la funcion cargar
		this->bloque3_1.setSize(ancho, alto);
		this->bloque3_1.draw();
		break;
	}
	case 34: //BLOQUE AZUL 3
	{
		this->bloque3_2.setPos(posicion.x, posicion.y);												//los case para las otras clases solo son necesarios en la funcion cargar
		this->bloque3_2.setSize(16, 4);
		this->bloque3_2.draw();
		break;

	}
	case 42: //BLOQUE VERDE 1
	{
		this->bloque4.setPos(posicion.x, posicion.y);												//los case para las otras clases solo son necesarios en la funcion cargar
		this->bloque4.setSize(ancho, alto);
		this->bloque4.draw();																		//mediante polimorfismo, al invocar el dibuja de cada tile , dependiendo de la clase hará la llamada a la suya
		break;
	}
	case 43: //BLOQUE VERDE 2
	{
		this->bloque4_1.setPos(posicion.x, posicion.y);												//los case para las otras clases solo son necesarios en la funcion cargar
		this->bloque4_1.setSize(ancho, alto);
		this->bloque4_1.draw();
		break;
	}
	case 44: //BLOQUE VERDE 3
	{
		this->bloque4_2.setPos(posicion.x, posicion.y);												//los case para las otras clases solo son necesarios en la funcion cargar
		this->bloque4_2.setSize(16, 4);
		this->bloque4_2.draw();
		break;

	}
	default:
		break;
	}
}

int Tile::getTipo()
{
	return tipo;
}

float Tile::getAncho()
{
	return ancho;
}
float Tile::getAlto()
{
	return alto;
}

Vector2D Tile::getPos()
{
	return posicion;
}

void Tile::mueve(float t)
{

}