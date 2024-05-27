#pragma once
#include <mysql.h>
#include <iostream>

using namespace std;

class ConexionDB
{
private:
	MYSQL* conectar;
public:
	void abrir_conexion() {
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "user", "user123#", "db_mercado", 3306, NULL, 0);
	}
	MYSQL* getConectar() {
		return conectar;
	}
	void cerrar_conexion() {
		mysql_close(conectar);
	}
};

