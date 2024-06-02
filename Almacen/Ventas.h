#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include <vector>
#include "ConexionDB.h"
#include "VentasDetalle.h"

using namespace std;

class Ventas {
private:
    int idVenta;
    int nofactura;
    char serie;
    string fechafactura;
    int idcliente;
    int idempleado;
    string fechaingreso;
    vector<VentasDetalle> detalles;

public:
    Ventas();
    Ventas(int idV, int noFact, char ser, string fechaFact, int idCli, int idEmp, string fechaIng, vector<VentasDetalle> dets);

    void setIdVenta(int idV);
    void setNoFactura(int noFact);
    void setSerie(char ser);
    void setFechaFactura(string fechaFact);
    void setIdCliente(int idCli);
    void setIdEmpleado(int idEmp);
    void setFechaIngreso(string fechaIng);
    void setDetalles(vector<VentasDetalle> dets);

    int getIdVenta();
    int getNoFactura();
    char getSerie();
    string getFechaFactura();
    int getIdCliente();
    int getIdEmpleado();
    string getFechaIngreso();
    vector<VentasDetalle> getDetalles();

    void crear();
    void leer();
    void actualizar();
    void borrar();
};
