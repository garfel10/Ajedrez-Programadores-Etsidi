#include "Rey.h"

void Rey::dibujar() {
	if (Color == 1) {
		ETSIDI::getTexture("bin/imagenes/Rey Blanco");
	}
	if (Color == 0) {
		ETSIDI::getTexture("bin/imagenes/Rey Negro");
	}
}

bool Rey::restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual) {
	if (((nueva_columna - columna_actual) == 1 || (nueva_fila - fila_actual) == 1) && ((nueva_columna - columna_actual) == (nueva_fila - fila_actual) || ((nueva_columna == columna_actual) || (nueva_fila == fila_actual))))
		return 1;
	else return 0;
}