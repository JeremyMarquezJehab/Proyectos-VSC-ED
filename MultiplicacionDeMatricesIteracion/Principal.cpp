/*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
  JEREMY JOEL MARQUEZ CRESPO
  ESTRUCTURA DE DATOS                    */
#include <iostream>
#include "Matriz.h"

int main() {
    int f = 2, c = 2, p = 2;
    
    Matriz<float> m1(f, c, p);
    Matriz<float> m2(f, c, p);

    std::cout << "===========================\n";
    std::cout << "      INGRESO MATRIZ 1     \n";
    std::cout << "===========================\n";
    m1.ingresar();

    std::cout << "\n===========================\n";
    std::cout << "      INGRESO MATRIZ 2     \n";
    std::cout << "===========================\n";
    m2.ingresar();

    std::cout << "\nCalculando Suma (Matriz 1 + Matriz 2)...\n";
    Matriz<float> resSuma = m1 + m2; 
    resSuma.imprimir();

    std::cout << "Calculando Multiplicacion (Matriz 1 * Matriz 2)...\n";
    Matriz<float> resMulti = m1 * m2;
    resMulti.imprimir();


    return 0;
}