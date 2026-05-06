#ifndef OPERACIONES_H
#define OPERACIONES_H
#include "Lista.h"

class Operaciones{
    public:
        virtual void insertar(string,string)=0;
        virtual void imprimir()=0;
        virtual Nodo* buscar(string)=0;
        virtual void eliminar(string)=0;
        virtual ~Operaciones() {}
        //Suma cuantos nodos tienen nombre que empiece con x letra
        virtual int conteoNodos(char)=0;
        virtual Nodo* retornoPenultimo()=0;
        virtual void eliminarPrimero()=0;

};
#endif