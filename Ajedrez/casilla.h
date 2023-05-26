#pragma once
#include "Fichas.h"
#include "Nombrefichas.h"
#include "lib/ETSIDI.h"
using ETSIDI::Sprite;

class casillas
{
public:

	bool amenazablanca;
	bool amenazanegra;
	bool clavada;
	int c; //COLUMNA (1-8)
	int f; //FILA (1-8)
	unsigned char color;//b black, w white
	void casillero(); //Para generar el tablero lógico. Vector casillas de 1 a 64. cada una con su color.
	int estado = 0; // 1 ocupada, 0 libre. Lo inicializamos a 0 y cuando se inicialicen las fichas ya se ponen a 1 las que se tienen que poner.
	//las casillas ocupadas seran de la 1 a la 16 y de la 48 a la 
	unsigned char fcolor;//b black , w white. el color de la ficha se lo pasa la propia ficha. 
	int bando;//como fcolor, pero mas facil de manejar en las funciones de la logica del juego, 1 es blanco, 0 es negro, 2 es vacio
	//char ficha;//alfil:'A', torre 'T', caballo 'C', peon 'P', rey'K', reina 'Q', nulo '0'
	//Fichas ficha;//nueva para logica
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
		int getFila();
		int getColumna();
		//virtual bool restricciones(int, int, int, int) {}
		void dibujar();
		void borrarcontenido();
		friend class casillas;
	};
	Fichas ficha;
	int numero;//la n


	//el punto sobre el que se debe centrar la ficha
	int centrox;
	int centroy;
	
	
	//las funciones que utilizaran las fichas cuando "lleguen" o se "vayan"
	void vaciar(int fila, int columna);
	void ocupar(int fila, int columna, Nombrefichas pieza, char colorficha);

};
casillas casilla[9][9];
