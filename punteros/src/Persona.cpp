#include "../include/Persona.h"
#include <iostream>
#include <fstream>


Persona::Persona(string cedula, string nombre, Cuenta* cuenta){
    this -> cedula = cedula;
    this -> nombre = nombre;
    this -> cuenta = cuenta;
}

void Persona::consignar(double valor){
    ofstream archivo("transacciones.txt");
    double valorInicial = this->cuenta->verSaldo();
    cuenta->setSaldo(valorInicial + valor);
    cout << nombre << " consignó " << valor << ". Nuevo saldo: " << cuenta->verSaldo() << endl;
    archivo << nombre << "-" << valorInicial << "-" << valorInicial + valor << "-" << "Consignación" << endl;

    archivo.close();
}

void Persona::retirar(double valor){
    //ifstream, -> para leer archivos
    //ofstream, -> para escribir archivos
    ofstream archivo("transacciones.txt", ios::app);
    double valorInicial = this->cuenta->verSaldo();
    if (valor > valorInicial) {
        cout << nombre << " intentó retirar " << valor << " pero no tiene suficiente saldo." << endl;
        return;
    }
    cuenta->setSaldo(valorInicial - valor);
    cout << nombre << " retiró " << valor << ". Nuevo saldo: " << cuenta->verSaldo() << endl;
    archivo << nombre << "-"<<valorInicial << "-"<<valorInicial - valor <<"-"<<"Retiro"<< endl;

    // Cerrar el archivo después de escribir
    archivo.close();
}



/*
Cuenta*
obj ->metodo()

* esto se hace para que el objeto cuenta no se copie, sino que se pase por referencia.
* el puntero permite que cualquier cambio en la cuenta se refleje en el objeto original.
* 
*/