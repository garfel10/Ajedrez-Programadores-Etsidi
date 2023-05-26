#pragma once
#include"casilla.h"
class Torre :public casillas::Fichas
{
private:
public:
	Torre();
	void dibujar();
	bool restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual);
};

