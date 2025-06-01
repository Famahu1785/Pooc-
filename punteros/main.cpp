#include <iostream>
#include <fstream>
#include <vector>
#include "include/Cuenta.h"
#include "include/Persona.h"

using namespace std;

void leerArchivo(string ruta, vector<string> &contenido);

int main() {
    Cuenta *punteroCuenta = NULL;

    Cuenta cuenta = Cuenta("111", 400);
    punteroCuenta = &cuenta;

    Persona el = Persona("123", "Alvaro", punteroCuenta);
    Persona ella = Persona("234", "Alicia", punteroCuenta);

    el.consignar(100);
    ella.consignar(50);
    ella.retirar(300);

    cout << "saldo -> " << cuenta.verSaldo() << endl;

    vector<string> lineas;
    leerArchivo("ruta_del_archivo.txt", lineas);
    cout<<lineas.at(1)<<endl;

    for (const auto &linea : lineas) {
        cout << linea << endl;
    }

    return 0;
}

void leerArchivo(string ruta, vector<string> &contenido) {
    ifstream fichero(ruta);

    if (!fichero.is_open()) {
        cerr << "Error al abrir el archivo: " << ruta << endl;
        return;
    }

    string linea;
    while (getline(fichero, linea)) {
        if (!linea.empty()) {
            contenido.push_back(linea);
        }
    }

    fichero.close();
}