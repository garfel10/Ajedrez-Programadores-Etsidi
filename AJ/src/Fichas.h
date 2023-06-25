#pragma once
#include "Nombrefichas.h"
#include "ETSIDI.h"
#include "casilla.h"
using ETSIDI::Sprite;

class Fichas
{
protected:
	Nombrefichas Tipo;
	int Fila, Columna;
	char Color;
	Sprite* imagen;

public:
	Fichas(Nombrefichas tipo, int fila, int columna, char color);
	Fichas();
	//void movimiento();
	void setPos(int fila2, int columna2);
	Nombrefichas getFicha();
	void setFicha(Nombrefichas ficha);
	void setColor(char);
	int getFila();
	int getColumna();
	virtual bool restricciones(int, int, int, int){}
	void dibujar();
	void borrarcontenido();
	friend class casillas;
};

