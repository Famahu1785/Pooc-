#ifndef USUARIO_H
#define USUARIO_H
#include "Material.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

class Usuario {
    string nombre;
    vector<Material*> prestamos;

public:
    Usuario(string n);
    bool prestar(Material* m);
    bool devolver(string id); // Cambiado: ahora devuelve bool
    void mostrarPrestamos();
    int cantidadPrestamos() const;
    string getNombre() const;
};

#endif