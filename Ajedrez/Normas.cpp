//posiblemente las normas aquí puestas sean añadidas como métodos en la clase tablero para acceder a la información de la forma más cómoda, mientras tanto estarán aquí
#include "Nombrefichas.h"
int jaque(int bando, int xatacante, int yatacante ) { //comprueba si el rey está en jaque, y si lo está, comprueba si está en jaque mate
	//datos de prueba, luego serán sustituidos por los equivalentes en la clase tablero
	int xrey, yrey;
	enum dato = tipoficha(xatacante, yatacante);// miramos que tipo de ficha es la que ataca, creo que esto esta mal planteado, habra que tener de input a la funcion la ficha atacante directamente
	int bandoatacante;
	if (bando = 1)
		bandoatacante = 0;
	else
		bandoatacante = 1; //ponemos al bando atacante como contrario del defensor y comprobamos si está amenazada
	//primero de todo comprobaremos si la posicion del rey está amenazada
	//IMPORTANTE: ANTES DE LA FUNCION JAQUE, LA FUNCION CLAVADA TIENE QUE HACER UNA PASADA POR TODAS LAS FICHAS DEL BANDO AL QUE SE HACE JAQUE, PARA QUE LAS CLAVADAS NO PUEDAN COMER NI AMENAZAR
	bool amenazarey = amenaza(xrey, yrey, bando);
	if (amenazarey == false)
		return 0; //0 significa que no está ni en jaque ni en jaque mate
	if (amenazarey == true) //la posición del rey está amenazada, por tanto es jaque, ahora comprobamos si hay jaque mate, empezando por ver si el rey puede huir
	{
		bool check = true; //esta variable booleana nos indicará si hay una posición no amenazada, ya que cuando no sea el caso, sabremos que puede huir a esta si está libre
		bool free = false;
		check = amenaza(xrey, yrey + 1, bando);
		free = ocupada(xrey, yrey + 1, bando); //esta funcion comprueba si esta libre o ocupada la casilla, retorna false solo si esta ocupada por una pieza aliada, ya que si es enemiga te la puedes comer
		if ((check == false) && (free == true))
			return 1; //1 significa que está en jaque, pero no en jaque mate
		check = amenaza(xrey, yrey - 1, bando);
		free = ocupada(xrey, yrey - 1, bando);
		if ((check == false)&&(free==true))
			return 1;
		check = amenaza(xrey + 1, yrey, bando);
		free = ocupada(xrey + 1, yrey, bando);
		if ((check == false) && (free == true))
			return 1;
		check = amenaza(xrey + 1, yrey + 1, bando);
		free = ocupada(xrey + 1, yrey + 1, bando);
		if ((check == false) && (free == true))
			return 1;
		check = amenaza(xrey + 1, yrey - 1, bando);
		free = ocupada(xrey + 1, yrey - 1, bando);
		if ((check == false) && (free == true))
			return 1;
		check = amenaza(xrey - 1, yrey, bando);
		free = ocupada(xrey - 1, yrey, bando);
		if ((check == false) && (free == true))
			return 1;
		check = amenaza(xrey - 1, yrey + 1, bando);
		free = ocupada(xrey - 1, yrey + 1, bando);
		if ((check == false) && (free == true))
			return 1;
		check = amenaza(xrey - 1, yrey - 1, bando);
		free = ocupada(xrey - 1, yrey - 1, bando);
		if ((check == false) && (free == true))
			return 1;
		//en caso de que el rey no haya podido huir por ninguna de las posiciones colindantes, comprobamos si se puede eliminar la amenaza
		bool atacante = amenaza(xatacante, yatacante, bandoatacante);
		if (atacante == true)
			return 1; //se puede comer al atacante, así que no es jaque mate
		if (atacante == false)
		{
			//esto significa que no podemos comernos al atacante, por lo que la única opción que queda es bloquear su camino, cosa que solo se puede si es una Reina, una Torre o un Alfil
			
				bool bloqueo = false;
				switch (dato) {
				case Nombrefichas::TORRE:
					{
					if (xatacante == xrey) //están en la misma fila
					{
						if (yatacante < yrey) //si está debajo del rey, comprobamos las casillas que tiene encima una a una
						{
							for (int i = 1; (yatacante + i) < yrey; i++)
							{
								bloqueo = amenaza(xatacante, yatacante + i, bandoatacante);
								if (bloqueo == true)
									return 1;
							}
						}
						if (yatacante > yrey)  //si está encima del rey, comprobamos las casillas que tiene debajo una a una
						{
							for (int i = 1; (yatacante - i) > yrey; i++)
							{
								bloqueo = amenaza(xatacante, yatacante - i, bandoatacante);
								if (bloqueo == true)
									return 1; 
							}
						}
						return 2; //si ninguna de las iteraciones ha encontrado un bloqueo para el ataque, es jaque mate
					}
					
					if (yatacante == yrey) //están en la misma columna
						{
							if (xatacante < xrey) //si está a la izquierda del rey, comprobamos las casillas en el camino una a una
							{
								for (int i = 1; (xatacante + i) < xrey; i++)
								{
									bloqueo = amenaza(xatacante + i, yatacante, bandoatacante);
									if (bloqueo == true)
										return 1;
								]
							}
							if (xatacante > xrey) //si está a la derecha del rey, comprobamos las casillas en el camino una a una
							{
								for (int i = 1; (xatacante - i) < xrey; i++)
								{
									bloqueo = amenaza(xatacante - i, yatacante, bandoatacante);
									if (bloqueo == true)
										return 1;
								}
							}
							return 2; //si ninguna de las iteraciones ha encontrado un bloqueo para el ataque, es jaque mate
						}
						
						
					}
				case Nombrefichas::ALFIL:
				{
					if ((xatacante - xrey < 0) && (yatacante - yrey < 0)) //abajo a la izquierda del rey
					{
						for (int i = 1; (yatacante + i) < yrey; i++)
						{
							bloqueo = amenaza(xatacante + i, yatacante + i, bandoatacante);
							if (bloqueo == true)
								return 1;
						}
					}
					if ((xatacante - xrey > 0) && (yatacante - yrey < 0)) //abajo a la derecha del rey
					{
						for (int i = 1; (yatacante + i) < yrey; i++)
						{
							bloqueo = amenaza(xatacante - i, yatacante + i, bandoatacante);
							if (bloqueo == true)
								return 1;
						}
					}
					if ((xatacante - xrey < 0) && (yatacante - yrey > 0)) //arriba a la izquierda del rey
					{
						for (int i = 1; (yatacante - i) > yrey; i++)
						{
							bloqueo = amenaza(xatacante + i, yatacante - i, bandoatacante);
							if (bloqueo == true)
								return 1;
						}
					}
					if ((xatacante - xrey > 0) && (yatacante - yrey > 0)) //arriba a la derecha del rey
					{
						for (int i = 1; (yatacante + i) < yrey; i++)
						{
							bloqueo = amenaza(xatacante - i, yatacante - i, bandoatacante);
							if (bloqueo == true)
								return 1;
						}
					}
						return 2; //si no se puede bloquear la trayectoria de la amenaza, es jaque mate
				} //no pasa nada por comprobar siempre la y, ya que al moverse en diagonal, la distancia que habra en x e y al rey será siempre igual
				case Nombrefichas::REINA: //combinamos las condiciones de la torre y el alfil para las de la reina
					{
					if (xatacante == xrey) //están en la misma fila
					{
						if (yatacante < yrey) //si está debajo del rey, comprobamos las casillas que tiene encima una a una
						{
							for (int i = 1; (yatacante + i) < yrey; i++)
							{
								bloqueo = amenaza(xatacante, yatacante + i, bandoatacante);
								if (bloqueo == true)
									return 1;
							}
						}

						if (yatacante > yrey)  //si está encima del rey, comprobamos las casillas que tiene debajo una a una
						{
							for (int i = 1; (yatacante - i) > yrey; i++)
							{
								bloqueo = amenaza(xatacante, yatacante - i, bandoatacante);
								if (bloqueo == true)
									return 1;
							}
						}
						return 2; //si no ha conseguido bloquearlo, es jaque mate
					}
					if (yatacante == yrey) //están en la misma columna
					{
						if (xatacante < xrey) //si está a la izquierda del rey, comprobamos las casillas en el camino una a una
						{
							for (int i = 1; (xatacante + i) < xrey; i++)
							{
								bloqueo = amenaza(xatacante + i, yatacante, bandoatacante);
								if (bloqueo == true)
									return 1;
							}
						}
						if (xatacante > xrey) //si está a la derecha del rey, comprobamos las casillas en el camino una a una
						{
							for (int i = 1; (xatacante - i) < xrey; i++)
							{
								bloqueo = amenaza(xatacante - i, yatacante, bandoatacante);
								if (bloqueo == true)
									return 1;
							}
						return 2; //no puede bloquarlo, así que es jaque mate
						}
					}
					if ((xatacante - xrey < 0) && (yatacante - yrey < 0)) //abajo a la izquierda del rey
					{
						for (int i = 1; (yatacante + i) < yrey; i++)
						{
							bloqueo = amenaza(xatacante + i, yatacante + i, bandoatacante);
							if (bloqueo == true)
								return 1;
						}
					}
					if ((xatacante - xrey > 0) && (yatacante - yrey < 0)) //abajo a la derecha del rey
					{
						for (int i = 1; (yatacante + i) < yrey; i++)
						{
							bloqueo = amenaza(xatacante - i, yatacante + i, bandoatacante);
							if (bloqueo == true)
								return 1;
						}
					}
					if ((xatacante - xrey < 0) && (yatacante - yrey > 0)) //arriba a la izquierda del rey
					{
						for (int i = 1; (yatacante - i) > yrey; i++)
						{
							bloqueo = amenaza(xatacante + i, yatacante - i, bandoatacante);
							if (bloqueo == true)
								return 1;
						}
					}
					if ((xatacante - xrey > 0) && (yatacante - yrey > 0)) //arriba a la derecha del rey
					{
						for (int i = 1; (yatacante + i) < yrey; i++)
						{
							bloqueo = amenaza(xatacante - i, yatacante - i, bandoatacante);
							if (bloqueo == true)
								return 1;
						}
					}
						return 2; //si no se puede bloquear la trayectoria de la amenaza, es jaque mate
					}
				case Nombrefichas::CABALLO:
					return 2;
				case Nombrefichas::PEON:
					return 2;
				case Nombrefichas::REY:
					return 2;
				break; //los casos que solo tienen return 2 son porque esa pieza, al saltar a la posicion de ataque sin seguir una trayectoria, no se puede bloquear, por tanto es jaque mate automáticamente
				default:
				}
		}
	}
}
bool clavada(int tablero[8,8], int bando) //esta funcion comprobara si hay fichas en el tablero clavadas, usaremos un ciclo for similar al switch case de bloquear el camino para comprobar si la pieza amenazada tiene 
//al rey en la trayectoria de ataque de una ficha tipo Torre, Alfil o Reina en caso de moverse, los return true o false se cambiaran por un tablero[i,j].clavada=true/false cuando sean metodos
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)//con estos bucles anidados comprobaremos en todas las casillas del tablero si la pieza está amenazada
		{
			bool amenazaclavada = false;
			if (tablero[i, j].bando == bando)//se comprueba si la pieza en la casilla es del bando que estamos comprobando las clavadas
			{
				if (tablero[i, j].amenaza == true)
				{
					//comprobamos si le amenazan por la derecha
					for (int k = i+1; k < 8; k++)
					{
						if (tablero[k, j].amenaza == false)
							k = 8;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una torre
						if (tablero[k, j].amenaza == true)
						{//comprueba si en la siguiente casilla está la torre/reina que amenaza
							if (tablero[k + 1, j].ficha == Nombrefichas::TORRE || tablero[k + 1, j].ficha == Nombrefichas::REINA) //en caso que esté amenazado por una torre o reina, comprobamos si el rey está amenazado
							{
								for (int l = i; l >= 1; l--)//miramos a la izquierda de la ficha
								{
									if (tablero[l, j].ficha == Nombrefichas::ALFIL || tablero[l, j].ficha == Nombrefichas::CABALLO || tablero[l, j].ficha == Nombrefichas::PEON || tablero[l, j].ficha == Nombrefichas::REINA || tablero[l, j].ficha == Nombrefichas::TORRE)
										return false; //si hay una de estas fichas en la trayectoria aunque esté en rey detrás no estará clavada
									if (tablero[l, j].ficha == Nombrefichas::REY)
										return true; //en caso de que sea el rey, estará clavada, si no es ni ficha de las nombradas o rey, el bucle no hará nada
								}
								return false; //no hay ninguna ficha en la trayectoria
							}
							if (tablero[k + 1, j].ficha == Nombrefichas::ALFIL || tablero[k + 1, j].ficha == Nombrefichas::CABALLO || tablero[k + 1, j].ficha == Nombrefichas::PEON||tablero[k+1,j].ficha==Nombrefichas::REY)
								return false; //añadido para evitar coincidencias en las que pueda parecer que está amenazado por este tipo de pieza pero haya un enemigo distinto bloqueando el camino
						}
					}
					//comprobamos si le amenazan por la izquierda 
					for (int k = i-1; k > 1; k--) 
					{
						if (tablero[k, j].amenaza == false)
							k = 1;//si no está amenazado en alguna de las casillas intermedias no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una torre
						if (tablero[k, j].amenaza == true)
						{
							if (tablero[k-1, j].ficha == Nombrefichas::TORRE || tablero[k-1, j].ficha == Nombrefichas::REINA) //en caso que esté amenazado por una torre o reina, comprobamos si el rey está amenazado
							{
								for (int l = i; l =< 8; l++)//miramos a la derecha de la ficha
								{
									if (tablero[l, j].ficha == Nombrefichas::ALFIL || tablero[l, j].ficha == Nombrefichas::CABALLO || tablero[l, j].ficha == Nombrefichas::PEON || tablero[l, j].ficha == Nombrefichas::REINA || tablero[l, j].ficha == Nombrefichas::TORRE)
										return false; //si hay una de estas fichas en la trayectoria aunque esté en rey detrás no estará clavada
									if (tablero[l, j].ficha == Nombrefichas::REY)
										return true; //en caso de que sea el rey, estará clavada, si no es ni ficha de las nombradas o rey, el bucle no hará nada
								}
								return false; //no hay ninguna ficha en la trayectoria
							}
							if (tablero[k - 1, j].ficha == Nombrefichas::ALFIL || tablero[k - 1, j].ficha == Nombrefichas::CABALLO || tablero[k - 1, j].ficha == Nombrefichas::PEON || tablero[k - 1, j].ficha == Nombrefichas::REY)
								return false;
						}
					}
					//comprobamos si le amenazan por encima 
					for (int k = j+1; k < 8; k++)
					{
						if (tablero[i, k].amenaza == false)
							k = 8;
						if (tablero[i, k].amenaza == true)
						{
							if (tablero[i, k+1].ficha == Nombrefichas::TORRE || tablero[i, k+1].ficha == Nombrefichas::REINA) //en caso que esté amenazado por una torre o reina, comprobamos si el rey está amenazado
							{
								for (int l = j; l >= 1; l--)//miramos por debajo de la ficha
								{
									if (tablero[i, l].ficha == Nombrefichas::ALFIL || tablero[l, j].ficha == Nombrefichas::CABALLO || tablero[l, j].ficha == Nombrefichas::PEON || tablero[l, j].ficha == Nombrefichas::REINA || tablero[l, j].ficha == Nombrefichas::TORRE)
										return false; //si hay una de estas fichas en la trayectoria aunque esté en rey detrás no estará clavada
									if (tablero[i, l].ficha == Nombrefichas::REY)
										return true; //en caso de que sea el rey, estará clavada, si no es ni ficha de las nombradas o rey, el bucle no hará nada
								}
								return false; //no hay ninguna ficha en la trayectoria
							}
							if (tablero[i, k+1].ficha == Nombrefichas::ALFIL || tablero[i, k+1].ficha == Nombrefichas::CABALLO || tablero[i, k+1].ficha == Nombrefichas::PEON || tablero[i, k+1].ficha == Nombrefichas::REY)
								return false;
						}
					}
					//comprobamos si le amenazan por debajo
					for (int k = j-1; k >1; k--)
					{
						if (tablero[i, k].amenaza == false)
							k = 1;
						if (tablero[i, k].amenaza == true)
						{
							if (tablero[i, k-1].ficha == Nombrefichas::TORRE || tablero[i, k-1].ficha == Nombrefichas::REINA) //en caso que esté amenazado por una torre o reina, comprobamos si el rey está amenazado
							{
								for (int l = j; l <=8; l++)//miramos por encima de la ficha
								{
									if (tablero[i, l].ficha == Nombrefichas::ALFIL || tablero[l, j].ficha == Nombrefichas::CABALLO || tablero[l, j].ficha == Nombrefichas::PEON || tablero[l, j].ficha == Nombrefichas::REINA || tablero[l, j].ficha == Nombrefichas::TORRE)
										return false; //si hay una de estas fichas en la trayectoria aunque esté en rey detrás no estará clavada
									if (tablero[i, l].ficha == Nombrefichas::REY)
										return true; //en caso de que sea el rey, estará clavada, si no es ni ficha de las nombradas o rey, el bucle no hará nada
								}
							}
							if (tablero[i, k-1].ficha == Nombrefichas::ALFIL || tablero[i, k-1].ficha == Nombrefichas::CABALLO || tablero[i, k-1].ficha == Nombrefichas::PEON || tablero[i, k-1].ficha == Nombrefichas::REY)
								return false;
						}
					}
					//comprobamos si le amenazan por la diagonal inferior izquierda
					for (int k = i-1; k > 1; k--)
					{
						if (tablero[k,j-(i-k)].amenaza == false)
							k = 1;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o alfil
						if (tablero[k, j-(i-k)].amenaza == true)
						{//comprueba si en la siguiente casilla está la torre/reina que amenaza
							if (tablero[k-1, j-(i-k)-1].ficha == Nombrefichas::ALFIL || tablero[k - 1, j-(i-k)].ficha == Nombrefichas::REINA) //en caso que esté amenazado por un alfil o reina, comprobamos si el rey está amenazado
							{
								for (int l = i+1; l <=8; l++)//miramos arriba a la derecha
								{
									if (tablero[l, j+(l-i)].ficha == Nombrefichas::ALFIL || tablero[l, j+(l-i)].ficha == Nombrefichas::CABALLO || tablero[l, j+(l-i)].ficha == Nombrefichas::PEON || tablero[l, j+(l-i)].ficha == Nombrefichas::REINA || tablero[l, j+(l-i)].ficha == Nombrefichas::TORRE)
										return false; //si hay una de estas fichas en la trayectoria aunque esté en rey detrás no estará clavada
									if (tablero[l, j+(l-i)].ficha == Nombrefichas::REY)
										return true; //en caso de que sea el rey, estará clavada, si no es ni ficha de las nombradas o rey, el bucle no hará nada
								}
								return false; //no hay ninguna ficha en la trayectoria
							}
							if (tablero[k - 1, j-(i-k)-1].ficha == Nombrefichas::ALFIL || tablero[k - 1, j-(i-k)-1].ficha == Nombrefichas::CABALLO || tablero[k -1, j-(i-k)-1].ficha == Nombrefichas::PEON || tablero[k -1, j-(i-k)-1].ficha == Nombrefichas::REY)
								return false; //añadido para evitar coincidencias en las que pueda parecer que está amenazado por este tipo de pieza pero haya un enemigo distinto bloqueando el camino
						}
					}
					//comprobamos si le amenazan por la diagonal inferior derecha
					for (int k = i + 1; k <8; k++)
					{
						if (tablero[k, j - (k-i)].amenaza == false)
							k = 8;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o alfil
						if (tablero[k, j - (k-i)].amenaza == true)
						{//comprueba si en la siguiente casilla está la torre/reina que amenaza
							if (tablero[k + 1, j - (k-i) - 1].ficha == Nombrefichas::ALFIL || tablero[k + 1, j].ficha == Nombrefichas::REINA) //en caso que esté amenazado por un alfil o reina, comprobamos si el rey está amenazado
							{
								for (int l = i -1; l >= 1; l--)//miramos arriba a izquierda
								{
									if (tablero[l, j + (i-l)].ficha == Nombrefichas::ALFIL || tablero[l, j + (i-l)].ficha == Nombrefichas::CABALLO || tablero[l, j + (i-l)].ficha == Nombrefichas::PEON || tablero[l, j + (i-l)].ficha == Nombrefichas::REINA || tablero[l, j + (i-l)].ficha == Nombrefichas::TORRE)
										return false; //si hay una de estas fichas en la trayectoria aunque esté en rey detrás no estará clavada
									if (tablero[l, j + (i-l)].ficha == Nombrefichas::REY)
										return true; //en caso de que sea el rey, estará clavada, si no es ni ficha de las nombradas o rey, el bucle no hará nada
								}
								return false; //no hay ninguna ficha en la trayectoria
							}
							if (tablero[k + 1, j - (k-i) - 1].ficha == Nombrefichas::ALFIL || tablero[k + 1, j-(k-i)-1].ficha == Nombrefichas::CABALLO || tablero[k + 1, j-(k-i)-1].ficha == Nombrefichas::PEON || tablero[k + 1, j-(k-i)-1].ficha == Nombrefichas::REY)
								return false; //añadido para evitar coincidencias en las que pueda parecer que está amenazado por este tipo de pieza pero haya un enemigo distinto bloqueando el camino
						}
					}
					//comprobamos si le amenazan por la diagonal superior izquierda
					for (int k = i - 1; k > 1; k--)
					{
						if (tablero[k, j + (i - k)].amenaza == false)
							k = 1;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o alfil
						if (tablero[k, j + (i - k)].amenaza == true)
						{//comprueba si en la siguiente casilla está la torre/reina que amenaza
							if (tablero[k - 1, j + (i - k) +1].ficha == Nombrefichas::ALFIL || tablero[k - 1, j + (i-k) +1].ficha == Nombrefichas::REINA) //en caso que esté amenazado por un alfil o reina, comprobamos si el rey está amenazado
							{
								for (int l = i + 1; l <= 8; l++)//miramos abajo a la derecha
								{
									if (tablero[l, j -(l-i)].ficha == Nombrefichas::ALFIL || tablero[l, j-(l-i)].ficha == Nombrefichas::CABALLO || tablero[l, j -(l-i)].ficha == Nombrefichas::PEON || tablero[l, j - (l-i)].ficha == Nombrefichas::REINA || tablero[l, j - (l-i)].ficha == Nombrefichas::TORRE)
										return false; //si hay una de estas fichas en la trayectoria aunque esté en rey detrás no estará clavada
									if (tablero[l, j - (l-i)].ficha == Nombrefichas::REY)
										return true; //en caso de que sea el rey, estará clavada, si no es ni ficha de las nombradas o rey, el bucle no hará nada
								}
								return false; //no hay ninguna ficha en la trayectoria
							}
							if (tablero[k - 1, j + (i-k) + 1].ficha == Nombrefichas::ALFIL || tablero[k -1, j +(i-k)+1].ficha == Nombrefichas::CABALLO || tablero[k-1, j+(i-k)+1].ficha == Nombrefichas::PEON || tablero[k -1, j+(i-k)+1].ficha == Nombrefichas::REY)
								return false; //añadido para evitar coincidencias en las que pueda parecer que está amenazado por este tipo de pieza pero haya un enemigo distinto bloqueando el camino
						}
					}
					//comprobamos si le amenazan por la diagonal superior derecha
					for (int k = i + 1; k < 8; k++)
					{
						if (tablero[k, j + (k-i)].amenaza == false)
							k = 8;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o alfil
						if (tablero[k, j + (k-i)].amenaza == true)
						{//comprueba si en la siguiente casilla está la torre/reina que amenaza
							if (tablero[k + 1, j + (k-i) + 1].ficha == Nombrefichas::ALFIL || tablero[k + 1, j + (k-i) + 1].ficha == Nombrefichas::REINA) //en caso que esté amenazado por un alfil o reina, comprobamos si el rey está amenazado
							{
								for (int l = i - 1; l >= 1; l--)//miramos abajo a la izquierda
								{
									if (tablero[l, j-(i-l)].ficha == Nombrefichas::ALFIL || tablero[l, j-(i - l)].ficha == Nombrefichas::CABALLO || tablero[l, j - (i - l)].ficha == Nombrefichas::PEON || tablero[l, j - (i - l)].ficha == Nombrefichas::REINA || tablero[l, j - (i - l)].ficha == Nombrefichas::TORRE)
										return false; //si hay una de estas fichas en la trayectoria aunque esté en rey detrás no estará clavada
									if (tablero[l, j - (i - l)].ficha == Nombrefichas::REY)
										return true; //en caso de que sea el rey, estará clavada, si no es ni ficha de las nombradas o rey, el bucle no hará nada
								}
								return false; //no hay ninguna ficha en la trayectoria
							}
							if (tablero[k + 1, j + (k-i) + 1].ficha == Nombrefichas::ALFIL || tablero[k + 1, j + (k-i) + 1].ficha == Nombrefichas::CABALLO || tablero[k + 1, j + (k-i) + 1].ficha == Nombrefichas::PEON || tablero[k + 1, j + (k-i) + 1].ficha == Nombrefichas::REY)
								return false; //añadido para evitar coincidencias en las que pueda parecer que está amenazado por este tipo de pieza pero haya un enemigo distinto bloqueando el camino
						}
					}
				}
			}
		}
	}
}
bool amenazar(int tablero[8, 8], int bando)//esta funcion hara una pasada por todo el tablero, mirando las fichas del bando y marcando donde amenazan,los return true o false se cambiaran por un tablero[i,j].amenazada=true/false cuando sean metodos
{
	int ob;//ob = otro bando, se usará para que cuando encuentre una ficha del equipo contrario la amenace pero no siga avanzando con la amenaza (casos de TORRE, ALFIL y REINA)
	if (bando == 1)
		ob = 0; 
	if (bando == 0)
		ob = 1;
		for (int i = 1; i <= 8; i++)
		{
			for (int j = 1; j <= 8; j++)//bucle anidado para ver todo el tablero
			{
				if (tablero[i, j].bando == bando) //si es el mismo bando, declaramos las amenazas de ese color
				{
					switch (tablero[i, j].ficha) //diferentes amenazas según el tipo de ficha
					{
					case Nombrefichas::PEON:
					{
						if (bando == 1)
						{
							if (tablero[i + 1, j + 1].bando != bando || tablero[i + 1, j + 1].bando == bando) //amenaza haya aliados o enemigos, pero solo amenaza en su zona de ataque
								return true; //seria un amenazablanca=true; el bando 2 será que no está ocupada ni por blancas ni negras
							if (tablero[i - 1, j + 1].bando != bando || tablero[i - 1, j + 1].bando == bando)
								return true;
						}
						if (bando == 0) //el peon es la unica pieza que según su bando ataca de forma distinta, "baja el tablero", ya que consideramos que estan arriba negras y abajo blancas
						{
							if (tablero[i + 1, j - 1].bando != bando || tablero[i + 1, j - 1].bando == bando) //amenaza haya aliados o enemigos, pero solo amenaza en su zona de ataque
								return true; //seria un amenazablanca=true; el bando 2 será que no está ocupada ni por blancas ni negras
							if (tablero[i - 1, j - 1].bando != bando || tablero[i - 1, j - 1].bando == bando)
								return true;
						}
					}
					case Nombrefichas::CABALLO:
					{
						if (tablero[i + 2, j + 1].bando != bando|| tablero[i + 2, j + 1].bando == bando)
							return true;
						if (tablero[i + 2, j - 1].bando != bando || tablero[i + 2, j - 1].bando == bando)
							return true;
						if (tablero[i - 2, j + 1].bando != bando || tablero[i - 2, j + 1].bando == bando)
							return true;
						if (tablero[i - 2, j - 1].bando != bando || tablero[i -2 2, j - 1].bando == bando)
							return true;
						if (tablero[i + 1, j + 2].bando != bando || tablero[i + 1, j + 2].bando == bando)
							return true;
						if (tablero[i + 1, j - 2].bando != bando || tablero[i + 1, j - 2].bando == bando)
							return true;
						if (tablero[i - 1, j + 2].bando != bando || tablero[i - 1, j + 2].bando == bando)
							return true;
						if (tablero[i - 1, j - 2].bando != bando || tablero[i - 1, j - 2].bando == bando)
							return true;
					}
					case Nombrefichas::TORRE:
					{
					//ARRIBA
						for (int k = i+1; k <= 8; k++)
						{
							if (tablero[i,k].bando != bando || tablero[i,k].bando == bando)
								return true;
							if (tablero[i,k].bando == ob || tablero[i,k].bando == bando)
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
						}
					//ABAJO
						for (int k = i-1; k >= 1; k--)
						{
							if (tablero[i, k].bando != bando || tablero[i,k].bando == bando)
								return true;
							if (tablero[i, k].bando == ob || tablero[i, k].bando == bando)
								k = 0;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
						}
					//IZQUIERDA
						for (int k = i-1; k >= 1; k--)
						{
							if (tablero[k,j].bando != bando || tablero[k,j].bando == bando)
								return true;
							if (tablero[k,j].bando == ob || tablero[k,j].bando == bando)
								k = 0;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
						}
					//DERECHA
						for (int k = i+1; k <= 8; k++)
						{
							if (tablero[k, j].bando != bando || tablero[k, j].bando == bando)
								return true;
							if (tablero[k,j].bando == ob || tablero[k,j].bando == bando)
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
						}
					}
					case Nombrefichas::ALFIL:
					{
					//ARRIBA DERECHA
						for (int k = i+1; k <= 8; k++)
						{
							if (tablero[k, j+(k-i)].bando != bando || tablero[k, j+(k-i)].bando == bando)
								return true;
							if (tablero[k, j+(k-i)].bando == ob || tablero[k,j+ (k-i)].bando == bando)
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
						}
					//ARRIBA IZQUIERDA
						for (int k = i-1; k >= 1; k--)
						{
							if (tablero[k, j - (k - i)].bando != bando || tablero[k, j - (k - i)].bando == bando)
								return true;
							if (tablero[k, j - (k - i)].bando == ob || tablero[k,j -(k - i)].bando == bando)
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
						}
					//ABAJO DERECHA
						for (int k = i+1; k <= 8; k++)
						{
							if (tablero[k, j-(k-i)].bando != bando || tablero[k, j-(k-i)].bando == bando)
								return true;
							if (tablero[k, j-(k-i)].bando == ob || tablero[k,j- (k-i)].bando == bando)
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
						}
					//ABAJO IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (tablero[k, j + (k - i)].bando != bando || tablero[k, j + (k - i)].bando == bando)
								return true;
							if (tablero[k, j + (k - i)].bando == ob || tablero[k, j + (k - i)].bando == bando)
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
						}
					}
					case Nombrefichas::REINA: //suma de TORRE y ALFIL
					{
						//ARRIBA
						for (int k = i + 1; k <= 8; k++)
						{
							if (tablero[i, k].bando != bando || tablero[i, k].bando == bando)
								return true;
							if (tablero[i, k].bando == ob || tablero[i, k].bando == bando)
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
						}
						//ABAJO
						for (int k = i - 1; k >= 1; k--)
						{
							if (tablero[i, k].bando != bando || tablero[i, k].bando == bando)
								return true;
							if (tablero[i, k].bando == ob || tablero[i, k].bando == bando)
								k = 0;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
						}
						//IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (tablero[k, j].bando != bando || tablero[k, j].bando == bando)
								return true;
							if (tablero[k, j].bando == ob || tablero[k, j].bando == bando)
								k = 0;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
						}
						//DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (tablero[k, j].bando != bando || tablero[k, j].bando == bando)
								return true;
							if (tablero[k, j].bando == ob || tablero[k, j].bando == bando)
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
						}
						//ARRIBA DERECHA
						for (int k = i+1; k <= 8; k++)
						{
							if (tablero[k, j+(k-i)].bando != bando || tablero[k, j+(k-i)].bando == bando)
								return true;
							if (tablero[k, j+(k-i)].bando == ob || tablero[k,j+ (k-i)].bando == bando)
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
						}
						//ARRIBA IZQUIERDA
						for (int k = i-1; k >= 1; k--)
						{
							if (tablero[k, j - (k - i)].bando != bando || tablero[k, j - (k - i)].bando == bando)
								return true;
							if (tablero[k, j - (k - i)].bando == ob || tablero[k,j -(k - i)].bando == bando)
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
						}
						//ABAJO DERECHA
						for (int k = i+1; k <= 8; k++)
						{
							if (tablero[k, j-(k-i)].bando != bando || tablero[k, j-(k-i)].bando == bando)
								return true;
							if (tablero[k, j-(k-i)].bando == ob || tablero[k,j- (k-i)].bando == bando)
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
						}
						//ABAJO IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (tablero[k, j + (k - i)].bando != bando || tablero[k, j + (k - i)].bando == bando)
								return true;
							if (tablero[k, j + (k - i)].bando == ob || tablero[k, j + (k - i)].bando == bando)
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
						}
					}
					case Nombrefichas::REY:
					{
						if (tablero[i + 1, j].bando != bando || tablero[i + 1, j].bando == bando)
							return true;
						if (tablero[i + 1, j + 1].bando != bando || tablero[i + 1, j + 1].bando == bando)
							return true;
						if (tablero[i + 1, j - 1].bando != bando || tablero[i + 1, j - 1].bando == bando)
							return true;
						if (tablero[i - 1, j].bando != bando || tablero[i - 1, j].bando == bando)
							return true;
						if (tablero[i - 1, j + 1].bando != bando || tablero[i - 1, j + 1].bando == bando)
							return true;
						if (tablero[i - 1, j - 1].bando != bando || tablero[i - 1, j - 1].bando == bando)
							return true;
						if (tablero[i, j + 1].bando != bando || tablero[i, j + 1].bando == bando)
							return true;
						if (tablero[i, j - 1].bando != bando || tablero[i, j - 1].bando == bando)
							return true;
					}
					}
				}
			}
		}
}
	
