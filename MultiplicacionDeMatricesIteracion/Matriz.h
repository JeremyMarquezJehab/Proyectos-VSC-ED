/*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
  JEREMY JOEL MARQUEZ CRESPO
  ESTRUCTURA DE DATOS                    */
#pragma once
#include <malloc.h>
#include <iostream>
#include <stdio.h>

template <typename T>
class Matriz {
private:
    T*** mat;
    int fila;
    int col;
    int prof;

public:
    Matriz(int f, int c, int p) {
        this->fila = f;
        this->col = c;
        this->prof = p;

        mat = (T***)malloc(sizeof(T**) * fila);
        for (int i = 0; i < fila; i++) {
            *(mat + i) = (T**)malloc(sizeof(T*) * col);
            for (int j = 0; j < col; j++) {
                *(*(mat + i) + j) = (T*)malloc(sizeof(T) * prof);
            }
        }
    }

    void ingresar() {
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

    void imprimir() {
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

    Matriz<T> operator+(Matriz<T>& otra) {
        Matriz<T> resultado(fila, col, prof); 
        for (int i = 0; i < fila; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < prof; k++) {
                    *(*(*(resultado.mat + i) + j) + k) = 
                        *(*(*(mat + i) + j) + k) + *(*(*(otra.mat + i) + j) + k);
                }
            }
        }
        return resultado;
    }

    Matriz<T> operator*(Matriz<T>& otra) {
        Matriz<T> resultado(fila, col, prof);
        
        for (int i = 0; i < fila; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < prof; k++) {
                    *(*(*(resultado.mat + i) + j) + k) = 0;
                }
            }
        }

        for (int k = 0; k < prof; k++) {
            for (int i = 0; i < fila; i++) {
                for (int j = 0; j < col; j++) {
                    for (int x = 0; x < col; x++) {
                        *(*(*(resultado.mat + i) + j) + k) += 
                            (*(*(*(mat + i) + x) + k)) * (*(*(*(otra.mat + x) + j) + k));
                    }
                }
            }
        }
        return resultado;
    }

    Matriz<T> operator*(T escalar) {
        Matriz<T> resultado(fila, col, prof);
        for (int i = 0; i < fila; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < prof; k++) {
                    *(*(*(resultado.mat + i) + j) + k) = 
                        (*(*(*(mat + i) + j) + k)) * escalar;
                }
            }
        }
        return resultado;
    }
};