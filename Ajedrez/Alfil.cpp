#include "Alfil.h"

void Alfil::dibujar() {
	if (Color == 1) {
		ETSIDI::getTexture("bin/imagenes/Alfil Blanco");
	}
	if (Color == 0) {
		ETSIDI::getTexture("bin/imagenes/Alfil Negro");
	}
}