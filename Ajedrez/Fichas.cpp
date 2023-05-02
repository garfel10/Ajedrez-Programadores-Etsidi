#include "Fichas.h"

Fichas::Fichas(Nombrefichas tipo, int fila, int columna, bool color) {
	tipo = Tipo;
	fila = Fila;
	columna = Columna;
	color = Color; //1 para blanco 0 para negro
}

void Fichas::movimiento(int nueva_fila, int nueva_columna) {
	bool comprobacion;
	Nombrefichas type = Tipo;
	int fila_actual = getFila(), columna_actual = getColumna();
	comprobacion = restricciones(nueva_fila, nueva_columna, fila_actual, columna_actual, type);
	if (comprobacion) {
		setPos(nueva_fila, nueva_columna);
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

bool Fichas::restricciones(int nueva_fila, int nueva_columna,int fila_actual, int columna_actual, Nombrefichas t){
	//En esta funcion se comprueba si es posible el movimiento de las fichas
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
		else return 0;
		break;
	case Nombrefichas::CABALLO: //REVISAR
		if ((((nueva_columna - columna_actual) == 1) || ((nueva_columna - columna_actual) == -1)) && (((nueva_fila - fila_actual) == 2) || (nueva_fila - fila_actual) == -2))
			return 1;
		if ((((nueva_fila - fila_actual) == 1) || ((nueva_fila - fila_actual) == -1)) && (((nueva_columna - columna_actual) == 2) || (nueva_columna - columna_actual) == -2))
			return 1;
		else return 0;
		break;
	case Nombrefichas::REINA:
		if ((nueva_columna - columna_actual) == (nueva_fila - fila_actual) || ((nueva_columna == columna_actual) || (nueva_fila == fila_actual)))
			return 1;
		else return 0;
		break;
	case Nombrefichas::REY:
		if (((nueva_columna - columna_actual) == 1 || (nueva_fila - fila_actual) == 1) && ((nueva_columna - columna_actual) == (nueva_fila - fila_actual) || ((nueva_columna == columna_actual) || (nueva_fila == fila_actual))))
			return 1;
		else return 0;
		break;
	}
}
