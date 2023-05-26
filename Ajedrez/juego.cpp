#include "juego.h"
#include "Fichas.h"
#include"Peon.h"
#include"Torre.h"
#include"Caballo.h"
#include"Alfil.h"
#include"Rey.h"
#include"Reina.h"
#include<iostream>
using namespace std;

void juego::limpiaramenazas()
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			casilla[j][i].amenazablanca = false;
			casilla[j][i].amenazanegra = false;
		}
	}
}


void juego::amenazar(int bando)
{
	int entry = 0;//entrada al switch case
	int ob;//ob = otro bando, se usará para que cuando encuentre una ficha del equipo contrario la amenace pero no siga avanzando con la amenaza (casos de TORRE, ALFIL y REINA)
	if (bando == 1)
		ob = 0;
	if (bando == 0)
		ob = 1;
	for (int i = 1; i <= 8; i++) //i son las filas, j las columnas, es decir, que es [y,x]
	{
		for (int j = 1; j <= 8; j++)//bucle anidado para ver todo el tablero
		{
			if (casilla[j][i].bando == bando) //si es el mismo bando, declaramos las amenazas de ese color, cada vez que se haya un movimiento se hacen dos amenazar, uno por color)
			{
				if (casilla[j][i].clavada == false)//por tanto, solo amenazaran si no están clavadas
				{
					
					if (casilla[j][i].ficha.getFicha() == Nombrefichas::PEON)
						entry = 1;
					if (casilla[j][i].ficha.getFicha() == Nombrefichas::CABALLO)
						entry = 2;
					if (casilla[j][i].ficha.getFicha() == Nombrefichas::TORRE)
						entry = 3;
					if (casilla[j][i].ficha.getFicha() == Nombrefichas::ALFIL)
						entry = 4;
					if (casilla[j][i].ficha.getFicha() == Nombrefichas::REINA)
						entry = 5;
					if (casilla[j][i].ficha.getFicha() == Nombrefichas::REY)
						entry = 6;
					if (casilla[j][i].ficha.getFicha() == Nombrefichas::VACIO)
						entry = 0;

					switch (entry) //diferentes amenazas según el tipo de ficha
					{
					case 1://peon
					{
						if (bando == 1)
						{
							if (casilla[j + 1][i + 1].bando != bando || casilla[j + 1][i + 1].bando == bando) //amenaza haya aliados o enemigos, pero solo amenaza en su zona de ataque
								casilla[j + 1][i + 1].amenazablanca = true; //seria un amenazablanca=true; el bando 2 será que no está ocupada ni por blancas ni negras
							if (casilla[j + 1][i - 1].bando != bando || casilla[j + 1][i - 1].bando == bando)
								casilla[j + 1][i - 1].amenazablanca = true;
						}
						if (bando == 0) //el peon es la unica pieza que según su bando ataca de forma distinta, "baja el tablero", ya que consideramos que estan arriba negras y abajo blancas
						{
							if (casilla[j - 1][i + 1].bando != bando || casilla[j - 1][i - 1].bando == bando) //amenaza haya aliados o enemigos, pero solo amenaza en su zona de ataque
								casilla[j - 1][i + 1].amenazanegra = true; //seria un amenazanegra=true; el bando 2 será que no está ocupada ni por blancas ni negras
							if (casilla[j - 1][i - 1].bando != bando || casilla[j - 1][i - 1].bando == bando)
								casilla[j - 1][i + 1].amenazanegra = true;
						}
					}
					case 2://caballo
					{
						if (casilla[j + 2][i + 1].bando != bando || casilla[j + 2][i + 1].bando == bando)
						{
							if (bando == 1)
								casilla[j + 2][i + 1].amenazablanca = true;
							if (bando == 0)
								casilla[j + 2][i + 1].amenazanegra = true;
						}
						if (casilla[j + 2][i - 1].bando != bando || casilla[j + 2][i - 1].bando == bando)
						{
							if (bando == 1)
								casilla[j + 2][i - 1].amenazablanca = true;
							if (bando == 0)
								casilla[j + 2][i - 1].amenazanegra = true;
						}
						if (casilla[j - 2][i + 1].bando != bando || casilla[j - 2][i + 1].bando == bando)
						{
							if (bando == 1)
								casilla[j - 2][i + 1].amenazablanca = true;
							if (bando == 0)
								casilla[j - 2][i + 1].amenazanegra = true;
						}
						if (casilla[j - 2][i - 1].bando != bando || casilla[j - 2][i - 1].bando == bando)
						{
							if (bando == 1)
								casilla[j - 2][i - 1].amenazablanca = true;
							if (bando == 0)
								casilla[j - 2][i - 1].amenazanegra = true;
						}
						if (casilla[j + 1][i + 2].bando != bando || casilla[j + 1][i + 2].bando == bando)
						{
							if (bando == 1)
								casilla[j + 1][i + 2].amenazablanca = true;
							if (bando == 0)
								casilla[j + 1][i + 2].amenazanegra = true;
						}
						if (casilla[j + 1][i - 2].bando != bando || casilla[j + 1][i - 2].bando == bando)
						{
							if (bando == 1)
								casilla[j + 1][i - 2].amenazablanca = true;
							if (bando == 0)
								casilla[j + 1][i - 2].amenazanegra = true;
						}
						if (casilla[j - 1][i + 2].bando != bando || casilla[j - 1][i + 2].bando == bando)
						{
							if (bando == 1)
								casilla[j - 1][i + 2].amenazablanca = true;
							if (bando == 0)
								casilla[j - 1][i + 2].amenazanegra = true;
						}
						if (casilla[j - 1][i - 2].bando != bando || casilla[j - 1][i - 2].bando == bando)
						{
							if (bando == 1)
								casilla[j - 1][i - 2].amenazablanca = true;
							if (bando == 0)
								casilla[j - 1][i - 2].amenazanegra = true;
						}
					}
					case 3://torre
					{
						//ARRIBA
						for (int k = j + 1; k <= 8; k++)
						{
							if (casilla[k][i].bando != bando || casilla[k][i].bando == bando)
							{
								if (bando == 1)
									casilla[k][i].amenazablanca = true;
								if (bando == 0)
									casilla[k][i].amenazanegra = true;
							}
							if (casilla[k][i].bando == ob || casilla[k][i].bando == bando)
							{
								if (bando == 1)
									casilla[k][i].amenazablanca = true;
								if (bando == 0)
									casilla[k][i].amenazanegra = true;
								k = 9;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}

						}
						//ABAJO
						for (int k = j - 1; k >= 1; k--)
						{
							if (casilla[k][i].bando != bando || casilla[k][i].bando == bando)
							{
								if (bando == 1)
									casilla[k][i].amenazablanca = true;
								if (bando == 0)
									casilla[k][i].amenazanegra = true;
							}
							if (casilla[k][i].bando == ob || casilla[k][i].bando == bando)
							{
								if (bando == 1)
									casilla[k][i].amenazablanca = true;
								if (bando == 0)
									casilla[k][i].amenazanegra = true;
								k = -1;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}

						}
						//IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (casilla[j][k].bando != bando || casilla[j][k].bando == bando)
							{
								if (bando == 1)
									casilla[j][k].amenazablanca = true;
								if (bando == 0)
									casilla[j][k].amenazanegra = true;
								k = -1;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
							if (casilla[j][k].bando == ob || casilla[k][j].bando == bando)
							{
								if (bando == 1)
									casilla[j][k].amenazablanca = true;
								if (bando == 0)
									casilla[j][k].amenazanegra = true;
								k = -1;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}

						}
						//DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (casilla[j][k].bando != bando || casilla[j][k].bando == bando)
							{
								if (bando == 1)
									casilla[j][k].amenazablanca = true;
								if (bando == 0)
									casilla[j][k].amenazanegra = true;
							}
							if (casilla[j][k].bando == ob || casilla[j][k].bando == bando)
							{
								if (bando == 1)
									casilla[j][k].amenazablanca = true;
								if (bando == 0)
									casilla[j][k].amenazanegra = true;
								k = 9;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás

							}

						}
					}
					case 4://alfil
					{
						//ARRIBA DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (casilla[j + (k - i)][k].bando != bando || casilla[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									casilla[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									casilla[j + (k - i)][k].amenazanegra = true;

							}

							if (casilla[j + (k - i)][k].bando == ob || casilla[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									casilla[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									casilla[j + (k - i)][k].amenazanegra = true;
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
						}
						//ARRIBA IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (casilla[j - (k - i)][k].bando != bando || casilla[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									casilla[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									casilla[j - (k - i)][k].amenazanegra = true;

							}
							if (casilla[j - (k - i)][k].bando == ob || casilla[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									casilla[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									casilla[j - (k - i)][k].amenazanegra = true;
								k = -1;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
						}
						//ABAJO DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (casilla[j - (k - i)][k].bando != bando || casilla[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									casilla[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									casilla[j - (k - i)][k].amenazanegra = true;
							}
							if (casilla[j - (k - i)][k].bando == ob || casilla[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									casilla[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									casilla[j - (k - i)][k].amenazanegra = true;
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
						}
						//ABAJO IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (casilla[j + (k - i)][k].bando != bando || casilla[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									casilla[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									casilla[j + (k - i)][k].amenazanegra = true;
							}
							if (casilla[j + (k - i)][k].bando == ob || casilla[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									casilla[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									casilla[j + (k - i)][k].amenazanegra = true;
								k = -1;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
						}
					}
					case 5: //reina, suma de TORRE y ALFIL
					{
						//ARRIBA
						for (int k = j + 1; k <= 8; k++)
						{
							if (casilla[k][i].bando != bando || casilla[k][i].bando == bando)
							{
								if (bando == 1)
									casilla[k][i].amenazablanca = true;
								if (bando == 0)
									casilla[k][i].amenazanegra = true;
							}
							if (casilla[k][i].bando == ob || casilla[k][i].bando == bando)
							{
								if (bando == 1)
									casilla[k][i].amenazablanca = true;
								if (bando == 0)
									casilla[k][i].amenazanegra = true;
								k = 9;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}

						}
						//ABAJO
						for (int k = j - 1; k >= 1; k--)
						{
							if (casilla[k][i].bando != bando || casilla[k][i].bando == bando)
							{
								if (bando == 1)
									casilla[k][i].amenazablanca = true;
								if (bando == 0)
									casilla[k][i].amenazanegra = true;
							}
							if (casilla[k][i].bando == ob || casilla[k][i].bando == bando)
							{
								if (bando == 1)
									casilla[k][i].amenazablanca = true;
								if (bando == 0)
									casilla[k][i].amenazanegra = true;
								k = -1;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}

						}
						//IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (casilla[j][k].bando != bando || casilla[j][k].bando == bando)
							{
								if (bando == 1)
									casilla[j][k].amenazablanca = true;
								if (bando == 0)
									casilla[j][k].amenazanegra = true;
								k = -1;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
							if (casilla[j][k].bando == ob || casilla[k][j].bando == bando)
							{
								if (bando == 1)
									casilla[j][k].amenazablanca = true;
								if (bando == 0)
									casilla[j][k].amenazanegra = true;
								k = -1;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}

						}
						//DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (casilla[j][k].bando != bando || casilla[j][k].bando == bando)
							{
								if (bando == 1)
									casilla[j][k].amenazablanca = true;
								if (bando == 0)
									casilla[j][k].amenazanegra = true;
							}
							if (casilla[j][k].bando == ob || casilla[j][k].bando == bando)
							{
								if (bando == 1)
									casilla[j][k].amenazablanca = true;
								if (bando == 0)
									casilla[j][k].amenazanegra = true;
								k = 9;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás

							}

						}
						//ARRIBA DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (casilla[j + (k - i)][k].bando != bando || casilla[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									casilla[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									casilla[j + (k - i)][k].amenazanegra = true;

							}

							if (casilla[j + (k - i)][k].bando == ob || casilla[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									casilla[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									casilla[j + (k - i)][k].amenazanegra = true;
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
						}
						//ARRIBA IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (casilla[j - (k - i)][k].bando != bando || casilla[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									casilla[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									casilla[j - (k - i)][k].amenazanegra = true;

							}
							if (casilla[j - (k - i)][k].bando == ob || casilla[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									casilla[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									casilla[j - (k - i)][k].amenazanegra = true;
								k = -1;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
						}
						//ABAJO DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (casilla[j - (k - i)][k].bando != bando || casilla[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									casilla[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									casilla[j - (k - i)][k].amenazanegra = true;
							}
							if (casilla[j - (k - i)][k].bando == ob || casilla[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									casilla[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									casilla[j - (k - i)][k].amenazanegra = true;
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
						}
						//ABAJO IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (casilla[j + (k - i)][k].bando != bando || casilla[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									casilla[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									casilla[j + (k - i)][k].amenazanegra = true;
							}
							if (casilla[j + (k - i)][k].bando == ob || casilla[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									casilla[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									casilla[j + (k - i)][k].amenazanegra = true;
								k = -1;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detrás
							}
						}

					}
					case 6://rey
					{
						if (casilla[j][i + 1].bando != bando || casilla[j][i + 1].bando == bando)
						{
							if (bando == 1)
								casilla[j][i + 1].amenazablanca = true;
							if (bando == 0)
								casilla[j][i + 1].amenazanegra = true;
						}
						if (casilla[j + 1][i + 1].bando != bando || casilla[j + 1][i + 1].bando == bando)
						{
							if (bando == 1)
								casilla[j + 1][i + 1].amenazablanca = true;
							if (bando == 0)
								casilla[j + 1][i + 1].amenazanegra = true;
						}
						if (casilla[j - 1][i + 1].bando != bando || casilla[j - 1][i + 1].bando == bando)
						{
							if (bando == 1)
								casilla[j - 1][i + 1].amenazablanca = true;
							if (bando == 0)
								casilla[j - 1][i + 1].amenazanegra = true;
						}
						if (casilla[j][i - 1].bando != bando || casilla[j][i - 1].bando == bando)
						{
							if (bando == 1)
								casilla[j][i - 1].amenazablanca = true;
							if (bando == 0)
								casilla[j][i - 1].amenazanegra = true;
						}
						if (casilla[j + 1][i - 1].bando != bando || casilla[j + 1][i - 1].bando == bando)
						{
							if (bando == 1)
								casilla[j + 1][i - 1].amenazablanca = true;
							if (bando == 0)
								casilla[j + 1][i - 1].amenazanegra = true;
						}
						if (casilla[j - 1][i - 1].bando != bando || casilla[j - 1][i - 1].bando == bando)
						{
							if (bando == 1)
								casilla[j - 1][i - 1].amenazablanca = true;
							if (bando == 0)
								casilla[j - 1][i - 1].amenazanegra = true;
						}
						if (casilla[j + 1][i].bando != bando || casilla[j + 1][i].bando == bando)
						{
							if (bando == 1)
								casilla[j + 1][i].amenazablanca = true;
							if (bando == 0)
								casilla[j + 1][i].amenazanegra = true;
						}
						if (casilla[j - 1][i].bando != bando || casilla[j - 1][i].bando == bando)
						{
							if (bando == 1)
								casilla[j - 1][i].amenazablanca = true;
							if (bando == 0)
								casilla[j - 1][i].amenazanegra = true;
						}
					}
					case 0: {}//vacio,si no hay ninguna ficha en la casilla, obviamente desde esa casilla no surgirá ninguna amenaza
					}
				}
			}
		}
	}
}

bool juego::clavadaficha(int bando, int ob, int i, int j)
{

	if (casilla[j][i].bando == bando)//se comprueba si la pieza en la casilla es del bando que estamos comprobando las clavadas
	{
		if (((casilla[j][i].amenazanegra == true) && ((casilla[j][i].bando == bando) && (bando == 1))) || (((casilla[j][i].amenazablanca == true) && (casilla[j][i].bando == bando)) && (bando == 0)))//en caso de que la casilla esté ocupada por tu bando y amenazada, comprobamos por donde la amenazan para ver si es una ficha con trayectoria
		{
			//comprobamos si le amenazan por la derecha
			for (int k = i + 1; k <= 8; k++)
			{
				if (((casilla[j][k].amenazanegra == false) && (bando == 1)) || ((casilla[j][k].amenazablanca == false) && (bando == 0)))
					k = 9;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una torre
				if (((casilla[j][k].amenazanegra == true) && (bando == 1)) || ((casilla[j][k].amenazablanca == true) && (bando == 0)))
				{//comprueba si en la siguiente casilla está la torre/reina que amenaza
					if (casilla[k + 1][j].ficha.getFicha() == Nombrefichas::TORRE || casilla[k + 1][j].ficha.getFicha() == Nombrefichas::REINA) //en caso que esté amenazado por una torre o reina, comprobamos si el rey está amenazado
					{
						for (int l = i; l >= 1; l--)//miramos a la izquierda de la ficha
						{
							if (casilla[l][j].ficha.getFicha() == Nombrefichas::ALFIL || casilla[l][j].ficha.getFicha() == Nombrefichas::CABALLO || casilla[l][j].ficha.getFicha() == Nombrefichas::PEON || casilla[l][j].ficha.getFicha() == Nombrefichas::REINA || casilla[l][j].ficha.getFicha() == Nombrefichas::TORRE)
								l = -1;
							if (casilla[l][j].ficha.getFicha() == Nombrefichas::REY)
								return true; //en caso de que sea el rey, estará clavada, si no es ni ficha de las nombradas o rey, el bucle no hará nada
						}
					}
					if (casilla[k + 1][j].ficha.getFicha() == Nombrefichas::ALFIL || casilla[k + 1][j].ficha.getFicha() == Nombrefichas::CABALLO || casilla[k + 1][j].ficha.getFicha() == Nombrefichas::PEON || casilla[k + 1][j].ficha.getFicha() == Nombrefichas::REY)
						k = 9;
				}
			}
			//comprobamos si le amenazan por la izquierda 
			for (int k = i - 1; k >= 1; k--)
			{
				if (((casilla[k][j].amenazanegra == false) && (bando == 1)) || ((casilla[k][j].amenazablanca == false) && (bando == 0)))
					k = -1;//si no está amenazado en alguna de las casillas intermedias no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una torre
				if (((casilla[k][j].amenazanegra == true) && (bando == 1)) || ((casilla[k][j].amenazablanca == true) && (bando == 0)))
				{
					if (casilla[k - 1][j].ficha.getFicha() == Nombrefichas::TORRE || casilla[k - 1][j].ficha.getFicha() == Nombrefichas::REINA) //en caso que esté amenazado por una torre o reina, comprobamos si el rey está amenazado
					{
						for (int l = i + 1; l <= 8; l++)//miramos a la derecha de la ficha
						{
							if (casilla[l][j].ficha.getFicha() == Nombrefichas::ALFIL || casilla[l][j].ficha.getFicha() == Nombrefichas::CABALLO || casilla[l][j].ficha.getFicha() == Nombrefichas::PEON || casilla[l][j].ficha.getFicha() == Nombrefichas::REINA || casilla[l][j].ficha.getFicha() == Nombrefichas::TORRE)
								l = 9;
							if ((casilla[l][j].ficha.getFicha() == Nombrefichas::REY) && (casilla[l][j].bando == bando))
							{
								return true;
							}

						}
					}
					if (casilla[k - 1][j].ficha.getFicha() == Nombrefichas::ALFIL || casilla[k - 1][j].ficha.getFicha() == Nombrefichas::CABALLO || casilla[k - 1][j].ficha.getFicha() == Nombrefichas::PEON || casilla[k - 1][j].ficha.getFicha() == Nombrefichas::REY)
						k = -1;//al llegar a una ficha que bloquea se deja de mirar esa direccion

				}
			}
			//comprobamos si le amenazan por encima 
			for (int k = j + 1; k <= 8; k++)
			{
				if (((casilla[k][i].amenazanegra == false) && (bando == 1)) || ((casilla[k][i].amenazablanca == false) && (bando == 0)))
					k = 9;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o torre
				if (((casilla[k][i].amenazanegra == true) && (bando == 1)) || ((casilla[k][i].amenazablanca == true) && (bando == 0)))
				{
					if (((casilla[k + 1][i].ficha.getFicha() == Nombrefichas::TORRE) && (casilla[k - 1][i].bando == ob)) || ((casilla[k - 1][i].ficha.getFicha() == Nombrefichas::REINA) && (casilla[k - 1][i].bando == ob))) //en caso que esté amenazado por una torre o reina, comprobamos si el rey está amenazado
					{
						for (int l = j - 1; l >= 1; l--)//miramos por debajo de la ficha
						{
							if (casilla[l][i].ficha.getFicha() == Nombrefichas::ALFIL || casilla[l][i].ficha.getFicha() == Nombrefichas::CABALLO || casilla[l][i].ficha.getFicha() == Nombrefichas::PEON || casilla[l][i].ficha.getFicha() == Nombrefichas::REINA || casilla[l][i].ficha.getFicha() == Nombrefichas::TORRE)
								l = -1;
							if (casilla[l][i].ficha.getFicha() == Nombrefichas::REY)
							{
								return true;
							}

						}
					}
					if (casilla[k + 1][i].ficha.getFicha() == Nombrefichas::ALFIL || casilla[k - 1][i].ficha.getFicha() == Nombrefichas::CABALLO || casilla[k - 1][i].ficha.getFicha() == Nombrefichas::PEON || casilla[k - 1][i].ficha.getFicha() == Nombrefichas::REY)
					{
						k = 9;//al llegar a una ficha que bloquea se deja de mirar esa direccion
					}
				}
			}
			//comprobamos si le amenazan por debajo
			for (int k = j - 1; k >= 1; k--)
			{
				if (((casilla[k][i].amenazanegra == false) && (bando == 1)) || ((casilla[k][i].amenazablanca == false) && (bando == 0)))
					k = -1;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o torre
				if (((casilla[k][i].amenazanegra == true) && (bando == 1)) || ((casilla[k][i].amenazablanca == true) && (bando == 0)))
				{
					if (((casilla[k - 1][i].ficha.getFicha() == Nombrefichas::TORRE) && (casilla[k - 1][i].bando == ob)) || ((casilla[k - 1][i].ficha.getFicha() == Nombrefichas::REINA) && (casilla[k - 1][i].bando == ob))) //en caso que esté amenazado por una torre o reina, comprobamos si el rey está amenazado
					{
						for (int l = j + 1; l <= 8; l++)//miramos por encima de la ficha
						{
							if (casilla[l][i].ficha.getFicha() == Nombrefichas::ALFIL || casilla[l][i].ficha.getFicha() == Nombrefichas::CABALLO || casilla[l][i].ficha.getFicha() == Nombrefichas::PEON || casilla[l][i].ficha.getFicha() == Nombrefichas::REINA || casilla[l][i].ficha.getFicha() == Nombrefichas::TORRE)
								l = 9;
							if ((casilla[l][i].ficha.getFicha() == Nombrefichas::REY) && (casilla[l][j].bando == bando))
							{
								return true;
							}

						}
					}
					if (casilla[k - 1][i].ficha.getFicha() == Nombrefichas::ALFIL || casilla[k - 1][i].ficha.getFicha() == Nombrefichas::CABALLO || casilla[k - 1][i].ficha.getFicha() == Nombrefichas::PEON || casilla[k - 1][i].ficha.getFicha() == Nombrefichas::REY)
					{
						k = -1;//al llegar a una ficha que bloquea se deja de mirar esa direccion
					}
				}
			}
			//comprobamos si le amenazan por la diagonal inferior izquierda
			for (int k = i - 1; k >= 1; k--)
			{
				if (((casilla[j - (i - k)][k].amenazanegra == false) && (bando == 1)) || ((casilla[j - (i - k)][k].amenazablanca == false) && (bando == 0)))
					k = -1;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o alfil
				if (((casilla[j - (i - k)][k].amenazanegra == true) && (bando == 1)) || ((casilla[j - (i - k)][k].amenazablanca == true) && (bando == 0)))
				{//comprueba si en la siguiente casilla está el alfil/reina que amenaza
					if (((casilla[j - (i - k)][k - 1].ficha.getFicha() == Nombrefichas::ALFIL) && (casilla[j - (i - k)][k - 1].bando == ob)) || ((casilla[j - (i - k)][k - 1].ficha.getFicha() == Nombrefichas::REINA) && (casilla[j - (i - k)][k - 1].bando == ob))) //en caso que esté amenazado por un alfil o reina, comprobamos si el rey está amenazado
					{
						for (int l = i + 1; l <= 8; l++)//miramos arriba a la derecha
						{
							if (casilla[j + (l - i)][l].ficha.getFicha() == Nombrefichas::ALFIL || casilla[j + (l - i)][l].ficha.getFicha() == Nombrefichas::CABALLO || casilla[j + (l - i)][l].ficha.getFicha() == Nombrefichas::PEON || casilla[j + (l - i)][l].ficha.getFicha() == Nombrefichas::REINA || casilla[j + (l - i)][l].ficha.getFicha() == Nombrefichas::TORRE)
								l = 9; //está bloqueado el camino, asi que sale del bucle
							if ((casilla[j + (l - i)][l].ficha.getFicha() == Nombrefichas::REY) && (casilla[j + (l - i)][l].bando == bando))
							{
								return true;
							}
						}
					}
					if (casilla[j - (i - k) - 1][k - 1].ficha.getFicha() == Nombrefichas::TORRE || casilla[j - (i - k) - 1][k - 1].ficha.getFicha() == Nombrefichas::CABALLO || casilla[j - (i - k) - 1][k - 1].ficha.getFicha() == Nombrefichas::PEON || casilla[j - (i - k) - 1][k - 1].ficha.getFicha() == Nombrefichas::REY)
					{
						k = -1;//al llegar a una ficha que bloquea se deja de mirar esa direccion
					}
				}
			}
			//comprobamos si le amenazan por la diagonal inferior derecha
			for (int k = i + 1; k <= 8; k++)
			{
				if (((casilla[j - (k - i)][k].amenazanegra == false) && (bando == 1)) || ((casilla[j - (k - i)][k].amenazablanca == false) && (bando == 0)))
					k = 9;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o alfil
				if (((casilla[j - (k - i)][k].amenazanegra == true) && (bando == 1)) || ((casilla[j - (k - i)][k].amenazablanca == true) && (bando == 0)))
				{//comprueba si en la siguiente casilla está el alfil/reina que amenaza
					if (casilla[j - (k - i) - 1][k + 1].ficha.getFicha() == Nombrefichas::ALFIL || casilla[j - (k - i) - 1][k + 1].ficha.getFicha() == Nombrefichas::REINA) //en caso que esté amenazado por un alfil o reina, comprobamos si el rey está amenazado
					{
						for (int l = i - 1; l >= 1; l--)//miramos arriba a izquierda
						{
							if (casilla[j + (i - l)][l].ficha.getFicha() == Nombrefichas::ALFIL || casilla[j + (i - l)][l].ficha.getFicha() == Nombrefichas::CABALLO || casilla[j + (i - l)][l].ficha.getFicha() == Nombrefichas::PEON || casilla[j + (i - l)][l].ficha.getFicha() == Nombrefichas::REINA || casilla[j + (i - l)][l].ficha.getFicha() == Nombrefichas::TORRE)
								l = -1; //está bloqueado el camino, asi que sale del bucle
							if ((casilla[j + (i - l)][l].ficha.getFicha() == Nombrefichas::REY) && (casilla[j + (i - l)][l].bando == bando))
							{
								return true;
							}
						}
					}
					if (casilla[j - (k - i) - 1][k + 1].ficha.getFicha() == Nombrefichas::TORRE || casilla[j - (k - i) - 1][k + 1].ficha.getFicha() == Nombrefichas::CABALLO || casilla[j - (k - i) - 1][k + 1].ficha.getFicha() == Nombrefichas::PEON || ((casilla[j - (k - i) - 1][k + 1].ficha.getFicha() == Nombrefichas::REY) && (casilla[j - (k - i) - 1][k + 1].bando == ob)))
					{
						k = 9;//al llegar a una ficha que bloquea se deja de mirar esa direccion
					}
				}
			}
			//comprobamos si le amenazan por la diagonal superior izquierda
			for (int k = i - 1; k >= 1; k--)
			{
				if (((casilla[j + (i - k)][k].amenazanegra == false) && (bando == 1)) || ((casilla[j + (i - k)][k].amenazablanca == false) && (bando == 0)))
					k = -1;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o alfil
				if (((casilla[j + (i - k)][k].amenazanegra == true) && (bando == 1)) || ((casilla[j + (i - k)][k].amenazablanca == true) && (bando == 0)))
				{//comprueba si en la siguiente casilla está el alfil/reina que amenaza
					if (casilla[j + (i - k) + 1][k - 1].ficha.getFicha() == Nombrefichas::ALFIL || casilla[j + (i - k) + 1][k - 1].ficha.getFicha() == Nombrefichas::REINA) //en caso que esté amenazado por un alfil o reina, comprobamos si el rey está amenazado
					{
						for (int l = i + 1; l <= 8; l++)//miramos abajo a la derecha
						{
							if (casilla[j - (l - i)][l].ficha.getFicha() == Nombrefichas::ALFIL || casilla[j - (l - i)][l].ficha.getFicha() == Nombrefichas::CABALLO || casilla[j - (l - i)][l].ficha.getFicha() == Nombrefichas::PEON || casilla[j - (l - i)][l].ficha.getFicha() == Nombrefichas::REINA || casilla[j - (l - i)][l].ficha.getFicha() == Nombrefichas::TORRE)
								l = 9; //está bloqueado el camino, asi que sale del bucle
							if ((casilla[j - (l - i)][l].ficha.getFicha() == Nombrefichas::REY) && (casilla[j - (l - i)][l].bando == bando))
							{
								return true;
							}
						}
					}
					if (casilla[j + (i - k) + 1][k - 1].ficha.getFicha() == Nombrefichas::TORRE || casilla[j + (i - k) + 1][k - 1].ficha.getFicha() == Nombrefichas::CABALLO || casilla[j + (i - k) + 1][k - 1].ficha.getFicha() == Nombrefichas::PEON || casilla[j + (i - k) + 1][k - 1].ficha.getFicha() == Nombrefichas::REY)
					{
						casilla[j][i].clavada = false; //añadido para evitar coincidencias en las que pueda parecer que está amenazado por este tipo de pieza pero haya un enemigo distinto bloqueando el camino
						k = -1;//al llegar a una ficha que bloquea se deja de mirar esa direccion
					}
				}
			}
			//comprobamos si le amenazan por la diagonal superior derecha
			for (int k = i + 1; k <= 8; k++)
			{
				if (((casilla[j + (k - i)][k].amenazanegra == false) && (bando == 1)) || ((casilla[j + (k - i)][k].amenazablanca == false) && (bando == 0)))
					k = 9;//si no está amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o alfil
				if (((casilla[j + (k - i)][k].amenazanegra == true) && (bando == 1)) || ((casilla[j + (k - i)][k].amenazablanca == true) && (bando == 0)))
				{//comprueba si en la siguiente casilla está el alfil/reina que amenaza
					if (((casilla[j + (k - i) + 1][k + 1].ficha.getFicha() == Nombrefichas::ALFIL) && (casilla[j + (k - i) + 1][k + 1].bando == ob)) || ((casilla[j + (k - i) + 1][k + 1].ficha.getFicha() == Nombrefichas::ALFIL) && (casilla[j + (k - i) + 1][k + 1].bando == ob))) //en caso que esté amenazado por un alfil o reina, comprobamos si el rey está amenazado
					{//Si está la amenaza, comprueba detras de la pieza para ver si esta tu rey y por tanto estas clavada
						for (int l = i - 1; l >= 1; l--)//miramos abajo a la izquierda
						{
							if (casilla[j - (i - l)][l].ficha.getFicha() == Nombrefichas::ALFIL || casilla[j - (i - l)][l].ficha.getFicha() == Nombrefichas::CABALLO || casilla[j - (i - l)][l].ficha.getFicha() == Nombrefichas::PEON || casilla[j - (i - l)][l].ficha.getFicha() == Nombrefichas::REINA || casilla[j - (i - l)][l].ficha.getFicha() == Nombrefichas::TORRE)
								l = -1; //está bloqueado el camino, asi que sale del bucle
							if ((casilla[j - (i - l)][l].ficha.getFicha() == Nombrefichas::REY) && (casilla[j - (i - l)][l].bando == bando))//si hay un rey, del color de tus fichas, está clavada
							{
								return true;
							}
						}
					}
					if (casilla[j + (k - i) + 1][k + 1].ficha.getFicha() == Nombrefichas::TORRE || casilla[j + (k - i) + 1][k + 1].ficha.getFicha() == Nombrefichas::CABALLO || casilla[j + (k - i) + 1][k + 1].ficha.getFicha() == Nombrefichas::PEON || ((casilla[j + (k - i) + 1][k + 1].ficha.getFicha() == Nombrefichas::REY) && (casilla[j + (k - i) + 1][k + 1].bando == ob)))//con esta ultima cond evitamos que confunda el rey atacante con el tuyo
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
			casilla[j][i].clavada = resultado;
		}
	}
}

void juego::movimiento() {

	Peon peon;
	Torre torre;
	Caballo caballo;
	Alfil alfil;
	Rey rey;
	Reina reina;

	int filaini = 0, columnaini = 0;

	do {
		cout << "Introduzca la fila y columna de la ficha que quiere mover: ";
		cin >> filaini >> columnaini;
		if (filaini > 8 || columnaini > 8 || filaini < 0 || columnaini < 0)
			cout << "Coordenadas fuera de rango";
		else {
			for (int i = 1; i < 10; i++) {
				for (int j = 1; j < 10; j++) {
					if (casilla[i][j].f == filaini && casilla[i][j].c == columnaini && casilla[i][j].estado == 0) {
						"No hay ninguna ficha en dichas coordenadas";
					}
					if (casilla[i][j].f == filaini && casilla[i][j].c == columnaini && casilla[i][j].estado == 1)
						break;
				}
			}
		}

	} while (filaini > 8 || columnaini > 8 || filaini < 0 || columnaini < 0 || casilla[filaini][columnaini].estado == 0);
	//Así nos aseguramos que las coordenadas introducidas son correctas, están dentro del tablero y hay una ficha en dicha casilla



	int filafin = 0, columnafin = 0, r = 0;

	do {
		cout << "Introduzca la fila y columna a donde quiere mover la ficha: ";
		cin >> filafin >> columnafin;
	} while (filafin > 8 || columnafin > 8 || filafin < 0 || columnafin < 0);//Así nos aseguramos que las coordenadas introducidas son correctas y están dentro del tablero

	if (casilla[filaini][columnaini].ficha.getFicha() == Nombrefichas::ALFIL)
		r = 1;
	if (casilla[filaini][columnaini].ficha.getFicha() == Nombrefichas::TORRE)
		r = 2;
	if (casilla[filaini][columnaini].ficha.getFicha() == Nombrefichas::CABALLO)
		r = 3;
	if (casilla[filaini][columnaini].ficha.getFicha() == Nombrefichas::PEON)
		r = 4;
	if (casilla[filaini][columnaini].ficha.getFicha() == Nombrefichas::REY)
		r = 5;
	if (casilla[filaini][columnaini].ficha.getFicha() == Nombrefichas::REINA)
		r = 6;

	switch (r) {
	case 1:
		if (alfil.restricciones(filafin, columnafin, filaini, columnaini)) {
			casilla[filafin][columnafin].ocupar(filafin, columnafin, Nombrefichas::ALFIL, casilla[filaini][columnaini].fcolor);
			casilla[filaini][columnaini].vaciar(filaini, columnaini);
		}
		else
			cout << "Movimiento no permitido";
		break;
	case 2:
		if (torre.restricciones(filafin, columnafin, filaini, columnaini)) {
			casilla[filafin][columnafin].ocupar(filafin, columnafin, Nombrefichas::TORRE, casilla[filaini][columnaini].fcolor);
			casilla[filaini][columnaini].vaciar(filaini, columnaini);
		}
		else
			cout << "Movimiento no permitido";
		break;
	case 3:
		if (caballo.restricciones(filafin, columnafin, filaini, columnaini)) {
			casilla[filafin][columnafin].ocupar(filafin, columnafin, Nombrefichas::CABALLO, casilla[filaini][columnaini].fcolor);
			casilla[filaini][columnaini].vaciar(filaini, columnaini);
		}
		else
			cout << "Movimiento no permitido";
		break;
	case 4:
		if (peon.restricciones(filafin, columnafin, filaini, columnaini)) {
			casilla[filafin][columnafin].ocupar(filafin, columnafin, Nombrefichas::PEON, casilla[filaini][columnaini].fcolor);
			casilla[filaini][columnaini].vaciar(filaini, columnaini);
		}
		else
			cout << "Movimiento no permitido";
		break;
	case 5:
		if (rey.restricciones(filafin, columnafin, filaini, columnaini)) {
			casilla[filafin][columnafin].ocupar(filafin, columnafin, Nombrefichas::REY, casilla[filaini][columnaini].fcolor);
			casilla[filaini][columnaini].vaciar(filaini, columnaini);
		}
		else
			cout << "Movimiento no permitido";
		break;
	case 6:
		if (reina.restricciones(filafin, columnafin, filaini, columnaini)) {
			casilla[filafin][columnafin].ocupar(filafin, columnafin, Nombrefichas::REINA, casilla[filaini][columnaini].fcolor);
			casilla[filaini][columnaini].vaciar(filaini, columnaini);
		}
		else
			cout << "Movimiento no permitido";
		break;
	}



}


void juego::casillero() {

	int n = 1;
	int i = 1;
	int j = 1;



	while (n < 65) {

		//la i es la fila y la j la columna: casilla[fila][columna]
		casilla[i][j].f = i;
		casilla[i][j].c = j;
		casilla[i][j].numero = n;

		if (i % 2 == j % 2) casilla[i][j].color = 'b';
		else casilla[i][j].color = 'w';


		casilla[i][j].centrox = 1 + i;
		casilla[i][j].centroy = 1 + j;




		n++;
		if (j < 8) j++;
		else {
			j = 1;
			i++;
		}
	}
	//se fora una matriz [filas(8)][columnas(8)] que recorre cada fila de izquierda a derecha (1-8) y  cuando acaba con la fila pasa a la fila superior.

}



int juego::jaque(int xatacante, int yatacante, int bando, int xrey, int yrey) { //comprueba si el rey está en jaque, y si lo está, comprueba si está en jaque mate
	//datos de prueba, luego serán sustituidos por los equivalentes en la clase tablero
	int entry = 0;//entrada a switch case
	Nombrefichas atacante = casilla[yatacante][xatacante].ficha.getFicha();// miramos que tipo de ficha es la que ataca, creo que esto esta mal planteado, habra que tener de input a la funcion la ficha atacante directamente
	int bandoatacante;
	if (bando == 1)
		bandoatacante = 0;
	else
		bandoatacante = 1; //ponemos al bando atacante como contrario del defensor y comprobamos si está amenazada
	//primero de todo comprobaremos si la posicion del rey está amenazada
	//IMPORTANTE: ANTES DE LA FUNCION JAQUE, LA FUNCION CLAVADA TIENE QUE HACER UNA PASADA POR TODAS LAS FICHAS DEL BANDO AL QUE SE HACE JAQUE, PARA QUE LAS CLAVADAS NO PUEDAN COMER NI AMENAZAR

	if ((bando == 1) && (casilla[yrey][xrey].amenazanegra == true) || ((bando == 0) && (casilla[yrey][xrey].amenazablanca == true))) //la posición del rey está amenazada, por tanto es jaque, ahora comprobamos si hay jaque mate, empezando por ver si el rey puede huir
	{
		if ((((bando == 1) && (casilla[yrey + 1][xrey].amenazanegra == false)) && (casilla[yrey + 1][xrey].bando != bando)) || (((bando == 0) && (casilla[yrey + 1][xrey].amenazablanca == false)) && (casilla[yrey + 1][xrey].bando != bando)))
			return 1; //1 significa que está en jaque, pero no en jaque mate
		if ((((bando == 1) && (casilla[yrey - 1][xrey].amenazanegra == false)) && (casilla[yrey - 1][xrey].bando != bando)) || (((bando == 0) && (casilla[yrey - 1][xrey].amenazablanca == false)) && (casilla[yrey - 1][xrey].bando != bando)))
			return 1;
		if ((((bando == 1) && (casilla[yrey][xrey + 1].amenazanegra == false)) && (casilla[yrey][xrey + 1].bando != bando)) || (((bando == 0) && (casilla[yrey][xrey + 1].amenazablanca == false)) && (casilla[yrey + 1][xrey].bando != bando)))
			return 1;
		if ((((bando == 1) && (casilla[yrey + 1][xrey + 1].amenazanegra == false)) && (casilla[yrey + 1][xrey + 1].bando != bando)) || (((bando == 0) && (casilla[yrey + 1][xrey + 1].amenazablanca == false)) && (casilla[yrey + 1][xrey].bando != bando)))
			return 1;
		if ((((bando == 1) && (casilla[yrey - 1][xrey + 1].amenazanegra == false)) && (casilla[yrey - 1][xrey + 1].bando != bando)) || (((bando == 0) && (casilla[yrey - 1][xrey + 1].amenazablanca == false)) && (casilla[yrey + 1][xrey].bando != bando)))
			return 1;
		if ((((bando == 1) && (casilla[yrey][xrey - 1].amenazanegra == false)) && (casilla[yrey][xrey - 1].bando != bando)) || (((bando == 0) && (casilla[yrey][xrey - 1].amenazablanca == false)) && (casilla[yrey + 1][xrey].bando != bando)))
			return 1;
		if ((((bando == 1) && (casilla[yrey + 1][xrey - 1].amenazanegra == false)) && (casilla[yrey + 1][xrey - 1].bando != bando)) || (((bando == 0) && (casilla[yrey + 1][xrey - 1].amenazablanca == false)) && (casilla[yrey + 1][xrey].bando != bando)))
			return 1;
		if ((((bando == 1) && (casilla[yrey - 1][xrey - 1].amenazanegra == false)) && (casilla[yrey - 1][xrey - 1].bando != bando)) || (((bando == 0) && (casilla[yrey + 1][xrey - 1].amenazablanca == false)) && (casilla[yrey + 1][xrey].bando != bando)))
			return 1;
		//en caso de que el rey no haya podido huir por ninguna de las posiciones colindantes, comprobamos si se puede eliminar la amenaza
		if (((bando == 1) && (casilla[yatacante][xatacante].amenazablanca == true)) || (((bando == 0) && (casilla[yatacante][xatacante].amenazanegra == true))))
			return 1;
		else
		{
			//esto significa que no podemos comernos al atacante, por lo que la única opción que queda es bloquear su camino, cosa que solo se puede si es una Reina, una Torre o un Alfil
			if (casilla[yatacante][xatacante].ficha.getFicha() == Nombrefichas::PEON)
				entry = 1;
			if (casilla[yatacante][xatacante].ficha.getFicha() == Nombrefichas::CABALLO)
				entry = 2;
			if (casilla[yatacante][xatacante].ficha.getFicha() == Nombrefichas::TORRE)
				entry = 3;
			if (casilla[yatacante][xatacante].ficha.getFicha() == Nombrefichas::ALFIL)
				entry = 4;
			if (casilla[yatacante][xatacante].ficha.getFicha() == Nombrefichas::REINA)
				entry = 5;
			if (casilla[yatacante][xatacante].ficha.getFicha() == Nombrefichas::REY)
				entry = 6;
			if (casilla[yatacante][xatacante].ficha.getFicha() == Nombrefichas::VACIO)
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
								if (casilla[yatacante + i][xatacante].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (casilla[yatacante + i][xatacante].amenazanegra == true)
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
								if (casilla[yatacante - i][xatacante].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (casilla[yatacante - i][xatacante].amenazanegra == true)
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
								if (casilla[yatacante][xatacante + i].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (casilla[yatacante][xatacante + i].amenazanegra == true)
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
								if (casilla[yatacante][xatacante - i].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (casilla[yatacante][xatacante - i].amenazanegra == true)
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
							if (casilla[yatacante + i][xatacante + i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (casilla[yatacante + i][xatacante + i].amenazanegra == true)
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
							if (casilla[yatacante + i][xatacante - i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (casilla[yatacante + i][xatacante - i].amenazanegra == true)
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
							if (casilla[yatacante - i][xatacante + i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (casilla[yatacante - i][xatacante + i].amenazanegra == true)
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
							if (casilla[yatacante - i][xatacante - i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (casilla[yatacante - i][xatacante - i].amenazanegra == true)
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
								if (casilla[yatacante + i][xatacante].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (casilla[yatacante + i][xatacante].amenazanegra == true)
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
								if (casilla[yatacante - i][xatacante].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (casilla[yatacante - i][xatacante].amenazanegra == true)
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
								if (casilla[yatacante][xatacante + i].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (casilla[yatacante][xatacante + i].amenazanegra == true)
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
								if (casilla[yatacante][xatacante - i].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (casilla[yatacante][xatacante - i].amenazanegra == true)
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
							if (casilla[yatacante + i][xatacante + i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (casilla[yatacante + i][xatacante + i].amenazanegra == true)
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
							if (casilla[yatacante + i][xatacante - i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (casilla[yatacante + i][xatacante - i].amenazanegra == true)
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
							if (casilla[yatacante - i][xatacante + i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (casilla[yatacante - i][xatacante + i].amenazanegra == true)
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
							if (casilla[yatacante - i][xatacante - i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (casilla[yatacante - i][xatacante - i].amenazanegra == true)
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
