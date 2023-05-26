#pragma once
#include "Fichas.h"
class Reina : public Fichas
{
private:
public:
	Reina();
	void dibujar();
	bool restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual);
};

