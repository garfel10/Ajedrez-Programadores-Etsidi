#pragma once
#include "Fichas.h"
class Reina : public Fichas
{
private:
public:
	Reina(int fila, int columna, bool color) :Fichas(Nombrefichas::REINA, fila, columna, color) {}
	void dibujar();
	bool restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual);
};

