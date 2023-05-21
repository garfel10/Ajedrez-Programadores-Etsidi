#pragma once
#include "Fichas.h"
class Alfil:public Fichas
{
private:
public:
	Alfil(int fila, int columna, bool color) :Fichas(Nombrefichas::PEON, fila, columna, color) {}
	void dibujar();
};

