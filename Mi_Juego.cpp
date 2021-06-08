#include <iostream>
#include "freeglut.h"
#include "ETSIDI.h"
#include "Mapa.h"
#include "Tile.h"
#include "MatrizTile.h"
Mapa* apuntando;


void OnDraw(void);
void OnKeyboardDown(unsigned char key, int x_t, int y_t);
void OnTimer(int value);
void onSpecialKeyboardDown(int key, int x, int y);

int main(int argc, char* argv[])
{
    //Inicializar el gestor de ventanas GLUT
  	//y crear la ventana
  	glutInit(&argc, argv);
  	glutInitWindowSize(800, 600);
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  	glutCreateWindow("Mi_Juego");
  
  	//habilitar luces y definir perspectiva
  	glEnable(GL_LIGHT0);
  	glEnable(GL_LIGHTING);
  	glEnable(GL_DEPTH_TEST);
  	glEnable(GL_COLOR_MATERIAL);
  	glMatrixMode(GL_PROJECTION);
  	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

    
  
  	//Registrar los callbacks
  	glutDisplayFunc(OnDraw);
  	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
  	glutKeyboardFunc(OnKeyboardDown);
    glutSpecialFunc(onSpecialKeyboardDown);
  	//inicialización de los datos de la simulacion
    
  	//inicializa();
    Mapa map;
    //inicialice el puntero con el valor del mapa
    apuntando = &map;

   
  	//pasarle el control a GLUT,que llamara a los callbacks
    
  	glutMainLoop();
  
  	return 0;

   }


void OnDraw(void)
{
    //Borrado de la pantalla
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Para definir el punto de vista
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(42, -16, 90, // posicion del ojo
        42, -16, 0.0, // hacia que punto mira (0,0,0)
        0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

    apuntando->dibujarMapa();
    //Al final, cambiar el buffer (redibujar)
    //no borrar esta linea ni poner nada despues 
    glutSwapBuffers();
   
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//tecla(key);
	glutPostRedisplay();
}

void onSpecialKeyboardDown(int key, int x, int y)
{
    // keySpecialStates[key] = true;
    //universitario.teclaEspecialAbajo(key);
    apuntando->teclaEspecial(key);
}
void OnTimer(int value)
{
	//mueve();

    apuntando->mover();
	//No borrar las dos ultimas lineas
	glutTimerFunc(25, OnTimer, 0);	//vuelve a hacer la llamada a Ontimer
	glutPostRedisplay();			//vuelve a repitar la escena
}




