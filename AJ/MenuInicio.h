#pragma once
#include "ETSIDI.h"

enum Estado { START, PLAY };

class MenuInicio {
public:
	MenuInicio();
	~MenuInicio();
	void tecla(unsigned char key);
	void dibuja();


protected:
	Estado estado;
	float tiempo;
};

