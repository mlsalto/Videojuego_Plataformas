
#if defined(_M_X64) || defined(__amd64__)
#    include "freeglut.h"
#else
#    include "glut.h"
#endif
#include <math.h>
#include "ETSIDI.h"

#include <iostream>
using namespace ETSIDI;
using ETSIDI::getTexture;
struct Esfera
{
	float radio;
	float x;
	float y;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
};
struct Mundo
{
	float x_ojo;
	float y_ojo;
	float z_ojo;
};

Mundo mundo={0,788,384};
SpriteSequence *Idle;


//OGLFT::Monochrome* monochrome;
//TTF::Font *font;
//TTF::Triangulator2DI triangulatorA, triangulatorB;
//declaraciones de funciones


//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(1366,768);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective(35.0f, 1366/ 768.0f, 1, -1);
	//glLoadIdentity();
	//glViewport(0, 0, 1366, 768);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//gluOrtho2D(0, 1366, 0, 768); // Origin in lower-left corner
	//glOrtho(0, 1366, 768, 0, 1, -1); // Origin in upper-left corner
//
	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	
	Idle = new SpriteSequence("imagenes/Idle.png",6, 1, 100, true, -2, 2, 128, 128);
	

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
	//glOrtho(0, 1366, 0, 768, 1, -1); // Origin in lower-left corner
	//glOrtho(0, 1366, 768, 0, 1, -1); // Origin in upper-left corner
	gluLookAt(mundo.x_ojo, mundo.y_ojo, mundo.z_ojo,  // posicion del ojo
			0.0, 0.0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el código de dibujo
	glEnable(GL_LIGHTING);
	Idle->draw();
	
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	
	glutPostRedisplay();
}

void OnTimer(int value)
{
//poner aqui el código de animacion
	
	Idle->loop();
	
	
	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}

