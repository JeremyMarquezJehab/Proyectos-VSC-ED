#include "Lista.h"
#include <iostream>
using namespace std;

int main(){
    string cedula,nombre;
    char aux,letra;
    int conteo;
    bool continuar=true;
    Lista* miLista=new Lista();
    while(continuar!=false){
        cout<<"-------- INGRESO DE DATOS ---------"<<endl;
        cout<<"Ingrese su cedula: ";
        cin>>cedula;
        cout<<"Ingrese su nombre: ";
        cin.ignore();
        getline(cin,nombre);
        miLista->insertar(cedula,nombre);
        cout<<"Desea agregar otro usuario? [Y/n]: ";
        cin>>aux;
        if(aux=='n' || aux=='N'){
            continuar=false;
        }else if(aux=='Y' || aux=='y'){
            continuar=true;
        }else{
            cout<<"Operador invalido! Saliendo por seguridad..."<<endl;
            return false;
        }
    }
    miLista->imprimir();
    /*cout<<"Para el conteo de nodos que tengan un nombre que empiece por x letra"<<endl;
    cout<<"Ingrese una letra: ";
    cin>>letra;
    conteo=miLista->conteoNodos(letra);
    cout<<"El numero de nodos que cumplen con eso son: "<<conteo;*/
    /*Nodo* penultimo=miLista->retornoPenultimo();
    cout<<"Penultimo nodo: "<<penultimo->getCedula()<<" | "<<penultimo->getNombre();*/
    miLista->eliminarPrimero();
    miLista->imprimir();
    delete miLista;
    return 0;
}