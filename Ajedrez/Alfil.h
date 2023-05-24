#pragma once
#include "Fichas.h"
class Alfil:public Fichas
{
private:
public:
	Alfil(int fila, int columna, bool color) :Fichas(Nombrefichas::ALFIL, fila, columna, color) {}
	void dibujar();
	bool restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual);
};

