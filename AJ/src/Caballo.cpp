#include "Caballo.h"

Caballo::Caballo(){}

void Caballo::dibujar(int fila, int columna) {
	if (casilla[fila][columna].fcolor == 'w') {
		imagen = new Sprite("bin/imagenes/Caballo Blanco", casilla[fila][columna].centrox, casilla[fila][columna].centroy, 1, 1);
	}
	if (casilla[fila][columna].fcolor == 'b') {
		imagen = new Sprite("bin/imagenes/Caballo Negro", casilla[fila][columna].centrox, casilla[fila][columna].centroy, 1, 1);
	}
}

bool Caballo::restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual) {
	if ((((nueva_columna - columna_actual) == 1) || ((nueva_columna - columna_actual) == -1)) && (((nueva_fila - fila_actual) == 2) || (nueva_fila - fila_actual) == -2))
		return 1;
	if ((((nueva_fila - fila_actual) == 1) || ((nueva_fila - fila_actual) == -1)) && (((nueva_columna - columna_actual) == 2) || (nueva_columna - columna_actual) == -2))
		return 1;
	else return 0;
}