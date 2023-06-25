#include "Torre.h"

Torre::Torre(){}

void Torre::dibujar(int fila, int columna) {
	if (Tablero::casilla[fila][columna].fcolor == 'w') {
		imagen = new Sprite("bin/imagenes/Torre Blanco", Tablero::casilla[fila][columna].centrox, Tablero::casilla[fila][columna].centroy, 1, 1);
	}
	if (Tablero::casilla[fila][columna].fcolor == 'b') {
		imagen = new Sprite("bin/imagenes/Torre Negro", Tablero::casilla[fila][columna].centrox, Tablero::casilla[fila][columna].centroy, 1, 1);
	}
}

bool Torre::restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual) {
	if ((nueva_columna == columna_actual) || (nueva_fila == fila_actual))
		return 1;
	else return 0;
}