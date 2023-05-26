#include "casilla.h"





void casillas::vaciar(int fila, int columna) {

	casilla[fila][columna].estado = 0;
	ficha.setFicha(Nombrefichas::VACIO);
	ficha.borrarcontenido();

}

void casillas::ocupar(int fila, int columna, Nombrefichas pieza, char colorficha) {

	casilla[fila][columna].estado = 1;
	casilla[fila][columna].fcolor = colorficha;
	ficha.setFicha(pieza);
	ficha.setPos(fila, columna);
	ficha.Color = colorficha;

}