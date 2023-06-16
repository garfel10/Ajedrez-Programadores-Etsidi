#include "MenuInicio.h"
#include "free
#include <iostream>

using namespace std;

MenuInicio::MenuInicio(){
	estado = START;
	tiempo = 0.000f;
}

MenuInicio::~MenuInicio()
{
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

void MenuInicio::dibuja(){
	if (estado == START)
	{
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(255, 255, 255);
		ETSIDI::setFont("fuente/Bitwise.ttf", 32);
		ETSIDI::printxy("AJEDREZ", -4, 11);
		ETSIDI::setTextColor(255, 255, 255);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("SI QUIERE EMPEZAR A JUGAR PULSE LA TECLA E", -6, 7);
		ETSIDI::printxy("SI QUIERE EMPEZAR A JUGAR PULSE LA TECLA S", -6, 6);
		ETSIDI::printxy("PROGRAMADORES ETSIDI", 2, 3);

	}

	//else if (estado == PLAY)
		//mundo1.dibuja();
}
