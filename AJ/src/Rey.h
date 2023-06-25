#pragma once
#include "casilla.h"
class Rey : public Fichas
{
private:
public:
	Rey();
	void dibujar(int fila, int columna);
	bool restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual);
};

