#include <iostream>
#include "Productos.h"

using namespace std;

void mostrarMenuProductos() {
    cout << "\nSeleccione una operacion:" << endl;
    cout << "1. Crear Producto" << endl;
    cout << "2. Leer Productos" << endl;
    cout << "3. Actualizar Producto" << endl;
    cout << "4. Borrar Producto" << endl;
    cout << "5. Salir" << endl;
    cout << "Opcion: ";
}

void crearProducto() {
    string producto, descripcion, imagen, fecha_ingreso;
    int idMarca, existencia;
    double precio_costo, precio_venta;

    cout << "Ingrese Producto: ";
    getline(cin, producto);
    cout << "Ingrese ID Marca: ";
    cin >> idMarca;
    cin.ignore();
    cout << "Ingrese Descripcion: ";
    getline(cin, descripcion);
    cout << "Ingrese Imagen: ";
    getline(cin, imagen);
    cout << "Ingrese Precio Costo: ";
    cin >> precio_costo;
    cout << "Ingrese Precio Venta: ";
    cin >> precio_venta;
    cout << "Ingrese Existencia: ";
    cin >> existencia;
    cin.ignore();
    cout << "Ingrese Fecha de Ingreso (YYYY-MM-DD HH:MM:SS): ";
    getline(cin, fecha_ingreso);

    Productos p(0, producto, idMarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso);
    p.crear();
}

void leerProductos() {
    Productos p;
    p.leer();
}

void actualizarProducto() {
    int idProducto, idMarca, existencia;
    string producto, descripcion, imagen, fecha_ingreso;
    double precio_costo, precio_venta;

    cout << "Ingrese ID del Producto a Actualizar: ";
    cin >> idProducto;
    cin.ignore();
    cout << "Ingrese Producto: ";
    getline(cin, producto);
    cout << "Ingrese ID Marca: ";
    cin >> idMarca;
    cin.ignore();
    cout << "Ingrese Descripcion: ";
    getline(cin, descripcion);
    cout << "Ingrese Imagen: ";
    getline(cin, imagen);
    cout << "Ingrese Precio Costo: ";
    cin >> precio_costo;
    cout << "Ingrese Precio Venta: ";
    cin >> precio_venta;
    cout << "Ingrese Existencia: ";
    cin >> existencia;
    cin.ignore();
    cout << "Ingrese Fecha de Ingreso (YYYY-MM-DD HH:MM:SS): ";
    getline(cin, fecha_ingreso);

    Productos p(idProducto, producto, idMarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso);
    p.actualizar();
}

void borrarProducto() {
    int idProducto;
    cout << "Ingrese ID del Producto a Borrar: ";
    cin >> idProducto;
    cin.ignore();

    Productos p;
    p.setIdProducto(idProducto);
    p.borrar();
}

void productos() {
    int opcion;
    do {
        mostrarMenuProductos();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            crearProducto();
            break;
        case 2:
            leerProductos();
            break;
        case 3:
            actualizarProducto();
            break;
        case 4:
            borrarProducto();
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
