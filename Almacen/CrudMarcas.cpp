#include <iostream>
#include "Marcas.h"

using namespace std;

void mostrarMenuMarcas() {
    cout << "\nSeleccione una operacion:" << endl;
    cout << "1. Crear Marcas" << endl;
    cout << "2. Leer Marcas" << endl;
    cout << "3. Actualizar Marcas" << endl;
    cout << "4. Borrar Marcas" << endl;
    cout << "5. Salir" << endl;
    cout << "Opcion: ";
}

void crearMarca() {
    string marca;

    cout << "Ingrese Marca: ";
    getline(cin, marca);

    Marcas c(0, marca);
    c.crear();
}

void actualizarMarca() {
    string marca;
    int id;

    cout << "Ingrese ID de la Marca a Actualizar: ";
    cin >> id;
    cin.ignore();
    cout << "Ingrese Marca: ";
    getline(cin, marca);

    Marcas c(id, marca);
    c.actualizar();
}

void borrarMarca() {
    int idMarcas;

    cout << "Ingrese ID de la Marca a Borrar: ";
    cin >> idMarcas;
    cin.ignore();

    Marcas c;
    c.setIdMarca(idMarcas);
    c.borrar();
}

void leerMarca() {
    Marcas c;
    c.leer();
}

void marc() {
    int opcion;

    do {
        system("cls");
        mostrarMenuMarcas();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            crearMarca();
            break;
        case 2:
            leerMarca();
            break;
        case 3:
            actualizarMarca();
            break;
        case 4:
            borrarMarca();
            break;
        case 5:
            cout << "Regresando al menu principal..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
        if (opcion != 5) {
            cout << "Presione Enter para continuar...";
            cin.ignore();
        }
    } while (opcion != 5);
}
