#include "Fichas.h"
#include "lib/ETSIDI.h"

Fichas::Fichas(Nombrefichas tipo, int fila, int columna, bool color) {
	tipo = Tipo;
	fila = Fila;
	columna = Columna;
	color = Color; //1 para blanco 0 para negro
}

void Fichas::movimiento(int nueva_fila, int nueva_columna) {
	/*bool comprobacion;
	Nombrefichas type = Tipo;
	int fila_actual = getFila(), columna_actual = getColumna();
	comprobacion = restricciones(nueva_fila, nueva_columna, fila_actual, columna_actual, type);
	if (comprobacion) {
		setPos(nueva_fila, nueva_columna);
	}
	*/

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