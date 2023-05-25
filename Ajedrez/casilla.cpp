#include "casilla.h"

casillas casilla[9][9];

void casillas::casillero() {

	int n = 1;
	int i = 1;
	int j = 1;



	while (n < 65) {


		casilla[i][j].f = i;
		casilla[i][j].c = j;
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
	//se fora una matriz [filas(8)][columnas(8)] que recorre cada fila de izquierda a derecha (1-8) y  cuando acaba con la fila pasa a la fila superior.

}





void casillas::vaciar(int fila, int columna) {

	casilla[fila][columna].estado = 0;
	casilla[fila][columna].ficha = '0';

}

void casillas::ocupar(int fila, int columna, char pieza, char colorficha) {

	casilla[fila][columna].estado = 1;
	casilla[fila][columna].ficha = pieza;
	casilla[fila][columna].fcolor = colorficha;

}
