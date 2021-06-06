#include <iostream>
#include "freeglut.h"
#include "ETSIDI.h"
#include "Mapa.h"
#include "Personaje.h"



Mapa* apuntando;
Personaje universitario;

//bool* keySpecialStates = new bool[246];

void OnDraw(void);
void OnKeyboardDown(unsigned char key, int x_t, int y_t);
//void OnKeyboardUp(unsigned char key, int x_t, int y_t);
void OnTimer(int value);
void onSpecialKeyboardDown(int key, int x, int y);
//void onSpecialKeyboardUp(int key, int x, int y);

int main(int argc, char* argv[])
{
    //Inicializar el gestor de ventanas GLUT
  	//y crear la ventana
  	glutInit(&argc, argv);
  	glutInitWindowSize(1366, 768);
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  	glutCreateWindow("Mi_Juego");
  
  	//habilitar luces y definir perspectiva
  	glEnable(GL_LIGHT0);
  	glEnable(GL_LIGHTING);
  	glEnable(GL_DEPTH_TEST);
  	glEnable(GL_COLOR_MATERIAL);
  	glMatrixMode(GL_PROJECTION);
  	gluPerspective(40.0, 1366 / 768.0f, 0.1, 150); //40.0,150

    
  
  	//Registrar los callbacks
  	glutDisplayFunc(OnDraw);
  	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
  	glutKeyboardFunc(OnKeyboardDown);
    //glutKeyboardFunc(OnKeyboardUp);

    glutSpecialFunc(onSpecialKeyboardDown); //gestion de los cursores
    //glutSpecialFunc(onSpecialKeyboardUp);
  
  	//inicialización de los datos de la simulacion
   
    Mapa map;
    //inicialice el puntero con el valor del mapa
    apuntando = &map;

    //map.dibujarMapa();
    // 
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

    //en este caso dibujamos solo un cubo de alambre 
    //aqui es donde hay que poner el código de dibujo

    //glEnable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Texturas/textura1.png").id);
    //glDisable(GL_LIGHTING);
    //glBegin(GL_POLYGON);
    ////glColor3f(1, 1, 1);
    //glTexCoord2d(0, 1); glVertex3f(-1.0, 0, 0);
    //glTexCoord2d(1, 1); glVertex3f(1, 0, 0);
    //glTexCoord2d(1, 0); glVertex3f(1, 1, 0);
    //glTexCoord2d(0, 0); glVertex3f(-1, 1, 0);
    //glEnd();
    //glEnable(GL_LIGHTING);
    //glDisable(GL_TEXTURE_2D);
   
    //
    universitario.dibujar();

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
    universitario.teclaEspecialAbajo(key); 
}


void OnTimer(int value)
{
	//mueve();
    universitario.mover(0.025f);

	//No borrar las dos ultimas lineas
	glutTimerFunc(25, OnTimer, 0);	//vuelve a hacer la llamada a Ontimer
	glutPostRedisplay();			//vuelve a repitar la escena
}




