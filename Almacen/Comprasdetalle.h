#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionDB.h"

using namespace std;

class ComprasDetalle {
private:
    long long id_compra_detalle;
    int idCompra;
    int idproducto;
    int cantidad;
    double precio_costo_unitario;

public:
    ComprasDetalle();
    ComprasDetalle(long long idDet, int idC, int idProd, int cant, double precio);

    void setIdCompraDetalle(long long idDet);
    void setIdCompra(int idC);
    void setIdProducto(int idProd);
    void setCantidad(int cant);
    void setPrecioCostoUnitario(double precio);

    long long getIdCompraDetalle();
    int getIdCompra();
    int getIdProducto();
    int getCantidad();
    double getPrecioCostoUnitario();

    void crear();
    void leer();
    void actualizar();
    void borrar();
};
