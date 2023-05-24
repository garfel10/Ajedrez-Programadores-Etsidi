#include "casilla.h"

casillas casilla[65];

void casillas::casillero (){

	int n = 1;
	int i = 1;
	int j = 1;
	


	while(n<65) {


		casilla[n].c = i;
		casilla[n].f = j;
		casilla[n].numero = n;
		
		if (i % 2 == j % 2) casilla[n].color = 'b';
		else casilla[n].color = 'w';

			n++;
			if (i < 8) i++;
			else {
				i = 1;
				j++;
			}
		
	}
	//se genera un vector que recorre el tablero por filas, de izquierda a derecha y de abajo a arriba.

}

void casillas::centros() {
	
	int c = 1;

	while (c < 65) {

		//limites en x: LOS ESTABLEZCO DIRECTAMENTE DEL TABLERO DE LUCIA
		casilla[c].limx1 = (0.5 + casilla[c].c);//+0.5 pq he decidido empezar por 1 en vez de 0
		casilla[c].limx2 = (1 + casilla[c].limx1);//realmente no lo utilizo

		//limites en y: lo mismo que arriba
		casilla[c].limy1 = (0.5 + casilla[c].f);
		casilla[c].limy2 = (1 + casilla[c].limy1);

		casilla[c].centrox = 0.5 + casilla[c].limx1;
		casilla[c].centroy = casilla[c].centrox;//es un cuadrado que empieza en el punto (1.5,1.5), los centros tienen la misma x que y

	}



}

void casillas::vaciar(int n) {

	casilla[n].estado = 0;
	casilla[n].ficha = '0';

}

void casillas::ocupar(int n, char pieza) {

	casilla[n].estado = 1;
	casilla[n].ficha = pieza;

}
