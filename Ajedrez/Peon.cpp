#include "Peon.h"

void Peon::dibujar() {
	if (Color == 1) {
		ETSIDI::getTexture("bin/imagenes/Peon Blanco");
	}
	if (Color == 0) {
		ETSIDI::getTexture("bin/imagenes/Peon Negro");
	}
}

bool Peon::restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual) {
	if (nueva_fila - fila_actual <= 2 && nueva_columna == columna_actual)
		return 1;
	else
		return 0;
}