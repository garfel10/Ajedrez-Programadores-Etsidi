#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;

enum Estado { START, MENUINICIO, INFO, MENU, PLAY };

class MenuInicio {
	Sprite* menuini = new Sprite("imagenes/menu.png", 0.0, 8.0, 35.0, 35.0);
	Sprite* info = new Sprite("imagenes/menu1.png", 0.0, 6.0, 35.0, 35.0);
	Sprite* ins = new Sprite("imagenes/instrucciones.png", 0.0, 6.0, 35.0, 35.0);
	Sprite* menu = new Sprite("imagenes/menu2.png", 0.0, 6.0, 35.0, 35.0);
	
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
