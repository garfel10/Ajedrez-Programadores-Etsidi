#pragma once
class casillas
{
public:

	int c; //COLUMNA (1-8)
	int f; //FILA (1-8)
	unsigned char color;//b black, w white
	void casillero(); //Para generar el tablero lógico. Vector casillas de 1 a 64. cada una con su color.
	int estado = 0; // 1 ocupada, 0 libre. Lo inicializamos a 0 y cuando se inicialicen las fichas ya se ponen a 1 las que se tienen que poner.
	//las casillas ocupadas seran de la 1 a la 16 y de la 48 a la 
	unsigned char fcolor;//b black , w white. el color de la ficha se lo pasa la propia ficha. 
	char ficha;//alfil:'A', torre 'T', caballo 'C', peon 'P', rey'K', reina 'Q', nulo '0'
	int numero;//la n


	//el punto sobre el que se debe centrar la ficha
	int centrox;
	int centroy;
	
	
	//las funciones que utilizaran las fichas cuando "lleguen" o se "vayan"
	void vaciar(int columna, int fila);
	void ocupar(int columna, int fila, char pieza, char colorficha);






};
