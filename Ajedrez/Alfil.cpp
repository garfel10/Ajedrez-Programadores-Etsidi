#include "Alfil.h"

void Alfil::dibujar() {
	if (Color == 1) {
		ETSIDI::getTexture("bin/imagenes/Alfil Blanco");
	}
	if (Color == 0) {
		ETSIDI::getTexture("bin/imagenes/Alfil Negro");
	}
}

bool Alfil::restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual) {
	if ((nueva_columna - columna_actual) == (nueva_fila - fila_actual))
		return 1;
	else return 0;
}