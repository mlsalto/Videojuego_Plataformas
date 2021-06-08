#include "Mapa.h"


Mapa::Mapa()
{
	celdas.cargarMatrix(1);									//he puesto el numero 1 porque es el nivel 1 habrá que modificarlo
	facultad= getTexture("Texturas/facultad.png");
	
}

void Mapa::dibujarMapa()
{
	//int tiletype = 0;
	
	//for (int fila = 0; fila < 10; fila++)
	//{
	//	for (int columna = 0; columna < 25; columna++) {
	//		tiletype = nivel[fila][columna];
	//		switch (tiletype)
	//		{
	//		case 0:
	//			/*glEnable(GL_TEXTURE_2D);
	//			glBindTexture(GL_TEXTURE_2D, aire.id);
	//			glDisable(GL_LIGHTING);
	//			glBegin(GL_POLYGON);
	//			
	//			glTexCoord2d(0, 1); glVertex3f(columna * 4, fila * (-4), 0);
	//			glTexCoord2d(1, 1); glVertex3f((columna + 1) * 4, fila * (-4), 0);
	//			glTexCoord2d(1, 0); glVertex3f((columna + 1) * 4, (fila + 1) * (-4), 0);
	//			glTexCoord2d(0, 0); glVertex3f(columna * 4, (fila + 1) * (-4), 0);
	//			glEnd();
	//			glEnable(GL_LIGHTING);
	//			glDisable(GL_TEXTURE_2D);*/
	//			break;
	//		case 1:
	//			glEnable(GL_TEXTURE_2D);
	//			glBindTexture(GL_TEXTURE_2D, ladrillo.id);
	//			glDisable(GL_LIGHTING);
	//			glBegin(GL_POLYGON);
	//			
	//			glTexCoord2d(0, 1); glVertex3f(columna * 4, fila * (-4), 0);
	//			glTexCoord2d(1, 1); glVertex3f((columna + 1) * 4, fila * (-4), 0);
	//			glTexCoord2d(1, 0); glVertex3f((columna + 1) * 4, (fila + 1) * (-4), 0);
	//			glTexCoord2d(0, 0); glVertex3f(columna * 4, (fila + 1) * (-4), 0);
	//			glEnd();
	//			glEnable(GL_LIGHTING);
	//			glDisable(GL_TEXTURE_2D);
	//			break;
	//		case 2:
	//			glEnable(GL_TEXTURE_2D);
	//			glBindTexture(GL_TEXTURE_2D, agua.id);
	//			glDisable(GL_LIGHTING);
	//			glBegin(GL_POLYGON);
	//			
	//			glTexCoord2d(0, 1); glVertex3f(columna * 4, fila * (-4), 0);
	//			glTexCoord2d(1, 1); glVertex3f((columna + 1) * 4, fila * (-4), 0);
	//			glTexCoord2d(1, 0); glVertex3f((columna + 1) * 4, (fila + 1) * (-4), 0);
	//			glTexCoord2d(0, 0); glVertex3f(columna * 4, (fila + 1) * (-4), 0);
	//			glEnd();
	//			glEnable(GL_LIGHTING);
	//			glDisable(GL_TEXTURE_2D);
	//			break;
	//		case 3:
	//			glEnable(GL_TEXTURE_2D);
	//			glBindTexture(GL_TEXTURE_2D, persona.id);
	//			glDisable(GL_LIGHTING);
	//			glBegin(GL_POLYGON);
	//			 
	//			glTexCoord2d(0, 1); glVertex3f(columna * 4, fila * (-4), 0);
	//			glTexCoord2d(1, 1); glVertex3f((columna + 1) * 4, fila * (-4), 0);
	//			glTexCoord2d(1, 0); glVertex3f((columna + 1) * 4, (fila + 1) * (-4), 0);
	//			glTexCoord2d(0, 0); glVertex3f(columna * 4, (fila + 1) * (-4), 0);
	//			glEnd();
	//			glEnable(GL_LIGHTING);
	//			glDisable(GL_TEXTURE_2D);
	//			break;
	//		default: 
	//			break;
	//
	//		}
	//
	//	}
	//}


	celdas.cargarMatrix(1);
	celdas.Dibuja();									//MatrizTile Dibujar
	glEnable(GL_TEXTURE_2D);							//fondo de la pantalla
	glBindTexture(GL_TEXTURE_2D, facultad.id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);

	glTexCoord2d(0, 1); glVertex3f(0, -32, -3);
	glTexCoord2d(1, 1); glVertex3f(84, -32, -3);
	glTexCoord2d(1, 0); glVertex3f(84,32,-3);
	glTexCoord2d(0, 0); glVertex3f(0, 32, -3);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}

void Mapa::dibujarMapaptr(Mapa* ptr)
{
	(*ptr).dibujarMapa();
}




