#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionDB.h"

using namespace std;

class VentasDetalle {
private:
    long long idventa_detalle;
    int idVenta =0;
    int idProducto = 0;
    int cantidad =0;
    double precio_unitario =0;

public:
    VentasDetalle();
    VentasDetalle(long long idDet, int idV, int idProd, int cant, double precio);

    void setIdVentaDetalle(long long idDet);
    void setIdVenta(int idV);
    void setIdProducto(int idProd);
    void setCantidad(int cant);
    void setPrecioUnitario(double precio);

    long long getIdVentaDetalle();
    int getIdVenta();
    int getIdProducto();
    int getCantidad();
    double getPrecioUnitario();

    void crear();
    void leer();
    void actualizar();
    void borrar();
};
