#include "../include/Deportista.h"
#include <string>
using namespace std;

void Deportista::setNombre(string nombre) {
    this->nombre = nombre;
}

string Deportista::getNombre() {
    return this->nombre;
}

void Deportista::setCedula(string cedula) {
    this->cedula = cedula;
}

string Deportista::getCedula() {
    return this->cedula;
}

void Deportista::setCodigo(string codigo) {
    this->codigo = codigo;
}

string Deportista::getCodigo() {
    return this->codigo;
}

void Deportista::setSexo(string sexo) {
    this->sexo = sexo;
}

string Deportista::getSexo() {
    return this->sexo;
}

void Deportista::setEdad(int edad) {
    this->edad = edad;
}

int Deportista::getEdad() {
    return this->edad;
}

void Deportista::setPrograma(int programa) {
    this->programa = programa;
}

int Deportista::getPrograma() {
    return this->programa;
}

void Deportista::setCantParticipantes(int cantparticipantes) {
    this->cantparticipantes = cantparticipantes;
}

int Deportista::getCantParticipantes() {
    return this->cantparticipantes;
}