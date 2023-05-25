#include "Peon.h"

void Peon::dibujar() {
	if (Color == 1) {
		imagen = new Sprite("bin/imagenes/Peon Blanco", posicion.centrox, posicion.centroy, 1, 1);
	}
	if (Color == 0) {
		imagen = new Sprite("bin/imagenes/Peon Negro", posicion.centrox, posicion.centroy, 1, 1);
	}
}

bool Peon::restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual) {
	if (nueva_fila - fila_actual <= 2 && nueva_columna == columna_actual)
		return 1;
	else
		return 0;
}