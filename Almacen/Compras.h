#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include <vector>
#include "ConexionDB.h"
#include "ComprasDetalle.h"

using namespace std;

class Compras {
private:
    int idCompra;
    int no_orden_compra;
    int id_proveedor;
    string fecha_orden;
    string fechaingreso;
    vector<ComprasDetalle> detalles;

public:
    Compras();
    Compras(int idC, int noOrden, int idProv, string fechaOrd, string fechaIng, vector<ComprasDetalle> dets);

    void setIdCompra(int idC);
    void setNoOrdenCompra(int noOrden);
    void setIdProveedor(int idProv);
    void setFechaOrden(string fechaOrd);
    void setFechaIngreso(string fechaIng);
    void setDetalles(vector<ComprasDetalle> dets);

    int getIdCompra();
    int getNoOrdenCompra();
    int getIdProveedor();
    string getFechaOrden();
    string getFechaIngreso();
    vector<ComprasDetalle> getDetalles();

    void crear();
    void leer();
    void actualizar();
    void borrar();
};
