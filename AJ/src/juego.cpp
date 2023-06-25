#include "juego.h"
#include "Fichas.h"
#include"Peon.h"
#include"Torre.h"
#include"Caballo.h"
#include"Alfil.h"
#include"Rey.h"
#include"Reina.h"
#include"Tablero.h"
#include<iostream>
using namespace std;

void juego::limpiaramenazas()
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Tablero::Tablero::casilla[j][i].amenazablanca = false;
			Tablero::Tablero::casilla[j][i].amenazanegra = false;
		}
	}
}


void juego::amenazar(int bando)
{
	int entry = 0;//entrada al switch case
	int ob;//ob = otro bando, se usar� para que cuando encuentre una ficha del equipo contrario la amenace pero no siga avanzando con la amenaza (casos de TORRE, ALFIL y REINA)
	if (bando == 1)
		ob = 0;
	if (bando == 0)
		ob = 1;
	for (int i = 1; i <= 8; i++) //i son las filas, j las columnas, es decir, que es [y,x]
	{
		for (int j = 1; j <= 8; j++)//bucle anidado para ver todo el tablero
		{
			if (Tablero::Tablero::casilla[j][i].bando == bando) //si es el mismo bando, declaramos las amenazas de ese color, cada vez que se haya un movimiento se hacen dos amenazar, uno por color)
			{
				if (Tablero::Tablero::casilla[j][i].clavada == false)//por tanto, solo amenazaran si no est�n clavadas
				{
					
					if (Tablero::Tablero::casilla[j][i].ficha->getFicha() == Nombrefichas::PEON)
						entry = 1;
					if (Tablero::Tablero::casilla[j][i].ficha->getFicha() == Nombrefichas::CABALLO)
						entry = 2;
					if (Tablero::Tablero::casilla[j][i].ficha->getFicha() == Nombrefichas::TORRE)
						entry = 3;
					if (Tablero::Tablero::casilla[j][i].ficha->getFicha() == Nombrefichas::ALFIL)
						entry = 4;
					if (Tablero::Tablero::casilla[j][i].ficha->getFicha() == Nombrefichas::REINA)
						entry = 5;
					if (Tablero::Tablero::casilla[j][i].ficha->getFicha() == Nombrefichas::REY)
						entry = 6;
					if (Tablero::Tablero::casilla[j][i].ficha->getFicha() == Nombrefichas::VACIO)
						entry = 0;

					switch (entry) //diferentes amenazas seg�n el tipo de ficha
					{
					case 1://peon
					{
						if (bando == 1)
						{
							if (Tablero::Tablero::casilla[j + 1][i + 1].bando != bando || Tablero::Tablero::casilla[j + 1][i + 1].bando == bando) //amenaza haya aliados o enemigos, pero solo amenaza en su zona de ataque
								Tablero::Tablero::casilla[j + 1][i + 1].amenazablanca = true; //seria un amenazablanca=true; el bando 2 ser� que no est� ocupada ni por blancas ni negras
							if (Tablero::Tablero::casilla[j + 1][i - 1].bando != bando || Tablero::Tablero::casilla[j + 1][i - 1].bando == bando)
								Tablero::Tablero::casilla[j + 1][i - 1].amenazablanca = true;
						}
						if (bando == 0) //el peon es la unica pieza que seg�n su bando ataca de forma distinta, "baja el tablero", ya que consideramos que estan arriba negras y abajo blancas
						{
							if (Tablero::Tablero::casilla[j - 1][i + 1].bando != bando || Tablero::Tablero::casilla[j - 1][i - 1].bando == bando) //amenaza haya aliados o enemigos, pero solo amenaza en su zona de ataque
								Tablero::casilla[j - 1][i + 1].amenazanegra = true; //seria un amenazanegra=true; el bando 2 ser� que no est� ocupada ni por blancas ni negras
							if (Tablero::casilla[j - 1][i - 1].bando != bando || Tablero::casilla[j - 1][i - 1].bando == bando)
								Tablero::casilla[j - 1][i + 1].amenazanegra = true;
						}
					}
					case 2://caballo
					{
						if (Tablero::casilla[j + 2][i + 1].bando != bando || Tablero::casilla[j + 2][i + 1].bando == bando)
						{
							if (bando == 1)
								Tablero::casilla[j + 2][i + 1].amenazablanca = true;
							if (bando == 0)
								Tablero::casilla[j + 2][i + 1].amenazanegra = true;
						}
						if (Tablero::casilla[j + 2][i - 1].bando != bando || Tablero::casilla[j + 2][i - 1].bando == bando)
						{
							if (bando == 1)
								Tablero::casilla[j + 2][i - 1].amenazablanca = true;
							if (bando == 0)
								Tablero::casilla[j + 2][i - 1].amenazanegra = true;
						}
						if (Tablero::casilla[j - 2][i + 1].bando != bando || Tablero::casilla[j - 2][i + 1].bando == bando)
						{
							if (bando == 1)
								Tablero::casilla[j - 2][i + 1].amenazablanca = true;
							if (bando == 0)
								Tablero::casilla[j - 2][i + 1].amenazanegra = true;
						}
						if (Tablero::casilla[j - 2][i - 1].bando != bando || Tablero::casilla[j - 2][i - 1].bando == bando)
						{
							if (bando == 1)
								Tablero::casilla[j - 2][i - 1].amenazablanca = true;
							if (bando == 0)
								Tablero::casilla[j - 2][i - 1].amenazanegra = true;
						}
						if (Tablero::casilla[j + 1][i + 2].bando != bando || Tablero::casilla[j + 1][i + 2].bando == bando)
						{
							if (bando == 1)
								Tablero::casilla[j + 1][i + 2].amenazablanca = true;
							if (bando == 0)
								Tablero::casilla[j + 1][i + 2].amenazanegra = true;
						}
						if (Tablero::casilla[j + 1][i - 2].bando != bando || Tablero::casilla[j + 1][i - 2].bando == bando)
						{
							if (bando == 1)
								Tablero::casilla[j + 1][i - 2].amenazablanca = true;
							if (bando == 0)
								Tablero::casilla[j + 1][i - 2].amenazanegra = true;
						}
						if (Tablero::casilla[j - 1][i + 2].bando != bando || Tablero::casilla[j - 1][i + 2].bando == bando)
						{
							if (bando == 1)
								Tablero::casilla[j - 1][i + 2].amenazablanca = true;
							if (bando == 0)
								Tablero::casilla[j - 1][i + 2].amenazanegra = true;
						}
						if (Tablero::casilla[j - 1][i - 2].bando != bando || Tablero::casilla[j - 1][i - 2].bando == bando)
						{
							if (bando == 1)
								Tablero::casilla[j - 1][i - 2].amenazablanca = true;
							if (bando == 0)
								Tablero::casilla[j - 1][i - 2].amenazanegra = true;
						}
					}
					case 3://torre
					{
						//ARRIBA
						for (int k = j + 1; k <= 8; k++)
						{
							if (Tablero::casilla[k][i].bando != bando || Tablero::casilla[k][i].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[k][i].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[k][i].amenazanegra = true;
							}
							if (Tablero::casilla[k][i].bando == ob || Tablero::casilla[k][i].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[k][i].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[k][i].amenazanegra = true;
								k = 9;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detr�s
							}

						}
						//ABAJO
						for (int k = j - 1; k >= 1; k--)
						{
							if (Tablero::casilla[k][i].bando != bando || Tablero::casilla[k][i].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[k][i].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[k][i].amenazanegra = true;
							}
							if (Tablero::casilla[k][i].bando == ob || Tablero::casilla[k][i].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[k][i].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[k][i].amenazanegra = true;
								k = -1;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detr�s
							}

						}
						//IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (Tablero::casilla[j][k].bando != bando || Tablero::casilla[j][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j][k].amenazanegra = true;
								k = -1;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detr�s
							}
							if (Tablero::casilla[j][k].bando == ob || Tablero::casilla[k][j].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j][k].amenazanegra = true;
								k = -1;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detr�s
							}

						}
						//DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (Tablero::casilla[j][k].bando != bando || Tablero::casilla[j][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j][k].amenazanegra = true;
							}
							if (Tablero::casilla[j][k].bando == ob || Tablero::casilla[j][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j][k].amenazanegra = true;
								k = 9;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detr�s

							}

						}
					}
					case 4://alfil
					{
						//ARRIBA DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (Tablero::casilla[j + (k - i)][k].bando != bando || Tablero::casilla[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j + (k - i)][k].amenazanegra = true;

							}

							if (Tablero::casilla[j + (k - i)][k].bando == ob || Tablero::casilla[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j + (k - i)][k].amenazanegra = true;
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detr�s
							}
						}
						//ARRIBA IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (Tablero::casilla[j - (k - i)][k].bando != bando || Tablero::casilla[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j - (k - i)][k].amenazanegra = true;

							}
							if (Tablero::casilla[j - (k - i)][k].bando == ob || Tablero::casilla[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j - (k - i)][k].amenazanegra = true;
								k = -1;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detr�s
							}
						}
						//ABAJO DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (Tablero::casilla[j - (k - i)][k].bando != bando || Tablero::casilla[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j - (k - i)][k].amenazanegra = true;
							}
							if (Tablero::casilla[j - (k - i)][k].bando == ob || Tablero::casilla[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j - (k - i)][k].amenazanegra = true;
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detr�s
							}
						}
						//ABAJO IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (Tablero::casilla[j + (k - i)][k].bando != bando || Tablero::casilla[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j + (k - i)][k].amenazanegra = true;
							}
							if (Tablero::casilla[j + (k - i)][k].bando == ob || Tablero::casilla[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j + (k - i)][k].amenazanegra = true;
								k = -1;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detr�s
							}
						}
					}
					case 5: //reina, suma de TORRE y ALFIL
					{
						//ARRIBA
						for (int k = j + 1; k <= 8; k++)
						{
							if (Tablero::casilla[k][i].bando != bando || Tablero::casilla[k][i].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[k][i].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[k][i].amenazanegra = true;
							}
							if (Tablero::casilla[k][i].bando == ob || Tablero::casilla[k][i].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[k][i].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[k][i].amenazanegra = true;
								k = 9;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detr�s
							}

						}
						//ABAJO
						for (int k = j - 1; k >= 1; k--)
						{
							if (Tablero::casilla[k][i].bando != bando || Tablero::casilla[k][i].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[k][i].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[k][i].amenazanegra = true;
							}
							if (Tablero::casilla[k][i].bando == ob || Tablero::casilla[k][i].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[k][i].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[k][i].amenazanegra = true;
								k = -1;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detr�s
							}

						}
						//IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (Tablero::casilla[j][k].bando != bando || Tablero::casilla[j][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j][k].amenazanegra = true;
								k = -1;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detr�s
							}
							if (Tablero::casilla[j][k].bando == ob || Tablero::casilla[k][j].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j][k].amenazanegra = true;
								k = -1;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detr�s
							}

						}
						//DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (Tablero::casilla[j][k].bando != bando || Tablero::casilla[j][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j][k].amenazanegra = true;
							}
							if (Tablero::casilla[j][k].bando == ob || Tablero::casilla[j][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j][k].amenazanegra = true;
								k = 9;//si encuentra una ficha , amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detr�s

							}

						}
						//ARRIBA DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (Tablero::casilla[j + (k - i)][k].bando != bando || Tablero::casilla[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j + (k - i)][k].amenazanegra = true;

							}

							if (Tablero::casilla[j + (k - i)][k].bando == ob || Tablero::casilla[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j + (k - i)][k].amenazanegra = true;
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detr�s
							}
						}
						//ARRIBA IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (Tablero::casilla[j - (k - i)][k].bando != bando || Tablero::casilla[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j - (k - i)][k].amenazanegra = true;

							}
							if (Tablero::casilla[j - (k - i)][k].bando == ob || Tablero::casilla[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j - (k - i)][k].amenazanegra = true;
								k = -1;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detr�s
							}
						}
						//ABAJO DERECHA
						for (int k = i + 1; k <= 8; k++)
						{
							if (Tablero::casilla[j - (k - i)][k].bando != bando || Tablero::casilla[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j - (k - i)][k].amenazanegra = true;
							}
							if (Tablero::casilla[j - (k - i)][k].bando == ob || Tablero::casilla[j - (k - i)][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j - (k - i)][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j - (k - i)][k].amenazanegra = true;
								k = 9;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detr�s
							}
						}
						//ABAJO IZQUIERDA
						for (int k = i - 1; k >= 1; k--)
						{
							if (Tablero::casilla[j + (k - i)][k].bando != bando || Tablero::casilla[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j + (k - i)][k].amenazanegra = true;
							}
							if (Tablero::casilla[j + (k - i)][k].bando == ob || Tablero::casilla[j + (k - i)][k].bando == bando)
							{
								if (bando == 1)
									Tablero::casilla[j + (k - i)][k].amenazablanca = true;
								if (bando == 0)
									Tablero::casilla[j + (k - i)][k].amenazanegra = true;
								k = -1;//si encuentra una ficha, sea blanca o negra, amenaza su posicion y sale del bucle, no amenazando a las que tenga la ficha detr�s
							}
						}

					}
					case 6://rey
					{
						if (Tablero::casilla[j][i + 1].bando != bando || Tablero::casilla[j][i + 1].bando == bando)
						{
							if (bando == 1)
								Tablero::casilla[j][i + 1].amenazablanca = true;
							if (bando == 0)
								Tablero::casilla[j][i + 1].amenazanegra = true;
						}
						if (Tablero::casilla[j + 1][i + 1].bando != bando || Tablero::casilla[j + 1][i + 1].bando == bando)
						{
							if (bando == 1)
								Tablero::casilla[j + 1][i + 1].amenazablanca = true;
							if (bando == 0)
								Tablero::casilla[j + 1][i + 1].amenazanegra = true;
						}
						if (Tablero::casilla[j - 1][i + 1].bando != bando || Tablero::casilla[j - 1][i + 1].bando == bando)
						{
							if (bando == 1)
								Tablero::casilla[j - 1][i + 1].amenazablanca = true;
							if (bando == 0)
								Tablero::casilla[j - 1][i + 1].amenazanegra = true;
						}
						if (Tablero::casilla[j][i - 1].bando != bando || Tablero::casilla[j][i - 1].bando == bando)
						{
							if (bando == 1)
								Tablero::casilla[j][i - 1].amenazablanca = true;
							if (bando == 0)
								Tablero::casilla[j][i - 1].amenazanegra = true;
						}
						if (Tablero::casilla[j + 1][i - 1].bando != bando || Tablero::casilla[j + 1][i - 1].bando == bando)
						{
							if (bando == 1)
								Tablero::casilla[j + 1][i - 1].amenazablanca = true;
							if (bando == 0)
								Tablero::casilla[j + 1][i - 1].amenazanegra = true;
						}
						if (Tablero::casilla[j - 1][i - 1].bando != bando || Tablero::casilla[j - 1][i - 1].bando == bando)
						{
							if (bando == 1)
								Tablero::casilla[j - 1][i - 1].amenazablanca = true;
							if (bando == 0)
								Tablero::casilla[j - 1][i - 1].amenazanegra = true;
						}
						if (Tablero::casilla[j + 1][i].bando != bando || Tablero::casilla[j + 1][i].bando == bando)
						{
							if (bando == 1)
								Tablero::casilla[j + 1][i].amenazablanca = true;
							if (bando == 0)
								Tablero::casilla[j + 1][i].amenazanegra = true;
						}
						if (Tablero::casilla[j - 1][i].bando != bando || Tablero::casilla[j - 1][i].bando == bando)
						{
							if (bando == 1)
								Tablero::casilla[j - 1][i].amenazablanca = true;
							if (bando == 0)
								Tablero::casilla[j - 1][i].amenazanegra = true;
						}
					}
					case 0: {}//vacio,si no hay ninguna ficha en la Tablero::casilla, obviamente desde esa Tablero::casilla no surgir� ninguna amenaza
					}
				}
			}
		}
	}
}

