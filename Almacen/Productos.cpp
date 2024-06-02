#include "Productos.h"

// Definición del constructor sin parámetros
Productos::Productos() : idProducto(0), idMarca(0), existencia(0), precio_costo(0.0), precio_venta(0.0) {}

Productos::Productos(int idProd, string prod, int idMar, string desc, string img, double pre_c, double pre_v, int exist, string fecha)
    : idProducto(idProd), producto(prod), idMarca(idMar), descripcion(desc), imagen(img), precio_costo(pre_c), precio_venta(pre_v), existencia(exist), fecha_ingreso(fecha) {}

void Productos::setIdProducto(int idProd) { idProducto = idProd; }
void Productos::setProducto(string prod) { producto = prod; }
void Productos::setIdMarca(int idMar) { idMarca = idMar; }
void Productos::setDescripcion(string desc) { descripcion = desc; }
void Productos::setImagen(string img) { imagen = img; }
void Productos::setPrecioCosto(double pre_c) { precio_costo = pre_c; }
void Productos::setPrecioVenta(double pre_v) { precio_venta = pre_v; }
void Productos::setExistencia(int exist) { existencia = exist; }
void Productos::setFechaIngreso(string fecha) { fecha_ingreso = fecha; }

int Productos::getIdProducto() { return idProducto; }
string Productos::getProducto() { return producto; }
int Productos::getIdMarca() { return idMarca; }
string Productos::getDescripcion() { return descripcion; }
string Productos::getImagen() { return imagen; }
double Productos::getPrecioCosto() { return precio_costo; }
double Productos::getPrecioVenta() { return precio_venta; }
int Productos::getExistencia() { return existencia; }
string Productos::getFechaIngreso() { return fecha_ingreso; }

bool Productos::buscar(int id) {
    int q_estado;
    ConexionDB cn;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    cn.abrir_conexion();

    if (cn.getConectar()) {
        string consulta = "SELECT * FROM productos WHERE idProductos = " + to_string(id);
        const char* c = consulta.c_str();
        q_estado = mysql_query(cn.getConectar(), c);

        if (!q_estado) {
            resultado = mysql_store_result(cn.getConectar());
            if ((fila = mysql_fetch_row(resultado))) {
                idProducto = stoi(fila[0]);
                producto = fila[1];
                idMarca = stoi(fila[2]);
                descripcion = fila[3];
                imagen = fila[4];
                precio_costo = stod(fila[5]);
                precio_venta = stod(fila[6]);
                existencia = stoi(fila[7]);
                fecha_ingreso = fila[8];
                cn.cerrar_conexion();
                return true;
            }
        }
    }
    cn.cerrar_conexion();
    return false;
}

