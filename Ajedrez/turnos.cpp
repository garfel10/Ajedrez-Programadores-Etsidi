#include "Nombrefichas.h"
#include "Fichas.h"
#include "casilla.h"
#include "Normas.cpp"
#include "Normas.h"
#include "Fichas.cpp"
#include "turnos.h"
#include "juego.h"
#include "juego.cpp"

//posiblemente se coloque el codigo directamente en main, tras la selección del juego en el menú
void turnos() {
	
	//generación del tablero, primero todas las casillas como huecos
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			tablero[i][j].iniciar();
		}
	}
	
	for (int i = 1; i <=8; i++)
	{
		tablero[2][i].ocupar(1, Nombrefichas::PEON, 'w'); //coloca los peones blancos en la segunda fila desde abajo
		tablero[7][i].ocupar(1, Nombrefichas::PEON, 'b'); //coloca los peones negros en la penúltima fila
	}
	//RESTO DE PIEZAS BLANCAS
	tablero[1][5].ocupar(1, Nombrefichas::REY, 'w');
	tablero[1][4].ocupar(1, Nombrefichas::REINA, 'w');
	tablero[1][2].ocupar(1, Nombrefichas::CABALLO, 'w');
	tablero[1][7].ocupar(1, Nombrefichas::CABALLO, 'w');
	tablero[1][3].ocupar(1, Nombrefichas::ALFIL, 'w');
	tablero[1][6].ocupar(1, Nombrefichas::ALFIL, 'w');
	tablero[1][1].ocupar(1, Nombrefichas::TORRE, 'w');
	tablero[1][8].ocupar(1, Nombrefichas::TORRE, 'w');
	//RESTO DE PIEZAS NEGRAS
	tablero[8][5].ocupar(1, Nombrefichas::REY, 'b');
	tablero[8][4].ocupar(1, Nombrefichas::REINA, 'b');
	tablero[8][2].ocupar(1, Nombrefichas::CABALLO, 'b');
	tablero[8][7].ocupar(1, Nombrefichas::CABALLO, 'b');
	tablero[8][3].ocupar(1, Nombrefichas::ALFIL, 'b');
	tablero[8][6].ocupar(1, Nombrefichas::ALFIL, 'b');
	tablero[8][1].ocupar(1, Nombrefichas::TORRE, 'b');
	tablero[8][8].ocupar(1, Nombrefichas::TORRE, 'b');
	int jaqueresultado = 0;
	int bando;
	int posatacante[1];
	bool estaenjaque = false;

	int ganador=2; //empieza en un valor que no es ni 1=blancas ni 0=negras
	
	while (jaqueresultado !=2) //mientras no haya jaque mate, se repetirá el ciclo
	{
		bando = 1;//movimiento de blancas, siendo estas las primeras
		posatacante[1]=mover(tablero, bando,estaenjaque); //tras mover una ficha, recibimos la posicion del atacante, si incluimos esto como método en una clase será más cómodo ya que modificara los valores de xatacante e yatacante
		//representación gráfica del movimiento
		tablero.amenazar(bando); //vemos que casillas están amenazadas por este bando
		tablero.clavada(tablero, bando); //vemos que piezas están clavadas por las amenazas
		jaqueresultado=jaque(tablero,bando, posatacante[0], posatacante[1]);//comprobamos si hay jaque o jaque mate
		if (jaqueresultado == 1) //si hay jaque, el movimiento del otro bando se verá condicionado
		{
			estaenjaque == true;
		}
		if (jaqueresultado == 0) //si no hay jaque, el movimiento del otro bando no se verá condicionado
		{
			estaenjaque == false;
		}
		if (jaqueresultado == 2)
			ganador = 1;//ganan las blancas
		if(jaqueresultado!=2)
		{
			bando=0; //cambio de bando
			posatacante[1]=mover(tablero, bando, estaenjaque);
			juego::amenazar(bando);
			juego::clavada(bando);
			jaqueresultado = jaque(tablero,bando, posatacante[0], posatacante[1]);
			if (jaqueresultado == 1) //si hay jaque, el movimiento del otro bando se verá condicionado
			{
				estaenjaque == true;
			}
			if (jaqueresultado == 0) //si hay jaque, el movimiento del otro bando no se verá condicionado
			{
				estaenjaque == false;
			}
			if (jaqueresultado == 2)
				ganador = 0;//ganan las negras
		}
		
	}
	victoria(ganador);
}
void victoria(int bando)
{
	//representacion gráfica del ganador, "ganan blancas", "ganan negras", o si ponemos que puedas poner nombres "gana nombreblancas", "gana nombrenegras"
}
int mover(casillas tablero[8][8], int bando, bool jaque)
{
	int posfinal[1];

	return posfinal[1];
}