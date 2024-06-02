#include <iostream>

// Declaración de las funciones de los otros menús
void marc();
void provee();
void productos();
void pues();
void clie();
void emple();
void comp();
void vent();

using namespace std;

void mostrarMenuPrincipal() {
    cout << "Seleccione un menu:" << endl;
    cout << "1. Proveedores" << endl;
    cout << "2. Marcas" << endl;
    cout << "3. Productos" << endl;
    cout << "4. Puestos" << endl;
    cout << "5. Clientes" << endl;
    cout << "6. Empleados" << endl;
    cout << "7. Compras" << endl;
    cout << "8. Ventas" << endl;
    cout << "0. Salir" << endl;
    cout << "Opcion: ";
}

int main() {
    int opcion;

    do {
        system("cls");
        mostrarMenuPrincipal();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            provee();
            break;
        case 2:
            marc();
            break;
        case 3:
            productos();
            break;
        case 4:
            pues();
            break;
        case 5:
            clie();
            break;
        case 6:
            emple();
            break;
        case 7:
            comp();
            break;
        case 8:
            vent();
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
    } while (opcion != 0);

    return 0;
}
