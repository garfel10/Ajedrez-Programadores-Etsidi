#pragma once
#include "Fichas.h"
class Caballo: public Fichas
{
private:
public:
	Caballo(int fila, int columna, bool color) :Fichas(Nombrefichas::CABALLO, fila, columna, color) {}
	void dibujar();
};

