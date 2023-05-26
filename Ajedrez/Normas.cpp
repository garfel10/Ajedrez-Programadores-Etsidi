//posiblemente las normas aquí puestas sean añadidas como métodos en la clase tablero para acceder a la información de la forma más cómoda, mientras tanto estarán aquí
#include "Nombrefichas.h"
#include "Normas.h"
#include "casilla.h"


int jaque(casillas tablero[9][9], int xatacante, int yatacante, int bando, int xrey, int yrey ) { //comprueba si el rey está en jaque, y si lo está, comprueba si está en jaque mate
	//datos de prueba, luego serán sustituidos por los equivalentes en la clase tablero
	int entry = 0;//entrada a switch case
	Nombrefichas atacante=tablero[yatacante][xatacante].ficha.getFicha();// miramos que tipo de ficha es la que ataca, creo que esto esta mal planteado, habra que tener de input a la funcion la ficha atacante directamente
	int bandoatacante;
	if (bando == 1)
		bandoatacante = 0;
	else
		bandoatacante = 1; //ponemos al bando atacante como contrario del defensor y comprobamos si está amenazada
	//primero de todo comprobaremos si la posicion del rey está amenazada
	//IMPORTANTE: ANTES DE LA FUNCION JAQUE, LA FUNCION CLAVADA TIENE QUE HACER UNA PASADA POR TODAS LAS FICHAS DEL BANDO AL QUE SE HACE JAQUE, PARA QUE LAS CLAVADAS NO PUEDAN COMER NI AMENAZAR
		
	if ((bando == 1) && (tablero[yrey][xrey].amenazanegra == true) || ((bando == 0) && (tablero[yrey][xrey].amenazablanca == true))) //la posición del rey está amenazada, por tanto es jaque, ahora comprobamos si hay jaque mate, empezando por ver si el rey puede huir
	{
		if ((((bando == 1) && (tablero[yrey + 1][xrey].amenazanegra == false)) && (tablero[yrey + 1][xrey].bando != bando))||(((bando == 0) && (tablero[yrey+1][xrey].amenazablanca == false)) && (tablero[yrey + 1][xrey].bando != bando)))
			return 1; //1 significa que está en jaque, pero no en jaque mate
		if ((((bando == 1) && (tablero[yrey - 1][xrey].amenazanegra == false)) && (tablero[yrey - 1][xrey].bando != bando)) || (((bando == 0) && (tablero[yrey-1][xrey].amenazablanca == false)) && (tablero[yrey - 1][xrey].bando != bando)))
			return 1;
		if ((((bando == 1) && (tablero[yrey][xrey+1].amenazanegra == false)) && (tablero[yrey][xrey+1].bando != bando)) || (((bando == 0) && (tablero[yrey][xrey+1].amenazablanca == false)) && (tablero[yrey + 1][xrey].bando != bando)))
			return 1;
		if ((((bando == 1) && (tablero[yrey+1][xrey + 1].amenazanegra == false)) && (tablero[yrey+1][xrey + 1].bando != bando)) || (((bando == 0) && (tablero[yrey+1][xrey+1].amenazablanca == false)) && (tablero[yrey + 1][xrey].bando != bando)))
			return 1;
		if ((((bando == 1) && (tablero[yrey-1][xrey + 1].amenazanegra == false)) && (tablero[yrey-1][xrey + 1].bando != bando)) || (((bando == 0) && (tablero[yrey-1][xrey+1].amenazablanca == false)) && (tablero[yrey + 1][xrey].bando != bando)))
			return 1;
		if ((((bando == 1) && (tablero[yrey][xrey - 1].amenazanegra == false)) && (tablero[yrey][xrey - 1].bando != bando)) || (((bando == 0) && (tablero[yrey][xrey-1].amenazablanca == false)) && (tablero[yrey + 1][xrey].bando != bando)))
			return 1;
		if ((((bando == 1) && (tablero[yrey+1][xrey - 1].amenazanegra == false)) && (tablero[yrey+1][xrey - 1].bando != bando)) || (((bando == 0) && (tablero[yrey+1][xrey-1].amenazablanca == false)) && (tablero[yrey + 1][xrey].bando != bando)))
			return 1;
		if ((((bando == 1) && (tablero[yrey-1][xrey - 1].amenazanegra == false)) && (tablero[yrey-1][xrey - 1].bando != bando)) || (((bando == 0) && (tablero[yrey+1][xrey-1].amenazablanca == false)) && (tablero[yrey + 1][xrey].bando != bando)))
			return 1;
		//en caso de que el rey no haya podido huir por ninguna de las posiciones colindantes, comprobamos si se puede eliminar la amenaza
		if (((bando == 1) && (tablero[yatacante][xatacante].amenazablanca == true)) || (((bando == 0) && (tablero[yatacante][xatacante].amenazanegra == true))))
			return 1;
		else
		{
			//esto significa que no podemos comernos al atacante, por lo que la única opción que queda es bloquear su camino, cosa que solo se puede si es una Reina, una Torre o un Alfil
			if (tablero[yatacante][xatacante].ficha.getFicha() == Nombrefichas::PEON)
				entry = 1;
			if (tablero[yatacante][xatacante].ficha.getFicha() == Nombrefichas::CABALLO)
				entry = 2;
			if (tablero[yatacante][xatacante].ficha.getFicha() == Nombrefichas::TORRE)
				entry = 3;
			if (tablero[yatacante][xatacante].ficha.getFicha() == Nombrefichas::ALFIL)
				entry = 4;
			if (tablero[yatacante][xatacante].ficha.getFicha() == Nombrefichas::REINA)
				entry = 5;
			if (tablero[yatacante][xatacante].ficha.getFicha() == Nombrefichas::REY)
				entry = 6;
			if (tablero[yatacante][xatacante].ficha.getFicha() == Nombrefichas::VACIO)
				entry = 0;
				switch (entry/*tablero[yatacante][xatacante].ficha*/) {
				case 1://peon
					return 2;
				case 2://caballo
					return 2;
				case 3: //torre
					{
					if (xatacante == xrey) //están en la misma columna
					{
						if (yatacante < yrey) //si está debajo del rey, comprobamos las casillas que tiene encima una a una
						{
							for (int i = 1; (yatacante + i) < yrey; i++)
							{
								if (bando == 1)
								{
									if (tablero[yatacante + i][xatacante].amenazablanca == true)
										return 1; //se ha podido bloquear alguno de los puntos intermedios
								}
								if (bando == 0)
								{
									if (tablero[yatacante + i][xatacante].amenazanegra == true)
										return 1;
								}
							}
						}
						if (yatacante > yrey)  //si está encima del rey, comprobamos las casillas que tiene debajo una a una
						{
							for (int i = 1; (yatacante - i) > yrey; i++)
							{
								if (bando == 1)
								{
									if (tablero[yatacante - i][xatacante].amenazablanca == true)
										return 1; //se ha podido bloquear alguno de los puntos intermedios
								}
								if (bando == 0)
								{
									if (tablero[yatacante - i][xatacante].amenazanegra == true)
										return 1;
								}
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
								if (bando == 1)
								{
									if (tablero[yatacante][xatacante+i].amenazablanca == true)
										return 1; //se ha podido bloquear alguno de los puntos intermedios
								}
								if (bando == 0)
								{
									if (tablero[yatacante][xatacante+i].amenazanegra == true)
										return 1;
								}
							}
						}
					if (xatacante > xrey) //si está a la derecha del rey, comprobamos las casillas en el camino una a una
							{
							for (int i = 1; (xatacante - i) < xrey; i++)
							{
								if (bando == 1)
								{
									if (tablero[yatacante][xatacante-i].amenazablanca == true)
										return 1; //se ha podido bloquear alguno de los puntos intermedios
								}
								if (bando == 0)
								{
									if (tablero[yatacante][xatacante-i].amenazanegra == true)
										return 1;
								}
							}
							}
					return 2; //si ninguna de las iteraciones ha encontrado un bloqueo para el ataque, es jaque mate
					}
					}
				case 4://alfil
					{
				if ((xatacante - xrey < 0) && (yatacante - yrey < 0)) //abajo a la izquierda del rey
				{
					for (int i = 1; (yatacante + i) < yrey; i++)
					{
						if (bando == 1)
						{
							if (tablero[yatacante + i][xatacante+i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (tablero[yatacante + i][xatacante+i].amenazanegra == true)
								return 1;
						}
					}
				}
				if ((xatacante - xrey > 0) && (yatacante - yrey < 0)) //abajo a la derecha del rey
				{
					for (int i = 1; (yatacante + i) < yrey; i++)
					{
						if (bando == 1)
						{
							if (tablero[yatacante + i][xatacante-i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (tablero[yatacante + i][xatacante-i].amenazanegra == true)
								return 1;
						}
					}
				}
				if ((xatacante - xrey < 0) && (yatacante - yrey > 0)) //arriba a la izquierda del rey
				{
					for (int i = 1; (yatacante - i) > yrey; i++)
					{
						if (bando == 1)
						{
							if (tablero[yatacante - i][xatacante+i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (tablero[yatacante - i][xatacante+i].amenazanegra == true)
								return 1;
						}
					}
				}
				if ((xatacante - xrey > 0) && (yatacante - yrey > 0)) //arriba a la derecha del rey
				{
					for (int i = 1; (yatacante + i) < yrey; i++)
					{
						if (bando == 1)
						{
							if (tablero[yatacante - i][xatacante-i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (tablero[yatacante -i][xatacante-i].amenazanegra == true)
								return 1;
						}
					}
				}
				return 2; //si no se puede bloquear la trayectoria de la amenaza, es jaque mate
				} //no pasa nada por comprobar siempre la y, ya que al moverse en diagonal, la distancia que habra en x e y al rey será siempre igual
				case 5: //reina, combinamos las condiciones de la torre y el alfil
					{
					if (xatacante == xrey) //están en la misma columna
					{
						if (yatacante < yrey) //si está debajo del rey, comprobamos las casillas que tiene encima una a una
						{
							for (int i = 1; (yatacante + i) < yrey; i++)
							{
								if (bando == 1)
								{
									if (tablero[yatacante + i][xatacante].amenazablanca == true)
										return 1; //se ha podido bloquear alguno de los puntos intermedios
								}
								if (bando == 0)
								{
									if (tablero[yatacante + i][xatacante].amenazanegra == true)
										return 1;
								}
							}
						}
						if (yatacante > yrey)  //si está encima del rey, comprobamos las casillas que tiene debajo una a una
						{
							for (int i = 1; (yatacante - i) > yrey; i++)
							{
								if (bando == 1)
								{
									if (tablero[yatacante - i][xatacante].amenazablanca == true)
										return 1; //se ha podido bloquear alguno de los puntos intermedios
								}
								if (bando == 0)
								{
									if (tablero[yatacante - i][xatacante].amenazanegra == true)
										return 1;
								}
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
								if (bando == 1)
								{
									if (tablero[yatacante][xatacante + i].amenazablanca == true)
										return 1; //se ha podido bloquear alguno de los puntos intermedios
								}
								if (bando == 0)
								{
									if (tablero[yatacante][xatacante + i].amenazanegra == true)
										return 1;
								}
							}
						}
						if (xatacante > xrey) //si está a la derecha del rey, comprobamos las casillas en el camino una a una
						{
							for (int i = 1; (xatacante - i) < xrey; i++)
							{
								if (bando == 1)
								{
									if (tablero[yatacante][xatacante - i].amenazablanca == true)
										return 1; //se ha podido bloquear alguno de los puntos intermedios
								}
								if (bando == 0)
								{
									if (tablero[yatacante][xatacante - i].amenazanegra == true)
										return 1;
								}
							}
						}
						return 2; //si ninguna de las iteraciones ha encontrado un bloqueo para el ataque, es jaque mate
					}
					if ((xatacante - xrey < 0) && (yatacante - yrey < 0)) //abajo a la izquierda del rey
					{
						for (int i = 1; (yatacante + i) < yrey; i++)
						{
							if (bando == 1)
							{
								if (tablero[yatacante + i][xatacante + i].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (tablero[yatacante + i][xatacante + i].amenazanegra == true)
									return 1;
							}
						}
					}
					if ((xatacante - xrey > 0) && (yatacante - yrey < 0)) //abajo a la derecha del rey
					{
						for (int i = 1; (yatacante + i) < yrey; i++)
						{
							if (bando == 1)
							{
								if (tablero[yatacante + i][xatacante - i].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (tablero[yatacante + i][xatacante - i].amenazanegra == true)
									return 1;
							}
						}
					}
					if ((xatacante - xrey < 0) && (yatacante - yrey > 0)) //arriba a la izquierda del rey
					{
						for (int i = 1; (yatacante - i) > yrey; i++)
						{
							if (bando == 1)
							{
								if (tablero[yatacante - i][xatacante + i].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (tablero[yatacante - i][xatacante + i].amenazanegra == true)
									return 1;
							}
						}
					}
					if ((xatacante - xrey > 0) && (yatacante - yrey > 0)) //arriba a la derecha del rey
					{
						for (int i = 1; (yatacante + i) < yrey; i++)
						{
							if (bando == 1)
							{
								if (tablero[yatacante - i][xatacante - i].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (tablero[yatacante - i][xatacante - i].amenazanegra == true)
									return 1;
							}
						}
					}
					return 2; //si no se puede bloquear la trayectoria de la amenaza, es jaque mate
				}
				case 6:
					return 2;
				break; //los casos que solo tienen return 2 son porque esa pieza, al saltar a la posicion de ataque sin seguir una trayectoria, no se puede bloquear, por tanto es jaque mate automáticamente
				
				}
		}
	}
	else
	return 0;//si no está amenazado siquiera, retorna 0, que significa que no hay ni jaque ni jaque mate
}
