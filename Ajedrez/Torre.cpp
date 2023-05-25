#include "Torre.h"

void Torre::dibujar() {
	if (casilla.fcolor == 'w') {
		imagen = new Sprite("bin/imagenes/Torre Blanco", casilla.centrox, casilla.centroy, 1, 1);
	}
	if (casilla.fcolor == 'b') {
		imagen = new Sprite("bin/imagenes/Torre Negro", casilla.centrox, casilla.centroy, 1, 1);
	}
}

bool Torre::restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual) {
	if ((nueva_columna == columna_actual) || (nueva_fila == fila_actual))
		return 1;
	else return 0;
}