#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionDB.h"

using namespace std;

class Empleados {
private:
    int idEmpleado;
    string nombres, apellidos, direccion, telefono, dpi, fecha_nacimiento, fecha_inicio_labores, fechaingreso;
    bool genero;
    int idPuesto;

public:
    Empleados();
    Empleados(int idEmp, string nom, string ape, string dir, string tel, string dpi, bool gen, string fechaNac, int idPue, string fechaInicio, string fechaIng);

    void setIdEmpleado(int idEmp);
    void setNombres(string nom);
    void setApellidos(string ape);
    void setDireccion(string dir);
    void setTelefono(string tel);
    void setDpi(string dpi);
    void setGenero(bool gen);
    void setFechaNacimiento(string fechaNac);
    void setIdPuesto(int idPue);
    void setFechaInicioLabores(string fechaInicio);
    void setFechaIngreso(string fechaIng);

    int getIdEmpleado();
    string getNombres();
    string getApellidos();
    string getDireccion();
    string getTelefono();
    string getDpi();
    bool getGenero();
    string getFechaNacimiento();
    int getIdPuesto();
    string getFechaInicioLabores();
    string getFechaIngreso();

    void crear();
    void leer();
    void actualizar();
    void borrar();
    bool buscarPorId(int idEmp);
};

/*
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


*/