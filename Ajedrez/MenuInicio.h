#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;

enum Estado { START, PLAY };

class MenuInicio {
	Sprite* menuini = new Sprite("imagenes/menu.png", 0.0, 8.0, 35.0, 35.0);
	Estado estado;
	float tiempo;
	bool audio;
public:
	MenuInicio();
	~MenuInicio();
	void tecla(unsigned char key);
	void dibuja();
	//void mueve();
};
