/*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
  JEREMY JOEL MARQUEZ CRESPO
  ESTRUCTURA DE DATOS                    */
#define _CRT_SECURE_NO_WARNINGS1
#include "Operacion.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void Operacion::encerar(float*** mat, int fila, int col, int prof) {
    int i, j,k;
    for (i = 0; i < fila; i++) {
        for (j = 0; j < col; j++) {
            for (int k = 0; k < prof; k++) {
                mat[i][j][k] = 0;
            }
        }
    }
}

void Operacion::ingresar(float*** mat, int fila, int col, int prof) {
    for (int k = 0; k < prof; k++) {
        printf("\n---> Llenando Capa %d <---\n", k + 1);
        for (int i = 0; i < fila; i++) {
            for (int j = 0; j < col; j++) {
                printf("Fila %d, Columna %d: ", i + 1, j + 1);
                scanf_s("%f", (*(*(mat + i) + j) + k)); 
            }
        }
    }
}

void Operacion::sumar(float*** matA, float*** matB, float*** matR, int fila, int col, int prof) {
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < prof; k++) {
                *(*(*(matR + i) + j) + k) = *(*(*(matA + i) + j) + k) + *(*(*(matB + i) + j) + k);
            }
        }
    }
}

void Operacion::imprimir(float*** mat, int fila, int col, int prof) {
    for (int k = 0; k < prof; k++) {
        printf("\n--- Capa %d ---\n", k + 1);
        for (int i = 0; i < fila; i++) {
            printf("| "); 
            for (int j = 0; j < col; j++) {
                printf("%8.2f ", *(*(*(mat + i) + j) + k));
            }
            printf(" |\n");
        }
    }
    printf("\n");
}