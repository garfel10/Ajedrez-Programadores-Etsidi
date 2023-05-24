#pragma once
#include"Fichas.h"
class Torre :public Fichas
{
private:
public:
	Torre(int fila, int columna, bool color) :Fichas(Nombrefichas::TORRE, fila, columna, color) {}
	void dibujar();
	bool restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual);
};

