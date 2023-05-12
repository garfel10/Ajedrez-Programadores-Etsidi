#include "casilla.h"

void casillas::tablero (){

	int n = 1;
	int i = 1;
	int j = 1;
	casillas casilla[65];


	while(n<65) {


		casilla[n].x = i;
		casilla[n].y = j;

		if (i % 2 == j % 2) casilla[n].color = 'b';
		else casilla[n].color = 'w';

			n++;
			if (i < 8) i++;
			else {
				i = 1;
				j++;
			}
		
	}


}
