#pragma once
#include "casilla.h"
class Caballo: public casillas::Fichas
{
private:
public:
	Caballo();
	void dibujar();
	bool restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual);
};

