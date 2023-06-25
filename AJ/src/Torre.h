#pragma once
#include"casilla.h"
class Torre :public Fichas
{
private:
public:
	Torre();
	void dibujar(int fila, int columna);
	bool restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual);
};

