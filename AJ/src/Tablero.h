#pragma once
#include "Alfil.h"
#include "Caballo.h"
#include "Torre.h"
#include "Peon.h"
#include "Rey.h"
#include "Reina.h"
#include "casilla.h"

class Tablero {
public:
	static casillas casilla[9][9];
	void dibuja();
};