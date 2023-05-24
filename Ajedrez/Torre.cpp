#include "Torre.h"

void Torre::dibujar() {
	if (Color == 1) {
		ETSIDI::getTexture("bin/imagenes/Torre Blanco");
	}
	if (Color == 0) {
		ETSIDI::getTexture("bin/imagenes/Torre Negro");
	}
}

bool Torre::restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual) {
	if ((nueva_columna == columna_actual) || (nueva_fila == fila_actual))
		return 1;
	else return 0;
}