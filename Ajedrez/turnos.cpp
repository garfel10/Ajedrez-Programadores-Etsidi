
#include "Normas.cpp"
#include "Normas.h"
#include "turnos.h"
#include "juego.h"

//posiblemente se coloque el codigo directamente en main, tras la selecci�n del juego en el men�
void turnos() {
	juego juego;
	int xrey=0, yrey = 0; //temporal, se sacar�n de juego en cada turno
	
	//generaci�n del tablero, primero todas las casillas como huecos
	
	juego.casillero();
	
	for (int i = 1; i <=8; i++)
	{
		juego.ocupar(2,i, Nombrefichas::PEON, 'w'); //coloca los peones blancos en la segunda fila desde abajo
		juego.ocupar(7,i, Nombrefichas::PEON, 'b'); //coloca los peones negros en la pen�ltima fila
	}
	//RESTO DE PIEZAS BLANCAS
	juego.ocupar(1,5, Nombrefichas::REY, 'w');
	juego.ocupar(1,4, Nombrefichas::REINA, 'w');
	juego.ocupar(1,2, Nombrefichas::CABALLO, 'w');
	juego.ocupar(1,7, Nombrefichas::CABALLO, 'w');
	juego.ocupar(1,3, Nombrefichas::ALFIL, 'w');
	juego.ocupar(1,6, Nombrefichas::ALFIL, 'w');
	juego.ocupar(1,1, Nombrefichas::TORRE, 'w');
	juego.ocupar(1,8, Nombrefichas::TORRE, 'w');
	//RESTO DE PIEZAS NEGRAS
	juego.ocupar(8,5, Nombrefichas::REY, 'b');
	juego.ocupar(8,4, Nombrefichas::REINA, 'b');
	juego.ocupar(8,2, Nombrefichas::CABALLO, 'b');
	juego.ocupar(8,7, Nombrefichas::CABALLO, 'b');
	juego.ocupar(8,3, Nombrefichas::ALFIL, 'b');
	juego.ocupar(8,6, Nombrefichas::ALFIL, 'b');
	juego.ocupar(8,1, Nombrefichas::TORRE, 'b');
	juego.ocupar(8,8, Nombrefichas::TORRE, 'b');
	int jaqueresultado = 0;
	int bando;
	int posatacante[1];
	bool estaenjaque = false;
	

	int ganador=2; //empieza en un valor que no es ni 1=blancas ni 0=negras
	
	while (jaqueresultado !=2) //mientras no haya jaque mate, se repetir� el ciclo
	{
		bando = 1;//movimiento de blancas, siendo estas las primeras
		//posatacante[1]=mover(tablero, bando,estaenjaque); //tras mover una ficha, recibimos la posicion del atacante, si incluimos esto como m�todo en una clase ser� m�s c�modo ya que modificara los valores de xatacante e yatacante
		//representaci�n gr�fica del movimiento
		juego.amenazar(bando); //vemos que casillas est�n amenazadas por este bando
		juego.clavada(bando); //vemos que piezas est�n clavadas por las amenazas
		//jaqueresultado=jaque(j,bando, posatacante[0], posatacante[1]);//comprobamos si hay jaque o jaque mate
		if (jaqueresultado == 1) //si hay jaque, el movimiento del otro bando se ver� condicionado
		{
			estaenjaque == true;
		}
		if (jaqueresultado == 0) //si no hay jaque, el movimiento del otro bando no se ver� condicionado
		{
			estaenjaque == false;
		}
		if (jaqueresultado == 2)
			ganador = 1;//ganan las blancas
		if(jaqueresultado!=2)
		{
			bando=0; //cambio de bando
			//posatacante[1]=mover(casilla, bando, estaenjaque);
			juego.amenazar(bando);
			juego.clavada(bando);
			jaqueresultado = jaque(casilla,bando, posatacante[0], posatacante[1], xrey, yrey);
			if (jaqueresultado == 1) //si hay jaque, el movimiento del otro bando se ver� condicionado
			{
				estaenjaque == true;
			}
			if (jaqueresultado == 0) //si hay jaque, el movimiento del otro bando no se ver� condicionado
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
	//representacion gr�fica del ganador, "ganan blancas", "ganan negras", o si ponemos que puedas poner nombres "gana nombreblancas", "gana nombrenegras"
}
/*int mover(casillas tablero[8][8], int bando, bool jaque)
{
	int posfinal[1];

	return posfinal[1];
}
*/