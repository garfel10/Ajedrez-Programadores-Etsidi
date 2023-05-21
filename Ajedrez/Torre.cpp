#include "Torre.h"

void Torre::dibujar() {
	if (Color == 1) {
		ETSIDI::getTexture("bin/imagenes/Torre Blanco");
	}
	if (Color == 0) {
		ETSIDI::getTexture("bin/imagenes/Torre Negro");
	}
}