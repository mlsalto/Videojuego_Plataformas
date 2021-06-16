#include "Tile.h"
#include "freeglut.h"
using namespace ETSIDI;
Tile::Tile()
{
	tipo = 0;
	columna = 0;
	fila = 0;
	lado = 4.0f;
												//defino la posicion mediante los índices columna y fila que hace las veces de la coordenada superior izquierda del cuadrado
												//la posicion será la suma de la mitad del lado a la coumna por el valor establecido para el lado
	posicion.x = (double)lado* ((double)columna+ 0.5f);
	posicion.y = (double)lado *((double)-fila - 0.5f);
	textura=getTexture("Texturas/textura1.png");//defecto ladrillo

	//facultad = getTexture("Texturas/facultad.png");
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

void Tile::Dibuja()
{
	switch (tipo)
	{
	case 0:
		textura = getTexture("Texturas/aire.png");								//en el caso de a textura no se pinta nada //la textura es vacia para mostrar el fondo, la imagen de la facultad
		/*glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, aire.id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glTexCoord2d(0, 1); glVertex3f(columna * 4, fila * (-4), 0);
		glTexCoord2d(1, 1); glVertex3f((columna + 1) * 4, fila * (-4), 0);
		glTexCoord2d(1, 0); glVertex3f((columna + 1) * 4, (fila + 1) * (-4), 0);
		glTexCoord2d(0, 0); glVertex3f(columna * 4, (fila + 1) * (-4), 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);*/
		break;
	case 1:
		textura = getTexture("Texturas/textura1.png");		//ladrillo
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textura.id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glTexCoord2d(0, 1); glVertex3f(columna * 4, fila * (-4), 0);
		glTexCoord2d(1, 1); glVertex3f((columna + 1) * 4, fila * (-4), 0);
		glTexCoord2d(1, 0); glVertex3f((columna + 1) * 4, (fila + 1) * (-4), 0);
		glTexCoord2d(0, 0); glVertex3f(columna * 4, (fila + 1) * (-4), 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;
	case 2:
		textura = getTexture("Texturas/agua.png");
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textura.id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glTexCoord2d(0, 1); glVertex3f(columna * 4, fila * (-4), 0);
		glTexCoord2d(1, 1); glVertex3f((columna + 1) * 4, fila * (-4), 0);
		glTexCoord2d(1, 0); glVertex3f((columna + 1) * 4, (fila + 1) * (-4), 0);
		glTexCoord2d(0, 0); glVertex3f(columna * 4, (fila + 1) * (-4), 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;
	
	default:
		break;

	}
}
