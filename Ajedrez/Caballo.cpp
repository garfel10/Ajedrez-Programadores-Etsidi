#include "Caballo.h"

void Caballo::dibujar() {
	if (Color == 1) {
		imagen = new Sprite("bin/imagenes/Caballo Blanco", posicion.centrox, posicion.centroy, 1, 1);
	}
	if (Color == 0) {
		imagen = new Sprite("bin/imagenes/Caballo Negro", posicion.centrox, posicion.centroy, 1, 1);
	}
}

bool Caballo::restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual) {
	if ((((nueva_columna - columna_actual) == 1) || ((nueva_columna - columna_actual) == -1)) && (((nueva_fila - fila_actual) == 2) || (nueva_fila - fila_actual) == -2))
		return 1;
	if ((((nueva_fila - fila_actual) == 1) || ((nueva_fila - fila_actual) == -1)) && (((nueva_columna - columna_actual) == 2) || (nueva_columna - columna_actual) == -2))
		return 1;
	else return 0;
}