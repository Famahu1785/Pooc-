#ifndef USUARIO_H
#define USUARIO_H
#include "Material.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

class Usuario {
    string nombre;
    vector<Material*> prestamos; // se utiliza el vector asi para almacenar los materiales prestados

public:
    Usuario(string n); // Constructor que recibe el nombre del usuario
    bool prestar(Material* m); // Método para prestar un material usando un puntero a Material
    bool devolver(string id); // Método para devolver un material por su ID
    void mostrarPrestamos(); 
    int cantidadPrestamos() const; // se utiliza const para indicar que no modifica el estado del objeto
    string getNombre() const; // Método para obtener el nombre del usuario
};

#endif