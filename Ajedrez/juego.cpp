#include "juego.h"

void juego::limpiaramenazas()
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tablero[j][i].amenazablanca = false;
			tablero[j][i].amenazanegra = false;
		}
	}
}

void juego::amenazar(int bando)
{
	int ob;//ob = otro bando, se usará para que cuando encuentre una ficha del equipo contrario la amenace pero no siga avanzando con la amenaza (casos de TORRE, ALFIL y REINA)
	if (bando == 1)
		ob = 0;
	if (bando == 0)
		ob = 1;
	for (int i = 1; i <= 8; i++) //i son las filas, j las columnas, es decir, que es [y,x]
	{
		for (int j = 1; j <= 8; j++)//bucle anidado para ver todo el tablero
		{
			if (tablero[j][i].bando == bando) //si es el mismo bando, declaramos las amenazas de ese color, cada vez que se haya un movimiento se hacen dos amenazar, uno por color)
			{
				if (tablero[j][i].clavada == false)//por tanto, solo amenazaran si no están clavadas
				{
					switch (tablero[j][i].ficha) //diferentes amenazas según el tipo de ficha
					{
					case Nombrefichas::PEON:
					{
						if (bando == 1)
						{
							if (tablero[j + 1][i + 1].bando != bando || tablero[j + 1][i + 1].bando == bando) //amenaza haya aliados o enemigos, pero solo amenaza en su zona de ataque
								tablero[j + 1][i + 1].amenazablanca = true; //seria un amenazablanca=true; el bando 2 será que no está ocupada ni por blancas ni negras
							if (tablero[j + 1][i - 1].bando != bando || tablero[j + 1][i - 1].bando == bando)
								tablero[j + 1][i - 1].amenazablanca = true;
						}
						if (bando == 0) //el peon es la unica pieza que según su bando ataca de forma distinta, "baja el tablero", ya que consideramos que estan arriba negras y abajo blancas
						{
							if (tablero[j - 1][i + 1].bando != bando || tablero[j - 1][i - 1].bando == bando) //amenaza haya aliados o enemigos, pero solo amenaza en su zona de ataque
								tablero[j - 1][i + 1].amenazanegra = true; //seria un amenazanegra=true; el bando 2 será que no está ocupada ni por blancas ni negras
							if (tablero[j - 1][i - 1].bando != bando || tablero[j - 1][i - 1].bando == bando)
								tablero[j - 1][i + 1].amenazanegra = true;
						}
					}
					case Nombrefichas::CABALLO:
					{
						if (tablero[j + 2][i + 1].bando != bando || tablero[j + 2][i + 1].bando == bando)
						{
							if (bando == 1)
								tablero[j + 2][i + 1].amenazablanca = true;
							if (bando == 0)
								tablero[j + 2][i + 1].amenazanegra = true;
						}
						if (tablero[j + 2][i - 1].bando != bando || tablero[j + 2][i - 1].bando == bando)
						{
							if (bando == 1)
								tablero[j + 2][i - 1].amenazablanca = true;
							if (bando == 0)
								tablero[j + 2][i - 1].amenazanegra = true;
						}
						if (tablero[j - 2][i + 1].bando != bando || tablero[j - 2][i + 1].bando == bando)
						{
							if (bando == 1)
								tablero[j - 2][i + 1].amenazablanca = true;
							if (bando == 0)
								tablero[j - 2][i + 1].amenazanegra = true;
						}
						if (tablero[j - 2][i - 1].bando != bando || tablero[j - 2][i - 1].bando == bando)
						{
							if (bando == 1)
								tablero[j - 2][i - 1].amenazablanca = true;
							if (bando == 0)
								tablero[j - 2][i - 1].amenazanegra = true;
						}
						if (tablero[j + 1][i + 2].bando != bando || tablero[j + 1][i + 2].bando == bando)
						{
							if (bando == 1)
								tablero[j + 1][i + 2].amenazablanca = true;
							if (bando == 0)
								tablero[j + 1][i + 2].amenazanegra = true;
						}
						if (tablero[j + 1][i - 2].bando != bando || tablero[j + 1][i - 2].bando == bando)
						{
							if (bando == 1)
								tablero[j + 1][i - 2].amenazablanca = true;
							if (bando == 0)
								tablero[j + 1][i - 2].amenazanegra = true;
						}
						if (tablero[j - 1][i + 2].bando != bando || tablero[j - 1][i + 2].bando == bando)
						{
							if (bando == 1)
								tablero[j - 1][i + 2].amenazablanca = true;
							if (bando == 0)
								tablero[j - 1][i + 2].amenazanegra = true;
						}
						if (tablero[j - 1][i - 2].bando != bando || tablero[j - 1][i - 2].bando == bando)
						{
							if (bando == 1)
								tablero[j - 1][i - 2].amenazablanca = true;
							if (bando == 0)
								tablero[j - 1][i - 2].amenazanegra = true;
						}
					}
					case Nombrefichas::TORRE:
					{
						//ARRIBA
						for (int k = j + 1; k <= 8; k++)
						{
							if (tablero[k][i].bando != bando || tablero[k][i].bando == bando)
							{
								if (bando == 1)
									tablero[k][i].amenazablanca = true;
								if (bando == 0)
									tablero[k][i].amenazanegra = true;
							}
							if (tablero[k][i].bando == ob || tablero[k][i].bando == bando)
							{
								if (bando == 1)
									tablero[k][i].amenazablanca = true;
								if (bando == 0)
									tablero[k][i].amenazanegra = true;
								k = 9;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}

						}
						//ABAJO
						for (int k = j - 1; k >= 1; k--)
						{
							if (tablero[k][i].bando != bando || tablero[k][i].bando == bando)
							{
								if (bando == 1)
									tablero[k][i].amenazablanca = true;
								if (bando == 0)
									tablero[k][i].amenazanegra = true;
							}
							if (tablero[k][i].bando == ob || tablero[k][i].bando == bando)
							{
								if (bando == 1)
									tablero[k][i].amenazablanca = true;
								if (bando == 0)
									tablero[k][i].amenazanegra = true;
								k = -1;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}

						}
						//IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (tablero[j][k].bando != bando || tablero[j][k].bando == bando)
							{
								if (bando == 1)
									tablero[j][k].amenazablanca = true;
								if (bando == 0)
									tablero[j][k].amenazanegra = true;
								k = -1;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
							if (tablero[j][k].bando == ob || tablero[k][j].bando == bando)
							{
								if (bando == 1)
									tablero[j][k].amenazablanca = true;
								if (bando == 0)
									tablero[j][k].amenazanegra = true;
								k = -1;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}

						}
						//DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (tablero[j][k].bando != bando || tablero[j][k].bando == bando)
							{
								if (bando == 1)
									tablero[j][k].amenazablanca = true;
								if (bando == 0)
									tablero[j][k].amenazanegra = true;
							}
							if (tablero[j][k].bando == ob || tablero[j][k].bando == bando)
							{
								if (bando == 1)
									tablero[j][k].amenazablanca = true;
								if (bando == 0)
									tablero[j][k].amenazanegra = true;
								k = 9;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás

							}

						}
					}
					case Nombrefichas::ALFIL:
					{
						//ARRIBA DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (tablero[j + (k - i)][k].bando != bando || tablero[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									tablero[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									tablero[j + (k - i)][k].amenazanegra = true;

							}

							if (tablero[j + (k - i)][k].bando == ob || tablero[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									tablero[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									tablero[j + (k - i)][k].amenazanegra = true;
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
						}
						//ARRIBA IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (tablero[j - (k - i)][k].bando != bando || tablero[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									tablero[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									tablero[j - (k - i)][k].amenazanegra = true;

							}
							if (tablero[j - (k - i)][k].bando == ob || tablero[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									tablero[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									tablero[j - (k - i)][k].amenazanegra = true;
								k = -1;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
						}
						//ABAJO DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (tablero[j - (k - i)][k].bando != bando || tablero[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									tablero[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									tablero[j - (k - i)][k].amenazanegra = true;
							}
							if (tablero[j - (k - i)][k].bando == ob || tablero[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									tablero[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									tablero[j - (k - i)][k].amenazanegra = true;
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
						}
						//ABAJO IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (tablero[j + (k - i)][k].bando != bando || tablero[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									tablero[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									tablero[j + (k - i)][k].amenazanegra = true;
							}
							if (tablero[j + (k - i)][k].bando == ob || tablero[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									tablero[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									tablero[j + (k - i)][k].amenazanegra = true;
								k = -1;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
						}
					}
					case Nombrefichas::REINA: //suma de TORRE y ALFIL
					{
						//ARRIBA
						for (int k = j + 1; k <= 8; k++)
						{
							if (tablero[k][i].bando != bando || tablero[k][i].bando == bando)
							{
								if (bando == 1)
									tablero[k][i].amenazablanca = true;
								if (bando == 0)
									tablero[k][i].amenazanegra = true;
							}
							if (tablero[k][i].bando == ob || tablero[k][i].bando == bando)
							{
								if (bando == 1)
									tablero[k][i].amenazablanca = true;
								if (bando == 0)
									tablero[k][i].amenazanegra = true;
								k = 9;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}

						}
						//ABAJO
						for (int k = j - 1; k >= 1; k--)
						{
							if (tablero[k][i].bando != bando || tablero[k][i].bando == bando)
							{
								if (bando == 1)
									tablero[k][i].amenazablanca = true;
								if (bando == 0)
									tablero[k][i].amenazanegra = true;
							}
							if (tablero[k][i].bando == ob || tablero[k][i].bando == bando)
							{
								if (bando == 1)
									tablero[k][i].amenazablanca = true;
								if (bando == 0)
									tablero[k][i].amenazanegra = true;
								k = -1;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}

						}
						//IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (tablero[j][k].bando != bando || tablero[j][k].bando == bando)
							{
								if (bando == 1)
									tablero[j][k].amenazablanca = true;
								if (bando == 0)
									tablero[j][k].amenazanegra = true;
								k = -1;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
							if (tablero[j][k].bando == ob || tablero[k][j].bando == bando)
							{
								if (bando == 1)
									tablero[j][k].amenazablanca = true;
								if (bando == 0)
									tablero[j][k].amenazanegra = true;
								k = -1;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}

						}
						//DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (tablero[j][k].bando != bando || tablero[j][k].bando == bando)
							{
								if (bando == 1)
									tablero[j][k].amenazablanca = true;
								if (bando == 0)
									tablero[j][k].amenazanegra = true;
							}
							if (tablero[j][k].bando == ob || tablero[j][k].bando == bando)
							{
								if (bando == 1)
									tablero[j][k].amenazablanca = true;
								if (bando == 0)
									tablero[j][k].amenazanegra = true;
								k = 9;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás

							}

						}
						//ARRIBA DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (tablero[j + (k - i)][k].bando != bando || tablero[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									tablero[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									tablero[j + (k - i)][k].amenazanegra = true;

							}

							if (tablero[j + (k - i)][k].bando == ob || tablero[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									tablero[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									tablero[j + (k - i)][k].amenazanegra = true;
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
						}
						//ARRIBA IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (tablero[j - (k - i)][k].bando != bando || tablero[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									tablero[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									tablero[j - (k - i)][k].amenazanegra = true;

							}
							if (tablero[j - (k - i)][k].bando == ob || tablero[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									tablero[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									tablero[j - (k - i)][k].amenazanegra = true;
								k = -1;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
						}
						//ABAJO DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (tablero[j - (k - i)][k].bando != bando || tablero[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									tablero[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									tablero[j - (k - i)][k].amenazanegra = true;
							}
							if (tablero[j - (k - i)][k].bando == ob || tablero[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									tablero[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									tablero[j - (k - i)][k].amenazanegra = true;
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
						}
						//ABAJO IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (tablero[j + (k - i)][k].bando != bando || tablero[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									tablero[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									tablero[j + (k - i)][k].amenazanegra = true;
							}
							if (tablero[j + (k - i)][k].bando == ob || tablero[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									tablero[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									tablero[j + (k - i)][k].amenazanegra = true;
								k = -1;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
						}

					}
					case Nombrefichas::REY:
					{
						if (tablero[j][i + 1].bando != bando || tablero[j][i + 1].bando == bando)
						{
							if (bando == 1)
								tablero[j][i + 1].amenazablanca = true;
							if (bando == 0)
								tablero[j][i + 1].amenazanegra = true;
						}
						if (tablero[j + 1][i + 1].bando != bando || tablero[j + 1][i + 1].bando == bando)
						{
							if (bando == 1)
								tablero[j + 1][i + 1].amenazablanca = true;
							if (bando == 0)
								tablero[j + 1][i + 1].amenazanegra = true;
						}
						if (tablero[j - 1][i + 1].bando != bando || tablero[j - 1][i + 1].bando == bando)
						{
							if (bando == 1)
								tablero[j - 1][i + 1].amenazablanca = true;
							if (bando == 0)
								tablero[j - 1][i + 1].amenazanegra = true;
						}
						if (tablero[j][i - 1].bando != bando || tablero[j][i - 1].bando == bando)
						{
							if (bando == 1)
								tablero[j][i - 1].amenazablanca = true;
							if (bando == 0)
								tablero[j][i - 1].amenazanegra = true;
						}
						if (tablero[j + 1][i - 1].bando != bando || tablero[j + 1][i - 1].bando == bando)
						{
							if (bando == 1)
								tablero[j + 1][i - 1].amenazablanca = true;
							if (bando == 0)
								tablero[j + 1][i - 1].amenazanegra = true;
						}
						if (tablero[j - 1][i - 1].bando != bando || tablero[j - 1][i - 1].bando == bando)
						{
							if (bando == 1)
								tablero[j - 1][i - 1].amenazablanca = true;
							if (bando == 0)
								tablero[j - 1][i - 1].amenazanegra = true;
						}
						if (tablero[j + 1][i].bando != bando || tablero[j + 1][i].bando == bando)
						{
							if (bando == 1)
								tablero[j + 1][i].amenazablanca = true;
							if (bando == 0)
								tablero[j + 1][i].amenazanegra = true;
						}
						if (tablero[j - 1][i].bando != bando || tablero[j - 1][i].bando == bando)
						{
							if (bando == 1)
								tablero[j - 1][i].amenazablanca = true;
							if (bando == 0)
								tablero[j - 1][i].amenazanegra = true;
						}
					}
					case Nombrefichas::VACIO: {}//si no hay ninguna ficha en la casilla, obviamente desde esa casilla no surgirá ninguna amenaza
					}
				}
			}
		}
	}
}

bool juego::clavadaficha(int bando, int ob, int i, int j)
{

	if (tablero[j][i].bando == bando)//se comprueba si la pieza en la casilla es del bando que estamos comprobando las clavadas
	{
		if (((tablero[j][i].amenazanegra == true) && ((tablero[j][i].bando == bando) && (bando == 1))) || (((tablero[j][i].amenazablanca == true) && (tablero[j][i].bando == bando)) && (bando == 0)))//en caso de que la casilla esté ocupada por tu bando y amenazada, comprobamos por donde la amenazan para ver si es una ficha con trayectoria
		{
			//comprobamos si le amenazan por la derecha
			for (int k = i + 1; k <= 8; k++)
			{
				if (((tablero[j][k].amenazanegra == false) && (bando == 1)) || ((tablero[j][k].amenazablanca == false) && (bando == 0)))
					k = 9;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una torre
				if (((tablero[j][k].amenazanegra == true) && (bando == 1)) || ((tablero[j][k].amenazablanca == true) && (bando == 0)))
				{//comprueba si en la siguiente casilla está la torre/reina que amenaza
					if (tablero[k + 1][j].ficha == Nombrefichas::TORRE || tablero[k + 1][j].ficha == Nombrefichas::REINA) //en caso que esté amenazado por una torre o reina, comprobamos si el rey está amenazado
					{
						for (int l = i; l >= 1; l--)//miramos a la izquierda de la ficha
						{
							if (tablero[l][j].ficha == Nombrefichas::ALFIL || tablero[l][j].ficha == Nombrefichas::CABALLO || tablero[l][j].ficha == Nombrefichas::PEON || tablero[l][j].ficha == Nombrefichas::REINA || tablero[l][j].ficha == Nombrefichas::TORRE)
								l = -1;
							if (tablero[l][j].ficha == Nombrefichas::REY)
								return true; //en caso de que sea el rey, estará clavada, si no es ni ficha de las nombradas o rey, el bucle no hará nada
						}
					}
					if (tablero[k + 1][j].ficha == Nombrefichas::ALFIL || tablero[k + 1][j].ficha == Nombrefichas::CABALLO || tablero[k + 1][j].ficha == Nombrefichas::PEON || tablero[k + 1][j].ficha == Nombrefichas::REY)
						k = 9;
				}
			}
			//comprobamos si le amenazan por la izquierda 
			for (int k = i - 1; k >= 1; k--)
			{
				if (((tablero[k][j].amenazanegra == false) && (bando == 1)) || ((tablero[k][j].amenazablanca == false) && (bando == 0)))
					k = -1;//si no está amenazado en alguna de las casillas intermedias no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una torre
				if (((tablero[k][j].amenazanegra == true) && (bando == 1)) || ((tablero[k][j].amenazablanca == true) && (bando == 0)))
				{
					if (tablero[k - 1][j].ficha == Nombrefichas::TORRE || tablero[k - 1][j].ficha == Nombrefichas::REINA) //en caso que esté amenazado por una torre o reina, comprobamos si el rey está amenazado
					{
						for (int l = i + 1; l <= 8; l++)//miramos a la derecha de la ficha
						{
							if (tablero[l][j].ficha == Nombrefichas::ALFIL || tablero[l][j].ficha == Nombrefichas::CABALLO || tablero[l][j].ficha == Nombrefichas::PEON || tablero[l][j].ficha == Nombrefichas::REINA || tablero[l][j].ficha == Nombrefichas::TORRE)
								l = 9;
							if ((tablero[l][j].ficha == Nombrefichas::REY) && (tablero[l][j].bando == bando))
							{
								return true;
							}

						}
					}
					if (tablero[k - 1][j].ficha == Nombrefichas::ALFIL || tablero[k - 1][j].ficha == Nombrefichas::CABALLO || tablero[k - 1][j].ficha == Nombrefichas::PEON || tablero[k - 1][j].ficha == Nombrefichas::REY)
						k = -1;//al llegar a una ficha que bloquea se deja de mirar esa direccion

				}
			}
			//comprobamos si le amenazan por encima 
			for (int k = j + 1; k <= 8; k++)
			{
				if (((tablero[k][i].amenazanegra == false) && (bando == 1)) || ((tablero[k][i].amenazablanca == false) && (bando == 0)))
					k = 9;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o torre
				if (((tablero[k][i].amenazanegra == true) && (bando == 1)) || ((tablero[k][i].amenazablanca == true) && (bando == 0)))
				{
					if (((tablero[k + 1][i].ficha == Nombrefichas::TORRE) && (tablero[k - 1][i].bando == ob)) || ((tablero[k - 1][i].ficha == Nombrefichas::REINA) && (tablero[k - 1][i].bando == ob))) //en caso que esté amenazado por una torre o reina, comprobamos si el rey está amenazado
					{
						for (int l = j - 1; l >= 1; l--)//miramos por debajo de la ficha
						{
							if (tablero[l][i].ficha == Nombrefichas::ALFIL || tablero[l][i].ficha == Nombrefichas::CABALLO || tablero[l][i].ficha == Nombrefichas::PEON || tablero[l][i].ficha == Nombrefichas::REINA || tablero[l][i].ficha == Nombrefichas::TORRE)
								l = -1;
							if (tablero[l][i].ficha == Nombrefichas::REY)
							{
								return true;
							}

						}
					}
					if (tablero[k + 1][i].ficha == Nombrefichas::ALFIL || tablero[k - 1][i].ficha == Nombrefichas::CABALLO || tablero[k - 1][i].ficha == Nombrefichas::PEON || tablero[k - 1][i].ficha == Nombrefichas::REY)
					{
						k = 9;//al llegar a una ficha que bloquea se deja de mirar esa direccion
					}
				}
			}
			//comprobamos si le amenazan por debajo
			for (int k = j - 1; k >= 1; k--)
			{
				if (((tablero[k][i].amenazanegra == false) && (bando == 1)) || ((tablero[k][i].amenazablanca == false) && (bando == 0)))
					k = -1;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o torre
				if (((tablero[k][i].amenazanegra == true) && (bando == 1)) || ((tablero[k][i].amenazablanca == true) && (bando == 0)))
				{
					if (((tablero[k - 1][i].ficha == Nombrefichas::TORRE) && (tablero[k - 1][i].bando == ob)) || ((tablero[k - 1][i].ficha == Nombrefichas::REINA) && (tablero[k - 1][i].bando == ob))) //en caso que esté amenazado por una torre o reina, comprobamos si el rey está amenazado
					{
						for (int l = j + 1; l <= 8; l++)//miramos por encima de la ficha
						{
							if (tablero[l][i].ficha == Nombrefichas::ALFIL || tablero[l][i].ficha == Nombrefichas::CABALLO || tablero[l][i].ficha == Nombrefichas::PEON || tablero[l][i].ficha == Nombrefichas::REINA || tablero[l][i].ficha == Nombrefichas::TORRE)
								l = 9;
							if ((tablero[l][i].ficha == Nombrefichas::REY) && (tablero[l][j].bando == bando))
							{
								return true;
							}

						}
					}
					if (tablero[k - 1][i].ficha == Nombrefichas::ALFIL || tablero[k - 1][i].ficha == Nombrefichas::CABALLO || tablero[k - 1][i].ficha == Nombrefichas::PEON || tablero[k - 1][i].ficha == Nombrefichas::REY)
					{
						k = -1;//al llegar a una ficha que bloquea se deja de mirar esa direccion
					}
				}
			}
			//comprobamos si le amenazan por la diagonal inferior izquierda
			for (int k = i - 1; k >= 1; k--)
			{
				if (((tablero[j - (i - k)][k].amenazanegra == false) && (bando == 1)) || ((tablero[j - (i - k)][k].amenazablanca == false) && (bando == 0)))
					k = -1;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o alfil
				if (((tablero[j - (i - k)][k].amenazanegra == true) && (bando == 1)) || ((tablero[j - (i - k)][k].amenazablanca == true) && (bando == 0)))
				{//comprueba si en la siguiente casilla está el alfil/reina que amenaza
					if (((tablero[j - (i - k)][k - 1].ficha == Nombrefichas::ALFIL) && (tablero[j - (i - k)][k - 1].bando == ob)) || ((tablero[j - (i - k)][k - 1].ficha == Nombrefichas::REINA) && (tablero[j - (i - k)][k - 1].bando == ob))) //en caso que esté amenazado por un alfil o reina, comprobamos si el rey está amenazado
					{
						for (int l = i + 1; l <= 8; l++)//miramos arriba a la derecha
						{
							if (tablero[j + (l - i)][l].ficha == Nombrefichas::ALFIL || tablero[j + (l - i)][l].ficha == Nombrefichas::CABALLO || tablero[j + (l - i)][l].ficha == Nombrefichas::PEON || tablero[j + (l - i)][l].ficha == Nombrefichas::REINA || tablero[j + (l - i)][l].ficha == Nombrefichas::TORRE)
								l = 9; //está bloqueado el camino, asi que sale del bucle
							if ((tablero[j + (l - i)][l].ficha == Nombrefichas::REY) && (tablero[j + (l - i)][l].bando == bando))
							{
								return true;
							}
						}
					}
					if (tablero[j - (i - k) - 1][k - 1].ficha == Nombrefichas::TORRE || tablero[j - (i - k) - 1][k - 1].ficha == Nombrefichas::CABALLO || tablero[j - (i - k) - 1][k - 1].ficha == Nombrefichas::PEON || tablero[j - (i - k) - 1][k - 1].ficha == Nombrefichas::REY)
					{
						k = -1;//al llegar a una ficha que bloquea se deja de mirar esa direccion
					}
				}
			}
			//comprobamos si le amenazan por la diagonal inferior derecha
			for (int k = i + 1; k <= 8; k++)
			{
				if (((tablero[j - (k - i)][k].amenazanegra == false) && (bando == 1)) || ((tablero[j - (k - i)][k].amenazablanca == false) && (bando == 0)))
					k = 9;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o alfil
				if (((tablero[j - (k - i)][k].amenazanegra == true) && (bando == 1)) || ((tablero[j - (k - i)][k].amenazablanca == true) && (bando == 0)))
				{//comprueba si en la siguiente casilla está el alfil/reina que amenaza
					if (tablero[j - (k - i) - 1][k + 1].ficha == Nombrefichas::ALFIL || tablero[j - (k - i) - 1][k + 1].ficha == Nombrefichas::REINA) //en caso que esté amenazado por un alfil o reina, comprobamos si el rey está amenazado
					{
						for (int l = i - 1; l >= 1; l--)//miramos arriba a izquierda
						{
							if (tablero[j + (i - l)][l].ficha == Nombrefichas::ALFIL || tablero[j + (i - l)][l].ficha == Nombrefichas::CABALLO || tablero[j + (i - l)][l].ficha == Nombrefichas::PEON || tablero[j + (i - l)][l].ficha == Nombrefichas::REINA || tablero[j + (i - l)][l].ficha == Nombrefichas::TORRE)
								l = -1; //está bloqueado el camino, asi que sale del bucle
							if ((tablero[j + (i - l)][l].ficha == Nombrefichas::REY) && (tablero[j + (i - l)][l].bando == bando))
							{
								return true;
							}
						}
					}
					if (tablero[j - (k - i) - 1][k + 1].ficha == Nombrefichas::TORRE || tablero[j - (k - i) - 1][k + 1].ficha == Nombrefichas::CABALLO || tablero[j - (k - i) - 1][k + 1].ficha == Nombrefichas::PEON || ((tablero[j - (k - i) - 1][k + 1].ficha == Nombrefichas::REY) && (tablero[j - (k - i) - 1][k + 1].bando == ob)))
					{
						k = 9;//al llegar a una ficha que bloquea se deja de mirar esa direccion
					}
				}
			}
			//comprobamos si le amenazan por la diagonal superior izquierda
			for (int k = i - 1; k >= 1; k--)
			{
				if (((tablero[j + (i - k)][k].amenazanegra == false) && (bando == 1)) || ((tablero[j + (i - k)][k].amenazablanca == false) && (bando == 0)))
					k = -1;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o alfil
				if (((tablero[j + (i - k)][k].amenazanegra == true) && (bando == 1)) || ((tablero[j + (i - k)][k].amenazablanca == true) && (bando == 0)))
				{//comprueba si en la siguiente casilla está el alfil/reina que amenaza
					if (tablero[j + (i - k) + 1][k - 1].ficha == Nombrefichas::ALFIL || tablero[j + (i - k) + 1][k - 1].ficha == Nombrefichas::REINA) //en caso que esté amenazado por un alfil o reina, comprobamos si el rey está amenazado
					{
						for (int l = i + 1; l <= 8; l++)//miramos abajo a la derecha
						{
							if (tablero[j - (l - i)][l].ficha == Nombrefichas::ALFIL || tablero[j - (l - i)][l].ficha == Nombrefichas::CABALLO || tablero[j - (l - i)][l].ficha == Nombrefichas::PEON || tablero[j - (l - i)][l].ficha == Nombrefichas::REINA || tablero[j - (l - i)][l].ficha == Nombrefichas::TORRE)
								l = 9; //está bloqueado el camino, asi que sale del bucle
							if ((tablero[j - (l - i)][l].ficha == Nombrefichas::REY) && (tablero[j - (l - i)][l].bando == bando))
							{
								return true;
							}
						}
					}
					if (tablero[j + (i - k) + 1][k - 1].ficha == Nombrefichas::TORRE || tablero[j + (i - k) + 1][k - 1].ficha == Nombrefichas::CABALLO || tablero[j + (i - k) + 1][k - 1].ficha == Nombrefichas::PEON || tablero[j + (i - k) + 1][k - 1].ficha == Nombrefichas::REY)
					{
						tablero[j][i].clavada = false; //añadido para evitar coincidencias en las que pueda parecer que está amenazado por este tipo de pieza pero haya un enemigo distinto bloqueando el camino
						k = -1;//al llegar a una ficha que bloquea se deja de mirar esa direccion
					}
				}
			}
			//comprobamos si le amenazan por la diagonal superior derecha
			for (int k = i + 1; k <= 8; k++)
			{
				if (((tablero[j + (k - i)][k].amenazanegra == false) && (bando == 1)) || ((tablero[j + (k - i)][k].amenazablanca == false) && (bando == 0)))
					k = 9;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o alfil
				if (((tablero[j + (k - i)][k].amenazanegra == true) && (bando == 1)) || ((tablero[j + (k - i)][k].amenazablanca == true) && (bando == 0)))
				{//comprueba si en la siguiente casilla está el alfil/reina que amenaza
					if (((tablero[j + (k - i) + 1][k + 1].ficha == Nombrefichas::ALFIL) && (tablero[j + (k - i) + 1][k + 1].bando == ob)) || ((tablero[j + (k - i) + 1][k + 1].ficha == Nombrefichas::ALFIL) && (tablero[j + (k - i) + 1][k + 1].bando == ob))) //en caso que esté amenazado por un alfil o reina, comprobamos si el rey está amenazado
					{//Si está la amenaza, comprueba detras de la pieza para ver si esta tu rey y por tanto estas clavada
						for (int l = i - 1; l >= 1; l--)//miramos abajo a la izquierda
						{
							if (tablero[j - (i - l)][l].ficha == Nombrefichas::ALFIL || tablero[j - (i - l)][l].ficha == Nombrefichas::CABALLO || tablero[j - (i - l)][l].ficha == Nombrefichas::PEON || tablero[j - (i - l)][l].ficha == Nombrefichas::REINA || tablero[j - (i - l)][l].ficha == Nombrefichas::TORRE)
								l = -1; //está bloqueado el camino, asi que sale del bucle
							if ((tablero[j - (i - l)][l].ficha == Nombrefichas::REY) && (tablero[j - (i - l)][l].bando == bando))//si hay un rey, del color de tus fichas, está clavada
							{
								return true;
							}
						}
					}
					if (tablero[j + (k - i) + 1][k + 1].ficha == Nombrefichas::TORRE || tablero[j + (k - i) + 1][k + 1].ficha == Nombrefichas::CABALLO || tablero[j + (k - i) + 1][k + 1].ficha == Nombrefichas::PEON || ((tablero[j + (k - i) + 1][k + 1].ficha == Nombrefichas::REY) && (tablero[j + (k - i) + 1][k + 1].bando == ob)))//con esta ultima cond evitamos que confunda el rey atacante con el tuyo
					{
						//añadido para evitar coincidencias en las que pueda parecer que está amenazado por este tipo de pieza pero haya un enemigo distinto bloqueando el camino
						k = 9;//al llegar a una ficha que bloquea se deja de mirar esa direccion
					}
				}
			}
			return false; //en caso de que no haya encontrado ninguna condicion de clavada tras comprobar todas las posibilidades, retorna el valor booleano false.
		}
	}
	else
		return false;
}

void juego::clavada(int bando)
{
	int ob;
	bool resultado = false;
	if (bando == 1)
		ob = 0;
	if (bando == 0)
		ob = 1;
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)//con estos bucles anidados comprobaremos en todas las casillas del tablero si la pieza está amenazada
		{
			resultado = clavadaficha(bando, ob, i, j); //usando esta estructura conseguimos que en el momento en el que resulte como clavada salga del bucle y pase a la siguiente casilla
			tablero[j][i].clavada = resultado;
		}
	}
}
