/*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
  JEREMY JOEL MARQUEZ CRESPO
  ESTRUCTURA DE DATOS                    */
#include "Matriz.h"
#include <stdlib.h>

Matriz::Matriz(int f, int c, int p) {
    fila = f;
    col = c;
    prof = p;

    mat = (float***)malloc(sizeof(float**) * fila);
    
    for (int i = 0; i < fila; i++) {
        *(mat + i) = (float**)malloc(sizeof(float*) * col);
        for (int j = 0; j < col; j++) {
            *(*(mat + i)+j) = (float*)malloc(sizeof(float) * prof);
        }
    }
}

float*** Matriz::getMat() { 
    return mat; 
}

int Matriz::getFila() { 
    return fila; 
}

int Matriz::getCol() { 
    return col; 
}
int Matriz::getProf() {
    return prof;
}