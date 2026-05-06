/*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
  JEREMY JOEL MARQUEZ CRESPO
  ESTRUCTURA DE DATOS                    */
#ifndef OPERACION_H
#define OPERACION_H
#include "Matriz.h"

class Operacion {
public:
    void encerar(float*** mat, int fila, int col, int prof);
    void ingresar(float*** mat, int fila, int col, int prof);
    void imprimir(float*** mat, int fila, int col, int prof);
    void sumar(float*** matA, float*** matB,float*** matR, int fila, int col, int prof);
};

#endif