void Productos::crear() {
    int q_estado;
    ConexionDB cn;
    cn.abrir_conexion();
    if (cn.getConectar()) {
        string insertar = "INSERT INTO Productos (producto, idMarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso) VALUES ('" + producto + "', " + to_string(idMarca) + ", '" + descripcion + "', '" + imagen + "', " + to_string(precio_costo) + ", " + to_string(precio_venta) + ", " + to_string(existencia) + ", '" + fecha_ingreso + "')";
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

void Productos::leer() {
    int q_estado;
    ConexionDB cn;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;

    cn.abrir_conexion();
    if (cn.getConectar()) {
        string consulta = "SELECT * FROM Productos";
        const char* c = consulta.c_str();
        q_estado = mysql_query(cn.getConectar(), c);
        if (!q_estado) {
            resultado = mysql_store_result(cn.getConectar());
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << ", " << fila[6] << ", " << fila[7] << ", " << fila[8] << endl;
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

void Productos::actualizar() {
    int q_estado;
    ConexionDB cn;
    cn.abrir_conexion();
    string idProd_str = to_string(idProducto);
    if (cn.getConectar()) {
        string actualizar = "UPDATE Productos SET producto = '" + producto + "', idMarca = " + to_string(idMarca) + ", Descripcion = '" + descripcion + "', Imagen = '" + imagen + "', precio_costo = " + to_string(precio_costo) + ", precio_venta = " + to_string(precio_venta) + ", existencia = " + to_string(existencia) + ", fecha_ingreso = '" + fecha_ingreso + "' WHERE idProductos = " + idProd_str;
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

void Productos::borrar() {
    int q_estado;
    ConexionDB cn;
    cn.abrir_conexion();
    string idProd_str = to_string(idProducto);
    if (cn.getConectar()) {
        string borrar = "DELETE FROM Productos WHERE idProductos = " + idProd_str;
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


/*
#include "Productos.h"

// Constructor
Productos::Productos(int idProd, string prod, int idMar, string desc, string img, double pre_c, double pre_v, int exist, string fecha) {
    idProducto = idProd;
    producto = prod;
    idMarca = idMar;
    descripcion = desc;
    imagen = img;
    precio_costo = pre_c;
    precio_venta = pre_v;
    existencia = exist;
    fecha_ingreso = fecha;
}

// Setters
void Productos::setIdProducto(int idProd) { idProducto = idProd; }
void Productos::setProducto(string prod) { producto = prod; }
void Productos::setIdMarca(int idMar) { idMarca = idMar; }
void Productos::setDescripcion(string desc) { descripcion = desc; }
void Productos::setImagen(string img) { imagen = img; }
void Productos::setPrecioCosto(double pre_c) { precio_costo = pre_c; }
void Productos::setPrecioVenta(double pre_v) { precio_venta = pre_v; }
void Productos::setExistencia(int exist) { existencia = exist; }
void Productos::setFechaIngreso(string fecha) { fecha_ingreso = fecha; }

// Getters
int Productos::getIdProducto() { return idProducto; }
string Productos::getProducto() { return producto; }
int Productos::getIdMarca() { return idMarca; }
string Productos::getDescripcion() { return descripcion; }
string Productos::getImagen() { return imagen; }
double Productos::getPrecioCosto() { return precio_costo; }
double Productos::getPrecioVenta() { return precio_venta; }
int Productos::getExistencia() { return existencia; }
string Productos::getFechaIngreso() { return fecha_ingreso; }

// CRUD methods
void Productos::crear() {
    int q_estado;
    ConexionDB cn;
    cn.abrir_conexion();
    if (cn.getConectar()) {
        string insertar = "INSERT INTO Productos (producto, idMarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso) VALUES ('" + producto + "', " + to_string(idMarca) + ", '" + descripcion + "', '" + imagen + "', " + to_string(precio_costo) + ", " + to_string(precio_venta) + ", " + to_string(existencia) + ", '" + fecha_ingreso + "')";
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

void Productos::leer() {
    int q_estado;
    ConexionDB cn;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    cn.abrir_conexion();

    if (cn.getConectar()) {
        cout << "------------ Datos de Productos ------------" << endl;
        string consulta = "SELECT * FROM Productos";
        const char* c = consulta.c_str();
        q_estado = mysql_query(cn.getConectar(), c);
        if (!q_estado) {
            resultado = mysql_store_result(cn.getConectar());
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << ", " << fila[6] << ", " << fila[7] << ", " << fila[8] << endl;
            }
        }
        else {
            cout << " xxx Error al Consultar  xxx" << endl << endl;
        }
    }
    else {
        cout << " xxx Error en la Conexion xxxx" << endl;
    }
    cn.cerrar_conexion();
}

void Productos::actualizar() {
    int q_estado;
    ConexionDB cn;
    cn.abrir_conexion();
    string idProd_str = to_string(idProducto);
    if (cn.getConectar()) {
        string actualizar = "UPDATE Productos SET producto = '" + producto + "', idMarca = " + to_string(idMarca) + ", descripcion = '" + descripcion + "', imagen = '" + imagen + "', precio_costo = " + to_string(precio_costo) + ", precio_venta = " + to_string(precio_venta) + ", existencia = " + to_string(existencia) + ", fecha_ingreso = '" + fecha_ingreso + "' WHERE idProductos = " + idProd_str;
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

void Productos::borrar() {
    int q_estado;
    ConexionDB cn;
    cn.abrir_conexion();
    string idProd_str = to_string(idProducto);
    if (cn.getConectar()) {
        string borrar = "DELETE FROM Productos WHERE idProductos = " + idProd_str;
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

bool Productos::buscar(int id) {
    int q_estado;
    ConexionDB cn;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    cn.abrir_conexion();
    if (cn.getConectar()) {
        string consulta = "SELECT * FROM Productos WHERE idProductos = " + to_string(id);
        const char* c = consulta.c_str();
        q_estado = mysql_query(cn.getConectar(), c);
        if (!q_estado) {
            resultado = mysql_store_result(cn.getConectar());
            if (fila = mysql_fetch_row(resultado)) {
                idProducto = stoi(fila[0]);
                producto = fila[1];
                idMarca = stoi(fila[2]);
                descripcion = fila[3];
                imagen = fila[4];
                precio_costo = stod(fila[5]);
                precio_venta = stod(fila[6]);
                existencia = stoi(fila[7]);
                fecha_ingreso = fila[8];
                cn.cerrar_conexion();
                return true;
            }
        }
    }
    cn.cerrar_conexion();
    return false;
}
*/