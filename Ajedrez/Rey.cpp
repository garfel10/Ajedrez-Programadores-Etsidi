#include "Rey.h"

void Rey::dibujar() {
	if (Color == 1) {
		ETSIDI::getTexture("bin/imagenes/Rey Blanco");
	}
	if (Color == 0) {
		ETSIDI::getTexture("bin/imagenes/Rey Negro");
	}
}