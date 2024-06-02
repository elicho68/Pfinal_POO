#include "ComprasDetalle.h"

ComprasDetalle::ComprasDetalle() : id_compra_detalle(0), idCompra(0), idproducto(0), cantidad(0), precio_costo_unitario(0.0) {}

ComprasDetalle::ComprasDetalle(long long idDet, int idC, int idProd, int cant, double precio)
    : id_compra_detalle(idDet), idCompra(idC), idproducto(idProd), cantidad(cant), precio_costo_unitario(precio) {}

void ComprasDetalle::setIdCompraDetalle(long long idDet) { id_compra_detalle = idDet; }
void ComprasDetalle::setIdCompra(int idC) { idCompra = idC; }
void ComprasDetalle::setIdProducto(int idProd) { idproducto = idProd; }
void ComprasDetalle::setCantidad(int cant) { cantidad = cant; }
void ComprasDetalle::setPrecioCostoUnitario(double precio) { precio_costo_unitario = precio; }

long long ComprasDetalle::getIdCompraDetalle() { return id_compra_detalle; }
int ComprasDetalle::getIdCompra() { return idCompra; }
int ComprasDetalle::getIdProducto() { return idproducto; }
int ComprasDetalle::getCantidad() { return cantidad; }
double ComprasDetalle::getPrecioCostoUnitario() { return precio_costo_unitario; }

void ComprasDetalle::crear() {
    int q_estado;
    ConexionDB cn;
    cn.abrir_conexion();

    if (cn.getConectar()) {
        string insertar = "INSERT INTO Compras_detalle (idcompra, idproducto, cantidad, precio_costo_unitario) VALUES ('" +
            to_string(idCompra) + "', '" + to_string(idproducto) + "', '" + to_string(cantidad) + "', '" + to_string(precio_costo_unitario) + "')";
        const char* i = insertar.c_str();
        q_estado = mysql_query(cn.getConectar(), i);

        if (!q_estado) {
            cout << "Ingreso Exitoso en Compras_detalle..." << endl;
        }
        else {
            cout << " xxx Error al Ingresar en Compras_detalle xxx" << endl;
        }
    }
    else {
        cout << " xxx Error en la Conexion xxx" << endl;
    }
    cn.cerrar_conexion();
}

void ComprasDetalle::leer() {
    // Implementar la lógica de lectura
}

void ComprasDetalle::actualizar() {
    // Implementar la lógica de actualización
}

void ComprasDetalle::borrar() {
    // Implementar la lógica de eliminación
}
