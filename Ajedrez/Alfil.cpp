#include "Alfil.h"

void Alfil::dibujar() {
	if (casilla.fcolor == 'w') {
		imagen = new Sprite("bin/imagenes/Alfil Blanco", casilla.centrox, casilla.centroy, 1, 1);
	}
	if (casilla.fcolor == 'b') {
		imagen = new Sprite("bin/imagenes/Alfil Negro", casilla.centrox, casilla.centroy, 1, 1);
	}
}

bool Alfil::restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual) {
	if ((nueva_columna - columna_actual) == (nueva_fila - fila_actual))
		return 1;
	else return 0;
}