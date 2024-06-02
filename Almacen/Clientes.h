#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionDB.h"
#include <string>

using namespace std;

#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionDB.h"

using namespace std;

class Clientes {
private:
	int idCliente;
	int telefono;
	string nombres;
	string apellidos;
	string nit;
	string correo_electronico;
	string fechaingreso;
	bool genero;

public:
	Clientes(); // Declaración del constructor sin parámetros
	Clientes(int id, string nom, string ape, string n, bool gen, int tel, string correo, string fecha);

	void setIdCliente(int id);
	void setNombres(string nom);
	void setApellidos(string ape);
	void setNit(string n);
	void setGenero(bool gen);
	void setTelefono(int tel);
	void setCorreoElectronico(string correo);
	void setFechaIngreso(string fecha);

	int getIdCliente();
	string getNombres();
	string getApellidos();
	string getNit();
	bool getGenero();
	int getTelefono();
	string getCorreoElectronico();
	string getFechaIngreso();

	void crear();
	void leer();
	void actualizar();
	void borrar();
	bool buscarPorNit(string nit);
};



/*
class Clientes
{
	//atributos
private:
	int idCliente =0, telefono=0 ;
	string nombres, apellidos, nit, correo_electronico, fechaingreso;
	bool genero =0;



public:
	Clientes(); //{}

	Clientes(int id, string nom, string ape, string n, bool gen, int tel, string correo, string fecha) {
		idCliente = id;
		nombres = nom;
		apellidos = ape;
		nit = n;
		genero = gen;
		telefono = tel;
		correo_electronico = correo;
		fechaingreso = fecha;
	}

	// Setters
	void setIdCliente(int id) { idCliente = id; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setNit(string n) { nit = n; }
	void setGenero(bool gen) { genero = gen; }
	void setTelefono(int tel) { telefono = tel; }
	void setCorreoElectronico(string correo) { correo_electronico = correo; }
	void setFechaIngreso(string fecha) { fechaingreso = fecha; }

	// Getters
	int getIdCliente() { return idCliente; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getNit() { return nit; }
	bool getGenero() { return genero; }
	int getTelefono() { return telefono; }
	string getCorreoElectronico() { return correo_electronico; }
	string getFechaIngreso() { return fechaingreso; }

	// CRUD methods
	void crear();
	void leer();
	void actualizar();
	void borrar();
	bool buscarPorNit(string nit);
};
*/



