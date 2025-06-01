#ifndef CUENTA_H
#define CUENTA_H

#include <string>


using namespace std;
class Cuenta {
    private:
        string numero;
        double saldo;
    
    public:
        Cuenta();
        Cuenta(string numero, double saldo);
        void setNumero(string numero);
        string getNumero();

        double verSaldo();
        void setSaldo(double saldo);
};

#endif