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
	
	info->setSize(35.0, 35.0);
	info->setPos(0.0, 6.0);	

	ins->setSize(35.0, 35.0);
	ins->setPos(0.0, 7.0);

	menu->setSize(35.0, 35.0);
	menu->setPos(0.0, 6.0);	
}

MenuInicio::~MenuInicio() {
}

void MenuInicio::tecla(unsigned char key) {
	switch (estado) {
	case START:
		if (key == 32) {
			tiempo = 0;
			estado = MENUINICIO;
		}
		break;
	case MENUINICIO:
		switch (key) {
		case  (key == 'i' || key == 'I'):
			tiempo = 0;
			estado = INFO;
			break;
		case 13:
			tiempo = 0;
			estado = MENU;
			break;
		}
		break;
	case INFO:
		if (key == 'b' || key == 'B') {
			tiempo = 0;
			estado = MENUINICIO;//VOLVER AL MENU
		}
		if (key == 'm' || key == 'M') {
			tiempo = 0;
			//estado = ;
		}
		break;
	case MENU: 
		if (key == 's' || key == 'S')
		{
			tiempo = 0;
			estado = PLAY;
		}
		if (key == 'e' || key == 'E')
			exit(0);
		break;
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
	else if (estado == MENUINICIO) {
		gluLookAt(0, 6.5, 30,
			0.0, 6.5, 0.0,
			0.0, 1.0, 0.0);

		info->draw();
	}
	else if (estado == INFO) {
		gluLookAt(0, 6.5, 30,
			0.0, 6.5, 0.0,
			0.0, 1.0, 0.0);

		ins->draw();
	}
	else if (estado == MENU) {
		gluLookAt(0, 6.5, 30,
			0.0, 6.5, 0.0,
			0.0, 1.0, 0.0);

		menu->draw();
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
