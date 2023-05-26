#include "Fichas.h"
#include "lib/ETSIDI.h"
#include "casilla.cpp"
#include"Peon.h"
#include"Torre.h"
#include"Caballo.h"
#include"Alfil.h"
#include"Rey.h"
#include"Reina.h"
#include <iostream>
using namespace std;

Fichas::Fichas(Nombrefichas tipo, int fila, int columna, char color) {
	tipo = Tipo;
	fila = Fila;
	columna = Columna;
	color = Color;
}

Fichas::Fichas(){}
/*
void Fichas::movimiento() {

	Peon peon;
	Torre torre;
	Caballo caballo;
	Alfil alfil;
	Rey rey;
	Reina reina;

	int filaini=0, columnaini=0;
	
	 do{
		cout << "Introduzca la fila y columna de la ficha que quiere mover: ";
		cin >> filaini >> columnaini;
		if (filaini > 8 || columnaini > 8 || filaini < 0 || columnaini < 0)
			cout << "Coordenadas fuera de rango";
		else {
			for (int i = 1; i < 10; i++) {
				for (int j = 1; j < 10; j++) {
					if (casilla[i][j].f == filaini && casilla[i][j].c == columnaini && casilla[i][j].estado == 0) {
						"No hay ninguna ficha en dichas coordenadas";
					}
					if (casilla[i][j].f == filaini && casilla[i][j].c == columnaini && casilla[i][j].estado == 1)
						break;
				}
			}
		}
		
	 } while (filaini > 8 || columnaini > 8 || filaini < 0 || columnaini < 0 || casilla[filaini][columnaini].estado == 0); 
	 //Así nos aseguramos que las coordenadas introducidas son correctas, están dentro del tablero y hay una ficha en dicha casilla

	

	int filafin=0, columnafin=0, r=0;

	 do{
		cout << "Introduzca la fila y columna a donde quiere mover la ficha: ";
		cin >> filafin >> columnafin;
	 } while (filafin > 8 || columnafin > 8 || filafin < 0 || columnafin < 0);//Así nos aseguramos que las coordenadas introducidas son correctas y están dentro del tablero

	 if (casilla[filaini][columnaini].ficha.getFicha() == Nombrefichas::ALFIL)
		 r = 1;
	 if (casilla[filaini][columnaini].ficha.getFicha() == Nombrefichas::TORRE)
		 r = 2;
	 if (casilla[filaini][columnaini].ficha.getFicha() == Nombrefichas::CABALLO)
		 r = 3;
	 if (casilla[filaini][columnaini].ficha.getFicha() == Nombrefichas::PEON)
		 r = 4;
	 if (casilla[filaini][columnaini].ficha.getFicha() == Nombrefichas::REY)
		 r = 5;
	 if (casilla[filaini][columnaini].ficha.getFicha() == Nombrefichas::REINA)
		 r = 6;

	switch (r) {
	case 1:
		if (alfil.restricciones(filafin, columnafin, filaini, columnaini)) {
			casilla[filafin][columnafin].ocupar(filafin, columnafin, Nombrefichas::ALFIL, casilla[filaini][columnaini].fcolor);
			//alfil.setPos(filafin, columnafin);
			casilla[filaini][columnaini].vaciar(filaini, columnaini);
		}	
		else
			cout << "Movimiento no permitido";
		break;
	case 2:
		if (torre.restricciones(filafin, columnafin, filaini, columnaini)){
			casilla[filafin][columnafin].ocupar(filafin, columnafin, Nombrefichas::TORRE, casilla[filaini][columnaini].fcolor);
			//torre.setPos(filafin, columnafin);
			casilla[filaini][columnaini].vaciar(filaini, columnaini);
		}
		else
			cout << "Movimiento no permitido";
		break;
	case 3:
		if (caballo.restricciones(filafin, columnafin, filaini, columnaini)) {
			casilla[filafin][columnafin].ocupar(filafin, columnafin, Nombrefichas::CABALLO, casilla[filaini][columnaini].fcolor);
			//caballo.setPos(filafin, columnafin);
			casilla[filaini][columnaini].vaciar(filaini, columnaini);
		}
		else
			cout << "Movimiento no permitido";
		break;
	case 4:
		if (peon.restricciones(filafin, columnafin, filaini, columnaini)) {
			casilla[filafin][columnafin].ocupar(filafin, columnafin, Nombrefichas::PEON, casilla[filaini][columnaini].fcolor);
			//peon.setPos(filafin, columnafin);
			casilla[filaini][columnaini].vaciar(filaini, columnaini);
		}
		else
			cout << "Movimiento no permitido";
		break;
	case 5:
		if (rey.restricciones(filafin, columnafin, filaini, columnaini)) {
			casilla[filafin][columnafin].ocupar(filafin, columnafin, Nombrefichas::REY, casilla[filaini][columnaini].fcolor);
			//rey.setPos(filafin, columnafin);
			casilla[filaini][columnaini].vaciar(filaini, columnaini);
		}
		else
			cout << "Movimiento no permitido";
		break;
	case 6:
		if (reina.restricciones(filafin, columnafin, filaini, columnaini)) {
			casilla[filafin][columnafin].ocupar(filafin, columnafin, Nombrefichas::REINA, casilla[filaini][columnaini].fcolor);
			//reina.setPos(filafin, columnafin);
			casilla[filaini][columnaini].vaciar(filaini, columnaini);
		}
		else
			cout << "Movimiento no permitido";
		break;
	}


	
}
*/
int Fichas::getFila() {
	return Fila;
}

int Fichas::getColumna() {
	return Columna;
}
Nombrefichas Fichas::getFicha() {
	return Tipo;
}
void Fichas::setFicha(Nombrefichas ficha)
{
	Tipo = ficha;
}

void Fichas::setPos(int fila, int columna) {
	fila = Fila;
	columna = Columna;
}

void Fichas::dibujar() {
	
}

void Fichas::borrarcontenido() {
	setPos(30,30);
	Color = '\0';
}