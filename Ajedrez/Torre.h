#pragma once
#include"Fichas.h"
class Torre :public Fichas
{
private:
public:
	Torre(int fila, int columna, bool color) :Fichas(Nombrefichas::TORRE, fila, columna, color) {}
	void dibujar();
};

