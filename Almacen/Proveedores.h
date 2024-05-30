#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionDB.h"
#include <string>

using namespace std;


class Proveedores
{
	//atributos
private:
	int idProveedor = 0;
	int telefono = 0;
    string proveedor, nit, direccion ;

public:
    Proveedores() {
    }
    Proveedores(int idPro, string pro, string n, string dir, int tel) {
        idProveedor = idPro;
        proveedor = pro;
        nit = n;
        direccion = dir;
        telefono = tel;
    }

	void setIdProveedor(int idPro) { idProveedor = idPro; }
	void setProveedor(string pro) { proveedor = pro; }
	void setNit(string n) { nit = n; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }

	//get (mostrar)
	int getIdProveedor() { return idProveedor; }
	string getProveedor() { return proveedor; }
	string getNit() { return nit; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	
	// CRUD methods
	void crear();
	void leer();
	void actualizar();
	void borrar();

};

void Proveedores::crear() {
	int q_estado;
	ConexionDB cn;// = ConexionBD();

	cn.abrir_conexion();
	string t = to_string(telefono);
	if (cn.getConectar()) {
		string  insertar = "INSERT	INTO Proveedores (proveedor,nit,direccion,telefono) values  ('" + proveedor + "','" + nit + "','" + direccion + "','" + t + "')";
		const char* i = insertar.c_str();
		// executar el query
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

void Proveedores::leer() {
	int q_estado;
	ConexionDB cn;// = ConexionBD();
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	cn.abrir_conexion();

	if (cn.getConectar()) {

		cout << "------------ Datos de Proveedores ------------" << endl;
		string consulta = "select * from proveedores";
		const char* c = consulta.c_str();
		q_estado = mysql_query(cn.getConectar(), c);
		if (!q_estado) {
			resultado = mysql_store_result(cn.getConectar());
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << endl;
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

void Proveedores::actualizar() {
	int q_estado;
	ConexionDB cn; //= ConexionBD();

	cn.abrir_conexion();
	string t = to_string(telefono);
	string ii = to_string(idProveedor);
	if (cn.getConectar()) {
		string  actualizar =
			"UPDATE proveedores SET proveedor = '" + proveedor + "', nit='" + nit + "',  direccion = '" + direccion + "', telefono ='" + t + "' where idProveedor = '" + ii + "'";
		const char* i = actualizar.c_str();
		// executar el query
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

// metodo
void Proveedores::borrar() {
	int q_estado;
	ConexionDB cn;// = ConexionBD();

	cn.abrir_conexion();
	string ii = to_string(idProveedor);
	if (cn.getConectar()) {
		string  borrar =
			"delete from proveedores where idProveedor = " + ii + "";
		const char* i = borrar.c_str();
		// executar el query
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
