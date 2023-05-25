#include "Fichas.h"
#include "lib/ETSIDI.h"
#include "casilla.cpp"
/*#include"Peon.h"
#include"Torre.h"
#include"Caballo.h"
#include"Alfil.h"
#include"Rey.h"
#include"Reina.h"*/
#include <iostream>
using namespace std;
Alfil alfil;

Fichas::Fichas(Nombrefichas tipo, int fila, int columna, bool color) {
	tipo = Tipo;
	fila = Fila;
	columna = Columna;
	color = Color; //1 para blanco 0 para negro
}

void Fichas::movimiento() {

	int filaini=0, columnaini=0;

	while (filaini > 8 || columnaini > 8 || filaini < 0 || columnaini < 0) {
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
		
	} //Así nos aseguramos que las coordenadas introducidas son correctas, están dentro del tablero y hay una ficha en dicha casilla

	

	int filafin, columnafin;

	while (filafin > 8 || columnafin > 8 || filafin < 0 || columnafin < 0) {
		cout << "Introduzca la fila y columna a donde quiere mover la ficha: ";
		cin >> filafin >> columnafin;
	} //Así nos aseguramos que las coordenadas introducidas son correctas y están dentro del tablero
	

	switch (casilla[filaini][columnaini].ficha) {
	case 'A':
		if (alfil.restricciones(filafin, columnafin, filaini, columnaini))
			alfil.setPos(filafin, columnafin);
		else
			cout << "Movimiento no permitido";
		break;
	case 'T':
		if (torre.restricciones(filafin, columnafin, filaini, columnaini))
			torre.setPos(filafin, columnafin);
		else
			cout << "Movimiento no permitido";
		break;
	case 'C':
		if (caballo.restricciones(filafin, columnafin, filaini, columnaini))
			caballo.setPos(filafin, columnafin);
		else
			cout << "Movimiento no permitido";
		break;
	case'P':
		if (peon.restricciones(filafin, columnafin, filaini, columnaini))
			peon.setPos(filafin, columnafin);
		else
			cout << "Movimiento no permitido";
		break;
	case 'K':
		if (rey.restricciones(filafin, columnafin, filaini, columnaini))
			rey.setPos(filafin, columnafin);
		else
			cout << "Movimiento no permitido";
		break;
	case 'Q':
		if (reina.restricciones(filafin, columnafin, filaini, columnaini))
			reina.setPos(filafin, columnafin);
		else
			cout << "Movimiento no permitido";
		break;
	}


	
}

int Fichas::getFila() {
	return Fila;
}

int Fichas::getColumna() {
	return Columna;
}
Nombrefichas Fichas::getFicha() {
	return Tipo;
}

void Fichas::setPos(int fila, int columna) {
	fila = Fila;
	columna = Columna;
}

void Fichas::dibujar() {
	
}