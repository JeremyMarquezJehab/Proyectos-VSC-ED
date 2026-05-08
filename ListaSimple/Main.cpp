#include "Lista.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int opcion;
    string cedula, nombre;
    Lista* miLista = new Lista();
    
    miLista->cargarDesdeArchivo();

    do {
        cout << "\n========== MENU INGRESO DE DATOS ==========" << endl;
        cout << "1. Insertar Usuario" << endl;
        cout << "2. Buscar Usuario" << endl;
        cout << "3. Eliminar Usuario" << endl;
        cout << "4. Ver Reporte por Provincias" << endl;
        cout << "5. Mostrar Todos" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Ingrese un numero valido." << endl;
            continue;
        }

        switch (opcion) {
            case 1:
                while (true) {
                    cout << "Ingrese la cedula: ";
                    cin >> cedula;
                    if (miLista->esCedulaValida(cedula)) break;
                    else cout << "Cedula invalida, ingrese nuevamente!" << endl;
                }
                
                cin.ignore(10000, '\n');
                
                while (true) {
                    cout << "Ingrese nombre: ";
                    getline(cin, nombre);
                    if (miLista->esNombreValido(nombre)) break;
                    else cout << "Nombre invalido ingrese caracteres válidos(A-Z)!" << endl;
                }
                
                miLista->insertar(cedula, nombre);
                miLista->guardarEnArchivo();
                break;

            case 2: { 
                cout << "Ingrese la cedula a buscar: ";
                cin >> cedula;
                Nodo* usuarioEncontrado = miLista->buscar(cedula);
                
                if (usuarioEncontrado != nullptr) {
                    cout << "\n--- Usuario Encontrado ---" << endl;
                    cout << "Cedula: " << usuarioEncontrado->getCedula() << endl;
                    cout << "Nombre: " << usuarioEncontrado->getNombre() << endl;
                } else {
                    cout << "\nError: No se encontro ningun usuario con la cedula " << cedula << endl;
                }
                break;
            }

            case 3:
                cout << "Ingrese la cedula a eliminar: ";
                cin >> cedula;
                miLista->eliminar(cedula);
                break;

            case 4:
                miLista->contarPorProvincia();
                break;

            case 5:
                miLista->imprimir();
                break;

            case 6:
                cout << "Saliendo y guardando datos..." << endl;
                break;

            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 6);

    delete miLista;
    return 0;
}