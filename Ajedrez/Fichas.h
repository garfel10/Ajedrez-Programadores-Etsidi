#pragma once
#include "Nombrefichas.h"
#include "lib/ETSIDI.h"
#include "casilla.h"
using ETSIDI::Sprite;

class Fichas
{
protected:
	Nombrefichas Tipo;
	int Fila, Columna;
	bool Color;
	Sprite* imagen;

public:
	Fichas(Nombrefichas tipo, int fila, int columna, bool color);
	void movimiento();
	void setPos(int fila2, int columna2);
	Nombrefichas getFicha();
	void setFicha(Nombrefichas ficha);
	int getFila();
	int getColumna();
	virtual bool restricciones(int, int, int, int){}
	void dibujar();
	friend class casillas;
};

