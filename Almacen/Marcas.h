#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionDB.h"
#include <string>

using namespace std;

class Marcas
{
	//atributos
private:
	int idMarcas = 0;
	string marca;
public:
	Marcas() {
	}
	Marcas(int idMar, string mar) {
		idMarcas = idMar;
		marca = mar;
	}

	void setIdMarca(int idMar) { idMarcas = idMar; }
	void setMarca(string mar) { marca = mar; }
	
	//get (mostrar)
	int getIdMarca() { return idMarcas; }
	string getMarca() { return marca; }

	// CRUD methods
	void crear();
	void leer();
	void actualizar();
	void borrar();

};

void Marcas::crear() {
	int q_estado;
	ConexionDB cn;// = ConexionBD();

	cn.abrir_conexion();
	if (cn.getConectar()) {
		string  insertar = "INSERT	INTO Marcas (marca) values  ('" + marca + "')";
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

void Marcas::leer() {
	int q_estado;
	ConexionDB cn;// = ConexionBD();
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	cn.abrir_conexion();

	if (cn.getConectar()) {

		cout << "------------ Datos de Marcar ------------" << endl;
		string consulta = "select * from marcas";
		const char* c = consulta.c_str();
		q_estado = mysql_query(cn.getConectar(), c);
		if (!q_estado) {
			resultado = mysql_store_result(cn.getConectar());
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << "," << fila[1] << endl;
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

void Marcas::actualizar() {
	int q_estado;
	ConexionDB cn; //= ConexionBD();

	cn.abrir_conexion();
	string ii = to_string(idMarcas);
	if (cn.getConectar()) {
		string  actualizar =
			"UPDATE marcas SET marca = '" + marca + "' where idMarcas = '" + ii + "'";
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
void Marcas::borrar() {
	int q_estado;
	ConexionDB cn;// = ConexionBD();

	cn.abrir_conexion();
	string ii = to_string(idMarcas);
	if (cn.getConectar()) {
		string  borrar =
			"delete from marcas where idMarcas = " + ii + "";
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
