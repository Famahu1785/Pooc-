#ifndef PERSONA_H
#define PERSONA_H

#include "Cuenta.h"
#include <string>

using namespace std;

class Persona{
    private:
        string cedula;
        string nombre;
        Cuenta* cuenta;
    public:
        Persona(string cedula, string nombre, Cuenta* cuenta);
        void retirar(double valor);
        void consignar(double valor);
};
#endif