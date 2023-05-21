#pragma once
#include "Fichas.h"
class Alfil:public Fichas
{
private:
public:
	Alfil(int fila, int columna, bool color) :Fichas(Nombrefichas::ALFIL, fila, columna, color) {}
	void dibujar();
};

