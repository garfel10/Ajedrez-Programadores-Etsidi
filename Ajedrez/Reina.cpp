#include "Reina.h"

void Reina::dibujar() {
	if (Color == 1) {
		ETSIDI::getTexture("bin/imagenes/Reina Blanco");
	}
	if (Color == 0) {
		ETSIDI::getTexture("bin/imagenes/Reina Negro");
	}
}