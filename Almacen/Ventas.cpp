#include "Ventas.h"

// Constructor
Ventas::Ventas() : idVenta(0), nofactura(0), serie('A'), fechafactura(""), idcliente(0), idempleado(0), fechaingreso("") {}

Ventas::Ventas(int idV, int noFact, char ser, string fechaFact, int idCli, int idEmp, string fechaIng, vector<VentasDetalle> dets)
    : idVenta(idV), nofactura(noFact), serie(ser), fechafactura(fechaFact), idcliente(idCli), idempleado(idEmp), fechaingreso(fechaIng), detalles(dets) {}

void Ventas::setIdVenta(int idV) { idVenta = idV; }
void Ventas::setNoFactura(int noFact) { nofactura = noFact; }
void Ventas::setSerie(char ser) { serie = ser; }
void Ventas::setFechaFactura(string fechaFact) { fechafactura = fechaFact; }
void Ventas::setIdCliente(int idCli) { idcliente = idCli; }
void Ventas::setIdEmpleado(int idEmp) { idempleado = idEmp; }
void Ventas::setFechaIngreso(string fechaIng) { fechaingreso = fechaIng; }
void Ventas::setDetalles(vector<VentasDetalle> dets) { detalles = dets; }

int Ventas::getIdVenta() { return idVenta; }
int Ventas::getNoFactura() { return nofactura; }
char Ventas::getSerie() { return serie; }
string Ventas::getFechaFactura() { return fechafactura; }
int Ventas::getIdCliente() { return idcliente; }
int Ventas::getIdEmpleado() { return idempleado; }
string Ventas::getFechaIngreso() { return fechaingreso; }
vector<VentasDetalle> Ventas::getDetalles() { return detalles; }

void Ventas::crear() {
    int q_estado;
    ConexionDB cn;
    cn.abrir_conexion();

    if (cn.getConectar()) {
        string insertar = "INSERT INTO Ventas (nofactura, serie, fechafactura, idcliente, idempleado, fechaingreso) VALUES ('" +
            to_string(nofactura) + "', '" + serie + "', '" + fechafactura + "', '" + to_string(idcliente) + "', '" + to_string(idempleado) + "', NOW())";
        const char* i = insertar.c_str();
        q_estado = mysql_query(cn.getConectar(), i);

        if (!q_estado) {
            cout << "Ingreso Exitoso en Ventas..." << endl;
            int venta_id = mysql_insert_id(cn.getConectar()); // Obtener el idVenta insertado

            for (VentasDetalle& detalle : detalles) {
                detalle.setIdVenta(venta_id);
                detalle.crear();
            }
            cout << "Ingreso Exitoso en Ventas y Detalle..." << endl;
        }
        else {
            cout << " xxx Error al Ingresar en Ventas xxx" << endl;
        }
    }
    else {
        cout << " xxx Error en la Conexion xxx" << endl;
    }
    cn.cerrar_conexion();
}

void Ventas::leer() {
    int q_estado;
    ConexionDB cn;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    cn.abrir_conexion();

    if (cn.getConectar()) {
        cout << "------------ Datos de Ventas ------------" << endl;
        string consulta = "SELECT * FROM Ventas";
        const char* c = consulta.c_str();
        q_estado = mysql_query(cn.getConectar(), c);

        if (!q_estado) {
            resultado = mysql_store_result(cn.getConectar());
            while ((fila = mysql_fetch_row(resultado))) {
                cout << "ID: " << fila[0] << " No Factura: " << fila[1] << " Serie: " << fila[2] << " Fecha Factura: " << fila[3] << " ID Cliente: " << fila[4] << " ID Empleado: " << fila[5] << " Fecha Ingreso: " << fila[6] << endl;
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

void Ventas::actualizar() {
    int q_estado;
    ConexionDB cn;
    cn.abrir_conexion();

    if (cn.getConectar()) {
        string actualizar = "UPDATE Ventas SET nofactura = " + to_string(nofactura) +
            ", serie = '" + serie + "', fechafactura = '" + fechafactura +
            "', idcliente = " + to_string(idcliente) + ", idempleado = " + to_string(idempleado) +
            " WHERE idVenta = " + to_string(idVenta);
        const char* i = actualizar.c_str();
        q_estado = mysql_query(cn.getConectar(), i);

        if (!q_estado) {
            cout << "Venta actualizada con éxito..." << endl;

            // Primero, eliminamos todos los detalles actuales
            string borrarDetalles = "DELETE FROM Ventas_detalle WHERE idVenta = " + to_string(idVenta);
            const char* bd = borrarDetalles.c_str();
            q_estado = mysql_query(cn.getConectar(), bd);
            if (!q_estado) {
                // Luego, insertamos los nuevos detalles
                for (VentasDetalle& detalle : detalles) {
                    detalle.setIdVenta(idVenta);
                    detalle.crear();
                }
            }
            else {
                cout << " xxx Error al eliminar los detalles de venta xxx" << endl;
            }
        }
        else {
            cout << " xxx Error al actualizar la venta xxx" << endl;
        }
    }
    else {
        cout << " xxx Error en la conexión xxx" << endl;
    }
    cn.cerrar_conexion();
}

void Ventas::borrar() {
    int q_estado;
    ConexionDB cn;
    cn.abrir_conexion();

    if (cn.getConectar()) {
        // Primero borrar los detalles de la venta
        string borrarDetalles = "DELETE FROM Ventas_detalle WHERE idVenta = " + to_string(idVenta);
        const char* bd = borrarDetalles.c_str();
        q_estado = mysql_query(cn.getConectar(), bd);
        if (!q_estado) {
            cout << "Detalles de venta eliminados exitosamente..." << endl;
        }
        else {
            cout << " xxx Error al eliminar los detalles de venta xxx" << endl;
            return;
        }

        // Luego borrar la venta
        string borrarVenta = "DELETE FROM Ventas WHERE idVenta = " + to_string(idVenta);
        const char* bv = borrarVenta.c_str();
        q_estado = mysql_query(cn.getConectar(), bv);
        if (!q_estado) {
            cout << "Venta eliminada exitosamente..." << endl;
        }
        else {
            cout << " xxx Error al eliminar la venta xxx" << endl;
        }
    }
    else {
        cout << " xxx Error en la conexión xxx" << endl;
    }
    cn.cerrar_conexion();
}
