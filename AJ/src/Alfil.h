#pragma once
#include "casilla.h"
class Alfil:public Fichas
{
private:
public:
	Alfil();
	void dibujar(int fila, int columna);
	bool restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual);
};

