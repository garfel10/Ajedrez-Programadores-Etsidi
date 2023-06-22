#include "Peon.h"

Peon::Peon(){}

void Peon::dibujar(int fila, int columna) {
	if (casilla[fila][columna].fcolor == 'w') {
		imagen = new Sprite("bin/imagenes/Peon Blanco", casilla[fila][columna].centrox, casilla[fila][columna].centroy, 1, 1);
	}
	if (casilla[fila][columna].fcolor == 'b') {
		imagen = new Sprite("bin/imagenes/Peon Negro", casilla[fila][columna].centrox, casilla[fila][columna].centroy, 1, 1);
	}
}

bool Peon::restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual) {
	if (nueva_fila - fila_actual <= 2 && nueva_columna == columna_actual)
		return 1;
	else
		return 0;
}