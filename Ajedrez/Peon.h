#pragma once
#include"Fichas.h"
class Peon :public Fichas
{
private:
public:
	Peon();
	void dibujar();
	bool restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual);
};

