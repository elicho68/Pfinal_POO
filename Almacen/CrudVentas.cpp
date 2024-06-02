#include <iostream>
#include <vector>
#include <ctime>
#include "Ventas.h"
#include "Clientes.h"
#include "Productos.h"
#include "Empleados.h"
#include "VentasDetalle.h"
#include "ValidadorNIT.h"

using namespace std;

void mostrarMenuVentas() {
    cout << "\nSeleccione una operacion:" << endl;
    cout << "1. Crear Venta" << endl;
    cout << "2. Leer Ventas" << endl;
    cout << "3. Actualizar Venta" << endl;
    cout << "4. Borrar Venta" << endl;
    cout << "5. Salir" << endl;
    cout << "Opcion: ";
}

bool validarEmpleado(int idEmpleado) {
    Empleados empleado;
    return empleado.buscarPorId(idEmpleado); // Asumiendo que esta función está implementada y retorna true si el empleado existe
}

void crearVenta() {
    int noFactura = 1; // Inicialización
    int idCliente, idEmpleado, cantidad, idProducto;
    double precioUnitario;
    string fechaFactura, nit, nombres, apellidos, correo, fechaIngreso;
    bool genero;
    vector<VentasDetalle> detalles;

    cout << "Ingrese NIT del Cliente: ";
    cin >> nit;

    // Validar NIT
    if (!validarNIT(nit)) {
        cout << "NIT inválido. Intente nuevamente." << endl;
        return;
    }


    Clientes cliente;
    if (!cliente.buscarPorNit(nit)) {
        cout << "Cliente no encontrado. Ingrese los datos del cliente:" << endl;
        cout << "Nombres: ";
        cin.ignore();
        getline(cin, nombres);
        cout << "Apellidos: ";
        getline(cin, apellidos);
        cout << "Genero (0 para femenino, 1 para masculino): ";
        cin >> genero;
        cout << "Telefono: ";
        cin >> idCliente;
        cout << "Correo: ";
        cin.ignore();
        getline(cin, correo);
        cout << "Fecha Ingreso (YYYY-MM-DD): ";
        getline(cin, fechaIngreso);

        cliente = Clientes(0, nombres, apellidos, nit, genero, idCliente, correo, fechaIngreso);
        cliente.crear();
        cliente.buscarPorNit(nit);  // Buscar de nuevo para obtener el ID del cliente
    }

    idCliente = cliente.getIdCliente();
    cout << "Cliente encontrado: " << cliente.getNombres() << " " << cliente.getApellidos() << endl;

    Empleados empleado;
    do {
        cout << "Ingrese ID del Empleado: ";
        cin >> idEmpleado;
        if (!validarEmpleado(idEmpleado)) {
            cout << "Empleado no encontrado. Intente nuevamente." << endl;
        }
    } while (!validarEmpleado(idEmpleado));
 
    // Generar fecha automáticamente
    time_t t = time(0);
    struct tm now;
    localtime_s(&now, &t);
    fechaFactura = to_string(now.tm_year + 1900) + '-' +
        to_string(now.tm_mon + 1) + '-' +
        to_string(now.tm_mday);

    // Generar número de factura automáticamente
    ConexionDB cn;
    cn.abrir_conexion();
    if (cn.getConectar()) {
        string consulta = "SELECT MAX(nofactura) FROM Ventas";
        const char* c = consulta.c_str();
        if (!mysql_query(cn.getConectar(), c)) {
            MYSQL_RES* result = mysql_store_result(cn.getConectar());
            MYSQL_ROW row = mysql_fetch_row(result);
            if (row && row[0]) {
                noFactura = stoi(row[0]) + 1;
            }
            mysql_free_result(result);
        }
        cn.cerrar_conexion();
    }
    else {
        cout << " xxx Error en la Conexion xxx" << endl;
        return;
    }

    char serie = 'A';

    char addMore = 's'; // Inicializamos addMore para evitar el error
    do {
        cout << "Ingrese ID Producto: ";
        cin >> idProducto;

        Productos prod;
        if (!prod.buscar(idProducto)) {
            cout << "Producto no encontrado. Intente nuevamente." << endl;
            continue;
        }

        cout << "Producto encontrado: " << prod.getProducto() << " (Marca ID: " << prod.getIdMarca() << ")" << endl;

        cout << "Ingrese Cantidad: ";
        cin >> cantidad;
        cout << "Ingrese Precio Unitario: ";
        cin >> precioUnitario;

        VentasDetalle detalle(0, 0, idProducto, cantidad, precioUnitario);
        detalles.push_back(detalle);

        cout << "¿Agregar otro producto? (s/n): ";
        cin >> addMore;
    } while (addMore == 's' || addMore == 'S');

    Ventas venta(0, noFactura, serie, fechaFactura, idCliente, idEmpleado, "", detalles);
    venta.crear();
}

void leerVentas() {
    Ventas v;
    v.leer();
}

