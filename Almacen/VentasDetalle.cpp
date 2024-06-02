#include "VentasDetalle.h"

VentasDetalle::VentasDetalle() : idventa_detalle(0), idVenta(0), idProducto(0), cantidad(0), precio_unitario(0.0) {}

VentasDetalle::VentasDetalle(long long idDet, int idV, int idProd, int cant, double precio)
    : idventa_detalle(idDet), idVenta(idV), idProducto(idProd), cantidad(cant), precio_unitario(precio) {}

void VentasDetalle::setIdVentaDetalle(long long idDet) { idventa_detalle = idDet; }
void VentasDetalle::setIdVenta(int idV) { idVenta = idV; }
void VentasDetalle::setIdProducto(int idProd) { idProducto = idProd; }
void VentasDetalle::setCantidad(int cant) { cantidad = cant; }
void VentasDetalle::setPrecioUnitario(double precio) { precio_unitario = precio; }

long long VentasDetalle::getIdVentaDetalle() { return idventa_detalle; }
int VentasDetalle::getIdVenta() { return idVenta; }
int VentasDetalle::getIdProducto() { return idProducto; }
int VentasDetalle::getCantidad() { return cantidad; }
double VentasDetalle::getPrecioUnitario() { return precio_unitario; }

void VentasDetalle::crear() {
    int q_estado;
    ConexionDB cn;
    cn.abrir_conexion();

    if (cn.getConectar()) {
        string insertar = "INSERT INTO Ventas_detalle (idVenta, idProducto, cantidad, precio_unitario) VALUES ('" +
            to_string(idVenta) + "', '" + to_string(idProducto) + "', '" + to_string(cantidad) + "', '" + to_string(precio_unitario) + "')";
        const char* i = insertar.c_str();
        q_estado = mysql_query(cn.getConectar(), i);

        if (!q_estado) {
            cout << "Ingreso Exitoso en Ventas_detalle..." << endl;
        }
        else {
            cout << " xxx Error al Ingresar en Ventas_detalle xxx" << endl;
        }
    }
    else {
        cout << " xxx Error en la Conexion xxx" << endl;
    }
    cn.cerrar_conexion();
}

void VentasDetalle::leer() {
    // Implementar la lógica de lectura si es necesario
}

void VentasDetalle::actualizar() {
    // Implementar la lógica de actualización si es necesario
}

void VentasDetalle::borrar() {
    // Implementar la lógica de eliminación si es necesario
}
