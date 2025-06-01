#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "Libreria.h"

class Usuario {
private:
    std::string nombre;
    std::vector<Libreria*> prestados;

public:
    Usuario(const std::string& nombre);
    std::string getNombre() const;
    void mostrarPrestamos() const;
    bool puedePrestar() const;
    void prestar(Libreria* libreria);
    void devolver(int index);
    int totalPrestados() const;
    Libreria* getPrestado(int index);
};

#endif
