#include "casilla.h"

void casillas::tablero (){

	int n = 0;
	int i = 1;
	int j = 1;
	casillas casilla[64];


	while(n<64) {


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
