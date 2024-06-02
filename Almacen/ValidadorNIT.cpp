#include "ValidadorNIT.h"
#include <iostream>

using namespace std;

bool validarNIT(const string& nit) {
    if (nit.length() != 8) {
        return false;
    }

    int suma = 0;
    int multiplicadores[] = { 8, 7, 6, 5, 4, 3, 2, 1 };

    for (size_t i = 0; i < 8; ++i) {
        if (!isdigit(nit[i])) {
            return false;
        }
        suma += (nit[i] - '0') * multiplicadores[i];
    }

    int residuo = suma % 11;
    int digitoVerificador = (11 - residuo) % 11;

    return digitoVerificador == (nit[7] - '0');
}
/*
int main() {
  string nit;

  cout << "Ingrese el NIT a validar: ";
  cin >> nit;

    if (validarNIT(nit)) {
      cout << "El NIT es válido." << endl;
    }
    else {
      cout << "El NIT es inválido." << endl;
    }

    return 0;
}
*/