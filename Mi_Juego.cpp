#include <iostream>
#include "Coordinador.h"

Coordinador coordinador;

void OnDraw(void);
void OnKeyboardDown(unsigned char key, int x_t, int y_t);
void OnTimer(int value);
void onSpecialKeyboardDown(int key, int x, int y);

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
  	gluPerspective(40.0, 1366 / 768.0f, 0.1, 150);

    
  
  	//Registrar los callbacks
  	glutDisplayFunc(OnDraw);
  	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
  	glutKeyboardFunc(OnKeyboardDown);
  

    glutSpecialFunc(onSpecialKeyboardDown);
  	//inicialización de los datos de la simulacion
    
  	//inicializa();
    //Mapa map;
    //inicialice el puntero con el valor del mapa
    //apuntando = &map;

   // mundo.inicializa();
   
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

   // gluLookAt(58, -8, 90, // posicion del ojo
     //   58, -8, 0.0, // hacia que punto mira (0,0,0)
       // 0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

    coordinador.dibuja();
    // universitario.dibujar();
    // apuntando->dibujarMapa();
    //Al final, cambiar el buffer (redibujar)
    //no borrar esta linea ni poner nada despues 
    glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	coordinador.tecla(key);
	glutPostRedisplay();
}


void onSpecialKeyboardDown(int key, int x, int y)
{;
    coordinador.teclaEspecial(key);
    glutPostRedisplay();
}

void OnTimer(int value)
{

    coordinador.mueve();
	//No borrar las dos ultimas lineas
	glutTimerFunc(25, OnTimer, 0);	//vuelve a hacer la llamada a Ontimer
	glutPostRedisplay();			//vuelve a repitar la escena
}




