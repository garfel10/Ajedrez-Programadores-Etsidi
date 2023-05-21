#pragma once
#include"Fichas.h"
class Peon :public Fichas
{
private:
public:
	Peon(int fila, int columna, bool color) :Fichas(Nombrefichas::PEON, fila, columna, color){}
	void dibujar();
};

