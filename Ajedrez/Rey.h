#pragma once
#include "Fichas.h"
class Rey : public Fichas
{
private:
public:
	Rey(int fila, int columna, bool color) :Fichas(Nombrefichas::REY, fila, columna, color) {}
	void dibujar();
};

