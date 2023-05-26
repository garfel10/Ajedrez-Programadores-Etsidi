#include "Tablero.h"
#include <freeglut.h>
#include"casilla.h"

void Tablero::dibuja(){
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0) {
                glDisable(GL_LIGHTING);
                glColor3ub(253, 253, 180); //marron claro
                glBegin(GL_POLYGON);
                glVertex3f(i + 1.5, j + 1.5, 0);
                glVertex3f(i + 1.5, j + 2.5, 0);
                glVertex3f(i + 2.5, j + 2.5, 0);
                glVertex3f(i + 2.5, j + 1.5, 0);
                glEnd();
            }
            else {
                glColor3ub(150, 55, 0); //marron oscuro 
                glBegin(GL_POLYGON);
                glVertex3f(i + 1.5, j + 1.5, 0);
                glVertex3f(i + 1.5, j + 2.5, 0);
                glVertex3f(i + 2.5, j + 2.5, 0);
                glVertex3f(i + 2.5, j + 1.5, 0);
                glEnd();
            }
            glEnable(GL_LIGHTING);
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch (casilla[i][j].ficha.getFicha()) {
			case Nombrefichas::ALFIL:
				alfil.dibujar();
				break;
			case Nombrefichas::TORRE:
                torre.dibujar();
				break;
			case Nombrefichas::CABALLO:
                caballo.dibujar();
				break;
			case Nombrefichas::PEON:
                peon.dibujar();
				break;
			case Nombrefichas::REY:
                rey.dibujar();
				break;
			case Nombrefichas::REINA:
                reina.dibujar();
				break;
            }
        }
    }
}
