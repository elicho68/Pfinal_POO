#include "Empleados.h"

// Constructor sin parámetros
Empleados::Empleados() : idEmpleado(0), idPuesto(0), genero(false) {}

Empleados::Empleados(int idEmp, string nom, string ape, string dir, string tel, string dpi, bool gen, string fechaNac, int idPue, string fechaInicio, string fechaIng)
    : idEmpleado(idEmp), nombres(nom), apellidos(ape), direccion(dir), telefono(tel), dpi(dpi), genero(gen), fecha_nacimiento(fechaNac), idPuesto(idPue), fecha_inicio_labores(fechaInicio), fechaingreso(fechaIng) {}

void Empleados::setIdEmpleado(int idEmp) { idEmpleado = idEmp; }
void Empleados::setNombres(string nom) { nombres = nom; }
void Empleados::setApellidos(string ape) { apellidos = ape; }
void Empleados::setDireccion(string dir) { direccion = dir; }
void Empleados::setTelefono(string tel) { telefono = tel; }
void Empleados::setDpi(string dpi) { this->dpi = dpi; }
void Empleados::setGenero(bool gen) { genero = gen; }
void Empleados::setFechaNacimiento(string fechaNac) { fecha_nacimiento = fechaNac; }
void Empleados::setIdPuesto(int idPue) { idPuesto = idPue; }
void Empleados::setFechaInicioLabores(string fechaInicio) { fecha_inicio_labores = fechaInicio; }
void Empleados::setFechaIngreso(string fechaIng) { fechaingreso = fechaIng; }

int Empleados::getIdEmpleado() { return idEmpleado; }
string Empleados::getNombres() { return nombres; }
string Empleados::getApellidos() { return apellidos; }
string Empleados::getDireccion() { return direccion; }
string Empleados::getTelefono() { return telefono; }
string Empleados::getDpi() { return dpi; }
bool Empleados::getGenero() { return genero; }
string Empleados::getFechaNacimiento() { return fecha_nacimiento; }
int Empleados::getIdPuesto() { return idPuesto; }
string Empleados::getFechaInicioLabores() { return fecha_inicio_labores; }
string Empleados::getFechaIngreso() { return fechaingreso; }


bool Empleados::buscarPorId(int idEmp) {
    int q_estado;
    ConexionDB cn;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    cn.abrir_conexion();

    if (cn.getConectar()) {
        string consulta = "SELECT * FROM empleados WHERE idEmpleado = " + to_string(idEmp);
        const char* c = consulta.c_str();
        q_estado = mysql_query(cn.getConectar(), c);

        if (!q_estado) {
            resultado = mysql_store_result(cn.getConectar());
            if ((fila = mysql_fetch_row(resultado))) {
                idEmpleado = stoi(fila[0]);
                nombres = fila[1];
                apellidos = fila[2];
                direccion = fila[3];
                telefono = fila[4];
                dpi = fila[5];
                genero = fila[6][0] == '1';
                fecha_nacimiento = fila[7];
                idPuesto = stoi(fila[8]);
                fecha_inicio_labores = fila[9];
                fechaingreso = fila[10];
                cn.cerrar_conexion();
                return true;
            }
        }
    }
    cn.cerrar_conexion();
    return false;
}


void Empleados::crear() {
    // Implementación del método para crear un empleado
    int q_estado;
    ConexionDB cn;

    // Obtener fecha y hora actual
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);
    char fecha_hora_actual[20];
    strftime(fecha_hora_actual, sizeof(fecha_hora_actual), "%Y-%m-%d %H:%M:%S", &ltm);
    string fecha_actual = fecha_hora_actual;


    cn.abrir_conexion();
    if (cn.getConectar()) {
        string insertar = "INSERT INTO Empleados (nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fechaingreso) VALUES ('" + nombres + "', '" + apellidos + "', '" + direccion + "', '" + telefono + "', '" + dpi + "', " + to_string(genero) + ", '" + fecha_nacimiento + "', " + to_string(idPuesto) + ", '" + fecha_inicio_labores + "', '" + fecha_actual + "')";
        const char* i = insertar.c_str();
        q_estado = mysql_query(cn.getConectar(), i);
        if (!q_estado) {
            cout << "Ingreso Exitoso ..." << endl;
        }
        else {
            cout << " xxx Error al Ingresar  xxx" << endl;
        }
    }
    else {
        cout << " xxx Error en la Conexion xxxx" << endl;
    }
    cn.cerrar_conexion();
}

void Empleados::leer() {
    // Implementación del método para leer empleados
    int q_estado;
    ConexionDB cn;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;

    cn.abrir_conexion();
    if (cn.getConectar()) {
        string consulta = "SELECT * FROM Empleados";
        const char* c = consulta.c_str();
        q_estado = mysql_query(cn.getConectar(), c);
        if (!q_estado) {
            resultado = mysql_store_result(cn.getConectar());
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << ", " << fila[6] << ", " << fila[7] << ", " << fila[8] << ", " << fila[9] << ", " << fila[10] << endl;
            }
        }
        else {
            cout << " xxx Error al Consultar  xxx" << endl;
        }
    }
    else {
        cout << " xxx Error en la Conexion xxxx" << endl;
    }
    cn.cerrar_conexion();
}

void Empleados::actualizar() {
    // Implementación del método para actualizar un empleado
    int q_estado;
    ConexionDB cn;

    // Obtener fecha y hora actual
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);
    char fecha_hora_actual[20];
    strftime(fecha_hora_actual, sizeof(fecha_hora_actual), "%Y-%m-%d %H:%M:%S", &ltm);
    string fecha_actual = fecha_hora_actual;


    cn.abrir_conexion();
    string ii = to_string(idEmpleado);
    if (cn.getConectar()) {
        string actualizar = "UPDATE Empleados SET nombres = '" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono = '" + telefono + "', DPI = '" + dpi + "', genero = " + to_string(genero) + ", fecha_nacimiento = '" + fecha_nacimiento + "', idPuesto = " + to_string(idPuesto) + ", fecha_inicio_labores = '" + fecha_inicio_labores + "', fechaingreso = '" + fecha_actual + "' WHERE idEmpleado = '" + ii + "'";
        const char* i = actualizar.c_str();
        q_estado = mysql_query(cn.getConectar(), i);
        if (!q_estado) {
            cout << "Actualizacion Exitosa ..." << endl;
        }
        else {
            cout << " xxx Error al Actualizar  xxx" << endl;
        }
    }
    else {
        cout << " xxx Error en la Conexion xxxx" << endl;
    }
    cn.cerrar_conexion();

}

void Empleados::borrar() {
    // Implementación del método para borrar un empleado
    int q_estado;
    ConexionDB cn;

    cn.abrir_conexion();
    string ii = to_string(idEmpleado);
    if (cn.getConectar()) {
        string borrar = "DELETE FROM Empleados WHERE idEmpleado = '" + ii + "'";
        const char* i = borrar.c_str();
        q_estado = mysql_query(cn.getConectar(), i);
        if (!q_estado) {
            cout << "Eliminacion Exitosa ..." << endl;
        }
        else {
            cout << " xxx Error al Eliminar  xxx" << endl;
        }
    }
    else {
        cout << " xxx Error en la Conexion xxxx" << endl;
    }
    cn.cerrar_conexion();
}

