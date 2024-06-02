#include "Clientes.h"

// Definición del constructor sin parámetros
Clientes::Clientes() : idCliente(0), telefono(0), genero(0) {}

Clientes::Clientes(int id, string nom, string ape, string n, bool gen, int tel, string correo, string fecha)
    : idCliente(id), nombres(nom), apellidos(ape), nit(n), genero(gen), telefono(tel), correo_electronico(correo), fechaingreso(fecha) {}

void Clientes::setIdCliente(int id) { idCliente = id; }
void Clientes::setNombres(string nom) { nombres = nom; }
void Clientes::setApellidos(string ape) { apellidos = ape; }
void Clientes::setNit(string n) { nit = n; }
void Clientes::setGenero(bool gen) { genero = gen; }
void Clientes::setTelefono(int tel) { telefono = tel; }
void Clientes::setCorreoElectronico(string correo) { correo_electronico = correo; }
void Clientes::setFechaIngreso(string fecha) { fechaingreso = fecha; }

int Clientes::getIdCliente() { return idCliente; }
string Clientes::getNombres() { return nombres; }
string Clientes::getApellidos() { return apellidos; }
string Clientes::getNit() { return nit; }
bool Clientes::getGenero() { return genero; }
int Clientes::getTelefono() { return telefono; }
string Clientes::getCorreoElectronico() { return correo_electronico; }
string Clientes::getFechaIngreso() { return fechaingreso; }

bool Clientes::buscarPorNit(string nit) {
    int q_estado;
    ConexionDB cn;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    cn.abrir_conexion();

    if (cn.getConectar()) {
        string consulta = "SELECT * FROM clientes WHERE nit = '" + nit + "'";
        const char* c = consulta.c_str();
        q_estado = mysql_query(cn.getConectar(), c);

        if (!q_estado) {
            resultado = mysql_store_result(cn.getConectar());
            if ((fila = mysql_fetch_row(resultado))) {
                idCliente = stoi(fila[0]);
                nombres = fila[1];
                apellidos = fila[2];
                this->nit = fila[3];
                genero = fila[4][0] == '1';
                telefono = stoi(fila[5]);
                correo_electronico = fila[6];
                fechaingreso = fila[7];
                cn.cerrar_conexion();
                return true;
            }
        }
    }
    cn.cerrar_conexion();
    return false;
}

void Clientes::crear() {
    int q_estado;
    ConexionDB cn;
    cn.abrir_conexion();
    string t = to_string(telefono);
    string g = to_string(genero);
    if (cn.getConectar()) {
        string insertar = "INSERT INTO Clientes (nombres, apellidos, nit, genero, telefono, correo_electronico, fechaingreso) VALUES ('" + nombres + "', '" + apellidos + "', '" + nit + "', " + g + ", '" + t + "', '" + correo_electronico + "', '" + fechaingreso + "')";
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

void Clientes::leer() {
    int q_estado;
    ConexionDB cn;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    cn.abrir_conexion();

    if (cn.getConectar()) {
        cout << "------------ Datos de Clientes ------------" << endl;
        string consulta = "SELECT * FROM Clientes";
        const char* c = consulta.c_str();
        q_estado = mysql_query(cn.getConectar(), c);
        if (!q_estado) {
            resultado = mysql_store_result(cn.getConectar());
            while ((fila = mysql_fetch_row(resultado))) {
                cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << ", " << fila[6] << ", " << fila[7] << endl;
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

void Clientes::actualizar() {
    int q_estado;
    ConexionDB cn;
    cn.abrir_conexion();
    string t = to_string(telefono);
    string g = to_string(genero);
    string ii = to_string(idCliente);
    if (cn.getConectar()) {
        string actualizar = "UPDATE Clientes SET nombres = '" + nombres + "', apellidos = '" + apellidos + "', nit = '" + nit + "', genero = " + g + ", telefono = '" + t + "', correo_electronico = '" + correo_electronico + "', fechaingreso = '" + fechaingreso + "' WHERE idCliente = " + ii;
        const char* i = actualizar.c_str();
        q_estado = mysql_query(cn.getConectar(), i);
        if (!q_estado) {
            cout << "Actualizacion Exitosa ..." << endl << endl;
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

void Clientes::borrar() {
    int q_estado;
    ConexionDB cn;
    cn.abrir_conexion();
    string ii = to_string(idCliente);
    if (cn.getConectar()) {
        string borrar = "DELETE FROM Clientes WHERE idCliente = " + ii;
        const char* i = borrar.c_str();
        q_estado = mysql_query(cn.getConectar(), i);
        if (!q_estado) {
            cout << "Eliminacion Exitosa ..." << endl << endl;
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