bool juego::clavadaficha(int bando, int ob, int i, int j)
{

	if (Tablero::casilla[j][i].bando == bando)//se comprueba si la pieza en la Tablero::casilla es del bando que estamos comprobando las clavadas
	{
		if (((Tablero::casilla[j][i].amenazanegra == true) && ((Tablero::casilla[j][i].bando == bando) && (bando == 1))) || (((Tablero::casilla[j][i].amenazablanca == true) && (Tablero::casilla[j][i].bando == bando)) && (bando == 0)))//en caso de que la Tablero::casilla est� ocupada por tu bando y amenazada, comprobamos por donde la amenazan para ver si es una ficha con trayectoria
		{
			//comprobamos si le amenazan por la derecha
			for (int k = i + 1; k <= 8; k++)
			{
				if (((Tablero::casilla[j][k].amenazanegra == false) && (bando == 1)) || ((Tablero::casilla[j][k].amenazablanca == false) && (bando == 0)))
					k = 9;//si no est� amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una torre
				if (((Tablero::casilla[j][k].amenazanegra == true) && (bando == 1)) || ((Tablero::casilla[j][k].amenazablanca == true) && (bando == 0)))
				{//comprueba si en la siguiente Tablero::casilla est� la torre/reina que amenaza
					if (Tablero::casilla[k + 1][j].ficha->getFicha() == Nombrefichas::TORRE || Tablero::casilla[k + 1][j].ficha->getFicha() == Nombrefichas::REINA) //en caso que est� amenazado por una torre o reina, comprobamos si el rey est� amenazado
					{
						for (int l = i; l >= 1; l--)//miramos a la izquierda de la ficha
						{
							if (Tablero::casilla[l][j].ficha->getFicha() == Nombrefichas::ALFIL || Tablero::casilla[l][j].ficha->getFicha() == Nombrefichas::CABALLO || Tablero::casilla[l][j].ficha->getFicha() == Nombrefichas::PEON || Tablero::casilla[l][j].ficha->getFicha() == Nombrefichas::REINA || Tablero::casilla[l][j].ficha->getFicha() == Nombrefichas::TORRE)
								l = -1;
							if (Tablero::casilla[l][j].ficha->getFicha() == Nombrefichas::REY)
								return true; //en caso de que sea el rey, estar� clavada, si no es ni ficha de las nombradas o rey, el bucle no har� nada
						}
					}
					if (Tablero::casilla[k + 1][j].ficha->getFicha() == Nombrefichas::ALFIL || Tablero::casilla[k + 1][j].ficha->getFicha() == Nombrefichas::CABALLO || Tablero::casilla[k + 1][j].ficha->getFicha() == Nombrefichas::PEON || Tablero::casilla[k + 1][j].ficha->getFicha() == Nombrefichas::REY)
						k = 9;
				}
			}
			//comprobamos si le amenazan por la izquierda 
			for (int k = i - 1; k >= 1; k--)
			{
				if (((Tablero::casilla[k][j].amenazanegra == false) && (bando == 1)) || ((Tablero::casilla[k][j].amenazablanca == false) && (bando == 0)))
					k = -1;//si no est� amenazado en alguna de las Tablero::casillas intermedias no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una torre
				if (((Tablero::casilla[k][j].amenazanegra == true) && (bando == 1)) || ((Tablero::casilla[k][j].amenazablanca == true) && (bando == 0)))
				{
					if (Tablero::casilla[k - 1][j].ficha->getFicha() == Nombrefichas::TORRE || Tablero::casilla[k - 1][j].ficha->getFicha() == Nombrefichas::REINA) //en caso que est� amenazado por una torre o reina, comprobamos si el rey est� amenazado
					{
						for (int l = i + 1; l <= 8; l++)//miramos a la derecha de la ficha
						{
							if (Tablero::casilla[l][j].ficha->getFicha() == Nombrefichas::ALFIL || Tablero::casilla[l][j].ficha->getFicha() == Nombrefichas::CABALLO || Tablero::casilla[l][j].ficha->getFicha() == Nombrefichas::PEON || Tablero::casilla[l][j].ficha->getFicha() == Nombrefichas::REINA || Tablero::casilla[l][j].ficha->getFicha() == Nombrefichas::TORRE)
								l = 9;
							if ((Tablero::casilla[l][j].ficha->getFicha() == Nombrefichas::REY) && (Tablero::casilla[l][j].bando == bando))
							{
								return true;
							}

						}
					}
					if (Tablero::casilla[k - 1][j].ficha->getFicha() == Nombrefichas::ALFIL || Tablero::casilla[k - 1][j].ficha->getFicha() == Nombrefichas::CABALLO || Tablero::casilla[k - 1][j].ficha->getFicha() == Nombrefichas::PEON || Tablero::casilla[k - 1][j].ficha->getFicha() == Nombrefichas::REY)
						k = -1;//al llegar a una ficha que bloquea se deja de mirar esa direccion

				}
			}
			//comprobamos si le amenazan por encima 
			for (int k = j + 1; k <= 8; k++)
			{
				if (((Tablero::casilla[k][i].amenazanegra == false) && (bando == 1)) || ((Tablero::casilla[k][i].amenazablanca == false) && (bando == 0)))
					k = 9;//si no est� amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o torre
				if (((Tablero::casilla[k][i].amenazanegra == true) && (bando == 1)) || ((Tablero::casilla[k][i].amenazablanca == true) && (bando == 0)))
				{
					if (((Tablero::casilla[k + 1][i].ficha->getFicha() == Nombrefichas::TORRE) && (Tablero::casilla[k - 1][i].bando == ob)) || ((Tablero::casilla[k - 1][i].ficha->getFicha() == Nombrefichas::REINA) && (Tablero::casilla[k - 1][i].bando == ob))) //en caso que est� amenazado por una torre o reina, comprobamos si el rey est� amenazado
					{
						for (int l = j - 1; l >= 1; l--)//miramos por debajo de la ficha
						{
							if (Tablero::casilla[l][i].ficha->getFicha() == Nombrefichas::ALFIL || Tablero::casilla[l][i].ficha->getFicha() == Nombrefichas::CABALLO || Tablero::casilla[l][i].ficha->getFicha() == Nombrefichas::PEON || Tablero::casilla[l][i].ficha->getFicha() == Nombrefichas::REINA || Tablero::casilla[l][i].ficha->getFicha() == Nombrefichas::TORRE)
								l = -1;
							if (Tablero::casilla[l][i].ficha->getFicha() == Nombrefichas::REY)
							{
								return true;
							}

						}
					}
					if (Tablero::casilla[k + 1][i].ficha->getFicha() == Nombrefichas::ALFIL || Tablero::casilla[k - 1][i].ficha->getFicha() == Nombrefichas::CABALLO || Tablero::casilla[k - 1][i].ficha->getFicha() == Nombrefichas::PEON || Tablero::casilla[k - 1][i].ficha->getFicha() == Nombrefichas::REY)
					{
						k = 9;//al llegar a una ficha que bloquea se deja de mirar esa direccion
					}
				}
			}
			//comprobamos si le amenazan por debajo
			for (int k = j - 1; k >= 1; k--)
			{
				if (((Tablero::casilla[k][i].amenazanegra == false) && (bando == 1)) || ((Tablero::casilla[k][i].amenazablanca == false) && (bando == 0)))
					k = -1;//si no est� amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o torre
				if (((Tablero::casilla[k][i].amenazanegra == true) && (bando == 1)) || ((Tablero::casilla[k][i].amenazablanca == true) && (bando == 0)))
				{
					if (((Tablero::casilla[k - 1][i].ficha->getFicha() == Nombrefichas::TORRE) && (Tablero::casilla[k - 1][i].bando == ob)) || ((Tablero::casilla[k - 1][i].ficha->getFicha() == Nombrefichas::REINA) && (Tablero::casilla[k - 1][i].bando == ob))) //en caso que est� amenazado por una torre o reina, comprobamos si el rey est� amenazado
					{
						for (int l = j + 1; l <= 8; l++)//miramos por encima de la ficha
						{
							if (Tablero::casilla[l][i].ficha->getFicha() == Nombrefichas::ALFIL || Tablero::casilla[l][i].ficha->getFicha() == Nombrefichas::CABALLO || Tablero::casilla[l][i].ficha->getFicha() == Nombrefichas::PEON || Tablero::casilla[l][i].ficha->getFicha() == Nombrefichas::REINA || Tablero::casilla[l][i].ficha->getFicha() == Nombrefichas::TORRE)
								l = 9;
							if ((Tablero::casilla[l][i].ficha->getFicha() == Nombrefichas::REY) && (Tablero::casilla[l][j].bando == bando))
							{
								return true;
							}

						}
					}
					if (Tablero::casilla[k - 1][i].ficha->getFicha() == Nombrefichas::ALFIL || Tablero::casilla[k - 1][i].ficha->getFicha() == Nombrefichas::CABALLO || Tablero::casilla[k - 1][i].ficha->getFicha() == Nombrefichas::PEON || Tablero::casilla[k - 1][i].ficha->getFicha() == Nombrefichas::REY)
					{
						k = -1;//al llegar a una ficha que bloquea se deja de mirar esa direccion
					}
				}
			}
			//comprobamos si le amenazan por la diagonal inferior izquierda
			for (int k = i - 1; k >= 1; k--)
			{
				if (((Tablero::casilla[j - (i - k)][k].amenazanegra == false) && (bando == 1)) || ((Tablero::casilla[j - (i - k)][k].amenazablanca == false) && (bando == 0)))
					k = -1;//si no est� amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o alfil
				if (((Tablero::casilla[j - (i - k)][k].amenazanegra == true) && (bando == 1)) || ((Tablero::casilla[j - (i - k)][k].amenazablanca == true) && (bando == 0)))
				{//comprueba si en la siguiente Tablero::casilla est� el alfil/reina que amenaza
					if (((Tablero::casilla[j - (i - k)][k - 1].ficha->getFicha() == Nombrefichas::ALFIL) && (Tablero::casilla[j - (i - k)][k - 1].bando == ob)) || ((Tablero::casilla[j - (i - k)][k - 1].ficha->getFicha() == Nombrefichas::REINA) && (Tablero::casilla[j - (i - k)][k - 1].bando == ob))) //en caso que est� amenazado por un alfil o reina, comprobamos si el rey est� amenazado
					{
						for (int l = i + 1; l <= 8; l++)//miramos arriba a la derecha
						{
							if (Tablero::casilla[j + (l - i)][l].ficha->getFicha() == Nombrefichas::ALFIL || Tablero::casilla[j + (l - i)][l].ficha->getFicha() == Nombrefichas::CABALLO || Tablero::casilla[j + (l - i)][l].ficha->getFicha() == Nombrefichas::PEON || Tablero::casilla[j + (l - i)][l].ficha->getFicha() == Nombrefichas::REINA || Tablero::casilla[j + (l - i)][l].ficha->getFicha() == Nombrefichas::TORRE)
								l = 9; //est� bloqueado el camino, asi que sale del bucle
							if ((Tablero::casilla[j + (l - i)][l].ficha->getFicha() == Nombrefichas::REY) && (Tablero::casilla[j + (l - i)][l].bando == bando))
							{
								return true;
							}
						}
					}
					if (Tablero::casilla[j - (i - k) - 1][k - 1].ficha->getFicha() == Nombrefichas::TORRE || Tablero::casilla[j - (i - k) - 1][k - 1].ficha->getFicha() == Nombrefichas::CABALLO || Tablero::casilla[j - (i - k) - 1][k - 1].ficha->getFicha() == Nombrefichas::PEON || Tablero::casilla[j - (i - k) - 1][k - 1].ficha->getFicha() == Nombrefichas::REY)
					{
						k = -1;//al llegar a una ficha que bloquea se deja de mirar esa direccion
					}
				}
			}
			//comprobamos si le amenazan por la diagonal inferior derecha
			for (int k = i + 1; k <= 8; k++)
			{
				if (((Tablero::casilla[j - (k - i)][k].amenazanegra == false) && (bando == 1)) || ((Tablero::casilla[j - (k - i)][k].amenazablanca == false) && (bando == 0)))
					k = 9;//si no est� amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o alfil
				if (((Tablero::casilla[j - (k - i)][k].amenazanegra == true) && (bando == 1)) || ((Tablero::casilla[j - (k - i)][k].amenazablanca == true) && (bando == 0)))
				{//comprueba si en la siguiente Tablero::casilla est� el alfil/reina que amenaza
					if (Tablero::casilla[j - (k - i) - 1][k + 1].ficha->getFicha() == Nombrefichas::ALFIL || Tablero::casilla[j - (k - i) - 1][k + 1].ficha->getFicha() == Nombrefichas::REINA) //en caso que est� amenazado por un alfil o reina, comprobamos si el rey est� amenazado
					{
						for (int l = i - 1; l >= 1; l--)//miramos arriba a izquierda
						{
							if (Tablero::casilla[j + (i - l)][l].ficha->getFicha() == Nombrefichas::ALFIL || Tablero::casilla[j + (i - l)][l].ficha->getFicha() == Nombrefichas::CABALLO || Tablero::casilla[j + (i - l)][l].ficha->getFicha() == Nombrefichas::PEON || Tablero::casilla[j + (i - l)][l].ficha->getFicha() == Nombrefichas::REINA || Tablero::casilla[j + (i - l)][l].ficha->getFicha() == Nombrefichas::TORRE)
								l = -1; //est� bloqueado el camino, asi que sale del bucle
							if ((Tablero::casilla[j + (i - l)][l].ficha->getFicha() == Nombrefichas::REY) && (Tablero::casilla[j + (i - l)][l].bando == bando))
							{
								return true;
							}
						}
					}
					if (Tablero::casilla[j - (k - i) - 1][k + 1].ficha->getFicha() == Nombrefichas::TORRE || Tablero::casilla[j - (k - i) - 1][k + 1].ficha->getFicha() == Nombrefichas::CABALLO || Tablero::casilla[j - (k - i) - 1][k + 1].ficha->getFicha() == Nombrefichas::PEON || ((Tablero::casilla[j - (k - i) - 1][k + 1].ficha->getFicha() == Nombrefichas::REY) && (Tablero::casilla[j - (k - i) - 1][k + 1].bando == ob)))
					{
						k = 9;//al llegar a una ficha que bloquea se deja de mirar esa direccion
					}
				}
			}
			//comprobamos si le amenazan por la diagonal superior izquierda
			for (int k = i - 1; k >= 1; k--)
			{
				if (((Tablero::casilla[j + (i - k)][k].amenazanegra == false) && (bando == 1)) || ((Tablero::casilla[j + (i - k)][k].amenazablanca == false) && (bando == 0)))
					k = -1;//si no est� amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o alfil
				if (((Tablero::casilla[j + (i - k)][k].amenazanegra == true) && (bando == 1)) || ((Tablero::casilla[j + (i - k)][k].amenazablanca == true) && (bando == 0)))
				{//comprueba si en la siguiente Tablero::casilla est� el alfil/reina que amenaza
					if (Tablero::casilla[j + (i - k) + 1][k - 1].ficha->getFicha() == Nombrefichas::ALFIL || Tablero::casilla[j + (i - k) + 1][k - 1].ficha->getFicha() == Nombrefichas::REINA) //en caso que est� amenazado por un alfil o reina, comprobamos si el rey est� amenazado
					{
						for (int l = i + 1; l <= 8; l++)//miramos abajo a la derecha
						{
							if (Tablero::casilla[j - (l - i)][l].ficha->getFicha() == Nombrefichas::ALFIL || Tablero::casilla[j - (l - i)][l].ficha->getFicha() == Nombrefichas::CABALLO || Tablero::casilla[j - (l - i)][l].ficha->getFicha() == Nombrefichas::PEON || Tablero::casilla[j - (l - i)][l].ficha->getFicha() == Nombrefichas::REINA || Tablero::casilla[j - (l - i)][l].ficha->getFicha() == Nombrefichas::TORRE)
								l = 9; //est� bloqueado el camino, asi que sale del bucle
							if ((Tablero::casilla[j - (l - i)][l].ficha->getFicha() == Nombrefichas::REY) && (Tablero::casilla[j - (l - i)][l].bando == bando))
							{
								return true;
							}
						}
					}
					if (Tablero::casilla[j + (i - k) + 1][k - 1].ficha->getFicha() == Nombrefichas::TORRE || Tablero::casilla[j + (i - k) + 1][k - 1].ficha->getFicha() == Nombrefichas::CABALLO || Tablero::casilla[j + (i - k) + 1][k - 1].ficha->getFicha() == Nombrefichas::PEON || Tablero::casilla[j + (i - k) + 1][k - 1].ficha->getFicha() == Nombrefichas::REY)
					{
						Tablero::casilla[j][i].clavada = false; //a�adido para evitar coincidencias en las que pueda parecer que est� amenazado por este tipo de pieza pero haya un enemigo distinto bloqueando el camino
						k = -1;//al llegar a una ficha que bloquea se deja de mirar esa direccion
					}
				}
			}
			//comprobamos si le amenazan por la diagonal superior derecha
			for (int k = i + 1; k <= 8; k++)
			{
				if (((Tablero::casilla[j + (k - i)][k].amenazanegra == false) && (bando == 1)) || ((Tablero::casilla[j + (k - i)][k].amenazablanca == false) && (bando == 0)))
					k = 9;//si no est� amenazado no comprueba el resto, evitando que confunda la amenaza de otra ficha con la de una reina o alfil
				if (((Tablero::casilla[j + (k - i)][k].amenazanegra == true) && (bando == 1)) || ((Tablero::casilla[j + (k - i)][k].amenazablanca == true) && (bando == 0)))
				{//comprueba si en la siguiente Tablero::casilla est� el alfil/reina que amenaza
					if (((Tablero::casilla[j + (k - i) + 1][k + 1].ficha->getFicha() == Nombrefichas::ALFIL) && (Tablero::casilla[j + (k - i) + 1][k + 1].bando == ob)) || ((Tablero::casilla[j + (k - i) + 1][k + 1].ficha->getFicha() == Nombrefichas::ALFIL) && (Tablero::casilla[j + (k - i) + 1][k + 1].bando == ob))) //en caso que est� amenazado por un alfil o reina, comprobamos si el rey est� amenazado
					{//Si est� la amenaza, comprueba detras de la pieza para ver si esta tu rey y por tanto estas clavada
						for (int l = i - 1; l >= 1; l--)//miramos abajo a la izquierda
						{
							if (Tablero::casilla[j - (i - l)][l].ficha->getFicha() == Nombrefichas::ALFIL || Tablero::casilla[j - (i - l)][l].ficha->getFicha() == Nombrefichas::CABALLO || Tablero::casilla[j - (i - l)][l].ficha->getFicha() == Nombrefichas::PEON || Tablero::casilla[j - (i - l)][l].ficha->getFicha() == Nombrefichas::REINA || Tablero::casilla[j - (i - l)][l].ficha->getFicha() == Nombrefichas::TORRE)
								l = -1; //est� bloqueado el camino, asi que sale del bucle
							if ((Tablero::casilla[j - (i - l)][l].ficha->getFicha() == Nombrefichas::REY) && (Tablero::casilla[j - (i - l)][l].bando == bando))//si hay un rey, del color de tus fichas, est� clavada
							{
								return true;
							}
						}
					}
					if (Tablero::casilla[j + (k - i) + 1][k + 1].ficha->getFicha() == Nombrefichas::TORRE || Tablero::casilla[j + (k - i) + 1][k + 1].ficha->getFicha() == Nombrefichas::CABALLO || Tablero::casilla[j + (k - i) + 1][k + 1].ficha->getFicha() == Nombrefichas::PEON || ((Tablero::casilla[j + (k - i) + 1][k + 1].ficha->getFicha() == Nombrefichas::REY) && (Tablero::casilla[j + (k - i) + 1][k + 1].bando == ob)))//con esta ultima cond evitamos que confunda el rey atacante con el tuyo
					{
						//a�adido para evitar coincidencias en las que pueda parecer que est� amenazado por este tipo de pieza pero haya un enemigo distinto bloqueando el camino
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
		for (int j = 1; j <= 8; j++)//con estos bucles anidados comprobaremos en todas las Tablero::casillas del tablero si la pieza est� amenazada
		{
			resultado = clavadaficha(bando, ob, i, j); //usando esta estructura conseguimos que en el momento en el que resulte como clavada salga del bucle y pase a la siguiente Tablero::casilla
			Tablero::casilla[j][i].clavada = resultado;
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
					if (Tablero::casilla[i][j].f == filaini && Tablero::casilla[i][j].c == columnaini && Tablero::casilla[i][j].estado == 0) {
						"No hay ninguna ficha en dichas coordenadas";
					}
					if (Tablero::casilla[i][j].f == filaini && Tablero::casilla[i][j].c == columnaini && Tablero::casilla[i][j].estado == 1)
						break;
				}
			}
		}

	} while (filaini > 8 || columnaini > 8 || filaini < 0 || columnaini < 0 || Tablero::casilla[filaini][columnaini].estado == 0);
	//As� nos aseguramos que las coordenadas introducidas son correctas, est�n dentro del tablero y hay una ficha en dicha Tablero::casilla



	int filafin = 0, columnafin = 0, r = 0;

	do {
		cout << "Introduzca la fila y columna a donde quiere mover la ficha: ";
		cin >> filafin >> columnafin;
	} while (filafin > 8 || columnafin > 8 || filafin < 0 || columnafin < 0);//As� nos aseguramos que las coordenadas introducidas son correctas y est�n dentro del tablero

	if (Tablero::casilla[filaini][columnaini].ficha->getFicha() == Nombrefichas::ALFIL)
		r = 1;
	if (Tablero::casilla[filaini][columnaini].ficha->getFicha() == Nombrefichas::TORRE)
		r = 2;
	if (Tablero::casilla[filaini][columnaini].ficha->getFicha() == Nombrefichas::CABALLO)
		r = 3;
	if (Tablero::casilla[filaini][columnaini].ficha->getFicha() == Nombrefichas::PEON)
		r = 4;
	if (Tablero::casilla[filaini][columnaini].ficha->getFicha() == Nombrefichas::REY)
		r = 5;
	if (Tablero::casilla[filaini][columnaini].ficha->getFicha() == Nombrefichas::REINA)
		r = 6;

	switch (r) {
	case 1:
		if (alfil.restricciones(filafin, columnafin, filaini, columnaini)) {
			ocupar(filafin, columnafin, Nombrefichas::ALFIL, Tablero::casilla[filaini][columnaini].fcolor);
			vaciar(filaini, columnaini);
		}
		else
			cout << "Movimiento no permitido";
		break;
	case 2:
		if (torre.restricciones(filafin, columnafin, filaini, columnaini)) {
			ocupar(filafin, columnafin, Nombrefichas::TORRE, Tablero::casilla[filaini][columnaini].fcolor);
			vaciar(filaini, columnaini);
		}
		else
			cout << "Movimiento no permitido";
		break;
	case 3:
		if (caballo.restricciones(filafin, columnafin, filaini, columnaini)) {
			ocupar(filafin, columnafin, Nombrefichas::CABALLO, Tablero::casilla[filaini][columnaini].fcolor);
			vaciar(filaini, columnaini);
		}
		else
			cout << "Movimiento no permitido";
		break;
	case 4:
		if (peon.restricciones(filafin, columnafin, filaini, columnaini)) {
			ocupar(filafin, columnafin, Nombrefichas::PEON, Tablero::casilla[filaini][columnaini].fcolor);
			vaciar(filaini, columnaini);
		}
		else
			cout << "Movimiento no permitido";
		break;
	case 5:
		if (rey.restricciones(filafin, columnafin, filaini, columnaini)) {
			ocupar(filafin, columnafin, Nombrefichas::REY, Tablero::casilla[filaini][columnaini].fcolor);
			vaciar(filaini, columnaini);
		}
		else
			cout << "Movimiento no permitido";
		break;
	case 6:
		if (reina.restricciones(filafin, columnafin, filaini, columnaini)) {
			ocupar(filafin, columnafin, Nombrefichas::REINA, Tablero::casilla[filaini][columnaini].fcolor);
			vaciar(filaini, columnaini);
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

		//la i es la fila y la j la columna: Tablero::casilla[fila][columna]
		Tablero::casilla[i][j].f = i;
		Tablero::casilla[i][j].c = j;
		Tablero::casilla[i][j].numero = n;

		if (i % 2 == j % 2) Tablero::casilla[i][j].color = 'b';
		else Tablero::casilla[i][j].color = 'w';


		Tablero::casilla[i][j].centrox = 1 + i;
		Tablero::casilla[i][j].centroy = 1 + j;




		n++;
		if (j < 8) j++;
		else {
			j = 1;
			i++;
		}
	}
	//se fora una matriz [filas(8)][columnas(8)] que recorre cada fila de izquierda a derecha (1-8) y  cuando acaba con la fila pasa a la fila superior.

}

void juego::ocupar(int fila, int columna, Nombrefichas pieza, char colorficha) {

	Tablero::casilla[fila][columna].estado = 1;
	Tablero::casilla[fila][columna].fcolor = colorficha;
	Tablero::casilla[fila][columna].ficha->setFicha(pieza);
	Tablero::casilla[fila][columna].ficha->setPos(fila, columna);
	Tablero::casilla[fila][columna].ficha->setColor(colorficha);

}

void juego::vaciar(int fila, int columna) {

	Tablero::casilla[fila][columna].estado = 0;
	Tablero::casilla[fila][columna].ficha->setFicha(Nombrefichas::VACIO);
	Tablero::casilla[fila][columna].ficha->borrarcontenido();

}

int juego::jaque(int xatacante, int yatacante, int bando, int xrey, int yrey) { //comprueba si el rey est� en jaque, y si lo est�, comprueba si est� en jaque mate
	//datos de prueba, luego ser�n sustituidos por los equivalentes en la clase tablero
	int entry = 0;//entrada a switch case
	Nombrefichas atacante = Tablero::casilla[yatacante][xatacante].ficha->getFicha();// miramos que tipo de ficha es la que ataca, creo que esto esta mal planteado, habra que tener de input a la funcion la ficha atacante directamente
	int bandoatacante;
	if (bando == 1)
		bandoatacante = 0;
	else
		bandoatacante = 1; //ponemos al bando atacante como contrario del defensor y comprobamos si est� amenazada
	//primero de todo comprobaremos si la posicion del rey est� amenazada
	//IMPORTANTE: ANTES DE LA FUNCION JAQUE, LA FUNCION CLAVADA TIENE QUE HACER UNA PASADA POR TODAS LAS FICHAS DEL BANDO AL QUE SE HACE JAQUE, PARA QUE LAS CLAVADAS NO PUEDAN COMER NI AMENAZAR

	if ((bando == 1) && (Tablero::casilla[yrey][xrey].amenazanegra == true) || ((bando == 0) && (Tablero::casilla[yrey][xrey].amenazablanca == true))) //la posici�n del rey est� amenazada, por tanto es jaque, ahora comprobamos si hay jaque mate, empezando por ver si el rey puede huir
	{
		if ((((bando == 1) && (Tablero::casilla[yrey + 1][xrey].amenazanegra == false)) && (Tablero::casilla[yrey + 1][xrey].bando != bando)) || (((bando == 0) && (Tablero::casilla[yrey + 1][xrey].amenazablanca == false)) && (Tablero::casilla[yrey + 1][xrey].bando != bando)))
			return 1; //1 significa que est� en jaque, pero no en jaque mate
		if ((((bando == 1) && (Tablero::casilla[yrey - 1][xrey].amenazanegra == false)) && (Tablero::casilla[yrey - 1][xrey].bando != bando)) || (((bando == 0) && (Tablero::casilla[yrey - 1][xrey].amenazablanca == false)) && (Tablero::casilla[yrey - 1][xrey].bando != bando)))
			return 1;
		if ((((bando == 1) && (Tablero::casilla[yrey][xrey + 1].amenazanegra == false)) && (Tablero::casilla[yrey][xrey + 1].bando != bando)) || (((bando == 0) && (Tablero::casilla[yrey][xrey + 1].amenazablanca == false)) && (Tablero::casilla[yrey + 1][xrey].bando != bando)))
			return 1;
		if ((((bando == 1) && (Tablero::casilla[yrey + 1][xrey + 1].amenazanegra == false)) && (Tablero::casilla[yrey + 1][xrey + 1].bando != bando)) || (((bando == 0) && (Tablero::casilla[yrey + 1][xrey + 1].amenazablanca == false)) && (Tablero::casilla[yrey + 1][xrey].bando != bando)))
			return 1;
		if ((((bando == 1) && (Tablero::casilla[yrey - 1][xrey + 1].amenazanegra == false)) && (Tablero::casilla[yrey - 1][xrey + 1].bando != bando)) || (((bando == 0) && (Tablero::casilla[yrey - 1][xrey + 1].amenazablanca == false)) && (Tablero::casilla[yrey + 1][xrey].bando != bando)))
			return 1;
		if ((((bando == 1) && (Tablero::casilla[yrey][xrey - 1].amenazanegra == false)) && (Tablero::casilla[yrey][xrey - 1].bando != bando)) || (((bando == 0) && (Tablero::casilla[yrey][xrey - 1].amenazablanca == false)) && (Tablero::casilla[yrey + 1][xrey].bando != bando)))
			return 1;
		if ((((bando == 1) && (Tablero::casilla[yrey + 1][xrey - 1].amenazanegra == false)) && (Tablero::casilla[yrey + 1][xrey - 1].bando != bando)) || (((bando == 0) && (Tablero::casilla[yrey + 1][xrey - 1].amenazablanca == false)) && (Tablero::casilla[yrey + 1][xrey].bando != bando)))
			return 1;
		if ((((bando == 1) && (Tablero::casilla[yrey - 1][xrey - 1].amenazanegra == false)) && (Tablero::casilla[yrey - 1][xrey - 1].bando != bando)) || (((bando == 0) && (Tablero::casilla[yrey + 1][xrey - 1].amenazablanca == false)) && (Tablero::casilla[yrey + 1][xrey].bando != bando)))
			return 1;
		//en caso de que el rey no haya podido huir por ninguna de las posiciones colindantes, comprobamos si se puede eliminar la amenaza
		if (((bando == 1) && (Tablero::casilla[yatacante][xatacante].amenazablanca == true)) || (((bando == 0) && (Tablero::casilla[yatacante][xatacante].amenazanegra == true))))
			return 1;
		else
		{
			//esto significa que no podemos comernos al atacante, por lo que la �nica opci�n que queda es bloquear su camino, cosa que solo se puede si es una Reina, una Torre o un Alfil
			if (Tablero::casilla[yatacante][xatacante].ficha->getFicha() == Nombrefichas::PEON)
				entry = 1;
			if (Tablero::casilla[yatacante][xatacante].ficha->getFicha() == Nombrefichas::CABALLO)
				entry = 2;
			if (Tablero::casilla[yatacante][xatacante].ficha->getFicha() == Nombrefichas::TORRE)
				entry = 3;
			if (Tablero::casilla[yatacante][xatacante].ficha->getFicha() == Nombrefichas::ALFIL)
				entry = 4;
			if (Tablero::casilla[yatacante][xatacante].ficha->getFicha() == Nombrefichas::REINA)
				entry = 5;
			if (Tablero::casilla[yatacante][xatacante].ficha->getFicha() == Nombrefichas::REY)
				entry = 6;
			if (Tablero::casilla[yatacante][xatacante].ficha->getFicha() == Nombrefichas::VACIO)
				entry = 0;
			switch (entry/*tablero[yatacante][xatacante].ficha*/) {
			case 1://peon
				return 2;
			case 2://caballo
				return 2;
			case 3: //torre
			{
				if (xatacante == xrey) //est�n en la misma columna
				{
					if (yatacante < yrey) //si est� debajo del rey, comprobamos las Tablero::casillas que tiene encima una a una
					{
						for (int i = 1; (yatacante + i) < yrey; i++)
						{
							if (bando == 1)
							{
								if (Tablero::casilla[yatacante + i][xatacante].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (Tablero::casilla[yatacante + i][xatacante].amenazanegra == true)
									return 1;
							}
						}
					}
					if (yatacante > yrey)  //si est� encima del rey, comprobamos las Tablero::casillas que tiene debajo una a una
					{
						for (int i = 1; (yatacante - i) > yrey; i++)
						{
							if (bando == 1)
							{
								if (Tablero::casilla[yatacante - i][xatacante].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (Tablero::casilla[yatacante - i][xatacante].amenazanegra == true)
									return 1;
							}
						}
					}
					return 2; //si ninguna de las iteraciones ha encontrado un bloqueo para el ataque, es jaque mate
				}

				if (yatacante == yrey) //est�n en la misma columna
				{
					if (xatacante < xrey) //si est� a la izquierda del rey, comprobamos las Tablero::casillas en el camino una a una
					{
						for (int i = 1; (xatacante + i) < xrey; i++)
						{
							if (bando == 1)
							{
								if (Tablero::casilla[yatacante][xatacante + i].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (Tablero::casilla[yatacante][xatacante + i].amenazanegra == true)
									return 1;
							}
						}
					}
					if (xatacante > xrey) //si est� a la derecha del rey, comprobamos las Tablero::casillas en el camino una a una
					{
						for (int i = 1; (xatacante - i) < xrey; i++)
						{
							if (bando == 1)
							{
								if (Tablero::casilla[yatacante][xatacante - i].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (Tablero::casilla[yatacante][xatacante - i].amenazanegra == true)
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
							if (Tablero::casilla[yatacante + i][xatacante + i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (Tablero::casilla[yatacante + i][xatacante + i].amenazanegra == true)
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
							if (Tablero::casilla[yatacante + i][xatacante - i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (Tablero::casilla[yatacante + i][xatacante - i].amenazanegra == true)
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
							if (Tablero::casilla[yatacante - i][xatacante + i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (Tablero::casilla[yatacante - i][xatacante + i].amenazanegra == true)
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
							if (Tablero::casilla[yatacante - i][xatacante - i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (Tablero::casilla[yatacante - i][xatacante - i].amenazanegra == true)
								return 1;
						}
					}
				}
				return 2; //si no se puede bloquear la trayectoria de la amenaza, es jaque mate
			} //no pasa nada por comprobar siempre la y, ya que al moverse en diagonal, la distancia que habra en x e y al rey ser� siempre igual
			case 5: //reina, combinamos las condiciones de la torre y el alfil
			{
				if (xatacante == xrey) //est�n en la misma columna
				{
					if (yatacante < yrey) //si est� debajo del rey, comprobamos las Tablero::casillas que tiene encima una a una
					{
						for (int i = 1; (yatacante + i) < yrey; i++)
						{
							if (bando == 1)
							{
								if (Tablero::casilla[yatacante + i][xatacante].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (Tablero::casilla[yatacante + i][xatacante].amenazanegra == true)
									return 1;
							}
						}
					}
					if (yatacante > yrey)  //si est� encima del rey, comprobamos las Tablero::casillas que tiene debajo una a una
					{
						for (int i = 1; (yatacante - i) > yrey; i++)
						{
							if (bando == 1)
							{
								if (Tablero::casilla[yatacante - i][xatacante].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (Tablero::casilla[yatacante - i][xatacante].amenazanegra == true)
									return 1;
							}
						}
					}
					return 2; //si ninguna de las iteraciones ha encontrado un bloqueo para el ataque, es jaque mate
				}

				if (yatacante == yrey) //est�n en la misma columna
				{
					if (xatacante < xrey) //si est� a la izquierda del rey, comprobamos las Tablero::casillas en el camino una a una
					{
						for (int i = 1; (xatacante + i) < xrey; i++)
						{
							if (bando == 1)
							{
								if (Tablero::casilla[yatacante][xatacante + i].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (Tablero::casilla[yatacante][xatacante + i].amenazanegra == true)
									return 1;
							}
						}
					}
					if (xatacante > xrey) //si est� a la derecha del rey, comprobamos las Tablero::casillas en el camino una a una
					{
						for (int i = 1; (xatacante - i) < xrey; i++)
						{
							if (bando == 1)
							{
								if (Tablero::casilla[yatacante][xatacante - i].amenazablanca == true)
									return 1; //se ha podido bloquear alguno de los puntos intermedios
							}
							if (bando == 0)
							{
								if (Tablero::casilla[yatacante][xatacante - i].amenazanegra == true)
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
							if (Tablero::casilla[yatacante + i][xatacante + i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (Tablero::casilla[yatacante + i][xatacante + i].amenazanegra == true)
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
							if (Tablero::casilla[yatacante + i][xatacante - i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (Tablero::casilla[yatacante + i][xatacante - i].amenazanegra == true)
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
							if (Tablero::casilla[yatacante - i][xatacante + i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (Tablero::casilla[yatacante - i][xatacante + i].amenazanegra == true)
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
							if (Tablero::casilla[yatacante - i][xatacante - i].amenazablanca == true)
								return 1; //se ha podido bloquear alguno de los puntos intermedios
						}
						if (bando == 0)
						{
							if (Tablero::casilla[yatacante - i][xatacante - i].amenazanegra == true)
								return 1;
						}
					}
				}
				return 2; //si no se puede bloquear la trayectoria de la amenaza, es jaque mate
			}
			case 6:
				return 2;
				break; //los casos que solo tienen return 2 son porque esa pieza, al saltar a la posicion de ataque sin seguir una trayectoria, no se puede bloquear, por tanto es jaque mate autom�ticamente

			}
		}
	}
	else
		return 0;//si no est� amenazado siquiera, retorna 0, que significa que no hay ni jaque ni jaque mate
}
