#pragma once
#include"Fichas.h"
class Peon :public Fichas
{
private:
public:
	Peon(int fila, int columna, bool color) :Fichas(Nombrefichas::PEON, fila, columna, color){}
	void dibujar();
	bool restricciones(int nueva_fila, int nueva_columna, int fila_actual, int columna_actual);
};

