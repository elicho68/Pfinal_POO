#include "Proveedores.h"

// Setters
void Proveedores::setIdProveedor(int idPro) { idProveedor = idPro; }
void Proveedores::setProveedor(string pro) { proveedor = pro; }
void Proveedores::setNit(string n) { nit = n; }
void Proveedores::setDireccion(string dir) { direccion = dir; }
void Proveedores::setTelefono(int tel) { telefono = tel; }

// Getters
int Proveedores::getIdProveedor() { return idProveedor; }
string Proveedores::getProveedor() { return proveedor; }
string Proveedores::getNit() { return nit; }
string Proveedores::getDireccion() { return direccion; }
int Proveedores::getTelefono() { return telefono; }

// CRUD methods
void Proveedores::crear() {
    int q_estado;
    ConexionDB cn;
    cn.abrir_conexion();
    string t = to_string(telefono);
    if (cn.getConectar()) {
        string insertar = "INSERT INTO Proveedores (proveedor, nit, direccion, telefono) VALUES ('" + proveedor + "', '" + nit + "', '" + direccion + "', '" + t + "')";
        const char* i = insertar.c_str();
        q_estado = mysql_query(cn.getConectar(), i);
        if (!q_estado) {
            cout << "Ingreso Exitoso ..." << endl << endl;
        }
        else {
            cout << " xxx Error al Ingresar  xxx" << endl << endl;
        }
    }
    else {
        cout << " xxx Error en la Conexion xxxx" << endl << endl;
    }
    cn.cerrar_conexion();
}

void Proveedores::leer() {
    int q_estado;
    ConexionDB cn;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    cn.abrir_conexion();

    if (cn.getConectar()) {
        cout << "------------ Datos de Proveedores ------------" << endl;
        string consulta = "SELECT * FROM proveedores";
        const char* c = consulta.c_str();
        q_estado = mysql_query(cn.getConectar(), c);
        if (!q_estado) {
            resultado = mysql_store_result(cn.getConectar());
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << endl;
            }
        }
        else {
            cout << " xxx Error al Consultar  xxx" << endl << endl;
        }
    }
    else {
        cout << " xxx Error en la Conexion xxxx" << endl << endl;
    }
    cn.cerrar_conexion();
}

void Proveedores::actualizar() {
    int q_estado;
    ConexionDB cn;

    cn.abrir_conexion();
    string t = to_string(telefono);
    string ii = to_string(idProveedor);
    if (cn.getConectar()) {
        string actualizar = "UPDATE proveedores SET proveedor = '" + proveedor + "', nit='" + nit + "', direccion = '" + direccion + "', telefono ='" + t + "' WHERE idProveedor = '" + ii + "'";
        const char* i = actualizar.c_str();
        q_estado = mysql_query(cn.getConectar(), i);
        if (!q_estado) {
            cout << "Actualizacion Exitosa ..." << endl << endl;
        }
        else {
            cout << " xxx Error al Actualizar  xxx" << endl << endl;
        }
    }
    else {
        cout << " xxx Error en la Conexion xxxx" << endl << endl;
    }
    cn.cerrar_conexion();
}

void Proveedores::borrar() {
    int q_estado;
    ConexionDB cn;

    cn.abrir_conexion();
    string ii = to_string(idProveedor);
    if (cn.getConectar()) {
        string borrar = "DELETE FROM proveedores WHERE idProveedor = " + ii;
        const char* i = borrar.c_str();
        q_estado = mysql_query(cn.getConectar(), i);
        if (!q_estado) {
            cout << "Eliminacion Exitosa ..." << endl << endl;
        }
        else {
            cout << " xxx Error al Eliminar  xxx" << endl << endl;
        }
    }
    else {
        cout << " xxx Error en la Conexion xxxx" << endl << endl;
    }
    cn.cerrar_conexion();
}

bool Proveedores::buscar(int id) {
    int q_estado;
    ConexionDB cn;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    cn.abrir_conexion();

    if (cn.getConectar()) {
        string consulta = "SELECT * FROM proveedores WHERE idProveedor = " + to_string(id);
        const char* c = consulta.c_str();
        q_estado = mysql_query(cn.getConectar(), c);

        if (!q_estado) {
            resultado = mysql_store_result(cn.getConectar());
            if (fila = mysql_fetch_row(resultado)) {
                idProveedor = stoi(fila[0]);
                proveedor = fila[1];
                nit = fila[2];
                direccion = fila[3];
                telefono = stoi(fila[4]);
                cn.cerrar_conexion();
                return true;
            }
        }
    }
    cn.cerrar_conexion();
    return false;
}
