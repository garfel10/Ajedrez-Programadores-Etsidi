#include "Reina.h"

void Reina::dibujar() {
	if (casilla.fcolor == 'w') {
		imagen = new Sprite("bin/imagenes/Reina Blanco", casilla.centrox, casilla.centroy, 1, 1);
	}
	if (casilla.fcolor == 'b') {
		imagen = new Sprite("bin/imagenes/Reina Negro", casilla.centrox, casilla.centroy, 1, 1);
	}
}

bool Reina::restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual) {
	if ((nueva_columna - columna_actual) == (nueva_fila - fila_actual) || ((nueva_columna == columna_actual) || (nueva_fila == fila_actual)))
		return 1;
	else return 0;
}