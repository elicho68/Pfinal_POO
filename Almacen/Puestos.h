#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionDB.h"
#include <string>

using namespace std;

class Puestos
{
	//atributos
private:
	int idPuestos = 0;
	string Puesto;
public:
	Puestos() {
	}
	Puestos(int idPue, string pue) {
		idPuestos = idPue;
		Puesto = pue;
	}

	void setidPuesto(int idPue) { idPuestos = idPue; }
	void setPuesto(string pue) { Puesto = pue; }

	//get (mostrar)
	int getidPuesto() { return idPuestos; }
	string getPuesto() { return Puesto; }

	// CRUD methods
	void crear();
	void leer();
	void actualizar();
	void borrar();

};

void Puestos::crear() {
	int q_estado;
	ConexionDB cn;// = ConexionBD();

	cn.abrir_conexion();
	if (cn.getConectar()) {
		string  insertar = "INSERT	INTO Puestos (Puesto) values  ('" + Puesto + "')";
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

void Puestos::leer() {
	int q_estado;
	ConexionDB cn;// = ConexionBD();
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	cn.abrir_conexion();

	if (cn.getConectar()) {

		cout << "------------ Datos de Puestor ------------" << endl;
		string consulta = "select * from Puestos";
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

void Puestos::actualizar() {
	int q_estado;
	ConexionDB cn; //= ConexionBD();

	cn.abrir_conexion();
	string ii = to_string(idPuestos);
	if (cn.getConectar()) {
		string  actualizar =
			"UPDATE Puestos SET Puesto = '" + Puesto + "' where idPuesto = '" + ii + "'";
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
void Puestos::borrar() {
	int q_estado;
	ConexionDB cn;// = ConexionBD();

	cn.abrir_conexion();
	string ii = to_string(idPuestos);
	if (cn.getConectar()) {
		string  borrar =
			"delete from Puestos where idPuesto = '" + ii + "'";
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
