#include "Compras.h"

// Constructor
Compras::Compras() : idCompra(0), no_orden_compra(0), id_proveedor(0), fecha_orden(""), fechaingreso("") {}

Compras::Compras(int idC, int noOrden, int idProv, string fechaOrd, string fechaIng, vector<ComprasDetalle> dets)
    : idCompra(idC), no_orden_compra(noOrden), id_proveedor(idProv), fecha_orden(fechaOrd), fechaingreso(fechaIng), detalles(dets) {}

void Compras::setIdCompra(int idC) { idCompra = idC; }
void Compras::setNoOrdenCompra(int noOrden) { no_orden_compra = noOrden; }
void Compras::setIdProveedor(int idProv) { id_proveedor = idProv; }
void Compras::setFechaOrden(string fechaOrd) { fecha_orden = fechaOrd; }
void Compras::setFechaIngreso(string fechaIng) { fechaingreso = fechaIng; }
void Compras::setDetalles(vector<ComprasDetalle> dets) { detalles = dets; }

int Compras::getIdCompra() { return idCompra; }
int Compras::getNoOrdenCompra() { return no_orden_compra; }
int Compras::getIdProveedor() { return id_proveedor; }
string Compras::getFechaOrden() { return fecha_orden; }
string Compras::getFechaIngreso() { return fechaingreso; }
vector<ComprasDetalle> Compras::getDetalles() { return detalles; }

void Compras::crear() {
    int q_estado;
    ConexionDB cn;
    cn.abrir_conexion();

    if (cn.getConectar()) {
        string insertar = "INSERT INTO Compras (no_orden_compra, idproveedor, fecha_orden, fechaingreso) VALUES ('" +
            to_string(no_orden_compra) + "', '" + to_string(id_proveedor) + "', '" + fecha_orden + "', NOW())";
        const char* i = insertar.c_str();
        q_estado = mysql_query(cn.getConectar(), i);

        if (!q_estado) {
            cout << "Ingreso Exitoso en Compras..." << endl;
            int compra_id = mysql_insert_id(cn.getConectar()); // Obtener el idCompra insertado

            for (ComprasDetalle& detalle : detalles) {
                detalle.setIdCompra(compra_id);
                detalle.crear();
            }
            cout << "Ingreso Exitoso en Compras y Detalle..." << endl;
        }
        else {
            cout << " xxx Error al Ingresar en Compras xxx" << endl;
        }
    }
    else {
        cout << " xxx Error en la Conexion xxx" << endl;
    }
    cn.cerrar_conexion();
}

void Compras::leer() {
    int q_estado;
    ConexionDB cn;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    cn.abrir_conexion();

    if (cn.getConectar()) {
        cout << "------------ Datos de Compras ------------" << endl;
        string consulta = "SELECT * FROM v_compras";
        const char* c = consulta.c_str();
        q_estado = mysql_query(cn.getConectar(), c);

        if (!q_estado) {
            resultado = mysql_store_result(cn.getConectar());
            while ((fila = mysql_fetch_row(resultado))) {
                cout << "ID: " << fila[0] << " \nNo Orden: " << fila[1] << " \nProveedor: " << fila[2] << " \nFecha Orden: " << fila[3] << " \nFecha Ingreso: " << fila[4] << " \nProducto: " << fila[5] << " \nCantidad: " << fila[6] << " \nCosto Uni.: " << fila[7] << endl;
                cout << "------------ fin ------------" << endl;
            }
        }
        else {
            cout << " xxx Error al Consultar xxx" << endl;
        }
    }
    else {
        cout << " xxx Error en la Conexion xxx" << endl;
    }
    cn.cerrar_conexion();
}

void Compras::actualizar() {
    // Implementar la lógica de actualización similar a crear
    int q_estado;
    ConexionDB cn;
    cn.abrir_conexion();

    if (cn.getConectar()) {
        string actualizar = "UPDATE Compras SET no_orden_compra = " + to_string(no_orden_compra) +
            ", id_proveedor = " + to_string(id_proveedor) + ", fecha_orden = '" + fecha_orden +
            "' WHERE idCompra = " + to_string(idCompra);
        const char* i = actualizar.c_str();
        q_estado = mysql_query(cn.getConectar(), i);

        if (!q_estado) {
            cout << "Compra actualizada con éxito..." << endl;

            // Primero, eliminamos todos los detalles actuales
            string borrarDetalles = "DELETE FROM Compras_detalle WHERE idCompra = " + to_string(idCompra);
            const char* bd = borrarDetalles.c_str();
            q_estado = mysql_query(cn.getConectar(), bd);
            if (!q_estado) {
                // Luego, insertamos los nuevos detalles
                for (ComprasDetalle& detalle : detalles) {
                    detalle.setIdCompra(idCompra);
                    detalle.crear();
                }
            }
            else {
                cout << " xxx Error al eliminar los detalles de compra xxx" << endl;
            }
        }
        else {
            cout << " xxx Error al actualizar la compra xxx" << endl;
        }
    }
    else {
        cout << " xxx Error en la conexión xxx" << endl;
    }
    cn.cerrar_conexion();

}

void Compras::borrar() {
    // Implementar la lógica de eliminación
    int q_estado;
//    int q_estadoe;
    ConexionDB cn;
    cn.abrir_conexion();
    string ii = to_string(idCompra);
    if (cn.getConectar()) {
        // Primero borrar los detalles de la compra
        string borrarDetalle = "delete FROM db_mercado.compras_detalle where idCompra= '" + ii +"'";
        const char* cd = borrarDetalle.c_str();
        q_estado = mysql_query(cn.getConectar(), cd);
        if (!q_estado) {
            cout << "Eliminacion Detalle Exitosa ..." << endl << endl;
        
        }
        else {
            cout << " xxx Error al Eliminar Detalle  xxx" << endl << endl;
            return;
        }
        // Luego borrar la compra
        string borrarEncabezado = "delete FROM db_mercado.compras where idCompra= '" + ii + "'";
        const char* ce = borrarEncabezado.c_str();
        q_estado = mysql_query(cn.getConectar(), ce);
        if (!q_estado) {
            cout << "Eliminacion Compra Exitosa ..." << endl << endl;

        }
        else {
            cout << " xxx Error al Eliminar Compra  xxx" << endl << endl;         
        }

    }
    else {
        cout << " xxx Error en la Conexion xxxx" << endl << endl;
    }
    cn.cerrar_conexion();
}


