/*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
  JEREMY JOEL MARQUEZ CRESPO
  ESTRUCTURA DE DATOS                    */
#pragma once
#include <iostream>
#include <stdio.h>

template <typename T>
class Operacion {
public:
    void ingresar(T*** mat, int fila, int col, int prof) {
        for (int k = 0; k < prof; k++) {
            printf("\n---> Llenando Capa %d <---\n", k + 1);
            for (int i = 0; i < fila; i++) {
                for (int j = 0; j < col; j++) {
                    printf("Fila %d, Columna %d: ", i + 1, j + 1);
                    std::cin >> *(*(*(mat + i) + j) + k);
                }
            }
        }
    }

    void imprimir(T*** mat, int fila, int col, int prof) {
        for (int k = 0; k < prof; k++) {
            printf("\n--- Capa %d ---\n", k + 1);
            for (int i = 0; i < fila; i++) {
                printf("| ");
                for (int j = 0; j < col; j++) {
                    std::cout << *(*(*(mat + i) + j) + k) << "\t";
                }
                printf(" |\n");
            }
        }
        printf("\n");
    }

    void multiplicar(T*** matA, T*** matB, T*** matR, int fila, int col, int prof) {
        // Primero enceramos la matriz resultante
        for (int i = 0; i < fila; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < prof; k++) {
                    *(*(*(matR + i) + j) + k) = 0;
                }
            }
        }

        for (int k = 0; k < prof; k++) {
            for (int i = 0; i < fila; i++) {
                for (int j = 0; j < col; j++) {
                    for (int x = 0; x < col; x++) {
                        *(*(*(matR + i) + j) + k) += 
                            (*(*(*(matA + i) + x) + k)) * (*(*(*(matB + x) + j) + k));
                    }
                }
            }
        }
    }
};