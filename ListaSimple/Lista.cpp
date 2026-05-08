#include "Lista.h"
#include "Operaciones.h"
#include <iostream>
#include <fstream>
#include <cctype>

Lista::Lista(){
    this->cabeza=nullptr;
    this->cola=nullptr;
}

void Lista::insertar(string cedula,string nombre){
    Nodo* nuevo=new Nodo(cedula,nombre,nullptr);
    if(cabeza==nullptr){
        cabeza=nuevo;
        cola=nuevo;
    }else{
        nuevo->setSiguiente(cabeza);
        cabeza=nuevo;
    }
}

void Lista::imprimir(){
    if(cabeza==nullptr){
        cout<<"No se ha podido encontrar ningun dato ingresado!"<<endl;
        cout<<"LISTA VACÍA!"<<endl;
    }else{
        Nodo* aux=cabeza;
        cout<<"Lista de registros:"<<endl;
        while(aux!=nullptr){
            cout<<"Cedula: "<<aux->getCedula()<<"| Nombre: "<<aux->getNombre()<<endl;
            aux=aux->getSiguiente();
        }
    }
}

Nodo* Lista::buscar(string cedulaBusqueda) {
    Nodo* aux = cabeza;
    while (aux != nullptr) {
        if (aux->getCedula() == cedulaBusqueda) {
            return aux;
        }
        aux = aux->getSiguiente();
    }
    return nullptr; 
}

void Lista::eliminar(string cedulaEliminar) {
    if (cabeza == nullptr) {
        cout << "La lista esta vacia." << endl;
        return;
    }

    Nodo* aux = cabeza;
    Nodo* anterior = nullptr;
    bool encontrado = false;

    while (aux != nullptr) {
        if (aux->getCedula() == cedulaEliminar) {
            encontrado = true;
            
            if (anterior == nullptr) {
                cabeza = cabeza->getSiguiente();
                if (cabeza == nullptr) cola = nullptr;
            } else {
                anterior->setSiguiente(aux->getSiguiente());
                if (aux == cola) {
                    cola = anterior;
                }
            }

            delete aux; 
            cout << "Usuario con cedula " << cedulaEliminar << " eliminado exitosamente." << endl;
            
            guardarEnArchivo();
            break;
        }
        anterior = aux;
        aux = aux->getSiguiente();
    }

    if (!encontrado) {
        cout << "Error: No se pudo eliminar. Cedula no encontrada." << endl;
    }
}

/*int Lista::conteoNodos(char letra){
    int suma=0;
    Nodo* aux=cabeza;
    while(aux!=nullptr){
        if(aux->getNombre().front()==letra){
            suma++;
        }
        aux=aux->getSiguiente();
    }
    return suma;
}*/

void Lista::contarPorProvincia() {
    int* conteo = new int[25](); 
    string* nombres = new string[25];
    ifstream archivo("provincias.txt");
    if (archivo.is_open()) {
        int codLeido;
        string nomLeido;
        while (archivo >> codLeido) {
            archivo >> ws; 
            getline(archivo, nomLeido);
            
            if (codLeido >= 1 && codLeido <= 24) {
                *(nombres + codLeido) = nomLeido; 
            }
        }
        archivo.close();
    } else {
        cout << "Error: No se pudo abrir el archivo provincias.txt" << endl;
        delete[] conteo;
        delete[] nombres;
        return;
    }
    Nodo* aux = cabeza;
    while (aux != nullptr) {
        string cedula = aux->getCedula();
        
        if (cedula.length() >= 2 && isdigit(cedula.at(0)) && isdigit(cedula.at(1))) {
            
            int codigo = (cedula.at(0) - '0') * 10 + (cedula.at(1) - '0');
            
            if (codigo >= 1 && codigo <= 24) {
                (*(conteo + codigo))++;
            }
        }
        aux = aux->getSiguiente();
    }

    cout << "\n--- Reporte Generado desde TXT (24 Provincias) ---" << endl;
    for (int i = 1; i <= 24; i++) {
        if (*(conteo + i) > 0) {
            cout << *(nombres + i) << " (" << (i < 10 ? "0" : "") << i << "): " 
                 << *(conteo + i) << " registros." << endl;
        }
    }
    cout << "--------------------------------------------------" << endl;

    delete[] conteo;
    delete[] nombres;
}

