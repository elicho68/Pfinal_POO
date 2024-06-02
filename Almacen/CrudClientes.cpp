#include <iostream>
#include "Clientes.h"

using namespace std;

void mostrarMenuClientes() {
    cout << "\nSeleccione una operacion:" << endl;
    cout << "1. Crear Cliente" << endl;
    cout << "2. Leer Clientes" << endl;
    cout << "3. Actualizar Cliente" << endl;
    cout << "4. Borrar Cliente" << endl;
    cout << "5. Salir" << endl;
    cout << "Opcion: ";
}

void crearCliente() {
    string nombres, apellidos, nit, correo_electronico, fechaingreso;
    bool genero;
    int telefono;

    cout << "Ingrese Nombres: ";
    getline(cin, nombres);
    cout << "Ingrese Apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese NIT: ";
    getline(cin, nit);
    cout << "Ingrese Genero (1 para masculino, 0 para femenino): ";
    cin >> genero;
    cin.ignore();
    cout << "Ingrese Telefono: ";
    cin >> telefono;
    cin.ignore();
    cout << "Ingrese Correo Electronico: ";
    getline(cin, correo_electronico);
    cout << "Ingrese Fecha de Ingreso (YYYY-MM-DD HH:MM:SS): ";
    getline(cin, fechaingreso);

    Clientes c(0, nombres, apellidos, nit, genero, telefono, correo_electronico, fechaingreso);
    c.crear();
}

void leerClientes() {
    Clientes c;
    c.leer();
}

void actualizarCliente() {
    int idCliente;
    string nombres, apellidos, nit, correo_electronico, fechaingreso;
    bool genero;
    int telefono;

    cout << "Ingrese ID del Cliente a Actualizar: ";
    cin >> idCliente;
    cin.ignore();
    cout << "Ingrese Nombres: ";
    getline(cin, nombres);
    cout << "Ingrese Apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese NIT: ";
    getline(cin, nit);
    cout << "Ingrese Genero (1 para masculino, 0 para femenino): ";
    cin >> genero;
    cin.ignore();
    cout << "Ingrese Telefono: ";
    cin >> telefono;
    cin.ignore();
    cout << "Ingrese Correo Electronico: ";
    getline(cin, correo_electronico);
    cout << "Ingrese Fecha de Ingreso (YYYY-MM-DD HH:MM:SS): ";
    getline(cin, fechaingreso);

    Clientes c(idCliente, nombres, apellidos, nit, genero, telefono, correo_electronico, fechaingreso);
    c.actualizar();
}

void borrarCliente() {
    int idCliente;
    cout << "Ingrese ID del Cliente a Borrar: ";
    cin >> idCliente;
    cin.ignore();

    Clientes c;
    c.setIdCliente(idCliente);
    c.borrar();
}

void clie() {
    int opcion;
    do {
        system("cls");
        mostrarMenuClientes();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            crearCliente();
            break;
        case 2:
            leerClientes();
            break;
        case 3:
            actualizarCliente();
            break;
        case 4:
            borrarCliente();
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
