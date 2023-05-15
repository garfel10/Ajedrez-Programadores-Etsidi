#include "freeglut.h"
#include "Tablero.h"
#include "MenuInicio.h"
#include <iostream>

Tablero tablero;

MenuInicio::MenuInicio() {
	estado = START;
	tiempo = 0.000f;
	audio = true;

	menuini->setSize(35.0, 35.0);
	menuini->setPos(0.0, 8.0);
	
}

MenuInicio::~MenuInicio() {
}

void MenuInicio::tecla(unsigned char key) {
	if (estado == START)
	{
		if (key == 's' || key == 'S')
		{
			tiempo = 0;
			estado = PLAY;
		}
		if (key == 'e' || key == 'E')
			exit(0);
	}
}

void MenuInicio::dibuja() {
	if (estado == START){

		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		menuini->draw();

		ETSIDI::playMusica("musica/musicamenu.mp3", true);
	}
	
	else if (estado == PLAY) {

		gluLookAt(5.5, 5.5, 12,
			5.5, 5.5, 0,
			0.0, 1.0, 0.0);

		tablero.dibuja();
	}
}

/*void MenuInicio::mueve() {
	if (estado == START || estado == PLAY) {
		ETSIDI::playMusica("musica/musicamenu.mp3", true);

		menuini->draw();
		tablero.dibuja();
	}
}*/
