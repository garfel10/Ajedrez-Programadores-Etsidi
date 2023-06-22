#pragma once
#include"casilla.h"
class Peon :public casillas::Fichas
{
private:
public:
	Peon();
	void dibujar(int fila, int columna);
	bool restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual);
};

