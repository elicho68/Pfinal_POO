#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionDB.h"
#include <string>

using namespace std;

class Productos
{
    // Atributos
private:
    int idProducto=0;
    string producto;
    int idMarca=0;
    string descripcion;
    string imagen;
    double precio_costo;
    double precio_venta;
    int existencia=0;
    string fecha_ingreso;

public:
    Productos() {}

    Productos(int idProd, string prod, int idMar, string desc, string img, double pre_c, double pre_v, int exist, string fecha) {
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

    void setIdProducto(int idProd) { idProducto = idProd; }
    void setProducto(string prod) { producto = prod; }
    void setIdMarca(int idMar) { idMarca = idMar; }
    void setDescripcion(string desc) { descripcion = desc; }
    void setImagen(string img) { imagen = img; }
    void setPrecioCosto(double pre_c) { precio_costo = pre_c; }
    void setPrecioVenta(double pre_v) { precio_venta = pre_v; }
    void setExistencia(int exist) { existencia = exist; }
    void setFechaIngreso(string fecha) { fecha_ingreso = fecha; }

    // Getters
    int getIdProducto() { return idProducto; }
    string getProducto() { return producto; }
    int getIdMarca() { return idMarca; }
    string getDescripcion() { return descripcion; }
    string getImagen() { return imagen; }
    double getPrecioCosto() { return precio_costo; }
    double getPrecioVenta() { return precio_venta; }
    int getExistencia() { return existencia; }
    string getFechaIngreso() { return fecha_ingreso; }

    // CRUD methods
    void crear();
    void leer();
    void actualizar();
    void borrar();
};

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
        string actualizar = "UPDATE Productos SET producto = '" + producto + "', idMarca = " + to_string(idMarca) + ", Descripcion = '" + descripcion + "', Imagen = '" + imagen + "', precio_costo = " + to_string(precio_costo) + ", precio_venta = " + to_string(precio_venta) + ", existencia = " + to_string(existencia) + ", fecha_ingreso = '" + fecha_ingreso + "' WHERE idProductos = '" + idProd_str +"'";
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
        string borrar = "DELETE FROM Productos WHERE idProductos = '" + idProd_str + "'";
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
