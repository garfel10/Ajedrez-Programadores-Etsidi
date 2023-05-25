#include "casilla.h"

casillas casilla[8][8];

void casillas::casillero() {

	int n = 1;
	int i = 1;
	int j = 1;



	while (n < 65) {


		casilla[i][j].c = i;
		casilla[i][j].f = j;
		casilla[i][j].numero = n;

		if (i % 2 == j % 2) casilla[i][j].color = 'b';
		else casilla[i][j].color = 'w';


		casilla[i][j].centrox = 1 + i;
		casilla[i][j].centroy = 1 + j;
		



		n++;
		if (i < 8) i++;
		else {
			i = 1;
			j++;
		}

	}
	//se genera un vector que recorre el tablero por filas, de izquierda a derecha y de abajo a arriba.

}



void casillas::vaciar(int columna,int fila) {

	casilla[columna][fila].estado = 0;
	casilla[columna][fila].ficha = '0';

}

void casillas::ocupar(int columna, int fila, char pieza, char colorficha) {

	casilla [columna][fila].estado = 1;
	casilla[columna][fila].ficha = pieza;
	casilla[columna][fila].fcolor = colorficha;

}
