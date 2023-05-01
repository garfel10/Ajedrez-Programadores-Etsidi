#include "Fichas.h"

Fichas::Fichas(Nombrefichas tipo, int fila, int columna, bool color) {
	tipo = Tipo;
	fila = Fila;
	columna = Columna;
	color = Color;
}

void Fichas::movimiento(int nueva_fila, int nueva_columna) {
	bool comprobacion;
	Nombrefichas type;
	int fila_actual = getFila(), columna_actual = getColumna();
	comprobacion = restricciones(nueva_fila, nueva_columna, fila_actual, columna_actual, type);
	if (comprobacion) {
		nueva_fila = Fila;
		nueva_columna = Columna;
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

void Fichas::setPos(int fila1, int columna1, int fila2, int columna2) {
	
}

bool Fichas::restricciones(int nueva_fila, int nueva_columna,int fila_actual, int columna_actual, Nombrefichas t){
	switch (t) {
	case Nombrefichas::PEON: //FALTARÍA METER LAS POSIBILIDADES DE COMER OTRA FICHA
		if (nueva_fila - fila_actual <=2 && nueva_columna == columna_actual)
			return 1;
		else
			return 0;
		break;
	case Nombrefichas::ALFIL:
		if ((nueva_columna - columna_actual) == (nueva_fila - fila_actual))
			return 1;
		else return 0;
		break;
	case Nombrefichas::TORRE:
		if ((nueva_columna == columna_actual) || (nueva_fila == fila_actual))
			return 1;
		break;
	case Nombrefichas::CABALLO: //REVISAR
		break;
	case Nombrefichas::REINA:
		if ((nueva_columna - columna_actual) == (nueva_fila - fila_actual) || ((nueva_columna == columna_actual) || (nueva_fila == fila_actual)))
			return 1;



	}
}
