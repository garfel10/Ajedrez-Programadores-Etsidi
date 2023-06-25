#include "Rey.h"

Rey::Rey(){}

void Rey::dibujar(int fila, int columna) {
	if (Tablero::casilla[fila][columna].fcolor == 'w') {
		imagen = new Sprite("bin/imagenes/Rey Blanco", Tablero::casilla[fila][columna].centrox, Tablero::casilla[fila][columna].centroy, 1, 1);
	}
	if (Tablero::casilla[fila][columna].fcolor == 'b') {
		imagen = new Sprite("bin/imagenes/Rey Negro", Tablero::casilla[fila][columna].centrox, Tablero::casilla[fila][columna].centroy, 1, 1);
	}
}

bool Rey::restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual) {
	if (((nueva_columna - columna_actual) == 1 || (nueva_fila - fila_actual) == 1) && ((nueva_columna - columna_actual) == (nueva_fila - fila_actual) || ((nueva_columna == columna_actual) || (nueva_fila == fila_actual))))
		return 1;
	else return 0;
}