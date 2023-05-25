#pragma once
#include "Fichas.h"
class Rey : public Fichas
{
private:
public:
	Rey(int fila, int columna, bool color) :Fichas(Nombrefichas::REY, fila, columna, color) {}
	void dibujar();
	bool restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual);
};

