#include <iostream>
#include <vector>
#include "Compras.h"
#include "Proveedores.h"
#include "Productos.h"
#include "ComprasDetalle.h"

using namespace std;

void mostrarMenuCompras() {
    cout << "\nSeleccione una operacion:" << endl;
    cout << "1. Crear Compra" << endl;
    cout << "2. Leer Compras" << endl;
    cout << "3. Actualizar Compra" << endl;
    cout << "4. Borrar Compra" << endl;
    cout << "5. Salir" << endl;
    cout << "Opcion: ";
}

void crearCompra() {
    int noOrden, idProveedor, cantidad, idProducto;
    double precioCosto;
    string fechaOrden;
    vector<ComprasDetalle> detalles;

    cout << "Ingrese No. Orden Compra: ";
    cin >> noOrden;
 
    bool proveedorEncontrado = false;
    Proveedores prov;
    do {
    cout << "Ingrese ID Proveedor: ";
    cin >> idProveedor;

    if (!prov.buscar(idProveedor)) {
        cout << "Proveedor no encontrado." << endl;
    }
    else {
        proveedorEncontrado = true;
    }
    } while (!proveedorEncontrado);

    cout << "Ingrese Fecha Orden (YYYY-MM-DD): ";
    cin >> fechaOrden;

    char addMore = 's'; // Inicializamos addMore para evitar el error
    do {
        cout << "Ingrese ID Producto: ";
        cin >> idProducto;

        Productos prod;
        if (!prod.buscar(idProducto)) {
            cout << "Producto no encontrado." << endl;
            continue;
        }

        cout << "Ingrese Cantidad: ";
        cin >> cantidad;
        cout << "Ingrese Precio Costo Unitario: ";
        cin >> precioCosto;

        ComprasDetalle detalle(0, 0, idProducto, cantidad, precioCosto);
        detalles.push_back(detalle);

        cout << "¿Agregar otro producto? (s/n): ";
        cin >> addMore;
    } while (addMore == 's' || addMore == 'S');

    Compras compra(0, noOrden, idProveedor, fechaOrden, "", detalles);
    compra.crear();

}

void leerCompras() {
    Compras c;
    c.leer();
}

void actualizarCompra() {
    // Implementar la lógica de actualización similar a crear
    int idCompra, noOrden, idProveedor, cantidad, idProducto;
    double precioCosto;
    string fechaOrden;
    vector<ComprasDetalle> detalles;

    cout << "Ingrese ID de la Compra a actualizar: ";
    cin >> idCompra;
    cout << "Ingrese No. Orden Compra: ";
    cin >> noOrden;
    cout << "Ingrese ID Proveedor: ";
    cin >> idProveedor;

    Proveedores prov;
    if (!prov.buscar(idProveedor)) {
        cout << "Proveedor no encontrado." << endl;
        return;
    }

    cout << "Ingrese Fecha Orden (YYYY-MM-DD): ";
    cin >> fechaOrden;

    char addMore = 's'; // Inicializamos addMore para evitar el error
    do {
        cout << "Ingrese ID Producto: ";
        cin >> idProducto;

        Productos prod;
        if (!prod.buscar(idProducto)) {
            cout << "Producto no encontrado." << endl;
            continue;
        }

        cout << "Ingrese Cantidad: ";
        cin >> cantidad;
        cout << "Ingrese Precio Costo Unitario: ";
        cin >> precioCosto;

        ComprasDetalle detalle(0, idCompra, idProducto, cantidad, precioCosto);
        detalles.push_back(detalle);

        cout << "¿Agregar otro producto? (s/n): ";
        cin >> addMore;
    } while (addMore == 's' || addMore == 'S');

    Compras compra(idCompra, noOrden, idProveedor, fechaOrden, "", detalles);
    compra.actualizar();
}


void borrarCompra() {
    // Implementar la lógica de eliminación
    int idCompra;
    cout << "Ingrese ID de Compra a Borrar: ";
    cin >> idCompra;
    cin.ignore();

    Compras c;
    c.setIdCompra(idCompra);
    c.borrar();
}

///int main() {
void comp(){
    int opcion;

    do {
        system("cls");
        mostrarMenuCompras();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            crearCompra();
            break;
        case 2:
            leerCompras();
            break;
        case 3:
            actualizarCompra();
            break;
        case 4:
            borrarCompra();
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
