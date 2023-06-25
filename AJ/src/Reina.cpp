#include "Reina.h"
#include "Reina.h"

Reina::Reina(){}

void Reina::dibujar(int fila, int columna) {
	if (Tablero::casilla[fila][columna].fcolor == 'w') {
		imagen = new Sprite("bin/imagenes/Reina Blanco", Tablero::casilla[fila][columna].centrox, Tablero::casilla[fila][columna].centroy, 1, 1);
	}
	if (Tablero::casilla[fila][columna].fcolor == 'b') {
		imagen = new Sprite("bin/imagenes/Reina Negro", Tablero::casilla[fila][columna].centrox, Tablero::casilla[fila][columna].centroy, 1, 1);
	}
}

bool Reina::restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual) {
	if ((nueva_columna - columna_actual) == (nueva_fila - fila_actual) || ((nueva_columna == columna_actual) || (nueva_fila == fila_actual)))
		return 1;
	else return 0;
}