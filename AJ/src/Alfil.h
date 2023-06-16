#pragma once
#include "casilla.h"
class Alfil:public casillas::Fichas
{
private:
public:
	Alfil();
	void dibujar();
	bool restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual);
};

