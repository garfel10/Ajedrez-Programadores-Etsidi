#pragma once
#include "casilla.h"
class Reina : public casillas::Fichas
{
private:
public:
	Reina();
	void dibujar();
	bool restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual);
};