void actualizarVenta() {
    int idVenta, noFactura = 1; // Inicialización
    int idCliente, idEmpleado, cantidad, idProducto;
    double precioUnitario;
    string fechaFactura, nit;
    vector<VentasDetalle> detalles;

    cout << "Ingrese ID de la Venta a actualizar: ";
    cin >> idVenta;

    Ventas venta;
    venta.setIdVenta(idVenta);
    venta.leer();  // Mostrar los datos actuales de la venta

    cout << "Ingrese NIT del Cliente: ";
    cin >> nit;

    // Validar NIT
    if (!validarNIT(nit)) {
        cout << "NIT inválido. Intente nuevamente." << endl;
        return;
    }

    Clientes cliente;
    if (!cliente.buscarPorNit(nit)) {
        cout << "Cliente no encontrado. Ingrese los datos del cliente:" << endl;
        string nombres, apellidos, correo, fechaIngreso;
        bool genero;
        cout << "Nombres: ";
        cin.ignore();
        getline(cin, nombres);
        cout << "Apellidos: ";
        getline(cin, apellidos);
        cout << "Genero (0 para femenino, 1 para masculino): ";
        cin >> genero;
        cout << "Telefono: ";
        cin >> idCliente;
        cout << "Correo: ";
        cin.ignore();
        getline(cin, correo);
        cout << "Fecha Ingreso (YYYY-MM-DD): ";
        getline(cin, fechaIngreso);

        cliente = Clientes(0, nombres, apellidos, nit, genero, idCliente, correo, fechaIngreso);
        cliente.crear();
        cliente.buscarPorNit(nit);  // Buscar de nuevo para obtener el ID del cliente
    }

    idCliente = cliente.getIdCliente();
    cout << "Cliente encontrado: " << cliente.getNombres() << " " << cliente.getApellidos() << endl;

    do {
        cout << "Ingrese ID del Empleado: ";
        cin >> idEmpleado;
        if (!validarEmpleado(idEmpleado)) {
            cout << "Empleado no encontrado. Intente nuevamente." << endl;
        }
    } while (!validarEmpleado(idEmpleado));

    // Generar fecha automáticamente
    time_t t = time(0);
    struct tm now;
    localtime_s(&now, &t);
    fechaFactura = to_string(now.tm_year + 1900) + '-' +
        to_string(now.tm_mon + 1) + '-' +
        to_string(now.tm_mday);

    // Generar número de factura automáticamente
    ConexionDB cn;
    cn.abrir_conexion();
    if (cn.getConectar()) {
        string consulta = "SELECT MAX(nofactura) FROM Ventas";
        const char* c = consulta.c_str();
        if (!mysql_query(cn.getConectar(), c)) {
            MYSQL_RES* result = mysql_store_result(cn.getConectar());
            MYSQL_ROW row = mysql_fetch_row(result);
            if (row && row[0]) {
                noFactura = stoi(row[0]) + 1;
            }
            mysql_free_result(result);
        }
        cn.cerrar_conexion();
    }
    else {
        cout << " xxx Error en la Conexion xxx" << endl;
        return;
    }

    char serie = 'A';

    char addMore = 's'; // Inicializamos addMore para evitar el error
    do {
        cout << "Ingrese ID Producto: ";
        cin >> idProducto;

        Productos prod;
        if (!prod.buscar(idProducto)) {
            cout << "Producto no encontrado. Intente nuevamente." << endl;
            continue;
        }

        cout << "Producto encontrado: " << prod.getProducto() << " (Marca ID: " << prod.getIdMarca() << ")" << endl;

        cout << "Ingrese Cantidad: ";
        cin >> cantidad;
        cout << "Ingrese Precio Unitario: ";
        cin >> precioUnitario;

        VentasDetalle detalle(0, idVenta, idProducto, cantidad, precioUnitario);
        detalles.push_back(detalle);

        cout << "¿Agregar otro producto? (s/n): ";
        cin >> addMore;
    } while (addMore == 's' || addMore == 'S');

    venta.setNoFactura(noFactura);
    venta.setSerie(serie);
    venta.setFechaFactura(fechaFactura);
    venta.setIdCliente(idCliente);
    venta.setIdEmpleado(idEmpleado);
    venta.setDetalles(detalles);
    venta.actualizar();
}

void borrarVenta() {
    int idVenta;
    cout << "Ingrese ID de la Venta a borrar: ";
    cin >> idVenta;
    cin.ignore();

    Ventas venta;
    venta.setIdVenta(idVenta);
    venta.borrar();
}

//int main() {
void vent(){
    int opcion;

    do {
        system("cls");
        mostrarMenuVentas();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            crearVenta();
            break;
        case 2:
            leerVentas();
            break;
        case 3:
            actualizarVenta();
            break;
        case 4:
            borrarVenta();
            break;
        case 5:
            cout << "Saliendo..." << endl;
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

  ///  return 0;
}
