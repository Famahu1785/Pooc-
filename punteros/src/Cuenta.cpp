
#include "../include/Cuenta.h"


Cuenta::Cuenta(){

}

Cuenta::Cuenta(string numero, double saldo){
    this->numero = numero;
    this->saldo = saldo;
}

void Cuenta::setNumero(string numero){
    this -> numero = numero;
}

string Cuenta::getNumero(){
    return numero;
}


double Cuenta::verSaldo(){
    return saldo;
}

void Cuenta::setSaldo(double saldo){
    this->saldo = saldo;
}

