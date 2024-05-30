#include <iostream>

// Declaración de las funciones de los otros menús
void marc();
void provee();
void productos();


using namespace std;

void mostrarMenuPrincipal() {
    cout << "Seleccione un menu:" << endl;
    cout << "1. Proveedores" << endl;
    cout << "2. Marcas" << endl;
    cout << "3. Productos" << endl;
    cout << "4. Salir" << endl;
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
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
    } while (opcion != 4);

    return 0;
}
