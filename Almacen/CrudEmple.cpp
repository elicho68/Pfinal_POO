#include <iostream>
#include "Empleados.h"

using namespace std;

void mostrarMenuEmpleados() {
    cout << "\nSeleccione una operacion:" << endl;
    cout << "1. Crear Empleado" << endl;
    cout << "2. Leer Empleados" << endl;
    cout << "3. Actualizar Empleado" << endl;
    cout << "4. Borrar Empleado" << endl;
    cout << "5. Salir" << endl;
    cout << "Opcion: ";
}

void crearEmpleado() {
    string nombres, apellidos, direccion, telefono, DPI, fecha_nacimiento, fecha_inicio_labores, fechaingreso;
    bool genero;
    int idPuesto;

    cout << "Ingrese Nombres: ";
    getline(cin, nombres);
    cout << "Ingrese Apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese Direccion: ";
    getline(cin, direccion);
    cout << "Ingrese Telefono: ";
    getline(cin, telefono);
    cout << "Ingrese DPI: ";
    getline(cin, DPI);
    cout << "Ingrese Genero (1 para masculino, 0 para femenino): ";
    cin >> genero;
    cin.ignore();
    cout << "Ingrese Fecha de Nacimiento (YYYY-MM-DD): ";
    getline(cin, fecha_nacimiento);
    cout << "Ingrese ID del Puesto: ";
    cin >> idPuesto;
    cin.ignore();
    cout << "Ingrese Fecha de Inicio de Labores (YYYY-MM-DD): ";
    getline(cin, fecha_inicio_labores);
    cout << "Ingrese Fecha de Ingreso (YYYY-MM-DD HH:MM:SS): ";
    getline(cin, fechaingreso);

    Empleados e(0, nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fechaingreso);
    e.crear();
}

void leerEmpleados() {
    Empleados e;
    e.leer();
}

void actualizarEmpleado() {
    int id;
    string nombres, apellidos, direccion, telefono, DPI, fecha_nacimiento, fecha_inicio_labores, fechaingreso;
    bool genero;
    int idPuesto;

    cout << "Ingrese ID del Empleado a actualizar: ";
    cin >> id;
    cin.ignore();
    cout << "Ingrese Nombres: ";
    getline(cin, nombres);
    cout << "Ingrese Apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese Direccion: ";
    getline(cin, direccion);
    cout << "Ingrese Telefono: ";
    getline(cin, telefono);
    cout << "Ingrese DPI: ";
    getline(cin, DPI);
    cout << "Ingrese Genero (1 para masculino, 0 para femenino): ";
    cin >> genero;
    cin.ignore();
    cout << "Ingrese Fecha de Nacimiento (YYYY-MM-DD): ";
    getline(cin, fecha_nacimiento);
    cout << "Ingrese ID del Puesto: ";
    cin >> idPuesto;
    cin.ignore();
    cout << "Ingrese Fecha de Inicio de Labores (YYYY-MM-DD): ";
    getline(cin, fecha_inicio_labores);
    cout << "Ingrese Fecha de Ingreso (YYYY-MM-DD HH:MM:SS): ";
    getline(cin, fechaingreso);

    Empleados e(id, nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fechaingreso);
    e.actualizar();
}

void borrarEmpleado() {
    int id;
    cout << "Ingrese ID del Empleado a borrar: ";
    cin >> id;
    cin.ignore();

    Empleados e;
    e.setIdEmpleado(id);
    e.borrar();
}

void emple() {
    int opcion;

    do {
        system("cls");
        mostrarMenuEmpleados();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            crearEmpleado();
            break;
        case 2:
            leerEmpleados();
            break;
        case 3:
            actualizarEmpleado();
            break;
        case 4:
            borrarEmpleado();
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
