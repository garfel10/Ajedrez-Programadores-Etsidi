#include "Reina.h"

void Reina::dibujar() {
	if (Color == 1) {
		ETSIDI::getTexture("bin/imagenes/Reina Blanco");
	}
	if (Color == 0) {
		ETSIDI::getTexture("bin/imagenes/Reina Negro");
	}
}

bool Reina::restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual) {
	if ((nueva_columna - columna_actual) == (nueva_fila - fila_actual) || ((nueva_columna == columna_actual) || (nueva_fila == fila_actual)))
		return 1;
	else return 0;
}