#include "/workspaces/Pooc-/polimorfismo/include/Animal.h" 

#include <iostream>
#include <string>

using namespace std;
Animal::Animal(const string& nombre, int edad) : nombre(nombre), edad(edad) {}
Animal::~Animal() {
    cout << "Destructor de Animal llamado para " << nombre << endl;
}   
void Animal::mostrarInfo() const {
    cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
}
void Animal::hacerSonido() const {
    cout << "El animal hace un sonido genérico." << endl;
}
void Animal::setNombre(const string& nombre) {
    this->nombre = nombre;
}
string Animal::getNombre() const {
    return nombre;
}
void Animal::setEdad(int edad) {
    this->edad = edad;
}
int Animal::getEdad() const {
    return edad;
}

