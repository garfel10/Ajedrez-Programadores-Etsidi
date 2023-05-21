#include "Peon.h"

void Peon::dibujar() {
	if (Color == 1) {
		ETSIDI::getTexture("bin/imagenes/Peon Blanco");
	}
	if (Color == 0) {
		ETSIDI::getTexture("bin/imagenes/Peon Negro");
	}
}