bool Lista::esCedulaValida(string cedula) {
    if (cedula.length() != 10) return false;
    
    for (char c : cedula) {
        if (!isdigit(c)) return false;
    }

    int provincia = (cedula.at(0) - '0') * 10 + (cedula.at(1) - '0');
    if (provincia < 1 || provincia > 24) return false;

    int tercerDigito = cedula.at(2) - '0';
    if (tercerDigito >= 6) return false;

    int suma = 0;
    for (int i = 0; i < 9; i++) {
        int digito = cedula.at(i) - '0';
        if (i % 2 == 0) { 
            digito = digito * 2;
            if (digito > 9) digito -= 9;
        }
        suma += digito;
    }

    int decenaSuperior = ((suma + 9) / 10) * 10;
    int digitoCalculado = decenaSuperior - suma;
    if (digitoCalculado == 10) digitoCalculado = 0;

    int digitoReal = cedula.at(9) - '0';
    return digitoCalculado == digitoReal;
}

bool Lista::esNombreValido(string nombre) {
    if (nombre.length() == 0) return false;
    
    for (char c : nombre) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

void Lista::guardarEnArchivo() {
    ofstream archivo("usuarios.txt");
    
    if (archivo.is_open()) {
        Nodo* aux = cabeza;
        while (aux != nullptr) {
            archivo << aux->getCedula() << ";" << aux->getNombre() << endl;
            aux = aux->getSiguiente();
        }
        archivo.close();
        cout << "\nDatos guardados correctamente en usuarios.txt" << endl;
    } else {
        cout << "Error al intentar guardar el archivo." << endl;
    }
}

void Lista::cargarDesdeArchivo() {
    ifstream archivo("usuarios.txt");
    string linea;
    
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            size_t pos = linea.find(';');
            if (pos != string::npos) {
                string ced = linea.substr(0, pos);
                string nom = linea.substr(pos + 1);
                
                this->insertar(ced, nom);
            }
        }
        archivo.close();
        cout << "Datos cargados desde el archivo con exito." << endl;
    } else {
        cout << "No se encontro un archivo previo. Iniciando lista vacia." << endl;
    }
}


/*Nodo* Lista::retornoPenultimo(){
    if(cabeza==nullptr || cabeza->getSiguiente()==nullptr) return nullptr;
    Nodo* aux=cabeza;
    while(aux->getSiguiente()->getSiguiente()!=nullptr){
        aux=aux->getSiguiente();
    }
    return aux->getSiguiente();
}*/

/*void Lista::eliminarPrimero(){
    if(cabeza!=nullptr){
        Nodo* aux=cabeza;
        cabeza=cabeza->getSiguiente();
        delete aux;
    }
}*/

/*void Lista::eliminarDuplicados(){
    if(cabeza==nullptr || cabeza->getSiguiente()==nullptr) return;
    Nodo* aux=cabeza;
    while(aux!=nullptr && aux->getSiguiente()!=nullptr){
        if(aux->getCedula()==aux->getSiguiente()->getCedula()){
            Nodo* duplicado=aux->getSiguiente();
            aux->setSiguiente(duplicado->getSiguiente());
            if(duplicado==cola){
                cola=aux;
            }
            delete duplicado;
        }else{
            aux=aux->getSiguiente();
        }
    }
}*/

void Lista::setCabeza(Nodo* cabeza){
    this->cabeza=cabeza;
}

void Lista::setCola(Nodo* cola){
    this->cola=cola;
}

Nodo* Lista::getCabeza(){
    return this->cabeza;
}

Nodo* Lista::getCola(){
    return this->cola;
}