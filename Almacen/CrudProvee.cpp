#include <iostream>
#include "Proveedores.h"

using namespace std;

void mostrarMenuProveedores() {
    cout << "\nSeleccione una operacion:" << endl;
    cout << "1. Crear Proveedores" << endl;
    cout << "2. Leer Proveedores" << endl;
    cout << "3. Actualizar Proveedores" << endl;
    cout << "4. Borrar Proveedores" << endl;
    cout << "5. Salir" << endl;
    cout << "Opcion: ";
}

void crearProveedor() {
    string proveedor, nit, direccion;
    int telefono;

    cout << "Ingrese Proveedor: ";
    getline(cin, proveedor);
    cout << "Ingrese NIT: ";
    getline(cin, nit);
    cout << "Ingrese Direccion: ";
    getline(cin, direccion);
    cout << "Ingrese Telefono: ";
    cin >> telefono;
    cin.ignore();

    Proveedores c(0, proveedor, nit, direccion, telefono);
    c.crear();
}

void actualizarProveedor() {
    string proveedor, nit, direccion;
    int telefono, id;

    cout << "Ingrese ID del Proveedor a Actualizar: ";
    cin >> id;
    cin.ignore();
    cout << "Ingrese Proveedor: ";
    getline(cin, proveedor);
    cout << "Ingrese NIT: ";
    getline(cin, nit);
    cout << "Ingrese Direccion: ";
    getline(cin, direccion);
    cout << "Ingrese Telefono: ";
    cin >> telefono;
    cin.ignore();

    Proveedores c(id, proveedor, nit, direccion, telefono);
    c.actualizar();
}

void borrarProveedor() {
    int id;

    cout << "Ingrese ID del Proveedor a Borrar: ";
    cin >> id;
    cin.ignore();

    Proveedores c;
    c.setIdProveedor(id);
    c.borrar();
}

void leerProveedor() {
    Proveedores c;
    c.leer();
}

void provee() {
    int opcion;

    do {
        system("cls");
        mostrarMenuProveedores();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            crearProveedor();
            break;
        case 2:
            leerProveedor();
            break;
        case 3:
            actualizarProveedor();
            break;
        case 4:
            borrarProveedor();
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
