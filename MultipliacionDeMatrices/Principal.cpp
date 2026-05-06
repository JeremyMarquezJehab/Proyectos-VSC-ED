
/*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
  JEREMY JOEL MARQUEZ CRESPO
  ESTRUCTURA DE DATOS                    */
#include <iostream>
#include "Matriz.h"
#include "Operacion.h"

int main() {
    int f = 2, c = 2, p = 2;
    Operacion op;

    Matriz m1(f, c, p);
    Matriz m2(f, c, p);
    Matriz mR(f, c, p);

    std::cout << "===========================\n";
    std::cout << "      INGRESO MATRIZ 1     \n";
    std::cout << "===========================\n";
    op.ingresar(m1.getMat(), f, c, p);

    std::cout << "\n===========================\n";
    std::cout << "      INGRESO MATRIZ 2     \n";
    std::cout << "===========================\n";
    op.ingresar(m2.getMat(), f, c, p);

    op.sumar(m1.getMat(), m2.getMat(), mR.getMat(), f, c, p);

    std::cout << "\n===========================\n";
    std::cout << "   RESULTADO DE LA SUMA    \n";
    std::cout << "===========================\n";
    op.imprimir(mR.getMat(), f, c, p);

    return 0;
}