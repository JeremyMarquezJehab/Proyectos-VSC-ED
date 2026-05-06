/*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
  JEREMY JOEL MARQUEZ CRESPO
  ESTRUCTURA DE DATOS                    */
#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz {
private:
    float*** mat;
    int fila;
    int col;
    int prof;

public:
    Matriz(int f, int c, int p);
    float*** getMat();
    int getFila();
    int getCol();
    int getProf();
};

#endif