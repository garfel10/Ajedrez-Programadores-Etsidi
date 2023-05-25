#pragma once
#include "Nombrefichas.h"
class casillas
{
public:
	bool amenazablanca;
	bool amenazanegra;
	bool clavada;
	int c; //COLUMNA (1-8)
	int f; //FILA (1-8)
	unsigned char color;//b black, w white
	void casillero(); //Para generar el tablero lógico. Vector casillas de 1 a 64. cada una con su color.
	int estado=0; // 1 ocupada, 0 libre. Lo inicializamos a 0 y cuando se inicialicen las fichas ya se ponen a 1 las que se tienen que poner.
	//las casillas ocupadas seran de la 1 a la 16 y de la 48 a la 
	unsigned char fcolor;//b black , w white. el color de la ficha se lo pasa la propia ficha. 
	int bando; //igual que fcolor, pero mas facil de manejar creo yo, se vera si se queda o mantiene
	Nombrefichas ficha;//alfil:'A', torre 'T', caballo 'C', peon 'P', rey'K', reina 'Q', nulo '0'
	int numero;//la n, el numero de casilla para devolver.


	//a partir de aquí orientamos a coordenadas de los centros sobre las que se colocarán las piezas
	//vamos a establecer los parámetros de coordenadas de cada casilla
	int limx1;//limite x por la izquierda
	int limx2;//limite x por la derecha
	int limy1;//limite y por abajo
	int limy2;//limite y por arriba
	
	//el punto sobre el que se debe centrar la ficha
	int centrox;
	int centroy;
	void centros();
	void iniciar();
	//todos los puntos x son los mismos que los puntos y, cuando haga la función de dibujo veo si viene bien unificarlos;

	void vaciar(int i);
	void ocupar(int i, Nombrefichas pieza, char fcolor);
	
	




};

