#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionDB.h"

using namespace std;

class Productos {
private:
    int idProducto, idMarca, existencia;
    string producto, descripcion, imagen, fecha_ingreso;
    double precio_costo, precio_venta;

public:
    Productos(); // Declaración del constructor sin parámetros
    Productos(int idProd, string prod, int idMar, string desc, string img, double pre_c, double pre_v, int exist, string fecha);

    void setIdProducto(int idProd);
    void setProducto(string prod);
    void setIdMarca(int idMar);
    void setDescripcion(string desc);
    void setImagen(string img);
    void setPrecioCosto(double pre_c);
    void setPrecioVenta(double pre_v);
    void setExistencia(int exist);
    void setFechaIngreso(string fecha);

    int getIdProducto();
    string getProducto();
    int getIdMarca();
    string getDescripcion();
    string getImagen();
    double getPrecioCosto();
    double getPrecioVenta();
    int getExistencia();
    string getFechaIngreso();

    void crear();
    void leer();
    void actualizar();
    void borrar();
    bool buscar(int id);
};
