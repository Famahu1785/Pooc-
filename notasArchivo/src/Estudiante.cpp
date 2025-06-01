#include "../include/Estudiante.h"
#include <string>
using namespace std;


Estudiante::Estudiante( string nombre,  string codigo,  float notas[3], float adicional){
    
    this->nombre = nombre;
    this->codigo = codigo;
    this->adicional = adicional;
    
    for (int i = 0; i < 3; i++) {
        this->notas[i] = notas[i];
    }
    calcularPromedio();
}

void Estudiante::setCodigo( string codigo) {
    this->codigo = codigo;
}
string Estudiante::getCodigo()  {
    return this->codigo;
}
void Estudiante::setNombre( string nombre) {
    this->nombre = nombre;
}
string Estudiante::getNombre()  {
    return this->nombre;
}
void Estudiante::setNotas( float notas[3]) {
    for (int i = 0; i < 3; i++) {
        this->notas[i] = notas[i];
    }
    calcularPromedio();
}
void Estudiante::setAdicional(float adicional) {
    this->adicional = adicional;
    calcularPromedio();
}
float Estudiante::getAdicional()  {
    return this->adicional;
}
void Estudiante::calcularPromedio() {
    float resultado;
    for(int i=0; i <3; i++){
        resultado += notas[i];

    }
    this ->promedio = resultado/3 + this->adicional;
}
float Estudiante::getPromedio()  {
    return promedio;
}

