#pragma once
#include "casilla.h"
#include "Fichas.h"

class Caballo: public Fichas
{
private:
public:
	Caballo();
	void dibujar(int fila, int columna);
	bool restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual);
};

