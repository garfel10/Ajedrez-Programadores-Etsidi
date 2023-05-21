#include "Caballo.h"
.
void Peon::dibujar() {
	if (Color == 1) {
		ETSIDI::getTexture("bin/imagenes/Caballo Blanco");
	}
	if (Color == 0) {
		ETSIDI::getTexture("bin/imagenes/Caballo Negro");
	}
}