#include <iostream>
#include "Puestos.h"

using namespace std;

void mostrarMenuPuestos() {
    cout << "\nSeleccione una operacion:" << endl;
    cout << "1. Crear Puestos" << endl;
    cout << "2. Leer Puestos" << endl;
    cout << "3. Actualizar Puestos" << endl;
    cout << "4. Borrar Puestos" << endl;
    cout << "5. Salir" << endl;
    cout << "Opcion: ";
}

void crearPuesto() {
    string Puesto;

    cout << "Ingrese Puesto: ";
    getline(cin, Puesto);

    Puestos c(0, Puesto);
    c.crear();
}

void actualizarPuesto() {
    string Puesto;
    int id;

    cout << "Ingrese ID de la Puesto a Actualizar: ";
    cin >> id;
    cin.ignore();
    cout << "Ingrese Puesto: ";
    getline(cin, Puesto);

    Puestos c(id, Puesto);
    c.actualizar();
}

void borrarPuesto() {
    int idPuestos;

    cout << "Ingrese ID de la Puesto a Borrar: ";
    cin >> idPuestos;
    cin.ignore();

    Puestos c;
    c.setidPuesto(idPuestos);
    c.borrar();
}

void leerPuesto() {
    Puestos c;
    c.leer();
}

void pues() {
    int opcion;

    do {
        system("cls");
        mostrarMenuPuestos();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            crearPuesto();
            break;
        case 2:
            leerPuesto();
            break;
        case 3:
            actualizarPuesto();
            break;
        case 4:
            borrarPuesto();
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
