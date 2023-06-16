#pragma once
#include "casilla.h"
class juego :
    public casillas
{
public:
    void limpiaramenazas();
    void amenazar(int bando);
    bool clavadaficha(int bando, int ob, int i, int j);
    void clavada(int bando);
    void movimiento();
    void casillero();
    void ocupar(int fila, int columna, Nombrefichas pieza, char colorficha);
    void vaciar(int fila, int columna);
    int jaque(int xatacante, int yatacante, int bando, int xrey, int yrey);
   
};

