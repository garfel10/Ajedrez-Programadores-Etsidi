#pragma once
#include "Nombrefichas.h"
class Fichas
{
private:
	Nombrefichas Tipo;
	int Fila, Columna;
	bool Color;
public:
	Fichas(Nombrefichas tipo, int fila, int columna, bool color);
	void movimiento(int, int);
	void setPos(int fila1, int columna1, int fila2, int columna2);
	Nombrefichas getFicha();
	int getFila();
	int getColumna();
	bool restricciones(int, int, int, int, Nombrefichas);
};

