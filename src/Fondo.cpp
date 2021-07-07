#include "Fondo.h"


void Fondo::dibujarNivel(int nivel)
{
	switch (nivel) {
	case 1:
		nivel1();
		break;
	case 2:
		nivel2();
		break;
	case 3:
		nivel3();
		break;
	case 4:
		nivel4();
		break;
	}
}

void Fondo::dibujarJefe(int jefe)
{
	switch (jefe) {
	case 1:
		jefe1();
		break;
	case 2:
		jefe2();
		break;
	case 3:
		jefe3();
		break;
	case 4:
		jefe4();
		break;
	}
}


void Fondo::nivel1()
{
	pared1.setPos(20, -17);
	pared1.setSize(70, 40);
	pared1.draw();

	puerta1.setPos(90, -17);
	puerta1.setSize(70, 40);
	puerta1.draw();

	pared1.setPos(160, -17);
	pared1.setSize(70, 40);
	pared1.draw();

}

void Fondo::nivel2()
{
	pared2.setPos(20, -17);//añadir a la x 70
	pared2.setSize(70, 40);
	pared2.draw();

	puerta2.setPos(90, -17);
	puerta2.setSize(70, 40);
	puerta2.draw();

	pared2.setPos(160, -17);
	pared2.setSize(70, 40);
	pared2.draw();

}

void Fondo::nivel3()
{
	pared3.setPos(20, -17);
	pared3.setSize(70, 40);
	pared3.draw();

	puerta3.setPos(90, -17);
	puerta3.setSize(70, 40);
	puerta3.draw();

	puerta3.setPos(160, -17);
	puerta3.setSize(70, 40);
	puerta3.draw();
}

void Fondo::nivel4()
{
	pared4.setPos(20, -17);
	pared4.setSize(70, 40);
	pared4.draw();

	puerta4.setPos(90, -17);
	puerta4.setSize(70, 40);
	puerta4.draw();

	puerta4.setPos(160, -17);
	puerta4.setSize(70, 40);
	puerta4.draw();

}

void Fondo::jefe1()
{

}

void Fondo::jefe2()
{

}

void Fondo::jefe3()
{

}

void Fondo::jefe4()
{

}