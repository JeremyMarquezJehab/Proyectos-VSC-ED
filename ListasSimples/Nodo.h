#ifndef NODO_H
#define NODO_H
#include <string.h>
#include <iostream>
using namespace std;
class Nodo{
    private:
    string cedula;
    string nombre;
    Nodo* siguiente;

    public:
    void setCedula(string);
    void setNombre(string);
    void setSiguiente(Nodo*);
    string getCedula(string);
    string getCedula(string);
    Nodo* getSiguiente(Nodo);
    Nodo(string, string, Nodo*);
    //~Nodo()();

};
#endif