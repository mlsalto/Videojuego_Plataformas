#include "Mundo.h"
#include "freeglut.h"
#include "mundo.h"
#include "math.h"
#include "Interaccion.h"


Mundo::~Mundo()
{
	//HAY QUE METER DESCTRUCTORES DE OBJETOS MÓVILES
	//facultad = getTexture("Texturas/facultad.png");
}

Mundo::Mundo()
{
	//facultad = getTexture("Texturas/facultad.png");
	nivel = 1;
}

void Mundo::dibuja(bool selector)//selector==true pintas el juego selector==false pintas la camara del boss
{
	if (selector == true) {
		gluLookAt(universitario.posicion.x, universitario.posicion.y + 10, 110, // posicion del ojo
			universitario.posicion.x, universitario.posicion.y + 10, 0.0, // hacia que punto mira (0,0,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)*/


		universitario.dibujar();
		universitario.dibujarvidas();
		universitario.dibujarNumBonus();

		//boss.dibuja();

		apuntando.dibujarMapa();

		//fuego.dibuja();
		mesa.dibuja();
		//llama.dibuja();
		robot.dibuja();
		carnet.dibuja();
		cafe.dibuja();


		fondo.dibujarNivel(nivel);
	}
	else {
		//cargarJefe();


		gluLookAt(73,  0, 110, // posicion del ojo
			73 , 0, 0.0, // hacia que punto mira (0,0,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)*/


		universitario.dibujar();
		universitario.dibujarvidas();
		universitario.dibujarNumBonus();

		apuntando.dibujarMapa();
		boss.dibuja();
		cafe.dibuja();

		disparos1.dibujaDisparoPersonaje();
		disparos2.dibujaDisparoJefe();

		fondo.dibujarJefe(jefe);
		//ETSIDI::play("Texturas/Sonidos/batallaboss.mp3");
	}
	

}

void Mundo::mover()
{ 

	universitario.mover(0.025f);
	boss.mueve(0.025f);
	mesa.mueve(0.025f);
	robot.mueve(0.025f);
	carnet.mueve(0.025f);
	cafe.mueve(0.025f);
	disparos1.mueve(0.025f);
	disparos2.mueve(0.025f);

	//Interaccion::rebote(universitario, menu);
	//Interaccion::rebote(universitario, fuego);
	//Interaccion::rebote(universitario, llama);
	//Interaccion::rebote(universitario, boss);

	mesa.rebote(universitario); //interaccions lista objeto fijo
	robot.rebote(universitario);
	///Interaccion::rebote(universitario, boss);
	apuntando.reboteMapa(universitario);

	disparos1.colision1(boss);
	disparos2.colision2(universitario);

	if (apuntando.finalMapa(universitario, apuntando.detectarBandera())) {
		cout << "final nivel" << endl;
		finNivel = true;
	}
	else finNivel = false;
	//interacción con mapa
	//ponerle que si esto es true pase a estado fin mapa o algo así

	Tile* aux = carnet.colision(universitario);
	if (aux != 0)
	{
		carnet.eliminar(aux);
		ETSIDI::play("Texturas/Sonidos/bonus.mp3");
	}

	Tile* aux1 = cafe.colision(universitario);
	if (aux1 != 0)
	{
		cafe.eliminar(aux1);
		ETSIDI::play("Texturas/Sonidos/bonus.mp3");
	}
}

void Mundo::tecla(unsigned char key)
{
	Disparo* d = new Disparo();
	d->setPos(universitario.posicion.x + (universitario.ancho / 2), universitario.posicion.y + 2.5);
	d->setDisparoObjeto(tipodisparo);

	switch (key) {
	case ' ':
	{
		disparos1.agregar(d);
		break;
	}
	}
}

void Mundo::inicializa()
{
	//inicializa();
	//Mapa map;

	nivel = 0;
	jefe = 0;
	cargarNivel();	//AQUI ES DONDE HARÁ CARGAR MAPA
					//una vez cargada la matriz hay que incluir los objetos en sus listas correspondientes
	agregarListas();
	robot.setMax_Min();
}


void Mundo::teclaEspecial(unsigned char key)
{
	universitario.teclaEspecialAbajo(key);
}

void Mundo::teclaEspecialBoss(unsigned char key)
{
	Disparo* e = new Disparo();
	if (jefe == 1 || jefe == 3) e->setPos(boss.posicion.x, universitario.posicion.y);
    if (jefe == 2 || jefe == 4 ) e->setPos(universitario.posicion.x, universitario.posicion.y + 50);

	e->setDisparoJefe(jefe);

	switch (key) {
	case GLUT_KEY_LEFT:
	{
		disparos2.agregar(e);
		break;
	}

	case GLUT_KEY_RIGHT:
	{
		disparos2.agregar(e);
		break;
	}

	case GLUT_KEY_UP:
	{
		disparos2.agregar(e);
		break;
	}

	case GLUT_KEY_DOWN:
	{
		disparos2.agregar(e);
		break;
	}
	}
}

bool Mundo::cargarNivel()
{
	nivel++;
	universitario.setPos(3, -22);
	universitario.setVida(5);
	mesa.destruirContenido();
	apuntando.celdas.destruirContenido();
	robot.destruirContenido();
	carnet.destruirContenido();
	cafe.destruirContenido();
	disparos1.destruirContenido();
	disparos2.destruirContenido();
	//añadir los destructores que faltan
	universitario.setJefeFalse();
	universitario.setBonus(0);

	if (nivel == 1)
	{
		apuntando.cargarMapa(1);
		return true;
	}
	if (nivel == 2)
	{
		apuntando.cargarMapa(2);
		agregarListas();
		robot.setMax_Min();
		return true;
	}
	if (nivel == 3)
	{
		apuntando.cargarMapa(3);
		agregarListas();
		robot.setMax_Min();
		return true;
	}
	if (nivel == 4)
	{
		apuntando.cargarMapa(4);
		agregarListas();
		robot.setMax_Min();
		return true;
	}
	if (nivel <= 4)
		return true;
	return false;
}

bool Mundo::cargarJefe()
{
	jefe++;
	universitario.setPos(3, -22);
	boss.setVida(5);
	universitario.setVida(5);
	mesa.destruirContenido();
	apuntando.celdas.destruirContenido();
	robot.destruirContenido();
	carnet.destruirContenido();
	cafe.destruirContenido();
	disparos1.destruirContenido();
	disparos2.destruirContenido();
	universitario.setJefeTrue();
	universitario.setBonus(0);

	if (jefe == 1)
	{
		apuntando.cargarMapa(5);
		boss.setJefe(1);
		agregarListas();
		return true;
	}
	if (jefe == 2)
	{
		apuntando.cargarMapa(5); 
		boss.setJefe(2);
		agregarListas();
		return true;
	}
	if (jefe == 3)
	{
		apuntando.cargarMapa(5);
		boss.setJefe(3);
		agregarListas();
		return true;
	}
	if (jefe == 4)
	{
		apuntando.cargarMapa(5);
		boss.setJefe(4);
		agregarListas();
		return true;
	}
	if (jefe <= 4)
		return true;
	return false;
}
void Mundo::agregarListas() //IMPORTANTE CAMBIAR LOS NÚMEROS PARA QUE COINCIDAN CON LO DE LA MATRIZ TILE
{
	//una vez que ya se ha cargado matriz tile
	for (int i = 0; i < MAX_TILES; i++)
	{
		if ((apuntando.celdas.mimatriz[i])->getTipo() == 5) {		//agregar a lista bonus
			//ejecutar funcion que devuelva un puntero de tipo tile new
			//carnet.agregar((apuntando.celdas.mimatriz[i]));
			(carnet.lista).push_back((apuntando.celdas).mimatriz[i]);
		}
		if ((apuntando.celdas.mimatriz[i])->getTipo() == 6) {		//agregar a lista obstaculo fijo
			//mesa.agregar((apuntando.celdas[i]));
			(mesa.lista).push_back((apuntando.celdas).mimatriz[i]);
		}
		if ((apuntando.celdas.mimatriz[i])->getTipo() == 7) {		//agregar a lista obstaculo movil
			//robot.agregar((apuntando.celdas[i]));
			(robot.lista).push_back((apuntando.celdas).mimatriz[i]);
		}
		if ((apuntando.celdas.mimatriz[i])->getTipo() == 8) {		//agregar a lista vida
			//cafe.agregar((apuntando.celdas[i]));
			(cafe.lista).push_back((apuntando.celdas).mimatriz[i]);
		}
		if ((apuntando.celdas.mimatriz[i])->getTipo() == 9) {		//agregar a lista boss
			//boss.agregar((apuntando.celdas[i]));
			//(boss.lista).push_back((apuntando.celdas).mimatriz[i]);
		}
	}
}

int Mundo::getVidasPersonaje()
{
	return universitario.getVida();
}

int Mundo::getVidasJefe()
{
	return boss.getVida();
}

int Mundo::getNivel()
{
	return nivel;
}

int Mundo::getJefe()
{
	return jefe;
}

int Mundo::getTipoDisparo()
{
	return tipodisparo;
}

bool Mundo::getFinNivel()
{
	return finNivel;
}

void Mundo::setTipoDisparo(int x)
{
	tipodisparo = x;
}
