#include "Torre.h"

void Torre::dibujar() {
	if (Color == 1) {
		imagen = new Sprite("bin/imagenes/Torre Blanco", posicion.centrox, posicion.centroy, 1, 1);
	}
	if (Color == 0) {
		imagen = new Sprite("bin/imagenes/Torre Negro", posicion.centrox, posicion.centroy, 1, 1);
	}
}

bool Torre::restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual) {
	if ((nueva_columna == columna_actual) || (nueva_fila == fila_actual))
		return 1;
	else return 0;
}